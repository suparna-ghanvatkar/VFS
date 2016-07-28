#include<stdio.h>
#include<string.h>
#include "vfs.h"
/*#define MAXLEN 30
#define MAX 20
struct vfs_file_info{
	char fname[MAXLEN];	
	int offset;
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
}*/
struct vfs VFS;

int vfs_create(char *vfs_file,int size){
	FILE *fp=fopen(vfs_file,"w");
	VFS.header.vi.vfs_size=size;//max size
	VFS.header.vi.no_of_files=0;
	strcpy(VFS.header.vi.vfs_name,vfs_file);
	if(fp==NULL){
		fprintf(stderr,"Error: invalid file name\n");
		return -1;
	}
	fwrite(&VFS.header,sizeof(struct vfs_header),1,fp);
	printf("%s",VFS.header.vi.vfs_name);
	VFS.vfs_status=0;
	fclose(fp);
	VFS.vfs_fp=NULL;
	return 0;
}
