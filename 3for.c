#include<stdio.h>
#include<omp.h>

#define NUM_THREADS 4
long N = 100000;

int main(){
    int i, id;
    double x, pi, sum[NUM_THREADS];
    double step = 1.0/(double) N;
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel private(x, id)
    {
        id = omp_get_thread_num();
        sum[id] = 0;

        #pragma omp for
        for(i = 0; i < N; i++){
            x = (i-0.5) * step;
            sum[id] += 4.0/(1.0 + x*x);
        }
    }

    for(i = 0, pi = 0.0; i < NUM_THREADS; i++)
        pi += sum[i] * step;
    printf(" Result of pi=%lf\n", pi);
    return 0;
}
