#include <bits/stdc++.h>
#define type pair<int,string>
#define mp(a,b) make_pair(a,b)
using namespace std;
struct tnode
{
    struct tnode *child[26];
    int wcnt;
    string word;
};
struct tnode *newtnode()
{
    struct tnode *temp = new struct tnode;
    for(int i = 0; i < 26; i++) {
        temp->child[i] = NULL;
    }
    temp->wcnt = 0;
    temp->word = "";
    return temp;
};
int cmp(type a,type b)
{
    return a.first > b.first;
}
struct tnode *root = NULL;
priority_queue<type,vector<type>, function<bool(type,type)> > q(&cmp);
void trieinsert(string s)
{
    int i;
    int c;
    struct tnode *temp = root;
    int n = s.size();
    string t = "";
    for(i = 0; i < n; i++) {
        c = (isupper(s[i]))?(s[i]-'A'):(s[i]-'a');
        if(temp->child[c] == NULL) {
            temp->child[c] = newtnode();
        }
        temp = temp->child[c];
    }
    temp->word = s;
    temp->wcnt += 1;
}
void traverse(struct tnode *temp,int k)
{
    if(temp->wcnt >= 1) {
        if(q.empty() || q.size() < k) {
            q.push(mp(temp->wcnt,temp->word));
        }
        else if(temp->wcnt > q.top().first) {
            q.pop();
            q.push(mp(temp->wcnt,temp->word));
        }
    }
    for(int i = 0; i < 26; i++) {
        if(temp->child[i]) {
            traverse(temp->child[i],k);
        }
    }
}
int main()
{
    int i;
    FILE *fp = fopen("program","r");
    root = newtnode();
    char c[1000];
    while(fscanf(fp,"%s",c) != EOF) {
        string s(c);
        trieinsert(s);
    }
    traverse(root,5);
    while(!q.empty()) {
        cout<<q.top().second<<' '<<q.top().first<<endl;
        q.pop();
    }
}
