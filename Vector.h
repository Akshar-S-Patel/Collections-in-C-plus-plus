#ifndef _vector_h
#define _vector_h

#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

/**
 * This class stores an ordered list of values similar to an array.
 * It supports traditional array selection using square brackets, but
 * also supports inserting and deleting elements.  It is similar in
 * function to the STL <code>vector</code> type, but is simpler both
 * to use and to implement.
 */
template <typename type>
class Vector {
public:
    ///  constructors and destructor

    /**
    *  Initialization of new Vector having length of 1
    */
    Vector();

    /**
    *  Initialization of new Vector having length <code>size</code>
    *  @throw "Exception" if <code>size</code> is less then 0
    */
    Vector(int size);

    /**
    *  Initialization of new Vector having length <code>size</code> and contain
    *  <code>value</code> in each block
    *  @throw "Exception" if <code>size</code> is less then 0
    */
    Vector(int size, type value);

    /**
    *  Copy Constructor - use the passed Vector to initialization itself (deep copy)
    */
    Vector(const Vector& list);     ///Copy Construction
    Vector(Vector&& list);          ///Move Constructor


    /**
     * Uses an initializer list to set up the Vector.
     */
    Vector(initializer_list<type> list);


    /**
    *  Clean up all heap memory that are allocate by Vector object
    */
    ~Vector();

    ///  member function (methods)
    /**
    *  add a new value to the end of the Vector
    */
    void push_back(const type& value);

    /**
    *  add a new value to the start of the Vector
    */
    void push_front(const type& value);

    /**
    *  remove a value from the end of the Vector
    *  @throw "Exception" if Vector is empty
    */
    void pop_back();

    /**
    *  remove a value from the start of the Vector
    *  @throw "Exception" if Vector is empty
    */
    void pop_front();

    /**
    *  remove all element from Vector
    */
    void clear();

    /**
     * Returns <code>true</code> if this stack contains exactly the same values
     * as the given other stack.
     * Identical in behavior to the == operator.
     */
    bool equals(const Vector& list) const;

    /**
    *  return the value at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of Vector.
    */
    type at(int index) const;

    /**
    *  return index of a given value if the given value is not there then it return -1
    */
    int contain(const type& value) const;

    /**
    *  insert <code>value</code> at given index <code>index</code>
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of Vector.
    */
    void insert(int index, const type& value);

    /**
    *  return true if Vector is empty else return false
    */
    bool empty() const;

    /**
    *  remove an element at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of Vector.
    */
    void remove(int index);

    /**
    *  set the given element to <code>value</code> at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of Vector.
    */
    void set(int index, const type& value);

    /**
    *  return size of Vector
    */
    int size() const;

    /**
    *  return capacity of Vector
    */
    int capacity() const;

    /**
    *  return value of first element of Vector
    *  @throw "Exception" if Vector is empty
    */
    type& front();
    const type& front() const;

    /**
    *  return value of last element of Vector
    *  @throw "Exception" if Vector is empty
    */
    type& back();
    const type& back() const;

    /**
    *  Exchange the contents of with the passed Vector
    */
    void swap(Vector& list);

    /**
    *  return new Vector having element of for index
    *  <code>start</code> to start + length
    *  @throw Exception if the <code>length</length> is not in the array range or
    *         start is > _size
    */
    Vector subList(int start, int length);

    /**
    *  return new Vector having element of for index
    *  <code>start</code> to end
    *  @throw if start is > _size
    */
    Vector subList(int start);

    /**
    *  pass a function and it apply this function to all its element\
    */
    void map(type (*fn)(type));
    void map(type (*fn)(type&));
    void map(type (*fn)(const type&));

    /**
    *  add a given Vector at the end of caller list or at the given index of caller list
    */
    void addAll(const Vector& list);
    void addAll(int index, const Vector& list);

    /**
    *  remove a given Vector from index to index + length
    */
    void removeAll(int index, int length);
    void removeAll(int index);

    /**
    *  use to sort the list
    */
    void sort();

    /// Operator Overloading

