#include<stdio.h>

int cmp(const void* a, const void* b){
	return *(int*)b - *(int*)a;
}

int main(){
	int m, n, i, count = 0;
	
	scanf("%d %d", &m, &n);
	
	int den[m], sum[n];
	
	for(i = 0; i < m; i++){
		scanf("%d", &den[i]);
	}
	
	printf("\n");
	
	for(i = 0; i < n; i++){
		scanf("%d", &sum[i]);
	}
	
	for(i = 0; i < m; i++){
		printf("%d", den[i]);
	}
	
	int k = 0;
	
	qsort(den, m, sizeof(int), cmp);
	
	while(k < n){
		for(i = 0; i < m; i++){
			if(sum[k] == 0){
				break;
			}
			count = 0;
			if(sum[k] >= den[i]){
			
				while(sum[k] >= den[i]){
					sum[k] -= den[i];
					count++;
				}
				printf("%d:%d ", den[i], count);
			}
			
		}
		k++;
		printf("\n");	
	}
	return 0;
}
