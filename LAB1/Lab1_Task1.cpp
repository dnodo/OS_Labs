#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>


typedef struct thread_data {
    int num;
    int* res_arr;

} thread_data;

void* task1(void* arg)
{
    thread_data *tdata = (thread_data *)arg;

    for(int i = 0; i <= tdata->num; i++)
    {
        tdata->res_arr[i] = i;
    }

    pthread_exit(NULL);
}

int main()
{
  pthread_t ID1;
  int ret;
  std::cin >> ret;
  thread_data tdata;
  tdata.num = ret;
  tdata.res_arr = new int[ret+1];
  pthread_create (&ID1 , NULL , task1 , (void* )&tdata);
  pthread_join(ID1, NULL);

  for(int i = 0; i <= ret; i++)
  {
    std::cout << tdata.res_arr[i];
  }

  return 0;
}
