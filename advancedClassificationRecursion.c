#include "NumClass.h"
#include  <math.h>

int length (int p);
int revese (int num,int len);
int numDigits(int num);
int Armstrong(int num, int digits);
/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int num){
	
	int digits = numDigits(num) ;
	int ans = Armstrong(num,digits);
	if (num == ans){
		return 1;
	}
	return 0;
}

/* will return the number of digits */
int numDigits(int num){
	if (num ==0){
		return 0 ;
	}
	return numDigits(num/10)+1 ;

}

int Armstrong(int num, int digits){
	if(num == 0){
		return 0;
	}
	int last = num %10;
	return Armstrong(num/10,digits) + pow(last,digits);
	
}


/* will return if a number is a palindrome */
int isPalindrome(int p){
    if (p == revese(p,length(p))){
        return 1;
    }
    return 0;
}
/* will return the length of the number */
int length (int p){
	if (p==0){
            return 1;
        }
	int len = 0;

        while (p!= 0){
            len = len+1;
            p = p/10;
        }
        return len;
}


 /* will return the number reversed */       
int revese (int num,int len){
    if(len == 1){
        return num;
    }
    else{
        int last = num%10;
        int rev =  revese(num/10, len-1);
        int sum = last*((int)pow(10,len-1)) +rev;
        return sum ;
	}

}
