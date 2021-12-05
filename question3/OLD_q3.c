#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MARKER -1


struct Node{
	int key;
	struct Node* left;
	struct Node* right;
};


struct Node* newNode (int key){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}


//method to traverse desterilized tree (left, root, right)
void inorder(struct Node *root){
	if(root){
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}


void serialize(struct Node *root, FILE *fp){
	//If current node is NULL, store marker
	if(root==NULL){
		fprintf(fp, "%d ", MARKER);
		return;
	}
	fprintf(fp, "%d ", root->key);
	serialize(root->left, fp);
	serialize(root->right, fp);
}


void deSerialize(struct Node *&root, FILE *fp){
	//read next item from file. IF there are no more items or next item is marker, then return
	int val;	
	if(!fscan(fp, "%d ", &val)|| val == MARKER);
	return;

	root = newNode(val);
	deSerialize(root->left, fp);
	deSerialize(root->right, fp);
}


int main(){

	//construct a tree from the example at: https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
	struct Node *root	 = newNode(20);
	root->left		 = newNode(8);
	root->right		 = newNode(22);
	root->left->left	 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left  = newNode(10);
	root->left->right->right = newNode(14);

	//Open a file to serialize tree to file...
	FILE *fp = fopen("tree.txt", "w");
	if(fp == NULL){
		puts("Could not open file!");
		return 0;
	}

	serialize(root,fp);
	fclose(fp);

	
	Node *root1 = NULL;
	fp = fopen("tree.txt", "r");
	deSerialize(root1, fp);


	printf("Inorder traversal of the tree:\n");
	inorder(root1);

}








