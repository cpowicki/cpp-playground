#include <stdlib.h> 

class MaxHeap {
    
    int* data;   
    int capacity;
    int size;

    public:
        MaxHeap(int c) {
            this->data = new int[c];
            size = 0;
            capacity = c;
        }
    
};