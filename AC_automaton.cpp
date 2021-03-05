#include<bits/stdc++.h>
using namespace std;
// Aho-Corasick
class actrie{
private:
    vector<actrie*> next;
    actrie* fail;
    bool isword;
public:
    actrie(): fail(nullptr), isword(false)
    {
        next.resize(26, nullptr);
    }
    void insert(string word);
    void build();
    int search(string word);
};

void actrie::insert(string word)
{
    int n = word.size();
    actrie* node = this;
    for(int i = 0; i < n; i++)
    {
        if(!node->next[word[i] - 'a'])
            node->next[word[i] - 'a'] = new actrie();
        node = node->next[word[i] - 'a'];
    }
    node->isword = true;
}

void actrie::build()
{
    this->fail = this;
    queue<actrie*> myque;
    for(int i = 0; i < 26; i++)
    {
        if(this->next[i])
        {
            this->next[i]->fail = this;
            myque.push(this->next[i]);
        }
        else
        {
            this->next[i] = this;
        }
    }
    while(!myque.empty())
    {
        actrie* node = myque.front();
        node->isword = node->isword || node->fail->isword;
        myque.pop();
        for(int i = 0; i < 26; i++)
        {
            if(node->next[i])
            {
                node->next[i]->fail = node->fail->next[i];
                myque.push(node->next[i]);
            }
            else
            {
                node->next[i] = node->fail->next[i];
            }
        }
    }
}

int actrie::search(string word)
{
    int res = 0, n = word.size();
    actrie* node = this;
    for(int i = 0; i < n; i++)
    {
        if(node->isword) res++;
        node = node->next[word[i] - 'a'];
    }
    if(node->isword) res++;
    return res;
}

int main(void)
{
    actrie tree;
    string s;
    int n;
    cout << "length" << endl;
    cin >> n;
    cout<< "word" << endl;
    while(n--)
    {
        cin >> s;
        tree.insert(s);
    }
    tree.build();
    string input;
    cout << "searchword" << endl;
    cin >> input;
    cout << tree.search(input) << endl;
    return 0;
}