//Write a server (TCP) program that opens a listening socket and waits to server client. 
//It also consists of 3 modules of three topology creation (tree, ring, star).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SA struct sockaddr

int main(){
    int sockfd,sessid,num=0;
    char s[100];
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = 6969;
    int ser_len = sizeof(servaddr);
    int cli_len = sizeof(cliaddr);
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    bind(sockfd,(SA *)&servaddr,ser_len);
    listen(sockfd,10);
    while(1){
    	printf("____________________________\n");
        printf("Server is waiting....\n");
        sessid = accept(sockfd,(SA *)&cliaddr,&cli_len);
        read(sessid,&s,sizeof(s));
        printf("Message received from client: \n%s\n",s);
        num=num*10;
        printf("\nSending response...\n");
        char t[100] = "Your message is received by server!";
        write(sessid,&t,sizeof(t));
        printf("____________________________\n\n");
    }
    close(sockfd);
    return 0;
}
