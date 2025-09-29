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
#include <stdio.h>
#include <stdlib.h>

// Function to create a file
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

// Function to write to a file (user input)
void writeFile() {
    FILE *fp;
    char data[200];
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    getchar(); // clear newline left by scanf
    printf("Enter text to write into the file: ");
    fgets(data, sizeof(data), stdin);
    fprintf(fp, "%s", data);
    printf("Data written to file successfully\n");
    fclose(fp);
}

// Function to read from a file
void readFile() {
    FILE *fp;
    char buffer[200];
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file (maybe it doesn't exist)\n");
        return;
    }
    printf("File contents:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
}

// Function to append data to a file (user input)
void appendFile() {
    FILE *fp;
    char data[200];
    fp = fopen("example.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    getchar(); // clear newline left by scanf
    printf("Enter text to append to the file: ");
    fgets(data, sizeof(data), stdin);
    fprintf(fp, "%s", data);
    printf("Data appended to file successfully\n");
    fclose(fp);
}

// Function to delete a file
void deleteFile() {
    if (remove("example.txt") == 0) {
        printf("File deleted successfully\n");
    } else {
        printf("Error deleting file (maybe file doesn't exist)\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n==== File Handling Program ====\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read from File\n");
        printf("4. Append to File\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
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
                deleteFile();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
