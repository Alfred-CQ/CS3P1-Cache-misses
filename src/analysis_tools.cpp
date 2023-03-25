#include "../include/matrix.hpp"

int main(int argc, char *argv[])
{
    if (argc != 3)
        return 1;

    srand(time(NULL));

    uint size_Matrix{atoi(argv[1])}, block_Size{atoi(argv[2])};
 
    Matrix *A, *B, *C;

    A = new Matrix(size_Matrix, block_Size);
    B = new Matrix(size_Matrix, block_Size);

    A->fill(); B->fill();

    auto start = std::chrono::system_clock::now();
    //C = classic_Mult(A, B);
    C = block_Mult(A,B);
    auto end = std::chrono::system_clock::now();
    
    std::chrono::duration<float,std::milli> duration = end - start;
    std::cout << "Matrix size\x1B[1m\x1B[34m [" << size_Matrix << " * " << size_Matrix << "] \x1B[0m"
              << "Execution time:\x1B[1m\x1B[33m " << duration.count() << " ms \x1B[0m \n";
    
    A->deallocate(); B->deallocate(); C->deallocate();

    return 0;
}