#include<stdio.h>
#include<conio.h>
#include<string.h>
struct student {
    char name[10];
    int usn;
    int marks1, marks2, marks3;
};

int main() {
    int n, avg[10], i;
    struct student a[10];
    clrscr();
    printf("Enter the number of students:\n");
    scanf("%d", &n);
    printf("Enter the details of students\n");
    for (i = 0; i < n; i++) {
	printf("Name = ");
	scanf("%s", a[i].name);
	printf("USN = ");
	scanf("%d", &a[i].usn);
	printf("Marks1 = ");
	scanf("%d", &a[i].marks1);
	printf("Marks2 = ");
	scanf("%d", &a[i].marks2);
	printf("Marks3 = ");
	scanf("%d", &a[i].marks3);
	avg[i] = (a[i].marks1 + a[i].marks2 + a[i].marks3) / 3;
    }
    printf("The details of students are:\n");
    printf("Name\tUSN\tMarks1\tMarks2\tMarks3\tAverage\n");
    for (i = 0; i < n; i++) {
	printf("%s\t%d\t%d\t%d\t%d\t%d\n", a[i].name, a[i].usn, a[i].marks1, a[i].marks2, a[i].marks3, avg[i]);
    }
    getch();
    return 0;
}
