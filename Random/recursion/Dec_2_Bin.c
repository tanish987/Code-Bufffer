	/**
	*Print Binary representation of a number(Iterative version)
	**/
	
	#include<stdio.h>
	void toBinary(unsigned);
	void main(){
		unsigned n;
		
		scanf("%u", &n);
		
		toBinary(n);
		return 0;
	}
	
	void toBinary(unsigned n){
		unsigned i = 1;
		
		for(i = 1 << 31; i > 0; i /= 2){
			if(n & i){
				printf("1 ");
			}
			else{
				printf("0 ");
			}
		}
	}
