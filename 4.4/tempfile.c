#include "apue.h"
#include <errno.h>


void make_temp(char *template);
int main(int argc,char** argv){

	char good_template[] = "/tmp/dirXXXXXX"; 
	
	printf("trying to create first temp file...\n");
	make_temp(good_template);
	
	exit(0);
}
void make_temp(char *template)
{
	int fd;
	struct stat sbuf;
	if ((fd = mkstemp(template)) < 0)
		perror("can’t create temp file");
		printf("temp name = %s\n", template);
		close(fd);
	if (stat(template, &sbuf) < 0) {
		if (errno == ENOENT)
			printf("file doesn’t exist\n");
		else
			perror("stat failed");
	} 
	else {
		printf("file exists\n");
		unlink(template);
	}
}
