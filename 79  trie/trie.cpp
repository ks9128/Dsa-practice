#include<iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTernminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0; i<26 ; i++){
                children[i] = NULL;
            }
            isTernminal= false;
        }
};
class Trie{
    public:
        TrieNode* root;

        Trie(){//constr;
            root =new TrieNode('\0');// null char initialize
        }

        void insertUtil(TrieNode* root, string word){
            // base case
            if(word.length() == 0){
                root->isTernminal = true;
                return;  // Add this return statement
            }
            // assumption: words are capital
            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root->children[index] != NULL){
                //go to next node
                child = root->children[index];
            }//absent
            else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // recursion
            insertUtil(child, word.substr(1)); // word except first char
        }
        void insertWord(string word){  // tc o(L) 
            insertUtil(root,word);

        }
        bool searchUtil(TrieNode* root, string word){
            //base case
            if(word.length() == 0){
                return root->isTernminal;
            }
            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root->children[index]!= NULL){
                child= root->children[index];
            }
            else{
                return false;
            }
            return searchUtil(child, word.substr(1));
        }
        bool searchWord(string word){
            return searchUtil(root,word);
        }
};
// remove word and space optimizre ??  .



int main(){
    Trie *t = new Trie();

    t->insertWord("ABCD");
    t->insertWord("DO");
    t->insertWord("TIME");
    
    cout<<"Present or Not ABCD: " << t->searchWord("ABCD")<<endl;  // Should print 1
    cout<<"Present or Not DO: " << t->searchWord("DO")<<endl;      // Should print 1
    cout<<"Present or Not ABC: " << t->searchWord("ABC")<<endl;    // Should print 0

    delete t;  // Don't forget to free memory
    return 0;
}