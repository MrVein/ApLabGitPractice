//
// Created by shazi on 4/28/2021.
//

#ifndef TIREDHAPOOLI_MATRIX_H
#define TIREDHAPOOLI_MATRIX_H
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

template <typename T>
class matrix
{
    vector<vector<T>> mat;
    bool checkMatrix(vector<vector<T>> _mat);
    vector<T> rowToCols(vector<T> _row , vector<vector<T>> _mat);

    public:
    matrix();
    matrix(vector<vector<T>> _mat);
    ~matrix();

    //getter
    vector<T> getLine(int _row);
    vector<vector<T>> getMatrix();
    T getElement(int _row , int _col);

    //setter
    void setRow(int _line , vector<T> _matLine);
    void setCol(int _col , vector<T> _matCol);
    void changeTo(int _row , int _col , T _data);

    bool isEqual(matrix<T> _mat);
    bool isNotEqual(matrix<T> _mat);
    void matrix_cin(vector<vector<T>> _mat);
    void matrix_cout();
    matrix<T> multiplyByNum(int _num);
    matrix<T> divideByNum(int _num);

    matrix<T> sumWithMatrix(matrix<T> _mat);
    matrix<T> subtractWithMatrix(matrix<T> _mat);
    matrix<T> multipleWithMatrix(matrix<T> _mat);

    friend istream& operator>>(istream& in , matrix<T>& _mat);
    friend ostream& operator<<(ostream& out , const matrix<T>& _mat);
    friend matrix<T> operator+(const matrix<T>& _m1 , const matrix<T>& _m2 );
    friend matrix<T> operator-(const matrix<T>& _m1 , const matrix<T>& _m2 );
    friend matrix<T> operator*(const matrix<T>& _m1 , const matrix<T>& _m2 );
    friend bool operator==(const matrix<T>& _m1 , const matrix<T>& _m2);
    friend bool operator!=(const matrix<T>& _m1 , const matrix<T>& _m2);
    T operator()(int , int);

    friend matrix<T> operator*(const matrix<T>& _mat , const int& x);
    friend matrix<T> operator/(const matrix<T>& _mat , const int& x);
    matrix<T>& operator++();
    matrix<T>& operator--();
    matrix<T> operator++(int);
    matrix<T> operator--(int);
    matrix<T> operator-=(const matrix<T>&);
    matrix<T> operator*=(const matrix<T>&);
    matrix<T> operator+=(const matrix<T>&);



};


template<typename T>
T matrix<T>::operator()(int i , int j)
{
    return mat[i][j];
}

template<typename T>
matrix<T> matrix<T>::operator*=(const matrix<T>& _m2)
{
    vector<vector<T>> res;
    for(auto i = 0 ; i < this->mat.size() ; ++i)
        res.emplace_back(rowToCols(this->mat[i], _m2));

    this->mat = res;
    return *this;
}


template<typename T>
matrix<T> matrix<T>::operator-=(const matrix<T>& obj)
{
    for(int i = 0 ; i < this->mat.size() ; i++)
        for(int j = 0 ; j < this->mat[0].size() ; j++)
            this->mat[i][j]+=obj.mat[i][j];
    return *this;
}

template<typename T>
matrix<T> matrix<T>::operator+=(const matrix<T>& obj)
{
    for(int i = 0 ; i < this->mat.size() ; i++)
        for(int j = 0 ; j < this->mat[0].size() ; j++)
            this->mat[i][j]-=obj.mat[i][j];
    return *this;
}

template<typename T>
matrix<T> matrix<T>::operator++(int)
{
    matrix<T> temp = *this;
    for(auto x : this->mat)
        for(auto y : x)
            ++y;
    return temp;
}

template<typename T>
matrix<T> matrix<T>::operator--(int)
{
    matrix<T> temp = *this;
    for(auto x : this->mat)
        for(auto y : x)
            --y;
    return temp;

}
template<typename T>
matrix<T>& matrix<T>::operator++()
{

    for(auto x : this->mat)
        for(auto y : x)
            ++y;
}

template<typename T>
matrix<T>& matrix<T>::operator--()
{
    for(auto x : this->mat)
        for(auto y : x)
            --y;
}

template<typename T>
matrix<T> operator*(const matrix<T>& _m1 , const matrix<T>& _m2 )
{
    assert(_m1.mat[0].size() == _m2.mat.size() && checkMatrix(_m2) &&checkMatrix(_m1));
    vector<vector<T>> res;
    matrix<T> temp;
    for(auto i = 0 ; i < _m1.mat.size() ; ++i)
        res.emplace_back(rowToCols(_m1.mat[i], _m2));

    temp.mat = res;
    return temp;
}

