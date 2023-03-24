#include "../include/matrix.hpp"

int main()
{
    srand(time(NULL));

    uint i, testing_sizes[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    uint testing_Size = sizeof(testing_sizes)/sizeof(testing_sizes[0]);
    
    Matrix *A, *B, *C;

    for (i = 0; i < testing_Size; ++i)
    {
        A = new Matrix(testing_sizes[i]);
        B = new Matrix(testing_sizes[i]);

        A->fill(); B->fill();

        auto start = std::chrono::system_clock::now();
        //C = classic_Mult(A, B);
        C = block_Mult(A,B);
        auto end = std::chrono::system_clock::now();

        std::chrono::duration<float,std::milli> duration = end - start;

        std::cout << "Matrix size\x1B[1m\x1B[34m [" << testing_sizes[i] << " * " << testing_sizes[i] << "] \x1B[0m"
                  << "Execution time:\x1B[1m\x1B[33m " << duration.count() << " ms \x1B[0m \n";

        A->deallocate(); B->deallocate(); C->deallocate();
    }

    return 0;
}