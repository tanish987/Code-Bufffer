	/**
	*Print Binary representation of a number(Recursive version)
	**/
	
	#include<stdio.h>
	
	void main(){
		unsigned n;
		
		scanf("%u", &n);
		
		toBinary(n);
		return 0;
	}
	
	toBinary(unsigned n){
		if( n > 1){
			toBinary(n/2);
		}
		
		printf("%d", n%2);
	}
