#ifndef _arraylist_h
#define _arraylist_h

#include<iostream>
#include<string>
using namespace std;

/**
 * This class stores an ordered list of values similar to an array.
 * It supports traditional array selection using square brackets, but
 * also supports inserting and deleting elements.  It is similar in
 * function to the STL <code>vector</code> type, but is simpler both
 * to use and to implement.
 */
template <typename type>
class arrayList {
public:
    ///  constructors and destructor

    /**
    *  Initialization of new arrayList having length of 1
    */
    arrayList();

    /**
    *  Initialization of new arrayList having length <code>size</code>
    */
    arrayList(int size);

    /**
    *  Initialization of new arrayList having length <code>size</code> and contain
    *  <code>value</code> in each block
    */
    arrayList(int size, type value);

    /**
    *  Copy Constructor - use the passed arrayList to initialization itself (deep copy)
    */
    arrayList(arrayList& list);
    arrayList(arrayList&& list);

    /**
    *  Clean up all heap memory that are allocate by arrayList object
    */
    ~arrayList();

    ///  member function (methods)
    /**
    *  add a new value to the end of the arrayList
    */
    void push_back(const type& value);

    /**
    *  remove a value from the end of the arrayList
    */
    void pop_back();

    /**
    *  remove all element from arrayList
    */
    void clear();

    /**
     * Returns <code>true</code> if this stack contains exactly the same values
     * as the given other stack.
     * Identical in behavior to the == operator.
     */
    bool equals(const arrayList& list) const;

    /**
    *  return the value at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of arrayList.
    */
    type at(int index) const;

    /**
    *  return index of a given value if the given value is not there then it return -1
    */
    int contain(const type& value) const;

    /**
    *  insert <code>value</code> at given index <code>index</code>
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of arrayList.
    */
    void insert(int index, const type& value);

    /**
    *  return true if arrayList is empty else return false
    */
    bool empty() const;

    /**
    *  remove an element at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of arrayList.
    */
    void remove(int index);

    /**
    *  set the given element to <code>value</code> at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of arrayList.
    */
    void set(int index, const type& value);

    /**
    *  return size of arrayList
    */
    int size() const;

    /**
    *  return capacity of arrayList
    */
    int capacity() const;

    /**
    *  return value of first element of arrayList
    */
    type front();

    /**
    *  return value of last element of arrayList
    */
    type back();

    /**
    *  Exchange the contents of with the passed arrayList
    */
    void swap(arrayList& list);

    /**
    *  return new arrayList having element of for index
    *  <code>start</code> to start + length
    *  @throw Exception if the <code>length</length> is not in the array range or
    *         start is > _size
    */
    arrayList subList(int start, int length);

    /**
    *  return new arrayList having element of for index
    *  <code>start</code> to end
    *  @throw if start is > _size
    */
    arrayList subList(int start);

    /**
    *  pass a function and it apply this function to all its element\
    */
    void map(type (*fn)(type));
    void map(type (*fn)(type&));
    void map(type (*fn)(const type&));

    /**
    *  add a given arrayList at the end of caller list or at the given index of caller list
    */
    void addAll(const arrayList& list);
    void addAll(int index, const arrayList& list);

    /**
    *  remove a given arrayList from index to index + length
    */
    void removeAll(int index, int length);
    void removeAll(int index);

    /**
    *  use to sort the list
    */
    void sort();

    /// Operator Overloading

    /**
     * Overloads <code>[]</code> to select elements from this arrayList.
     * This extension enables the use of traditional array notation to
     * get or set individual elements.
     * @throw Exception if the index is not in the array range
     */
    type& operator[](const int index) const;

    /**
     * Overloads = to assign new arrayList to left arrayList
     */
    void operator=(arrayList&& list);
    void operator=(arrayList& list);

    /**
     * Relational operators to compare two arrayList.
     * Each element is compared pairwise to the corresponding element at the
     * same index in the other arrayList; for example, we first check the values
     * at index 0, then 1, and so on.
     * The ==, !=, <, >, <=, >= operators require that the <code>type</code>
     * has a ==, < and > operator so that the elements can be compared pairwise.
     */
    bool operator==(const arrayList& list) const;
    bool operator!=(const arrayList& list) const;
    bool operator<(const arrayList& list) const;
    bool operator<=(const arrayList& list) const;
    bool operator>(const arrayList& list) const;
    bool operator>=(const arrayList& list) const;

    /// Arithmetic Operator
    /**
     * Concatenates two arrayList and returns the new arrayList.
     */
    arrayList operator+(arrayList& list);

