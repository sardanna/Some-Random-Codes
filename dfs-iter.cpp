/* DFS implemented using iteration on a graph represented using adjacency list */

#include<bits/stdc++.h>
using namespace std;
bool vis[10] = {false};
 vector<int> a[10];
stack<int> s;
 void dfs(int x){
   s.push(x);
   vis[x] = true;
   while(!s.empty()){
     int tmp = s.top();
     s.pop();
     cout<<tmp<<endl;
     
     
     for(int j = 0;j<a[tmp].size();j++){
       if(!vis[a[tmp][j]])
       {
         vis[a[tmp][j]] = true;
       s.push(a[tmp][j]);
       }
     }
   }
 }
int main()
{
 
  int n,i,j;
  cin>>n;
  for(int x=0;x<n;x++){
    cin>>i>>j;
    a[i].push_back(j);
    a[j].push_back(i);
  }
   dfs(1);
 
}