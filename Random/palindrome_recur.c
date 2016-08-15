#include <stdio.h>

int main() {
	int n;
	
	scanf("%d", &n);
	
	int copy = n;
	
	if(isPalindrome(n, &copy)){
		printf("Yes, number is palindrome");
	}
	else{
			printf("No, number is palindrome");
	}
	
	return 0;
}

int isPalindrome(int n, int* copy){
	if(isOneDigit(n)){
		return n == (*copy)%10;
	}
	
	if(!isPalindrome(n/10, copy)){
		return 0;
	}
	
	*copy /= 10;
	
	return (n%10 == (*copy)%10);
}

int isOneDigit(int n){
	return n>=0 && n<=9;
}
