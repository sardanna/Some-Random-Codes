#include<bits/stdc++.h>
using namespace std;
template <class T>
class minHeap
{
  private:
      vector<T> heap;
      int size;
  public:
      minHeap():size(0){}                                                           //Initial size is 0
      int getSize(){                                                                //Returns current size of heap
        return size;
      }
      T getMin(){                                                                   //Returns maximum element of current heap
        return heap[0];
      }
      int getLeftChildIndex(int parent_index){                                      
        return 2*parent_index + 1;
      }
      int getRightChildIndex(int parent_index){
        return 2*parent_index + 2;
      }
      int getParentIndex(int child_index){
        return (child_index - 1)/2;
      }
      bool hasLeftChild(int parent_index){
        if(getLeftChildIndex(parent_index) < size)
        return true;
        return false;
      }
      bool hasRightChild(int parent_index){
        if(getRightChildIndex(parent_index) < size)
        return true;
        return false;
      }
      bool hasParent(int child_index){
        if(getParentIndex(child_index) >= 0)
        return true;
        return false;
      }
      T getLeftChild(int parent_index){
        return heap[getLeftChildIndex(parent_index)];

      }
      T getRightChild(int parent_index){
        return heap[getRightChildIndex(parent_index)];
      }
      T getParent(int child_index){
        return heap[getParentIndex(child_index)];
      }
      void heapifyDown(int index){                                                     //Used when an element is deleted from within
        int l = getLeftChildIndex(index);
        int r = getRightChildIndex(index);
        int smallest_element_index = 0;
        if(l < size and heap[l] < heap[index])
        smallest_element_index = l;
        else
        smallest_element_index = index;
        if(r < size and heap[r] < heap[smallest_element_index])
        smallest_element_index = r;
        if(smallest_element_index != index){
          swap(heap[smallest_element_index],heap[index]);
          heapifyDown(smallest_element_index);
        }
      }
      void heapifyUp(int index){                                                        //Used when new element is inserted at end
        while(hasParent(index) and getParent(index) > heap[index]){
          swap(heap[getParentIndex(index)],heap[index]);
          index = getParentIndex(index);
        }
      }
      void insert(T x){
        heap.push_back(x);
        heapifyUp(size);
        size++;
      }
      T extractMinimum(){                                                               //Removes the current maximum
        T tmp = getMin();
        swap(heap[0],heap[size - 1]);
        size-=1;
        heapifyDown(0);
        return tmp;
      }
      void removeKey(int index){                                                        //Removes element from index, throws invalid_argument
        if(index >= size or index < 0)
        throw invalid_argument("Index out of bounds");
        heap[index] = getMin() - 1;
        heapifyUp(index);
        extractMinimum();
      }
      void removeValue(T value){                                                        //Removes element with the value, throws invalid_argument
        int index = -1;
        for(int i = 0;i<size;i++){
          if(heap[i] == value){
            index = i;
            break;
          }
        }
        removeKey(index);
      }
      void printHeap(){
        for(int i=0;i<size;i++)
        cout<<heap[i]<<" ";
        cout<<endl;
      }
};
int main(){
        minHeap<char> mh;                                                                //Can be initialized as follows with any data type as required
        mh.insert('d');
        mh.insert('b');
        mh.insert('c');
        mh.printHeap();
        try{
                mh.removeValue('d');
        }
        catch(const invalid_argument& e){                                           //Catching the exception thrown and using in-built what() function
                cerr<<e.what()<<endl;
        }
        mh.printHeap();
}
