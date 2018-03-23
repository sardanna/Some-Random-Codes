/*DFS implemented using recursion on a graph represented via adjacency list */
#include<bits/stdc++.h>
using namespace std;
bool vis[10] = {false};
 vector<int> a[10];
 void dfs(int x){
   vis[x] = true;
   cout<<x<<endl;
   for(int i = 0;i<a[x].size();i++){
     if(!vis[a[x][i]] && a[a[x][i]].size()>0)
     dfs(a[x][i]);
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
   for(int x=0;x<10;x++){
    if(!vis[x] && a[x].size()>0)
    dfs(x);
  }
 
}