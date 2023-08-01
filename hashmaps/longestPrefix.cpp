#include<iostream>
using namespace std; 
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans="";
    for(int i=0;i<arr[0].size();i++)
    {
        char ch=arr[0][i]; 
        bool match=true;
        for(int j=0;j<n;j++)
        {
            if(arr[j].size()<i || ch!=arr[j][i])
            {
                match=false;
                break;
            }
            
        }
        if(match==false)
        {
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}






// using trie
class trieNode {
public:
  char data;
  int childCount;
  trieNode *children[26];
  bool isTerminal;
  trieNode(char ch) {
    data = ch;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    childCount=0;
    isTerminal = false;
  }
 
  
};

class trie {
public:
  trieNode *root;
  trie(char ch) { root = new trieNode(ch); }

  void insertUtil(trieNode *root, string word) {
    // base cases
    // if word ends
    if (word.length() == 0) {
      root->isTerminal = true;
      return;
    }

    // assume that all the words are in CAPS
    int index = word[0] - 'a';
    trieNode *child;

    if (root->children[index] != NULL) { // if word already present
      child = root->children[index];
    } else { // if word not present
      child = new trieNode(word[0]);
      root->childCount++;  
      root->children[index] = child;
    }

    // recursion
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word) { 
      insertUtil(root, word); 
      }

  void lcp(string str,string &ans)
  {
      for(int i=0;i<str.length();i++)
      {
          char ch=str[i];
          if(root->childCount==1)
          {
              ans.push_back(ch);
              int index=ch-'a';
              root=root->children[index];
          }
          else{
              break;
          }
          if(root->isTerminal)
          {
              break;
          }
      }
  }
};

string longestCommonPrefix(vector<string> &arr, int n) {
  // Write your code here
  string ans="";
  string first=arr[0];
  trie *t=new trie('\0');
  for (int i = 0; i < n; i++) { 
      t->insertWord(arr[i]);
      }
    
  t->lcp(first, ans);

  return ans;
}
