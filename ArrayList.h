#ifndef _ArrayList_h
#define _ArrayList_h

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
class ArrayList {
public:
    ///  constructors and destructor

    /**
    *  Initialization of new ArrayList having length of 1
    */
    ArrayList();

    /**
    *  Initialization of new ArrayList having length <code>size</code>
    *  @throw "Exception" if <code>size</code> is less then 0
    */
    ArrayList(int size);

    /**
    *  Initialization of new ArrayList having length <code>size</code> and contain
    *  <code>value</code> in each block
    *  @throw "Exception" if <code>size</code> is less then 0
    */
    ArrayList(int size, type value);

    /**
    *  Copy Constructor - use the passed ArrayList to initialization itself (deep copy)
    */
    ArrayList(const ArrayList& list);     ///Copy Construction
    ArrayList(ArrayList&& list);          ///Move Constructor


    /**
     * Uses an initializer list to set up the ArrayList.
     */
    ArrayList(initializer_list<type> list);


    /**
    *  Clean up all heap memory that are allocate by ArrayList object
    */
    ~ArrayList();

    ///  member function (methods)
    /**
    *  add a new value to the end of the ArrayList
    */
    void push_back(const type& value);

    /**
    *  remove a value from the end of the ArrayList
    *  @throw "Exception" if ArrayList is empty
    */
    void pop_back();

    /**
    *  remove all element from ArrayList
    */
    void clear();

    /**
     * Returns <code>true</code> if this stack contains exactly the same values
     * as the given other stack.
     * Identical in behavior to the == operator.
     */
    bool equals(const ArrayList& list) const;

    /**
    *  return the value at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of ArrayList.
    */
    type at(int index) const;

    /**
    *  return index of a given value if the given value is not there then it return -1
    */
    int contain(const type& value) const;

    /**
    *  insert <code>value</code> at given index <code>index</code>
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of ArrayList.
    */
    void insert(int index, const type& value);

    /**
    *  return true if ArrayList is empty else return false
    */
    bool empty() const;

    /**
    *  remove an element at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of ArrayList.
    */
    void remove(int index);

    /**
    *  set the given element to <code>value</code> at given index
    *  @throw Exception if the index is not in the array range from 0
    *         up to the length of ArrayList.
    */
    void set(int index, const type& value);

    /**
    *  return size of ArrayList
    */
    int size() const;

    /**
    *  return capacity of ArrayList
    */
    int capacity() const;

    /**
    *  return value of first element of ArrayList
    *  @throw "Exception" if ArrayList is empty
    */
    type& front();
    const type& front() const;

    /**
    *  return value of last element of ArrayList
    *  @throw "Exception" if ArrayList is empty
    */
    type& back();
    const type& back() const;

    /**
    *  Exchange the contents of with the passed ArrayList
    */
    void swap(ArrayList& list);

    /**
    *  return new ArrayList having element of for index
    *  <code>start</code> to start + length
    *  @throw Exception if the <code>length</length> is not in the array range or
    *         start is > _size
    */
    ArrayList subList(int start, int length);

    /**
    *  return new ArrayList having element of for index
    *  <code>start</code> to end
    *  @throw if start is > _size
    */
    ArrayList subList(int start);

    /**
    *  pass a function and it apply this function to all its element\
    */
    void map(type (*fn)(type));
    void map(type (*fn)(type&));
    void map(type (*fn)(const type&));

    /**
    *  add a given ArrayList at the end of caller list or at the given index of caller list
    */
    void addAll(const ArrayList& list);
    void addAll(int index, const ArrayList& list);

    /**
    *  remove a given ArrayList from index to index + length
    */
    void removeAll(int index, int length);
    void removeAll(int index);

    /**
    *  use to sort the list
    */
    void sort();

    /// Operator Overloading

    /**
     * Overloads <code>[]</code> to select elements from this ArrayList.
     * This extension enables the use of traditional array notation to
     * get or set individual elements.
     * @throw Exception if the index is not in the array range
     */
    type& operator[](const int index);
    const type& operator[](const int index) const;

