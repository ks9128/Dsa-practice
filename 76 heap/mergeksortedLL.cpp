//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends

/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
  
  class compare{
      public:
        bool operator()(Node* a , Node* b){
            return a->data > b->data;
        }
  };
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node* , vector<Node*> , compare> minHeap;  //sc k
        int k = arr.size() ;
        if(k== 0) return NULL;
        
        //step 1
        for (int i =0 ;i<k;i++){ // tc klogk
            if(arr[i] != NULL){
                minHeap.push(arr[i]);
            }
        }
        //step 2
        Node* head  = NULL;
        Node* tail = NULL;
        
        while(minHeap.size() > 0){ //tc (n*k-k) logk = n*klogk 
            Node* top = minHeap.top();
            minHeap.pop();
            
            if(top->next != NULL){
                minHeap.push(top->next);
            }
            if(head  == NULL ){ //LL is empty
                head = top;
                tail= top;
            }
            else{ // insert in LL
                tail->next = top;
                tail= top;
            }
        }
        return head;
    }
};



//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends