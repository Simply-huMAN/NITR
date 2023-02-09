// Server side implementation of UDP client-server model
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SA struct sockaddr
   
#define PORT 6969
#define MAXLINE 1024

int main(){
	int sockfd,res,num;
	struct sockaddr_in servaddr, cliaddr;
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = 6969;
	int ser_len = sizeof(servaddr);
	int cli_len = sizeof(cliaddr);
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	bind(sockfd,(SA *)&servaddr,ser_len);
	int diff,prod,quo;
	while(1){
		printf("____________________________\n");
		printf("Ready to receive datagram :)\n");
		recvfrom(sockfd,&res,sizeof(res),0,(SA *)&cliaddr,&cli_len);
		recvfrom(sockfd,&num,sizeof(num),0,(SA *)&cliaddr,&cli_len);
		printf("Received num1: %d\tnum2: %d\n",res,num);
		diff = res-num;
		prod = res*num;
		//for(int i=0;i<3;i++) sans[i]=htonl(ans[i]);
		if(num==0) quo=-1;
		else quo = res/num;
		printf("\nDifference: %d\nProduct: %d\nQuotient: %d\n",diff,prod,quo);
		sendto(sockfd,&diff,4,0,(SA *)&cliaddr,cli_len);
		sendto(sockfd,&prod,4,0,(SA *)&cliaddr,cli_len);
		sendto(sockfd,&quo,4,0,(SA *)&cliaddr,cli_len);
		printf("----------------------------\n\n");
	}
	close(sockfd);
	return 0;
}
