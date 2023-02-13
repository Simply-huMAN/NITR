// Client side implementation of UDP client-server model
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define SA struct sockaddr

int main(){
    int sid,num1,num2,res;
    time_t clientTime,dTime;
    time(&clientTime);
    struct sockaddr_in server_address;
    int ser_len;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 6970;
    ser_len = sizeof(server_address);
    printf("Sending message to server...\n\n");
    sleep(2);
    sid=socket(AF_INET,SOCK_DGRAM,0);
    sendto(sid,&clientTime,sizeof(clientTime),0,(SA *)&server_address,ser_len);
    recvfrom(sid,&dTime,sizeof(dTime),0,(SA *)&server_address,&ser_len);
    printf("Message from server: \nServer response time: %s\n",ctime(&dTime));
    printf("Time difference: %f\n",difftime(clientTime,dTime));
    close(sid);
    return 0;
}

