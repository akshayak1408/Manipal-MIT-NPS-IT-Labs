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
		/*char dept[30];
		int sem;
		char sec;
		char course_reg[30][30];*/
	};
int main()
{
	
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in addr;
	addr.sin_port = htons(myport);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(addr.sin_zero, '\0', sizeof(addr.sin_zero));
	
	//Server will bind
	printf("Successful till here!");
	
	int size = sizeof(struct sockaddr);
	struct student s[30];
	int choice,reg,pid2;
	char nm[30],sbc[30],nm2[30],r_add[50];
	while(1)
	{
		printf("\n1.Registration Number");
		printf("\n2.Name of the Student");
		printf("\n3.Subject code");
		printf("\n4.Exit");
		printf("\nPlease enter choice: ");
		scanf("%d",&choice);
		sendto(sockfd, &choice, sizeof(choice), 0,(struct sockaddr *)&addr, size);
		switch(choice)
		{
			case 1:
			{
				scanf("%d", &reg);
				sendto(sockfd,&reg, sizeof(reg), 0,(struct sockaddr*)&addr, size);
				recvfrom(sockfd, nm2, sizeof(nm2), 0,(struct sockaddr*)&addr, &size);
				recvfrom(sockfd, r_add, sizeof(r_add),0, (struct sockaddr*)&addr, &size);
				recvfrom(sockfd, &pid2, sizeof(pid2), 0,(struct sockaddr*)&addr, &size);
				break;
			}
			case 2:
			{
				scanf("%s",nm);
				sendto(sockfd, nm, sizeof(nm),0, (struct sockaddr*)&addr, size);
				break;
			}
			case 3:
			{
				scanf("%s",sbc);
				sendto(sockfd, sbc, sizeof(sbc),0, (struct sockaddr*)&addr, size);
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
