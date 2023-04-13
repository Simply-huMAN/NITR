//TCP Client program
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int sid,num1,num2;
	struct sockaddr_in server_address;
	int server_addlen;

	server_address.sin_family=AF_INET;
	char ipAddr[15];
	printf("Enter the server IP address: ");
	gets(ipAddr);
	
	server_address.sin_addr.s_addr=inet_addr(ipAddr);
	
	server_address.sin_port=9876;
	
	server_addlen=sizeof(server_address);
	
	sid=socket(AF_INET,SOCK_STREAM,0);
	
	connect(sid,(struct sockaddr *)&server_address,server_addlen);
	printf("Connected Successfully\nEnter two numbers: ");
	scanf("%d %d",&num1,&num2);
	write(sid,&num1,4);
	write(sid,&num2,4);
	read(sid,&num1,1);
	
	printf("\nMessage received from server\nAns: %d\n",num1);
	close(sid);
	return(0);
}
