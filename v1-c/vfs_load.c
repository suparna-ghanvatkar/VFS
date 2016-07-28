#include<stdio.h>
#include "vfs.h"
extern struct vfs VFS;
int vfs_load(){
	if(VFS.vfs_status==0 && VFS.header.vi.vfs_name!="\0"){
		VFS.vfs_fp=fopen(VFS.header.vi.vfs_name,"r+");
		VFS.vfs_status=1;
		fread(&VFS.header,sizeof(struct vfs_header),1,VFS.vfs_fp);
		return 0;
	}
	else if(VFS.header.vi.vfs_name=="\0"){
		fprintf(stderr,"Error loading VFS as VFS-FILE is undefined\n");
		return -2;
	}
	else{
		fprintf(stderr,"warning: vfs already loaded");
		return -1;
	}
}
