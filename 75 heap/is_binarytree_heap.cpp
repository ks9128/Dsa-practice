
class Solution {
    public:
      int nodesintree(Node* root){
          if(root==NULL) return 0;
          
          int ans = 1  + nodesintree(root->left) + nodesintree(root->right);
          return ans;
      }
      bool isCBT(struct Node* root, int i, int cnt){
          if(root == NULL) return true;
          if(i >= cnt) return false;
          // starting from i = 0 heap
          else{
          bool left = isCBT(root->left, 2*i+1 , cnt);
          bool right = isCBT(root->right, 2*i+2, cnt);
          return left && right;
          }
      }
      bool isMaxOrder(struct Node* root){
          //3 cases 
          //no child node
          if(root->left == NULL && root->right == NULL){
              return true;
          } 
          //1 child ie left only (as its heap)
          if(root->right == NULL){
              return (root->data > root->left->data);
          }
          // both child nodes
          else{
              bool left= isMaxOrder(root->left);
              bool right = isMaxOrder(root->right);
              
              return (left && right && 
              (root->data > root->left->data && root->data > root->right->data));
          }
              
        }
      
      bool isHeap(struct Node* tree) {
          // code here
          int index = 0;
          int totalnodes = nodesintree(tree);
          if(isCBT(tree,index,totalnodes) && isMaxOrder(tree)){
              return true;
          }else{
              return false;
          }
      }
  };