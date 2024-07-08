#include "D:\Documents\Angela - University Of London\COURSES\Algorithms and Data Structures II\WEEK10\MIDTERM\Posfix++\src\stack.hpp"
#include "gtest/gtest.h"

class StackTest : public testing::Test
{
protected:
    Stack<int> stack;

    void SetUp() override
    {
        stack.push(1);
        stack.push(2);
    }

    void TearDown() override
    {
        while (!stack.isEmpty())
        {
            stack.pop();
        }
    }
};

TEST_F(StackTest, PushPop)
{
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
}

TEST_F(StackTest, Peek)
{
    EXPECT_EQ(stack.peek(), 2);
}

TEST_F(StackTest, IsEmpty)
{
    EXPECT_FALSE(stack.isEmpty());
    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

TEST_F(StackTest, Underflow)
{
    stack.pop();
    stack.pop();
    EXPECT_THROW(stack.pop(), std::underflow_error);
    EXPECT_THROW(stack.peek(), std::underflow_error);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
