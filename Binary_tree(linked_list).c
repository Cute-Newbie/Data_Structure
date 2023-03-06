#include <stdio.h>
#include <stdlib.h>

typedef struct _node{

	int data;
	struct _node* leftchild;
	struct _node* rightchild;

}Node;

//initNode Function
Node* initNode(int data, Node* leftchild, Node* rightchild);
Node* initNode(int data, Node* leftchild, Node* rightchild)
{
	Node* root;
	root = (Node*)malloc(sizeof(Node));
	root->data = data;
	root->leftchild = leftchild;
	root->rightchild = rightchild;
	return root;

}
//initNode Function ends here 

//preorder Function
void preorder(Node* root);
void preorder(Node* root)
{

	if (root) {
		printf("%d\n", root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);

	}
	return;

}
//preorder Function ends here 

//inorder Function
void inorder(Node* root);
void inorder(Node* root)
{

	if (root) {
		
		inorder(root->leftchild);
		printf("%d\n", root->data);
		inorder(root->rightchild);

	}
	return;

}
//inorder Function ends here 

//postorder Function
void postorder(Node* root);
void postorder(Node* root)
{

	if (root) {
		;
		preorder(root->leftchild);
		preorder(root->rightchild);
		printf("%d\n", root->data);
		

	}
	return;

}
//postorder Function ends here 




int main(void)
{
	Node* n7 = initNode(50, NULL, NULL);
	Node* n6 = initNode(37, NULL, NULL);
	Node* n5 = initNode(23, NULL, NULL);
	Node* n4 = initNode(5, NULL, NULL);
	Node* n3 = initNode(48, n6, n7);
	Node* n2 = initNode(17, n4, n5);
	Node* n1 = initNode(30, n2, n3);
	preorder(n1);
	printf("\n");
	inorder(n1);
	printf("\n");
	postorder(n1);
	printf("\n");
 }