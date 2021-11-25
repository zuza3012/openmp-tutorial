#include <stdio.h>
#include <omp.h>

void print1(int rank){
    printf("Print 1 from rank %d\n", rank);
}
void print2(int rank){
    printf("Print 2 from rank %d \n", rank);
}
int main(void){
   #pragma omp parallel sections
   {
        #pragma omp section
        {
            printf ("id = %d \n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf ("id = %d \n", omp_get_thread_num());
        }
   }
    return 0;
}

