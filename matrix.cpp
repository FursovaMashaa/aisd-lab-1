#pragma once
#include <iostream>
#include <random>
#include<exception>
#include<complex>
using namespace std;


namespace matrixx {
    template<class T>
    class Matrix {
    private:
        int _rows;
        int _cols;
        T** _data;

    public:
        Matrix() { _rows = 0; _cols = 0; _data = nullptr; }
        Matrix(size_t r, size_t c, T value){
            this->_rows = r;
            this->_cols = c;
            _data = new T * [_rows];
            for (size_t i = 0; i < _rows; i++){
                _data[i] = new T[_cols];
                for (size_t j = 0; j < _cols; j++){
                    _data[i][j] = value;
                }
            }
        }
        void print(){
            for (int i = 0; i < _rows; i++) {
                for (int j = 0; j < _cols; j++) {
                    std::cout << _data[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        Matrix(size_t r, size_t c, T low, T up){
            this->_rows = r;
            this->_cols = c;
            _data = new T * [_rows];
            std::mt19937 rng(std::random_device{}());
            std::uniform_int_distribution<T> distribution(low, up);
            for (size_t i = 0; i < _rows; i++){
                _data[i] = new T[_cols];
                for (size_t j = 0; j < _cols; j++){
                    _data[i][j] = distribution(rng);
                }
            }
        }



        T get_rows(){
            return _rows;
        }

        T get_cols(){
            return _cols;
        }
    };
             
};

