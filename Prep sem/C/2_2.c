#include<stdio.h>
#include<math.h>

struct pair{
    int val;
    int count;
};
typedef struct pair Denom;
    
int cmp(const void* a, const void* b){
	Denom* p = (Denom*)a;
	Denom* q = (Denom*)b;
	return (q->val - p->val);
}


int main(){
	int m, n, i, count = 0;
	int times = 0;
	scanf("%d %d", &m, &n);
	
	int sum[n];
    
    Denom den[m];
	
	for(i = 0; i < m; i++){
		scanf("%d : %d", &den[i].val, &den[i].count);
       // printf(":");
	}
    
	
	for(i = 0; i < n; i++){
		scanf("%d", &sum[i]);
	}
	
    for(i = 0; i < m; i++){
		printf("%d:", den[i].val);
        printf("0");
        
        if(i != m-1){
            printf(",");
        }
	}
	
	printf("\n");
	int k = 0;
	
	qsort(den, m, sizeof(Denom), cmp);
	
	while(k < n){
        times = 0;
        if(sum[k] == 0){
				continue;
		}
		
        for(i = 0; i < m; i++){
			
			count = 0;
			if(sum[k] >= den[i].val && den[i].count != 0 ){
			     times++;
				while(sum[k] >= den[i].val && den[i].count != 0){
					sum[k] -= den[i].val;
					count++;
                    den[i].count--;
              
				}
			    if( times != 1){
                    printf(",");
                }
                
				printf("%d:%d", den[i].val, count);
                
			}		
		}
		k++;
        
		printf("\n");	
	}
    
	return 0;
}


