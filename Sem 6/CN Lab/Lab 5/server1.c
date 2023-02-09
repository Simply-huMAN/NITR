// Server side implementation of UDP client-server model
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SA struct sockaddr

int main(){
    int sockfd;
    char c;
    struct sockaddr_in servaddr, cliaddr;
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = 6969;
    int ser_len = sizeof(servaddr);
    int cli_len = sizeof(cliaddr);
    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    bind(sockfd,(SA *)&servaddr,ser_len);
    
    while(1){
        printf("----------------------------\n");
        printf("Ready to receive datagram :)\n");
        recvfrom(sockfd,&c,1,0,(SA *)&cliaddr,&cli_len);
        printf("Received %c\n",c);
        c='X';
        sendto(sockfd,&c,1,0,(SA *)&cliaddr,cli_len);
        printf("____________________________\n\n");
    }
    close(sockfd);
    return 0;
}
