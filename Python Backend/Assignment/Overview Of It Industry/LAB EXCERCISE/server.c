#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server;
    char response[] = 
        "HTTP/1.1 200 OK\r\n\r\n"
        "Hello from C Server!";

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *)&server, sizeof(server));
    listen(server_socket, 1);

    printf("Server running on port 8080\n");

    client_socket = accept(server_socket, NULL, NULL);
    recv(client_socket, response, sizeof(response), 0); // optional
    send(client_socket, response, strlen(response), 0);

    close(client_socket);
    close(server_socket);
    return 0;
}
