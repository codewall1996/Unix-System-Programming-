#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	struct stat buf;
	stat("test.txt",&buf);
	printf("File permissions(in octal) : %o\n",buf.st_mode );
	printf("ID of the device containing the file : %d\n",buf.st_dev );
	printf("Inode Number :  %d\n",buf.st_ino );
	printf("Number of hard links : %d\n",buf.st_nlink );
	printf("User ID : %d\n",buf.st_uid );
	printf("Size of the file : %d\n",buf.st_size);
	/*printf("%o\n",buf.st_mode );
	printf("%o\n",buf.st_mode );
	printf("%o\n",buf.st_mode );
 	*/
	return 0;
}
