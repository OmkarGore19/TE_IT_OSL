/* Assignment No. 7A
Name: Omkar Arun Gore
Roll No: 35024
Batch:B
Title: Inter process communication in Linux using FIFOS.
Problem Statement: Inter process communication in Linux using following.
A. FIFOS: Full duplex communication between two independent processes. First process accepts sentences and writes on one pipe to be read by second process and second process counts number of characters, number of words and number of lines in accepted sentences, writes this output in a text file and writes the contents of the file on second pipe to be read by first process and displays onstandard output.
*/


#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	int fd,fd1;
	char * myfifo = "myfifo";
	char * myfifo1 = "myfifo1";
	char buf[1024];
	
	mkfifo(myfifo,0666);
	mkfifo(myfifo1,0777);

	fd=open(myfifo,O_WRONLY);

	write(fd,"Hello All.. \nWelcome... \nto PES MCOE \nPune. \nMaharashtra \nIndia.",sizeof("Hello All.. \nWelcome... \nto PES MCOE \nPune. \nMaharashtra \nIndia."));

	close(fd);

	unlink(myfifo);

	fd1=open(myfifo1,O_RDONLY);
	read(fd1,buf,sizeof(buf));
	printf("%s", buf);
	unlink(myfifo1);
	close(fd1);
	return 0;
}

