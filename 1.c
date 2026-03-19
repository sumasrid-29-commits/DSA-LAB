#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
/* Create Linked List */
void create()
{
    int choice = 1;
    struct node *newnode, *temp;
    while(choice == 1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Press 1 to continue: ");
        scanf("%d", &choice);
    }
}
/* Display Linked List */
void display()
{
    struct node *temp = head;
    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
/* Count Nodes */
int count()
{
    struct node *temp = head;
    int c = 0;
    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
/* Insert at Beginning */
void insert_begin()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
/* Insert at End */
void insert_end()
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
/* Insert at Given Position */
void insert_pos()
{
    int pos, i = 1;
    struct node *newnode, *temp;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos == 1)
    {
        insert_begin();
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    temp = head;
    while(i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
/* Delete from Beginning */
void delete_begin()
{
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted\n");
}
/* Delete from End */
void delete_end()
{
    struct node *temp, *prev;
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}
/* Delete from Given Position */
void delete_pos()
{
    int pos, i = 1;
    struct node *temp, *nextnode;
    printf("Enter position: ");
    scanf("%d", &pos);
    temp = head;
    while(i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    printf("Node deleted\n");
}
/* Reverse Linked List */
void reverse()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextnode;
    while(current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
    printf("Linked List Reversed\n");
}
/* Main Function */
int main()
{
    int total;
    create();
    display();
    total = count();
    printf("Total nodes = %d\n", total);
    insert_begin();
    display();
    insert_end();
    display();
    insert_pos();
    display();
    delete_begin();
    display();
    delete_end();
    display();
    delete_pos();
    display();
    reverse();
    display();  
    return 0;
}