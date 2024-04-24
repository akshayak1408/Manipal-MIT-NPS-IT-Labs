#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#define myport 1543

struct student
	{
		int reg_no;
		char name[30];
		char sub_code[30];
		char res_add[50];
	};
	
int main()
{
	int n;
	printf("\nEnter the number of students: ");
	scanf("%d",&n);
	struct student s[n];
	printf("\nEnter the registration number, name,subject code and residental address: \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i].reg_no);
		scanf("%s",s[i].name);
		scanf("%s",s[i].sub_code);
		scanf("%s",s[i].res_add);
	}
	
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server_addr, c_addr;
	server_addr.sin_port = htons(myport);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(&(server_addr.sin_zero), '\0', sizeof(server_addr.sin_zero));
	
	bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	int size = sizeof(struct sockaddr);
	printf("Waiting to receive\n");
	
	int choice,reg,pid2;
	char nm[30],sbc[30],nm2[30],r_add[50];
	
	sendto(sockfd, &n, sizeof(n), 0,(struct sockaddr*)&c_addr, size);
	sendto(sockfd, s, sizeof(s),0, (struct sockaddr*)&c_addr, size); 
	while(1)
	{
		recvfrom(sockfd, &choice, sizeof(choice),0, (struct sockaddr*)&c_addr, &size);
		switch(choice)
		{
			case 1:
			{
				recvfrom(sockfd, &reg, sizeof(reg), 0,(struct sockaddr*)&c_addr, &size);
				int pid = fork();
				if(pid==0)
				{
					for(int i=0;i<n;i++)
					{
						if(s[i].reg_no==reg)
						{
							nm2 = s[i].name;
							r_add = s[i].res_add;
							
							sendto(sockfd, nm2, sizeof(nm2),0, (struct sockaddr*)&c_addr, size):
							sendto(sockfd, r_add, sizeof(r_add),0, (struct sockaddr*)&a_addr,size);
						}
					}
					pid2 = getpid();
					sendto(sockfd, &pid2, sizeof(pid2), 0,(struct sockaddr*)&c_addr, size);
				}
				break;
			}
			case 2:
			{
				recvfrom(sockfd, nm, sizeof(nm),0, (struct sockaddr*)&c_addr, &size);
				puts(nm);
				break;
			}
			case 4:
			{
				close(sockfd);
				exit(0);
			}
		}
	}
}
	/*printf("\nYour entered details are: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d %s %s\n",s[i].reg_no, s[i].name, s[i].sub_code);
	}
	printf("\nEnter the registration number of student to delete the data of: ");
	scanf("%d",&reg);
	for(int i=0;i<n;i++)
	{
		if(s[i].reg_no == reg)
		{
			pos=i;
			break;
		}
	}
	for(int i=pos;i<n-1;i++)
	{
		s[i]=s[i+1];
	}
	printf("\nThe details after deletion are: \n");
	for(int i=0;i<n-1;i++)
	{
		printf("%d %s %s\n",s[i].reg_no, s[i].name, s[i].sub_code);
	}
	printf("\nEnter registration number of student to update info of: ");
	scanf("%d",&reg2);
	for(int i=0;i<n-1;i++)
	{
		if(s[i].reg_no == reg2)
		{
			scanf("%s",s[i].name);
			scanf("%s",s[i].sub_code);
		}
	}
	printf("\nThe updated details are: \n");
	for(int i=0;i<n-1;i++)
	{
		printf("%d %s %s\n",s[i].reg_no, s[i].name, s[i].sub_code);
	}*/	

