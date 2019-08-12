#ifndef _grid_h
#define _grid_h

#include <iostream>

using namespace std;

/**
*  It is 2D array with some more functionality
*/
template <typename type>
class Grid {
public:

    /**
    *  Initializes a new Grid.
    */
    Grid();

    /**
    *  Initializes a new Grid with given numbers row and column
    */
    Grid(int row, int column);

    /**
    *  Initializes a new Grid with given numbers row and column having value
    *  <code>value</code> in each elements.
    */
    Grid(int row, int column, const type& value);

    /**
    *  This constructor uses an initializer list to set up the Grid.
    */
    Grid(std::initializer_list<std::initializer_list<type> > list);

    /**
    *  Copy Constructor - Deep Copy
    *  Take Constructor - Sallow Copy
    */
    Grid(Grid& grid);       ///Copy Constructor
    Grid(Grid&& grid);      ///Take Constructor

    /**
    *  Frees any heap storage associated with this Grid.
    */
    virtual ~Grid();

    /**
    *  Returns the first element in the Grid.
    *  @throw "Exception" if the Grid is empty.
    */
    type& front();
    const type& front() const;

    /**
    *  Returns the last element in the Grid.
    *  @throw "Exception" if the Grid is empty.
    */
    type& back();
    const type& back() const;

    /**
    *  Sets every value in the Grid to its element type's default value.
    */
    void clear();

    /**
    *  Returns <code>true</code> if this Grid contains exactly the same
    *  values as the given other Grid.
    *  Identical in behavior to the == operator.
    */
    bool equals(const Grid<type>& Grid) const;

    /**
    *  Stores the given value in every cell of this Grid.
    */
    void fill(const type& value);

    /**
    *  Returns the element at the specified <code>row</code>/<code>col</code>
    *  position in this Grid.
    *  @throw "Exception" if the <code>row</code> and <code>col</code>
    *  arguments are outside the Grid boundaries.
    */
    type get(int row, int col) const ;

    /**
    *  Returns the Grid's height,i.e. the number of rows in the Grid.
    */
    int height() const;

    /**
    *  Returns the Grid's width,i.e. the number of columns in the Grid.
    */
    int width() const;

    /**
    *  Returns <code>true</code> if the specified row and column position
    *  is inside the bounds of the Grid.
    */
    bool inBounds(int row, int col) const;

    /**
    *  Returns <code>true</code> if the Grid has 0 rows and/or 0 columns.
    */
    bool empty() const;

    /**
    *  Calls the specified function on each element of the Grid.
    */
    void map(type (*fn)(type));
    void map(type (*fn)(type&));
    void map(type (*fn)(const type&));

    /**
    *  Returns the number of columns in the Grid.
    */
    int numCols() const;

    /**
    *  Returns the number of rows in the Grid.
    *  This is equal to the Grid's height.
    */
    int numRows() const;

    /**
    *  Reinitializes the Grid to have the specified number of rows
    *  and columns.  If the <code>retain</code> parameter is true,
    *  the previous Grid contents are retained as much as possible.
    *  If <code>retain</code> is not passed or is false, any previous Grid contents
    *  are discarded.
    */
    void resize(int row, int column, bool retain = false);

    /**
    *  Return the element at  <code>row</code>/<code>col</code>
    * Identical in behavior to the [][] operator the only difference is it return value nor pointer.
    */
    type at(int row, int col) const;

    /**
    *  Replaces the element at the specified <code>row</code>/<code>col</code>
    *  location in this Grid with a new value.
    *  @throw "Exception" if the <code>row</code> and <code>col</code>
    *  arguments are outside the Grid boundaries.
    */
    void set(int row, int col, const type& value);

    /**
    *  Returns the total number of elements in the Grid (row * col)
    */
    int size() const;

    /// Operator Overloading

    /**
    *  Copy Assignment Operator - Deep Copy
    *  Take Assignment Operator - Sallow Copy
    */
    type& operator=(Grid& grid);       ///Copy Assignment
    type& operator=(Grid&& grid);      ///Take Assignment

    /**
    *  Overloads <code>[]</code> to select elements from this Grid.
    *  This extension enables the use of traditional array notation to
    *  get or set individual elements.  This method signals an error if
    *  the <code>row</code> and <code>col</code> arguments are outside
    *  the Grid boundaries.
    */
    type* operator[](int row);
    const type* operator[](int row) const;

    /**
    *  Compares two Grids for equality.
    */
    bool operator==(const Grid& grid) const;

