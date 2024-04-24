#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#define MAXLINE 4096
#define SERV_PORT 3000
#define SERV_PORT2 3001
#define LISTENQ 8

int main()
{
	int pid = fork();
	if(pid == 0)
	{
		int listenfd, connfd, n;
		pid_t childid;
		socklen_t clilen;
		char str[MAXLINE];
		struct sockaddr_in cliaddr, servaddr;
		listenfd = socket(AF_INET, SOCK_STREAM, 0);
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = htons(INADDR_ANY);
		servaddr.sin_port = htons(SERV_PORT);
		bind( listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
		listen(listenfd, LISTENQ);
		printf("%s\n","Server running... waiting for connections.");
	for(;;)
	{
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
		printf("%s\n","Received request...");
		while((n = recv(connfd, str, MAXLINE,0)) > 0)
		{
			/*printf("%s","String received from and resent to the client: ");
			puts(str);*/
			str[3]="G";
			str[2]="D";
			send(connfd, str, n, 0);
		} 
		if(n<0)
		{
			perror("Read error");
			exit(1);
		}
		close(connfd);
	} 
	close(listenfd);
	}
	else
	{
		int listenfd, connfd, n;
		pid_t childid;
		socklen_t clilen;
		char str2[MAXLINE];
		struct sockaddr_in cliaddr, servaddr;
		listenfd = socket(AF_INET, SOCK_STREAM, 0);
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = htons(INADDR_ANY);
		servaddr.sin_port = htons(SERV_PORT2);
		bind( listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
		listen(listenfd, LISTENQ);
		printf("%s\n","Server running... waiting for connections.");
	for(;;)
	{
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
		printf("%s\n","Received request...");
		while((n = recv(connfd, str2, MAXLINE,0)) > 0)
		{
			/*printf("%s","String received from and resent to the client: ");
			puts(buf);*/
			str2[3]="G";
			str2[2]="D";
			send(connfd, str2, n, 0);
		} 
		if(n<0)
		{
			perror("Read error");
			exit(1);
		}
		close(connfd);
	} 
	close(listenfd);
	}
}
