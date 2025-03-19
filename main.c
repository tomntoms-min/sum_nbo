//main.c file
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "file_reader.h"

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "need more file\n");
        return EXIT_FAILURE;
    }

    uint32_t total = 0;
    int first = 1;
    
    for(int i = 1; i < argc; i++){
        uint32_t number = read_network_number(argv[i]);
        if(!first) {
            printf(" + ");
        }
        // Decimal and hexadecimal outputs
        printf("%u(0x%04x)", number, number);
        total += number;
        first = 0;
    }
    printf(" = %u(0x%04x)\n", total, total);
    return EXIT_SUCCESS;
}
