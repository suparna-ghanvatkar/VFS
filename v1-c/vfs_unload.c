#include<stdio.h>
#include "vfs.h"
extern struct vfs VFS;
int vfs_unload(){
	if(VFS.vfs_status==1 && VFS.vfs_fp!=NULL){
		fseek(VFS.vfs_fp,0,SEEK_SET);
		fwrite(&VFS.header,sizeof(struct vfs_header),1,VFS.vfs_fp);
		fclose(VFS.vfs_fp);
		VFS.vfs_fp=NULL;
		VFS.vfs_status=0;
		return 0;
	}
	else if(VFS.vfs_fp==NULL){
		fprintf(stderr,"Error unloading VFS as VFS-FILE is not loaded\n");
		return -2;
	}
	else{
		fprintf(stderr,"warning: vfs already unloaded");
		return -1;
	}
}
