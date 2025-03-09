//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
#include <vector>
#include <queue>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends

//User function Template for C++


class Solution
{
    public:
    
    class Node{
        public:
        int data;
        int i ;
        int j;
        Node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
            
        }
    };
    class compare{
        public:
            bool operator()(Node* a, Node* b){
                return a->data > b->data;
            }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node* , vector<Node*> , compare > minHeap;
        //step 1: sare k arraysfirst element insert krne h
        for(int i = 0; i<K; i++){  // tc - klogk  sc -o(k)
            Node* temp = new Node(arr[i][0],i,0);
            minHeap.push(temp);
        }
        
        vector <int> ans;
        // step 2:
        while(minHeap.size() > 0){     // tc - (N*k-k)logk sc -o(n*k)
            Node* temp = minHeap.top();
            ans.push_back(temp->data);
            minHeap.pop();
            
            int i = temp->i;
            int j= temp->j;
            
            if(j+1<arr[i].size()){  // next element is lie inside arr
                Node* next = new Node(arr[i][j+1],i,j+1);
                minHeap.push(next);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends