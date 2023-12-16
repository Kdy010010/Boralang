// fsbora.h

#ifndef FSBORA_H
#define FSBORA_H

#include <stdio.h>
#include <stdlib.h>

// Function to read the content of a Bora file
char* readBoraFile(const char* filename) {
    // Form the full filename with the .bora extension
    char fullFilename[256];
    snprintf(fullFilename, sizeof(fullFilename), "%s.bora", filename);

    FILE* file = fopen(fullFilename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = (char*)malloc(file_size + 1);
    fread(content, 1, file_size, file);
    fclose(file);

    content[file_size] = '\0';

    return content;
}

#endif // FSBORA_H
