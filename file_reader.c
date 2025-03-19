#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "file_reader.h"


uint32_t my_ntohl(uint32_t net) {
    return ((net & 0x000000FFU) << 24) | 
           ((net & 0x0000FF00U) << 8)  |
           ((net & 0x00FF0000U) >> 8)  |
           ((net & 0xFF000000U) >> 24);
}

uint32_t read_network_number(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if(file == NULL) {
        fprintf(stderr, "fail open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    uint32_t num;
    if (fread(&num, sizeof(uint32_t), 1, file) != 1) {
        fprintf(stderr, "file read fail.\n", filename);
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
    
    return my_ntohl(num);
}
