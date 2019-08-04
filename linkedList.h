#ifndef _linkedlist_h
#define _linkedlist_h

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

/**
 * This class stores an ordered list of values similar to an array.
 * It supports traditional array selection using square brackets, but
 * also supports inserting and deleting elements.  It is similar in
 * function to the STL <code>list</code> type.
 */
template <typename nodeType>
struct Node {
        nodeType data;
        Node* next;

        Node(nodeType d = nodeType(), Node* n = nullptr) {
            data = d;
            next = n;
        }
    };

template <typename type>
class linkedList {
public:
    ///  constructors and destructor

    /**
    *  Initialization of new empty linkedList
    */
    linkedList();

    /**
    *  Copy Constructor - use the passed linkedList to initialization itself (deep copy)
    */
    linkedList(const linkedList& list); ///Copy Constructor
    linkedList(linkedList&& list);      ///Take Constructor

    /**
    *  Use a initializer list to set up linked list
    */
    linkedList(initializer_list<type> list);

    /**
    *  Clean up all the memory which are allocated by linkedList object
    */
    ~linkedList();

    ///  member function (methods)

    /**
    *  Add element at the start of linkedList
    */
    void push_front(const type& value);

    /**
    *  Add element at the end of linkedList
    */
    void push_back(const type& value);

    /**
    *  Remove element from the start of linkedList
    */
    void pop_back();

    /**
    *  Remove element from the start of linkedList
    */
    void pop_front();

    /**
    *  Clear whole linkedList
    */
    void clear();

    /**
    *  return the element at given index <code>index</code>
    *  @throw Exception if the index is not in range of linkedList
    */
    type at(int index) const;

    /**
    *  Return index of <code>value</code> if not there there then it return -1
    */
    int contain(const type& value) const;

    /**
    *  Insert a <code>value</code> at given index <code>index</code>
    *  @throw Exception if the index is not in range of linkedList
    */
    void insert(int index, const type& value);

    /**
    *  Return true if the linkedList is empty or else return false
    */
    bool empty() const;

    /**
     * Returns <code>true</code> if this stack contains exactly the same values
     * as the given other stack.
     * Identical in behavior to the == operator.
     */
    bool equals(const linkedList& list) const;

    /**
    *  remove the element at the given index <code>index</code>
    *  @throw Exception if index is not in range of linkedList
    */
    void remove(int index);

    /**
    *  Set the <code>value</code> of the given index <code>index</code>
    *  @throw Exception if index is not in range of linkedList
    */
    void set(int index, const type& value);

    /**
    *  return the size of linkedList
    */
    int size() const;

    /**
    *  return the first element of linkedList
    */
    type front() const;

    /**
    *  return the last element of linkedList
    */
    type back() const;

    /**
    *  swap the linkedList with given linkedList
    */
    void swap(linkedList& list);

    /**
    *  return the linkedList from index <code>start</code>
    *  to <code>start + length</code>
    *  @throw Exception if start is is not in range of linkedList or
    *         start + length is not range of linkedList
    */
    linkedList subList(int start, int length);
    linkedList subList(int start);

    /**
    *  implement the given function to whole linkedList
    */
    void map(int (*fn)(type));
    void map(int (*fn)(type&));
    void map(int (*fn)(const type&));

    /**
    *  add all the element to the end or at the given index of the list
    *  @throw Exception if index is is not in range of linkedList
    */
    void addAll(const linkedList& list);
    void addAll(int index, const linkedList& list);

    /**
    *  remove the elements
    *  @throw Exception if index is is not in range of linkedList or
    *         index + length is not range of linkedList
    */
    void removeAll(int index, int length);
    void removeAll(int index);

    /**
    *  sort the linkedList
    */
    void sort();

    /// Operator overloading

    type operator[](int index) const;

    /**
     * Overloads = to assign new linkedList to left linkedList
     */
    linkedList& operator=(const linkedList& list);
    linkedList& operator=(linkedList&& list);

