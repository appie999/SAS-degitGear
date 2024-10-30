#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TASKS 100
#define TITLE_LEN 100
#define DESC_LEN 256

typedef struct {
    char title[TITLE_LEN];
    char description[DESC_LEN];
    char dueDate[11]; // Format: YYYY-MM-DD
    char priority[10]; // "High" or "Low"
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;    //for Keep tracking the current number of tasks. ---> indicates how many tasks have been added to the tasks array.

void addTask() {
    if (taskCount >= MAX_TASKS) {        /*This prevents adding more tasks than the array can hold, which would cause memory overflow and possibly crash the program.*/
        printf("Task list is full!\n");
        return;
    }

    Task newTask;// new task
    printf("Enter task title: ");
    scanf(" %[^\n]", newTask.title);
    printf("Enter task description: ");
    scanf(" %[^\n]", newTask.description);
    printf("Enter due date (YYYY-MM-DD): ");
    scanf(" %[^\n]", newTask.dueDate);
    printf("Enter priority (High/Low): ");
    scanf(" %[^\n]", newTask.priority);

    tasks[taskCount++] = newTask; // Adds the newly created newTask to the tasks array and updates taskCount.
    printf("Task added successfully!\n");
}

 // This function displays all tasks in the tasks array.
void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nList of Tasks:\n");
     int i;
    for ( i = 0 ; i < taskCount; i++) {
        printf("Task %d:\n", i + 1);
        printf("  Title: %s\n", tasks[i].title);
        printf("  Description: %s\n", tasks[i].description);
        printf("  Due Date: %s\n", tasks[i].dueDate);
        printf("  Priority: %s\n\n", tasks[i].priority);
    }
}

void modifyTask() {
    int taskIndex;

    displayTasks();

    printf("Enter the task number to modify: ");
    scanf("%d", &taskIndex);

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    Task *task = &tasks[taskIndex - 1];
    printf("Enter new description (or press enter to keep current): ");
    char input[DESC_LEN];
    scanf(" %[^\n]", input);
    int len = strlen(input);
    if (len > 0) {
        strcpy(task->description, input);
    }

    printf("Enter new due date (or press enter to keep current): ");
    scanf(" %[^\n]", input);
    if (strlen(input) > 0) {
        strcpy(task->dueDate, input);
    }

    printf("Enter new priority (or press enter to keep current): ");
    scanf(" %[^\n]", input);
    if (strlen(input) > 0) {
        strcpy(task->priority, input);
    }

    printf("Task modified successfully!\n");
}

void deleteTask() {
    int taskIndex;
    displayTasks();
    int i;

    printf("Enter the task number to delete: ");
    scanf("%d", &taskIndex);

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    for ( i = taskIndex - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    printf("Task deleted successfully!\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: displayTasks(); break;
            case 3: modifyTask(); break;
            case 4: deleteTask(); break;
            case 5: filterTasks(); break;
            case 6: printf("Exiting the application.\n"); break;
            default: printf("Invalid choice. Please try again.\n");


        }
    } while (choice != 6);