    /**
     * Overloads = to assign new ArrayList to left ArrayList
     */
    ArrayList& operator=(ArrayList& list); ///Copy assignment operator
    ArrayList& operator=(ArrayList&& list);  ///Take assignment operator

    /**
     * Relational operators to compare two ArrayList.
     * Each element is compared pairwise to the corresponding element at the
     * same index in the other ArrayList; for example, we first check the values
     * at index 0, then 1, and so on.
     * The ==, !=, <, >, <=, >= operators require that the <code>type</code>
     * has a ==, < and > operator so that the elements can be compared pairwise.
     */
    bool operator==(const ArrayList& list) const;
    bool operator!=(const ArrayList& list) const;
    bool operator<(const ArrayList& list) const;
    bool operator<=(const ArrayList& list) const;
    bool operator>(const ArrayList& list) const;
    bool operator>=(const ArrayList& list) const;

    /// Arithmetic Operator
    /**
     * Concatenates two ArrayList and returns the new ArrayList.
     */
    ArrayList operator+(ArrayList& list);

    /**
     * Produces a ArrayList formed by appending the given value to this ArrayList.
     */
    ArrayList operator+(const type& value) ;
    /**
     * Adds all of the elements from <code>list</code> to the end of this ArrayList.
     */
    void operator+=(const ArrayList& list);

    /**
     * Adds the single specified value to the end of the ArrayList.
     */
    void operator+=(const type& value);

    /**
     * Produces a ArrayList formed by removing the given value to this ArrayList.
     */
    ArrayList operator-(const type& value) ;

    /**
     * Remove the single specified value to the end of the ArrayList.
     */
    void operator-=(const type& value);

    /// Unary Operator

    /**
    *  Change sign of all the values of the given ArrayList and return new ArrayList
    */
    ArrayList operator-();

    template <typename T>
    friend ostream& operator<<(ostream& out, ArrayList<T>& list);

    template <typename T>
    friend ostream& operator<<(ostream& out, const ArrayList<T>& list);



private:
    // member variable (fields)
    type* _ArrayList;
    int _size;
    int _capacity;
};

/** Implementation Section */

template <typename type>
ArrayList<type>::ArrayList() {
    _ArrayList = new type[1]();
    _size = 0;
    _capacity = 1;
}

template <typename type>
ArrayList<type>::ArrayList(int size) {
    if (size < 0)
        throw "Exception :-(";
    _ArrayList = new type[size]();
    _size = size;
    _capacity = size;
}

template <typename type>
ArrayList<type>::ArrayList(int size, type value) {
    if (size < 0)
        throw "Exception :-(";
    _ArrayList = new type[size];

    for (int i = 0; i < size; i++)
        _ArrayList[i] = value;

    _size = size;
    _capacity = size;
}

template <typename type>
ArrayList<type>::ArrayList(const ArrayList& list) {
    _size = list._size;
    _capacity = list.capacity();
    _ArrayList = new type[_capacity];

    for (int i = 0; i < _size; i++)
        _ArrayList[i] = list._ArrayList[i];
}

template <typename type>
ArrayList<type>::ArrayList(ArrayList&& list) {
    _size = list._size;
    _capacity = list.capacity();
    _ArrayList = list._ArrayList;
    list._ArrayList = nullptr;
}

template <typename type>
ArrayList<type>::ArrayList(initializer_list<type> list) {
    _ArrayList = new type[1]();
    _size = 0;
    _capacity = 1;
    for (type i : list)
        push_back(i);
}

template <typename type>
ArrayList<type>::~ArrayList() {
    delete[] _ArrayList;
}

template <typename type>
void ArrayList<type>::push_back(const type& value) {
    insert(_size, value);
}

template <typename type>
void ArrayList<type>::pop_back() {
    if (_ArrayList == nullptr)
        throw "Exception :-(";
    remove(_size);
}

template <typename type>
void ArrayList<type>::clear() {
    delete[] _ArrayList;
    _size = 0;
    _capacity = 1;
    _ArrayList = new type[1]();
}

template <typename type>
bool ArrayList<type>::equals(const ArrayList<type>& list) const {
    return operator==(list);
}

