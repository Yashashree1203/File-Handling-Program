#include <stdio.h>

void createFile() {
    FILE *fp;
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        return;
    }
    printf("File created successfully\n");
    fclose(fp);
}

void writeFile() {
    FILE *fp;
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(fp, "Hello, World!\n");
    printf("Data written to file successfully\n");
    fclose(fp);
}

void readFile() {
    FILE *fp;
    char buffer[100];
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    while (fgets(buffer, 100, fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
}

void appendFile() {
    FILE *fp;
    fp = fopen("example.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(fp, "Appended data\n");
    printf("Data appended to file successfully\n");
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("File Handling Program\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read from File\n");
        printf("4. Append to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                writeFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                appendFile();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
