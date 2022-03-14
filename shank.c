#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 2) {
        printf("To use this program please use ./shank <prime>.\nWhere <prime> is a prime number.\nThis program makes no check for determining if <prime> is a prime number other than checking that it's greater than 1.\n");
        return 0;
    }

    int prime = atoi(argv[1]);

    if (prime <= 1) {
        printf("please use a prime number.");
        return 0;
    }

    int curr = 10;
    int index = 0;
    char* remanders = calloc(prime, sizeof(char));

    // Check this box since we start with 1
    remanders[1] = 1;


    while(1) {

        // Check for significant zeros
        // Don't check for repeats here since there's no new divide
        // Also can give a segfault since this number can go out of the range of 0:prime-1
        while(curr < prime) {
            curr *= 10;
            index++;
        }
        
        // Find the remander
        curr = curr % prime;
        index++;

        if (remanders[curr]) {
            printf("It takes %d decimals to repeat\n", index);
            return 0;
        }

        remanders[curr] = 1;

        // Figuratively add a zero to the end
        curr *= 10;
    }

    return 0;
}