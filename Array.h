#ifndef _array_h
#define _array_h

template <typename type>
class Array {
public:
    /**
    *  Initializes a new Array.
    */
    Array() {
        _elements = nullptr;
        _maxsize = 0;
        _size = 0;
    }

    /**
    *  Initializes a new Array with given size.
    */
    Array(int size) {
        _elements = new type[size]();
        _maxsize = size;
        _size = 0;
    }

    /**
    *  Initializes a new Array with given numbers size having value
    *  <code>value</code> in each elements.
    */
    Array(int size, const type& value) {
       _elements = new type[size];
        _maxsize = size;
        _size = size;
        for(int i = 0; i < _maxsize; i++)
            _elements[i] = value;
    }

    /**
    *  This constructor uses an initializer list to set up the Array.
    */
    Array(std::initializer_list<type> list) {
        _elements = new type[list.size()];
        _size = 0;
        _maxsize = list.size();
        for (type i : list)
            push_back(i);
    }

    /**
    *  Copy Constructor - Deep Copy
    *  Take Constructor - Sallow Copy
    */
    Array(Array& array) {       ///Copy Constructor
        _elements = new type[array._maxsize];
        for (int i = 0; i < array._maxsize; i++)
            _elements[i] = array._elements[i];
        _size = array._size;
        _maxsize = array._maxsize;
    }

    Array(Array&& array) {     ///Take Constructor
        _size = array._size;
        _maxsize = array._maxsize;
        _elements = array._elements;
        array._elements = nullptr;
    }

    /**
    *  Frees any heap storage associated with this Array.
    */
    virtual ~Array() {
        delete[] _elements;
    }

    /**
    *  Returns the first element in the Array.
    *  @throw "Exception" if the Array is empty.
    */
    type& front() {
        if(empty())
            throw "Exception :-(";
        return _elements[0];
    }

    const type& front() const {
        if(empty())
            throw "Exception :-(";
        return _elements[0];
    }

    /**
    *  Returns the last element in the Array.
    *  @throw "Exception" if the Array is empty.
    */
    type& back() {
        if(empty())
            throw "Exception :-(";
        return _elements[_size - 1];
    }

    const type& back() const {
        if(empty())
            throw "Exception :-(";
        return _elements[_size - 1];
    }

    /**
    *  Insert the element at the end of Array.
    *  @throw "Exception" if the Array is empty.
    */
    void push_back(const type& value) {
        if(_maxsize == _size)
            throw "Exception :-(";
        _elements[_size++] = value;
    }

    /**
    *  Insert the element at the start of Array.
    *  @throw "Exception" if the Array is empty.

    */
    void push_front(const type& value) {
        if(_maxsize == _size)
            throw "Exception :-(";
        for (int i = _size; i > 0; i--)
            _elements[i] = _elements[i - 1];
        _elements[0] = value;
        _size++;
    }

    /**
    *  Remove the element from the start of Array.
    *  @throw "Exception" if the Array is empty.
    */
    void pop_front() {
        if(empty())
            throw "Exception :-(";
        for (int i = 0; i < _size - 1; i++)
            _elements[i] = _elements[i + 1];
        _elements[_size - 1] = 0;
        _size--;
    }

    /**
    *  Remove the element from the end of Array.
    *  @throw "Exception" if the Array is empty.
    */
    void pop_back() {
        if(empty())
            throw "Exception :-(";
        _elements[_size - 1] = 0;
        _size--;
    }

    /**
    *  Clear the Array.
    */
    void clear() {
        delete[] _elements;
        _size = 0;
    }

    /**
    *  Returns <code>true</code> if this Array contains exactly the same
    *  values as the given other Array.
    *  Identical in behavior to the == operator.
    */
    bool equals(const Array<type>& array) const {
        if (_maxsize == array._maxsize) {
            for (int i = 0; i < _maxsize; i++)
                if (!(_elements[i] == array._elements[i]))
                    return false;
            return true;
        }
        return false;
    }

