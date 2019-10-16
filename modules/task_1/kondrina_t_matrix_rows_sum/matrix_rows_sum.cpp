// Copyright 2019 Kondrina Tatyana

#include <mpi.h>

#include <valarray>

#include "./matrix_rows_sum.h"

std::valarray<int> rowSumSeq(std::valarray<int> const matrix) {

}

std::valarray<int> rowsSum(std::valarray<int> const matrix,
    int const rows, int const columns) {
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int __rowSendCount = columns;
    int delta = rows / size,
        remainder = rows % size;
    if (rank == 0 && delta != 0) {
        for (int currTurn = 0; currTurn < delta; ++currTurn) {
            for (int process = 1; process < size; ++process) {
                MPI_Send(&matrix[0] + process * delta, delta, )
            }
        }
    }

    std::valarray<int> localRow(delta);
    if (rank == 0) {
        localRow = ;
    } else {
        
    }

    int sum = localRow.sum();
    if (rank == 0) {
        localRow.resize(rows);
    }
    MPI_Barrier(MPI_COMM_WORLD);



    MPI_Reduce();
}
