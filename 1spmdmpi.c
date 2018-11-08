#include<stdio.h>
#include<mpi.h>
int main(int argc, char** argv){
    long N = 100000;
    int mid, incresment, i;
    double mpi, pi, sum, x,step;
  
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &incresment);
    MPI_Comm_rank(MPI_COMM_WORLD, &mid);

    sum = 0;
    step = 1.0/(double)N;
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    for(i = mid + 1; i <= N; i += incresment){
        x = ((double)i - 0.5) * step;
        sum += 4/(1 + x*x);
    }

    mpi = sum * step;
   
    MPI_Reduce(&mpi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if(mid == 0)
        printf(" Result of pi=%f\n", mid ,pi);
    MPI_Finalize();
    return 0;
}
