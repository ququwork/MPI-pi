#include<stdio.h>
#include<omp.h>
#define NUM_THREADS 4

long N = 100000;

int main(){
    int i, id;
    double x, pi, sum;
    double step = 1.0/(double) N;
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel private(id, i, x, sum)
    {
        id = omp_get_thread_num();
        for (i = id, sum = 0.0; i < N; i = i+NUM_THREADS){
            x = (i + 0.5) * step;
            sum += 4.0/(1.0 + x*x);
        }
        #pragma omp critical
        pi += sum;
    }
    pi *= step;
    printf(" Result of pi=%1f\n", pi);
    return 0;
}
