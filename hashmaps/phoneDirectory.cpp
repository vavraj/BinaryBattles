#include <iostream>
#include <vector>

using namespace std;
class trieNode
{
public:
    char data;
    int childCount;
    trieNode *children[26];
    bool isTerminal;
    trieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class trie
{
public:
    trieNode *root;
    trie()
    {
        root = new trieNode('\0');
    }
    trie(char ch) { root = new trieNode(ch); }

    void insertUtil(trieNode *root, string word)
    {
        // base cases
        // if word ends
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assume that all the words are in CAPS
        int index = word[0] - 'a';
        trieNode *child;

        if (root->children[index] != NULL)
        { // if word already present
            child = root->children[index];
        }
        else
        { // if word not present
            child = new trieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestion(trieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            trieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestion(string queryStr)
    {
        trieNode *prev = root;
        vector<vector<string>> output;
        string prefix;
        for (int i = 0; i < queryStr.length(); i++)
        {
            char lastchar = queryStr[i];
            prefix.push_back(lastchar);

            trieNode *curr = prev->children[lastchar - 'a'];

            if (curr == NULL)
            {
                break;
            }

            vector<string> temp;
            printSuggestion(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    //    Write your code here.
    trie *t = new trie();
    for (int i = 0; i < contactList.size(); i++)
    {
        string temp = contactList[i];
        t->insertWord(temp);
    }
    return t->getSuggestion(queryStr);
}