    /**
     * Relational operators to compare two linkedList.
     * Each element is compared pairwise to the corresponding element at the
     * same index in the other linkedList; for example, we first check the values
     * at index 0, then 1, and so on.
     * The ==, !=, <, >, <=, >= operators require that the <code>type</code>
     * has a ==, < and > operator so that the elements can be compared pairwise.
     */
    bool operator==(const linkedList& list) const;
    bool operator!=(const linkedList& list) const;
    bool operator<(const linkedList& list) const;
    bool operator<=(const linkedList& list) const;
    bool operator>(const linkedList& list) const;
    bool operator>=(const linkedList& list) const;

    /// Arithmetic Operator
    /**
     * Concatenates two linkedList and returns the new linkedList.
     */
    linkedList operator+(linkedList& list);

    /**
     * Produces a linkedList formed by appending the given value to this linkedList.
     */
    linkedList operator+(const type& value) ;
    /**
     * Adds all of the elements from <code>list</code> to the end of this linkedList.
     */
    void operator+=(const linkedList& list);

    /**
     * Adds the single specified value to the end of the linkedList.
     */
    void operator+=(const type& value);

    /**
     * Produces a linkedList formed by removing the given value to this linkedList.
     */
    linkedList operator-(const type& value) ;

    /**
     * Remove the single specified value to the end of the linkedList.
     */
    void operator-=(const type& value);

    /// Unary Operator

    /**
    *  Change sign of all the values of the given linkedList and return new linkedList
    */
    linkedList operator-();

    /**
    *  Use to print the linkedList using << operator
    */
    template <typename T>
    friend ostream& operator<<(ostream& out, linkedList<T>& list);

private:

    Node<type>* start;
    int _size;
};

template <typename type>
linkedList<type>::linkedList() {
    start = nullptr;
    _size = 0;
}

template <typename type>
linkedList<type>::linkedList(const linkedList& list) {
    _size = 0;
    start = nullptr;
    Node<type>* temp = list.start;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}

template <typename type>
linkedList<type>::linkedList(linkedList&& list) {
    _size = 0;
    start = list.start;
    list.start = nullptr;
}

template <typename type>
linkedList<type>::linkedList(initializer_list<type> list) {
    start = nullptr;
    _size = 0;
    for (type i : list)
        push_back(i);
}

template <typename type>
linkedList<type>::~linkedList() {
    clear();
}

template <typename type>
void linkedList<type>::push_front(const type& value) {
    insert(0, value);
}

template <typename type>
void linkedList<type>::push_back(const type& value) {
    insert(_size, value);
}

template <typename type>
void linkedList<type>::pop_front() {
    remove(0);
}

template <typename type>
void linkedList<type>::pop_back() {
    remove(_size - 1);
}

template <typename type>
void linkedList<type>::clear() {
    Node<type>* trash;
    while (start != nullptr) {
        trash = start;
        start = start->next;
        delete trash;
    }
    _size = 0;
}

template <typename type>
bool linkedList<type>::equals(const linkedList<type>& list) const {
    return operator==(list);
}

template <typename type>
type linkedList<type>::at(int index) const {
    if (index >= _size)
        throw "Exception :-(";
    else {
        Node<type>* temp = start;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        return temp->data;
    }
}

template <typename type>
int linkedList<type>::contain(const type& value) const {
    Node<type>* temp = start;
    for (int i = 0; i < _size; i++) {
        if (temp->data == value)
            return i;
        temp = temp->next;
    }
    return -1;
}

template <typename type>
void linkedList<type>::insert(int index, const type& value) {
    if (index > _size)
        throw "Exception :-(";
    else if (start == nullptr) {
        Node<type>* newNode = new Node<type>(value);
        start = newNode;
        _size++;
    } else if (index == 0) {
        Node<type>* newNode = new Node<type>(value, start);
        start = newNode;
        _size++;
    } else {
        Node<type>* temp = start;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;
        Node<type>* newNode = new Node<type>(value,temp->next);
        temp->next = newNode;
        _size++;
    }
}

