#include<iostream.h>
#include<stdio.h>
#include<conio.h>
class employee
{ char name[20]; char desig[20]; float basesal; float da()
{float d=(basesal*3)/5;   return d; }
float cal_salary()
{ float d=da();  float t;  t=basesal+d; return t; }
public:
void input()
{  gets(name); gets(desig); cin>>basesal; }
void output()
{  float t;
cout<<endl<<name<<endl<<desig<<endl;t=cal_salary();
cout<<"Your payable salary is "<<t;}};
void main()
{employee E[5];
for(int i=0;i<5;i++)
{cout<<"\nEnter the name, designation & basic salary\n";  E[i].input(); E[i].output();} 
getch();
}
