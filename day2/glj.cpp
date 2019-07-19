#include <bits/stdc++.h>
using namespace std;
const int  maxn=1010;
int n;
int pre[maxn],in[maxn];
vector<int>ans;
struct node{
    int val;
    node *lc;
    node *rc;
    node(int val):val(val),lc(NULL),rc(NULL){}
};
struct tree{
    node* root;
};

node* build(int preL, int preR,int inL,int inR)
{
    if(preL>preR) return NULL;
    node *root=new node(pre[preL]);
    int index;
    for(index=inL;index<=inR;index++)
    {
        if(in[index]==pre[preL]) break;
    }
    int numleft=index-inL;
    root->lc=build(preL+1,preL+numleft,inL,index-1);
    root->rc=build(preL+numleft+1,preR,index+1,inR);
    return root;
}
void postorder(node *root)
{
    if(!root) return;
    postorder(root->lc);
    postorder(root->rc);
    ans.push_back(root->val);

}
int main()
{
    while(cin>>n)
    {
        ans.clear();
        for(int i=0;i<n;i++) cin>>pre[i];
        for(int i=0;i<n;i++) cin>>in[i];
        tree tre;
        tre.root=build(0,n-1,0,n-1);
        postorder(tre.root);
        int l=ans.size();
        for(int i=0;i<l;i++)
        {
            if(i!=0) cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
        delete tre.root;
    }
  
 
    return 0;
}


