#include <stdio.h>

int main() {
    // 1. Create an integer variable port = 80
    int port = 80;
    
    // 2. Create a pointer to port
    int *ptr = &port;
    
    // 3. Print port value using variable
    printf("Port value using variable: %d\n", port);
    
    // 4. Print port value using pointer
    printf("Port value using pointer: %d\n", *ptr);
    
    // 5. Change port to 443 using pointer
    *ptr = 443;
    
    // 6. Print new value
    printf("New port value after change: %d\n", port);
    
    return 0;
}