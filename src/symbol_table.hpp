#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

/**
 * @file SymbolTable.hpp
 * @brief Implementation of a symbol table using a static array with a maximum size of 26 characters, representing the 26 letters of the alphabet.
 * @details This implementation uses the ASCII value of the letters to map them to their respective indices in the array, thus limiting the table to 26 positions.
 *
 */

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <array>

/**
 * @class SymbolTable
 * @brief A simple symbol table implementation using a static array.
 *
 * @details This class provides methods to insert, search, and remove key-value pairs from the symbol table.
 */

class SymbolTable
{
private:
    /**
     * *PSEUDOCODE:
        CONSTANT MAX_SIZE ← 26
        DECLARE table[0..MAX_SIZE-1] OF DOUBLE
        DECLARE isSet[0..MAX_SIZE-1] OF BOOLEAN

        *Initializes the symbol table by setting all entries as unset
        SYMBOL_TABLE_INITIALIZE()
            FOR i ← 0 TO MAX_SIZE - 1 DO
                isSet[i] ← false
            END FOR
        END SYMBOL_TABLE_INITIALIZE
    */
    const std::string SOFT_PINK = "\033[38;5;225m";
    static const int MAX_SIZE = 26;             // Maximum size of the symbol table
    std::array<double, MAX_SIZE> table = {};    // Array to store the values associated with the keys
    std::array<bool, MAX_SIZE> isSet = {false}; // Array to check if a key is set

    /**
     * @brief Calculates the hash value (index) for a given key.
     *
     * @param key The character to calculate the hash value for.
     * @return The hash value (index) for the given key.
     */
    int hash(char key) const;

    /**
     * @brief Checks if the given key is a valid character.
     *
     * @param key The character to check.
     * @return True if the key is a valid character, false otherwise.
     */
    bool isValidKey(char key) const;

public:
    /**
     * @brief Constructs an empty symbol table.
     */
    SymbolTable() = default;

    /**
     * @brief Inserts a key-value pair into the symbol table.
     *
     * @param key The character representing the key.
     * @param value The value associated with the key.
     * @throws std::invalid_argument If the key is not a valid character.
     */
    void insert(char key, double value);

    /**
     * @brief Searches for a key in the symbol table and returns its associated value.
     *
     * @param key The character representing the key to search for.
     * @return The value associated with the key, or 0.0 if the key is not found.
     * @throws std::invalid_argument If the key is not a valid character.
     */
    double search(char key) const;

    /**
     * @brief Removes a key-value pair from the symbol table.
     *
     * @param key The character representing the key to remove.
     * @throws std::invalid_argument If the key is not a valid character.
     */
    void remove(char key);

    /**
     * @brief Prints the contents of the symbol table.
     *
     * This method prints the contents of the symbol table (just assigned keys), including the keys and their associated values.
     *
     * @details The method iterates through the symbol table and prints each key-value pair in the format:
     *
     *  - Key: <key> = Value: <value>
     *
     * @throws std::invalid_argument If the symbol table is empty.
     */
    void printST() const;
};

#endif // SYMBOL_TABLE_HPP