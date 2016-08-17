 /**
   * Given a set of characters and a positive integer k, print all possible strings of length k that can be formed from the given set.
 **/

#include <stdio.h>

int main(void) {	
	int size, len;
	
	scanf("%d%d", &size, &len);
	
	char arr[size], data[len];
	int i;
	
	for(i = 0; i < size; i++){
		scanf(" %c", &arr[i]);
	}
	
	for(i = 0; i < size; i++){
		printf("%c", arr[i]);
	}
	printf("\n");
	permute(arr, 0, size-1, 0, len, data);
	
	return 0;
}

void permute(char* arr, int start, int end, int index, int len, char* data){
	int i;
	if(index == len){
		for(i = 0; i < len; i++){
			printf("%c", data[i]);
		}
		printf("\n");
		return;
	}

	for(i = 0; i <= end; i++){
	
		data[index] = arr[i];
		permute(arr, 0, end, index+1, len, data);
	}
}