    /**
     * Produces a arrayList formed by appending the given value to this arrayList.
     */
    arrayList operator+(const type& value) ;
    /**
     * Adds all of the elements from <code>list</code> to the end of this arrayList.
     */
    void operator+=(const arrayList& list);

    /**
     * Adds the single specified value to the end of the arrayList.
     */
    void operator+=(const type& value);

    /**
     * Produces a arrayList formed by removing the given value to this arrayList.
     */
    arrayList operator-(const type& value) ;

    /**
     * Remove the single specified value to the end of the arrayList.
     */
    void operator-=(const type& value);

    /// Unary Operator

    /**
    *  Change sign of all the values of the given arrayList and return new arrayList
    */
    arrayList operator-();



private:
    // member variable (fields)
    type* _arrayList;
    int _size;
    int _capacity;
};

/** Implementation Section */

template <typename type>
arrayList<type>::arrayList() {
    _arrayList = new type[1]();
    _size = 0;
    _capacity = 1;
}

template <typename type>
arrayList<type>::arrayList(int size) {
    _arrayList = new type[size]();
    _size = 0;
    _capacity = size;
}

template <typename type>
arrayList<type>::arrayList(int size, type value) {
    _arrayList = new type[size];

    for (int i = 0; i < size; i++)
        _arrayList[i] = value;

    _size = size;
    _capacity = size;
}

template <typename type>
arrayList<type>::arrayList(arrayList& list) {
    _size = list._size;
    _capacity = list.capacity();
    _arrayList = new type[_capacity];

    for (int i = 0; i < _size; i++)
        _arrayList[i] = list._arrayList[i];
}

template <typename type>
arrayList<type>::arrayList(arrayList&& list) {
    _size = list._size;
    _capacity = list.capacity();
    _arrayList = new type[_capacity];

    for (int i = 0; i < _size; i++)
        _arrayList[i] = list._arrayList[i];
}

template <typename type>
arrayList<type>::~arrayList() {
    delete[] _arrayList;
}

template <typename type>
void arrayList<type>::push_back(const type& value) {
    insert(_size, value);
}

template <typename type>
void arrayList<type>::pop_back() {
    remove(_size);
}

template <typename type>
void arrayList<type>::clear() {
    delete[] _arrayList;
    _size = 0;
    _capacity = 1;
    _arrayList = new type[1]();
}

template <typename type>
bool arrayList<type>::equals(const arrayList<type>& list) const {
    return operator==(list);
}

template <typename type>
type arrayList<type>::at(int index) const {
    return _arrayList[index];
}

template <typename type>
int arrayList<type>::contain(const type& value) const {
    for (int i = 0; i < _size; i++)
        if (_arrayList[i] == value)
            return i;
    return -1;
}

template <typename type>
void arrayList<type>::insert(int index, const type& value) {
    if (index > _size)
        throw "Exception :-(";
    else {
        if (_capacity == _size) {                       /// Check of your arrayList is too small
            type* big = new type[2 * _capacity]();      ///then it increase to preferable size

            for (int i = 0; i < _size; i++)
                big[i] = _arrayList[i];

            delete[] _arrayList;
            _arrayList = big;
            _capacity *= 2;
        }
        for (int i = _size; i > index; i--)
            _arrayList[i] = _arrayList[i - 1];

        _arrayList[index] = value;
        _size++;
    }
}

template <typename type>
bool arrayList<type>::empty() const {
    return !_size;
}

template <typename type>
void arrayList<type>::remove(int index) {
    if (index > _size)
        throw "Exception :-(";
    else {
        if (_size == _capacity / 2) {           /// Check of your arrayList is too big
            type* small = new type[_size]();    ///then it shrink to preferable size

            for (int i = 0; i < _size; i++)
                small[i] = _arrayList[i];

            delete[] _arrayList;
            _arrayList = small;
            _capacity /= 2;
        }

        for (int i = index; i < _size; i++)
            _arrayList[i] = _arrayList[i + 1];

        _size--;
    }
}

template <typename type>
void arrayList<type>::set(int index, const type& value) {
    _arrayList[index] = value;
}

template <typename type>
int arrayList<type>::size() const {
    return _size;
}

template <typename type>
int arrayList<type>::capacity() const {
    return _capacity;
}

template <typename type>
type arrayList<type>::front() {
    return _arrayList[0];
}

template <typename type>
type arrayList<type>::back() {
    return _arrayList[_size - 1];
}

template <typename type>
void arrayList<type>::swap(arrayList& list) {
    type* temp = _arrayList;
    int tempSize = _size;
    int tempCapacity = _capacity;

    _arrayList = list._arrayList;
    _size = list._size;
    _capacity = list.capacity();

    list._arrayList = temp;
    list._size = tempSize;
    list._capacity = tempCapacity;
}

