#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	if (argc < 2) { printf("Usage: ./nchoosek N K\n"); exit(1); }
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int x = k;
	if (k > n) { printf("K must be less than N\n"); }
	long double C = 1;

	struct timespec start,stop;

	if (k > n-k) { x = n-k; } // flip k and n-k for k is bigger than 1/2n

	long double lut[n+1][x+1];
	for (int i = 0; i <= n; ++i) { 
		for (int j = 0; j <= k; ++j) {
			lut[i][j] = 0; } } // zeroing loop

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (j == 0 || j == i) {
				lut[i][j] = 1; } } }

	clock_gettime(CLOCK_MONOTONIC_RAW, &start);

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			lut[i][j] = lut[i-1][k] + lut[i-1][k-1]; } }
	
	clock_gettime(CLOCK_MONOTONIC_RAW, &stop);

	//printfactors(fac,n);
	printf("C(%d,%d): %.0Lf in %lluns\n",n,k,lut[n][k],(stop.tv_sec - start.tv_sec)*1000000000 + stop.tv_nsec - start.tv_nsec);	


	return 0;
}
