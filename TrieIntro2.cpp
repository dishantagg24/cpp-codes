//* Don't Burn Your Opportunities just for Temporary Happiness
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//*count no of words equal to, count no of words starting with
struct Node
{
    Node *links[26];
    int endWith = 0;
    int cntPrefix = 0;

    bool checkNode(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void link_ch_to_node(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    void setCp()
    {
        cntPrefix++;
    }

    void setEnd()
    {
        endWith++;
    }

    int getCp()
    {
        return cntPrefix;
    }

    int getEnd()
    {
        return endWith;
    }

    void deleteEnd()
    {
        endWith--;
    }
    void deleteCp()
    {
        cntPrefix--;
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
                temp->link_ch_to_node(word[i], new Node());
            }
            temp = temp->getNode(word[i]);
            temp->setCp();
        }
        temp->setEnd();
    }
    int countWords(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->checkNode(word[i]))
            {
                return 0;
            }
            temp = temp->getNode(word[i]);
        }
        return temp->getEnd();
    }
    int countWordsStartingWith(string prefix)
    {
        Node *temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!temp->checkNode(prefix[i]))
            {
                return 0;
            }
            temp = temp->getNode(prefix[i]);
        }
        return temp->getCp();
    }
    void deleteWord(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->checkNode(word[i]))
            {
                return;
            }
            temp = temp->getNode(word[i]);
            temp->deleteCp();
        }
        temp->deleteEnd();
    }
};

int main()
{
    Trie T;
    T.insert("apple");
    T.insert("apple");
    T.insert("apps");
    T.insert("apps");
    string word1 = "apps";
    cout << "Count Words Equal to " << word1 << " " << T.countWords(word1) << endl;
    string word2 = "abc";
    cout << "Count Words Equal to " << word2 << " " << T.countWords(word2) << endl;
    string word3 = "ap";
    cout << "Count Words Starting With " << word3 << " " << T.countWordsStartingWith(word3)
         << endl;
    string word4 = "appl";
    cout << "Count Words Starting With " << word4 << " " << T.countWordsStartingWith(word4)
         << endl;
    T.deleteWord(word1);
    cout << "Count Words equal to " << word1 << " " << T.countWords(word1) << endl;
    return 0;
}