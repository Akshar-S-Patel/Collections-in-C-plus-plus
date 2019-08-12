#ifndef _queue_h
#define _queue_h

#include <iostream>
#include <initializer_list>
#include "LinkedList.h"

using namespace std;

/**
 * This class models a linear structure called a queue
 * in which values are added from the front and removed  from end.
 * This data-structure gives rise to a first-in/first-out behavior (FIFO)
 * that is the defining feature of queue.  The fundamental queue
 * operations are <code>push</code> (add to front) and <code>pop</code>
 * (remove from back).
 */
template <typename type>
class Queue {

public:
    ///  constructors and destructor

    /**
    *  Initializes a new empty queue.
    */
    Queue() = default;

    /**
    *  Copy Constructor - use the passed Queue to initialization itself (deep copy)
    *  Take Constructor - use the passed Queue to initialization itself (shallow copy)
    */
    Queue(const Queue& queue) {    ///Copy Constructor
        _elements = queue._elements;
    }

    Queue(Queue&& queue) {      ///Take Constructor
        _elements = queue._elements;
    }

    /**
    *  Initializes a new queue that stores the given elements from front-back.
    */
    Queue(initializer_list<type> queue) : _elements(queue) { }

    /**
    *  Frees any heap storage associated with this queue.
    */
    virtual ~Queue() = default;


    /// member function (methods)

    /**
    *  Returns the first value in the queue by reference.
    *  @throw "Exception" for empty queue
    */
    const type& front() const {
        if (empty())
            throw "Exception :-(";
        return _elements.front();
    }

    /**
    *  Returns the last value in the queue by reference.
    *  @throw "Exception" for empty queue
    */
    const type& back() const {
        if (empty())
            throw "Exception :-(";
        return _elements.back();
    }


    /**
    *  Removes all elements from the queue.
    */
    void clear() {
        _elements.clear();
    }

    /**
    *  Removes and returns the last item in the queue.
    *  @throw "Exception" for empty queue
    */
    type dequeue() {
        if (empty())
            throw "Exception :-(";
        type temp = _elements[_elements.size() - 1];
        _elements.pop_back();
        return temp;
    }

    /**
    *  Adds <code>value</code> to the start of the queue.
    */
    void enqueue(const type& value) {
        _elements.push_front(value);
    }

    /**
    *  Compares two queues for equality.
    *  Returns <code>true</code> if this queue contains exactly the same
    *  values as the given other queue.
    *  Identical in behavior to the == operator.
    */
    bool equals(const Queue<type>& queue) const {
        return _elements.equals(queue._elements);
    }

    /**
    *  Returns <code>true</code> if the queue contains no elements.
    */
    bool empty() const {
        return _elements.empty();
    }

    /**
    *  Returns the first value in the queue, without removing it.
    *  @throw "Exception" for empty queue
    */
    const type peek() const {
        type temp = _elements[0];
        _elements.pop_front();
        return temp;
    }

    /**
    *  Removes and returns the first item in the queue.
    *  A synonym for the dequeue method.
    */
    type remove() {
        return dequeue();
    }

    /**
    *  Returns the number of values in the queue.
    */
    int size() const {
        return _elements.size();
    }

    void swap(Queue<type>& queue) {
        _elements.swap(queue._elements);
    }

    /// Operator Overloading

    /**
    *  A synonym for the dequeue method. But you can use as an operator.
    */
    type operator--(int) {
        return dequeue();
    }

    type operator--() {
        return dequeue();
    }

    /**
     * Overloads = to assign new Queue to left Queue
     */
    Queue& operator=(Queue& queue) {   ///Copy assignment operator
        if (this != &queue)
            _elements = queue._elements;
        return *this;
    }

    Queue& operator=(Queue&& queue) {  ///Take assignment operator
        if (this != &queue)
            _elements = queue._elements;
        return *this;
    }

    /**
    *  Returns <code>true</code> if <code>queue1</code> and <code>queue</code>
    *  contain the same elements.
    */
    bool operator==(const Queue& queue) const {
        return equals(queue);
    }

    /**
    *  Returns <code>true</code> if <code>queue1</code> and <code>queue</code>
    *  do not contain the same elements.
    */
    bool operator!=(const Queue& queue) const {
        return !equals(queue);
    }

    /**
    *  Relational operators to compare two queues.
    *  The <, >, <=, >= operators require that the type has a < and > operator
    *  so that the elements can be compared pairwise.
    */
    bool operator<(const Queue& queue) const {
        return _elements < queue._elements;
    }

    bool operator<=(const Queue& queue) const {
        return _elements <= queue._elements;
    }

    bool operator>(const Queue& queue) const {
        return _elements > queue._elements;
    }

    bool operator>=(const Queue& queue) const {
        return _elements >= queue._elements;
    }

    /**
    *  A synonym for the enqueue method. But you can use as an operator.
    */
    Queue operator+(const type& value) {
        Queue<type> queue;
        queue._elements.addAll(_elements);
        enqueue(value);
        return queue;
    }

    void operator+=(const type& value) {
        enqueue(value);
    }

    template <typename T>
    friend ostream& operator<<(ostream& out, Queue<T>& queue);

    template <typename T>
    friend ostream& operator<<(ostream& out, const Queue<T>& queue);

private:
    // member variable (fields)
    LinkedList<type> _elements;
};


template <typename type>
 ostream& operator<<(ostream& out, Queue<type>& queue) {
    out << queue._elements;
    return out;
 }

 template <typename type>
 ostream& operator<<(ostream& out, const Queue<type>& queue) {
    out << queue._elements;
    return out;
 }


#endif /// _queue_h