    /**
    *  Stores the given value in every cell of this Array.
    */
    void fill(const type& value) {
        if(empty())
            throw "Exception :-(";
        for (int i = 0; i < _maxsize; i++)
            _elements[i] = value;
    }

    /**
    *  Swap the current Array with given Array
    */
    void swap(Array& array) {
        type* temp = array._elements;
        int temps = array._size;
        int tempm = array._maxsize;

        array._elements = _elements;
        array._size = _size;
        array._maxsize = _maxsize;

        _elements = temp;
        _size = temps;
        _maxsize = tempm;
    }

    /**
    *  Returns the Array's size.
    */
    int size() const {
        return _size;
    }

    /**
    *  Returns the Array's maximum size.
    */
    int maxSize() const {
        return _maxsize;
    }

    /**
    *  Returns <code>true</code> if the Array has 0 rows and/or 0 columns.
    */
    bool empty() const {
        return !_size;
    }

    /**
    *  Calls the specified function on each element of the Array.
    */
    void map(type (*fn)(type)) {
        for (int i = 0; i < _size; i++)
            _elements[i] = fn(_elements[i]);
    }

    void map(type (*fn)(type&)) {
        for (int i = 0; i < _size; i++)
            _elements[i] = fn(_elements[i]);
    }

    void map(type (*fn)(const type&)) {
        for (int i = 0; i < _size; i++)
            _elements[i] = fn(_elements[i]);
    }

    /**
    *  Reinitializes the Array to have the specified number of rows
    *  and columns.  If the <code>retain</code> parameter is true,
    *  the previous Array contents are retained as much as possible.
    *  If <code>retain</code> is not passed or is false, any previous Array contents
    *  are discarded.
    */
    void resize(int newSize, bool retain = false) {
        type* temp = _elements;
        int temps = _size;

        _elements = new type[newSize]();
        _maxsize = newSize;
        _size = 0;

        if(retain) {
            int Size = (temps > newSize ? newSize : temps);
            for(int i = 0; i < Size; i++)
                _elements[i] = temp[i];
            _size = Size;
        }
        delete[] temp;
    }

    /**
    *  Return the element at  <code>index</code>
    *  Identical in behavior to the [] operator.
    */
    type at(int index) const {;
        return operator[](index);
    }

    /**
    *  Replaces the element at the specified <code>row</code>/<code>col</code>
    *  location in this Array with a new value.
    *  @throw "Exception" if the <code>row</code> and <code>col</code>
    *  arguments are outside the Array boundaries.
    */
    void set(int index, const type& value) {
        if(index < 0 || index + 1 > _size)
            throw "Exception :-(";
            _elements[index] = value;
    }

    /**
    *  return new Array having element of for index
    *  <code>start</code> to start + length
    *  @throw Exception if the <code>length</length> is not in the array range or
    *         start is > _size
    */
    Array subList(int start, int length) {
        Array array(length);
        if (start > _size || start + length > _size || start < 0 || length < 0)
            throw "Exception :-(";
        else {
            for (int i = start; i < start + length; i++)
                array.push_back(_elements[i]);
        }
        return array;
    }

    /**
    *  return new Array having element of for index
    *  <code>start</code> to end
    *  @throw if start is > _size
    */
    Array subList(int start) {
        return subList(start, _size - start);
    }

    void sort() {
        int temp;
        bool flag = true;
        for (int round = 1; round < _size; round++) {
            flag = true;

            for(int i = 0; i < _size - round; i++) {
                if(_elements[i] > _elements[i+1]) {
                        flag = false;
                        temp = _elements[i];
                        _elements[i] = _elements[i + 1];
                        _elements[i + 1] = temp;
                   }
            }
            if (flag)
                return;
        }
    }

    /// Operator Overloading

