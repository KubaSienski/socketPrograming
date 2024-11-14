#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP Server is listening on port %d\n", PORT);

    while (1) {
        int num, result;

        // Receive number from client
        recvfrom(sockfd, &num, sizeof(num), 0, (struct sockaddr*)&client_addr, &addr_len);
        num = ntohl(num); // Convert from network byte order
        printf("Received number: %d\n", num);

        // Compute square and send back
        result = num * num;
        result = htonl(result); // Convert to network byte order
        sendto(sockfd, &result, sizeof(result), 0, (struct sockaddr*)&client_addr, addr_len);
        printf("Sent squared result: %d\n", result);
    }

    close(sockfd);
    return 0;
}
