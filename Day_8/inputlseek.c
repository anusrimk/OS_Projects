#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int sz, seek_pos;
	char buf[100];
	
	int fd = open("lseek1.txt",O_RDWR);

	if(fd<0)
	{
		perror("Error occurred during open");
		exit(1);
	}
	
	seek_pos = lseek(fd,0,SEEK_SET);
	printf("\n Initial offset position: (%d)\n", seek_pos);
	
	seek_pos = lseek(fd,2,SEEK_SET);
        printf("\n Initial offset position: (%d)\n", seek_pos);

	seek_pos = lseek(fd,6,SEEK_SET);
        printf("\n Initial offset position: (%d)\n", seek_pos);

	sz = read(fd,buf,10);
	
	printf("\nRead bytes from file after lseek is = (%d)\n",sz);
	buf[sz] = '\0';
	printf("Read bytes are as follows: \n%s\n", buf);
	
	int seek_end = lseek(fd,0,SEEK_END);
	int seek_pos1 = lseek(fd,sz,SEEK_SET);
	char buf1[100];
	int len = (seek_end + seek_pos1) + 1;

	sz = read(fd,buf1,len);
	
	printf("\nRead bytes from file after lseek is = (%d)\n",sz);
        buf1[sz] = '\0';
        printf("Read bytes are as follows: \n%s\n", buf1);


	seek_pos = lseek(fd,0,SEEK_END);
	printf("\nOffeset position after (SEEK_END + 0): (%d)\n",seek_pos);
	
	strcpy(buf,"New string appended after seek end\n");

	sz = write(fd,buf,strlen(buf));
	
	close(fd);
}	
