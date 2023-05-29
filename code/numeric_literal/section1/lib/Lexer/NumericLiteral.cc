#include "Cocktail/Lexer/NumericLiteral.h"

#include <bitset>

#include "Cocktail/Lexer/CharacterSet.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Support/FormatVariadic.h"

namespace Cocktail {

auto NumericLiteralToken::Lex(llvm::StringRef source_text)
    -> llvm::Optional<NumericLiteralToken> {
  NumericLiteralToken result;

  if (source_text.empty() || !IsDecimalDigit(source_text.front())) {
    return llvm::None;
  }

  bool seen_plus_minus = false;
  bool seen_radix_point = false;
  bool seen_potential_exponent = false;

  int i = 1;
  for (int n = source_text.size(); i != n; ++i) {
    char c = source_text[i];
    if (IsAlnum(c) || c == '_') {
      if (IsLower(c) && seen_radix_point && !seen_plus_minus) {
        result.exponent = i;
        seen_potential_exponent = true;
      }
      continue;
    }

    if (c == '.' && i + 1 != n && IsAlnum(source_text[i + 1]) &&
        !seen_radix_point) {
      result.radix_point = i;
      seen_radix_point = true;
      continue;
    }

    if ((c == '+' || c == '-') && seen_potential_exponent &&
        result.exponent == i - 1 && i + 1 != n &&
        IsAlnum(source_text[i + 1])) {
      assert(!seen_plus_minus && "should only consume one + or -");
      seen_plus_minus = true;
      continue;
    }
    break;
  }

  result.text = source_text.substr(0, i);
  if (!seen_radix_point) {
    result.radix_point = i;
  }
  if (!seen_potential_exponent) {
    result.exponent = i;
  }

  return result;
}

}  // namespace Cocktail