template<typename T>
matrix<T> operator*(const matrix<T>& _mat , const int& x)
{
    matrix<T> temp;
    temp.mat = _mat.mat;
    for(auto x : temp.mat)
        for(auto y: x)
            y *= x;

    return temp;
}

template<typename T>
matrix<T> operator/(const matrix<T>& _mat , const int& x)
{
    assert(x!=0);
    matrix<T> temp;
    temp.mat = _mat.mat;
    for(auto x : temp.mat)
        for(auto y: x)
            y /= x;

    return temp;
}

template<typename T>
bool operator==(const matrix<T>& _m1 , const matrix<T>& _m2)
{
    if(_m1.mat == _m2.mat)
        return true;
    else
        return false;
}

template<typename T>
bool operator!=(const matrix<T>& _m1 , const matrix<T>& _m2)
{
    if(_m1.mat != _m2.mat)
        return true;
    else
        return false;
}

template<typename T>
matrix<T> operator+(const matrix<T>& _m1 , const matrix<T>& _m2 )
{
    assert(_m1.mat.size() == _m2.mat.size() && checkMatrix(_m1.mat) && _m1.mat[0].size() == _m2.mat[0].size());
    vector<vector<T>> temp = _m1.mat;
    matrix<T> res;
    for(int i = 0 ; i < _m1.mat.size() ; ++i)
        for(int j = 0 ; j < _m1.mat[i].size() ; ++j)
            temp += _m2.mat[i][j];
    res.mat = temp;
    return res;
}

template<typename T>
matrix<T> operator-(const matrix<T>& _m1 , const matrix<T>& _m2 )
{
    assert(_m1.mat.size() == _m2.mat.size() && checkMatrix(_m1.mat) && _m1.mat[0].size() == _m2.mat[0].size());
    vector<vector<T>> temp = _m1.mat;
    matrix<T> res;
    for(int i = 0 ; i < _m1.mat.size() ; ++i)
        for(int j = 0 ; j < _m1.mat[i].size() ; ++j)
            temp -= _m2.mat[i][j];

    res.mat = temp;
    return res;
}

template<typename T>
ostream& operator<<(ostream& out , const matrix<T>& _mat)
{
    for(auto x : _mat.mat)
        for(auto y : x)
            out << y;

    return out;
}

template<typename T>
vector<T> matrix<T>::rowToCols(vector<T> _row , vector<vector<T>> _mat)
{
    vector<T> temp;
    for(auto i = 0 ; i < _mat.size() ; ++i)
    {
        T mul = 0 ;
        for(auto y = 0 ; y < _row.size() ; ++ y)
            mul += _row[y]*_mat[i][y];
        temp.template emplace_back(mul);
    }
    return temp;
}

template<typename T>
bool matrix<T>::checkMatrix(vector<vector<T>> _mat)
{
    if(_mat.empty())
        return false;
    int size = _mat[0].size();
    for(auto i = 0 ; i < _mat.size() ; ++i)
        if(_mat[i].size() != size)
            return false;
    return true;
}


template<typename T>
matrix<T>::matrix()
{}

template<typename T>
matrix<T>::matrix(vector<vector<T>> _mat)
{
    assert(checkMatrix(_mat));
    mat = _mat;
}

template<typename T>
matrix<T>::~matrix<T>()
{}

template<typename T>
vector<T> matrix<T>::getLine(int _row)
{
    assert(_row < mat.size() && _row > -1);
    return mat[_row];
}

template<typename T>
vector<vector<T>> matrix<T>::getMatrix()
{
    return mat;
}

template<typename T>
T matrix<T>::getElement(int _row , int _col)
{
    assert(_row < mat.size() && _row > -1 && _col < mat[0].size() && _col > -1);
    return mat[_row][_col];
}

template<typename T>
bool matrix<T>::isEqual(matrix<T> _mat)
{
    assert(_mat.mat.size() == mat.size() && checkMatrix(_mat.mat) && mat[0].size() == _mat.mat[0].size());
    if(mat == _mat.mat)
        return true;
    return false;
}

template<typename T>
bool matrix<T>::isNotEqual(matrix<T> _mat)
{
    assert(_mat.mat.size() == mat.size() && checkMatrix(_mat.mat) &&mat[0].size() == _mat.mat[0].size());
    if(mat != _mat.mat)
        return true;
    return false;
}


