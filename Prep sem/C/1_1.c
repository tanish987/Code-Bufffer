#include<stdio.h>
#include<math.h>

void utility(char s[], int *y, int *m, int *n, int val, char ch);

void main(){
 
	char str[100];

	scanf("%s", str);

	int num[10];

	int m, n, i, j, k, result = 0, count;
	int nop = 0;
	i = 0;
	
	while(1)
	{
		scanf("%d", &num[i]);
		if(num[i] == 1000){
			break;
		}
		
		i++;
	}

	k = 0;
	i = 0;

	while(num[k] != 1000){
        i = m = n = 0;
		result = 0;
		nop = 0;
		while(str[i] != '\0'){
	
			switch(str[i]){
			
				case ' ':
					i++;
					break;
					
				
				case '^':
					nop++;
					if(result == 0 && nop == 1){
						utility(str, &i, &m, &n, num[k], 'x');
						result = pow(m, n);
						m = n = 0;
					}
				
					else{
						n = 0;
					//	printf("hi");
						if(str[i+1] == 'x'){
							n = num[k];
							i += 2;
						}
				
						else if(str[i+1] >= '0' && str[i+1] <= '9'){
							j = i+1;
							count = 0;
							
							while(str[j] >= '0' && str[j] <= '9'){
								j++;
								
							}
							i = j;
							j--;
							
							while(str[j] >= '0' && str[j] <= '9'){
								n += (str[j] - '0')*pow(10, count);
								count++;
								j--;
								
							}
						}
					//	printf("%d", result);
						result = pow(result, n);
					}
					break;
					
				case '+':
					nop++;
					if(result == 0 && nop == 1){
						utility(str, &i, &m, &n, num[k], 'x');
						result = m + n;
						m = n = 0;
					}
				
					else{
						n = 0;
						if(str[i+1] == 'x'){
							n = num[k];
							i += 2;
						}
				
						else if(str[i+1] >= '0' && str[i+1] <= '9'){
							j = i+1;
							count = 0;
							
							while(str[j] >= '0' && str[j] <= '9'){
								j++;
								
							}
							i = j;
							j--;
							
							while(str[j] >= '0' && str[j] <= '9'){
								n += (str[j] - '0')*pow(10, count);
								count++;
								j--;
								
							}
						
						}
				
						result += n;
				
					}
					break;
					
				case '-':
					nop++;
					if(result == 0 && nop == 1){
						utility(str, &i, &m, &n, num[k], 'x');
						result = m - n;
				//		printf("vz: %d", result);
						m = n = 0;
				
					}
				
					else{
						n = 0;
						if(str[i+1] == 'x'){
							n = num[k];
							i += 2;
						}
				
						else if(str[i+1] >= '0' && str[i+1] <= '9'){
							j = i+1;
							count = 0;
							
							while(str[j] >= '0' && str[j] <= '9'){
								j++;
								
							}
							i = j;
							j--;
							
							while(str[j] >= '0' && str[j] <= '9'){
								n += (str[j] - '0')*pow(10, count);
								count++;
								j--;
								
							}
						}
				
						result -= n;
						
					}
					break;
					
				case '*':
					nop++;
					if(result == 0 && nop == 1){
						utility(str, &i, &m, &n, num[k], 'x');
						result = m*n;
				
						m = n = 0;
				
					}
				
					else{
						n = 0;
						if(str[i+1] == 'x'){
							n = num[k];
							i += 2;
						}
				
						else if(str[i+1] >= '0' && str[i+1] <= '9'){
							j = i+1;
							count = 0;
							
							while(str[j] >= '0' && str[j] <= '9'){
								j++;
								
							}
							i = j;
							j--;
							
							while(str[j] >= '0' && str[j] <= '9'){
								n += (str[j] - '0')*pow(10, count);
								count++;
								j--;
								
							}
						}
				
						result *= n;
			
					}
					break;
					
				case '/':
					nop++;
					if(result == 0 && nop == 1){
						utility(str, &i, &m, &n, num[k], 'x');
						result /= n;
						m=n=0;
					}
				
					else{
						n = 0;
						if(str[i+1] == 'x'){
							n = num[k];
							i += 2;
						}
				
						else if(str[i+1] >= '0' && str[i+1] <= '9'){
							j = i+1;
							count = 0;
							
							while(str[j] >= '0' && str[j] <= '9'){
								j++;
								
							}
							i = j;
							j--;
							
							while(str[j] >= '0' && str[j] <= '9'){
								n += (str[j] - '0')*pow(10, count);
								count++;
								j--;
								
							}
						}
				
						result /= n;
					}
					break;
				
				default:
					i++;
			}// switch
		} // innner
		printf("result: %d\n", result);
		k++;
	}// outer

}

void utility(char s[], int *y, int *m, int *n, int val, char ch){

	int i = *y;
	int temp = *y;
	int j, count;
/*	
	if(s[i-1] == ' '){
		j = i-1;
		while(str[j] == ' '){
			j--;
		}
		i = ++j;
	}
*/
/*	int p = 0;
	printf("Str is:");
	while(s[p] != 0){
		printf("%c", s[p]);
		p++;
	}
*/
	if(s[i-1] == ch){
		*m = val;
//		printf("value of m:%d\n", *m);
	}
	else if(s[i-1] >= '0' && s[i-1] <= '9'){
		j = i-1;
		count = 0;
		while(s[j] >= '0' && s[j] <= '9'){
			*m += (s[j] - '0')*pow(10, count);
			count++;
			j--;
		}
//		printf("value of m:%d", *m);
	}
	
/*	i = temp;
	
	if(s[i+1] == ' '){
		j = i+1;
		while(str[j] == ' '){
			j++;
		}
		i = --j;
	}
*/	

//	printf("hsdfnks");
	if(s[i+1] == ch){
		*n = val;
//		printf("value of m:%d", *n);
		*y = *y + 2;
	//	printf("value of i:%d", *y);
	}

	else if(s[i+1] >= '0' && s[i+1] <= '9'){
		j = i+1;
		count = 0;
		while(s[j] >= '0' && s[j] <= '9'){
			*n += (s[j] - '0')*pow(10, count);
			count++;
			j++;
		}
	//	printf("value of m:%d", *n);
		*y = j;
//		printf("value of i:%d", *y);
	}
}
