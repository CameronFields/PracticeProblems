#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



struct node{
	int data;
	int key;
	struct node *next;
};


struct node *head=NULL;
struct node *curr=NULL;

//PRINT LIST
void printList(){
	struct node *ptr = head;
	printf("\n[ ");
	while(ptr!=NULL){
		printf("(%d,%d) ", ptr->key, ptr->data);
		ptr=ptr->next;
	}
	printf(" ]");
}

void insertFirst(int key, int data){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	//setting parameter data/key
	link->key = key;
	link->data = data;
	//adding a node to space in which the next node is the orginial head
	link->next = head; 
	//setting the global variable of head to the link, creating a new head
	head = link;
}


//function that returns deleted node.
struct node* deleteFirst(){
	struct node *tempLink=head;
	head = head->next;
	return tempLink;
}



//return bool val of empty
bool isEmpty(){
	return head == NULL;
}


//length of LL
int length(){
	int length = 0; 
	struct node *current;
	for(current = head; current != NULL; current = current->next){
		length++;
	}
	return length;
}


//find a link with given key
struct node* find(int key){
	struct node* current = head;

	if(head==NULL){
		return NULL;
	}
	
	while(current->key!=key){
		if(current->next == NULL){
			return NULL;
		} else { 
			current = current->next;	
		}
	}
	return current;
}


//delete a link with a given key
struct node* delete (int key){
	struct node* current=head;
	struct node* previous=NULL;

	if(head == NULL){
		return NULL;
	}

	while(current->key != key){
		if(current->next == NULL){
			return NULL;
		} else {
			previous = current;
			current = current->next;
		}
	}
	
	if(current == head){
		head = head->next;
	} else { 
		previous->next = current->next;
	}
	return current;
}



void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
	
   //print list
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
   }  
	
   printf("\nList after deleting all items: ");
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   printf("\nRestored List: ");
   printList();
   printf("\n");  

   struct node *foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");  
   } else {
      printf("Element not found.");
   }

   delete(4);
   printf("List after deleting an item: ");
   printList();
   printf("\n");
   foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }
	



}
