#include<iostream.h>
#include<conio.h>
int main()
{
int i,ar[50],item,n,index;            
cout<<"how many elements enter";
cin>>n;
cout<<"enter array elements";
for(int i=0;i<n;i++)
cin>>ar[i];
cout<<"array with doubled elements as follows";
for(i=0;i<n;i++)
{
ar[i]*=2;
cout<<ar[i]<<" ";}
cout<<endl;
return 0;
getch();
}
