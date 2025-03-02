#include <iostream>
#include <queue>
using namespace std;

//# notes : inorder of BST is sorted 


class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }


};



// preorder
// NLR 
void preOrder(Node* root){
    if (root==NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

//- main part of bst making
//! tc is O(log(n)) 
Node* insertInBst(Node* root, int data){
    // base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->left = insertInBst(root->left,data);
    }
    else{
        root->right = insertInBst(root->right, data);
    }
    return root;
}

void levelOrderTraversal(Node* root){

    queue <Node* > q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //purana level traverse ho gya h
            cout<<endl;
            
            if(!q.empty()){
                // q stillhas child nodes
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }

    }

}

void insertElement(Node* &root){
    
    int data;
    cin>> data;

    while(data != -1){
        root = insertInBst(root,data);
        cin>> data;
    }
}

//- min element of bst
Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

//- max element of bst
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
int main(){

    Node* root = NULL;

    cout<<"enter the values"<<endl;
    
    insertElement(root);

    cout<<"printing the bst"<<endl;
    levelOrderTraversal(root);

    cout<<"preorder traversal: ";
    preOrder(root);

    cout<<endl;

    cout<<"min value is:" <<minVal(root)->data << endl;
    cout<< "max vlaue is :" << maxVal(root)->data << endl;
}
