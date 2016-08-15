#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	char target[1000], copy_target[1000];
	int i = 0,j;
	float un;
	int count1 = 0, count2 = 0;
	float score = 0.0;
	
	fgets(target, 1000, stdin);
	
	char *tar_tok[1000];
/*
	while(target[i] != '\0'){
		if(target[i] == '\n'){
			printf(" HI ");
		}
	
		printf("%c ", target[i]);
		i++;
	}
*/
	strcpy(copy_target, target);
	
	char* t_tok = strtok(target, " \n\0");
	
	i = 0;
	while(t_tok != NULL){
		tar_tok[i] = t_tok;
		t_tok = strtok(NULL, " \n\0");
		i++;
	}
	
	count1 = i;
	tar_tok[i] = NULL;
	i = 0;
//	printf("\n The tokens are: \n");
	
	while(tar_tok[i] != NULL){
		printf("%s ", tar_tok[i]);
		i++;
	}
	printf("\n");
	int n = 5;
	
	i = 0;
	
	while(i < 5){
	
		char line[1000];
		
		fgets(line, 1000, stdin);
		
		j = 0;
	/*	while(line[j] != '\0'){
			printf("%c ", line[j]);
			j++;
		}
	*/
		j = 0;
	/*	printf("\nThe target tokens are: ");
		while(tar_tok[j] != NULL) {
			printf("%s ", tar_tok[j]);
			j++;
		}
	*/	
		char *line_tok[1000];
		
		char *tok = strtok(line, " \n\0");
		j = 0;
		while(tok != NULL){
			line_tok[j] = tok;
			j++;
			tok = strtok(NULL, " \n\0");
		}
		
		count2 = j;
		line_tok[j] = NULL;
		j = 0;
	/*	
		printf("\nThe Line tokens are: ");
		while(line_tok[j] != NULL) {
			printf("%s ", line_tok[j]);
			j++;
		}
	*/	
		int k = 0;
		int flag, count = 0;
		j = 0;
		
		while(tar_tok[j] != NULL){
			while(line_tok[k] != NULL){
			  if(strcmp(tar_tok[j], line_tok[k]) == 0){
			  		count++;
			  }
			  k++;
			}
			j++;
			k = 0;
		}
		
		
		un = count1 + count2 - count;
		
		float c = count;
		
	//	printf("un: %f count: %f ", un, c);
		
		
		
		score = c/un;
		
		printf("%f:", score);
		
		j = 0;
		while(line_tok[j] != NULL){
			printf("%s ", line_tok[j]);
			j++;
		}
		
		printf("\n");
		i++;
	}
	
	return 0;
	
	
}
