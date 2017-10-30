/**

Given a number line from -infinity to +infinity. 
You start at 0 and can go either to the left or to the right. The condition is that in i’th move, you take i steps.
a) Find if you can reach a given number x
b) Find the most optimal way to reach a given number x, if we can indeed reach it. 
For example, 3 can be reached om 2 steps, (0, 1) (1, 3) and 4 can be reached in 3 steps (0, -1), (-1, 1) (1, 4).

**/
#include<stdio.h>
#include<limits.h>
#include<conio.h>

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
    
    int r = min(minSteps(x, move+count, count), minSteps(x, move-count, count));
    return r;
}


