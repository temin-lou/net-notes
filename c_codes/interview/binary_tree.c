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
#include <stdlib.h>

#ifdef NULL
    #undef NULL
    #define NULL 0
#endif

struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};
struct BinaryTreeNode *buildTree(int *preorder, int preorderLen, int *inorder, int inorderLen)
{
    struct BinaryTreeNode *binTree;
    int root;
    int nLeft, nRight;
    int *pIn, *pPre;

    if ( (preorderLen == 0) && (inorderLen == 0)) {
        return NULL;
    }
    //if ( (preorderLen == 1) && (inorderLen == 1)) {
    printf("n=%d pre= ", preorderLen);
    for (nLeft = 0; nLeft <= preorderLen - 1; nLeft++)
    {
        printf("%d, ", preorder[nLeft]);
    }
    printf("\n");

    printf("n=%d in= ", inorderLen);
    for (nLeft = 0; nLeft <= inorderLen - 1; nLeft++)
    {
        printf("%d, ", inorder[nLeft]);
    }
    printf("\n");


    binTree = (struct BinaryTreeNode *) malloc (sizeof(struct BinaryTreeNode));
    memset(binTree, NULL, sizeof(struct BinaryTreeNode));
    binTree->value = *preorder;
    root = *preorder;
    for (nLeft = 0; nLeft <= inorderLen - 1; nLeft++) 
    {
        if (inorder[nLeft] == root) break;
    }

    pIn  = inorder;
    pPre = preorder + 1; 
    binTree->left  = buildTree( pPre, nLeft, pIn, nLeft );
    pIn  = inorder + nLeft + 1;
    pPre = preorder + nLeft + 1;

    nRight = preorderLen - nLeft - 1;
    binTree->right = buildTree( pPre, nRight, pIn, nRight );

    printf ("var=%d, %p, %p\n", binTree->value, binTree->left, binTree->right);
    return binTree;
}

int main(int argc, char **argv)
{
    //int preOrder[] = {1,2,4,3,5,6};
    //int inOrder[]  = {4,2,1,5,6,3};
    int preOrder[] = {1,2};
    int inOrder[]  = {1,2};
    struct BinaryTreeNode *tree;

    //tree = buildTree(preOrder, 6, inOrder, 6);
    tree = buildTree(preOrder, 2, inOrder, 2);
    return 0;
}

