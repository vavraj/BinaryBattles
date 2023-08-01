#include<iostream>
using namespace std;

class trieNode{
    public:
    char data;
    trieNode *children[26];
    bool isTerminal;
    trieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;

    }
    ~trieNode()
    {
        for(int i=0 ;i<26;i++)
        {
            delete children[i];
        }
        
    }
};

class trie{
    public:
    trieNode*root;
    trie()
    {
        root=new trieNode('\0');
    }



    void insertUtil(trieNode*root,string word)
    {
    // base cases
        // if word ends
        if(word.length()==0)
        {
            root->isTerminal=true;
            return ;
        }
        
        // assume that all the words are in CAPS
        int index=word[0]-'A';
        trieNode*child;

        if(root->children[index]!=NULL)
        {//if word already present
            child=root->children[index];
        }
        else
        {//if word not present 
            child =new trieNode(word[0]);
            root->children[index]=child;
        }

    // recursion
        insertUtil(child,word.substr(1));
    }



    void insertWord(string word)
    {
        insertUtil(root,word);
    }



    bool searchUtil(trieNode*root,string word)
    {
    // base cases
        if(word.length()==0)
        {
            return root->isTerminal;
        }
        trieNode*child;
        int index=word[0]-'A';
        if(root->children[index]!=NULL)
        {//present
            child=root->children[index];
        }
        else{//not present
            return false;
        }

    // recursion call
        return searchUtil(child,word.substr(1));
    }
   
   
    bool search(string word)
    {
        return searchUtil(root,word);
    }
   
   
   
   
    void removeUtil(trieNode*root,string word)
    {
    // base cases
        if(word.length()==0)
        {
            root->isTerminal=false;
            return;
        }
        trieNode*child;
        int index=word[0]-'A';
        if(root->children[index]!=NULL)
        {//present
            child=root->children[index];
            
        }
        else{//not present
            cout<<"Word not present";
            return;
        }

    // recursion call
        removeUtil(child,word.substr(1));
    // free space
        int flag=0;
        for(int i=0;i<26;i++)
        {
            if(child->children[i]!=NULL)
            {
                flag++;
                break;
            }
        }
        if(flag==0)
        {
            child=NULL;
            delete child;
        }
    }
    void remove(string word)
    {
        removeUtil(root,word);
    }

};

int main()
{ 
    trie *t=new trie();
    t->insertWord("ABCD");
    t->insertWord("TIME");
    t->insertWord("TI");
    t->insertWord("DONE");
    t->insertWord("VAIBHAV");
    string word;
    cout<<"enter word to be searched:: ";
    cin>>word;
    if(t->search(word))
    {
        cout<<"found ";
    }
    else{
        cout<<"not found ";
    }
    t->remove("TIME");
    cout<<"enter word to be searched:: ";
    cin>>word;
    if(t->search(word))
    {
        cout<<"found ";
    }
    else{
        cout<<"not found ";
    }
    
    return 0;
}