#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void printKeywordStats(char * keywords[], int keywordStats[], int keywordLength) {
    for (int i = 0; i < keywordLength; i++) {
        printf("%s: %d\n", keywords[i], keywordStats[i]);
    }
}

int countKeywords(char * filename, char * keywords[], int keywordStats[], int keywordLength) {
    printf("Reading from %s\n", filename);
    FILE * inf = fopen(filename, "r");
    if (inf == NULL) {
        return -1;
    }
    char line[200];
    int lineNum = 1;
    int numberOfItemsRead = fscanf(inf, " %[^\r\n]", line);
    while (numberOfItemsRead == 1) {
        for (int i = 0; i < keywordLength; i++) {
            if (strstr(line, keywords[i]) != NULL) {
                keywordStats[i]++;
            }
        }
        checkWarnings(line, lineNum);
        lineNum++;
        numberOfItemsRead = fscanf(inf, " %[^\r\n]", line);
    }
    printf("***Line numbers in warnings do not include blank lines***\n\n");
    fclose(inf);
    return 0;
}

void checkWarnings(char * line, int lineNum) {
    if (strstr(line, "){") != NULL) {
        printf("Line %d, WARNING: Need space between ) and {\n", lineNum);
    }
    if (strstr(line, " ;)") != NULL) {
        printf("Line %d, WARNING: No space before ;\n", lineNum);
    }
    if (strstr(line, "#include<") != NULL) {
        printf("Line %d, WARNING: Need space after include\n", lineNum);
    }
    if (strstr(line, "int  ") != NULL) {
        printf("Line %d, WARNING: Multiple spaces after int\n", lineNum);
    }
    if (strstr(line, "<") != NULL && strstr(line, " <") == NULL) {
        printf("Line %d, WARNING: Put space before <\n", lineNum);
    }
}

void fileWriteTester(char * filename) {
    printf("Writing to file %s\n", filename);
    FILE * outf = fopen(filename, "w");
    for (int i = 0; i < 10; i++) {
        fprintf(outf, "%d\n", i);
    }
    fclose(outf);
}

int main(int argc, char * argv[]) {
    fileWriteTester("myoutput.txt");
    char * keywords[] = { "void ", "int ", "double ", "char " };
    int keywordStats[] = { 0, 0, 0, 0 };
    int keywordLength = 4;
    char * fileToRead = argv[1];
    int err = countKeywords(fileToRead, keywords, keywordStats, keywordLength);
    if (err == -1) {
        printf("Failed to read file: %s\n", fileToRead);
        printf("Press any key to exit\n");
        char c;
        scanf("%c", &c);
        return -1;
    }
    printKeywordStats(keywords, keywordStats, keywordLength);
    printf("Press any key to exit\n");
    char c;
    scanf("%c", &c);
    return 0;
}