template<typename T>
void matrix<T>::matrix_cin(vector<vector<T>> _mat)
{
    mat = _mat;
}
template<typename T>

istream &operator>>(istream &in, matrix<T> &_mat)
{
    int rows, cols;
    T temp;
    cout << "Enter Matrix Dimensions (Rows and Cols respectively. like \"3 4\")" << endl;
    in >> rows >> cols;
    cout << "Enter Matrix elements" << endl;

    for (auto i = 0; i < rows; ++i)
    {
        _mat.mat.push_back({});

        for (auto j = 0; j < cols; ++j)
        {
            in >> temp;
            _mat.mat[i].push_back(temp);

        }
    }
    return in;
}


template<typename T>
void matrix<T>::matrix_cout()
{
    for(auto i = 0 ; i < mat.size() ; ++i)
    {
        for (auto j = 0; j < mat[i].size(); ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

template<typename T>
matrix<T> matrix<T>::multiplyByNum(int _num)
{
    matrix<T> temp(mat);
    for(auto i = 0 ; i < temp.mat.size() ; ++i)
        for (auto j = 0; j < temp.mat[i].size(); ++j)
            temp.mat[i][j] *= _num;

    return temp;
}

template<typename T>
matrix<T> matrix<T>::divideByNum(int _num)
{
    assert(!_num);
    matrix<T> temp(mat);
    for(auto i = 0 ; i < temp.mat.size() ; ++i)
        for (auto j = 0; j < temp.mat[i].size(); ++j)
            temp.mat[i][j] /= _num;
    return temp;
}

template<typename T>
void matrix<T>::setRow(int _line , vector<T> _matLine)
{
    assert(_line > -1 && _line < mat.size());
    assert(_matLine.size() == mat[0].size());

    mat[_line] = _matLine;
}

template<typename T>
void matrix<T>::setCol(int _col , vector<T> _matCol)
{
    assert(_col > -1 && _col < mat[0].size());
    assert(_matCol.size() == mat.size());

    for(auto i = 0 ; i < mat.size() ; ++i)
        mat[i][_col] = _matCol[i];
}

template<typename T>
void matrix<T>::changeTo(int _row , int _col , T _data)
{
    assert(_row < mat.size() && _row > -1 && _col < mat[0].size() && _col > -1);
    mat[_row][_col] = _data;
}

template<typename T>
matrix<T> matrix<T>::sumWithMatrix(matrix<T> _mat)
{
    assert(_mat.mat.size() == mat.size() && checkMatrix(_mat.mat) && mat[0].size() == _mat[0].size());
    matrix<T> temp(mat);
    for(auto i = 0 ; i < mat.size() ; ++i)
        for (auto j = 0; j < mat[i].size(); ++j)
            _mat.mat[i][j] += _mat[i][j];
    return temp;
}

template<typename T>
matrix<T> matrix<T>::subtractWithMatrix(matrix<T> _mat)
{
    assert(_mat.size() == mat.size() && checkMatrix(_mat) && mat[0].size() == _mat[0].size());
    for(auto i = 0 ; i < mat.size() ; ++i)
        for (auto j = 0; j < mat[i].size(); ++j)
            mat[i][j] -= _mat[i][j];
}

template<typename T>
matrix<T> matrix<T>::multipleWithMatrix(matrix<T> _mat)
{
    assert(mat[0].size() == _mat.size() && checkMatrix(_mat));
    vector<vector<T>> res;
    for(auto i = 0 ; i < mat.size() ; ++i)
        res.emplace_back(rowToCols(mat[i], _mat));

    return res;
}

//class template specialization
template <>
class matrix<char*>
{
    vector<vector<char*>> mat;
    bool checkMatrix(vector<vector<char*>> _mat);

public:
    matrix();
    matrix(vector<vector<char*>> _mat);
    ~matrix();

    //getter
    vector<char*> getLine(int _row);
    vector<vector<char*>> getMatrix();
    char* getElement(int _row , int _col);

    //setter
    void setRow(int _line , vector<char*> _matLine);
    void setCol(int _col , vector<char*> _matCol);
    void changeTo(int _row , int _col , char* _data);

    bool isEqual(matrix<char*> _mat);
    bool isNotEqual(matrix<char*> _mat);
    void matrix_cin(vector<vector<char*>> _mat);
    void matrix_cout();

    matrix<char *> concatenate(matrix<char *> _mat);

};

bool matrix<char*>::checkMatrix(vector<vector<char*>> _mat)
{
    if(_mat.empty())
        return false;
    int size = _mat[0].size();
    for(auto i = 0 ; i < _mat.size() ; ++i)
        if(_mat[i].size() != size)
            return false;
    return true;
}

matrix<char*>::matrix()
{}

matrix<char*>::matrix(vector<vector<char*>> _mat)
{
    assert(checkMatrix(_mat));
    mat = _mat;
    for(auto i = 0 ; i < mat.size() ; ++i)
    {
        for (auto j = 0; j < mat[i].size(); ++j)
        {
            mat[i][j] = new char[sizeof(_mat[i][j])];
            strcpy(mat[i][j] , _mat[i][j]);
        }

    }

}

matrix<char*>::~matrix<char*>()
{
    for(auto i = 0 ; i < mat.size() ; ++i)
    {
        for (auto j = 0; j < mat[i].size(); ++j)
            delete mat[i][j];

    }

}

vector<char*> matrix<char*>::getLine(int _row)
{
    assert(_row < mat.size() && _row > -1);
    return mat[_row];
}

vector<vector<char*>> matrix<char*>::getMatrix()
{
    return mat;
}

char* matrix<char*>::getElement(int _row , int _col)
{
    assert(!mat.empty());
    assert(_row < mat.size() && _row > -1 && _col < mat[0].size() && _col > -1);
    return mat[_row][_col];
}

bool matrix<char*>::isEqual(matrix<char*> _mat)
{
    assert(_mat.mat.size() == mat.size() && checkMatrix(_mat.mat) && mat[0].size() == _mat.mat[0].size());
    if(mat == _mat.mat)
        return true;
    return false;
}

bool matrix<char*>::isNotEqual(matrix<char*> _mat)
{
    assert(_mat.mat.size() == mat.size() && checkMatrix(_mat.mat) &&mat[0].size() == _mat.mat[0].size());
    if(mat != _mat.mat)
        return true;
    return false;
}

void matrix<char*>::matrix_cin(vector<vector<char*>> _mat)
{
    assert(checkMatrix(_mat));
    for(auto i = 0 ; i < mat.size() ; ++i)
        for (auto j = 0; j < mat[i].size(); ++j)
        {
            mat[i][j] = new char[sizeof(_mat[i][j])];
            strcat(mat[i][j] , _mat[i][j]);
        }

}

void matrix<char*>::matrix_cout()
{
    for(auto i = 0 ; i < mat.size() ; ++i)
    {
        for (auto j = 0; j < mat[i].size(); ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void matrix<char*>::setRow(int _line , vector<char*> _matLine)
{
    assert(!mat.empty());
    assert(_line > -1 && _line < mat.size());
    assert(_matLine.size() == mat[0].size());

    for(auto i = 0 ; i < mat[i].size() ; ++i)
    {
        mat[_line][i] = new char[sizeof(_matLine[i])];
        strcpy(mat[_line][i] , _matLine[i]);
    }
}

void matrix<char*>::setCol(int _col , vector<char*> _matCol)
{
    assert(!mat.empty());
    assert(_col > -1 && _col < mat[0].size());
    assert(_matCol.size() == mat.size());

    for(auto i = 0 ; i < mat.size() ; ++i)
    {
        mat[i][_col] = new char[sizeof(_matCol[i])];
        strcpy(mat[i][_col] , _matCol[i]);
    }
}

void matrix<char*>::changeTo(int _row , int _col , char* _data)
{
    assert(_row < mat.size() && _row > -1 && _col < mat[0].size() && _col > -1);
    mat[_row][_col] = new char[sizeof(_data)];
    strcpy(mat[_row][_col] , _data);
}

matrix<char *> matrix<char*>::concatenate(matrix<char*> _mat)
{
    assert(!mat.empty() && !_mat.mat.empty() &&_mat.mat.size() == mat.size() && checkMatrix(_mat.mat) && mat[0].size() == _mat.mat[0].size());
    matrix<char*> temp(mat);
    for(auto i = 0 ; i < mat.size() ; ++i)
    {
        for (auto j = 0; j < mat[i].size(); ++j)
        {
            temp.mat[i][j] = new char[sizeof(_mat.mat[i][j])+ sizeof(mat[i][j])];
            strcpy(temp.mat[i][j] , mat[i][j]);
            strcat(temp.mat[i][j], _mat.mat[i][j]);
        }
    }
    return temp;
}


#endif //TIREDHAPOOLI_MATRIX_H
