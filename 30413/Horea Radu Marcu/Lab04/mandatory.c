#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    char id;
    struct node_type *left, *right;
}NodeT;
void fatalError(const char *msg)
{
    printf(msg);
    printf("\n");
    exit(1);
}
void preorder(NodeT *p, int level)
{
    if (p!=NULL)
    {
        int i;
        for(i=0;i<=level;i++) printf(" ");
        printf("%2.2d\n", p->id);
        preorder(p->left, level+1);
        preorder(p->right, level+1);
    }
}
void inorder(NodeT *p, int level)
{
    if(p!=NULL)
    {
        inorder(p->left, level+1);
        int i;
        for(i=0; i<=level; i++) printf(" ");
        printf("%2.2d\n", p->id);
        inorder(p->right, level+1);
    }
}
void postorder(NodeT *p, int level)
{
    if(p!=NULL)
    {
        postorder(p->left,level+1);
        postorder(p->right, level+1);
        int i;
        for(i=0;i<=level;i++) printf(" ");
        printf("%2.2d\n",p->id);
    }
}
NodeT*createBinTree( int branch, NodeT*parent)
{
    NodeT*p;
    int id;

    if( branch == 0 )
        printf("Root identifier [0 to end] = " );
    else if( branch == 1 )
        printf("Left child of %d [0 to end] = ",parent->id );
        else
            printf("Right child of %d [0 to end] = ",parent->id );
        scanf("%d", &id);
    if( id == 0 )
    return NULL;
    else
    {
        p = ( NodeT*)malloc(sizeof( NodeT ));
        if(p == NULL)fatalError("Out of space in createBinTree" );

        p->id= id;
        p->left= createBinTree( 1,p );
        p->right= createBinTree( 2,p );
    }
    return p;
}
NodeT* interchangedTree(NodeT* root)
{
    NodeT *aux;
    aux=root->left;
    root->left=root->right;
    root->right=aux;
    return root;
}
int heightOfTree(NodeT* root)
{
    if(root->left==NULL && root->right==NULL) return 1;
    if(heightOfTree(root->left)>=heightOfTree(root->right)) return 1+heightOfTree(root->left);
    return 1+heightOfTree(root->right);
}
int numberOfLeaves(NodeT* root)
{
    if(root->left==NULL && root->right==NULL) return 1;
    return numberOfLeaves(root->left)+numberOfLeaves(root->right);
}
int main()
{
    NodeT *root= createBinTree( 0, NULL );
    printf("Number of leaves of the given tree :%d\n",numberOfLeaves(root));
    printf("The height of the given tree :%d\n", heightOfTree(root));
    while('\n' != getc(stdin));
        printf("\nPreorder listing\n" );
    preorder( root, 0 );
    printf("Press Enter to continue." );
    while('\n' != getc(stdin));
        printf("\nInorder listing\n" );
    inorder( root, 0 );
    printf("Press Enter to continue." );
    while('\n' != getc(stdin));
        printf("\nPostorder listing\n" );
        postorder( root, 0 );
    printf("Press Enter to continue." );
    while('\n' != getc(stdin));
    root=interchangedTree(root);
    printf("The preorder listing of the interchanged tree is:\n");
    preorder(root,0);
    return 0;
}
