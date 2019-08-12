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
class LinkedList {
public:
    ///  constructors and destructor

    /**
    *  Initialization of new empty LinkedList
    */
    LinkedList();

    /**
    *  Copy Constructor - use the passed LinkedList to initialization itself (deep copy)
    */
    LinkedList(const LinkedList& list); ///Copy Constructor
    LinkedList(LinkedList&& list);      ///Take Constructor

    /**
    *  Use a initializer list to set up linked list
    */
    LinkedList(initializer_list<type> list);

    /**
    *  Clean up all the memory which are allocated by LinkedList object
    */
    ~LinkedList();

    ///  member function (methods)

    /**
    *  Add element at the start of LinkedList
    */
    void push_front(const type& value);

    /**
    *  Add element at the end of LinkedList
    */
    void push_back(const type& value);

    /**
    *  Remove element from the start of LinkedList
    *  @throw "Exception" if LinkedList is empty
    */
    void pop_back();

    /**
    *  Remove element from the start of LinkedList
    *  @throw "Exception" if LinkedList is empty
    */
    void pop_front();

    /**
    *  Clear whole LinkedList
    */
    void clear();

    /**
    *  return the element at given index <code>index</code>
    *  @throw Exception if the index is not in range of LinkedList
    */
    type at(int index) const;

    /**
    *  Return index of <code>value</code> if not there there then it return -1
    */
    int contain(const type& value) const;

    /**
    *  Insert a <code>value</code> at given index <code>index</code>
    *  @throw Exception if the index is not in range of LinkedList
    */
    void insert(int index, const type& value);

    /**
    *  Return true if the LinkedList is empty or else return false
    */
    bool empty() const;

    /**
     * Returns <code>true</code> if this stack contains exactly the same values
     * as the given other stack.
     * Identical in behavior to the == operator.
     */
    bool equals(const LinkedList& list) const;

    /**
    *  remove the element at the given index <code>index</code>
    *  @throw Exception if index is not in range of LinkedList
    */
    void remove(int index);

    /**
    *  Set the <code>value</code> of the given index <code>index</code>
    *  @throw Exception if index is not in range of LinkedList
    */
    void set(int index, const type& value);

    /**
    *  return the size of LinkedList
    */
    int size() const;

    /**
    *  return the first element of LinkedList
    *  @throw "Exception" if LinkedList is empty
    */
    type& front();
    const type& front() const;

    /**
    *  return the last element of LinkedList
    *  @throw "Exception" if LinkedList is empty
    */
    type& back();
    const type& back() const;

    /**
    *  swap the LinkedList with given LinkedList
    */
    void swap(LinkedList& list);

    /**
    *  return the LinkedList from index <code>start</code>
    *  to <code>start + length</code>
    *  @throw Exception if start is is not in range of LinkedList or
    *         start + length is not range of LinkedList
    */
    LinkedList subList(int start, int length);
    LinkedList subList(int start);

    /**
    *  implement the given function to whole LinkedList
    */
    void map(int (*fn)(type));
    void map(int (*fn)(type&));
    void map(int (*fn)(const type&));

    /**
    *  add all the element to the end or at the given index of the list
    *  @throw Exception if index is is not in range of LinkedList
    */
    void addAll(const LinkedList& list);
    void addAll(int index, const LinkedList& list);

    /**
    *  remove the elements
    *  @throw Exception if index is is not in range of LinkedList or
    *         index + length is not range of LinkedList
    */
    void removeAll(int index, int length);
    void removeAll(int index);

    /**
    *  sort the LinkedList
    */
    void sort();

    /// Operator overloading

    /**
    *  Overloads <code>[]</code> to select elements from this LinkedList.
    *  This extension enables the use of traditional array notation to
    *  get or set individual elements.
    *  @throw Exception if the index is not in the array range
    */
    type& operator[](int index);
    const type& operator[](int index) const;

    /**
     * Overloads = to assign new LinkedList to left LinkedList
     */
    LinkedList& operator=(const LinkedList& list);
    LinkedList& operator=(LinkedList&& list);

    /**
     * Relational operators to compare two LinkedList.
     * Each element is compared pairwise to the corresponding element at the
     * same index in the other LinkedList; for example, we first check the values
     * at index 0, then 1, and so on.
     * The ==, !=, <, >, <=, >= operators require that the <code>type</code>
     * has a ==, < and > operator so that the elements can be compared pairwise.
     */
    bool operator==(const LinkedList& list) const;
    bool operator!=(const LinkedList& list) const;
    bool operator<(const LinkedList& list) const;
    bool operator<=(const LinkedList& list) const;
    bool operator>(const LinkedList& list) const;
    bool operator>=(const LinkedList& list) const;

