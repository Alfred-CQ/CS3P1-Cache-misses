#include "../include/matrix.hpp"

int main()
{
    srand(time(NULL));

    Matrix* A{ new Matrix(16)}, *B{ new Matrix(16)}, *C, *D;

    A->fill(); B->fill();

    C = classic_Mult(A, B);
    D = block_Mult(A, B);

    std::cout << "░░░░ Matrix A ░░░░ \n";
    A->print();
    
    std::cout << "░░░░ Matrix B ░░░░ \n";
    B->print();

    std::cout << "\n░░░░ Matrix C | Classic Mult ░░░░ \n";
    C->print();

    std::cout << "░░░░ Matrix D | Block Mult ░░░░ \n";
    D->print();
}