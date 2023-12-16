// fscreate.h

#ifndef FSCREATE_H
#define FSCREATE_H

#include <stdio.h>
#include <stdlib.h>

// Function to create a new Bora file
void createBoraFile(const char* filename, const char* content) {
    // Form the full filename with the .bora extension
    char fullFilename[256];
    snprintf(fullFilename, sizeof(fullFilename), "%s.bora", filename);

    // Create and write content to the Bora file
    FILE* file = fopen(fullFilename, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s", content);
    fclose(file);

    printf("Created Bora file: %s\n", fullFilename);
}

#endif // FSCREATE_H