    /// Arithmetic Operator
    /**
     * Concatenates two LinkedList and returns the new LinkedList.
     */
    LinkedList operator+(LinkedList& list);

    /**
     * Produces a LinkedList formed by appending the given value to this LinkedList.
     */
    LinkedList operator+(const type& value) ;
    /**
     * Adds all of the elements from <code>list</code> to the end of this LinkedList.
     */
    void operator+=(const LinkedList& list);

    /**
     * Adds the single specified value to the end of the LinkedList.
     */
    void operator+=(const type& value);

    /**
     * Produces a LinkedList formed by removing the given value to this LinkedList.
     */
    LinkedList operator-(const type& value) ;

    /**
     * Remove the single specified value to the end of the LinkedList.
     */
    void operator-=(const type& value);

    /**
    *  Change sign of all the values of the given LinkedList and return new LinkedList
    */
    LinkedList operator-();

    /**
    *  Use to print the LinkedList using << operator
    */
    template <typename T>
    friend ostream& operator<<(ostream& out, LinkedList<T>& list);

    template <typename T>
    friend ostream& operator<<(ostream& out, const LinkedList<T>& list);

private:
    // member variable (fields)
    Node<type>* start;
    int _size;
};

template <typename type>
LinkedList<type>::LinkedList() {
    start = nullptr;
    _size = 0;
}

template <typename type>
LinkedList<type>::LinkedList(const LinkedList& list) {
    _size = 0;
    start = nullptr;
    Node<type>* temp = list.start;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}

template <typename type>
LinkedList<type>::LinkedList(LinkedList&& list) {
    _size = 0;
    start = list.start;
    list.start = nullptr;
}

template <typename type>
LinkedList<type>::LinkedList(initializer_list<type> list) {
    start = nullptr;
    _size = 0;
    for (type i : list)
        push_back(i);
}

template <typename type>
LinkedList<type>::~LinkedList() {
    clear();
}

template <typename type>
void LinkedList<type>::push_front(const type& value) {
    insert(0, value);
}

template <typename type>
void LinkedList<type>::push_back(const type& value) {
    insert(_size, value);
}

template <typename type>
void LinkedList<type>::pop_front() {
    if (start == nullptr)
        throw "Exception :-(";
    remove(0);
}

template <typename type>
void LinkedList<type>::pop_back() {
    if (start == nullptr)
        throw "Exception :-(";
    remove(_size - 1);
}

template <typename type>
void LinkedList<type>::clear() {
    Node<type>* trash;
    while (start != nullptr) {
        trash = start;
        start = start->next;
        delete trash;
    }
    _size = 0;
}

template <typename type>
bool LinkedList<type>::equals(const LinkedList<type>& list) const {
    return operator==(list);
}

template <typename type>
type LinkedList<type>::at(int index) const {
    return operator[](index);
}

template <typename type>
int LinkedList<type>::contain(const type& value) const {
    Node<type>* temp = start;
    for (int i = 0; i < _size; i++) {
        if (temp->data == value)
            return i;
        temp = temp->next;
    }
    return -1;
}

