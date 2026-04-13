#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/**
 * Task 4.3: Simple Port Scanner in C
 * Scans ports 22, 80, 443, and 3306 on localhost (127.0.0.1).
 */

void scan_port(int port) {
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        return;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    server.sin_port = htons(port);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Port %d: CLOSED\n", port);
    } else {
        printf("Port %d: OPEN\n", port);
    }

    close(sock);
}

int main() {
    int ports[] = {22, 80, 443, 3306};
    int num_ports = sizeof(ports) / sizeof(ports[0]);

    printf("Starting C Port Scanner on 127.0.0.1...\n");

    for (int i = 0; i < num_ports; i++) {
        scan_port(ports[i]);
    }

    return 0;
}