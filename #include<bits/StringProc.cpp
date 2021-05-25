#Pattern Matching/ Answering Q Query.
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node
{
    int data, id, sid, len;
    int next[26], fail;
};
node a[N];
char s[N], s1[N];
int top = 0;
int creat_kong()
{
    node *root = &a[top++];
    root->id = 0;
    for(int i = 0; i < 26; i++)
        root->next[i] = -1;
    root->fail = -1;
    root->sid = -1;
    return top-1;
}
void Insert(int root, char *s, int id)
{
    int len = strlen(s);
    int p = root;
    for(int i = 0; i < len; i++)
    {
        int tmp = s[i]-'a';
        if(a[p].next[tmp] == -1) a[p].next[tmp] = creat_kong();
        a[a[p].next[tmp]].len = i+1;
        p = a[p].next[tmp];
    }
    a[p].id = id;
}
void get_fail(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int p = q.front(); q.pop();
        for(int i = 0; i < 26; i++)
        {
            if(a[p].next[i] == -1) continue;
            if(p == root) a[a[p].next[i]].fail = root;
            else {
                int tmp = a[p].fail;
                while(tmp != -1 && a[tmp].next[i] == -1) tmp = a[tmp].fail;
                if(tmp == -1) a[a[p].next[i]].fail = root;
                else a[a[p].next[i]].fail = a[tmp].next[i];
            }
            q.push(a[p].next[i]);
        }
    }
}
unordered_map<string, int>ans;
string ss[N];
int flag;
void mat(int root, char *s)
{
    int p = root;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int tmp = s[i]-'a';
        while(p != root && a[p].next[tmp] == -1) p = a[p].fail;
        if(p == root && a[p].next[tmp] == -1) continue;
        p = a[p].next[tmp];
        int t = p;
        while(t != root)
        {
            if(a[t].id && (i - a[t].sid >= a[t].len)) {
                a[t].sid = i;
                ans[ss[a[t].id]]++;
            }
            t = a[t].fail;
        }
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    top = 0;
    int root = creat_kong();
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", s1);
        ss[i] = string(s1);
        Insert(root, s1, i);
    }
    get_fail(root);
    mat(root, s);
    for(int i = 1; i <= m; i++)
    {
        printf("%d\n", ans[ss[i]]);
    }
    return 0;
}

