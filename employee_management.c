#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    char department[30];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int count = 0;

void addEmployee() {
    if (count >= MAX_EMPLOYEES) {
        printf("Employee list is full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &employees[count].id);

    printf("Name: ");
    scanf("%s", employees[count].name);

    printf("Department: ");
    scanf("%s", employees[count].department);

    printf("Salary: ");
    scanf("%f", &employees[count].salary);
    
    count++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    int i;

    if (count == 0) {
        printf("No employees to display!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Dept: %s, Salary: %.2f\n", 
            employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
}

void searchEmployee() {
    char name[50];
    int i;

    printf("Enter name to search: ");
    scanf("%s", name);

    for (i = 0; i < count; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("Found: ID: %d, Dept: %s, Salary: %.2f\n", 
                employees[i].id, employees[i].department, employees[i].salary);
            return;
        }
    }
    printf("Employee not found!\n");
}

void updateEmployee() {
    int id, i;

    printf("Enter employee ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Enter new Name, Department, Salary: ");
            scanf("%s %s %f", employees[i].name, employees[i].department, &employees[i].salary);
            printf("Updated successfully!\n");
            return;
        }
    }
    printf("Employee not found!\n");
}

void deleteEmployee() {
    int id, i, found = 0;

    printf("Enter employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (employees[i].id == id) {
            employees[i] = employees[count - 1];
            count--;
            found = 1;
            printf("Employee deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Employee  2. Display Employees  3. Search Employee by Name  4. Update Employee  5. Delete Employee  6. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}