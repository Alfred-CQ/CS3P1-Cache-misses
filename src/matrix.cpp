#include "../include/matrix.hpp"

/* Multiplication algorithms */
Matrix* classic_Mult(Matrix* A, Matrix* B)
{
    if (A->size != B->size)
    {
        std::cout << "[ Error ] Matrixes of different sizes\n";

        return nullptr;
    }

    uint i, j, k;

    Matrix* C = new Matrix(A->size);

    for (i = 0; i < A->size; ++i)
    {
        for (j = 0; j < A->size; ++j)
        {
            C->matrix[i][j] = 0;
            for (k = 0; k < A->size; ++k)
                C->matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]);
        }   
    }

    return C;
}

Matrix* block_Mult(Matrix* A, Matrix* B)
{
    if (A->size != B->size)
    {
        std::cout << "[ Error ] Matrixes of different sizes\n";

        return nullptr;
    }

    uint i, j, k, ii, jj, kk;

    Matrix* C = new Matrix(A->size);

    for (ii = 0; ii < A->size; ii += A->block_size)
        for (jj = 0; jj < A->size; jj += A->block_size)
            for (kk = 0; kk < A->size; kk += A->block_size)
                for (i = ii; i < ii + A->block_size; i++)
                    for (j = jj; j < jj + A->block_size; j++)
                        for (k = kk; k < kk + A->block_size; k++)
                            C->matrix[i][j] += (A->matrix[i][k] * B->matrix[k][j]);

    return C;
}

/** Class Matrix **/
/* Constructors and Destructor */
Matrix::Matrix(uint _size, uint _block_size)
{
    this->size = _size;
    this->block_size = _block_size;

    this->allocate();
    this->fillZeros();
}

Matrix::~Matrix()
{
    this->deallocate();
}

/* Methods */
// Core
void Matrix::fill()
{
    uint i, j;

    for (i = 0; i < this->size; ++i)
        for (j = 0; j < this->size; ++j)
            matrix[i][j] = rand() % MAX_RANDOM_VALUE;

}

void Matrix::fillZeros()
{
    uint i, j;

    for (i = 0; i < this->size; ++i)
        for (j = 0; j < this->size; ++j)
            matrix[i][j] = 0;
}

void Matrix::allocate()
{
    uint i;

    matrix = new uint*[this->size];

    for (i = 0; i < this->size; ++i)
        matrix[i] = new uint[this->size];
}

void Matrix::deallocate()
{
    uint i;
    for (i = 0; i < this->size; ++i)
        delete matrix[i];
    
    delete[] matrix;

    matrix = nullptr;
}

// Utils
void Matrix::print()
{
    uint i, j;

    for (i = 0; i < this->size; ++i)
    {
        for ( j = 0; j < this->size; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
}