#include<stdio.h>
#include "vfs.h"
int main(){
	char ch[10];
	char *args[3];
	char name_path[100],name[100]="";
	int loaded=0;
	while(1){
		if(strcmp(name,"")==0 || loaded==0)
			printf("\n(VFS)");
		else
			printf("\n(%s)",name);
		scanf("%s",&ch);
		if(strcmp(ch,"create")==0 || strcmp(ch,"c")==0){
			args[0] = calloc(30, sizeof(char));
			args[1] = calloc(30, sizeof(char));
			scanf("%s %s",args[0],args[1]);
			strcpy(name,args[0]);
			vfs_create(args[0],atoi(args[1]));
		}
		else if(strcmp(ch,"mount")==0 || strcmp(ch,"m")==0){
			vfs_load();
			loaded=1;
		}
		else if(strcmp(ch,"save")==0 || strcmp(ch,"s")==0){
			scanf("%s %s",args[0],args[1]);
			vfs_save(args[0],args[1]);
		}
		else if(strcmp(ch,"extract")==0 || strcmp(ch,"e")==0){
			scanf("%s %s",args[0],args[1]);
			vfs_extract(args[0],args[1]);
		}
		else if(strcmp(ch,"umount")==0 || strcmp(ch,"u")==0){
			vfs_unload();
			loaded=0;
		}
		else if(strcmp(ch,"ls")==0 || strcmp(ch,"l")==0){
			vfs_ls();
		}
		else if(strcmp(ch,"quit")==0 || strcmp(ch,"q")==0){			
			break;
		}
		else{
			printf("Help:\nCommands and usage:\n1.create(c) name_of_vfs size_in_bytes\n");
			printf("2.mount(m)\n3.save(s) vfs_target_filename source_file_namepath\n");
			printf("4.extract(e) vfs_target_filename dest_file_namepath\n5.umount(u)\n");
			printf("6.ls(l)\n7.quit(q)\n");
		}
	}
	return 0;
}
