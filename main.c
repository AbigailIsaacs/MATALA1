#include "NumClass.h"
#include  <stdio.h>
#include  <math.h>

int main(){
	int n1 =-1;
	int n2 =-1;
	printf("Enter two Intiger numbers -");
	scanf("%d %d",&n1,&n2);

	int between = n1;
	
	printf("\nThe Armstrong numbers are:");
		while(between<=n2){
			if (isArmstrong(between) == 1){
				printf(" %d",between);
			}
			between = between+1;
		}

	between = n1;

	printf("\nThe Palindromes are:");
		while(between<=n2){
			if (isPalindrome(between) == 1){
				printf(" %d",between);
			}
			between = between+1;
		}
	
	between = n1;
	printf("\nThe Prime numbers are:");
		while(between<=n2){
			if (isPrime(between) == 1){
				printf(" %d",between);
			}
			between = between+1;
		}
	between = n1;
	printf("\nThe Strong numbers are:");
	
		while(between<=n2){
			if (isStrong(between) == 1){
				printf(" %d",between);
			}
			between = between+1;
		}
	printf("\n");
	
	
	return 0;
}
