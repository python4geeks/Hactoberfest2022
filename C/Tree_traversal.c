#include <stdio.h>
#include <stdlib.h>
#define count 10
struct node
{
  int data;
  struct node *left, *right;
};

struct node *create()
{
  int x;
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("\n enter the data in new node,write -1 if no node is needed\n");
  scanf("%d", &x);
  if (x == -1)
    return 0;
  newnode->data = x;
  printf("\n enter the left child of %d", x);
  newnode->left = create();
  printf("\n enter the  right child of %d", x);
  newnode->right = create();
  return newnode;
}

void preorder(struct node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(struct node *root)
{
  if (root != NULL)
  {

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}
void inorder(struct node *root)
{
  if (root != NULL)
  {

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int print_tree(struct node *root, int space)
{
  if (root == NULL)
    return 0;
  space += count;
  print_tree(root->right, space);
  printf("\n");
  for (int i = count; i < space; i++)
    printf(" ");
  printf("%d\n", root->data);
  print_tree(root->left, space);
}

int main()
{
  int ch;

  printf("\n***Binary Tree Traversal***\n");
  struct node *root = create();
  print_tree(root, 0);
  printf("\n");
  while (1)
  {

    printf("\nenter 1- Preorder Traversal\n 2-Inorder Traversal\n 3-Postorder Traversal \n 4-exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    printf("the pre-order traversal is:");
      preorder(root);

      break;
    case 2:
     printf("the in-order traversal is:");
      inorder(root);
      break;
    case 3:
     printf("the post-order traversal is:");
      postorder(root);
      break;
    case 4:
      exit(0);
      break;
    default:
      printf("invalid");
      break;
    }
    
  }
 
  return 0;
}