#ifndef _stack_h
#define _stack_h


#include "ArrayList.h"
#include <iostream>
#include <initializer_list>

using namespace std;

/**
 * This class models a linear structure called a stack
 * in which values are added and removed only from one end.
 * This data-structure gives rise to a last-in/first-out behavior (LIFO)
 * that is the defining feature of stacks.  The fundamental stack
 * operations are <code>push</code> (add to top) and <code>pop</code>
 * (remove from top).
 */
template <typename type>
class Stack {
public:
    ///  constructors and destructor

    /**
    *  Initializes a new empty stack.
    */
    Stack() = default;

    /**
    *  Copy Constructor - use the passed Stack to initialization itself (deep copy)
    *  Take Constructor - use the passed Stack to initialization itself (shallow copy)
    */
    Stack(const Stack& stack);    ///Copy Constructor
    Stack(Stack&& stack);        ///Take Constructor

    /**
    *  Create a stack using initializer list
    */
    Stack(initializer_list<type> stack);

    /**
    *  Frees any heap storage associated with this stack.
    */
    virtual ~Stack() = default;

    ///  member function (methods)

    /**
    *  Pushes the specified value onto the top of this stack.
    */
    void push(const type& value);

    /**
    *  Removes all elements from this stack.
    */
    void clear();

    /**
    *  Returns <code>true</code> if this stack contains exactly the same values
    *  as the given other stack.
    *  Identical in behavior to the == operator.
    */
    bool equals(const Stack<type>& stack) const;

    /**
    *  Returns <code>true</code> if this stack contains no elements.
    */
    bool empty() const;

    /**
    *  Returns the value of top element from this stack, without removing
    *  it.
    *  @throw "Exception" if stack is empty
    */
    type peek() const;

    /**
    *  Removes the top element from this stack and returns it.
    *  @throw "Exception" if stack is empty
    */
    type pop();

    /**
    *  Removes the top element from this stack and returns it.
    *  A synonym for the pop method.
    */
    type remove();

    /**
    *  Returns the number of values in this stack.
    */
    int size() const;

    /**
    *  Returns the value of top element from this stack, without removing
    *  it.
    */
    const type& top();

    /**
    *  Swap the two Stack
    */
    void swap(Stack& stack);

    /// Operator Overloading

    /**
    *  A synonym for the pop method. But you can use as an operator.
    */
    type operator--(int);
    type operator--();

    /**
     * Overloads = to assign new Stack to left Stack
     */
    Stack& operator=(Stack& stack);   ///Copy assignment operator
    Stack& operator=(Stack&& stack);  ///Take assignment operator


    /**
    *  Returns <code>true</code> if <code>stack1</code> and <code>stack</code>
    *  contain the same elements.
    */
    bool operator==(const Stack& stack) const;

    /**
    *  Returns <code>true</code> if <code>stack1</code> and <code>stack</code>
    *  do not contain the same elements.
    */
    bool operator!=(const Stack& stack) const;

    /**
    *  Relational operators to compare two stacks.
    *  The <, >, <=, >= operators require that the type has a < and > operator
    *  so that the elements can be compared pairwise.
    */
    bool operator<(const Stack& stack) const;
    bool operator<=(const Stack& stack) const;
    bool operator>(const Stack& stack) const;
    bool operator>=(const Stack& stack) const;

    /**
    *  A synonym for the push method. But you can use as an operator.
    */
    Stack operator+(const type& value);
    void operator+=(const type& value);

    /**
    *  The easiest way to implement a stack is to store the elements in a
    *  ArrayList. Doing so means that the problems of dynamic memory allocation
    *  and copy assignment are already solved by the implementation of the
    *  ArrayList class.
    */

    template <typename T>
    friend ostream& operator<<(ostream& out, Stack<T>& stack);

    template <typename T>
    friend ostream& operator<<(ostream& out, const Stack<T>& stack);

private:
    // member variable (fields)
    ArrayList<type> _elements;
};

template <typename type>
Stack<type>::Stack(const Stack& stack) {
    _elements = stack._elements;
}

template <typename type>
Stack<type>::Stack(Stack&& stack){
    _elements = stack._elements;
}

template <typename type>
Stack<type>::Stack(initializer_list<type> stack) : _elements(stack) {
}

template <typename type>
void Stack<type>::push(const type& value) {
    _elements.push_back(value);
}

template <typename type>
void Stack<type>::clear() {
    _elements.clear();
}

template <typename type>
bool Stack<type>::equals(const Stack<type>& stack) const {
    return _elements.equals(stack._elements);
}

template <typename type>
bool Stack<type>::empty() const {
    return _elements.empty();
}

template <typename type>
type Stack<type>::peek() const {
    if (empty())
        throw "Exception :-(";
    return _elements[_elements.size() - 1];
}

template <typename type>
type Stack<type>::pop() {
    if (empty())
        throw "Exception :-(";
    type element = _elements[_elements.size() - 1];
    _elements.pop_back();
    return element;
}

template <typename type>
type Stack<type>::remove() {
    pop();
}

template <typename type>
int Stack<type>::size() const {
    return _elements.size();
}

template <typename type>
const type& Stack<type>::top() {
    return _elements[_elements.size() - 1];
}

template <typename type>
void Stack<type>::swap(Stack<type>& stack) {
    _elements.swap(stack._elements);
}

template <typename type>
type Stack<type>::operator--(int) {
    return pop();
}

template <typename type>
type Stack<type>::operator--() {
    return pop();
}

template <typename type>
Stack<type>& Stack<type>::operator=(Stack& stack) {
    if (this != &stack)
        _elements = stack._elements;
    return *this;
}

template <typename type>
Stack<type>& Stack<type>::operator=(Stack&& stack) {
    if (this != &stack)
        _elements = stack._elements;
    return *this;
}


template <typename type>
bool Stack<type>::operator==(const Stack& stack) const {
    return equals(stack);
}

template <typename type>
bool Stack<type>::operator!=(const Stack& stack) const {
    return !equals(stack);
}

template <typename type>
bool Stack<type>::operator<(const Stack& stack) const {
    return _elements < stack._elements;
}

template <typename type>
bool Stack<type>::operator<=(const Stack& stack) const {
    return _elements <= stack._elements;
}

template <typename type>
bool Stack<type>::operator>(const Stack& stack) const {
    return _elements > stack._elements;
}

template <typename type>
bool Stack<type>::operator>=(const Stack& stack) const {
    return _elements >= stack._elements;
}

template <typename type>
Stack<type> Stack<type>::operator+(const type& value) {
    Stack<type> stack;
    stack._elements.addAll(_elements);
    stack.push(value);
    return stack;
}

template <typename type>
void Stack<type>::operator+=(const type& value) {
    push(value);
}

template <typename type>
ostream& operator<<(ostream& out, Stack<type>& stack) {
    out << stack._elements;
    return out;
}

template <typename type>
ostream& operator<<(ostream& out, const Stack<type>& stack) {
    out << stack._elements;
    return out;
}


#endif // _stack_h
