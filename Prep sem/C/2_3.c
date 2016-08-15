#include<stdio.h>

int min(int, int);

int min(int a, int b){
	
	if(a >= b){
		return b;
	}
	else{
		return a;
	}
	
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a- *(int*)b );
}

int  main(){
	
	int m, n, i, j, p;
	
	int d[100], c[100];
	int cont[100][100];
	
	scanf("%d %d", &m, &n);
	
	int den[m+1], sum[n];
	
	for(i = 1; i <= m; i++){
		scanf("%d", &den[i]);
	}
	
	for(i = 0; i < n; i++){
		scanf("%d", &sum[i]);
	}
	
	for(i = 1; i <= m; i++){
		printf("%d ", den[i]);
	}
	printf("\n");
	int k = 0;
	qsort(den, m+1, sizeof(int), cmpfunc);
	
	while(k < n){
		
	//	int count[sum[k]+1][m+1];
		j = 0;

		 for(i=0; i <= sum[k]; i++)
        {
            for(j=0; j <= m; j++)
            {
                if(i == 0)
                {
                    cont[i][j] = 0;
                }
                
				else if(j==0)
                {
                    cont[i][j] = 1000;
                }
                
				else if(i < den[j])
                    cont[i][j] = cont[i][j-1];
                
				else if(i >= den[j])
                {
                    cont[i][j] = min(cont[i-den[j]][j]+1,cont[i][j-1]);
                }
            }
        }
        
	 	p = 1;
        
        for(i = 0; i <= m; i++)
        {
            d[i]=0;
            c[i]=0;
        }
        
        i = sum[k];
        j = m;
        
       while(i>0 && j>0)
    	{
            if(cont[i][j-1]==cont[i][j])
            {
                j--;
            }
            else
            {
                
                
                if(d[p-1]==den[j])
                {
                    p--;
                    c[p++]++;
                    i=i-den[j];
                }
                else
                {
                    d[p]=den[j];
                    c[p++]++;
                    i=i-den[j];
                }
            }
        }
        
        for(i = 1; i < p; i++)
        {
            if(i != p-1){
          
            	printf("%d:%d,",d[i], c[i]);
        	}
            else{
            	printf("%d:%d",d[i], c[i]);
        	}
        }
        printf("\n");
        k++;
   	}
		
	return 0;
}
