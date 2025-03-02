#include <iostream>
#include <queue>
using namespace std;

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
int main(){

    Node* root = NULL;

    cout<<"enter the values"<<endl;
    
    insertElement(root);

    cout<<"printing the bst"<<endl;
    levelOrderTraversal(root);
}
