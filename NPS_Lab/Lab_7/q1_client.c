#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#define myport 1564

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (sockfd == -1)
	{
		printf("Socket creation error!");
		exit(0);
	}
	
	struct sockaddr_in c_addr;
	c_addr.sin_port = htons(myport);
	c_addr.sin_family = AF_INET;
	c_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(c_addr.sin_zero,'\0', sizeof(c_addr.sin_zero));
	
	int size = sizeof(struct sockaddr);
	connect(sockfd, (struct sockaddr*)&c_addr, sizeof(c_addr));
	
	char usr[20], pswrd[20, res[20];
	int choice;
	printf("Enter the username: ");
	scanf("%s",usr);
	printf("Enter the password: ");
	scanf("%s",pswrd);
	send(sockfd, usr, sizeof(usr), 0);
	send(sockfd, pswrd, sizeof(pswrd), 0);
	
	recv(sockfd, res, sizeof(res), 0);
	printf("%s",res);
	if(strcmp(res, "Success") == 0)
	{
		printf("1.Debit\n");
		printf("2.Credit\n");
		printf("3.View balance\n");
		printf("4.Exit\n");
		printf("Please enter your choice: ");
		scanf("%d",&choice);
		send(sockfd, &choice, sizeof(choice), 0);
		switch(choice)
		{
			case 1:
			{
				
			}
		}
		
	}
	
	
		
}
