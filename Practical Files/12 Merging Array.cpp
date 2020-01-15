#include<iostream.h>
#include<conio.h>
void merge(float a[],int m,float b[],int n,float c[]){ int i=0,j=0,k=0;
while(i<m&&j<n)
{ if(a[i]<b[j])
{ c[k]=a[i]; k++; i++; }
else { c[k]=b[j];  k++; j++; } }
while(i<m)
{ c[k]=a[i]; k++; i++; }
while(j<n)
{ c[k]=b[j]; k++; j++; }
for(int p=0;p<m+n;p++)
cout<<c[p]<<endl;}
void main()
{ float x[5],y[5],z[10];
cout<<"Enter the 2 sorted strings\n";for(int f=0;f<5;f++)  cin>>x[f]; cout<<endl; 
for(int g=0;g<5;g++)cin>>y[g];
cout<<endl;merge(x,5,y,5,z);
getch();}
