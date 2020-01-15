#include<iostream.h>
#include<conio.h>
void bubsort(float a[],int n)
{  float t;
   for(int i=0;i<n;i++)
{for(int j=0;j<n-i-1;j++) {if(a[j]>a[j+1]){t=a[j];   a[j]=a[j+1];    a[j+1]=t;}}}
for(int k=0;k<n;k++)
{cout<<a[k]<<endl;}}
void main()
{
float x[10];
cout<<"Enter the 10 numbers\n";
for(int i=0;i<10;i++)
{cin>>x[i];   }
cout<<endl;  bubsort(x,10);
getch();
}