template <typename type>
type ArrayList<type>::at(int index) const {
    return _ArrayList[index];
}

template <typename type>
int ArrayList<type>::contain(const type& value) const {
    for (int i = 0; i < _size; i++)
        if (_ArrayList[i] == value)
            return i;
    return -1;
}

template <typename type>
void ArrayList<type>::insert(int index, const type& value) {
    if (index > _size || index < 0)
        throw "Exception :-(";
    else {
        if (_capacity == _size) {                       /// Check of your ArrayList is too small
            type* big = new type[2 * _capacity]();      ///then it increase to preferable size

            for (int i = 0; i < _size; i++)
                big[i] = _ArrayList[i];

            delete[] _ArrayList;
            _ArrayList = big;
            _capacity *= 2;
        }
        for (int i = _size; i > index; i--)
            _ArrayList[i] = _ArrayList[i - 1];

        _ArrayList[index] = value;
        _size++;
    }
}

template <typename type>
bool ArrayList<type>::empty() const {
    return !_size;
}

template <typename type>
void ArrayList<type>::remove(int index) {
    if (index > _size || index < 0)
        throw "Exception :-(";
    else {
        if (_size == _capacity / 2) {           /// Check of your ArrayList is too big
            type* small = new type[_size]();    ///then it shrink to preferable size

            for (int i = 0; i < _size; i++)
                small[i] = _ArrayList[i];

            delete[] _ArrayList;
            _ArrayList = small;
            _capacity /= 2;
        }

        for (int i = index; i < _size; i++)
            _ArrayList[i] = _ArrayList[i + 1];

        _size--;
    }
}

template <typename type>
void ArrayList<type>::set(int index, const type& value) {
    _ArrayList[index] = value;
}

template <typename type>
int ArrayList<type>::size() const {
    return _size;
}

template <typename type>
int ArrayList<type>::capacity() const {
    return _capacity;
}

template <typename type>
type& ArrayList<type>::front() {
    if (_ArrayList == nullptr)
        throw "Exception :-(";
    return _ArrayList[0];
}

template <typename type>
const type& ArrayList<type>::front() const {
    if (_ArrayList == nullptr)
        throw "Exception :-(";
    return _ArrayList[0];
}

template <typename type>
type& ArrayList<type>::back() {
    if (_ArrayList == nullptr)
        throw "Exception :-(";
    return _ArrayList[_size - 1];
}

template <typename type>
const type& ArrayList<type>::back() const {
    if (_ArrayList == nullptr)
        throw "Exception :-(";
    return _ArrayList[_size - 1];
}

template <typename type>
void ArrayList<type>::swap(ArrayList& list) {
    type* temp = _ArrayList;
    int tempSize = _size;
    int tempCapacity = _capacity;

    _ArrayList = list._ArrayList;
    _size = list._size;
    _capacity = list.capacity();

    list._ArrayList = temp;
    list._size = tempSize;
    list._capacity = tempCapacity;
}

template <typename type>
ArrayList<type> ArrayList<type>::subList(int start, int length) {
    ArrayList<type> list;
    if (start > _size || start + length > _size || start < 0 || length < 0)
        throw "Exception :-(";
    else {
        for (int i = start; i < start + length; i++)
            list.push_back(_ArrayList[i]);
    }
    return list;
}

template <typename type>
ArrayList<type> ArrayList<type>::subList(int start) {
    return subList(start, _size - start);
}

