//
// Created by albert on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <vector>

using ::std::string;
using ::std::vector;
using ::std::complex;
using ::std::pair;
using ::std::initializer_list;

namespace algebra{
    // '{' && '('
    // rule of five default;
    // vector<>();
    class Matrix{
    private:
        vector<vector<complex<double>>> matrix;
        int columns_num;
        int rows_num;
    public:
        Matrix();
        Matrix(int, int);
        Matrix(initializer_list<vector<complex<double>>>);
        Matrix(string);
//        Rule of Zero
        ~Matrix() = default;

        Matrix Add(const Matrix) const;
        Matrix Sub(const Matrix) const;
        Matrix Mul(const Matrix) const;
        Matrix Mul(const complex<double>) const;
        Matrix Pow(int) const;
        string Print() const;
        pair<size_t, size_t> Size() const;
        bool setElement(int, int, complex<double>);
        complex<double> getElement(int, int) const;
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
