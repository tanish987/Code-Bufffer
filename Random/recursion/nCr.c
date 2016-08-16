#include<stdio.h>

void combination(int* arr, int initial, int end, int index, int r, int* data);

void main(){
	int r, n, i;
	
	scanf("%d%d", &r, &n);
	
	int arr[n];
	int data[r];
	
	for(i = 0; i<n; i++){
		scanf("%d", &arr[i]);
//		printf("%d", arr[i]);
	}
	
	printf("\n");
	combination(arr, 0, n-1, 0, r, data);
}

void combination(int* arr, int initial, int end, int index, int r, int* data){
	int j = 0;
	if(index == r){
	
		for(j = 0; j < r; j++){
			printf("%d ", data[j]);
		}
		printf("\n");
		return;
	}

	for(j = initial; j <= end && end-j+1 >= r-index; j++){

		data[index] = arr[j];
		combination(arr, j+1, end, index+1, r, data);
	}
}
