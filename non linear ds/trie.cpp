#include<iostream>
using namespace std;
struct node{
    bool isword;
    node* next[26];
};

node* newnode(){
    node *temp = new node;
    temp->isword = false;
      for (int i = 0; i < 26; i++)
        temp->next[i] =NULL;
    return temp;
}
void insert(node* root,  string s){
    node* temp = root;
for (int i = 0; i < s.length(); i++)
{
    if(temp->next[s[i] - 'a']== NULL){
        temp->next[s[i] - 'a'] = newnode();
       temp= temp->next[s[i] - 'a'];
    }
}
temp->isword = true;
}

bool search(node* root,string s){
    node* temp = root;
for (int i = 0; i < s.length(); i++)
{
    if(temp->next[s[i] - 'a']== NULL)
        return false;
    temp= temp->next[s[i] - 'a'];
}
 return temp->isword;
}
void deleteword(node* root,string s){
    node* temp = root;
for (int i = 0; i < s.length(); i++)
{
    if(temp->next[s[i] - 'a']== NULL)
        cout<<"word not found"<<endl;
    temp= temp->next[s[i] - 'a'];
}
    cout<<"deleted"<<endl;
    temp->isword =false;
}
int main(){
    node *root = newnode();
    int n;
    cout<<"Enter number of words ";
    cin>>n;
    string s;
    cout<<"Enter words ";
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        insert(root,s);
    }
    cout<<"Enter number of quries ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
         if(search(root,s)) cout<<s<<" is in the trie\n";
         else cout<<s<<" is not in the trie\n";
         deleteword(root,s);
    }
    
    
}