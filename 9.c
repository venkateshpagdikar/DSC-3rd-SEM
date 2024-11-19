#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[20];
    int id;
    int sem;
    struct student *link;
};

typedef struct student *STUDENT;

STUDENT getnode(void) {
    STUDENT X;
    X = (STUDENT)malloc(sizeof(struct student));
    if (X == NULL) {
        printf("out of memory\n");
        exit(0);
    }
    return X;
}

void freenode(STUDENT X) {
    free(X);
}

STUDENT insert_front(char name[], int id, int sem, STUDENT first) {
    STUDENT temp;
    temp = getnode();
    strcpy(temp->name, name);
    temp->sem = sem;
    temp->id = id;
    temp->link = first;
    first = temp;
    return first;
}

STUDENT insert_rear(char name[], int id, int sem, STUDENT first) {
    STUDENT temp;
    STUDENT cur;
    temp = getnode();
    strcpy(temp->name, name);
    temp->id = id;
    temp->sem = sem;
    temp->link = NULL;
    if (first == NULL) return temp;
    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

STUDENT delete_student(int id, STUDENT first) {
    STUDENT pre, cur;
    if (first == NULL) {
        printf("no student in the organization\n");
        return NULL;
    }
    pre = NULL;
    cur = first;
    while (cur != NULL && id != cur->id) {
        pre = cur;
        cur = cur->link;
    }
    if (cur == NULL) {
        printf("student id not found\n");
        return first;
    }
    if (pre == NULL)
        first = first->link;
    else
        pre->link = cur->link;
    free(cur);
    return first;
}

void display(STUDENT first) {
    STUDENT temp;
    if (first == NULL) {
        printf("no student in the organization\n");
        return;
    }
    printf("studentname studentid studentsem\n");
    printf("................\n");
    for (temp = first; temp != NULL; temp = temp->link)
        printf("%10s %4d %4d\n", temp->name, temp->id, temp->sem);
    printf("\n");
}

int main() {
    STUDENT first = NULL;
    int choice, id, sem;
    char name[20];
    // clrscr(); // Commented out, as it's not standard in modern compilers
    for (;;) {
        printf("1:insert front 2:insert rear\n");
        printf("3:delete 4:display\n");
        printf("5:exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2) {
            printf("name:");
            scanf("%s", name);
            printf("id:");
            scanf("%d", &id);
            printf("sem:");
            scanf("%d", &sem);
        }
        switch (choice) {
            case 1:
                first = insert_front(name, id, sem, first);
                break;
            case 2:
                first = insert_rear(name, id, sem, first);
                break;
            case 3:
                printf("delete student details for id:");
                scanf("%d", &id);
                first = delete_student(id, first);
                break;
            case 4:
                display(first);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