template <typename type>
bool linkedList<type>::empty() const {
    return !_size;
}

template <typename type>
void linkedList<type>::remove(int index) {
    if (index >= _size)
        throw "Exception :-(";
    else if (start == nullptr)
        throw "Exception :-(";
    else if (index == 0) {
        Node<type>* trash = start;
        start = start->next;
        delete trash;
        _size--;
    } else {
        Node<type>* temp = start;
        Node<type>* trash;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;
        trash = temp->next;
        temp->next = trash->next;
        delete trash;
        _size--;
    }
}

template <typename type>
void linkedList<type>::set(int index, const type& value) {
    Node<type>* temp = start;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    temp->data = value;
}

template <typename type>
int linkedList<type>::size() const {
    return _size;
}

template <typename type>
type linkedList<type>::front() const {
    return at(0);
}

template <typename type>
type linkedList<type>::back() const {
    return at(_size - 1);
}

template <typename type>
void linkedList<type>::swap(linkedList& list) {
    Node<type>* temp_start= start;
    int temp_size = _size;

    start = list.start;
    _size = list._size;

    list.start = temp_start;
    list._size = temp_size;
}

template <typename type>
linkedList<type> linkedList<type>::subList(int start, int length) {
    linkedList<type> list;
    if (start > _size || start + length > _size)
        throw "Exception :-(";
    else {
        for (int i = start; i < start + length; i++)
            list.push_back(at(i));
    }
    return list;
}

template <typename type>
linkedList<type> linkedList<type>::subList(int start) {
    return subList(start, _size - start);
}

template <typename type>
void linkedList<type>::map(int (*fn)(type)) {
    Node<type>* temp = start;
    while (temp != nullptr) {
        temp->data = fn(temp->data);
        temp = temp->next;
    }
}

template <typename type>
void linkedList<type>::map(int (*fn)(type&)) {
    Node<type>* temp = start;
    for (int i = 0; i < _size; i++) {
        temp->data = fn(temp->data);
        temp = temp->next;
    }
}

template <typename type>
void linkedList<type>::map(int (*fn)(const type&)) {
    Node<type>* temp = start;
    for (int i = 0; i < _size; i++) {
        temp->data = fn(temp->data);
        temp = temp->next;
    }
}

template <typename type>
void linkedList<type>::addAll(const linkedList& list) {
    Node<type>* temp = start;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = list.start;
    _size += list._size;
}

template <typename type>
void linkedList<type>::addAll(int index, const linkedList& list) {
    if (index > _size)
        throw "Exception :-(";
    else {
        Node<type>* temp1 = start;
        Node<type>* temp2 = list.start;
        for (int i = 0; i < index - 1; i++)
            temp1 = temp1->next;
        while (temp2->next != nullptr)
            temp2 = temp2->next;
        temp2->next = temp1->next;
        temp1->next = list.start;
        _size += list._size;
    }
}

template <typename type>
void linkedList<type>::removeAll(int index, int length) {
    vector<Node<type>*> tresh;
    Node<type>* first;
    Node<type>* temp = start;
    if (index > _size || index + length > _size)
        throw "Exception :-(";
    else
        for (int i = 0; i < index + length; i++) {
            if (i == index - 1)
                first = temp;
            if (i >= index)
                tresh.push_back(temp);
            temp = temp->next;
        }
        first->next = temp;
        for (Node<type>* n : tresh)
            delete n;
}

template <typename type>
void linkedList<type>::removeAll(int index) {
    removeAll(index, _size - index);
}

template <typename type>
void linkedList<type>::sort() {
    type temp1;
    Node<type>* temp2 = start;
    bool flag = true;
    for (int round = 1; round < _size; round++) {
        flag = true;
        temp2 = start;
        for(int i = 0; i < _size - round; i++) {
            if(temp2->data > temp2->next->data) {
                flag = false;
                temp1 = temp2->data;
                temp2->data = temp2->next->data;
                temp2->next->data = temp1;
            }
            temp2 = temp2->next;
        }
        if (flag)
            return;
    }
}

