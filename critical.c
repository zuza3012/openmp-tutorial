#include <stdio.h>
#include <omp.h>

int main(void){

    int count = 0;
    int N = 10;
    int x[N];

    #pragma omp parallel
    for( int i = 0; i < N; i++){
        x[i] = i * i;
        #pragma omp critical
        count++;
        printf("x[%d] = %d, count = %d, thread: %d \n", i, x[i], count, omp_get_thread_num());
    }
    printf("count = %d\n", count);
    return 0;
}