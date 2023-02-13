#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define SA struct sockaddr
int main(){
    int sid;
    char c = 'p';
    struct sockaddr_in server_address;
    int ser_len;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 6969;
    ser_len = sizeof(server_address);
    printf("%c is sent to server\n\n",c);
    printf("Sending char to server...\n\n");
    sid=socket(AF_INET,SOCK_DGRAM,0); 
    sendto(sid,&c,1,0,(SA *)&server_address,ser_len);
    recvfrom(sid,&c,1,0,(SA *)&server_address,&ser_len);
    printf("Recieved characted from server is %c\n",c); 
    close(sid);  
    return 0;
}
