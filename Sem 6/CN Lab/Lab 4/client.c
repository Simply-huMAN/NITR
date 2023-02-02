/*TCP_Client*/
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server;
    int num1, num2, result;
    
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Could not create socket");
        return 1;
    }
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    
    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connect failed");
        return 1;
    }
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    num1 = htonl(num1);
    num2 = htonl(num2);
    send(client_socket, &num1, sizeof(num1), 0);
    send(client_socket, &num2, sizeof(num2), 0);
    recv(client_socket, &result, sizeof(result), 0);
//    result = ntohl(result);
    
    printf("Result: %d\n", result);
    
    close(client_socket);
    
    return 0;
}
