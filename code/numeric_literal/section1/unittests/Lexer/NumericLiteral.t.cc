#include "Cocktail/Lexer/NumericLiteral.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iterator>

namespace {

using namespace Cocktail;

TEST(NumericLiteralTest, LexBasic) {
  auto token = NumericLiteralToken::Lex("1");
  EXPECT_EQ("1", std::string(token->Text()));
  EXPECT_EQ(1, token->GetRadixPoint());
  EXPECT_EQ(1, token->GetExponent());
  token = NumericLiteralToken::Lex("123_456.78e-9");
  EXPECT_EQ("123_456.78e-9", std::string(token->Text()));
  EXPECT_EQ(7, token->GetRadixPoint());
  EXPECT_EQ(10, token->GetExponent());
}

}  // namespace