    /**
     * Overloads <code>[]</code> to select elements from this Vector.
     * This extension enables the use of traditional array notation to
     * get or set individual elements.
     * @throw Exception if the index is not in the array range
     */
    type& operator[](const int index);
    const type& operator[](const int index) const;

    /**
     * Overloads = to assign new Vector to left Vector
     */
    Vector& operator=(Vector& list); ///Copy assignment operator
    Vector& operator=(Vector&& list);  ///Take assignment operator

    /**
     * Relational operators to compare two Vector.
     * Each element is compared pairwise to the corresponding element at the
     * same index in the other Vector; for example, we first check the values
     * at index 0, then 1, and so on.
     * The ==, !=, <, >, <=, >= operators require that the <code>type</code>
     * has a ==, < and > operator so that the elements can be compared pairwise.
     */
    bool operator==(const Vector& list) const;
    bool operator!=(const Vector& list) const;
    bool operator<(const Vector& list) const;
    bool operator<=(const Vector& list) const;
    bool operator>(const Vector& list) const;
    bool operator>=(const Vector& list) const;

    /// Arithmetic Operator
    /**
     * Concatenates two Vector and returns the new Vector.
     */
    Vector operator+(Vector& list);

    /**
     * Produces a Vector formed by appending the given value to this Vector.
     */
    Vector operator+(const type& value) ;
    /**
     * Adds all of the elements from <code>list</code> to the end of this Vector.
     */
    void operator+=(const Vector& list);

    /**
     * Adds the single specified value to the end of the Vector.
     */
    void operator+=(const type& value);

    /**
     * Produces a Vector formed by removing the given value to this Vector.
     */
    Vector operator-(const type& value) ;

    /**
     * Remove the single specified value to the end of the Vector.
     */
    void operator-=(const type& value);

    /// Unary Operator

    /**
    *  Change sign of all the values of the given Vector and return new Vector
    */
    Vector operator-();

    template <typename T>
    friend ostream& operator<<(ostream& out, Vector<T>& list);

    template <typename T>
    friend ostream& operator<<(ostream& out, const Vector<T>& list);



private:
    // member variable (fields)
    type* _Vector;
    int _size;
    int _capacity;
};

/** Implementation Section */

template <typename type>
Vector<type>::Vector() {
    _Vector = new type[1]();
    _size = 0;
    _capacity = 1;
}

template <typename type>
Vector<type>::Vector(int size) {
    if (size < 0)
        throw "Exception :-(";
    _Vector = new type[size]();
    _size = size;
    _capacity = size;
}

template <typename type>
Vector<type>::Vector(int size, type value) {
    if (size < 0)
        throw "Exception :-(";
    _Vector = new type[size];

    for (int i = 0; i < size; i++)
        _Vector[i] = value;

    _size = size;
    _capacity = size;
}

template <typename type>
Vector<type>::Vector(const Vector& list) {
    _size = list._size;
    _capacity = list.capacity();
    _Vector = new type[_capacity];

    for (int i = 0; i < _size; i++)
        _Vector[i] = list._Vector[i];
}

template <typename type>
Vector<type>::Vector(Vector&& list) {
    _size = list._size;
    _capacity = list.capacity();
    _Vector = list._Vector;
    list._Vector = nullptr;
}

template <typename type>
Vector<type>::Vector(initializer_list<type> list) {
    _Vector = new type[1]();
    _size = 0;
    _capacity = 1;
    for (type i : list)
        push_back(i);
}

template <typename type>
Vector<type>::~Vector() {
    delete[] _Vector;
}

template <typename type>
void Vector<type>::push_back(const type& value) {
    insert(_size, value);
}

template <typename type>
void Vector<type>::push_front(const type& value) {
    insert(0, value);
}

template <typename type>
void Vector<type>::pop_back() {
    if (_Vector == nullptr)
        throw "Exception :-(";
    remove(_size);
}

template <typename type>
void Vector<type>::pop_front() {
    if (_Vector == nullptr)
        throw "Exception :-(";
    remove(0);
}

