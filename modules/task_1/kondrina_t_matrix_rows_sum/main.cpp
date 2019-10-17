// Copyright 2019 Kondrina Tatyana

#include <gtest-mpi-listener.hpp>
#include <gtest/gtest.h>
#include <mpi.h>

#include <valarray>
#include <iostream>

#include "../../../modules/task_1/kondrina_t_matrix_rows_sum/matrix_rows_sum.h"

TEST(Matrix_Rows_Sum_MPI, Sample_Test) {
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    std::valarray<int> testMatrix = randomMatrix(10, 9);
    std::valarray<int> result(9);
    if (rank == 0) {
        for (auto elem : testMatrix) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    result = rowsSum(testMatrix, 10, 9);

    if (rank == 0) {
        std::cout << "Sums: ";
        for (auto element : result) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        ASSERT_EQ(1, 1);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    MPI_Init(&argc, &argv);

    ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
    ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();

    listeners.Release(listeners.default_result_printer());
    listeners.Release(listeners.default_xml_generator());

    listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
    return RUN_ALL_TESTS();
}
