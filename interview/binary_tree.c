/*
 * 用c/c++实现
 * 已知二叉树的前序和中序遍历序列，
 * 由此构建出一棵二叉树。
 *
 *            1
 *           / \
 *          2   3
 *         /   /
 *        4   5
 *             \
 *              6
 *
 * 前序序列为preOrder={1,2,4,3,5,6}; 
 * 中序遍历序列为inOrder={4,2,1,5,6,3}
 * 构建出一棵二叉树
 *
 */
#include <stdio.h>
#include <string.h>

int preOrder[] = {1,2,4,3,5,6};
int inOrder[]  = {4,2,1,5,6,3};

struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};
struct BinaryTreeNode *buildTree(int *preorder, int preorderLen, int *inorder, int inorderLen)
{
    struct BinaryTreeNode *binTree;

    binTree = (struct BinaryTreeNode *) malloc (sizeof(struct BinaryTreeNode));
    memset(binTree, 0, sizeof(struct BinaryTreeNode));
    if ( (preorderLen == 1) && (inorderLen == 1)) {


    }

    

}

int main(int argc, char **argv)
{
    return 0;
}

////根据前序和中序遍历写出后序遍历
//int t1[1001],t2[1001];
//void sousuo(int a,int b,int n,int flag)
//{
//
//    if(n==1)//如果存在左子树或右子树就直接输出
//    {
//        printf("%d ",t1[a]);
//        return ;
//    }
//    else if(n<=0)//如果不存在左子树或右子树就返回上一层
//        return ;
//    int i;//继续罚分为左子树和右子树
//    for(i=0;t1[a]!=t2[b+i];i++) ;//找到罚分点也就是根节点
//    sousuo(a+1,b,i,0);//左子树的遍历
//    sousuo(a+i+1,b+i+1,n-i-1,0);//右子树的遍历
//    if(flag==1)//最原始的跟节点
//        printf("%d",t1[a]);
//    else//一般的根节点
//        printf("%d ",t1[a]);
//}
//int main()
//{
//    int n,i;
//    while(scanf("%d",&n)!=EOF)
//    {
//        for(i=1;i<=n;i++)
//            scanf("%d",&t1[i]);//t1中存的是前序
//        for(i=1;i<=n;i++)//t2中存的中序
//            scanf("%d",&t2[i]);
//        sousuo(1,1,n,1);
//        printf("\n");
//
//    }
//    return 0;
//}
//
