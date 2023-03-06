//Write a client (TCP) program that connects with the server program knowing IP address and port number.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SA struct sockaddr

int main(){
    int sid,num=100;
    char s[100]="Hello, Sample message from client!";
    struct sockaddr_in server_address;
    int ser_len;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 6969;
    ser_len = sizeof(server_address);
    printf("Sending string to server...\n\n");
    sleep(2);
    sid=socket(AF_INET,SOCK_STREAM,0);
    connect(sid,(SA *)&server_address,ser_len);
    write(sid,&s,sizeof(s));
    read(sid,&s,sizeof(s));
    printf("Message from server: \n%s\n",s);
    close(sid);
    return 0;
}
