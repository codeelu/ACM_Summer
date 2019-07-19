#include <iostream>
using namespace std;
struct BiTNode{
    char data;
    struct BiTNode* lchild,* rchild; // 左右孩子
};
void CreatBiTree(BiTNode* &T){ // 先序递归创建二叉树
    // 先按顺序驶入二叉树中节点的值(一个字符),空格字符代表空树
    char ch;
   
        if((ch=getchar()) == '#') // getchar() 为逐个读入标准库函数
            T = NULL;
        else{
            T = new BiTNode; // 产生新的子树
            T->data = ch; // 由getchar()逐个读进来
            CreatBiTree(T->lchild); // 递归创建左子树
            CreatBiTree(T->rchild); // 递归创建右子树
        }
    }

void PreOrderTraverse(BiTNode* &T){ // 先序遍历二叉树
    if(T){ // 当节点不为空时执行
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    else
        cout << "";
}
void Inoder(BiTNode* &T){ // 中序遍历二叉树
    if(T){
        Inoder(T->lchild);
        cout << T->data;
        Inoder(T->rchild);
    }
    else
        cout << "";
 
}
void Posoder(BiTNode* &T){ // 中序遍历二叉树
    if(T){
        Posoder(T->lchild);
        Posoder(T->rchild);
        cout << T->data;
    }
    else
        cout << "";
}
int main(){
    cout << "创建一颗二叉树,其中A~Z字符代表树的数据,用'#'表示空树:" << endl;
    BiTNode* T;
    CreatBiTree(T);
    cout << "先序递归遍历" << endl;
    PreOrderTraverse(T);
    cout << "中序递归遍历" << endl;
    Inoder(T);
    cout << "后序递归遍历" << endl;
    Posoder(T);
 
    return 1;
}