    /**
    *  Copy Assignment Operator - Deep Copy
    *  Take Assignment Operator - Sallow Copy
    */
    Array<type>& operator=(Array& array) {       ///Copy Assignment
        resize(array._maxsize);
        if(this != &array) {
            for (int i = 0; i < array._maxsize; i++)
                _elements[i] = array._elements[i];
            _size = array._size;
            _maxsize = array._maxsize;
            }
        return *this;
    }

    Array<type>& operator=(Array&& array) {      ///Take Assignment
        resize(array._maxsize);
        _size = array._size;
        _maxsize = array._maxsize;
        _elements = array._elements;
        array._elements = nullptr;
        return *this;
    }

    /**
    *  Overloads <code>[]</code> to select elements from this Array.
    *  This extension enables the use of traditional array notation to
    *  get or set individual elements.  This method signals an error if
    *  the <code>index</code> arguments are outside
    *  the Array boundaries.
    */
    type& operator[](int index) {
        if (index < 0 || index + 1 > _size)
            throw "Exception :-(";
        return _elements[index];
    }

    const type& operator[](int index) const {
        if (index < 0 || index + 1 > _size)
            throw "Exception :-(";
        return _elements[index];
    }

    /**
    *  Compares two Arrays for equality.
    */
    bool operator==(const Array& array) const {
        return equals(array);
    }

    /**
    *  Compares two Arrays for inequality.
    */
    bool operator!=(const Array& array) const {
        return !equals(array);
    }

    /**
    *  Relational operators to compare two Arrays.
    *  The <, >, <=, >= operators require that the type has a < and > operator
    *  so that the elements can be compared pairwise.
    */
    bool operator<(const Array& array) const {
        if (_size == array._size) {
            for (int i = 0; i < _size; i++) {
                if (!(_elements[i] < array._elements[i]))
                    return false;
            }
            return true;
        }
        return false;
    }

    bool operator<=(const Array& array) const {
        if (_size == array._size) {
            for (int i = 0; i < _size; i++) {
                if (!(_elements[i] <= array._elements[i]))
                    return false;
            }
            return true;
        }
        return false;
    }

    bool operator>(const Array& array) const {
        if (_size == array._size) {
            for (int i = 0; i < _size; i++) {
                if (!(_elements[i] > array._elements[i]))
                    return false;
            }
            return true;
        }
        return false;
    }

    bool operator>=(const Array& array) const {
        if (_size == array._size) {
            for (int i = 0; i < _size; i++) {
                if (!(_elements[i] >= array._elements[i]))
                    return false;
            }
            return true;
        }
        return false;
    }

    /**
    *  Add elements at the end of newly created Array and return it.
    */
    Array operator+(const type& value) {
        Array array(_maxsize + 1);

        array = *this;
        array.push_back(value);

        return array;
    }

    /**
    *  Add at the end of Array list.
    */
    void operator+=(const type& value) {
        push_back(value);
    }

    /**
    *  remove value from the end of Array
    *  Identical to pop_back()
    */
    void operator--(int) {
        pop_back();
    }

    /**
    *  remove value from the front of Array
    *  Identical to pop_front()
    */
    void operator--() {
        pop_front();
    }

    /**
    */

    template <typename T>
    friend ostream& operator<<(ostream& out, Array<T>& Array);

    template <typename T>
    friend ostream& operator<<(ostream& out, const Array<T>& Array);

private:
    type* _elements;
    int _maxsize;
    int _size;

};


template <typename T>
ostream& operator<<(ostream& out, Array<T>& array) {
    out << "{ ";
    for (int i = 0; i < array._maxsize; i++) {
            if (i == array._maxsize - 1)
                out << array._elements[i];
            else
                out << array._elements[i] << ", ";
    }
    out << " }";
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, const Array<T>& array) {
   out << "{ ";
    for (int i = 0; i < array._maxsize; i++) {
            if (i == array._maxsize - 1)
                out << array._elements[i];
            else
                out << array._elements[i] << ", ";
    }
    out << " }";
    return out;
}

#endif // _array_h
