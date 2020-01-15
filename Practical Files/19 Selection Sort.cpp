#include<iostream.h>
#include<conio.h>
void sel_sort(float A[], int N)
{  int i,j,c,M;  float Temp;
cout<<"Original Array : "<<endl;
for(c=0;c<N;c++)
cout<<A[c]<<'\t';   cout<<endl<<endl;
for(i=0;i<N-1;i++)
{ M=i;
for(j=i+1;j<N;j++)
{  if(A[M]>A[j])
 M=j;  }       if(M!=i)
{ Temp=A[M];  A[M]=A[i];    A[i]=Temp;    }
for(c=0;c<N;c++)
cout<<A[c]<<'\t';
cout<<endl;   }   }
void main()
{      float X[5]={3,1,7,4,2};
 sel_sort(X,5);
 getch();}
