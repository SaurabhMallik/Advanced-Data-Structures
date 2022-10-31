#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* links[26]={NULL};
    bool flag=false;
  
    bool containsKey(char c)
    {
        return links[c-'a']!=NULL;
    }
  
    void put(char c, Node* temp)
    {
        links[c-'a']=temp;
    }
  
    Node* get(char c)
    {
        return links[c-'a'];
    }
  
    void set_flag()
    {
        flag=true;
    }
};

class Trie
{
    public:
        Node* root;
  
        Trie()
        {
            root=new Node();
        }
  
        void add(string s)
        {
            Node* temp=root;
            for (int i=0;i<s.size();i++)
            {
                if (!temp->containsKey(s[i]))
                    temp->put(s[i],new Node());
                temp=temp->get(s[i]);
            }
            temp->set_flag();
        }
  
        bool query(string s)
        {
            Node* temp=root;
            for (int i=0;i<s.size();i++)
            {
                if (!temp->containsKey(s[i]))
                    return false;
                temp=temp->get(s[i]);
            }
            return temp->flag;
        } 
};

int main()
{
    int n;
    cin>>n;
    string s;
    Trie* trie=new Trie();
    for (int i=0;i<n;i++)
    {
        cin>>s;
        trie->add(s);
    }
    cin>>s;
    bool ans=trie->query(s);
    if (ans==false)
        cout<<s<<" is not present in the dictionary.\n";
    else
        cout<<s<<" is present in the dictionary.\n";
}
