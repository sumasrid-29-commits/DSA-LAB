#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
/* Create Doubly Linked List */
void create()
{
    int choice = 1;
    struct node *newnode, *temp;
    while(choice == 1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Press 1 to continue: ");
        scanf("%d", &choice);
    }
}
/* Forward Traversal */
void display_forward()
{
    struct node *temp = head;
    printf("Forward: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
/* Backward Traversal */
void display_backward()
{
    struct node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Backward: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
/* Insert at Beginning */
void insert_begin()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
/* Insert at End */
void insert_end()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->next = NULL;
    newnode->prev = temp;
    temp->next = newnode;
}
/* Insert at Position */
void insert_pos()
{
    int pos, i = 1;
    struct node *newnode, *temp;
    printf("Enter position: ");
    scanf("%d", &pos);
    temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}
/* Delete from Beginning */
void delete_begin()
{
    struct node *temp;
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    printf("First node deleted\n");
}
/* Delete from End */
void delete_end()
{
    struct node *temp;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}
/* Delete from Position */
void delete_pos()
{
    int pos, i = 1;
    struct node *temp;
    printf("Enter position: ");
    scanf("%d", &pos);
    temp = head;
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("Node deleted\n");
}
/* Reverse Doubly Linked List */
void reverse()
{
    struct node *temp = NULL;
    struct node *current = head;
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != NULL)
    {
        head = temp->prev;
    }
    printf("Doubly Linked List Reversed\n");
}
/* Main Function */
int main()
{
    create();
    display_forward();
    display_backward();
    insert_begin();
    display_forward();
    insert_end();
    display_forward();
    insert_pos();
    display_forward();
    delete_begin();
    display_forward();
    delete_end();
    display_forward();
    delete_pos();
    display_forward();
    reverse();
    display_forward();
    return 0;
}