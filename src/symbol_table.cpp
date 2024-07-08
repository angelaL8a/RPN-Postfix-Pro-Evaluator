#include "symbol_table.hpp"

int SymbolTable::hash(char key) const
{
    /**
     * *PSEUDOCODE:
       HASH(key)
           RETURN ASCII(key) mod MAX_SIZE
       END HASH
    */
    return (key - 'A') % MAX_SIZE;
}

bool SymbolTable::isValidKey(char key) const
{
    /**
     * *PSEUDOCODE:
       IS_VALID_KEY(key)
           IF (key is a letter between "A" AND "Z") THEN
               return TRUE
           ELSE return FALSE
       END IS_VALID_KEY
    */
    return (key >= 'A' && key <= 'Z');
}

void SymbolTable::insert(char key, double value)
{
    /**
     * *PSEUDOCODE:
        INSERT(key, value)
            IF NOT IS_VALID_KEY(key) THEN
                THROW "Invalid key: must be between 'A' and 'Z'."
            END IF
            index ← HASH(key)
            table[index] ← value
            isSet[index] ← true
        END INSERT
    */
    if (!isValidKey(key))
    {
        throw std::out_of_range("Invalid key: must be between 'A' and 'Z'.");
    }
    int index = hash(key);
    table[index] = value;
    isSet[index] = true;
}

double SymbolTable::search(char key) const
{
    /**
     * *PSEUDOCODE:
        SEARCH(key)
            IF NOT IS_VALID_KEY(key) THEN
                THROW "Invalid key: must be between 'A' and 'Z'."
            END IF
            index ← HASH(key)
            IF NOT isSet[index] THEN
                THROW "Key not found: the specified key is not set."
            END IF
            RETURN table[index]
        END SEARCH
    */
    if (!isValidKey(key))
    {
        throw std::out_of_range("Invalid key: must be between 'A' and 'Z'.");
    }
    int index = hash(key);
    if (!isSet[index])
    {
        throw std::out_of_range("Key not found: the specified key is not set.");
    }
    return table[index];
}

void SymbolTable::remove(char key)
{
    /**
     * *PSEUDOCODE:
    REMOVE(key)
        IF NOT IS_VALID_KEY(key) THEN
            THROW "Invalid key: must be between 'A' and 'Z'."
        END IF
        index ← HASH(key)
        IF NOT isSet[index] THEN
            THROW "Key not found: the specified key is not set."
        END IF
        isSet[index] ← false
    END REMOVE
    */
    if (!isValidKey(key))
    {
        throw std::out_of_range("Invalid key: must be between 'A' and 'Z'.");
    }
    int index = hash(key);
    if (!isSet[index])
    {
        throw std::out_of_range("Key not found: the specified key is not set.");
    }
    isSet[index] = false;
}

void SymbolTable::printST() const
{
    std::cout << SOFT_PINK << "Symbol Table" << std::endl;
    std::cout << "------------" << std::endl;

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        if (isSet[i])
        {
            std::cout << (char)('A' + i) << " = " << table[i] << std::endl;
        }
    }
}