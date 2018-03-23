/* bfs implemented using iteration 
ip - 
9
 1 2
 1 3
 1 5
 2 4
 2 6
 3 5
 3 4
 4 6
 5 6
 */
#include<bits/stdc++.h>
using namespace std;
bool vis[10] = {false};
int level[10];
vector<int> a[10];
queue<int> q;
void bfs(int x){
  level[x] = 0;
  q.push(x);
  vis[x] = true;
  while(!q.empty()){
    int tmp = q.front();
    q.pop();
    for(int i=0;i<a[tmp].size();i++){
      if(!vis[a[tmp][i]]){
        q.push(a[tmp][i]);
        vis[a[tmp][i]] = true;
        level[a[tmp][i]] = level[tmp]+1;
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
   bfs(1);
   for(int i=1;i<=6;i++)
   cout<<i<<" : "<<level[i]<<endl;
 
}