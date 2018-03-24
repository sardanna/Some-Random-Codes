template <class T,int size>
class segTree
{
  private:
       long start,end;
       T tree[2*size-1];
       
  public:
        segTree():start(1),end(size){}
        
		/*
		* Override this method as per your requirement
		* Currently it is set for sum of the range
		*/
		
        T process(T a,T b){                          
            return (a+b);
        }
        
        /*
		* This method will build the segment tree
		* Call this function as obj.buildTree(arr) where arr represents the base address of input array
		*/
        void buildTree(T *arr,long st = -1,long en = -1 ,long index = 1){
            if(st == -1)
            st = start;
            if(en == -1)
            en = end;
            if(st == en){
            tree[index] = arr[st-1];
            return;
            }
            int mid = (st+en)/2;
            buildTree(arr,st,mid,index*2);
            buildTree(arr,mid+1,en,index*2 +1);
            tree[index] = process(tree[index*2],tree[index*2 + 1]);
      }
      
      
      int overlap(long st,long en,long qstart,long qend){
        if(st >= qstart && en <= qend)              //Full Overlap
            return 2;
        if(st > qend || en < qstart)                //No Overlap
            return 0;
        return 1;                                   //Partial Overlap
      }
      
      /*
	  * Override according to your requirement
	  * Contradict method returns a value which doesn't affects the answer
	  * when no overlap is found
	  * for sum we return 0
	  * for max in the range it can be a minimum number and vice-versa
	  */
      T contradict(){                               
            return 0;
      }
      
      /* 
	  * This method will return the result according to the range provided as query
	  * for range x,y call this function as obj.getResult(x,y)
	  */
      T getResult(long qstart,long qend,long st = -1,long en = -1,long index = 1){
        if(st == -1)
              st = start;
        if(en == -1)
              en = end;
        int over = overlap(st,en,qstart,qend);
        switch(over){
          case 0:                                                   //No Overlap
              return contradict();
          case 1:                                                   //Partial Overlap
              int lt,rt,mid;
              mid = (st+en)/2;
              lt = getResult(qstart,qend,st,mid,index*2);
              rt = getResult(qstart,qend,mid+1,en,index*2 + 1);
              return process(lt,rt);
          case 2:                                                   //Full Overlap
              return tree[index];
        }
      }
	  /*
	  * Update method will be used if some values in the original array are to be changed
	  * Call this method as obj.update(NewValue,Index)
	  */
	  void update(int value,int qstart,int qend = -1,int st = -1,int en = -1,int index = 1){
        if(st == -1)
              st = start;
        if(en == -1)
              en = end;
        if(qend == -1)
              qend = qstart;
        int over = overlap(st,en,qstart,qend);
        switch(over){
          case 0:
              return;
          case 1:
              update(value,qstart,qend,st,(st+en)/2,index*2);
              update(value,qstart,qend,(st+en)/2 + 1,en,index*2 + 1);
              tree[index] = process(tree[index*2],tree[index*2 + 1]);
              return;
          case 2:
              tree[index] = value;
              return;
        }
      }
};
int main(){
  int arr[] = {1,2,3,4,5,6,7,7};
  const int n = sizeof(arr)/sizeof(int);
  segTree<int,n> s;
  s.buildTree(arr);
  cout<<s.getResult(7,8)<<endl;
  s.update(8,8);
  cout<<s.getResult(7,8);
  
}