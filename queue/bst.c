#include <stdio.h>
#include <stdlib.h>

struct tree{
    struct tree *right;
    struct tree *left;
    int info;
};
struct tree *root=NULL;
struct tree *insert_in_tree(int item){
  struct tree *new,*curr=root,*prev;
  new=(struct tree *)malloc(sizeof(struct tree));
  new->left=NULL;
  new->right=NULL;
  new->info=item;
  if(root==NULL){
    root=new;
  }
  else{
      while(curr!=NULL){
        prev=curr;
        if(curr->left>item){
            curr=curr->left;
        }
        else curr=curr->right;
      }
      if(prev->info>item){
        prev->left=new;

      }
      else prev->right=new;
  }
  return root;
}
struct tree *create_tree(){
    int item,opt;
    printf("Enter the item:");
    scanf("%d",&item);
    while(item!=-999){
        root=insert_in_tree(item);
        scanf("%d",&item);
    }
    return root;

}
struct tree *delete_a_node(int item)
{
    struct tree *curr,*par,*suc,*psuc,*ptr;
    if(root==NULL){
printf("Empty tree");
    }
else{
    curr=root;
    while(curr!=NULL && curr->info!=item){
        par=curr;
        if(item<curr->info)curr=curr->left;
        else curr=curr->right;
    }
    if(curr==NULL){
        printf("\nItem not ther");}

    
    else {
        if(curr->right==NULL && curr->left==NULL){
            if(curr==par->left){
                par->left=NULL;
            }
            else par->right=NULL;
        }
       
    }
}
}
