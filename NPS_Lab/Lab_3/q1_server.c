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
	int size;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in server_addr, c_addr;
	server_addr.sin_port = htons(myport);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));
	
	bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr));
	size=sizeof(struct sockaddr);
	listen(sockfd, 10);
	printf("The server is ready for listening!\n");
	
	int afd = accept(sockfd, (struct sockaddr*) &c_addr, &size);
	
	int pid;
	char str[20],msg[20];
	pid = fork();
	if(pid==0)
	{
		recv(afd, str, sizeof(str), 0);
		//printf("\n%s",str);
		printf("The child process PID %d and PPID %d",getpid(), getppid());
		printf("\n");
		puts(str);
	}
	else
	{
		//scanf("%s",&msg);
		gets(msg);
		send(afd, msg, sizeof(msg), 0);
		printf("The parent process PID %d and PPID %d",getpid(), getppid());
		if(msg=="BYE")
		{
			kill(getpid());
			close(sockfd);
		}
	}
	
}
