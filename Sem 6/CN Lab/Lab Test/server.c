//TCP Server program
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int serid,sessid,num1,num2;
	struct sockaddr_in server_address,client_address;

	unsigned int server_addlen,client_addlen;
	
	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	server_address.sin_port=9876;
	
	server_addlen=sizeof(server_address);
	client_addlen=sizeof(client_addlen);
	
	serid=socket(AF_INET,SOCK_STREAM,0);
	
	bind(serid,(struct sockaddr*)&server_address,server_addlen);
	
	listen(serid,10);
	
	while(1){
		printf("Server is ready to accept ......\n");
		sessid=accept(serid,(struct sockaddr *)&client_address,&client_addlen);
		read(sessid,&num1,4);
		read(sessid,&num2,4);
		printf("\nMessage received from client\nThe numbers are: %d %d\n\n",num1,num2);
		num1 = num1/num2;
		write(sessid,&num1,4);
		close(sessid);
	}
	return(0);
}
