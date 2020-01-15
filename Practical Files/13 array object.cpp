#include<iostream.h>
#include<conio.h>
class Item { int itemno;
float price ;
public :
void getdata(int i,float j)
{  itemno=i;    price=j;
}
void putdata(void)
{cout<<"itemno:" <<itemno; cout<<"price:" <<price;}};
const int size=10;
Item order[size];
int main()
{   int a,ino ; float cost;
for(a=0;a<size;a++)
{  cout<<"Enter itemno & price for item"<<(a+1);
cin>>ino>>cost;
order[a].getdata(ino,cost); }
for(a=0;a<size;a++)
{  cout<<"Item"<<(a+1);
order[a].putdata();
} return 0; getch(); }
