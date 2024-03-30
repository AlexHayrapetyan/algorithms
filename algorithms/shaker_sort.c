#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void dump_array(double *arr, int size, const char *file_name) {
	FILE *f ;
	f = fopen(file_name, "w") ;
	if (f == NULL) {
		fprintf(stderr, "Error openeing file: %s\n", file_name) ;
		exit(2) ;
	}

	for (int i = 0; i < size - 1; ++i) {
		fprintf(f, "%.2lf ", arr[i]) ;
	}
	fprintf(f, "%.2lf\n", arr[size - 1]) ;
	
	fclose(f) ;
}

void shaker_sort(double *A, int n) {
	int swapped = 0 ;
	do {
		swapped = 0 ;
		for (int i = 0; i < n - 1; ++i) {
			if (A[i] > A[i + 1]) {
				double tmp = A[i] ;
				A[i] = A[i + 1] ;
				A[i + 1] = tmp ;
				swapped = 1 ;
			}
		}
		if (!swapped) break ;
		for (int i = n - 1; i >= 0; --i) {
			if (A[i] > A[i + 1]) {
				double tmp = A[i] ;
				A[i] = A[i + 1] ;
				A[i + 1] = tmp ;
				swapped = 1 ;
			}
		}
	} while (swapped) ;
}

double min = -10.0 ;
double max = 10.0 ;

int main(int argc, char **argv) {
	int n;
	double *arr = NULL ;
	printf("Provide the array size - ") ;
	scanf("%d", &n) ;

	arr = (double *)malloc(n * sizeof(double)) ;
	if (arr == NULL) {
		fprintf(stderr, "Error: failed to allocate memory!\n") ;
		exit(1) ;
	}
	double *sorted_arr = (double *)malloc(n * sizeof(double)) ;
	if (sorted_arr == NULL) {
		fprintf(stderr, "Error: failed to allocate memory!\n") ;
		exit(1) ;
	}

	for (int i = 0; i < n; ++i) {
		arr[i] = min + (max - min) * ((double)rand() / RAND_MAX) ;
	}

	printf("\nThe initial array is written in orig.txt:\n") ;
	dump_array(arr, n, "orig.txt") ;

	memcpy(sorted_arr, arr, n * sizeof(double)) ;
	printf("\nSorting array with Shaker sort:\n") ;
	clock_t start = clock() ;

	shaker_sort(sorted_arr, n) ;
	clock_t end = clock() ;
	double sort_time = (double)(end - start) / CLOCKS_PER_SEC ;
	printf("\nShaker sort time spent %.4lf:\n", sort_time) ;
	printf("\nThe Shaker sorted array is written in shaker.txt:\n") ;
	dump_array(sorted_arr, n, "shaker.txt") ;

	printf("\n") ;
	free(arr) ;
	free(sorted_arr) ;
	return 0 ;
}
