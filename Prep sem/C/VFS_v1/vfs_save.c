#include "vfs.h"

extern struct vfs glob_vfs;

int vfs_save(char* save_name, char* name_with_path){
		
//	char* name = strcat(save_name, ".txt");
	FILE* fp = fopen(save_name, "rb+");
	
	if(glob_vfs.vfs_status == VFS_CLOSE ){
		printf("Sorry, VFS file is closed\n");
		return -1;
	}
	if(fp == NULL){
		printf("%s doesn't exist\n", save_name);
		return -1;
	}
	struct vfs_file_info finfo;
	
	fseek(fp, 0, SEEK_END);
	
	long size = ftell(fp);
	rewind(fp);
	printf("size: %d", size);
	
	fseek(glob_vfs.fp, 0, SEEK_END);
	
	long offset = ftell(glob_vfs.fp);
//	rewind(glob_vfs.fp);
	printf("HI");
	strcpy(finfo.fname, save_name);
	finfo.f_offset = offset;
	finfo.f_size = size;
	
	glob_vfs.header.files[glob_vfs.header.v_info.num_files] = finfo;
	glob_vfs.header.v_info.size += size;
	glob_vfs.header.v_info.num_files++;
	
	int count = 0;
	char ch;
	printf(" hasdcI ");
	
	while(count != size){
	//	printf(" t ");
		fread(&ch, sizeof(char), 1, fp);
	//	printf(" %c ", ch);
		fwrite(&ch, sizeof(char), 1, glob_vfs.fp);
		count++;
	}
	
	printf(" Helloo ");
	printf("count: %d\n", count);
	
	rewind(glob_vfs.fp);
	
	return 1;
		
}
