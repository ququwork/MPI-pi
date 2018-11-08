#include<stdio.h>
#include<omp.h>

#define NUM_THREADS 2
long  N = 100000;

int main(){
    int i;
    double x, pi, sum[NUM_THREADS];
    double step = 1.0/(double)N;
    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel private(i)
    {
        double x;
        int id;
        id = omp_get_thread_num();
        for (i = id, sum[id] = 0.0; i < N; i = i+NUM_THREADS){
            x = (i + 0.5) * step;
            sum[id] += 4.0/(1.0 + x*x);
        }
    }

    for( i = 0, pi = 0.0; i < NUM_THREADS; i++)
        pi += sum[i] * step;
    printf(" Result of pi=%1f\n", pi);
    
    return 0;
}
