#include<stdio.h>
#include<stdlib.h>

/* Prototypes */
int lookup(char arr[], int start, int end, char value);
struct node* newNode(char data);
struct node {
  char data;
  struct node* left;
  struct node* right;
};
int lookup(char arr[],int start,int end,char value) {
  int i;
  for (i = start; i <= end; i++) {
    if(arr[i] == value)
      return i;
  }
}
struct node* newNode(char data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
struct node* makeTree(char in[],char pre[],int start,int end) {
  static int preIndex = 0;
  if(start > end)
    return NULL;
  struct node *topNode = newNode(pre[preIndex++]);
  if(start == end)
    return topNode;
  int inIndex = lookup(in,start,end,topNode->data);
  topNode->left = makeTree(in,pre,start,inIndex-1);
  topNode->right = makeTree(in,pre,inIndex+1,end);
  return topNode;
}
void printOrder(struct node* node) {
  if (node == NULL)
    return;
  printOrder(node->left);
  printf("%c ", node->data);
  printOrder(node->right);
}

int main() {
  char in[] = {'A','B','C','D','E','F','G','H','I'};
  char pre[] = {'F','B','A','D','C','E','G','I','H'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = makeTree(in, pre, 0, len - 1);
  printf("\n Inorder traversal of the constructed tree is \n");
  printOrder(root);
  printf("\n");
}





