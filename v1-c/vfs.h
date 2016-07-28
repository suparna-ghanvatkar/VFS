#include<stdio.h>
#ifndef STRUCTS
#define STRUCTS
#define MAXLEN 30
#define MAX 20
struct vfs_file_info{
	char fname[MAXLEN];	
	long offset;
	int filesize;
};
struct vfs_info{
	char vfs_name[MAXLEN];
	int no_of_files;
	int vfs_size;
};
struct vfs_header{
	struct vfs_info vi;
	struct vfs_file_info fi[MAX];
};
struct vfs{
	struct vfs_header header;
	FILE *vfs_fp;
	int vfs_status;
};
#endif
//creates a vfs with file name vfs_file and maximum size allocated for vfs is size
int vfs_create(char *vfs_file,int size);

//loads the vfs into the memory for manipulation
int vfs_load();

//save the file with the specified name_path in the vfs with name fname
int vfs_save(char *fname,char *name_path);

//unload and commit the vfs 
int vfs_unload();

//extract the file with filename name from the vfs into the name_path specified
int vfs_extract(char *name,char *name_path);
