// Copyright 2019 Kondrina Tatyana

#ifndef MODULES_TASK_1_KONDRINA_T_MATRIX_ROWS_SUM_MATRIX_ROWS_SUM_H_
#define MODULES_TASK_1_KONDRINA_T_MATRIX_ROWS_SUM_MATRIX_ROWS_SUM_H_

#include <valarray>

std::valarray<int> rowsSumSeq(std::valarray<int> const matrix);
std::valarray<int> rowsSum(std::valarray<int> const matrix);
std::valarray<int> randomMatrix(int const cols, int const rows);

#endif