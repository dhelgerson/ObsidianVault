#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printfactors(short fac[],int size) {
	for (int i = 2; i <= size; ++i) {
		if (fac[i]) { printf("%d %llu\n",i,fac[i]); } } }


int main(int argc, char **argv)
{
	if (argc < 2) { printf("Usage: ./nchoosek N K\n"); exit(1); }
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int x = k;
	if (k > n) { printf("K must be less than N\n"); }
	long double upper = 1;
	long double lower = 1;

	struct timespec start,stop;

	short fac[n+1];
	for (int i = 2; i <= n; ++i) { fac[i] = 0; } // zeroing loop

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	if (k > n-k) { x = n-k; } // flip k and n-k for k is bigger than 1/2n
	for (int i = n-x+1; i <= n; ++i) { ++fac[i]; } // numerators

	//printfactors(fac,n);

	for (int i = x; i >= 2; --i) { // denominators
		for (int j = (n/i)*i; j >= n; j -= i) {
			//printf("loop: i:%d j:%d fac[i]=%llu\n",i,j,fac[i]);
			if (fac[j]) {
				--fac[j];
				++fac[j/i]; 
				goto breakpoint;
			} 
		} 
		//printf("didn't factor %d\n",i);
		lower *= i;
		breakpoint:
	}

	for (int i = 2; i <= n; ++i) {
		if (fac[i] == 1) {
			upper *= i;
			continue; } 
		if (fac[i]) {
			upper *= pow(i,fac[i]); }
	}

	long double ans = upper / lower;
	
	clock_gettime(CLOCK_MONOTONIC_RAW, &stop);

	//printfactors(fac,n);
	printf("naive-factorization,%d,%d,%.0Lf,%llu\n",n,k,ans,(stop.tv_sec - start.tv_sec)*1000000000 + stop.tv_nsec - start.tv_nsec);	
	// printf("C(%d,%d): %.0Lf in %lluns\n",n,k,ans,(stop.tv_sec - start.tv_sec)*1000000000 + stop.tv_nsec - start.tv_nsec);	


	return 0;
}
