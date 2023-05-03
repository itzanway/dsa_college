
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};
void insertFront(struct node** head,int data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
}