template <typename type>
type linkedList<type>::operator[](int index) const {
    return at(index);
}


template <typename type>
linkedList<type>& linkedList<type>::operator=(const linkedList& list) {
    if (this != &list) {
        Node<type>* temp = list.start;
        while (temp != nullptr) {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

template <typename type>
linkedList<type>& linkedList<type>::operator=(linkedList&& list) {
    start = list.start;
    list.start = nullptr;
    return *this;
}

template <typename type>
bool linkedList<type>::operator==(const linkedList& list) const {
    Node<type>* temp1 = start;
    Node<type>* temp2 = list.start;
    if (_size == list._size) {
        while (temp1 != nullptr) {
            if (!(temp1->data == temp2->data))
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    return false;
}

template <typename type>
bool linkedList<type>::operator!=(const linkedList& list) const {
    return !(operator==(list));
}

template <typename type>
bool linkedList<type>::operator<(const linkedList& list) const {
   Node<type>* temp1 = start;
    Node<type>* temp2 = list.start;
    if (_size == list._size) {
        while (temp1 != nullptr) {
            if (!(temp1->data < temp2->data))
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    return false;
}

template <typename type>
bool linkedList<type>::operator<=(const linkedList& list) const {
     Node<type>* temp1 = start;
    Node<type>* temp2 = list.start;
    if (_size == list._size) {
        while (temp1 != nullptr) {
            if (!(temp1->data <= temp2->data))
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    return false;
}

template <typename type>
bool linkedList<type>::operator>(const linkedList& list) const {
    Node<type>* temp1 = start;
    Node<type>* temp2 = list.start;
    if (_size == list._size) {
        while (temp1 != nullptr) {
            if (!(temp1->data > temp2->data))
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    return false;
}

template <typename type>
bool linkedList<type>::operator>=(const linkedList& list) const {
     Node<type>* temp1 = start;
    Node<type>* temp2 = list.start;
    if (_size == list._size) {
        while (temp1 != nullptr) {
            if (!(temp1->data >= temp2->data))
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    return false;
}

template <typename type>
linkedList<type> linkedList<type>::operator+(linkedList& list) {
    linkedList<type> list1;
    Node<type>* temp = start;
    while (temp != nullptr) {
        list1.push_back(temp->data);
        temp = temp->next;
    }
    temp = list1.start;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = list.start;
    return list1;
}

template <typename type>
linkedList<type> linkedList<type>::operator+(const type& value) {
    linkedList<type> list;
    Node<type>* temp = start;
    while (temp != nullptr) {
        list.push_back(temp->data);
        temp = temp->next;
    }
    list.push_back(value);
    return list;
}

template <typename type>
void linkedList<type>::operator+=(const linkedList& list) {
    addAll(list);
}

template <typename type>
void linkedList<type>::operator+=(const type& value) {
    push_back(value);
}

template <typename type>
linkedList<type> linkedList<type>::operator-(const type& value) {
    linkedList<type> list;
    Node<type>* temp = start;
    Node<type>* trash;
    while (temp != nullptr) {
        list.push_back(temp->data);
        temp = temp->next;
    }
    temp = list.start;
    while (temp->next != nullptr) {
        if (temp->next->data == value) {
            trash = temp->next;
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    delete trash;
    return list;
}

template <typename type>
void linkedList<type>::operator-=(const type& value) {
    int val = contain(value);
    if (val != -1)
        remove(val);
}

template <typename type>
linkedList<type> linkedList<type>::operator-() {
    linkedList<type> list;
    Node<type>* temp = start;
    while (temp != nullptr) {
        list.push_back(-temp->data);
        temp = temp->next;
    }
    return list;
}



template <typename type>
ostream& operator<<(ostream& out, linkedList<type>& list) {
    Node<type>* temp = list.start;
    out << "{ ";
    while (temp != nullptr) {
        out << temp->data << " ";
        temp = temp->next;
    }
    out << "}";
    return out;
}


#endif /// _linkedlist_h
