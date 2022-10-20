//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Insert word , search word, the word starts with, in Trie
struct Node
{
    Node *links[26];
    bool end = false;

    bool checkNode(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void link_ch_ToNode(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getLinked_Node(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        end = true;
    }

    bool isEnd()
    {
        return end;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->checkNode(word[i]))
            {
                temp->link_ch_ToNode(word[i], new Node());
            }
            temp = temp->getLinked_Node(word[i]);
        }
        temp->setEnd();
    }
    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->checkNode(word[i]))
            {
                return false;
            }
            temp = temp->getLinked_Node(word[i]);
        }
        return temp->isEnd();
    }
    bool startsWith(string prefix)
    {
        Node *temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!temp->checkNode(prefix[i]))
            {
                return false;
            }
            temp = temp->getLinked_Node(prefix[i]);
        }
        return true;
    }
};

int main()
{
    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            trie.insert(value[i]);
        }
        else if (type[i] == 2)
        {
            if (trie.search(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
        else
        {
            if (trie.startsWith(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
    }
    return 0;
}