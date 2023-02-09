// Client side implementation of UDP client-server model
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SA struct sockaddr

int main(){
	int sid,num1,num2,res;
	printf("Enter num1: ");
	scanf("%d",&num1);
	printf("Enter num2: ");
	scanf("%d",&num2);
	struct sockaddr_in server_address;
	int ser_len;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = 6969;
	ser_len = sizeof(server_address);
	printf("Seeking a signal from server\n\n");
	sid=socket(AF_INET,SOCK_DGRAM,0);
	sendto(sid,&num1,sizeof(num1),0,(SA *)&server_address,ser_len);
	sendto(sid,&num2,sizeof(num2),0,(SA *)&server_address,ser_len);
	recvfrom(sid,&res,sizeof(res),0,(SA *)&server_address,&ser_len);
	printf("Sum received from server: %d\n",res);
	close(sid);
	return 0;
}
