// Client side implementation of UDP client-server model
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SA struct sockaddr

void prime(int num){
	if(num) printf("prime number\n");
	else printf("not a prime number\n");
}

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
	printf("\n\nSeeking a signal from server\n");
	sid=socket(AF_INET,SOCK_DGRAM,0);
	sendto(sid,&num1,sizeof(num1),0,(SA *)&server_address,ser_len);
	sendto(sid,&num2,sizeof(num2),0,(SA *)&server_address,ser_len);
	int diff,prod,quo;
	recvfrom(sid,&diff,4,0,(SA *)&server_address,&ser_len);
	recvfrom(sid,&prod,4,0,(SA *)&server_address,&ser_len);
	recvfrom(sid,&quo,4,0,(SA *)&server_address,&ser_len);
	//for(int i=0;i<3;i++) rans[i]=ntohl(ans[i]);
	printf("Heard something from server\n");
	printf("\nDifference: %d\nProduct: %d\nQuotient: %d\n",diff,prod,quo);
	if(quo==-1) printf("Since num2 is 0, couldn't perform division\n");
	printf("-----Checking if a number is prime-----\n");
	printf("%d: ",num1);
	recvfrom(sid,&num1,4,0,(SA *)&server_address,&ser_len);
	prime(num1);
	printf("%d: ",num2);
	recvfrom(sid,&num2,4,0,(SA *)&server_address,&ser_len);
	prime(num2);
	close(sid);
	return 0;
}
