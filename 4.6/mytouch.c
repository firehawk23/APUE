#include "apue.h"
#include<errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc,char* argv[]){
	int fd;
	struct timespec times[2];

	if(argc < 2){
		printf("give file name as well\n");
		exit(0);
	}

	if( (fd = open(argv[1], O_RDWR | S_IRWXU | S_IRWXG | S_IRWXO )) == -1)
	{
		return 0;
		printf("\nSORRY the File could not be opened.\n");
	}

	clock_gettime(CLOCK_REALTIME,&times[1]);
	clock_gettime(CLOCK_REALTIME,&times[0]);

	if (futimens(fd,times) < 0){ /* reset times */
		perror("futimens error");
	}
	close(fd);
	return 0;
}
