#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#define myport 3001

int main()
{
	int sockfd =  socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		printf("Socket creation error\n");
		exit(0);
	}
	struct sockaddr_in c_addr;
	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(myport);
	c_addr.sin_addr.s_addr = htons(INADDR_ANY);
	memset(c_addr.sin_zero, '\0', sizeof(c_addr.sin_zero));
	
	connect(sockfd, (struct sockaddr *)&c_addr, sizeof(c_addr));
	
	char str2[30];
	printf("Enter a string: ");
	gets(str2);
	send(sockfd, str2, sizeof(str2), 0);
	recv(sockfd, str2, sizeof(str2), 0);
	printf("The final string is: %s\n",str2);
}
