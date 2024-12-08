#include<iostream.h>
#include<conio.h>
#include<stdio.h>
template<class t>
void quick(t a[],int low,int high)
{
t key;
int i,j,flag=1;
if(low<high)
{
key=a[low];
i=low+1;
j=high;
while(flag)
{
while((a[i]<=key) && (i<j))
i++;
while(a[j]>key)
j--;
if(i<j)
swap(a,i,j);
else
flag=0;
}
swap(a,low,j);
quick(a,low,j-1);
quick(a,j+1,high);
}
}
template<class t1>
void swap(t1 a[],int x,int y)
{
t1 temp;
temp=a[x];
a[x]=a[y];
a[y]=temp;
}
void main()
{
int i,n,a[20];
clrscr();
cout<<"Enter the number of elements to be sort::";
cin>>n;
cout<<"Enter elements:\n";
for(i=0;i<n;i++)
cin>>a[i];
quick(a,0,n-1);
cout<<"The sorted elements are:\n";
for(i=0;i<n;i++)
cout<< a[i]<<endl;;
getch();
}