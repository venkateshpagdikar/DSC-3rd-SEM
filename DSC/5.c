#include<stdio.h>
#include<conio.h>
#include<string.h>

int stack[50], top = -1;
char postfix[50];

void infix_to_postfix(char infix[]);
int preced(char ch);
void push(char ch);
char pop();

int main(void) {
    char infix[25];
    clrscr(); // May need to remove this if unsupported
    printf("Enter a valid infix expression: ");
    gets(infix); // Use fgets() if modern compiler
    infix_to_postfix(infix);
    getch(); // May need to remove this if unsupported
    return 0;
}

void infix_to_postfix(char infix[]) {
    int length, index = 0, pos = 0;
    char symbol, temp;
    length = strlen(infix);
    push('#'); // Start with a marker
    while (index < length) {
        symbol = infix[index];
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                temp = pop();
                while (temp != '(') {
                    postfix[pos++] = temp;
                    temp = pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (preced(stack[top]) >= preced(symbol)) {
                    temp = pop();
                    postfix[pos++] = temp;
                }
                push(symbol);
                break;
            default:
                postfix[pos++] = symbol;
                break;
        }
        index++;
    }
    while (top > 0) {
        temp = pop();
        postfix[pos++] = temp;
    }
    postfix[pos] = '\0';
    printf("The postfix of %s is = %s", infix, postfix);
}

int preced(char ch) {
    switch (ch) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
        case ')':
            return 0;
        case '#':
            return -1;
    }
    return 0;
}

void push(char ch) {
    top++;
    stack[top] = ch;
}

char pop() {
    char ch;
    ch = stack[top];
    top--;
    return ch;
}
