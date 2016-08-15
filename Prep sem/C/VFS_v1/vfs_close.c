#include "vfs.h"

extern struct vfs glob_vfs;

int vfs_close(){
	
	if(glob_vfs.vfs_status == VFS_CLOSE){
		printf("VFS is closed already\n");
		return -1;
	}
	
	fseek(glob_vfs.fp, 0, SEEK_SET);
	
	fwrite(&glob_vfs.header, sizeof(struct vfs_header_info), 1, glob_vfs.fp);
	
	fclose(glob_vfs.fp);
	
	glob_vfs.fp = NULL;
	
	glob_vfs.vfs_status = VFS_CLOSE;
	
	return 1;
}
