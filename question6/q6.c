#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>



//doubly linked list
//instead of field prev and next, the field both is an XOR on prev and next node

struct Node{
	int data;
	struct Node *npx; // next, previous xor
};


struct Node *XOR(struct Node *a, struct Node *b){
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

//add, takes an element and adds it to the XOR LL
void insert(struct Node **head_ref, int data){
	struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) );
	new_node->data = data;

	//Since new node is being inserted at the beginning, npx of new node will always be XOR of current head and NULL
	new_node->npx = *head_ref;

	if(*head_ref != NULL){
		(*head_ref)->npx = XOR(new_node, (*head_ref)->npx);
	}
	*head_ref = new_node;
}



void printList (struct Node *head){
	struct Node *curr = head;
	struct Node *prev = NULL;
	struct Node *next;

	printf("Following are the nodes of the XOR linked list: \n");

	while(curr!=NULL){
		printf("%d \n", curr->data);

		//get address of next node curr->npx is next^prev, so curr->npx^prev will be next^prev^prev which is next
		next = XOR (prev, curr->npx);

		//update prev and curr for next iteration
		prev = curr;
		curr = next;
	}
}


//get, takes an index of the XOR LL and returns the node at that index (use pointers)

struct Node *getNode(struct Node *head, int index){
	struct Node *curr = head;
	struct Node *prev = NULL; 
	struct Node *next;
	int counter; 
	
	while(curr!=NULL){
		if(counter == index){
			return curr;
		} else {
	
		//calc next
		next = XOR(prev, curr->npx);
		
		//iterate	
		prev = curr;
		curr = next;
		counter++;	
		}
	}
}



int main(){
	
	// head --> 40 <--> 30 <--> 20 <--> 10
	struct Node *head = NULL;
	insert(&head, 10);			//addr(a) = NULL ^ addr(b)
	insert(&head, 20);			//addr(b) = addr(a) ^ addr(c)
	insert(&head, 30);			//addr(c) = addr(b) ^ addr(d)
	insert(&head, 40);			//addr(d) = addr(c) ^ NULL

	printList (head);
	
	printf("%d \n", getNode(head,1)->data);

	return (0);

}
