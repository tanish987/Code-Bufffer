#include<stdio.h>
#include<limits.h>

int minSteps(int x, int move, int count);
int min(int,int);

int min(int a, int b){
    return a>b?b:a;
}

int main(){
    int x, move = 0, count = 0;
    
    scanf("%d", &x);
    
    count =  minSteps(x, move, count);
    
    printf("%d", count);
    
    return 0;
}

int minSteps(int x, int move, int count){
    
    if(abs(move) > abs(x)){
        return INT_MAX;
    }
    if(move == x){
        return count;
    }
    count++;
    
    return min(minSteps(x, move+count, count), minSteps(x, move-count, count));
}


