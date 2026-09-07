#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Display all lines */
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* Insert a new line */
void insertLine()
{
    int lineNumber;

    if (lineCount >= MAX_LINES)
    {
        printf("\nDocument is full.\n");
        return;
    }

    printf("\nEnter line number to insert: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift lines down */
    for (int i = lineCount; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter the text: ");
    fgets(lines[lineNumber - 1], MAX_LENGTH, stdin);

    /* Remove newline */
    lines[lineNumber - 1][strcspn(lines[lineNumber - 1], "\n")] = '\0';

    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Delete a line */
void deleteLine()
{
    int lineNumber;

    if (lineCount == 0)
    {
        printf("\nDocument is empty. Nothing to delete.\n");
        return;
    }

    printf("\nEnter line number to delete: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift lines up */
    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

/* Main function */
int main()
{
    int choice;

    while (1)
    {
        printf("\n================================\n");
        printf("        SIMPLE LINE EDITOR\n");
        printf("================================\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            insertLine();
            break;

        case 2:
            deleteLine();
            break;

        case 3:
            displayDocument();
            break;

        case 4:
            printf("\nExiting editor...\n");
            return 0;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}