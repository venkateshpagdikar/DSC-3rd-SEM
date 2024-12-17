#include<stdio.h>
#include<stdlib.h> // For malloc() and exit()
#include<conio.h>  // Only if you use Turbo C++

struct node1 {
    int data;
    struct node1 *lt, *rt;
};
typedef struct node1 node;
node *root = NULL;

// Function prototypes
node *insert(node *, int);
void inorder(node *);
void preorder(node *);
void postorder(node *);

int ch = 0, num; // Initialize ch to avoid undefined behavior

void main() {
    clrscr(); // Only works in Turbo C++; remove or replace if not using Turbo C

    while (ch != 5) {
        printf("\n***** MENU OPERATION *****\n");
        printf("1_INSERT\n");
        printf("2_INORDER\n");
        printf("3_POSTORDER\n");
        printf("4_PREORDER\n");
        printf("5_EXIT\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to be inserted:\n");
                scanf("%d", &num);
                root = insert(root, num);
                break;
            case 2:
                printf("Elements in INORDER:\n");
                inorder(root);
                break;
            case 3:
                printf("Elements in POSTORDER:\n");
                postorder(root);
                break;
            case 4:
                printf("Elements in PREORDER:\n");
                preorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Enter a valid choice.\n");
        }
    }

    getch(); // Only for Turbo C++; remove if using modern compilers
}

node *insert(node *p, int num) {
    if (p == NULL) {
        p = (node*)malloc(sizeof(node));
        if (p == NULL) { // Check for memory allocation failure
            printf("Memory allocation failed.\n");
            exit(1);
        }
        p->data = num;
        p->lt = NULL;
        p->rt = NULL;
    } else {
        if (num < p->data)
            p->lt = insert(p->lt, num);
        else
            p->rt = insert(p->rt, num);
    }
    return p;
}

void preorder(node *p) {
    if (p != NULL) {
        printf("%d\t", p->data);
        preorder(p->lt);
        preorder(p->rt);
    }
}

void inorder(node *p) {
    if (p != NULL) {
        inorder(p->lt);
        printf("%d\t", p->data);
        inorder(p->rt);
    }
}

void postorder(node *p) {
    if (p != NULL) {
        postorder(p->lt);
        postorder(p->rt);
        printf("%d\t", p->data);
    }
}
