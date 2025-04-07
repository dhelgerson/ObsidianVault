#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BIL 1000000000L
#define LUT_SIZE 199

unsigned long long lut[LUT_SIZE][LUT_SIZE];

// Recrusive funciton
unsigned long long C(unsigned long long n, unsigned long long k)
{
	if (k == 0 || k == n) { return 1; }
	if (lut[n][k]) { 
		return lut[n][k];
	}
	lut[n][k] = C(n-1, k) + C(n-1,k-1);
	return lut[n][k];
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{ printf("Usage: nchoosek N K\n");
		exit(1); }
	int n = atoi(argv[1]), k = atoi(argv[2]);
	if (k > n)
	{ printf("Cannot choose more than available\n");
		exit(2); }
  //printf("Method,N,K,Solution,time(ns)\n");

  // Variables used by both
  struct timespec start, stop;

	// Begin memoization approach -------------------------------------------------------------
	// Nuke the lut
	for (int i = 0; i < LUT_SIZE; ++i){
		for (int j = 0; j < LUT_SIZE; ++j){
			lut[i][j] = 0; } }

	// start timer
  clock_gettime(CLOCK_MONOTONIC, &start);
	// Do calculations:
	unsigned long long answer = C(n,k);
	// stop timer
  clock_gettime(CLOCK_MONOTONIC, &stop);

	// print results
	printf("Memoization,%d,%d,%llu,%llu\n",n,k,answer,BIL * (stop.tv_sec - start.tv_sec) + stop.tv_nsec - start.tv_nsec);

	// Begin bottom up ------------------------------------------------------------------------
	// Nuke the lut
	for (int i = 0; i < LUT_SIZE; ++i){
		for (int j = 0; j < LUT_SIZE; ++j){
			lut[i][j] = 0; } }

	// start timer
  clock_gettime(CLOCK_MONOTONIC, &start);

  // set the correct identities:
  for (int i = 0; i <= n; ++i){
    lut[i][0] = 1;
    lut[i][i] = 1; }

  // build the rest
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= k; ++j){
      lut[i][j] = lut[i-1][j] + lut[i-1][j-1]; } } 

	// stop timer
  clock_gettime(CLOCK_MONOTONIC, &stop);
	
	// print results
	printf("Bottom-up,%d,%d,%llu,%llu\n",n,k,lut[n][k],BIL * (stop.tv_sec - start.tv_sec) + stop.tv_nsec - start.tv_nsec);

	return 0;
}
