#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode * children[26];
    bool isTerminal ;
    TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i<26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie{
    public:
   
    TrieNode * root;
     Trie(){
        root = new TrieNode('\0');
    }
    void insertUtils(TrieNode * root , string word){
         //Base case
         if(word.length() == 0){
            root->isTerminal = true;
            return ;
         }
         int index = word[0] - 'A';
         TrieNode * child;
         //Present 
         if(root->children[index] != NULL){
            child = root->children[index];
         }//Absent
         else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
         }
         // Recursion
         insertUtils(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtils(root,word);
    }
    bool searchUtils(TrieNode * root,string word){
       // Base case
       if(word.length()==0){
         return root->isTerminal;
       }
       int index = word[0] - 'A';
       TrieNode * child;
       //Present 
       if(root->children[index] != NULL){
          root->children[index] = child;
       }else{
           //Absent
           return false;
       }
       //Recursion 
      searchUtils(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtils(root,word);
    }

};
int main(){
    Trie *t = new Trie();
    t->insertWord("VISHAL");
    t->insertWord("SHARMA");
    cout<<"Present or not " << (t->searchWord("VISHAL"))<<endl;
    return 0;
}