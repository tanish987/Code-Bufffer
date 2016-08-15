//#include<stdio.h>
#include "vfs.h"
#include "vfs_create.c"
#include "vfs_load.c"
#include "vfs_save.c"
#include "vfs_extract.c"
#include "vfs_close.c"

void main(){
	
	int flag = 0;
	int choice;
	char vf_name[MAXLEN], fname[MAXLEN];
	
	while(!flag){
		printf("Enter 1 for creating a VFS file\n");
		printf("Enter 2 for loading a VFS file\n");
		printf("Enter 3 for saving a file into VFS\n");
		printf("Enter 4 for extracting a file from VFS\n");
		printf("Enter 5 for unloading a VFS file\n");
		printf("Enter 6 for exit\n");
		
		scanf("%d", &choice);
	//	printf("\n");
		
		switch(choice){
			case 1:
				scanf("%s", &vf_name);
				if(vfs_create(vf_name) == 1)
				{
					printf("succesful creation of vfs file\n");
				}
				break;
				
			case 2:
				scanf("%s", &vf_name);
				if(load_vfs(vf_name) == 1){
					printf("Successful loading of VFS file\n");
				}
				break;
				
			case 3:
				scanf("%s %s", fname, vf_name);
				if(vfs_save(fname, vf_name) == 1){
					printf("Successful saving of file in VFS\n");
				}
				break;
				
			case 4:
				scanf("%s %s", fname, vf_name);
				if(vfs_extract(fname, vf_name) == 1){
					printf("Successful extraction of VFS file\n");
				}
				break;
				
			case 5:
				if(vfs_close() == 1){
					printf("Successful closing of VFS file\n");
				}
				break;
				
			case 6:
				flag = 1;
				break;
				
		}
	}
	
	
	
}
