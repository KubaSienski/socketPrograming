#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int num, result;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("TCP Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a client connection
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Receive number from client
        read(client_fd, &num, sizeof(num));
        num = ntohl(num); // Convert from network byte order
        printf("Received number: %d\n", num);

        // Compute square and send back
        result = num * num;
        result = htonl(result); // Convert to network byte order
        write(client_fd, &result, sizeof(result));
        printf("Sent squared result: %d\n", result);

        // Close the connection
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