    /**
    *  Compares two Grids for inequality.
    */
    bool operator!=(const Grid& grid) const;

    /**
    *  Relational operators to compare two Grids.
    *  The <, >, <=, >= operators require that the type has a < and > operator
    *  so that the elements can be compared pairwise.
    */
    bool operator<(const Grid& grid) const;
    bool operator<=(const Grid& grid) const;
    bool operator>(const Grid& grid) const;
    bool operator>=(const Grid& grid) const;

    template <typename T>
    friend ostream& operator<<(ostream& out, Grid<T>& grid);

    template <typename T>
    friend ostream& operator<<(ostream& out, const Grid<T>& grid);

private:
    // member variable (fields)
    type** _elements;
    int _row;             // The number of rows in the Grid
    int _column;          // The number of columns in the Grid
};

template <typename type>
Grid<type>::Grid() {
    _row = 0;
    _column = 0;
    _elements = nullptr;
}

template <typename type>
Grid<type>::Grid(int row, int column) {
    _row = row;
    _column = column;
    _elements = new type*[row];
    for (int i = 0; i < row; i++)
        _elements[i] = new type[column]();
}

template <typename type>
Grid<type>::Grid(int row, int column, const type& value) {
    _row = row;
    _column = column;
    _elements = new type*[row];
    for (int i = 0; i < row; i++)
        _elements[i] = new type[column];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            _elements[i][j] = value;
}

template <typename type>
Grid<type>::Grid(initializer_list<initializer_list<type> > list) {
    _row = list.size();
    if (list.begin() != list.end()) {
        _column = list.begin()->size();
    }
    _elements = new type*[_row];
    for (int i = 0; i < _row; i++)
        _elements[i] = new type[_column];

    auto rowItr = list.begin();
    for (int row = 0; row < _row; row++) {
        auto colItr = rowItr->begin();
        for (int col = 0; col < _column; col++) {
            _elements[row][col] = *colItr;
            colItr++;
        }
        rowItr++;
    }
}

template <typename type>
Grid<type>::Grid(Grid& grid) {
    _row = grid._row;
    _column = grid._column;
    _elements = new type*[_row];
    for (int i = 0; i < _row; i++)
        _elements[i] = new type[_column];

    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            _elements[i][j] = grid._elements[i][j];
}

template <typename type>
Grid<type>::Grid(Grid&& grid) {
    _row = grid._row;
    _column = grid._column;
    _elements = grid._elements;
    grid._elements = nullptr;
}

template <typename type>
Grid<type>::~Grid() {
    _row = 0;
    _column = 0;
    for(int i = 0; i < _row; i++)
        delete[] _elements[i];
    delete[] _elements;
}

template <typename type>
type& Grid<type>::front() {
    if(empty())
        throw "Exception :-(";
    return _elements[0][0];
}

template <typename type>
const type& Grid<type>::front() const {
    if(empty())
        throw "Exception :-(";
    return _elements[0][0];
}

template <typename type>
type& Grid<type>::back() {
    if(empty())
        throw "Exception :-(";
    return _elements[_row - 1][_column - 1];
}

template <typename type>
const type& Grid<type>::back() const {
    if(empty())
        throw "Exception :-(";
    return _elements[_row - 1][_column - 1];
}

template <typename type>
void Grid<type>::clear() {
    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            _elements[i][j] = type();
}

template <typename type>
bool Grid<type>::equals(const Grid<type>& Grid) const {
    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            if (_elements[i][j] != Grid._elements[i][j])
                return false;
    return true;
}

template <typename type>
void Grid<type>::fill(const type& value) {
    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            _elements[i][j] = value;
}

template <typename type>
type Grid<type>::get(int row, int col) const {
    if (!inBounds(row, col))
        throw "Exception :-(";
    return _elements[row][col];
}

template <typename type>
int Grid<type>::height() const {
    return _row;
}

template <typename type>
int Grid<type>::width() const {
    return _column;
}

template <typename type>
bool Grid<type>::inBounds(int row, int col) const {
    return row >= 0 && col >= 0 && row < _row && col < _column;
}

template <typename type>
bool Grid<type>::empty() const {
    return _row == 0 && _column == 0;
}

template <typename type>
void Grid<type>::map(type (*fn)(type)) {
    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            _elements[i][j] = fn(_elements[i][j]);
}

template <typename type>
void Grid<type>::map(type (*fn)(type&)) {
    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            _elements[i][j] = fn(_elements[i][j]);
}

