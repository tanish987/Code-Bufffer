#include<vfs.h>

extern struct vfs glob_vfs;

int vfs_extract(char* saved_name, char* name_with_path){
	
	if(glob_vfs.vfs_status == VFS_CLOSE){
		printf("Sorry, VFS File is closed\n");
		return -1;
	}
	
	int num_files = glob_vfs.header.v_info.num_files;

	if(num_files == 0){
		printf("There are no files\n");
		return -1;
	}
	
	int count = 0;
	char* name;
	while(count != num_files){
		char* name = glob_vfs.header.files[count].fname; 
		if(strcmp(saved_name, name) == 0){
			break;
		}
		count++;
	}
	
	if(count == num_files){
		printf("%s doesn't exist", saved_name);
		return -1;
	}
	
	long offset = glob_vfs.header.files[count].f_offset;
	long size = glob_vfs.header.files[count].f_size;
	
	fseek(glob_vfs.fp, offset, SEEK_SET);
	
	FILE* fp = fopen("extracted_file.txt", "wb");
	
	count = 0;
	char ch;
	while(count != size){
		
		fread(&ch, sizeof(char), 1, glob_vfs.fp);
		fwrite(&ch, sizeof(char), 1, fp);
		count++;
		
	}
	
	fclose(fp);
	
	return 1;

}
