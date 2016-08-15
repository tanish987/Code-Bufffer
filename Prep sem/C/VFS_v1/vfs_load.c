#include "vfs.h"

extern struct vfs glob_vfs;

int load_vfs(char* name_with_path){
	
	if(glob_vfs.vfs_status == VFS_OPEN){
		printf("VFS file already loaded\n");
		return -1;
	}
	
	FILE* fp = fopen(name_with_path, "rb+");
		
	glob_vfs.fp = fp;
	
	fread(&glob_vfs.header, sizeof(struct vfs_header_info), 1, fp);
	
	fseek(fp, 0, SEEK_END);
	
	long size = ftell(fp);
	rewind(fp);
	
	glob_vfs.vfs_status = VFS_OPEN;
	glob_vfs.header.v_info.size = size;
	
	return 1;
}
