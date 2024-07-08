#include "D:\Documents\Angela - University Of London\COURSES\Algorithms and Data Structures II\WEEK10\MIDTERM\Posfix++\src\postfix_evaluator.hpp"
#include <gtest/gtest.h>

TEST(PostfixEvaluatorTest, SimpleExpression)
{
    PostfixEvaluator evaluator;
    std::string expression = "3 1 + 2 pow 7 4 - 2 * + 5 -";
    Result result = evaluator.evaluate(expression);
    ASSERT_FALSE(result.isAssignment);
    EXPECT_EQ(result.result, 17);
}

TEST(PostfixEvaluatorTest, AssignmentAndExpression)
{
    PostfixEvaluator evaluator;
    std::string expression = "A 5 = B 3 = A B +";
    Result result = evaluator.evaluate(expression);
    ASSERT_TRUE(result.isAssignment);
    EXPECT_EQ(result.result, 8.0);
}

TEST(PostfixEvaluatorTest, InvalidExpression)
{
    PostfixEvaluator evaluator;
    std::string expression = "5 +"; // Missing operand
    EXPECT_THROW(evaluator.evaluate(expression), std::runtime_error);
}

TEST(PostfixEvaluatorTest, InvalidAssignment)
{
    PostfixEvaluator evaluator;
    std::string expression = "A = 3"; // Missing operand
    EXPECT_THROW(evaluator.evaluate(expression), std::out_of_range);
}

// Add more test cases as needed
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
