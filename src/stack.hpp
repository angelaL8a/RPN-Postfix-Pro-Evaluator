/**
 * @file Stack.hpp
 * @brief This file contains the definition of the Stack class template.
 *
 * The Stack class template is used to manage a stack of elements of any type. It provides methods to push, pop, and peek at the top element, as well as to check if the stack is empty.
 */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>

/**
 * @class Stack
 * @brief A class template to manage a stack of elements of any type.
 *
 * The Stack class template provides methods to manipulate a stack of elements. It uses an array to store the stack elements and keeps track of the index of the top element.
 * @tparam T The type of the elements in the stack.
 */
template <typename T>
class Stack
{
private:
    static const int INITIAL_CAPACITY = 10; // Maximum size of the stack
    T *items;                               // Array to store stack elements
    int top;                                // Index of the top element
    int capacity;                           // Actual capacity of the stack

    void resize(int newSize); // Resize the stack

public:
    /**
     * @brief Construct a new Stack object.
     */
    Stack();
    /**
     * @brief Destroy the Stack object and free allocated memory.
     */
    ~Stack();

    /**
     * @brief Push an element onto the stack.
     *
     * @param[in] value The element to be pushed onto the stack.
     */
    void push(T value);

    /**
     * @brief Pop an element from the stack.
     *
     * @return The element that was popped from the stack.
     * @throws std::underflow_error If the stack is already empty.
     */
    T pop();

    /**
     * @brief Get the top element of the stack without popping it.
     *
     * @return The top element of the stack.
     * @throws std::underflow_error If the stack is already empty.
     */
    T peek() const;

    /**
     * @brief Check if the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty() const;

    void clearStack();
};

#include "Stack.tpp"

#endif // STACK_HPP