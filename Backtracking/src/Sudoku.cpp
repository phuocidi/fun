#include "Sudoku.hpp"
#include <exception>
#include <cmath>
#include <deque>
#include <iostream>

using namespace std;

Sudoku::Sudoku(Matrix &mat, int size): _mat(mat), _size(size)
{
  if (_mat.size() != _size) {
    throw std::__throw_length_error;
  }
}

bool Sudoku::is_valid_sudoku(const Matrix &partial_mat) 
{
  // check row;
  for (int i = 0; i < _size; ++i) 
  {
    if(has_duplicate( partial_mat, i, i+1, 0, _size) ) 
    {
      return false;
    }
  }

  // Check column
  for(int j = 0; j < _size; ++j) 
  {
    if(has_duplicate(partial_mat, 0, _size, j, j+1)) 
    {
      return false;
    }
  }

  // check sub matrix
  int sub_size = sqrt(_size);
  for (int r = 0; r < sub_size; ++r) 
  {
    for (int c = 0; c < sub_size; ++c) 
    {
      if (has_duplicate(partial_mat, 
                        sub_size * r, 
                        sub_size * (r+1), 
                        sub_size * c, 
                        sub_size * (c+1)))
      {
        return false;
      }
    }
  }

  return true;
}

bool Sudoku::has_duplicate(const Matrix &partial_mat, int start_row, int end_row, int start_col, int end_col)
{
  std::deque<bool> is_present(partial_mat.size() + 1, false);

  for (int i = start_row; i < end_row; ++i)
  {
    for(int j = start_col; j < end_col; ++j) 
    {
      if ( partial_mat[i][j] != 0 &&  is_present[ partial_mat[i][j]])
      {
        return true;
      }
      is_present[partial_mat[i][j]] = true;
    }
  }
  return false;
}

bool Sudoku::is_valid_sudoku() {
  is_valid_sudoku(_mat);
}

string Sudoku::to_string() {
  string str;
  
  for (int r = 0; r < _size; ++r)
  {
    str.append("| ");
    for(int c = 0; c < _size; ++c)
    {
      str.append(std::to_string(_mat[r][c]));
      str.append(" ");
    }
    str.append(" |\n");
  }
  return str;
}

void Sudoku::demo() 
{
  const int kSize = 9;
  Matrix valid_mat {
  Vector{5,6,0,8,4,7,0,0,0},
  Vector{3,0,9,0,0,0,6,0,0},
  Vector{0,0,8,0,0,0,0,0,0},
  Vector{0,1,0,0,8,0,0,4,0},
  Vector{7,9,0,6,0,2,0,1,8},
  Vector{0,5,0,0,3,0,0,9,0},
  Vector{0,0,0,0,0,0,2,0,0},
  Vector{0,0,6,0,0,0,8,0,7},
  Vector{0,0,0,3,1,6,0,5,9}
};

  Matrix invalid_mat {
  Vector{5,6,0,8,4,7,0,0,0},
  Vector{3,0,9,0,0,0,6,0,0},
  Vector{3,0,8,0,0,0,0,0,0},
  Vector{0,1,0,0,8,0,0,4,0},
  Vector{7,9,0,6,0,2,0,1,8},
  Vector{0,5,0,0,3,0,0,9,0},
  Vector{0,0,0,0,0,0,2,0,0},
  Vector{0,5,6,0,0,0,8,0,7},
  Vector{0,0,0,3,1,6,0,5,9}
};


Sudoku invalid_sudoku = Sudoku(invalid_mat,kSize);
cout << invalid_sudoku.to_string();
cout << "is valid: " << invalid_sudoku.is_valid_sudoku() << endl;

Sudoku valid_sudoku = Sudoku(valid_mat,kSize);
cout << valid_sudoku.to_string();
cout << "is valid: " << valid_sudoku.is_valid_sudoku() << endl;
}