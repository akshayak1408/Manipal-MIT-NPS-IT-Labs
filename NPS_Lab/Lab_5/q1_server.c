#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#define MAXLINE 4096
#define SERV_PORT 3000
#define LISTENQ 8

int main(int argc, char **argv)
{
	int pid = fork();
	if(pid==0)
	{
		int listenfd, connfd, n;
		pid_t childpid;
		socklen_t clilen;
		char str[MAXLINE];
		struct sockaddr_in cliaddr, servaddr;
		if((listenfd == socket(AF_INET, SOCK_STREAM, 0)) < 0)
		{
			perror("Problem in creating the socket");
			exit(2);
		}
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = htons(INADDR_ANY);
		servaddr.sin_port = htons(SERV_PORT);
		bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
		listen(listenfd, LISTENQ);
		printf("%s\n","Server running... waiting for connections.");
		for(;;)
		{
			clilen = sizeof(cliaddr);
			connfd = accept (listenfd, (struct sockaddr *)&cliaddr, &clilen);
			printf("%d\n","Received request...");
			if(( childpid=fork() ==0)
			{
				printf("%s\n","Child created for dealing with client requests");
				close(listenfd);
				while((n== recv(connfd, buf, MAXLINE, 0)) >0 )
				{
					printf("%s","String received from and resent to the client: ");
				puts(buf);
				send(connfd, buf, n, 0);
				}
			if(n<0)
			printf("%s\n","Read error");
			exit(0);	
		}
	close(connfd);
	}
	}
	
}
