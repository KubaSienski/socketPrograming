#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    int num, result;
    socklen_t addr_len = sizeof(server_addr);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter an integer: ");
    scanf("%d", &num);

    num = htonl(num); // Convert to network byte order

    // Send number to server
    sendto(sockfd, &num, sizeof(num), 0, (const struct sockaddr*)&server_addr, addr_len);

    // Receive squared result from server
    recvfrom(sockfd, &result, sizeof(result), 0, (struct sockaddr*)&server_addr, &addr_len);
    result = ntohl(result); // Convert from network byte order

    printf("Squared result from server: %d\n", result);

    close(sockfd);
    return 0;
}
