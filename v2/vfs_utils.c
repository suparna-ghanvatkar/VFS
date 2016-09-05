#include<stdio.h>
#include<sys/stat.h>
#include "vfs.h"
extern struct vfs VFS;
int vfs_save(char *fname,char *name_path){
	struct stat buffer1,buffer2;
	char c;
	if(VFS.vfs_status==0){
		fprintf(stderr,"VFS not loaded\n");
		return -1;
	}
	FILE *source=fopen(name_path,"r");
	if(source==NULL){
		fprintf(stderr,"Unable to open files specified\n");
		return -2;
	}
	stat(VFS.header.vi.vfs_name,&buffer1);
	stat(name_path,&buffer2);
	if(VFS.header.vi.vfs_size<(buffer1.st_size+buffer2.st_size)){
		fprintf(stderr,"VFS size small to load file");
		return -3;
	}
	fseek(VFS.vfs_fp,0,SEEK_END);
	VFS.header.fi[VFS.header.vi.no_of_files].offset=ftell(VFS.vfs_fp);
	VFS.header.fi[VFS.header.vi.no_of_files].filesize=buffer2.st_size;
	strcpy(VFS.header.fi[VFS.header.vi.no_of_files].fname,fname);
	VFS.header.vi.no_of_files++;
	while(!feof(source)){
		fread(&c,sizeof(char),1,source);
		fwrite(&c,sizeof(char),1,VFS.vfs_fp);
	}
	fclose(source);
	qsort(&VFS.header.fi,VFS.header.vi.no_of_files,sizeof(struct vfs_file_info),struct_comp);
	return 0;
	
}

int vfs_extract(char *name,char *name_path){
	long offset;
	int index=-1,i,size;
	char c;
	struct vfs_file_info temp,*item;
	strcpy(temp.fname,name);
	item=bsearch (&temp, VFS.header.fi, VFS.header.vi.no_of_files, sizeof (struct vfs_file_info), struct_comp);
	if(item==NULL){
		fprintf(stderr,"File not found\n");
		return -1;
	}
	printf("found:%s\n",item->fname);
	offset=item->offset;
	size=item->filesize;
	FILE *dest=fopen(name_path,"w");
	if(dest==NULL){
		fprintf(stderr,"Unable to open files specified\n");
		return -2;
	}
	fseek(VFS.vfs_fp,offset,SEEK_SET);
	i=0;
	while(i<size){
		fread(&c,sizeof(char),1,VFS.vfs_fp);
		//printf("%d",c);
		fwrite(&c,sizeof(char),1,dest);
		i++;
	}
	fclose(dest);
}

void vfs_ls(){
	int i;
	printf("FILENAME\tSIZE\n");
	for(i=0;i<VFS.header.vi.no_of_files;i++){
		printf("%s\t%dB\n",VFS.header.fi[i].fname,VFS.header.fi[i].filesize);
	}
}
