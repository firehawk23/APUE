#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include "apue.h"

int main(int argc, char *argv[])
{
if(argc != 2) {
       printf("Usage: %s number-of-rings\n",argv[0]);
       return 1;
   }
struct stat buf;
if (stat(argv[1], &buf) == 0)
    {
        printFileProperties(buf);
    }
if (stat(argv[1], &buf) < 0) {
    printf("stat error");
    
    }
return 0;
}


void printFileProperties(struct stat stats)
{
    struct tm dt;
    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        printf("read ");
    if (stats.st_mode & W_OK)
        printf("write ");
    if (stats.st_mode & X_OK)
        printf("execute");
    printf("\nFile size: %ld", stats.st_size);
    dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d\n", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

}