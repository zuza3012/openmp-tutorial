#include <stdio.h>
#include <omp.h>

int main(void){

    printf("Testing tasks and single in omp\n");

    #pragma omp parallel
    {
        #pragma omp single
        {   int id = omp_get_thread_num();
            printf("This printf is executed by one thread: nr %d\n",  omp_get_thread_num());
             
            #pragma omp task
            {
                 printf("Task 1:  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }

            #pragma omp task
            {
                 printf("Task 2 :  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }

            #pragma omp task
            {
                printf("Task 3:  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }
        }
    }

    return 0;
}
