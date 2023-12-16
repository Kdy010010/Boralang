#include <stdio.h>
#include <string.h>

void processInclude(char* filename) {
    // 파일을 열고 읽어오는 로직을 추가하세요
    printf("Including file: %s\n", filename);

    // 예시로 파일 내용을 출력
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        printf("Error opening file: %s\n", filename);
    }
}

void customInput() {
    // 사용자로부터 입력을 받는 로직을 추가하세요
    char userInput[100];
    printf("Enter something: ");
    fgets(userInput, sizeof(userInput), stdin);
    printf("You entered: %s", userInput);
}

void customOutput() {
    // 사용자에게 결과를 출력하는 로직을 추가하세요
    printf("Custom output: Hello, World!\n");
}

int main() {
    // Bora 코드 with include statements
    char code[] = "bora.include<example.h>";

    // Include 문 처리 및 사용자 정의 입출력 모듈 호출
    char* includeKeyword = "bora.include<";
    char* includeEnd = ">";
    char* includeStart = strstr(code, includeKeyword);

    while (includeStart != NULL) {
        includeStart += strlen(includeKeyword);
        char* includeFileName = strtok(includeStart, includeEnd);
        processInclude(includeFileName);

        includeStart = strstr(includeStart, includeKeyword);
    }

    // 사용자 정의 입출력 모듈 호출
    customInput();
    customOutput();

    return 0;
}
