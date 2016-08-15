#include<stdio.h>
#include<math.h>
int operation(int m, int n, char c);
int preeced(char op1, char op2);

struct stack_val{
	int top;
	int cap;
	int* arr;
};
struct stack_op{
	int top;
	int cap;
	char* arr;
};

typedef struct stack_op s_op;
typedef struct stack_val s_val;

s_op *m1(int cap){
	s_op* st = (s_op *)malloc(sizeof(s_op));
	st->cap = cap;
	st->top = -1;
	st->arr = (char*)malloc(cap*sizeof(char));
	return st;
}

s_val *m2(int cap){
	s_val* st = (s_val *)malloc(sizeof(s_val));
	st->cap = cap;
	st->top = -1;
	st->arr = (int*)malloc(cap*sizeof(int));
	return st;
}

void pushOp(s_op* s, char op){
	if(s->top == s->cap-1){
		printf("operator stack is full. Can't push");
		return;
	}
	else{
		s->arr[++s->top] = op;
	}
}

void pushVal(s_val* s, int val){
	if(s->top == s->cap-1){
		printf("operator stack is full. Can't push");
		return;
	}
	else{
		s->arr[++s->top] = val;
	}
}

char popOp(s_op* s){
	if(s->top == -1){
		printf("Underflows\n");
		return;
	}
	char item = s->arr[s->top--];
	return item;
}
int popVal(s_val* s){
	if(s->top == -1){
		printf("Underflows\n");
		return;
	}
	int item = s->arr[s->top--];
	return item;
}

int isEmptyOp(s_op* s){
	if(s->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}


int isEmptyVal(s_val* s){
	if(s->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

char peekOp(s_op* s){
	return s->arr[s->top];
}

int peekVal(s_val* s){
	return s->arr[s->top];
}


int main(){
	s_op* op = m1(30);
	s_val* val = m2(30);
	
	char str[1000];

	scanf("%s", str);

	int num[10];

	int m, n, i, j, k, result = 0, count;
//	int nop = 0;
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
	while(num[k] != 1000){
		i = 0;
		while(str[i] != '\0'){
			
			if(str[i] == '('){
				pushOp(op, str[i]);
			}
			
			else if(str[i] == ')'){
				while(peekOp(op) != '('){
					pushVal(val, operation(popVal(val), popVal(val), popOp(op)));
				}
				popOp(op);
			}
			
			else if(str[i] == '^' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
				while(!isEmptyOp(op) && preeced(peekOp(op), str[i])){
					pushVal(val, operation(popVal(val), popVal(val), popOp(op)));
				}
				pushOp(op, str[i]);
			}
			
			else if(str[i] >= 'a' && str[i] <= 'z'){
				pushVal(val, num[k]);
			}
			
			else if(str[i] >= '0' && str[i] <= '9'){
					j = i;
					while(str[j] >= '0' && str[j] <= '9'){
						j++;
					}
					i = j;
					j--;
					count = 0;
					n = 0;
					while(str[j] >= '0' && str[j] <= '9'){
						n += (str[j] - '0')*pow(10, count);
						count++;
						j--;
					}
					pushVal(val, n);
					continue;
			}
			i++;
			
		}
		while(!isEmptyOp(op)){
				pushVal(val, operation(popVal(val), popVal(val), popOp(op)));
		}
		result = popVal(val);
		printf("the result: %d\n", result);
		k++;
	}
	return 0;
}

int operation(int m, int n, char c){

	int result = 0;
	
	switch(c){
		case '+':
			result = m + n;
			break;
		
		case '-':
			result = m - n;
			break;
		
		case '*':
			result = m*n;
			break;
			
		case '/':
			result = m/n;
			break;
			
		case '^':
			result = pow(m, n);
			break;
	}
	printf("r: %d", result);
	return result;
	
}

int preeced(char op1, char op2){
	if(op1 == '(' || op1 == ')'){
		return 0;
	}
	if(op1 == '^'){
		return 1;
	}
	else if(op2 == '^'){
		return 0;
	}
	else if((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')){
		return 0;
	}
	else{
		return 1;
	}
}
