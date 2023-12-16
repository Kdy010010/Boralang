// iobora.h

#ifndef IOBORA_H
#define IOBORA_H

#include <stdio.h>
#include <stdlib.h>

// Function to process Bora include statements
void processBoraInclude(const char* filename) {
    // Form the full filename with the .bora extension
    char fullFilename[256];
    snprintf(fullFilename, sizeof(fullFilename), "%s.bora", filename);

    // Read and include the content of the specified Bora file
    FILE* file = fopen(fullFilename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* includeCode = (char*)malloc(file_size + 1);
    fread(includeCode, 1, file_size, file);
    fclose(file);

    includeCode[file_size] = '\0';

    // Print or process the included Bora code as needed
    printf("Including file: %s\n", fullFilename);
    printf("%s\n", includeCode);

    free(includeCode);
}

#endif // IOBORA_H
