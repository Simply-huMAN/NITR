// Client side implementation of UDP client-server model
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
    int sid,num1=20,num2,res;
    char s[100]="Hello, This is a sample message from client!";
    struct sockaddr_in server_address;
    int ser_len;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.125.242");
    server_address.sin_port = 6969;
    ser_len = sizeof(server_address);
    printf("Data sent: %d\n",num1);
    printf("Sending string to server...\n\n");
    sleep(2);
    sid=socket(AF_INET,SOCK_DGRAM,0);
    sendto(sid,&num1,sizeof(num1),0,(SA *)&server_address,ser_len);
    recvfrom(sid,&num1,sizeof(num1),0,(SA *)&server_address,&ser_len);
    printf("Message from server: \n%d\n",num1);
    close(sid);
    return 0;
}


