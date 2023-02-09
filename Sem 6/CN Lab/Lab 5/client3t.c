// Client side implementation of TCP client-server model
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
int main(){ 
    int sid,num1,num2;
    	printf("Enter num1: ");
	scanf("%d",&num1);
	printf("Enter num2: ");
	scanf("%d",&num2);
    struct sockaddr_in server_address;
    int server_addlen;
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_address.sin_port=5080;
    server_addlen=sizeof(server_address);
    sid=socket(AF_INET,SOCK_STREAM,0);
    connect(sid,(struct sockaddr *)&server_address,server_addlen);
    printf("Sending data to server\n");
    write(sid,&num1,sizeof(int));
    write(sid,&num2,sizeof(int));
    
    int diff,prod,quo,ans[3];
    read(sid,&diff,sizeof(int));
    read(sid,&prod,sizeof(int));
    read(sid,&quo,sizeof(int));
    printf("\nDifference: %d\nProduct: %d\nQuotient: %d\n",diff,prod,quo);   
    if(quo==-1) printf("Since num2 is 0, couldn't perform division\n");       
    close(sid);
    return(0);
}
