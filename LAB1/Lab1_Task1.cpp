#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

void* task1(void*N)
{
  int *n = (int*)n;
  for (int i = 0; i < n; i++)
    {
      std::cout << i;
    }
  return;
}

int main()
{
  pthread_t ID1;
  int N;
  std::cin >> N;
  pthread_create (&ID1 , NULL , task1 , NULL);
  int* task1_return;  
  delete(task1_return);
}
