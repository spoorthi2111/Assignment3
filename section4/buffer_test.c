#include <stdio.h>
#include <string.h>

/**
 * Task 4.2: Vulnerable Buffer Program
 * This program demonstrates a buffer overflow vulnerability using the unsafe gets() function.
 */

int main() {
    // Requirement: Create a buffer of size 16 [cite: 95]
    char buffer[16];

    // Requirement: Ask user for input [cite: 96]
    printf("Enter some text: ");

    // Requirement: Use unsafe method to copy input [cite: 97]
    // Note: gets() does not check for buffer limits, making it highly vulnerable.
    gets(buffer); 

    printf("You entered: %s\n", buffer);

    /* * --- ASSIGNMENT ANSWERS [cite: 99-104] ---
     * 1. What happens with long input (30+ characters)? 
     * Answer: The input overflows the 16-byte allocated space and overwrites 
     * adjacent memory. This usually results in a "Segmentation fault (core dumped)" 
     * and the program crashes.
     * * 2. Why is this dangerous? 
     * Answer: An attacker can use this to overwrite the function's return address 
     * on the stack, potentially redirecting the program execution to malicious 
     * code (Remote Code Execution).
     * * 3. How would you fix it? 
     * Answer: Use safer functions like 'fgets()' which allow you to specify 
     * the maximum number of characters to read, preventing the buffer from 
     * being exceeded.
     */

    return 0;
}