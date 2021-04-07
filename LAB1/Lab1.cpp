#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void* thread1_start(void* arg)
{
    std::cout << "\nTHREAD 1 STARTING" << std::endl;
    bool* ptr = (bool *) arg;
    while(!*ptr)
    {
        std::cout << '1';
        sleep(1);
    }
    int* retval_1 = new int;
    *retval_1 = 5;
    int n;
    std::cout << "enter number";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
    std::cout << i;
    }
    std::cout << "\nTHREAD 1 FINISHING" << std::endl;
    pthread_exit(retval_1);
}

static void* thread2_start(void* arg)
{
    std::cout << "\nTHREAD 2 STARTING" << std::endl;
    bool* ptr = (bool *) arg;
    while(!*ptr)
    {      
        std::cout << '2';
        sleep(1);
    }
    int* retval_2 = new int;
    *retval_2 = 10;
    std::cout << "\nTHREAD 2 FINISHING" << std::endl;
    pthread_exit(retval_2);
}

int main()
{
    std::cout << "PROGRAMM STARTING" << std::endl;
    bool cancel_thread_1 = false;
    bool cancel_thread_2 = false;
    int* ptr_t1;
    int* ptr_t2;

    pthread_t thread_1;
    pthread_t thread_2;
    pthread_create(&thread_1, NULL, thread1_start, &cancel_thread_1);
    pthread_create(&thread_2, NULL, thread2_start, &cancel_thread_2);
  
    std::cout << "PRESS ANY KEY" << std::endl;
    getchar();
    std::cout << std::endl;
    cancel_thread_1 = true;
    cancel_thread_2 = true;
    pthread_join(thread_1, (void**)&ptr_t1);
    pthread_join(thread_2, (void**)&ptr_t2);
    std::cout << "Return value of thread 1 - " << *ptr_t1 << std::endl;
    delete ptr_t1;
    std::cout << "Return value of thread 2 - " << *ptr_t2 << std::endl;
    delete ptr_t2;
    return 0;
}
