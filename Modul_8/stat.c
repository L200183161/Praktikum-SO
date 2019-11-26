#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc, char*argv[]){
	struct stat
	file; int n;
	if(argc != 2)
	{
		printf("usage ./a.out <filename>\n"); exit(-1);
	}
	if(( n= stat( argv[1], &file)) == -1)
	{
		perror(argv[1]);
		exit(-1);
	}
	printf("user id : %d\n", file.st_uid);
	printf("group id : %d\n", file.st_gid);
	printf("block size : %d\n", file.st_blksize);
	printf("block allocated : %d\n", file.st_blocks);
	printf("inode no.: %d\n", file.st_ino);
	printf("last accessed : %s", ctime(&(file.st_atime)));
	printf("last modified: %s", ctime(&(file.st_mtime)));
	printf("file size: %d bytes\n", file.st_size);
	printf("no. of links : %d\n", file.st_nlink);
	printf("permissions : ");
	printf( (S_ISDIR(file.st_mode))  ? "d" : "-");
	printf( (file.st_mode & S_IRUSR) ? "r" : "-");
	printf( (file.st_mode & S_IWUSR) ? "w" : "-");
	printf( (file.st_mode & S_IXUSR) ? "x" : "-");
	printf( (file.st_mode & S_IRGRP) ? "r" : "-");
	printf( (file.st_mode & S_IWGRP) ? "w" : "-");
	printf( (file.st_mode & S_IXGRP) ? "x" : "-");
	printf( (file.st_mode & S_IROTH) ? "r" : "-");
	printf( (file.st_mode & S_IWOTH) ? "w" : "-");
	printf( (file.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
	if(file.st_mode & S_IFREG)
		printf("file type : Regular\n");
	if(file.st_mode &S_IFDIR)
		printf("file type : Directory\n");
}
