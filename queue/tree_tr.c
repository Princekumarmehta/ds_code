#include <stdio.h>
#include <stdlib.h>
struct tree
{
    struct tree *left;
    struct tree *right;
    int info;
};
struct tree *root=NULL;
struct tree *insert(int item)
{struct tree *new,*curr,*prev;
new=(struct tree *)malloc(sizeof(struct tree));
new->left=NULL;
new->right=NULL;
new->info=item;
if(root==NULL){
root=new;
}
else{
    curr=root;
    while(curr!=NULL){
        prev=curr;
        if(curr->info>item)curr=curr->left;
        else curr=curr->right;
    }
    if(prev->info>item){
        prev->left=new;

    }
    else prev->right=new;
}
return root;


}
struct tree *create_tree()
{
    int item;
    printf("\nEnter to insert in tree: ");
    scanf("%d",&item);
    while(item!=-999){
        root=insert(item);
        printf("\n");
        scanf("%d",&item);

    }
    return root;
}
void inorder(struct tree *root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->info);
    inorder(root->right);
}
void preorder(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->info);
    preorder(root->left);
    
    preorder(root->right);
}
void postorder(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    
    postorder(root->right);
    printf("%d", root->info);
}
struct tree *delete(struct tree *root ,int item){
    int value;
    struct tree *child,*curr,*prev,*succ;
    if(root==NULL){
        printf("no");
    }
    else{
        curr=root;
        while(curr!=NULL && curr->info!=item){
            prev=curr;
            if(curr->info>item)curr=curr->left;
            else curr=curr->right;

        }
        if(curr==NULL){
            printf("no");
        }
        else if(curr->left==NULL && curr->right==NULL){
            if(curr==prev->left){
                prev->left=NULL;
                free(curr);
            }
            else prev->right=NULL;
        }
        else if (curr->left == NULL || curr->right == NULL){
            if(curr->left!=NULL){
                child=curr->left;

            }
            else child=curr->right;
            if(curr==prev->right){
                prev->right=child;
            }
            else prev->left=child;
        }
         else {
        succ=curr->right;
        while(succ->left!=NULL){
            succ=succ->left;
        }
        value=succ->info;
        delete(root,succ->info);
        curr->info=value;

    }
    }
    return root;
}

int main()
{
    int opt;
    int item;
    printf("Enter choice: ");
   scanf("%d",&opt);
   while(opt!=6)
   {
    switch(opt)
    {
        case 1: root=create_tree();
        break;
        case 2:inorder(root);
        break;
        case 3:
        preorder(root);
        break;
        case 4:
        postorder(root);
        break;
        case 5: 
        
        printf("\nsss");
        scanf("%d",&item);
        break;
    }
    scanf("%d", &opt);
   }
   return 0;
}