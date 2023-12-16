// makefile.h

#ifndef MAKEFILE_H
#define MAKEFILE_H

#include <stdio.h>
#include <stdlib.h>

// Function to execute make command
void executeMakefile(const char* makefilePath) {
    // Form the full filename with the .makefile extension
    char fullMakefilePath[256];
    snprintf(fullMakefilePath, sizeof(fullMakefilePath), "%s.makefile", makefilePath);

    // Execute make command
    printf("Executing makefile: %s\n", fullMakefilePath);
    int result = system(makefilePath);
    if (result == -1) {
        perror("Error executing make command");
        exit(EXIT_FAILURE);
    }
}

#endif // MAKEFILE_H
