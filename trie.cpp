#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

class trie
{
private:
    trie* next[26];
    bool isword;
public:
    trie():isword(false)
    {
        memset(next, NULL, sizeof(next));
    }
    void insert(string word);
    bool search(string word);
    void deletetrie();
};

void trie::insert(string word)
{
    int n = word.size();
    trie* node = this;
    for(int i = 0; i < n; i++)
    {
        if(!node->next[word[i] - 'a'])
        {
            node->next[word[i] - 'a'] = new trie();
        }
        node = node->next[word[i] - 'a'];
    }
    node->isword = true;
}

bool trie::search(string word)
{
    int n = word.size();
    trie* node = this;
    for(int i = 0; i < n && node; i++)
    {
        node = node->next[word[i] - 'a'];
    }
    return node && node->isword;
}

void trie::deletetrie()
{
    for(int i = 0; i < 26; i++)
    {
        if(this->next[i])
        {
            trie* temp = this->next[i];
            this->next[i] = NULL;
            delete temp;
        }
    }
}
int main(void)
{
    trie tree;
    string s;
    int n;
    cout << "输入大小" << endl;
    cin >> n;
    cout<< "输入单词" << endl;
    while(n--)
    {
        cin >> s;
        tree.insert(s);
    }
    string input;
    cout << "输入想查找的单词" << endl;
    cin >> input;
    cout << tree.search(input) << endl;
    return 0;
}