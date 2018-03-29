/*
* Eertree class consisting of basic functions on palindromic tree
*/
#define maxsize 1000											//change according to need, should be atleast n+3 where n is the size of string
class Eertree{
	
  struct node{
    int suffEdg,start,end,insEdg[26],len; 							//structure of eertree node
  }root1,root2;														//dummy nodes
  
  node tree[maxsize];											    //tree array
  int currInd,sz,mx;
  string s;
  
  public:
  Eertree(string s){												//initializing with the string and data for dummy nodes
    this->s = s;
    root1.len = -1;
    root1.suffEdg = 1;
    root2.len = 0;
    root2.suffEdg = 1;
    sz  = 2;														//size of array (no. of palindromes)
    currInd = 1;
    tree[1] = root1;
    tree[2] = root2;
    mx = 2;															//longest palindromic substring
  }
  
  void addLetter(int ind){											//adding character at ind index to the tree
    int tmp = currInd;
  while(true){
    int currLen = tree[tmp].len;
    if(ind - currLen >=1 && s[ind] == s[ind - currLen - 1])
    break;
    tmp = tree[tmp].suffEdg;
  }
  if(tree[tmp].insEdg[s[ind] - 'a'] != 0){
    currInd = tree[tmp].insEdg[s[ind] - 'a'];
    return;
  }
  sz++;
  tree[tmp].insEdg[s[ind] - 'a'] = sz;
  tree[sz].len = tree[tmp].len + 2;
  tree[sz].end = ind;
  tree[sz].start = ind - tree[sz].len + 1;
  tmp = tree[tmp].suffEdg;
  currInd = sz;
  if(tree[currInd].len == 1){
    tree[currInd].suffEdg = 2;
    
    return;
  }
  while(true){
    int currLen = tree[tmp].len;
    if(ind - currLen >= 1 && s[ind] == s[ind - currLen - 1])
    break;
    tmp = tree[tmp].suffEdg;
  }
  tree[currInd].suffEdg = tree[tmp].insEdg[s[ind] - 'a'];
  if(tree[currInd].len > tree[mx].len){
    mx = currInd;
  }
  }
  void buildTree(){
    for(int i=0;i<s.length();i++)
    addLetter(i);
  }
  
  void printAll(){
    for(int i=3;i<=sz;i++){
      cout<<s.substr(tree[i].start,tree[i].end - tree[i].start + 1);
      cout<<endl;
    }
  }
  
  string longest_pal(){														//return longest palindromic substring
    return s.substr(tree[mx].start,tree[mx].end-tree[mx].start+1);
  }
  
  int count(){															    //return number of palindromic substrings
    return sz-2;
  }
};
/*
  string s;
  cin>>s;
  Eertree ob(s);
  ob.buildTree();
  ob.printAll();
  cout<<ob.longest_pal()<<endl;
  cout<<ob.count()<<endl;
*/