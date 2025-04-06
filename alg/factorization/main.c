#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printfactors(short fac[],int size) {
	for (int i = 2; i <= size; ++i) {
		if (fac[i]) { printf("%d %llu\n",i,fac[i]); } } }

void factorize(short array[], short n, short dir) {
	while (n%2 == 0) {
		array[2] += dir;
		n /= 2; }

	for (int i = 3; i*i <= n; i += 2) {
		while (n%i == 0) {
			array[i] += dir;
			n /= i; } }

	if (n > 2) { 
		array[n] += dir; } }

int main(int argc, char **argv)
{
	if (argc < 2) { printf("Usage: ./nchoosek N K\n"); exit(1); }
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int x = k;
	if (k > n) { printf("K must be less than N\n"); }
	long double C = 1;

	struct timespec start,stop;

	short fac[n+1];
	for (int i = 2; i <= n; ++i) { fac[i] = 0; } // zeroing loop

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	if (k > n-k) { x = n-k; } // flip k and n-k for k is bigger than 1/2n
	for (int i = n-x+1; i <= n; ++i) { factorize(fac,i,1); } // numerators

	//printfactors(fac,n);

	for (int i = 2; i <= x; ++i) { factorize(fac,i,-1); }

	//printfactors(fac,n);

	for (int i = 2; i <= n; ++i) {
		if (fac[i] == 1) {
			C *= i;
			continue; } 
		if (fac[i]) {
			C *= pow(i,fac[i]); }
	}

	
	clock_gettime(CLOCK_MONOTONIC_RAW, &stop);

	//printfactors(fac,n);
	printf("C(%d,%d): %.0Lf in %lluns\n",n,k,C,(stop.tv_sec - start.tv_sec)*1000000000 + stop.tv_nsec - start.tv_nsec);	


	return 0;
}
