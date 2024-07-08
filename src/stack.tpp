/**
 * @file Stack.tpp
 * @brief This file contains the implementation of the Stack class template.
 */

#include "Stack.hpp"

/**
 * *PSEUDOCODE:
 * Initializes the stack by setting the top index to -1,
 indicating the stack is empty.
    STACK_INITIALIZE()
        top ← - 1
        capacity ← INITIAL_CAPACITY
    END STACK_INITIALIZE
 */
template <typename T>
Stack<T>::Stack() : top(-1),
                    capacity(INITIAL_CAPACITY)
{
    items = new T[INITIAL_CAPACITY];
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] items;
}

template <typename T>
void Stack<T>::resize(int newSize)
{
    /**
     * *PSEUDOCODE:
    RESIZE()
        T temp = new T[capacity*2]
        for (int i = 0; i < top; i++)
        {temp[i] = items[i]}
        items = temp
        capacity = capacity * 2
    END RESIZE
     */
    T *temp = new T[newSize];
    for (int i = 0; i < top; i++)
    {
        temp[i] = items[i];
    }
    delete[] items;
    items = temp;
    capacity = newSize;
}

template <typename T>
void Stack<T>::push(T value)
{
    /**
     * *PSEUDOCODE:
        PUSH(value)
            IF (top ≥ capacity - 1) RESIZE()
            top ← top + 1
            items[top] ← value
        END PUSH
    */
    if (top >= capacity - 1)
    {

        resize(capacity * 2);
    }
    items[++top] = value;
}

template <typename T>
T Stack<T>::pop()
{
    /**
     * *PSEUDOCODE:
        POP()
            IF top < 0 THEN
                THROW "Stack is empty: cannot pop."
            END IF
            value ← items[top]
            top ← top - 1
            RETURN value
        END POP
    */
    if (top < 0)
    {
        throw std::underflow_error("Stack is empty: cannot pop.");
    }
    return items[top--];
}

template <typename T>
T Stack<T>::peek() const
{
    /**
     * *PSEUDOCODE:
        PEEK()
            IF top < 0 THEN
                THROW "Stack is empty: cannot peek."
            END IF
            return items[top]
        END PEEK
    */
    if (top < 0)
    {
        throw std::underflow_error("Stack is empty: cannot peek.");
    }
    return items[top];
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    /**
     * *PSEUDOCODE:
    IS_EMPTY()
        return top = -1
    END IS_EMPTY
    */
    return top == -1;
}

template <typename T>
void Stack<T>::clearStack()
{
    /***
     * *PSEUDOCODE:
        CLEAR_STACK()
            top ← - 1
        END CLEAR_STACK
    */
    top = -1;
}