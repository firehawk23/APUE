#include <stdio.h>
#include <unistd.h>
#include "apue.h"
#include <fcntl.h>
#include <limits.h>
#include<time.h>


char name[21], telno[21], BUFF_SIZE[42];
int size, ind, flag;
time_t tm;

int printing_index(int fd,int fd1)
{
	printf("Enter the index number to print (except '0') : ");
	scanf("%d", &ind);

	if(ind > size)
		printf("Sorry !!! Index is out of range\n");

	else
	{
		lseek(fd, sizeof(size) + (ind-1) * 43, SEEK_SET);
		if( (read(fd, &flag, 1)) != 1)
			return -1;

		if( flag!= 1)
		{
			printf("\nThere are no entries in the specified index\n");
			exit(1);
		}

		read(fd, BUFF_SIZE, 42);
		strcpy(name, BUFF_SIZE);
		strcpy(telno, BUFF_SIZE+21);
		
		printf("\n-------------------------------------------------------------------------------------------------\n");
		printf("\nRequested entry is : ");
		printf("\nName : %s", name);
		printf("\nTelephone number : %s", telno);
		printf("\n-------------------------------------------------------------------------------------------------\n");
		
		FILE *fp;
		fp = fdopen(fd1, "a+");
  		if(fp == NULL)
 		 {
     		     printf("fdopen : error log file \n");
 		     exit(1);
 		 }

		time(&tm);
		fprintf(fp, "\nDate and Time : %s", ctime(&tm));
		fprintf(fp, "Action : Print\n");

	}

	return 0;
}


void writing_entries(int fd,int fd1)
{
	printf("\nEnter the entry that has to be added");
	printf("\nName : ");
	scanf("%s",name);
	printf("\nTelephone Number : ");
	scanf("%s",telno);
	printf("Enter the index(except '0') at which the entry to be added : ");
	scanf("%d",&ind);
	if(ind > size)
		printf("Index is out of range. Try again\n");
	else
	{	lseek(fd, sizeof(size) + (ind-1) * 43, SEEK_SET);
		flag = 1;
		write(fd,&flag,1);
		strcpy(BUFF_SIZE, name);
		strcpy(BUFF_SIZE + 21, telno);
		write(fd, BUFF_SIZE, 42);
		
		FILE *fp;
		fp = fdopen(fd1, "a+");
  		if(fp == NULL)
 		 {
     		     printf("fdopen : error log file \n");
 		     exit(1);
 		 }

		time(&tm);
		fprintf(fp, "\nDate and Time : %s", ctime(&tm));
		fprintf(fp, "Action : Write");
		fprintf(fp, "\nContent Updated :");
		fprintf(fp,"\n\tName : %s", name);
		fprintf(fp,"\n\tTelephone number : %s\n", telno);
		
	}
}



int main()
{

	char choice, filename[25],filename1[200];
	int fptr;
	int fptr1;
	char chk='y';

	printf("\nNow, enter the name of the telbook file : ");
	scanf("%s", filename);

	if( (fptr = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR )) == -1)
	{
		return 0;
		printf("\nSORRY the File could not be opened.\n");
	}

	printf("\nEnter the size of the telbook : ");
	scanf("%d",&size);

	printf("\nTelbook file has been created successfully.");
	
	printf("\nNow, enter the name of the logfile file : ");
	scanf("%s", filename1);

	if( (fptr1 = open(filename1, O_RDWR | O_CREAT |O_APPEND)) == -1)
	{
		return 0;
		printf("\nSORRY the LogFile could not be openedb or Created.\n");
	}
	
	printf("\nLogfile has been created successfully.");
	
	while(chk!='n')
	{
		printf("\nPlease choose the following options : ");
		printf("\n1. Write an entry at a specified index in the telbook (ENTER '1')");
		printf("\n2. print corresponding entry of the index no. entered by you (ENTER '2')");
		printf("\nEnter the option : ");
		getchar();
		scanf("%c", &choice);
		printf("\n");
		switch( choice )
		{
			case '1' :
					writing_entries(fptr,fptr1);
                              	break;
			
			case '2' : 	
					if(printing_index(fptr,fptr1) == -1)
					{
						printf("\nCouldn't read the data. Try again\n");
						exit(-1);
					}
					
					break;

			default  : 	
					printf("\n Invalid Choice\n");
					break;
		}
		printf("\nDo you want to continue (y/n): ");
		scanf("%c",&chk);
		printf("\n");	
		
	}

}