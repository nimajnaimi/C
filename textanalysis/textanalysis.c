#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void analyzeLine(char * message, int * statsArr) {
    assert(message != NULL);
    assert(statsArr != NULL);
    for (int i = 0; message[i] != '\0'; i++){
        if(message[i]  - 'a' >= 0 && message[i] - 'a' <= 25){
            statsArr[message[i] - 'a']++;
        }
    }
}

void printStats(int * statsArr, int length) {
    assert(statsArr != NULL);
    for (int i = 0; i < length; i++){
        if (statsArr[i] != 0){
          printf("%c: %d\n", 'a' + i, statsArr[i]);
        }
    }
}

void getLine(char * message) {
    assert(message != NULL);
    printf("Enter a line (use stop to end): ");
    int numWordsRead = scanf(" %[^\r\n]", message);
    assert(numWordsRead == 1);
}


void textStats() {
    char str[140];
    char * stopMessage = "stop";
    int charStats[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int charStatsLength = 26;
    getLine(str);
    while (strcmp(stopMessage, str) != 0){
        analyzeLine(str, charStats);
        printStats(charStats, charStatsLength);
        getLine(str);
    }
}

int main() {
    textStats();
    return 0;
}
