// httpbora.h

#ifndef HTTPBORA_H
#define HTTPBORA_H

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Callback function for receiving HTTP response
size_t writeCallback(void* contents, size_t size, size_t nmemb, char** response) {
    size_t realsize = size * nmemb;

    *response = realloc(*response, realsize + 1);
    if (*response == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    memcpy(*response, contents, realsize);
    (*response)[realsize] = '\0';

    return realsize;
}

// Function to perform an HTTP GET request
char* httpGet(const char* url) {
    CURL* curl;
    CURLcode res;
    char* response = NULL;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return response;
}

#endif // HTTPBORA_H