template <typename type>
arrayList<type> arrayList<type>::subList(int start, int length) {
    arrayList<type> list;
    if (start > _size || start + length > _size)
        throw "Exception :-(";
    else {
        for (int i = start; i < start + length; i++)
            list.push_back(_arrayList[i]);
    }
    return list;
}

template <typename type>
arrayList<type> arrayList<type>::subList(int start) {
    return subList(start, _size - start);
}

template <typename type>
void arrayList<type>::map(type (*fn)(type)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void arrayList<type>::map(type (*fn)(type&)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void arrayList<type>::map(type (*fn)(const type&)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void arrayList<type>::addAll(const arrayList& list) {
    for (int i = 0; i < list._size; i++)
        push_back(list.at(i));
}

template <typename type>
void arrayList<type>::addAll(int index, const arrayList& list){
    if (index > _size)
        throw "Exception :-(";
    else
        for (int i = 0; i < list._size; i++)
            insert(index + i, list.at(i));
}

template <typename type>
void arrayList<type>::removeAll(int index, int length) {
    if (index > _size || index + length > _size)
        throw "Exception :-(";
    else
        for (int i = index + length - 1; i >= index; i--)
            remove(i);
}

template <typename type>
void arrayList<type>::removeAll(int index) {
    removeAll(index, _size - index);
}

template <typename type>
void arrayList<type>::sort() {
    int temp;
    bool flag = true;
    for (int round = 1; round < _size; round++) {
        flag = true;

        for(int i = 0; i < _size - round; i++) {
            if(_arrayList[i] > _arrayList[i+1]) {
                    flag = false;
                    temp = _arrayList[i];
                    _arrayList[i] = _arrayList[i + 1];
                    _arrayList[i + 1] = temp;
               }
        }
        if (flag)
            return;
    }
}

template <typename type>
type& arrayList<type>::operator[](const int index) const {
    if (index > _size)
        throw "Exception :-(";
    else
        return _arrayList[index];
}

template <typename type>
void arrayList<type>::operator=(arrayList&& list) {
    delete[] _arrayList;
    _size = list._size;
    _capacity = list.capacity();
    _arrayList = new type[_capacity];

    for (int i = 0; i < _size; i++)
        _arrayList[i] = list._arrayList[i];
}

template <typename type>
void arrayList<type>::operator=(arrayList& list) {
    delete[] _arrayList;
    _size = list._size;
    _capacity = list.capacity();
    _arrayList = new type[_capacity];

    for (int i = 0; i < _size; i++)
        _arrayList[i] = list._arrayList[i];
}

template <typename type>
bool arrayList<type>::operator==(const arrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_arrayList[i] == list._arrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool arrayList<type>::operator!=(const arrayList& list) const {
    return !(operator==(list));
}

template <typename type>
bool arrayList<type>::operator<(const arrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_arrayList[i] < list._arrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool arrayList<type>::operator<=(const arrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_arrayList[i] <= list._arrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool arrayList<type>::operator>(const arrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_arrayList[i] > list._arrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool arrayList<type>::operator>=(const arrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_arrayList[i] >= list._arrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
arrayList<type> arrayList<type>::operator+(arrayList& list) {
    arrayList<type> list1;

    list1.addAll(subList(0));
    list1.addAll(list.subList(0));

    return list1;
}

template <typename type>
arrayList<type> arrayList<type>::operator+(const type& value) {
    arrayList<type> list1;

    list1.addAll(subList(0));
    list1.push_back(value);

    return list1;
}

template <typename type>
void arrayList<type>::operator+=(const arrayList& list) {
    addAll(list);
}

template <typename type>
void arrayList<type>::operator+=(const type& value) {
    push_back(value);
}

template <typename type>
arrayList<type> arrayList<type>::operator-(const type& value) {
    arrayList<type> list1;

    list1.addAll(subList(0));

    int val = contain(value);
    if (val != -1)
        list1.remove(val);

    return list1;
}

template <typename type>
void arrayList<type>::operator-=(const type& value) {
    if (contain(value) != -1)
        remove(contain(value));
}

template <typename type>
arrayList<type> arrayList<type>::operator-() {
    arrayList<type> list1;

    for (int i = 0; i < _size; i++)
        list1.push_back(-at(i));

    return list1;
}


template <typename type>
ostream& operator<<(ostream& out, arrayList<type>& list) {
    out << "{ ";
    for (int i = 0; i < list.size(); i++) {
            out << list[i] << " ";
    }
    out << "}";
    return out;
}


#endif /// _arraylist_h
