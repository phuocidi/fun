#ifndef BACKTRACKING_SUDOKU_H
#define BACKTRACKING_SUDOKU_H
#pragma once

#include <vector>
#include <string>

typedef std::vector<std::vector<int>> Matrix;
typedef std::vector<int> Vector;
class Sudoku {
  private:
    int _size; 
    Matrix _mat;
    bool is_valid_sudoku(const Matrix &partial_mat);
    bool has_duplicate( const Matrix &partial_mat, int start_row, int end_row, int start_col, int end_col);
  public:
    Sudoku(Matrix &mat, int size);
    bool is_valid_sudoku();
    std::string to_string();
    static void demo();
};

#endif