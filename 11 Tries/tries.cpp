#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminate;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminate = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
        return;
    }
    void deleteWord(string word)
    {
        deleteUtil(root, word);
        return;

        // ?? To be Complete !
    }

private:
    void insertUtil(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminate = true;
            return;
        }
        int idx = word[0] - 'A';
        TrieNode *child;

        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        // Recursion *****
        insertUtil(child, word.substr(1));
        return;
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            return root->isTerminate;
        }
        int idx = word[0] - 'A';
        TrieNode *child;

        if (root->children[idx] == NULL)
        {
            return false;
        }

        // Recursion *****
        child = root->children[idx];
        return searchUtil(child, word.substr(1));
    }

    void deleteUtil(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminate = false;
        }
        int idx = word[0] - 'A';
        TrieNode *child;

        if (root->children[idx] == NULL)
        {
            return;
        }

        // Recursion *****
        child = root->children[idx];
        deleteUtil(child, word.substr(1));
        return;
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("PIYUSH");
    t->insertWord("AYUSH");
    t->insertWord("SHIVA");
    t->insertWord("JANVI");
    cout << "Is Present -> PIYUSH -> " << t->searchWord("PIYUSH") << endl;
    cout << "Is Present -> PIYUS -> " << t->searchWord("PIYUS") << endl;
    cout << "Is Present -> BABBAR -> " << t->searchWord("BABBAR") << endl;
    cout << "Is Present -> AYUSH -> " << t->searchWord("AYUSH") << endl;
    return 0;
}