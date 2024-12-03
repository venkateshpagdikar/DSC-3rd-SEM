#include<stdio.h>
#include<conio.h>

void towers(int n, char src, char dst, char temp);

int main() {
    int n;
    clrscr(); // If unsupported, remove clrscr()
    printf("Enter the number of discs\n");
    scanf("%d", &n);
    towers(n, 'A', 'C', 'B');
    getch(); // If unsupported, remove getch()
    return 0;
}

void towers(int n, char src, char dst, char temp) {
    if (n == 1) {
        printf("Move disc %d from %c to %c\n", n, src, dst);
    } else {
        towers(n - 1, src, temp, dst);
        printf("Move disc %d from %c to %c\n", n, src, dst);
        towers(n - 1, temp, dst, src);
    }
}
