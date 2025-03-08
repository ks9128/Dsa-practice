#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1; // is empty heap start from arr[1]
            size = 0;
        }
        // max heap
        void insert(int data){  //O(logn)
            size = size +1;
            int index = size;
            arr[index] = data;
            while(index> 1){
                int parent = index/2;
                if(arr[index]>arr[parent]){
                    swap(arr[index],arr[parent]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }
        
        // delete root element
        void deletion(){
            if(size == 0){
                cout<< "nothing to delete" <<endl;
                return;
            }
                //step 1 copy last node to first node (ie root)
                arr[1] = arr[size]; 
            // step 2 remove last node
            size--;
            // step 3: progate root node to correct positon  //o(logn)
            int i =1;
            while(i<size){
                int leftindex = 2*i;
                int rightindex = 2*i+1;

                if(leftindex <size && arr[i]< arr[leftindex]){
                    swap(arr[i],arr[leftindex]);
                    i = leftindex;
                }
                else if(rightindex<size && arr[i] < arr[rightindex]){
                    swap(arr[i],arr[rightindex]);
                    i = rightindex;
                }
                else {
                    return ;
                }
            }
        }

        void print(){
            for(int i = 1; i<= size; i++){
            cout<<arr[i]<<" ";
            } cout<<endl;
        }

};


//# heapyfy algorithm part (inside of for loop in main fn) : this part tc= O(logn)
//# 1 based indexing
void heapify(int arr[] , int n , int i){  // put i-th element at correct position
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if( left <= n && arr[largest]< arr[left]){
        largest = left;
    }
    if( right<= n && arr[largest]< arr[right]){
        largest = right;
    }

    if(largest!=i){   // means i is updated
        swap (arr[largest], arr[i]);
        heapify(arr,n,largest); // now put largest at correct position
    }
}
// # for zero based idexing
void heapifyzerobased(vector<int> &arr , int n , int i){  // put i-th element at correct position
    int largest = i;
    int left = 2*i+1;
    int right = 2*i + 2; 

    if( left < n && arr[largest]< arr[left]){
        largest = left;
    }
    if( right< n && arr[largest]< arr[right]){
        largest = right;
    }

    if(largest!=i){   // means i is updated
        swap (arr[largest], arr[i]);
        heapify(arr,n,largest); // now put largest at correct position
    }
}
//- Heap Sort
void heapSort(int arr[], int n){
    int size = n;
    
    while(size>1){
        //step 1: swap and dec size
        swap(arr[size],arr[1]);
        size--;

        //step 2: heapify call (to make root at correct position)
        heapify(arr, size,1);
    }
}

int main(){
    heap h;
    h.insert(70);
    h.insert(30);
    h.insert(50);
    h.insert(28);
    h.insert(90);
    h.print();

    h.deletion();
    h.print();

    //! heapify algorithm  

    int arr[6] = {-1,54,53,55,51,52};
    int n = 5;
    for(int i = n/2 ; i>=1;i--){
        heapify(arr,n,i);
    }

    cout<<"printing the  array now"<<endl;
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 
    //- sort a heap tc (o(logn)) -> build heap + sort;
    heapSort(arr,n); 

    cout<<"printing the sorted array now"<<endl;
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //! using stl
    cout<<"using priprity queue to make heap"<<endl;
    //- using priority queue - simply create heap 
    //? by default is max heap

    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"top element" <<pq.top()<<endl;
    pq.pop();
    cout<<"top element now"<< pq.top()<<endl;
    cout<<"size of pq "<<pq.size()<<endl;
    if(pq.empty()) cout<<"pq is empty"<<endl;
    else cout<<"pq is not empty"<<endl;

    cout<<endl<<"min heap"<<endl;
    //- create min heap using priority queue
    priority_queue<int,vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"top element" <<minheap.top()<<endl;
    minheap.pop();
    cout<<"top element now"<< minheap.top()<<endl;
    cout<<"size of pq "<<minheap.size()<<endl;
    if(minheap.empty()) cout<<"pq is empty"<<endl;
    else cout<<"pq is not empty"<<endl;

    return 0;
}