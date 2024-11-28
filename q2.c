#include <stdio.h>

void readFileDisplay(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", fileName);
        return;
    }

    char line[256];
    int lineNumber = 1;

    printf("Contents of the file %s:\n", fileName);
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", lineNumber, line);
        lineNumber++;
    }

    fclose(file);
}

int main() {
    char fileName[100];

    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);

    readFileDisplay(fileName);

    return 0;
}
