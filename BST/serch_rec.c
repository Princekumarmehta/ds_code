#include <stdio.h>
#include <stdlib.h>
struct tree
{
    struct tree *left;
    struct tree *right;
    int info;
};

struct tree *insert_in_tree(int item, struct tree *root)
{
    struct tree *p, *temp;
    p = (struct tree *)malloc(sizeof(struct tree));
    p->info = item;
    p->left = NULL;
    p->right = NULL;
    if (root == NULL)
    {
        root = p;
    }
    else
    {
        temp = root;
        struct tree *prev;
        while (temp != NULL)
        {
            prev = temp;
            if (temp->info > item)
            {
                temp = temp->left;
            }
            else
                temp = temp->right;
        }
        if (prev->info > item)
        {
            prev->left = p;
        }
        else
            prev->right = p;
    }
    return root;
}

struct tree *create_tree(struct tree *root)
{
    int item;
    printf("Enter item to enter in bst:(-999 to exit :)\n");
    scanf("%d", &item);
    while (item != -999)
    {
        root = insert_in_tree(item, root);
        scanf("%d", &item);
    }
    return root;
}
struct tree *search(struct tree *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->info==key){
        return root;
    }
    else if(root->info>key){
        return search(root->left,key);

    }
    else return search(root->right,key);
}

int main()
{
    struct tree *root = NULL,*n;
    root = create_tree(root);
    int key;

   do{ 
    printf("Enter key to search:\n");
    scanf("%d",&key);
    n=search(root,key);
    if(n!=NULL){
        printf("Key Found: %d\n",n->info);
    }
    else{
        printf("Element not found\n");
    }
   }while(key!=-999);
    return 0;
}