template <typename type>
void Vector<type>::clear() {
    delete[] _Vector;
    _size = 0;
    _capacity = 1;
    _Vector = new type[1]();
}

template <typename type>
bool Vector<type>::equals(const Vector<type>& list) const {
    return operator==(list);
}

template <typename type>
type Vector<type>::at(int index) const {
    return _Vector[index];
}

template <typename type>
int Vector<type>::contain(const type& value) const {
    for (int i = 0; i < _size; i++)
        if (_Vector[i] == value)
            return i;
    return -1;
}

template <typename type>
void Vector<type>::insert(int index, const type& value) {
    if (index > _size || index < 0)
        throw "Exception :-(";
    else {
        if (_capacity == _size) {                       /// Check of your Vector is too small
            type* big = new type[2 * _capacity]();      ///then it increase to preferable size

            for (int i = 0; i < _size; i++)
                big[i] = _Vector[i];

            delete[] _Vector;
            _Vector = big;
            _capacity *= 2;
        }
        for (int i = _size; i > index; i--)
            _Vector[i] = _Vector[i - 1];

        _Vector[index] = value;
        _size++;
    }
}

template <typename type>
bool Vector<type>::empty() const {
    return !_size;
}

template <typename type>
void Vector<type>::remove(int index) {
    if (index > _size || index < 0)
        throw "Exception :-(";
    else {
        if (_size == _capacity / 2) {           /// Check of your Vector is too big
            type* small = new type[_size]();    ///then it shrink to preferable size

            for (int i = 0; i < _size; i++)
                small[i] = _Vector[i];

            delete[] _Vector;
            _Vector = small;
            _capacity /= 2;
        }

        for (int i = index; i < _size; i++)
            _Vector[i] = _Vector[i + 1];

        _size--;
    }
}

template <typename type>
void Vector<type>::set(int index, const type& value) {
    if(index < 0 || index + 1 > _size)
        throw "Exception :-(";
    _Vector[index] = value;
}

template <typename type>
int Vector<type>::size() const {
    return _size;
}

template <typename type>
int Vector<type>::capacity() const {
    return _capacity;
}

template <typename type>
type& Vector<type>::front() {
    if (_Vector == nullptr)
        throw "Exception :-(";
    return _Vector[0];
}

template <typename type>
const type& Vector<type>::front() const {
    if (_Vector == nullptr)
        throw "Exception :-(";
    return _Vector[0];
}

template <typename type>
type& Vector<type>::back() {
    if (_Vector == nullptr)
        throw "Exception :-(";
    return _Vector[_size - 1];
}

template <typename type>
const type& Vector<type>::back() const {
    if (_Vector == nullptr)
        throw "Exception :-(";
    return _Vector[_size - 1];
}

template <typename type>
void Vector<type>::swap(Vector& list) {
    type* temp = _Vector;
    int tempSize = _size;
    int tempCapacity = _capacity;

    _Vector = list._Vector;
    _size = list._size;
    _capacity = list.capacity();

    list._Vector = temp;
    list._size = tempSize;
    list._capacity = tempCapacity;
}

template <typename type>
Vector<type> Vector<type>::subList(int start, int length) {
    Vector<type> list;
    if (start > _size || start + length > _size || start < 0 || length < 0)
        throw "Exception :-(";
    else {
        for (int i = start; i < start + length; i++)
            list.push_back(_Vector[i]);
    }
    return list;
}

template <typename type>
Vector<type> Vector<type>::subList(int start) {
    return subList(start, _size - start);
}

