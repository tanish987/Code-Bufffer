#include "vfs.h"

struct vfs glob_vfs;

int vfs_create(char* name_with_path){

//	char* name = strcat(name_with_path, ".txt");
	
	
	FILE* fp = fopen(name_with_path, "wb");
	
	if(fp == NULL){
		printf("Error occured while VFS creation\n");
		return CREATE_ERROR;
	}
	
	struct vfs_info v_info;
	
	strcpy(v_info.vfs_name, name_with_path);
	v_info.num_files = 0;
	 v_info.size = 0;
	
	struct vfs_header_info header;
	header.v_info = v_info;
	
//	printf("vfs name: %s\n", )
	fwrite(&header, sizeof(struct vfs_header_info), 1, fp);
	
	glob_vfs.header = header;
//	glob_vfs.fp = NULL;
	glob_vfs.vfs_status = VFS_CLOSE;
	
	fclose(fp);	
	
	return 1;
}
