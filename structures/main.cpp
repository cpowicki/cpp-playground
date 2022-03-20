#include "queue.cpp"
#include "heap.cpp"

int main()
{
  Queue q = Queue::with_capacity(2);

  q.push(2);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);

  q.print();
  std::cout << *q.pop() << '\n';
  q.print();
  std::cout << *q.pop() << '\n';
  q.print();
}

