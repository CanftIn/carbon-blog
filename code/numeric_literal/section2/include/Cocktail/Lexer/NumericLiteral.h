#ifndef COCKTAIL_LEXER_NUMERIC_LITERAL_H
#define COCKTAIL_LEXER_NUMERIC_LITERAL_H

#include <utility>

#include "llvm/ADT/APInt.h"
#include "llvm/ADT/Optional.h"
#include "llvm/ADT/StringRef.h"

namespace Cocktail {

class NumericLiteralToken {
 public:
  auto Text() const -> llvm::StringRef { return text; }

  static auto Lex(llvm::StringRef source_text)
      -> llvm::Optional<NumericLiteralToken>;

  class Parser;

 private:
  NumericLiteralToken() {}

  llvm::StringRef text;

  // The offset of '.'
  int radix_point;

  // The offset of the alphabetical character introducing the exponent.
  int exponent;
};

class NumericLiteralToken::Parser {
 public:
  Parser(NumericLiteralToken literal);

  auto IsInteger() -> bool {
    return literal.radix_point == static_cast<int>(literal.Text().size());
  }

  auto GetRadix() const -> int { return radix; }

  auto GetMantissa() -> llvm::APInt;

  auto GetExponent() -> llvm::APInt;

 private:
  NumericLiteralToken literal;

  // The radix of the literal: 2, 10, or 16
  int radix = 10;

  // [radix] int_part [. fract_part [[ep] [+-] exponent_part]]
  llvm::StringRef int_part;
  llvm::StringRef fract_part;
  llvm::StringRef exponent_part;

  bool mantissa_needs_cleaning = false;
  bool exponent_needs_cleaning = false;

  // True if we found a `-` before `exponent_part`.
  bool exponent_is_negative = false;
};

}  // namespace Cocktail

#endif  // COCKTAIL_LEXER_NUMERIC_LITERAL_H