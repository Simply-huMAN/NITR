/*TCP_Server*/
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int add_numbers(int num1, int num2) {
    return num1 + num2;
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server, client;
    int c;
    int num1, num2, result;
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Could not create socket");
        return 1;
    }
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5000);
    
    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Bind failed");
        return 1;
    }
    
    listen(server_socket, 3);
    
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t*)&c))) {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        recv(client_socket, &num1, sizeof(num1), 0);
        recv(client_socket, &num2, sizeof(num2), 0);
        result = add_numbers(ntohl(num1), ntohl(num2));
        send(client_socket, &result, sizeof(result), 0);
        close(client_socket);
        printf("Connection closed\n");
    }
    
    if (client_socket < 0) {
        printf("Accept failed");
        return 1;
    }
    
    return 0;
}
