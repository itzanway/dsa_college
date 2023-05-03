#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node *InsertAtFirst(struct Node *head)
{
    struct Node *temp = head;
    int data;
    printf("Enter the data you want to insert in list\n");
    scanf("%d", &data);
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    while(temp->next!=head) {
        temp=temp->next;
    }

    temp->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *InsertAtIndex(struct Node *head,int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp;
    temp = head;
    int index, i = 0;

  //  printf("Enter the data you want to insert in list\n");
  //  scanf("%d", &data);

    printf("enter the index you want to insert data in\n");
    scanf("%d", &index);

    do{
        temp = temp->next;
        i++;
    }while (i != index - 1);

    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp;
    temp = head->next;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->next = head;

    return head;
}

struct Node *DeletionAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    struct Node * temp;
    temp=head->next;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    head=ptr;
    head=head->next;
    free(ptr);
    return head;
}

struct Node *DeletionAtIndex(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    int i, index;

    printf("Enter the index at which you want to delete the node\n");
    scanf("%d", &index);

    for (i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

struct Node *DeletionAtValue(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    int value;

    printf("Enter the value you want to delete the node\n");
    scanf("%d", &value);

    while (q->data != value)
    {
        q = q->next;
    }
    if (q->data != value)
    {
        printf("NO such value found\n");
    }
    else
    {
        ptr->next = q->next;
        free(q);
    }

    return head;
}

struct Node *DeletionAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != head)
    {
        q = q->next;
        p = p->next;
    }
    p->next = head;
    free(q);
    return head;
}

void PrintList()
{
    struct Node *temp;
    temp = head;
    int i=0;

    do
    {
        printf("the value at index %d is %d\n",i, temp->data);
        temp = temp->next;
        i++;
    } while (temp!=head);

    printf("\n");
}

void CreateList()
{
    struct Node *temp;
    int choice = 1;
    do {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        printf("enter the value in node : \n");
        int x;
        scanf("%d", &x);
        new_node->data = x;
        if (head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }
        temp->next = head;
        printf("Do you want to enter another value (1/0) : \n");
        scanf("%d", &choice);
    } while(choice!=0);
}
int main()
{
    int data, n=1;
    printf("MENU\n");
    printf("1.to create List\n");
    printf("2.to display the list\n");
    printf("3.to Insert data at first\n");
    printf("4.to Insert data at index\n");
    printf("5.to Insert data at end\n");
    printf("6.to delete node at first\n");
    printf("7.to delete Node at given index\n");
    printf("8.to delete Node at given value\n");
    printf("9.to delete Node at end\n");
    printf("0.Exit\n");

    while(1)
    {
        printf("Enter the 'n' to get your choice : ");
        scanf("%d", &n);
            // int choice = 1;
            // struct Node *temp = head;

        switch (n)
        {
            case 1:
                CreateList();
                break;

            case 2:
                printf("Circular List is :\n");
                PrintList();
                break;

            case 3:
                head = InsertAtFirst(head);
                printf("LIST UPDATED SUCCESFULLY\n");
                break;

            case 4:
                printf("Enter the data you want to insert in list\n");
                scanf("%d", &data);
                
                head = InsertAtIndex(head,data);
                printf("LIST UPDATED SUCCESFULLY\n");

                break;
                      
            case 5:
                printf("Enter the data you want to insert in list\n");
                scanf("%d", &data);
                head = InsertAtEnd(head, data);
                printf("LIST UPDATED SUCCESFULLY\n");

                break;

            case 6:
                head = DeletionAtFirst(head);
                printf("LIST UPDATED SUCCESFULLY\n");
                break;

            case 7:
                head = DeletionAtIndex(head);
                printf("LIST UPDATED SUCCESFULLY\n");

                break;

            case 8:
                head = DeletionAtValue(head);
                printf("LIST UPDATED SUCCESFULLY\n");

                break;

            case 9:
                head = DeletionAtEnd(head);
                printf("LIST UPDATED SUCCESFULLY\n");

                break;

            case 0:
                printf("exiting the program.....\n");        //you can press 0 to exit the given program
                return 0;
            default:
                printf("INVALID CHOICE, TRY AGAIN\n");
        }
    }
}
