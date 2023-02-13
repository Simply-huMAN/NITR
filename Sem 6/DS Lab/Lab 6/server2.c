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
    int sockfd,res,num;
    char t[100];
    //string t;
    //const char hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
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
        recvfrom(sockfd,&t,sizeof(t),0,(SA *)&cliaddr,&cli_len);
        printf("String received from client:\n%s\n",t);
        char te[100] = "This is a acknowledgement message from server";
        sendto(sockfd,&te,sizeof(te),0,(SA *)&cliaddr,cli_len);
        printf("----------------------------\n\n");
    }
    close(sockfd);
    return 0;
}

