#include "queue.cpp"
#include "heap.cpp"

int main()
{
  MaxHeap heap (10);
  heap.insert(1);
  heap.print();
  
  heap.insert(5);
  heap.print();
  
  heap.insert(3);
  heap.print();

  heap.insert(12);
  heap.print();
  
  heap.insert(10);
  heap.print();

  heap.pop();
  heap.print();
  heap.pop();
  heap.print();
  heap.pop();
  heap.print();
  heap.pop();
  heap.print();
  heap.pop();
  heap.print();
}

