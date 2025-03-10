//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
#define N 1000


// } Driver Code Ends

// you are required to complete this function 
// function should print the required range
#include<limits.h>
#include<queue>
class Solution{
    public:
    class node{
    public:
        int data;
        int row;
        int col;
        node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data> b->data;
        }
};
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
          priority_queue<node*, vector<node*>,compare> minHeap;

    int mini = INT_MAX;
    int maxi = INT_MIN;
    // step1: create a min heap for starting element of each list and tracking mini/maxi val
    for(int i = 0 ;i< k ; i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element,i,0));
    }

    int start= mini , end = maxi;
    // process range
    while(!minHeap.empty()){
        // mini fetch
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;
        // range or answer updation
        if(maxi-mini < end- start){
            start = mini;
            end= maxi;
        }
        // next element exists
        if(temp->col + 1 < n){
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1],temp->row, temp->col+1));
        }
        else{
            // next element dont exist
            break;
        }
    }
    return {start,end};

    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    
cout << "~" << "\n";
}   
	return 0;
}


// } Driver Code Ends