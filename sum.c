#include <stdio.h>
#ifdef _OPENMP
   #include <omp.h>
#else
   #define omp_get_thread_num() 0
#endif

int main(void){
    int sum = 0;
    int N = 10;    
    #pragma omp parallel for
    for(int i = 1; i <= N; i++){
        sum = sum + i;
        printf("sum = %d, thread %d\n", sum, omp_get_thread_num());
    }
    printf("sum = %d\n", sum);
    return 0;
}
