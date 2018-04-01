#include<bits/stdc++.h>
using namespace std;
int sum(int a[],int n,int *start,int *end){
  int max_so_far = INT_MIN,max_ending_here = 0,tmp = 0;
  for(int i = 0;i<n;i++){
    max_ending_here = max_ending_here + a[i];
    if(max_ending_here < 0){
      max_ending_here = 0;
      tmp = i+1;
    }
    else if(max_so_far < max_ending_here){
      max_so_far = max_ending_here;
      *start = tmp;
      *end = i;
    }
  }
  return max_so_far;
}
int main(){
  int a[10],n,start = 0,end = 0;
  cin>>n;
  for(int i = 0;i<n;i++)
    cin>>a[i];
  cout<<endl<<sum(a,n,&start,&end)<<endl<<start<<" "<<end;
}
