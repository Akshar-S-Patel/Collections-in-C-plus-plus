#ifndef _queue_h
#define _queue_h

#include <iostream>
#include <initializer_list>
#include "linkedList.h"

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
    Queue(const Queue& queue);    ///Copy Constructor
    Queue(Queue&& queue);        ///Take Constructor

    /**
    *  Initializes a new queue that stores the given elements from front-back.
    */
    Queue(initializer_list<type> queue);

    /**
    *  Frees any heap storage associated with this queue.
    */
    virtual ~Queue() = default;


    /// member function (methods)

    /**
    *  Returns the last value in the queue by reference.
    *  @throw "Exception" for empty queue
    */
    const type& back() const;

    /**
    *  Removes all elements from the queue.
    */
    void clear();

    /**
    *  Removes and returns the last item in the queue.
    *  @throw "Exception" for empty queue
    */
    type dequeue();

    /**
    *  Adds <code>value</code> to the start of the queue.
    */
    void enqueue(const type& value);

    /**
    *  Compares two queues for equality.
    *  Returns <code>true</code> if this queue contains exactly the same
    *  values as the given other queue.
    *  Identical in behavior to the == operator.
    */
    bool equals(const Queue<type>& queue) const;

    /**
    *  Returns the first value in the queue by reference.
    */
    const type& front() const;

    /**
    *  Returns <code>true</code> if the queue contains no elements.
    */
    bool empty() const;

    /**
    *  Swap the two Queue
    */
    void swap(Queue& queue);

    /**
    *  Returns the first value in the queue, without removing it.
    *  @throw "Exception" for empty queue
    */
    const type peek() const;

    /**
    *  Removes and returns the first item in the queue.
    *  A synonym for the dequeue method.
    */
    type remove();

    /**
    *  Returns the number of values in the queue.
    */
    int size() const;

    /// Operator Overloading

    /**
    *  A synonym for the dequeue method. But you can use as an operator.
    */
    type operator--(int);
    type operator--();

    /**
     * Overloads = to assign new Queue to left Queue
     */
    Queue& operator=(Queue& queue);   ///Copy assignment operator
    Queue& operator=(Queue&& queue);  ///Take assignment operator

    /**
    *  Returns <code>true</code> if <code>queue1</code> and <code>queue</code>
    *  contain the same elements.
    */
    bool operator==(const Queue& queue) const;

    /**
    *  Returns <code>true</code> if <code>queue1</code> and <code>queue</code>
    *  do not contain the same elements.
    */
    bool operator!=(const Queue& queue) const;

    /**
    *  Relational operators to compare two queues.
    *  The <, >, <=, >= operators require that the type has a < and > operator
    *  so that the elements can be compared pairwise.
    */
    bool operator<(const Queue& queue) const;
    bool operator<=(const Queue& queue) const;
    bool operator>(const Queue& queue) const;
    bool operator>=(const Queue& queue) const;

    /**
    *  A synonym for the enqueue method. But you can use as an operator.
    */
    Queue operator+(const type& value);
    void operator+=(const type& value);

    template <typename T>
    friend ostream& operator<<(ostream& out, Queue<T>& queue);

    template <typename T>
    friend ostream& operator<<(ostream& out, const Queue<T>& queue);

private:
    linkedList<type> _elements;
};

template <typename type>
Queue<type>::Queue(const Queue& queue) {
    _elements = queue._elements;
}

template <typename type>
Queue<type>::Queue(Queue&& queue) {
    _elements = queue._elements;
}

template <typename type>
Queue<type>::Queue(initializer_list<type> queue) : _elements(queue) {
}

template <typename type>
const type& Queue<type>::back() const {
    if (empty())
        throw "Exception :-(";
    return _elements.back();
}

template <typename type>
void Queue<type>::clear() {
    _elements.clear();
}

template <typename type>
type Queue<type>::dequeue() {
    if (empty())
        throw "Exception :-(";
    type temp = _elements[_elements.size() - 1];
    _elements.pop_back();
    return temp;
}

template <typename type>
void Queue<type>::enqueue(const type& value) {
    _elements.push_front(value);
}

template <typename type>
bool Queue<type>::equals(const Queue<type>& queue) const {
    return _elements.equals(queue._elements);
}

template <typename type>
const type& Queue<type>::front() const {
    return _elements.front();
}

template <typename type>
bool Queue<type>::empty() const {
    return _elements.empty();
}

template <typename type>
const type Queue<type>::peek() const {
    type temp = _elements[0];
    _elements.pop_front();
    return temp;
}

template <typename type>
type Queue<type>::remove() {
    return dequeue();
}

template <typename type>
int Queue<type>::size() const {
    return _elements.size();
}

template <typename type>
void Queue<type>::swap(Queue<type>& queue) {
    _elements.swap(queue._elements);
}

template <typename type>
type Queue<type>::operator--(int) {
    return dequeue();
}

template <typename type>
type Queue<type>::operator--() {
    return dequeue();
}


template <typename type>
Queue<type>& Queue<type>::operator=(Queue& queue) {
    if (this != &queue)
        _elements = queue._elements;
    return *this;
}

template <typename type>
Queue<type>& Queue<type>::operator=(Queue&& queue) {
    if (this != &queue)
        _elements = queue._elements;
    return *this;
}

template <typename type>
bool Queue<type>::operator==(const Queue& queue) const {
    return equals(queue);
}

template <typename type>
bool Queue<type>::operator!=(const Queue& queue) const {
    return !equals(queue);
}

template <typename type>
bool Queue<type>::operator<(const Queue& queue) const {
    return _elements < queue._elements;
}

template <typename type>
bool Queue<type>::operator<=(const Queue& queue) const {
    return _elements <= queue._elements;
}

template <typename type>
bool Queue<type>::operator>(const Queue& queue) const {
    return _elements > queue._elements;
}

template <typename type>
bool Queue<type>::operator>=(const Queue& queue) const {
    return _elements >= queue._elements;
}

template <typename type>
Queue<type> Queue<type>::operator+(const type& value) {
    Queue<type> queue;
    queue._elements.addAll(_elements);
    enqueue(value);
    return queue;
}

template <typename type>
void Queue<type>::operator+=(const type& value) {
    enqueue(value);
}

template <typename type>
 ostream& operator<<(ostream& out, Queue<type>& queue) {
    out << "{";
    for (int i = 0; i < queue._elements.size(); i++)
        out << " " << queue._elements[i];
    out << " }";
    return out;
 }

 template <typename type>
 ostream& operator<<(ostream& out, const Queue<type>& queue) {
    out << "{";
    for (int i = 0; i < queue._elements.size(); i++)
        out << " " << queue._elements[i];
    out << " }";
    return out;
 }


#endif /// _queue_h
