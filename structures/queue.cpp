#include <iostream>
#include <sstream>
#include <string>

class Queue {
  int* data;
  int capacity;
  int size;

  private:
    void resize() 
    {
      int c = capacity*2;
      int* ptr = (int*) realloc(data, c * sizeof(int));
      
      if (ptr == NULL) {
        free(data);
        exit(1);
      }

      data = ptr;
      capacity = c;
    }
  public:
    static Queue with_capacity(int c) 
    {
      Queue q;
      q.data = (int*) malloc(c * sizeof(int));
      q.capacity = c;
      q.size = 0;

      return q;
    };
    void push(int e) 
    {
      if (size == capacity) { resize(); }
      
      *(data + size) = e;
      size++;
    }
    int* pop() 
    {
      int* ret = data;
      data = data + 1;
      size--;
      return ret;
    }    
    int peek(void);
    int length(void);
    const int at(int);
    void print(void);
};

void Queue::print() 
{
  std::cout << "[ ";
  for (int i = 0; i < this->length(); i++) {
    std::cout << this->at(i);
    
    if (i < this->length()-1) {
      std::cout << ", ";
    } else {
      std::cout << " ]\n";
    }
  }
}

const int Queue::at(int i) 
{
  return *(data + i);
}

int Queue::length() 
{
  return size;
}

int Queue::peek() 
{
  if (size == 0) {
    return -1;
  }
  return *data;
}