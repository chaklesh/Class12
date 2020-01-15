#include<iostream.h>
#include<conio.h>
void main()
{
int a,b,c,d,cho;
cout<<"Enter the real and imagimary parts of the 2 complex numbers:\n";
cin>>a>>b>>c>>d;
cout<<"Choose the operation\n"<<"1.Add\n2.Difference\n3.Multiply\n\n";
cin>>cho;
switch(cho)
{
case 1:cout<<a+c<<"+"<<b+d<<"i";
		break;
case 2:cout<<a-c<<"+"<<b-d<<"i";
		break;
case3:cout<<(a*c)-(b*d)<<"+"<<(a*d)+(b*c)<<"i"; }
getch(); }
