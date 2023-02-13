// Client side implementation of UDP client-server model chat application

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
     int sid,num1=69,num2,res; 
     char s[100]="Hello, This is a sample message from client!"; 
     struct sockaddr_in server_address; 
     int ser_len; 
     server_address.sin_family = AF_INET; 
     server_address.sin_addr.s_addr = inet_addr("192.168.137.180"); 
     server_address.sin_port = 7890; 
     ser_len = sizeof(server_address);
     while(1){
          printf("__________________\n");
          printf("Enter your message: "); 
          fgets(s,100,stdin);
          //scanf("%d",&num1);
          printf("Your message: %s\n",s); 
          printf("Sending string to server...\n\n"); 
          sleep(2); 
          sid=socket(AF_INET,SOCK_DGRAM,0); 
          sendto(sid,&s,sizeof(s),0,(SA *)&server_address,ser_len); 
          recvfrom(sid,&s,sizeof(s),0,(SA *)&server_address,&ser_len); 
          printf("Message from server: \n%s\n",s);
          printf("-------------------\n\n"); 
    }
     close(sid); 
     return 0; 
 } 
