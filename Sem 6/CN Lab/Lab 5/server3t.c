// Server side implementation of TCP client-server model
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
int main(){
    int serid,sessid;
    int res,num;
    struct sockaddr_in server_address,client_address;
    int server_addlen,client_addlen;
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_address.sin_port=5080;
    server_addlen=sizeof(server_address);
    client_addlen=sizeof(client_addlen);
    serid=socket(AF_INET,SOCK_STREAM,0);
    bind(serid,(struct sockaddr*)&server_address,server_addlen);
    listen(serid,10);
    while(1){
    	printf("________________________________\n");
        printf("Server is ready to accept ......\n");
        sessid=accept(serid,(struct sockaddr *)&client_address,&client_addlen);
        read(sessid,&res,sizeof(int)); 
        read(sessid,&num,sizeof(int));
        printf("Received num1: %d\tnum2: %d\n",res,num);
        int prod,diff,quo; 
        diff = res-num;
	prod = res*num;
	if(num==0) quo=-1;
	else quo = res/num;
	printf("\nDifference: %d\nProduct: %d\nQuotient: %d\n",diff,prod,quo);
	write(sessid,&diff,sizeof(int));
	write(sessid,&prod,sizeof(int));
	write(sessid,&quo,sizeof(int));
	printf("----------------------------------\n\n");
        close(sessid);
    }
    return(0);
}
