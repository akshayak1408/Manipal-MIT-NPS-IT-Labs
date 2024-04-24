#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#define myport 1564
struct user
{
	char username[20];
	char password[20];
	int balance;
};
int main()
{
	struct user u[5];
	strcpy(u[0].username, "Akshaya");
	strcpy(u[1].username, "Ganesan");
	strcpy(u[2].username, "Abhaya");
	strcpy(u[3].username, "Lata");
	strcpy(u[4].username, "Swapnil");
	
	strcpy(u[0].password, "akshaya@123");
	strcpy(u[1].password, "ganesan@123");
	strcpy(u[2].password, "abhaya@123");
	strcpy(u[3].password, "lata@123");
	strcpy(u[4].password, "swapnil@123");
	
	int size;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_addr,c_addr;
	server_addr.sin_port = htons(myport);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));
	
	bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

	size = sizeof(struct sockaddr*);
	listen(sockfd, 10);
	printf("The server is ready for listening!\n");
	int afd = accept(sockfd, (struct sockaddr*)&c_addr, &size);
	
	char usr[20], pswrd[20],res[20];
	int flag=0;
	recv(afd, usr, sizeof(usr), 0);
	recv(afd, pswrd, sizeof(pswrd), 0);
	for(int i=0;i<5;i++)
	{
		if(strcmp(usr,u[i].username) == 0)
		{
			flag=1;
			if(strcmp(pswrd, u[i].password) == 0)
			{
				strcpy(res, "Success");
				break;
			}
			else
			{
				strcpy(res, "Incorrect password!");
				break;	
			}
		}
	}
	if(flag==0)
	{
		strcpy(res, "Incorrect username!");
	}
	send(afd, res, sizeof(res), 0);
	
	else
	{
		
	}
	
}
