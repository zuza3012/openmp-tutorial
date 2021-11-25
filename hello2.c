#include <stdio.h>
#include <omp.h>

int main(void){
   
    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("Hello from %d threads:\n",omp_get_num_threads());
        }
        printf("Hello from thread: %d\n",omp_get_thread_num());
    }
    return 0;
}