template <typename type>
void LinkedList<type>::insert(int index, const type& value) {
    if (index > _size || index < 0)
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
bool LinkedList<type>::empty() const {
    return !_size;
}

template <typename type>
void LinkedList<type>::remove(int index) {
    if (index >= _size || index < 0)
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
void LinkedList<type>::set(int index, const type& value) {
    if(index < 0 || index + 1 > _size)
        throw "Exception :-(";
    Node<type>* temp = start;
    for (int i = 0; i < index; i++)
        temp = temp->next;
    temp->data = value;
}

template <typename type>
int LinkedList<type>::size() const {
    return _size;
}

template <typename type>
type& LinkedList<type>::front() {
    if (start == nullptr)
        throw "Exception :-(";
    return start->data;
}

template <typename type>
const type& LinkedList<type>::front() const {
    if (start == nullptr)
        throw "Exception :-(";
    return start->data;
}

template <typename type>
type& LinkedList<type>::back() {
    if (start == nullptr)
        throw "Exception :-(";
    Node<type>* temp = start;
    while(temp->next != nullptr)
        temp = temp->next;

    return temp->data;
}

template <typename type>
const type& LinkedList<type>::back() const {
    if (start == nullptr)
        throw "Exception :-(";
    Node<type>* temp = start;
    while(temp->next != nullptr)
        temp = temp->next;

    return temp->data;
}

template <typename type>
void LinkedList<type>::swap(LinkedList& list) {
    Node<type>* temp_start= start;
    int temp_size = _size;

    start = list.start;
    _size = list._size;

    list.start = temp_start;
    list._size = temp_size;
}

template <typename type>
LinkedList<type> LinkedList<type>::subList(int start, int length) {
    LinkedList<type> list;
    if (start > _size || start + length > _size || start < 0 || length < 0)
        throw "Exception :-(";
    else {
        for (int i = start; i < start + length; i++)
            list.push_back(at(i));
    }
    return list;
}

template <typename type>
LinkedList<type> LinkedList<type>::subList(int start) {
    return subList(start, _size - start);
}

template <typename type>
void LinkedList<type>::map(int (*fn)(type)) {
    Node<type>* temp = start;
    while (temp != nullptr) {
        temp->data = fn(temp->data);
        temp = temp->next;
    }
}

template <typename type>
void LinkedList<type>::map(int (*fn)(type&)) {
    Node<type>* temp = start;
    for (int i = 0; i < _size; i++) {
        temp->data = fn(temp->data);
        temp = temp->next;
    }
}

template <typename type>
void LinkedList<type>::map(int (*fn)(const type&)) {
    Node<type>* temp = start;
    for (int i = 0; i < _size; i++) {
        temp->data = fn(temp->data);
        temp = temp->next;
    }
}

template <typename type>
void LinkedList<type>::addAll(const LinkedList& list) {
    Node<type>* temp = start;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = list.start;
    _size += list._size;
}

template <typename type>
void LinkedList<type>::addAll(int index, const LinkedList& list) {
    if (index > _size || index < 0)
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
void LinkedList<type>::removeAll(int index, int length) {
    vector<Node<type>*> tresh;
    Node<type>* first;
    Node<type>* temp = start;
    if (index > _size || index + length > _size || index < 0 || length < 0)
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
void LinkedList<type>::removeAll(int index) {
    removeAll(index, _size - index);
}

template <typename type>
void LinkedList<type>::sort() {
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
type& LinkedList<type>::operator[](int index) {
    if (index >= _size || index < 0)
        throw "Exception :-(";
    else {
        Node<type>* temp = start;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        return temp->data;
    }
}

template <typename type>
const type& LinkedList<type>::operator[](int index) const {
    if (index >= _size || index < 0)
        throw "Exception :-(";
    else {
        Node<type>* temp = start;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        return temp->data;
    }
}

template <typename type>
LinkedList<type>& LinkedList<type>::operator=(const LinkedList& list) {
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
LinkedList<type>& LinkedList<type>::operator=(LinkedList&& list) {
    start = list.start;
    list.start = nullptr;
    return *this;
}

template <typename type>
bool LinkedList<type>::operator==(const LinkedList& list) const {
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
bool LinkedList<type>::operator!=(const LinkedList& list) const {
    return !(operator==(list));
}

template <typename type>
bool LinkedList<type>::operator<(const LinkedList& list) const {
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
bool LinkedList<type>::operator<=(const LinkedList& list) const {
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
bool LinkedList<type>::operator>(const LinkedList& list) const {
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
bool LinkedList<type>::operator>=(const LinkedList& list) const {
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
LinkedList<type> LinkedList<type>::operator+(LinkedList& list) {
    LinkedList<type> list1;
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
LinkedList<type> LinkedList<type>::operator+(const type& value) {
    LinkedList<type> list;
    Node<type>* temp = start;
    while (temp != nullptr) {
        list.push_back(temp->data);
        temp = temp->next;
    }
    list.push_back(value);
    return list;
}

template <typename type>
void LinkedList<type>::operator+=(const LinkedList& list) {
    addAll(list);
}

template <typename type>
void LinkedList<type>::operator+=(const type& value) {
    push_back(value);
}

template <typename type>
LinkedList<type> LinkedList<type>::operator-(const type& value) {
    LinkedList<type> list;
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
void LinkedList<type>::operator-=(const type& value) {
    int val = contain(value);
    if (val != -1)
        remove(val);
}

template <typename type>
LinkedList<type> LinkedList<type>::operator-() {
    LinkedList<type> list;
    Node<type>* temp = start;
    while (temp != nullptr) {
        list.push_back(-temp->data);
        temp = temp->next;
    }
    return list;
}

template <typename type>
ostream& operator<<(ostream& out, LinkedList<type>& list) {
    Node<type>* temp = list.start;
    out << "{ ";
    while (temp != nullptr) {
        if(temp->next == nullptr)
            out << temp->data;
        else
            out << temp->data << ", ";
        temp = temp->next;
    }
    out << " }";
    return out;
}

template <typename type>
ostream& operator<<(ostream& out, const LinkedList<type>& list) {
    Node<type>* temp = list.start;
    out << "{ ";
    while (temp != nullptr) {
        if(temp->next == nullptr)
            out << temp->data;
        else
            out << temp->data << ", ";
        temp = temp->next;
    }
    out << " }";
    return out;
}


#endif /// _linkedlist_h
