//MY IMPLEMENTATION of TRIE DS
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    map<char, TrieNode *> links;
    bool isWord = false;
};

class Trie
{

    void insertRecur(TrieNode *root, string word)
    {
        if (word.size() == 0)
            return;

        if (root->links.find(word[0]) == root->links.end())
        {
            TrieNode *temp = new TrieNode();
            if (word.size() == 1)
                temp->isWord = true;
            root->links[word[0]] = temp;
            insertRecur(temp, word.substr(1, word.size() - 1));
        }
        else
        {
            if (word.size() == 1)
            {
                root->links[word[0]]->isWord = true;
                return;
            }
            insertRecur(root->links.find(word[0])->second, word.substr(1, word.size() - 1));
        }
    }

    bool searchRecurs(TrieNode *node, string word)
    {
        if (node->links.find(word[0]) != node->links.end())
        {
            if (word.size() == 1)
            {
                if (node->links[word[0]]->isWord)
                    return true;
                return false;
            }
            return searchRecurs(node->links[word[0]], word.substr(1, word.size() - 1));
        }
        return false;
    }

    bool startsWithRecurse(TrieNode *node, string word)
    {
        if (node->links.find(word[0]) != node->links.end())
        {
            if (word.size() == 1)
                return true;

            return startsWithRecurse(node->links[word[0]], word.substr(1, word.size() - 1));
        }
        return false;
    }

public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        insertRecur(root, word);
    }

    bool search(string word)
    {
        return searchRecurs(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return startsWithRecurse(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */