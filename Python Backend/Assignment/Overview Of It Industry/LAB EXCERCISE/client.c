#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock;
    struct sockaddr_in server;
    char message[1000];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    char request[] = "GET / HTTP/1.1\r\n\r\n";
    send(sock, request, strlen(request), 0);

    recv(sock, message, sizeof(message), 0);
    printf("Server Response:\n%s\n", message);

    close(sock);
    return 0;
}
