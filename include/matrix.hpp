#ifndef __MATRIX__
    #define __MATRIX__

    #include "main_header.h"

    class Matrix
    {
        public:
            /* Variables */
            uint**  matrix = nullptr;
            uint    size;

           /* Constructor and Destructor*/
            Matrix  (uint _size);
           ~Matrix  ();

           /** Methods **/
           // Core
            void fill();
            void fillZeros();

            void allocate();
            void deallocate();

           // Utils
            void print();
            
    };

    /* Multiplication algorithms */
    Matrix* classic_Mult(Matrix*, Matrix*);
    Matrix* block_Mult  (Matrix*, Matrix*);

#endif // !__MATRIX__