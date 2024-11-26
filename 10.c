#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct node {
    struct node *prev;
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
} *h, *temp, *temp1, *temp2, *temp4;

void create() {
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    temp = (struct node *)malloc(sizeof(struct node));
    if (!temp) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter ssn, name, department, designation, salary, and phno of employee: ");
    scanf("%d %s %s %s %f %d", &ssn, name, dept, desg, &sal, &phno);
    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}

void insertbeg() {
    if (h == NULL) {
        create();
        h = temp;
        temp1 = h;
    } else {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

void insertend() {
    if (h == NULL) {
        create();
        h = temp;
        temp1 = h;
    } else {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

void displaybeg() {
    temp2 = h;
    if (temp2 == NULL) {
        printf("List empty to display\n");
        return;
    }
    printf("\nLinked list elements from beginning:\n");
    while (temp2 != NULL) {
        printf("%d %s %s %s %f %d\n", temp2->ssn, temp2->name, temp2->dept,
               temp2->desg, temp2->sal, temp2->phno);
        temp2 = temp2->next;
    }
    printf("Number of employees = %d\n", count);
}

int deleteend() {
    if (h == NULL) {
        printf("List is empty\n");
        return 0;
    }
    if (h->next == NULL) {
        printf("%d %s %s %s %f %d\n", h->ssn, h->name, h->dept, h->desg, h->sal, h->phno);
        free(h);
        h = NULL;
    } else {
        temp2 = temp1->prev;
        temp2->next = NULL;
        printf("%d %s %s %s %f %d\n", temp1->ssn, temp1->name, temp1->dept,
               temp1->desg, temp1->sal, temp1->phno);
        free(temp1);
        temp1 = temp2;
    }
    count--;
    return 0;
}

int deletebeg() {
    if (h == NULL) {
        printf("List is empty\n");
        return 0;
    }
    temp = h;
    if (h->next == NULL) {
        printf("%d %s %s %s %f %d\n", h->ssn, h->name, h->dept, h->desg, h->sal, h->phno);
        free(h);
        h = NULL;
    } else {
        h = h->next;
        h->prev = NULL;
        printf("%d %s %s %s %f %d\n", temp->ssn, temp->name, temp->dept,
               temp->desg, temp->sal, temp->phno);
        free(temp);
    }
    count--;
    return 0;
}

int main() {
    int ch, n, i;
    h = NULL;
    temp = temp1 = NULL;

    printf("-----------------MENU--------------------\n");
    printf("\n1 - Create a DLL of n employees");
    printf("\n2 - Display from beginning");
    printf("\n3 - Insert at end");
    printf("\n4 - Delete at end");
    printf("\n5 - Insert at beginning");
    printf("\n6 - Delete at beginning");
    printf("\n7 - Exit\n");
    printf("------------------------------------------\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the number of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    insertend();
                break;
            case 2:
                displaybeg();
                break;
            case 3:
                insertend();
                break;
            case 4:
                deleteend();
                break;
            case 5:
                insertbeg();
                break;
            case 6:
                deletebeg();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
