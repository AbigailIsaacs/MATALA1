#include "NumClass.h"
#include <math.h>

int factorial(int i);

/*Strong number is a special number whose sum of the factorial of digits is equal to the original
number. For Example: 145 is strong number
1! + 4! + 5! = 145
*/
int isStrong(int number){
	int digit = 0 ;
	int sum = 0 ;
	int temp = number ;
	while( temp != 0 ){
		digit = temp %10 ;
		temp= temp/10;
		sum = sum+ factorial(digit);
	}
	if(number !=sum){
		return 0;
	}
	return 1;
}
/*calculates factorial*/
int factorial(int number){
	int counter = 1;
	int atz = 1;
	while( counter <= number){
		atz = atz*counter;
		counter = counter+1 ;

	}
	return atz;
}
/* will return if a number is prime*/
int isPrime(int number){
	int counter = 2;
	
	while (counter <=(int)sqrt(number)){
		if ((number % counter) == 0){
			return 0;
		}
		counter = counter+1;
	}
	return 1;


}



