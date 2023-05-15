#include <stdio.h>
#include <stdlib.h>
 struct tree{
    struct tree *left;
    struct tree *right;
    int info;
 };

struct tree *insert_in_tree(int item , struct tree *root){
    struct tree *p,*temp;
    p=(struct tree*)malloc(sizeof(struct tree));
    p->info=item;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL){
        root=p;
    }
    else{
        temp=root;
        struct tree *prev;
        while(temp!=NULL){
            prev=temp;
            if(temp->info>item){
                temp=temp->left;
            }
            else temp=temp->right;
        }
        if(prev->info>item){
            prev->left=p;
        }
        else prev->right=p;
    }
return root;
}

 struct tree *create_tree(struct tree *root){
    int item;
    printf("Enter item to enter in bst:(-999 to exit :)\n");
    scanf("%d",&item);
    while(item!=-999){
        root=insert_in_tree(item,root);
        scanf("%d",&item);
        }
    return root;
 }

 int main(){
    struct tree *root=NULL;
    root=create_tree(root);
    return 0;
 }