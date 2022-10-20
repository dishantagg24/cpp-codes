//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*Longest word with all prefixes
// Time Complexity:- O(n)*O(length of each string)
// n :- array of strings
//*Count Distinct substrings of strings
// Time Complexity:- O(n^2)
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

    bool checkPrefixExists(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->checkNode(word[i]))
            {
                return false;
            }
            temp = temp->getLinked_Node(word[i]);
            if (temp->isEnd() == false)
            {
                return false;
            }
        }
        return true;
    }

    int countDistinctSubstrings(string word)
    {
        Node *root = new Node();
        int count = 0;
        for (int i = 0; i < word.length(); i++)
        {
            Node *temp = root;
            for (int j = i; j < word.length(); j++)
            {
                if (!temp->checkNode(word[j]))
                {
                    count++;
                    temp->link_ch_ToNode(word[j], new Node());
                }
                temp = temp->getLinked_Node(word[j]);
            }
        }
        return count + 1;
    }
};

int main()
{
    vector<string> a = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    Trie *obj = new Trie();
    for (auto word : a)
        obj->insert(word);
    string longest = "";
    for (auto word : a)
    {
        if (obj->checkPrefixExists(word))
        {
            if (word.size() > longest.size())
            {
                longest = word;
            }
            else if (word.size() == longest.size() && word < longest)
            {
                longest = word;
            }
        }
    }
    if (longest == "")
        cout << "None"
             << "\n";
    cout << longest << "\n";
    return 0;
}