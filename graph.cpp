/*
This code shows the implementation of the Graphs in C++ using adjacency lists method.
It works normally for nodes numbered as integers but can be very helpful where nodes are represented as char or string
since this is a template class it can be used with any data type.
*/
#include<bits/stdc++.h>
using namespace std;
template<class T,int size>
class graph{
  private:
      vector<int> grph[size+1];
      queue<int> q;
      map<int,bool> visited;
      int root;
      int currIndex;
      int directedEdges,unDirectedEdges;
      map<T,int> nodes;
      map<int,T> indices;
  public:
      graph():root(-1),currIndex(1),directedEdges(0),unDirectedEdges(0){}
      
      int getNumberOfNodes(){ 					//Returns number of nodes present
        return nodes.size();
      }
      
      int getRootIndex(){					//Returns index of root
        return root;
      }

      T getRootName(){ 						//Returns the name of root
        return indices.find(root)->second;
      }
	  
      int getIndex(T name){ 					//Returns index of any node using its name
        if(isNodeExist(name))
        return nodes.find(name)->second;
        return -1;
      }
	  
      T getNodeName(int index){ 				//Returns name of any node using its index
        if(indices.find(index)->second)
        return indices.find(index)->second;
        throw invalid_argument("Index Error\n");
      }
	  
      int getDirectedEdges(){ 					//Returns number of directed edges used
        return directedEdges;	
      }
	  
      int getUnDirectedEdges(){ 				//Returns number of undirected edges
        return unDirectedEdges;	
      }
	  
      void setRoot(T nodeName){ 				//Sets the root using the node name
        root = getIndex(nodeName);
      }
	  
      bool isDirected(){ 					 //Returns true if graph is directed
        if(unDirectedEdges == 0)
        return true;
        return false;
      }
	  
      void makeNode(T name){ 					//Creates new node
        if(currIndex <= size-1){
        nodes[name] = currIndex;
        indices[currIndex] = name;
		if(currIndex == 1)
		root = currIndex;
        currIndex++;
        }
        else
        throw invalid_argument("Overflow\n");
      }
	  
      bool isNodeExist(T name){ 						//Returns true if the node exists, using its name
        if(nodes.find(name)->second)
        return true;
        return false;
      }

      void insertDirectedEdge(T source,T destination){ 				//Inserts a Directed Edge using source and destination name
          directedEdges++;
          int inda = getIndex(source);
          int indb = getIndex(destination);
          if(inda == -1){
            makeNode(source);
            inda = getIndex(source);
          }
          if(indb == -1){
            makeNode(destination);
            indb = getIndex(destination);
          }
            grph[inda].push_back(indb);


      }
      void insertUnDirectedEdge(T source,T destination){ 			//Inserts an Undirected Edge using source and destination name
          unDirectedEdges++;
          int inda = getIndex(source);
          int indb = getIndex(destination);
          if(inda == -1){
            makeNode(source);
            inda = getIndex(source);
          }
          if(indb == -1){
            makeNode(destination);
            indb = getIndex(destination);
          }
            grph[inda].push_back(indb);
            grph[indb].push_back(inda);


      }
/*
* Returns a vector with nodes in the order of Breadth first Search
* Can be called without any argument, default will be root
* Can be called from a specific index
*/
       
      vector<T> bfs(int index = -1){	
	    if(index == -1)
        	index = root;
        vector<T> output;
        q.push(index);
         int tmp;
        visited[index] = true;
                       while(!q.empty()){
                            tmp = q.front();
                            q.pop();
                            output.push_back(getNodeName(tmp));
        for(int i = 0;i < grph[tmp].size();i++){
           if(visited.find(grph[tmp][i]) == visited.end()){
                            q.push(grph[tmp][i]);
                            visited[grph[tmp][i]] = true;
                                    }
                            }
                      }
                      visited.clear();
                      return output;
            }



};


   int main(){
    graph<char,10> gg;
    gg.insertUnDirectedEdge('a','b');
    gg.insertUnDirectedEdge('a','c');
    gg.insertUnDirectedEdge('b','d');
    gg.insertUnDirectedEdge('b','e');
    gg.insertUnDirectedEdge('c','f');
    gg.setRoot('a');
	gg.bfs();
}
