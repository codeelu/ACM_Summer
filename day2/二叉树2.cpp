#include <iostream>
#include <cstring>
using namespace std;
typedef struct BinaryTree
    {
    char data;
    BinaryTree* lchild;
    BinaryTree* rchild;
}BinaryTree;
 
void RebuildTree(BinaryTree* &Tree,char* pre,char* in,int len)
    {
    Tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if(Tree!=NULL)
        {
        if(len<=0)
            {//递归截止条件
            Tree = NULL;
            return ;
        }
        int index = 0;
        while(index<len&&*(pre)!=*(in+index))
            {//寻找当前的root结点（包含子树）
            index++;
        }
        Tree->data = *(pre);
        RebuildTree(Tree->lchild,pre+1,in,index);//去掉root结点
        RebuildTree(Tree->rchild,pre+1+index,in+1+index,len-(index+1));//去掉左边和根节点
    }
    return ;
}
 
void PostOrderTravese(BinaryTree* Tree)
    {//后序遍历输出
    if(Tree==NULL)
        return;
    PostOrderTravese(Tree->lchild);
    PostOrderTravese(Tree->rchild);
    printf("%c",Tree->data);
}
 
 
int main()
{
    char pre[101];
    char in[101];
    while(scanf("%s %s",pre,in)!=EOF)
        {
        BinaryTree* tree;
        int length = strlen(pre);
        RebuildTree(tree,pre,in,length);   
        PostOrderTravese(tree);
        cout<<endl;
    }
    return 0;
}

