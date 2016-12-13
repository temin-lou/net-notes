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
struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
}

int main(int argc, char **argv)
{
    return 0;
}
