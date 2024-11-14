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

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Enter an integer: ");
    scanf("%d", &num);

    num = htonl(num); // Convert to network byte order

    // Send number to server
    write(sockfd, &num, sizeof(num));

    // Receive squared result from server
    read(sockfd, &result, sizeof(result));
    result = ntohl(result); // Convert from network byte order

    printf("Squared result from server: %d\n", result);

    close(sockfd);
    return 0;
}
