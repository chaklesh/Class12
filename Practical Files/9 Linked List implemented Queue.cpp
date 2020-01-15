#include<iostream.h>
#include<stdio.h>
#include<conio.h>
struct node
{ char name[20];
int marks;
node *next;
};
class queue
{ node *front;
node *rear;
public:
queue(){front=rear=NULL;}
void addq(); void delq();  void display();
~queue();
};
void queue::addq()
{ node *temp;   temp=new node;  gets(temp->name);
cin>>temp->marks;   temp->next=NULL;
if(front!=NULL)
{   rear->next=temp;
rear=temp;    }
else
front=rear=temp;  }
void queue::delq()
{  if(front==NULL)
cout<<"Underflow!!Queue is empty\n";
else      {  node *temp;
temp=front;
front=front->next;    delete(temp);
if(front==NULL)rear=NULL; }  }
void queue::display()			
{   if(front==NULL)
cout<<"Queue is empty\n";
else
{  node *temp;   temp=front;
while(temp!=NULL)
{cout<<temp->name;
cout<<temp->marks;
temp=temp->next;    }  }  }
 queue::~queue()
 {  node *temp;
 while(front!=NULL)
 {  temp=front;    front=front->next;  delete(temp);   }  }
 void main()
 {   queue q;    int ch;
 do
 {   cout<<"1.ADD\n2.DEL\n3.DISPLAY\n4.QUIT\n";
 cin>>ch;
switch(ch)
 {   case 1: q.addq();break;
 case 2: q.delq();break;
 case 3: q.display();break;
 case 4: break; } } while(ch!=4); getch();}
