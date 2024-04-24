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
	//create assign bind listen accept operate reply
	int size;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);	//socket creation
	struct sockaddr_in	server_addr, c_addr;	
	
	//feeding values into the socket address structure
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(myport);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset( server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero) );
	
	bind( sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr) );
	
	//ready for listening
	listen(sockfd, 10);
	printf("The server is ready for listening.\n");
	size = sizeof(struct sockaddr);
	
	int afd = accept(sockfd, (struct sockaddr *) & c_addr, &size);
	char filename[30],str2[30],str[30];
	int i=0,flag=0;
	recv(afd, filename, sizeof(filename), 0);
	FILE *fp;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("\nFile cannot be opened!");	
	}
	else
	{
		puts(filename);
		printf("\nContent of this file are: \n");
		while(fgets(str2, 30, fp) !=NULL)
		{
			printf("%s", str2);
		}
	}
	fclose(fp);

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
				recv(afd, str, sizeof(buffer), 0);
				for(int i=0;str2[i]!='\0';i++)
				{
					for(int j=0,k=0; str[j]!='\0' && str2[k]!='\0';j++)
					{
						if(str[j]==str2[k])
						{
							j++;
						}
						else
						{
							j
						}	
					}
				}
				break;
				
		}
		
	}
}
	
	/*while(1)
	{
		printf("\n1.Search: ");
		printf("\n2.Replace: ");
		printf("\n3.Reorder: ");
		printf("\n4.Exit: ");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
	}
}	
	

	/*int choice, sz, temp, pos, ele, flag=0;
	int odd[10] = {0};
	int even[10] = {0};
	int a =0, b = 0;
	while(1)
	{
		recv(afd, buffer, sizeof(buffer), 0);
		recv(afd, &sz, sizeof(sz), 0);
		recv(afd, &choice, sizeof(choice), 0);
		switch(choice)
		{
			case 1:// have to sort asc
					for(int i=0 ; i<sz-1 ; i++)
					{
						for(int j=0 ; j<sz-1-i ; j++)
						{
							if(buffer[j]>buffer[j+1])
							{
								temp = buffer[j];
								buffer[j] = buffer[j+1];
								buffer[j+1] = temp;
							}
						}
					}
					send(afd, buffer, 40, 0);
					break;
					
			case 2:// hav to sort it in dsc order
					for(int i=0 ; i<sz-1 ; i++)
					{
						for(int j=0 ; j<sz-1-i ; j++)
						{
							if(buffer[j]<buffer[j+1])
							{
								temp = buffer[j];
								buffer[j] = buffer[j+1];
								buffer[j+1] = temp;
							}
						}
					}
					send(afd, buffer, 40, 0);
					break;
					
			case 3: // have to split the array into odd and even


					for(int i=0 ; i<sz ; i++)
					{
						if(buffer[i]%2==0)
							even[a++] = buffer[i];
						else
							odd[b++] = buffer[i];					
					}
					send(afd, odd, sizeof(odd), 0);
					send(afd , &b, sizeof(b) ,0);
					send(afd, even, sizeof(even), 0);
					send(afd, &a, sizeof(a), 0);

					break;
					
			case 4:	recv(afd, &ele, sizeof(ele), 0);
					for(int i=0 ; i<sz ; i++)
					{
						if(ele==buffer[i])
						{
							flag=1;
							pos=i+1;
							break;
						}
					}
					send(afd, &flag, sizeof(flag), 0);
					send(afd, &pos, sizeof(pos), 0);
					
					break;
					
			case 5:	close(sockfd);
					exit(0);
			
		} 
	}
}*/
