#include <stdlib.h> 

// given index i, 
//  * left = 2i + 1
//  * right = 2i + 2
//  * parent = floor(i/2)
class MaxHeap {
    
    int* data;   
    int capacity;
    int size;

    private: 
        void heapify_down(int idx) {
            if (size == 1) { return; }
            while (true) {
                // set max_idx = left index
                int max_idx = 2 * idx + 1;
                int right_idx = 2 * idx + 2;
                // check if right is in bounds and greater than max
                if (right_idx < size && data[right_idx] > data[max_idx]) {
                    max_idx = right_idx;
                }

                if (data[max_idx] > data[idx]) {
                    std::swap(data[idx], data[max_idx]);
                    idx = max_idx;
                } else {
                    return;
                }
            }
        }
        void heapify_up(int idx) {
            while (data[idx] > data[idx / 2]) {
                std::swap(data[idx], data[idx/2]);
                idx/=2;
            };
        };
                
        void resize() {}

    public:
        MaxHeap(int c): size(0), capacity(c) {
            data = new int[c];
        }

        int peek() {
            return data[0];
        }

        int pop() {
            if (size == 0)
                return (int) NULL;
            
            if (size == 1) {
                size--;
                return data[0];
            }

            int ret = data[0];
            data[0] = data[size-1];
            size--;
            
            heapify_down(0);
            
            return ret;
        }
        
        void insert(int e) {
            if (size == capacity) { resize(); }
            
            data[size] = e;   
            size++;         
            heapify_up(size-1);
        }

        void print() {
            if (size == 0) {
                std::cout << "[]\n";
                return;
            }
            std::cout << "[ ";
            for (int i = 0; i < size; i++) {
                std::cout << data[i];
                
                if (i < size-1) {
                    std::cout << ", ";
                } else {
                    std::cout << " ]\n";
                }
            }
        }

        ~MaxHeap() {
            delete[] data;
        }
};

