#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct univalNode{
	int key;
	struct univalNode* left;
	struct univalNode* right;
};


struct univalNode* newNode (int key){
	struct univalNode* temp = (struct univalNode*)malloc(sizeof(struct univalNode));
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

int countUnivalTree(struct univalNode *node){
	//return value 
	int count = 0;
	if(node->left==NULL && node->right == NULL){
		return 1;
	}
	if(node->left->key == node->right->key){
		count++;
	}
	if(node->left != NULL){
		count += countUnivalTree(node->left);
	}
	if(node->right != NULL){
		count += countUnivalTree(node->right);
	}
	return count;
}


int main(){
	//creating the example tree found in Question8.txt
	struct univalNode *root =  newNode(0);
	root->left = 		   newNode(1);
	root->right =		   newNode(0);
	root->right->left =	   newNode(1);
	root->right->right = 	   newNode(0);
	root->right->left->left =  newNode(1);
	root->right->left->right = newNode(1);
	printf("Total number of UniVal trees: %d\n", countUnivalTree(root));
}






