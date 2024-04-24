#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#define myport 1234

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		printf("Socket creation error!");
		exit(0);
	}
	struct sockaddr_in c_addr;
	c_addr.sin_port = htons(myport);
	c_addr.sin_family = AF_INET;
	c_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(c_addr.sin_zero, '\0', sizeof(c_addr.sin_zero));
	
	int size = sizeof(struct sockaddr);
	connect(sockfd, (struct sockaddr*) &c_addr, sizeof(c_addr));
	
	int pid;
	pid=fork();
	char str[20],msg[20];
	if(pid==0)
	{
		printf("Send message:\n");
		//scanf("%s",&str);
		gets(str);
		printf("The child process PID %d and PPID %d",getpid(), getppid());
		printf("\n");
		send(sockfd, str, sizeof(str), 0);
	}
	else
	{
		recv(sockfd, msg, sizeof(msg), 0);
		puts(msg);
		printf("The parent process PID %d and PPID %d",getpid(), getppid());
		if(msg=="BYE")
		{
			kill(getpid());
			close(sockfd);
		}
	}
}
