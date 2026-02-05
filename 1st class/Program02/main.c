// Reverse a singly linked list.

#include <stdio.h>          // 1 
#include <stdlib.h>         // 1 
struct Node {               // 1 
int data;               // 1 
struct Node* next;      // 1 
}; 
void reverse(struct Node** head_ref) {   // T₀(n) 
struct Node* prev = NULL;                // 1 
struct Node* current = *head_ref;        // 1 
struct Node* next = NULL;                // 1 
while (current != NULL) {                // n + 1 
next = current->next;                    // n 
current->next = prev;                    // n 
prev = current;                          //n 
        current = next;                  // n 
    } 
    *head_ref = prev;                    // 1 
} 
 
void printList(struct Node* node) {       // T₁(n) 
    while (node != NULL) {                // n + 1 
        printf("%d ", node->data);        // n 
        node = node->next;                // n 
    } 
    printf("\n");                         // 1 
} 
 
int main() {                              // 1 
    struct Node* head = NULL;             // 1 
 
    // Create list of n nodes 
    head = (struct Node*)malloc(sizeof(struct Node)); // 1 
    head->data = 1;                                   // 1 
    head->next = (struct Node*)malloc(sizeof(struct Node)); // 1 
    head->next->data = 2;                                   // 1 
    head->next->next = (struct Node*)malloc(sizeof(struct Node)); // 1 
    head->next->next->data = 3;                                   // 1 
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node)); // 1 
    head->next->next->next->data = 4;                    // 1 
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node)); // 1 
    head->next->next->next->next->data = 5;                                   // 1 
    head->next->next->next->next->next = NULL;  // 1 
 
    printf("Original list: ");             // 1 
    printList(head);                       // T₁(n) 
 
    reverse(&head);                        // T₀(n) 
 
    printf("Reversed list: ");             // 1 
    printList(head);                       // T₁(n) 
 
    return 0;                              // 1 
}