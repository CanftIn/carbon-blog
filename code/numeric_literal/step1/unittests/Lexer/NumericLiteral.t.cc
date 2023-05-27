#include "Cocktail/Lexer/NumericLiteral.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iterator>

namespace {

using namespace Cocktail;

TEST(NumericLiteralTest, LexBasic) {
  auto token = NumericLiteralToken::Lex("1");
  EXPECT_EQ("1", std::string(token->Text()));
  token = NumericLiteralToken::Lex("123_456.78e-9");
  EXPECT_EQ("123_456.78e-9", std::string(token->Text()));
}

}  // namespace