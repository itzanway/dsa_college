#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void linkedlisttraversal(struct Node *ptr){
	while(ptr!=NULL){
		printf("Elements :%d\n",ptr->data);
		ptr=ptr->next;
	}
}

struct Node *insertatfirst(struct Node *head,int data){
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->data=data;
	
	ptr->next=head;
	return ptr;
}

struct Node *insertatindex(struct Node *head,int data,int index){
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	struct Node *p=head;
	int i=0;
	
	while(i!=index-1){
		p=p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	
	return head;
	
}

int main(){
	struct Node *head;
	head=(struct Node *)malloc(sizeof(struct Node));
	
	struct Node *second;
	second=(struct Node *)malloc(sizeof(struct Node));
	
	struct Node *third;
	third=(struct Node *)malloc(sizeof(struct Node));
	
	struct Node *fourth;
	fourth=(struct Node *)malloc(sizeof(struct Node));
	
	head->data=12;
	head->next=second;
	
	second->data=23;
	second->next=third;
	
	third->data=44;
	third->next=fourth;
	
	fourth->data=45;
	fourth->next=NULL;
	
	linkedlisttraversal(head);
	
	
	head=insertatfirst(head,78);
	
	linkedlisttraversal(head);
	
	printf("afetr changes\n");
	
	head=insertatindex(head,56,3);
	
	linkedlisttraversal(head);
}
