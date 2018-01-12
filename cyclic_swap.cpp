/* The following program is checked on gcc compiler to cyclically swap an array of numbers taken using command line
This program however, will not work on TurboC  */

#include<iostream>
#include<stdlib.h>
using namespace std; 							//swapping n numbers cyclically
void delayy(int count) 							//delay function self made
{
for(long double i=count*1000000;i>0;i--);
}
void cycswap(int *a, int n) 						//swap function
{
int tmp;
tmp=a[n-2];

for(int i=n-1;i>0;i--)
{
a[i]=a[i-1];
}
a[0]=tmp;
}	
int main(int argc, char **argv)				 		//command line arguments
{
int a[100],n;
n=argc;

for(int i=1;i<n;i++){							//converting char to int
a[i-1]= atoi(argv[i]);
}
char ch;
cout<<endl;
do
{
cycswap(a,n);
for(int i=0;i<n-1;i++)
{
cout<<a[i]<<endl;
delayy(10);
}

cout<<endl<<"Do you wanna repeat this cycle (Y/N)..??\t";		//repeating iterations
cin>>ch;
}while(ch == 'y' || ch=='Y');

return 0;
}
