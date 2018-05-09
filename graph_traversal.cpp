/*Following code can be used to apply graph traversals on a graph implemented in the form of adjacency list using vectors
* The nodes of the graph can be of any data type.
* Function will return a vector containing nodes in the order they are traversed based on the algorithm used
* Use sample input and draw the input graph for better understanding
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
template <class T>
class GraphTraversal{
  private:
        queue<T> q;                                                                        //Queue for BFS
        vector<T> op;                                                                      //Output vector which will be returned
        map<T,bool> vis;                                                                   //Keep track of visited nodes
  public:
        GraphTraversal(){}
        vector<T> breadthFirstSearch(T root, vector<T> graph[]){                            //Pass the adjacency list and root element
                  q.push(root);
                  T tmp;
                  vis[root] = true;
                  while(!q.empty()){
                        tmp = q.front();
                        q.pop();
                        op.push_back(tmp);

                        for(int i = 0;i < graph[tmp].size();i++){
                                if(vis.find(graph[tmp][i]) == vis.end()){
                                q.push(graph[tmp][i]);
                                vis[graph[tmp][i]] = true;
                                }
                        }
                  }
                  vis.clear();
                  return op;
        }
  
};
int main(){
  vector<int> a[10];
  int n,i,j;
  cin>>n;
  for(int x=0;x<n;x++){
        cin>>i>>j;
        a[i].push_back(j);
        a[j].push_back(i);
  }
  GraphTraversal<int> gg;
  vector<int> b = gg.breadthFirstSearch(1,a);                                             //Function call for a vector with int type nodes
  for(int i = 0;i<b.size();i++)
  cout<<b[i]<<endl;
  
}
