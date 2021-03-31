#include <stdlib.h>

#define HASH_SIZE 100

/*
	c solution for sock merchant problem from hackerrank.com
	problems URL = https://hackerrank.com/challenges/sock-merchant/problem
	time complexity = O(n)
*/


int sockMerchant(int n, int ar_count, int* ar){
	int *hashArr = calloc(sizeof(int),HASH_SIZE);
	int pairs = 0;
	
	for(int i=0; i<n; i++){
		if(hashArr[ar[i]-1] == 0)
			hashArr[ar[i]-1] = ar[i];
		else{  // if pairs match, clean it to count if there will be other pair with same value
			pairs++;
			hashArr[ar[i]-1] = 0;
		}
	}
	return pairs;
}
