#define _BSD_SOURCE
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int loop(char *name){
	int dc=0,fc=0,nlinks;
	DIR *dir=opendir(name);
	struct dirent *entry=NULL;
	struct stat buf;
	while((entry=readdir(dir))!=NULL){
		if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") ==0 )
			continue;
		stat(entry->d_name,&buf);
		if (entry->d_type == 8){
			fc++;
			nlinks = buf.st_nlink;
		}
		else
		{
			printf("Directory encountered : %s\n",entry->d_name);
			nlinks = buf.st_nlink-2;
			dc++;
		}
	printf("inode no:%u length:%d  No. of links : %d type:%u name:%s\n",entry->d_ino,entry->d_reclen,nlinks,entry->d_type,entry->d_name);

	}
	printf("File Count : %d\nDirectory Count : %d\n",fc,dc );
	return 0;
}


void file_display(char *name){
	FILE *f;
    char c;
    f=fopen(name,"rt");

    while((c=fgetc(f))!=EOF){
        printf("%c",c);
    }

    fclose(f);
}

int main(int argc, char const *argv[]){
	struct stat buf_local;
	char *name = ".";
	if (argc > 1)
		name = argv[1];
	stat(name,&buf_local);
	if ((buf_local.st_mode & S_IFMT) == S_IFDIR)
		loop(name);
	else
		file_display(name);
	return 0;
}

