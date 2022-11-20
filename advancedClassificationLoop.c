#include "NumClass.h"

int nth_power(int number,int pow);

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int number){
	int temp = number ;
	int counter = 0;
/*calculates the number of digits of number*/
	while( temp != 0 ){	
		temp= temp/10;
		counter=counter+1;
	}

	int digit = 0 ;
	int sum = 0 ;
	temp = number ;
	while( temp != 0 ){
		digit = temp %10 ;
		temp= temp/10;
		sum = sum+ nth_power(digit,counter);

	}
	if(number ==sum){
		return 1;
	}
	return 0;
}
/*calculates the nth power of a digit*/
int nth_power(int number,int pow){
	int sum=1;
	while(pow>0){
		sum = sum*number;
		pow = pow-1;
	}
	return sum;
}


/* will return if a number is a palindrome */
int isPalindrome(int num){
	int save_num = num;
	int reversed =num % 10 ;
	num = num/10;
	while(num != 0){
		reversed = (reversed * 10)+ (num % 10) ;
		num = num/10;
	}
	if(save_num == reversed){
		return 1;
	}	
	return 0 ;


}
