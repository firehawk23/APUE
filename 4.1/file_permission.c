#include <stdio.h>
#include <unistd.h>
#include "apue.h"
#include <fcntl.h>

int main(void)
{ int fd;
char filename[25];
printf("\nNow, enter the name of the telbook file : ");
scanf("%s", filename);
if( (fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR )) == -1)
	{
		return 0;
		printf("\nSORRY the File could not be opened.\n");
	}

/* set absolute mode to "rwxrwxrwx" */
if (chmod(filename, S_IRWXU | S_IRWXG | S_IRWXO) < 0){
printf("chmod error for bar");
}
exit(0);
}