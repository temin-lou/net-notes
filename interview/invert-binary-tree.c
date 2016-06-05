/*
 * gcc -o invert-binary-tree invert-binary-tree.c
 */
#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *initTree( int i )
{
    struct TreeNode *root;

    if(i < 10) {
        i++;
        root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        root->left  = initTree(2*i);
        root->right = initTree(2*i-1);
        root->val   = i;
        //printf("root=%p,l=%p,r=%p,%d\n", root, root->left, root->right, root->val);
    } else {
        root = NULL;
    }
    
    return root;
}

void printTree( struct TreeNode *root)
{
    struct TreeNode *p;

    p = root;
    if(p == NULL) return; 
    printf("%d\n", p->val);
    printTree( root->left );
    printTree( root->right);
}
void invert_binary_tree(struct TreeNode *root)
{
    struct TreeNode *p, *tmp;

    if(!root)return;
    p = root;
    tmp = p->left;
    p->left  = p->right;
    p->right = tmp;

    invert_binary_tree(p->left);
    invert_binary_tree(p->right);
}

int main(int argc, char **argv)
{
    struct TreeNode *root;
    
    root = initTree(0);
    //printTree(root);
    printf("    %d\n  %d   %d\n %d %d %d %d\n", root->val,
            root->left->val, root->right->val,
            root->left->left->val,  root->left->right->val, 
            root->right->left->val, root->right->right->val);
    invert_binary_tree(root);
    printf("    %d\n  %d   %d\n %d %d %d %d\n", root->val,
            root->left->val, root->right->val,
            root->left->left->val,  root->left->right->val, 
            root->right->left->val, root->right->right->val);
    return 0;
}
