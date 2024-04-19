#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** matrixcreate(int m) 
{
    int** mass;
    int i, j;
    mass = (int**)calloc(m, sizeof(int*));
    for (i = 0; i < m; i++) 
	{
        mass[i] = (int*)calloc(m, sizeof(int));
    }
    for (i = 0; i < m; i++) 
	{
        for (j = 0; j < m; j++) 
		{
            mass[i][j] = rand() % 100;
        }
    }
    return mass;
}

double** prod(int** mass1, int** mass2, int m) 
{
    int i, j, o;
    double** s = (double**)malloc(m * sizeof(double*));
    for (i = 0; i < m; i++) 
	{
        s[i] = (double*)malloc(m * sizeof(double));
    }
    for (i = 0; i < m; i++) 
	{
        for (j = 0; j < m; j++) 
		{
            s[i][j] = 0;
            for (o = 0; o < m; o++) 
			{
                s[i][j] += mass1[i][o] * mass2[o][j];
            }
        }
    }
    return s;
}

int main() 
{
    double time_clock = 0.0;
    int m, i, j;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &m);
    clock_t opening = clock();
    int** mass1 = matrixcreate(m);
    int** mass2 = matrixcreate(m);
    double** x = prod(mass1, mass2, m);
    clock_t ending = clock();
    for (i = 0; i < m; i++) 
	{
        for (j = 0; j < m; j++) 
		{
            printf("%lf ", x[i][j]);
        }
        printf("\n");
    }
    // Free memory
    for (i = 0; i < m; i++) 
	{
        free(mass1[i]);
        free(mass2[i]);
        free(x[i]);
    }
    free(mass1);
    free(mass2);
    free(x);
    time_clock = (double)(ending - opening) / CLOCKS_PER_SEC;
    printf("The elapsed time is %.3f seconds\n", time_clock);
    return 0;
}
