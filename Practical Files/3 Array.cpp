#include<fstream.H>
#include<string.H>
#include<stdio.H>
#include<conio.H>
const N=5;
class queue
{
float A[N];  int rear ;
public:
queue(){rear=-1;}
void addq();  void delq();   void dispq();
};
void queue::addq()			{
if(rear==N-1)
cout<<"overflow,addition not possible";
else
{
rear++;
cin>>A[rear];}}
void queue::delq()			
{
if(rear==-1)
cout<<"Underflow! queue is empty";
else
{
rear--;
for (int i=0;i<=rear;i++)
A[i]=A[i+1];}}
void queue::dispq()			{
if (rear==-1)
cout<<"queue is empty";
else
{
for(int i=0;i<=rear;i++)
cout<<A[i]<<endl;}}
void main()
{
int choice;
queue q;
do{
cout<<"1.ADD\n";
cout<<"2.DELETE\n";
cout<<"3.DISPLAY \n";
cout<<"4.QUIT\n";
choice=getch();
switch(choice)
{
case '1': q.addq();    break;
case '2': q.delq();    break;
case '3': q.dispq();    break;
case '4':     break;
default :cout<<"\nWrong Choice Entered !!\n\n";}
}while(choice!='4');
getch();
}
