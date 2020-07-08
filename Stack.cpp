#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNode 
{	
	char* data;				
	struct sNode* next;	
}Node;

typedef struct listStack
{
	
	Node* peek;				
	int size;				

}listStack;

void createStack(listStack** Stack) 
{				

	(*Stack) = (listStack*)malloc(sizeof(listStack));
	(*Stack)->peek = NULL;							
	(*Stack)->size = 0;								
}

Node* createNode(char* newChar)
{						
	Node* newNode = (Node*)malloc(sizeof(Node));		
	newNode->data = (char*)malloc(strlen(newChar) + 1);	 

	strcpy(newNode->data,newChar);
	newNode->next = NULL;								
}

void deleteNode(Node* removeNode) {						
	free(removeNode -> data);					
	free(removeNode);								
}

void Push(listStack* Stack, Node* newNode) {		
	
	if (Stack->size == 0) {								
		Stack->peek = newNode;
	}
	else {												
		Stack->peek = newNode;																					
	}
	Stack->size++;
}

Node* Pop(listStack* Stack) {						
	Node* tempNode;										

	if (Stack->size == 0) {								
		printf("stack is empty");				
		tempNode = NULL;
	}
	else {									
		tempNode = Stack->peek;							
		Stack->peek = Stack->peek->next;				
		Stack->size--;									
	}
	return tempNode;									
}

void deleteStack(listStack* Stack) {
	int count = Stack->size;
	int i;
	Node* tempNode;

	for (i = 0; i < count; i++) {
		tempNode = Pop(Stack);
		deleteNode(tempNode);
	}

	free(Stack);
}

int main()
{
	int i;
	listStack* Stack;

	createStack(&Stack);

		Push(Stack, createNode("a"));
		Push(Stack, createNode("b"));
		Push(Stack, createNode("c"));
		Push(Stack, createNode("d"));

		printf("abcd pushed\n");

		printf("\n--Current Stack--[size:%d]\n\n", Stack->size);

		Node* horse = Stack->peek;
		for (i = 0; i < (Stack->size); i++) {
			printf("%s\n", horse->data);
			horse = horse->next;
		}

		horse = Pop(Stack);
		horse = Pop(Stack);
		horse = Pop(Stack);
		horse = Pop(Stack);

		printf("\n--Current Stack--[size:%d]\n\n", Stack->size);
		horse = Stack-> peek;
		for (i = 0; i < (Stack->size); i++) {
			printf("%s\n", horse->data);
			horse = horse->next;
		}

		deleteStack(Stack);
		printf("\nStack has been completely free\n");
}
