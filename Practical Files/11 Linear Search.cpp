#include<iostream.h>
#include<conio.h>
int Lsearch(int[],int,int);
int main()
{int AR[50],ITEM,N,index;
cout<<"enter array";
cin>>N;
cout<<"enter array element";
for(int i=0;i<N;i++)
{cin>>AR[i];   }
cout<<"enter element search";
cin>>ITEM;
index=Lsearch(AR,N,ITEM);
if(index==-1)
cout<<"element not found";
else
cout<<"elementfound at index:"<<index<<",position:"<<index+1<<endl;
return 0;
}int Lsearch(int AR[],int size,int item)
{  for(int i=0;i<size;i++)
{ if(AR[i]==item)
return i;
}return-1;
getch();
}
