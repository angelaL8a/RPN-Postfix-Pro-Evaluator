
#include "D:\Documents\Angela - University Of London\COURSES\Algorithms and Data Structures II\WEEK10\MIDTERM\Posfix++\src\symbol_table.hpp"
#include <gtest/gtest.h>

class SymbolTableTest : public ::testing::Test
{
protected:
    SymbolTable symbolTable;
};

// Test valid insertion and search
TEST_F(SymbolTableTest, InsertAndSearchValidKeys)
{
    symbolTable.insert('A', 1.23);
    EXPECT_DOUBLE_EQ(symbolTable.search('A'), 1.23);

    symbolTable.insert('B', 4.56);
    EXPECT_DOUBLE_EQ(symbolTable.search('B'), 4.56);

    symbolTable.insert('Z', 7.89);
    EXPECT_DOUBLE_EQ(symbolTable.search('Z'), 7.89);
}

// Test invalid key insertion
TEST_F(SymbolTableTest, InsertInvalidKey)
{
    EXPECT_THROW(symbolTable.insert('a', 1.23), std::out_of_range);
    EXPECT_THROW(symbolTable.insert('1', 4.56), std::out_of_range);
}

// Test search for unset keys
TEST_F(SymbolTableTest, SearchUnsetKey)
{
    EXPECT_THROW(symbolTable.search('C'), std::out_of_range);
    EXPECT_THROW(symbolTable.search('X'), std::out_of_range);
}

// Test remove key
TEST_F(SymbolTableTest, RemoveKey)
{
    symbolTable.insert('A', 1.23);
    symbolTable.remove('A');
    EXPECT_THROW(symbolTable.search('A'), std::out_of_range);

    symbolTable.insert('B', 4.56);
    symbolTable.remove('B');
    EXPECT_THROW(symbolTable.search('B'), std::out_of_range);
}

// Test remove invalid key
TEST_F(SymbolTableTest, RemoveInvalidKey)
{
    EXPECT_THROW(symbolTable.remove('a'), std::out_of_range);
    EXPECT_THROW(symbolTable.remove('1'), std::out_of_range);
}

// Test remove unset key
TEST_F(SymbolTableTest, RemoveUnsetKey)
{
    EXPECT_THROW(symbolTable.remove('C'), std::out_of_range);
    EXPECT_THROW(symbolTable.remove('X'), std::out_of_range);
}

// Test printST function (this would typically be done by capturing stdout, but it's simpler to just run it here)
TEST_F(SymbolTableTest, PrintSymbolTable)
{
    symbolTable.insert('A', 1.23);
    symbolTable.insert('B', 4.56);
    symbolTable.printST();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
