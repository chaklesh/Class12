#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
int i,N;
float X,T,S=0;
cout<<"Enter X and N\n";
cin>>X>>N;
  T=X;S=T;
for( i=2; i<=N; i++)
{
  T=T*(-1)*X*X/((2*i-1)*(2*i-2));
 S=S+T;
}
  cout<<"The sum is "<<S;  
  getch();
}