template <typename type>
void Vector<type>::map(type (*fn)(type)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void Vector<type>::map(type (*fn)(type&)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void Vector<type>::map(type (*fn)(const type&)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void Vector<type>::addAll(const Vector& list) {
    for (int i = 0; i < list._size; i++)
        push_back(list.at(i));
}

template <typename type>
void Vector<type>::addAll(int index, const Vector& list){
    if (index > _size || index < 0)
        throw "Exception :-(";
    else
        for (int i = 0; i < list._size; i++)
            insert(index + i, list.at(i));
}

template <typename type>
void Vector<type>::removeAll(int index, int length) {
    if (index > _size || index + length > _size || index < 0 || length < 0)
        throw "Exception :-(";
    else
        for (int i = index + length - 1; i >= index; i--)
            remove(i);
}

template <typename type>
void Vector<type>::removeAll(int index) {
    removeAll(index, _size - index);
}

template <typename type>
void Vector<type>::sort() {
    int temp;
    bool flag = true;
    for (int round = 1; round < _size; round++) {
        flag = true;

        for(int i = 0; i < _size - round; i++) {
            if(_Vector[i] > _Vector[i+1]) {
                    flag = false;
                    temp = _Vector[i];
                    _Vector[i] = _Vector[i + 1];
                    _Vector[i + 1] = temp;
               }
        }
        if (flag)
            return;
    }
}

template <typename type>
type& Vector<type>::operator[](const int index) {
    if (index > _size || index < 0)
        throw "Exception :-(";
    else
        return _Vector[index];
}

template <typename type>
const type& Vector<type>::operator[](int index) const {
    if (index > _size || index < 0)
        throw "Exception :-(";
    else
        return _Vector[index];
}

template <typename type>
Vector<type>& Vector<type>::operator=(Vector& list) {
    if (this != &list) {
        delete[] _Vector;
        _size = list._size;
        _capacity = list.capacity();
        _Vector = new type[_capacity];

        for (int i = 0; i < _size; i++)
            _Vector[i] = list._Vector[i];
    }
    return *this;
}

template <typename type>
Vector<type>& Vector<type>::operator=(Vector&& list) {
    _size = list._size;
    _capacity = list.capacity();
    _Vector = list._Vector;
    list._Vector = nullptr;
    return *this;
}

template <typename type>
bool Vector<type>::operator==(const Vector& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_Vector[i] == list._Vector[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool Vector<type>::operator!=(const Vector& list) const {
    return !(operator==(list));
}

template <typename type>
bool Vector<type>::operator<(const Vector& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_Vector[i] < list._Vector[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool Vector<type>::operator<=(const Vector& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_Vector[i] <= list._Vector[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool Vector<type>::operator>(const Vector& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_Vector[i] > list._Vector[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool Vector<type>::operator>=(const Vector& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_Vector[i] >= list._Vector[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
Vector<type> Vector<type>::operator+(Vector& list) {
    Vector<type> list1;

    list1.addAll(subList(0));
    list1.addAll(list.subList(0));

    return list1;
}

template <typename type>
Vector<type> Vector<type>::operator+(const type& value) {
    Vector<type> list1;

    list1.addAll(subList(0));
    list1.push_back(value);

    return list1;
}

template <typename type>
void Vector<type>::operator+=(const Vector& list) {
    addAll(list);
}

template <typename type>
void Vector<type>::operator+=(const type& value) {
    push_back(value);
}

template <typename type>
Vector<type> Vector<type>::operator-(const type& value) {
    Vector<type> list1;

    list1.addAll(subList(0));

    int val = contain(value);
    if (val != -1)
        list1.remove(val);

    return list1;
}

template <typename type>
void Vector<type>::operator-=(const type& value) {
    if (contain(value) != -1)
        remove(contain(value));
}

template <typename type>
Vector<type> Vector<type>::operator-() {
    Vector<type> list1;

    for (int i = 0; i < _size; i++)
        list1.push_back(-at(i));

    return list1;
}


template <typename type>
ostream& operator<<(ostream& out, Vector<type>& list) {
    out << "{ ";
    for (int i = 0; i < list.size(); i++) {
            if (i == list.size() - 1)
                out << list[i];
            else
                out << list[i] << ", ";
    }
    out << " }";
    return out;
}

template <typename type>
ostream& operator<<(ostream& out, const Vector<type>& list) {
    out << "{ ";
    for (int i = 0; i < list.size(); i++) {
            if (i == list.size() - 1)
                out << list[i];
            else
                out << list[i] << ", ";
    }
    out << " }";
    return out;
}


#endif /// _vector_h