template <typename type>
void Grid<type>::map(type (*fn)(const type&)) {
    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            _elements[i][j] = fn(_elements[i][j]);
}

template <typename type>
int Grid<type>::numCols() const {
    return _column;
}

template <typename type>
int Grid<type>::numRows() const {
    return _row;
}

template <typename type>
void Grid<type>::resize(int row, int column, bool retain) {
    type** temp = _elements;
    int tempr = _row;
    int tempc = _column;

    _row = row;
    _column = column;
    _elements = new type*[row];
    for (int i = 0; i < row; i++)
        _elements[i] = new type[column]();

    if(retain) {
        int minCol = tempc > row ? row : tempc;
        int minRow = tempr > column ? column : tempr;
        for(int i = 0; i < minRow; i++)
            for(int j = 0; j < minCol; j++)
                _elements[i][j] = temp[i][j];
    }

    for(int i = 0; i < tempr; i++)
        delete[] temp[i];
    delete[] temp;
}

template <typename type>
type Grid<type>::at(int row, int col) const {
    if(!inBounds(row, col))
        throw "Exception :-(";
    return _elements[row][col];
}

template <typename type>
void Grid<type>::set(int row, int col, const type& value) {
    if(!inBounds(row, col))
        throw "Exception :-(";
    _elements[row][col] = value;
}

template <typename type>
int Grid<type>::size() const {
    return _row * _column;
}

template <typename type>
type& Grid<type>::operator=(Grid& grid) {
    _row = grid._row;
    _column = grid._column;
    _elements = new type*[_row];
    for (int i = 0; i < _row; i++)
        _elements[i] = new type[_column];

    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _column; j++)
            _elements[i][j] = grid._elements[i][j];
}

template <typename type>
type& Grid<type>::operator=(Grid&& grid) {
    _row = grid._row;
    _column = grid._column;
    _elements = grid._elements;
    grid._elements = nullptr;
}

template <typename type>
type* Grid<type>::operator[](int row) {
    if(!(row < _row))
        throw "Exception :-(";
    return _elements[row];
}

template <typename type>
const type* Grid<type>::operator[](int row) const {
    if(!(row < _row))
        throw "Exception :-(";
    return _elements[row];
}

template <typename type>
bool Grid<type>::operator==(const Grid& grid) const {
    return equals(grid);
}

template <typename type>
bool Grid<type>::operator!=(const Grid& grid) const {
    return !equals(grid);
}


template <typename type>
bool Grid<type>::operator<(const Grid& grid) const {
    if (size() == grid.size()) {
        for (int i = 0; i < _row; i++) {
            for (int j = 0; j < _column; j++)
                if (!(_elements[i][j] < grid._elements[i][j]))
                    return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool Grid<type>::operator<=(const Grid& grid) const {
    if (size() == grid.size()) {
        for (int i = 0; i < _row; i++) {
            for (int j = 0; j < _column; j++)
                if (!(_elements[i][j] <= grid._elements[i][j]))
                    return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool Grid<type>::operator>(const Grid& grid) const {
    if (size() == grid.size()) {
        for (int i = 0; i < _row; i++) {
            for (int j = 0; j < _column; j++)
                if (!(_elements[i][j] > grid._elements[i][j]))
                    return false;
        }
        return true;
    }
    return false;
}

template <typename type>
bool Grid<type>::operator>=(const Grid& grid) const {
    if (size() == grid.size()) {
        for (int i = 0; i < _row; i++) {
            for (int j = 0; j < _column; j++)
                if (!(_elements[i][j] >= grid._elements[i][j]))
                    return false;
        }
        return true;
    }
    return false;
}

template <typename T>
ostream& operator<<(ostream& out, Grid<T>& grid) {
    out << "{ ";
    for (int i = 0; i < grid._row; i++) {
        out << "{ ";
        for(int j = 0; j < grid._column; j++)
            if (j == grid._column - 1)
                out << grid._elements[i][j];
            else
                out << grid._elements[i][j] << ",";
    out << " }";
    if (i != grid._row - 1)
        out << "," << endl << "  ";
    }
    out << " } ";
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, const Grid<T>& grid) {
    out << "{ ";
    for (int i = 0; i < grid._row; i++) {
        out << "{ ";
        for(int j = 0; j < grid._column; j++)
            if (j == grid._column - 1)
                out << grid._elements[i][j];
            else
                out << grid._elements[i][j] << ",";
    out << " }";
    if (i != grid._row - 1)
        out << "," << endl << "  ";
    }
    out << " } ";
    return out;
}


#endif // _grid_h
