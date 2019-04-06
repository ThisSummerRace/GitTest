#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#define FIFO_PATH "myfifofile"
int main(int argc,char *argv[])
{
    int fd;
    if(mkfifo(FIFO_PATH,0666) < 0 && errno != EEXIST)
	{
		perror("create fifo failed");
		return -1;
	}
	else
	{
		printf("create fifo sucess\n");
		fd = open(FIFO_PATH,O_CREAT|O_WRONLY,0666);
		if(fd > 0)
		{
		    while(1)
			{
				write(fd,cont_w,strlen(cont_w));
				printf("write success");
				sleep(2);
			}
			close(fd);
		}
		else
		{
			perror("open failed!");
		}
	}
}