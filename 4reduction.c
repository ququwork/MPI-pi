#include<stdio.h>
#include<omp.h>
#define NUM_THREADS 2

long N = 100000;

void main(){
    int i;
    double pi = 0.0, sum = 0.0, x = 0.0;
    double step = 1.0/(double)N;
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel for reduction(+:sum) private(i)
    for (i = 1; i < N; i++){
        x = (i-0.5) * step;
        sum += 4.0/(1 + x*x);
    }
    pi = sum * step;
    printf(" Result of pi=%lf\n", pi);
}
