#include <stdio.h>
#include <omp.h>

int main(void){

    printf("Testing tasks and single in omp\n");

    #pragma omp parallel
    {   // single will be executed only once by one thread eaven if we have more than one threads  
        #pragma omp single
        {   int id = omp_get_thread_num();
            printf("This printf is executed by one thread: nr %d\n",  omp_get_thread_num());
             
            #pragma omp task
            {
                printf("Task 1:  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }

            #pragma omp task
            {
                printf("Task 2:  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }

            #pragma omp task
            {
               printf("Task 3:  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }

            #pragma omp task
            {
                printf("Task 4:  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }

            #pragma omp task
            {
                printf("Task 5:  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }

            #pragma omp task
            {
                printf("Task 6:  single thread: %d working thread: %d \n", id, omp_get_thread_num());
            }
        }       
        
        #pragma omp task
        {   
            #pragma omp critical
            {   // in this section should be 'critical' code, onlu executed once at a time by one thread
                // but it can be executed multiple times
                // for example writing to the variable
                printf ("In this section should be executed only once in the same time thread: id: %d\n",omp_get_thread_num() );
            }
        }
        // without taskwait code behind pragma parallel will be executed while other tasks are in progress
        // it prevents code behind parallel of crashing if it depends on some output from prallel region
        #pragma omp taskwait
        
    }
    
    printf("It will be in printed in a master thread\n\n");

    return 0;
}