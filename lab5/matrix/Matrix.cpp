//
// Created by albert on 03.04.17.
//

#include "Matrix.h"
#include <iostream>

using std::cout;
using std::endl;

namespace algebra{
    Matrix::Matrix(){
        columns_num = rows_num = 0;
    }

    Matrix::Matrix(int r_num, int c_num){
        if(c_num <= 0 || r_num <= 0) {
            rows_num = columns_num = 0;
            return;
        }

        columns_num = c_num;
        rows_num = r_num;


        for(int i = 0; i < rows_num; i++){
            matrix.push_back(vector<complex<double>>());
            for(int j = 0; j < columns_num; j++){
                matrix[i].push_back(complex<double>());
            }
        }
    }

    Matrix::Matrix(initializer_list<vector<complex<double>>> numbers){
        initializer_list<vector<complex<double>>>::iterator it;

        rows_num = numbers.size();
        columns_num = (*numbers.begin()).size();

        if(columns_num <= 0 || rows_num <= 0) {
            rows_num = columns_num = 0;
            return;
        }

        for(int i = 0; i < rows_num; i++){
            matrix.push_back(vector<complex<double>>());
            for(int j = 0; j < columns_num; j++){
                matrix[i].push_back(complex<double>());
            }
        }

        int i = 0;
        for(it = numbers.begin(); it != numbers.end(); it++){
            for(int j = 0; j < columns_num; j++){
                matrix[i][j] = (*it)[j];
            }
            i++;
        }
    }

    Matrix::Matrix(string str) {
        columns_num = rows_num = 0;
        string row = "";
        for(int i = 0; i < str.length(); i++){
            if(rows_num == 1 && str[i] != ';') row += str[i];
            if(str[i] == ';') rows_num++;
        }
        rows_num++;
        row += ' ';
        for(int i = 0; i < row.length(); i++){
            if(row[i] == ' ') continue;
            else{
                columns_num++;
                while(row[i+1] != ' ') i++;
            }
        }

        for(int i = 0; i < rows_num; i++){
            matrix.push_back(vector<complex<double>>());
            for(int j = 0; j < columns_num; j++){
                matrix[i].push_back(complex<double>());
            }
        }

        string real = "";
        string imag = "";
        int rows = 0;
        int columns = -1;
        str[0] = str[str.length() - 1] = ' ';
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') continue;
            if (str[i] == ';') {
                rows++;
                columns = -1;
                continue;
            }
            while (str[i] != 'i' && str[i] != ' ' && str[i] != ';') {
                real += str[i];
                i++;
            }
            columns++;
            if (str[i] == 'i') {
                i++;
                while (str[i] != ' ' && str[i] != ';') {
                    imag += str[i];
                    i++;
                }
            } else imag = "0";
            i--;
            matrix[rows][columns] = {stod(real), stod(imag)};
            real = imag = "";
        }
    }

    Matrix Matrix::Add(const Matrix m) const{
        if(this->Size() != m.Size()) return Matrix(0, 0);

        Matrix tmp(rows_num, columns_num);
        for(int i = 0; i < rows_num; i++){
            for(int j = 0; j < columns_num; j++){
                tmp.matrix[i][j] = (matrix[i][j] + m.matrix[i][j]);
            }
        }
        return tmp;
    }

    Matrix Matrix::Sub(const Matrix m) const{
        if(this->Size() != m.Size()) return Matrix(0, 0);

        Matrix tmp{rows_num, columns_num};
        for(int i = 0; i < rows_num; i++)
            for(int j = 0; j < columns_num; j++){
                tmp.matrix[i][j] = (matrix[i][j] - m.matrix[i][j]);
            }
        return tmp;
    }

    Matrix Matrix::Mul(const Matrix m) const{
        if(columns_num != m.rows_num) return Matrix(0, 0);

        Matrix tmp{rows_num, m.columns_num};
        for(int i = 0; i < rows_num; i++)
            for(int k = 0; k < m.columns_num; k++) {
                tmp.matrix[i][k] = {0, 0};
                for (int j = 0; j < columns_num; j++) {
                    tmp.matrix[i][k] += matrix[i][j] * m.matrix[j][k];
                }
            }

        return tmp;
    }

    Matrix Matrix::Mul(const complex<double> x) const{
        Matrix tmp{rows_num, columns_num};
        for(int i = 0; i < rows_num; i++)
            for(int j = 0; j < columns_num; j++) {
                tmp.matrix[i][j] = matrix[i][j] * x;
            }
        return tmp;
    }

    Matrix Matrix::Pow(int x) const{
        if(columns_num != rows_num) return Matrix(0, 0);

        Matrix tmp{rows_num, columns_num};
        if(x == 0){
            for(int i = 0; i < rows_num; i++)
                for(int j = 0; j < columns_num; j++){
                    if(i == j) tmp.matrix[i][j] = 1. + 0.0i;
                    else tmp.matrix[i][j] = {0, 0};
                }
            return tmp;
        }

        tmp.matrix = matrix;
        if(x == 1) return tmp;

        for(int i = 0; i < x-1; i++){
            tmp = tmp.Mul(*this);
        }
        return tmp;
    }

    string Matrix::Print() const{
        if(rows_num == 0 || columns_num == 0) return "[]";

        string ret = "[";
        for(int i = 0; i < rows_num; i++){
            for(int j = 0; j < columns_num; j++){
                ret += " ";
                std::string str = std::to_string(matrix[i][j].real());
                str.erase(str.find_last_not_of('0') + 1, string::npos);
                if(str[str.length()-1] == '.') str.pop_back();
                ret += str;
                str = std::to_string(matrix[i][j].imag());
                str.erase(str.find_last_not_of('0') + 1, string::npos);
                if(str[str.length()-1] == '.') str.pop_back();
                ret += ("i" + str);
                ret += ",";
            }
            ret.pop_back();
            ret += ";";
        }
        ret.erase(0,1);
        ret[0] = '[';
        ret[ret.length() - 1] = ']';
        return ret;
    }

    std::pair<size_t, size_t> Matrix::Size() const{
        return {rows_num, columns_num};
    }


    bool Matrix::setElement(int x, int y, complex<double> el){
        if(x < 0 || x >= rows_num || y < 0 || y >= columns_num) return false;
        matrix[x][y] = el;
        return true;
    }

    complex<double> Matrix::getElement(int x, int y) const{
        if(x < 0 || x >= rows_num || y < 0 || y >= columns_num) return {0, 0};

        return matrix[x][y];
    }
}