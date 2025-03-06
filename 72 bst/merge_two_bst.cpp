//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    Node* inorderTOBst(int s , int e , vector<int> &in){
      //base case
      if(s>e) return NULL;
      
      int mid = (s+e)/2;
      Node* root = new Node(in[mid]);
      root->left = inorderTOBst(s,mid-1,in);
      root->right = inorderTOBst(mid+1,e,in);
      return root;
  }
    
    void inorder(Node* root, vector<int> &in){
        if(root==NULL) return;
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    
    vector<int> mergeSort(vector<int> &a, vector<int> &b){
        vector <int> ans(a.size()+b.size());
        
        int i = 0, j = 0;
        int k = 0;
        while(i< a.size() &&  j<b.size()){
            if(a[i]<=b[j]){
                ans[k++] = a[i];
                i++;
            }
            else{
                ans[k++] = b[j];
                j++;
            }
        }
        while(i<a.size()){
            ans[k++] = a[i];
            i++;
        }
        while(j<b.size()){
            ans[k++] = b[j];
            j++;
            
        }
        return ans;
        
        
    }

    void convertIntoSortedDLL(Node* root, Node* &head){
        // base case 
        if(root == NULL ) return;
      //right part krkr lao
        convertIntoSortedDLL(root->right,head);
        // root ko merge kro
        root->right = head;

        if(head != NULL) head ->left = root;
        // left part karke lao
        convertIntoSortedDLL(root->left, head);

    }
    // step 1
    Node* mergeLinkedList(Node* head1, Node* head2){
        Node* head = NULL;
        Node* tail = NULL;

        while(head1 != NULL && head2 != NULL){
            if(head1->data<= head2->data){
                if(head == NULL){
                    head = head1;
                    tail= head1;
                    head1= head1->right;
                }
                else{
                    tail->right= head1;
                    head1->left = tail;
                    tail = head1;
                    head1= head1->right;

                }
            }
            else{
                if(head == NULL){
                    head = head2;
                    tail= head2;
                    head2= head->right;
                }
                else{
                    tail->right= head2;
                    head2->left = tail;
                    tail = head2;
                    head2= head2->right;
                }
            }
        }
        while(head1 != NULL){
                    tail->right= head1;
                    head1->left = tail;
                    tail = head1;
                    head1= head1->right;
        }
        while(head2 != NULL) {
                    tail->right= head2;
                    head2->left = tail;
                    tail = head2;
                    head2= head2->right;
        }
        return head;
    }
int countNodes(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

    //sorted linked list to bst
    Node* sortedLLToBst(Node* &head, int n){
        //base
        if (n<=0 || head== NULL){
            return NULL;
        }
        Node* left = sortedLLToBst(head, n/2);
        Node* root = head;
        head = head->right;
        root->right = sortedLLToBst(head,n-n/2-1);
        return root;
    }

    Node* merge(Node *root1, Node *root2) {
        //- approach 1:  tc is O(m+n) and SC is O(m+n)
        // //step 1: store inorder
        // vector<int> bst1, bst2; 
        // inorder(root1,bst1);
        // inorder(root2,bst2);
        
        // // step 2 : merge two sorted array
        // vector<int> mergeArray = mergeSort(bst1,bst2);
        // int s =0;
        // int e = mergeArray.size()-1;
        // return inorderTOBst(s,e,mergeArray);

        //- approach 2: decrease space complexity to O(h1+h2) 
        // step 1: conv to sorted linkedlist/ or doubly linked list sc O(1)
        Node* head1= NULL;
        convertIntoSortedDLL(root1, head1);
        head1->left = NULL;

        Node* head2 = NULL;
        convertIntoSortedDLL(root2, head2);
        head2->left = NULL;
        // step 2: merge 2 sorted linked list 
        Node* head = mergeLinkedList(head1,head2);

        // step 3: sorted LL to bst;
        return sortedLLToBst(head, countNodes(head));
        
    }
    
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends