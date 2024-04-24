#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#define myport 1234
int main()
{
	//create assign  listen accept operate reply
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{	printf("socket creation error");
		exit(0);
	}
	struct sockaddr_in c_addr;
	c_addr.sin_port = htons(myport);
	c_addr.sin_family = AF_INET;
	c_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(c_addr.sin_zero, '\0', sizeof(c_addr.sin_zero));
	
	int size = sizeof(struct sockaddr);
	connect(sockfd, (struct sockaddr*) &c_addr, sizeof(c_addr));
	
	char filename[30],str[30];
	printf("Enter the filename: ");
	gets(filename);
	send(sockfd, filename, sizeof(filename),0);
	
	while(1)
	{
		printf("\n\n1. Search: ");
		printf("\n2. Replace: ");
		printf("\n3. Reorder: ");
		printf("\n4.Exit ");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the string is search for: ");
				gets(str);
				send(sockfd, str, sizeof(str), 0);
				send(sockfd, choice, sizeof(choice), 0);
				
				
				break;
				
		}
		
	}
}	
	
	
	
	
	/*int buffer[10]={3,2,5,1,6,7,5,3,9,10};
	int x=4014;
	send(sockfd, &x, 4 ,0);
	send(sockfd, buffer, 40 ,0);
	close(sockfd);
	int n,arr[20];
	
	while(1)
	{
		printf("\n\n1. Search: ");
		printf("\n2. Replace: ");
		printf("\n3. Reorder: ");
		printf("\n4.Exit ");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	
					
					break;
		case 2://des ord
				printf("\nEnter the no of elements in array:");
					scanf("%d", &sz);
					printf("\nEnter the elements in array:");
					for(int i=0 ; i<sz ; i++)
						scanf("%d", &buffer[i]);
					send(sockfd, buffer, sizeof(buffer), 0);
					send(sockfd, &sz, sizeof(sz), 0);
					send(sockfd, &choice, sizeof(choice), 0);
					recv(sockfd, buffer, sizeof(buffer),0);
					printf("\nThe array in descending order is \n");
					for(int i=0 ; i<sz ; i++)
						printf("%d ", buffer[i]);
					break;					
		case 3://split
					printf("\nEnter the no of elements in array:");
					scanf("%d", &sz);
					printf("\nEnter the elements in array:");
					for(int i=0 ; i<sz ; i++)
						scanf("%d", &buffer[i]);
					send(sockfd, buffer, 40, 0);
					send(sockfd, &sz, 4, 0);
					send(sockfd, &choice, 4, 0);
					
					recv(sockfd, odd, 40,0);
					recv(sockfd, &b, 4, 0);
					recv(sockfd, even, 40, 0);
					recv(sockfd, &a, 4, 0);
					printf("\nThe odd elements in the array \n");
					for(int i=0 ; i<b ; i++)
						printf("%d ", odd[i]);
					printf("\nThe odd elements in the array \n");
					for(int i=0 ; i<a ; i++)
						printf("%d ", even[i]);
					break;
					
		case 4://search
					printf("\nEnter the no of elements in array:");
					scanf("%d", &sz);
					printf("\nEnter the elements in array:");
					for(int i=0;i<sz;i++)
						scanf("%d", &buffer[i]);
					printf("\nEnter the element to search for: ");
					scanf("%d", &ele);
					send(sockfd, buffer, sizeof(buffer), 0);
					send(sockfd, &sz, sizeof(sz), 0);
					send(sockfd, &ele, sizeof(ele), 0);
					send(sockfd, &choice, sizeof(choice), 0);
					
					recv(sockfd, &flag, sizeof(flag), 0);
					recv(sockfd, &pos, sizeof(pos) , 0);
					if(flag==1)
					printf("\nThe element is present in position %d",pos+1);
					else
					printf("\nThe given element is not present in the array!");
					break;
					
		case 5://exit
					send(sockfd, buffer, 40, 0);
					send(sockfd, &sz, 4, 0);
					send(sockfd, &choice, 4, 0);
					close(sockfd);
					exit(0);
					
		} 
	}
	send(sockfd, buffer, 40, 0);
					send(sockfd, &sz, 4, 0);
					send(sockfd, &choice, 4, 0);
					close(sockfd);
					exit(0);
}*/

