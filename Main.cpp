#include <stdio.h>
#include <string.h>

void processInclude(char* filename) {
    // Implement logic to process include statements
    printf("Including file: %s\n", filename);
    // Add your logic to include the content of the specified file
}

int main() {
    // Bora code with include statements
    char code[] = "bora.include<example.h>";

    // Find include statements and process them
    char* includeKeyword = "bora.include<";
    char* includeEnd = ">";
    char* includeStart = strstr(code, includeKeyword);

    while (includeStart != NULL) {
        includeStart += strlen(includeKeyword);
        char* includeFileName = strtok(includeStart, includeEnd);
        processInclude(includeFileName);

        includeStart = strstr(includeStart, includeKeyword);
    }

    return 0;
}
