#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
int x,n[5];
cout<<"Guess the number between 1-15 within 5 chances\n";
randomize();
x=random(15)+1;		
for(int i=0;i<5;i++)
{
cin>>n[i];
if(n[i]==x)
{cout<<"Correct!!\n";break; }
else	
{	
if(n[i]>x)
cout<<"Too High\n";
else
cout<<"Too low\n";
}
}
getch();
} 