template <typename type>
void ArrayList<type>::map(type (*fn)(type)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void ArrayList<type>::map(type (*fn)(type&)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void ArrayList<type>::map(type (*fn)(const type&)) {
    for (int i = 0; i < _size; i++)
        set(i, fn(at(i)));
}

template <typename type>
void ArrayList<type>::addAll(const ArrayList& list) {
    for (int i = 0; i < list._size; i++)
        push_back(list.at(i));
}

template <typename type>
void ArrayList<type>::addAll(int index, const ArrayList& list){
    if (index > _size || index < 0)
        throw "Exception :-(";
    else
        for (int i = 0; i < list._size; i++)
            insert(index + i, list.at(i));
}

template <typename type>
void ArrayList<type>::removeAll(int index, int length) {
    if (index > _size || index + length > _size || index < 0 || length < 0)
        throw "Exception :-(";
    else
        for (int i = index + length - 1; i >= index; i--)
            remove(i);
}

template <typename type>
void ArrayList<type>::removeAll(int index) {
    removeAll(index, _size - index);
}

template <typename type>
void ArrayList<type>::sort() {
    int temp;
    bool flag = true;
    for (int round = 1; round < _size; round++) {
        flag = true;

        for(int i = 0; i < _size - round; i++) {
            if(_ArrayList[i] > _ArrayList[i+1]) {
                    flag = false;
                    temp = _ArrayList[i];
                    _ArrayList[i] = _ArrayList[i + 1];
                    _ArrayList[i + 1] = temp;
               }
        }
        if (flag)
            return;
    }
}

template <typename type>
type& ArrayList<type>::operator[](const int index) {
    if (index > _size || index < 0)
        throw "Exception :-(";
    else
        return _ArrayList[index];
}

template <typename type>
const type& ArrayList<type>::operator[](int index) const {
    if (index > _size || index < 0)
        throw "Exception :-(";
    else
        return _ArrayList[index];
}

template <typename type>
ArrayList<type>& ArrayList<type>::operator=(ArrayList& list) {
    if (this != &list) {
        delete[] _ArrayList;
        _size = list._size;
        _capacity = list.capacity();
        _ArrayList = new type[_capacity];

        for (int i = 0; i < _size; i++)
            _ArrayList[i] = list._ArrayList[i];
    }
    return *this;
}

template <typename type>
ArrayList<type>& ArrayList<type>::operator=(ArrayList&& list) {
    _size = list._size;
    _capacity = list.capacity();
    _ArrayList = list._ArrayList;
    list._ArrayList = nullptr;
    return *this;
}

template <typename type>
bool ArrayList<type>::operator==(const ArrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_ArrayList[i] == list._ArrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool ArrayList<type>::operator!=(const ArrayList& list) const {
    return !(operator==(list));
}

template <typename type>
bool ArrayList<type>::operator<(const ArrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_ArrayList[i] < list._ArrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool ArrayList<type>::operator<=(const ArrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_ArrayList[i] <= list._ArrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool ArrayList<type>::operator>(const ArrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_ArrayList[i] > list._ArrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool ArrayList<type>::operator>=(const ArrayList& list) const {
    if (_size == list._size) {
        for (int i = 0; i < _size; i++) {
            if (!(_ArrayList[i] >= list._ArrayList[i]))
                return false;
        }
        return true;
    }
    return false;
}

template <typename type>
ArrayList<type> ArrayList<type>::operator+(ArrayList& list) {
    ArrayList<type> list1;

    list1.addAll(subList(0));
    list1.addAll(list.subList(0));

    return list1;
}

template <typename type>
ArrayList<type> ArrayList<type>::operator+(const type& value) {
    ArrayList<type> list1;

    list1.addAll(subList(0));
    list1.push_back(value);

    return list1;
}

template <typename type>
void ArrayList<type>::operator+=(const ArrayList& list) {
    addAll(list);
}

template <typename type>
void ArrayList<type>::operator+=(const type& value) {
    push_back(value);
}

template <typename type>
ArrayList<type> ArrayList<type>::operator-(const type& value) {
    ArrayList<type> list1;

    list1.addAll(subList(0));

    int val = contain(value);
    if (val != -1)
        list1.remove(val);

    return list1;
}

template <typename type>
void ArrayList<type>::operator-=(const type& value) {
    if (contain(value) != -1)
        remove(contain(value));
}

template <typename type>
ArrayList<type> ArrayList<type>::operator-() {
    ArrayList<type> list1;

    for (int i = 0; i < _size; i++)
        list1.push_back(-at(i));

    return list1;
}


template <typename type>
ostream& operator<<(ostream& out, ArrayList<type>& list) {
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
ostream& operator<<(ostream& out, const ArrayList<type>& list) {
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


#endif /// _ArrayList_h
