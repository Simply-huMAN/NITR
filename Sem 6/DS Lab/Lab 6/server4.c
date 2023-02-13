// Server side implementation of UDP client-server model
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SA struct sockaddr
   
#define PORT 6969
#define MAXLINE 1024

int main(){
    int sockfd,res,num1;
    char t[100];
    struct sockaddr_in servaddr, cliaddr;
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.125.206");
    servaddr.sin_port = 6969;
    int ser_len = sizeof(servaddr);
    int cli_len = sizeof(cliaddr);
    
    //if(sockfd = socket(AF_INET,SOCK_DGRAM,0)<0){
    //    printf("Socket creation failed!!");
        //exit(EXIT_FAILURE);
    //}
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    bind(sockfd,(SA *)&servaddr,ser_len);
    
    while(1){
        printf("____________________________\n");
        printf("Server is waiting...\n\n");
        recvfrom(sockfd,&num1,sizeof(num1),0,(SA *)&cliaddr,&cli_len);
        printf("Message received from client:\n%d\n",num1);
        num1=num1+100;
        char str[100];
        inet_ntop(AF_INET, &(cliaddr.sin_addr.s_addr), str, INET_ADDRSTRLEN);
        //unsigned int ipaddr = cliaddr.sin_addr.s_addr;
        printf("Client IP address: %s\n",str);
        sendto(sockfd,&num1,sizeof(num1),0,(SA *)&cliaddr,cli_len);
        printf("----------------------------\n\n");
    }
    close(sockfd);
    return 0;
}

