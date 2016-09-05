#include<stdio.h>
#include "vfs.h"
extern struct vfs VFS;
int struct_comp(const void* a,const void* b){
	return strcmp((char*)(((struct vfs_file_info*)a)->fname),(char*)(((struct vfs_file_info*)b)->fname));
}
int vfs_load(){
	int i;
	if(VFS.vfs_status==0 && VFS.header.vi.vfs_name!="\0"){
		VFS.vfs_fp=fopen(VFS.header.vi.vfs_name,"r+");
		VFS.vfs_status=1;
		fread(&VFS.header,sizeof(struct vfs_header),1,VFS.vfs_fp);
		qsort(&VFS.header.fi,VFS.header.vi.no_of_files,sizeof(struct vfs_file_info),struct_comp);	
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
