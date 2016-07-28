#include<stdio.h>
#include "vfs.h"
int main(){
	int ch=1;
	char name_path[100],name[100];
	while(1){
		printf("\n1.Create VFS\n2.Load VFS\n3.Save\n4.Extract\n5.Unload\n6.Exit:");
		scanf("%d",&ch);;
		if(ch==1)
			vfs_create("vfs.vfs",3024);
		else if(ch==2)
			vfs_load();
		else if(ch==3){
			scanf("%s %s",name,name_path);
			vfs_save(name,name_path);
		}
		else if(ch==4){
			scanf("%s %s",name_path,name);
			vfs_extract(name_path,name);
		}
		else if(ch==5)
			vfs_unload();
		else			
			break;
	}
	return 0;
}
