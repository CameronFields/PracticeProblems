#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



//doubly linked list
//instead of field prev and next, the field both is an XOR on prev and next node




struct node{
	int data;
	int key;

	struct node *next;
	struct node *prev;
};


//this link always points to first Link
struct node *head = NULL;

//this link always points to last link
struct node *last = NULL;


struct node *curr = NULL;


bool isEmpty(){
	return head == NULL;
}

int length(){
	int length = 0;
	struct node *current;
	for(current = head; current != NULL; current = current->next){
		length++;
	}
	return length;
}







int main(){

}
