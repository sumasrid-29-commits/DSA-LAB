#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Insert at end
void insert(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display list
void display(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 11. Search and Update
void searchUpdate(int key, int newVal) {
    struct node* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            printf("Found! Updating...\n");
            temp->data = newVal;
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

// 12. Middle element
void findMiddle() {
    struct node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow != NULL)
        printf("Middle element: %d\n", slow->data);
}

// 13. Maximum element
void findMax() {
    struct node* temp = head;
    int max = temp->data;

    while(temp != NULL) {
        if(temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("Max = %d\n", max);
}

// 14. Minimum element
void findMin() {
    struct node* temp = head;
    int min = temp->data;

    while(temp != NULL) {
        if(temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("Min = %d\n", min);
}

// 15. Sum of elements
void findSum() {
    struct node* temp = head;
    int sum = 0;

    while(temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum = %d\n", sum);
}

// 16. Recursive length
int length(struct node* temp) {
    if(temp == NULL)
        return 0;
    return 1 + length(temp->next);
}

// 17. Separate even and odd
void separateEvenOdd() {
    struct node *even = NULL, *odd = NULL;
    struct node *eTail = NULL, *oTail = NULL;
    struct node* temp = head;

    while(temp != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = temp->data;
        newNode->next = NULL;

        if(temp->data % 2 == 0) {
            if(even == NULL) {
                even = eTail = newNode;
            } else {
                eTail->next = newNode;
                eTail = newNode;
            }
        } else {
            if(odd == NULL) {
                odd = oTail = newNode;
            } else {
                oTail->next = newNode;
                oTail = newNode;
            }
        }
        temp = temp->next;
    }

    printf("Even List: ");
    display(even);
    printf("Odd List: ");
    display(odd);
}

// 18. Remove duplicates
void removeDuplicates() {
    struct node *ptr1, *ptr2, *dup;

    ptr1 = head;
    while(ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while(ptr2->next != NULL) {
            if(ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

// MAIN
int main() {
    int n, val, key, newVal;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(val);
    }

    printf("Linked List: ");
    display(head);

    // 11
    printf("Enter element to search & update: ");
    scanf("%d %d", &key, &newVal);
    searchUpdate(key, newVal);
    display(head);

    // 12
    findMiddle();

    // 13
    findMax();

    // 14
    findMin();

    // 15
    findSum();

    // 16
    printf("Length = %d\n", length(head));

    // 17
    separateEvenOdd();

    // 18
    removeDuplicates();
    printf("After removing duplicates:\n");
    display(head);

    return 0;
}