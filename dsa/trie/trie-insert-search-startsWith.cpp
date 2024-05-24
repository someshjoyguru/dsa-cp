#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag =false;

    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
};
// insert - search - startsWith
class Trie{
    private:
    Node * root = new Node();

    public:
    void insert(string word){
        int n = word.size();
        Node* node=root;
        for (int i=0; i<n; i++){
            if (node->containsKey(word[i])){
                // put
                node->links[word[i]-'a']=new Node();
            }
            // get
            node=node->links[word[i]-'a'];
        }
        // node -> setEnd()
        node->flag=true;
    }

    bool search(string word){
        Node* node =root;
        int n = word.size();
        for (int i=0; i<n; i++){
            if (node->links[word[i]-'a']==NULL){
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        // isEnd()
        return node->flag;
    }

    bool startsWith(string word){
        Node* node =root;
        int n = word.size();
        for (int i=0; i<n; i++){
            if (node->links[word[i]-'a']==NULL){
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        return true;
    }

};

int main(){
    return 0;
}