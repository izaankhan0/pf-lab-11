#include <stdio.h>
#include <ctype.h>

void copyFile(const char *Original, const char *New) {
    FILE *OrgFile = fopen(Original, "r");
    FILE *NewFile = fopen(New, "w");

    if (OrgFile == NULL) {
        printf("Error: Could not open file %s.\n", Original);
        return;
    }
    if (NewFile == NULL) {
        printf("Error: Could not create file %s.\n", New);
        fclose(OrgFile);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), OrgFile) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            line[i] = toupper(line[i]);
        }
        fputs(line, NewFile);
    }

    printf("File copied successfully with transformations.\n");

    fclose(OrgFile);
    fclose(NewFile);
}

int main() {
    char originalFile[100], newFile[100];

    printf("Enter the name of the original file: ");
    scanf("%s", originalFile);
    printf("Enter the name of the new file: ");
    scanf("%s", newFile);

    copyFile(originalFile, newFile);

    return 0;
}
