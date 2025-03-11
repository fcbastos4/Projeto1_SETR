#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_ELEMENTS 100 // Maximum number of elements in the DLL
#define ELEMENT_SIZE 32  // Size of each element's data

// DLL Node structure
typedef struct DLLNode {
    uint16_t key; // Unique identifier for the node
    unsigned char data[ELEMENT_SIZE]; // Data storage
    struct DLLNode* prev; // Pointer to the previous node
    struct DLLNode* next; // Pointer to the next node
} DLLNode;

// DLL structure
typedef struct {
    DLLNode nodes[MAX_ELEMENTS]; // Statically allocated array of nodes
    DLLNode* head; // Pointer to the head of the list
    DLLNode* tail; // Pointer to the tail of the list
    int count; // Current number of elements in the list
} DoublyLinkedList;

DoublyLinkedList myDLL;

// Initialize the doubly linked list
void MyDLLInit() {
    myDLL.head = NULL;
    myDLL.tail = NULL;
    myDLL.count = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        myDLL.nodes[i].key = 0; // Mark node as unused
        myDLL.nodes[i].prev = NULL;
        myDLL.nodes[i].next = NULL;
    }
}

// Insert an element into the DLL
int MyDLLInsert(uint16_t key, unsigned char* data) {
    if (myDLL.count >= MAX_ELEMENTS) return -1; // List is full
    
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (myDLL.nodes[i].key == 0) { // Find an empty slot
            myDLL.nodes[i].key = key;
            memcpy(myDLL.nodes[i].data, data, ELEMENT_SIZE); // Copy data
            myDLL.nodes[i].prev = myDLL.tail;
            myDLL.nodes[i].next = NULL;
            
            if (myDLL.tail) myDLL.tail->next = &myDLL.nodes[i]; // Update previous tail's next pointer
            myDLL.tail = &myDLL.nodes[i]; // Update tail pointer
            if (!myDLL.head) myDLL.head = &myDLL.nodes[i]; // Update head if list was empty
            
            myDLL.count++;
            return 0; // Success
        }
    }
    return -1; // Failure
}

// Remove an element from the DLL by key
int MyDLLRemove(uint16_t key) {
    DLLNode* current = myDLL.head;
    while (current) {
        if (current->key == key) {
            if (current->prev) current->prev->next = current->next; // Update previous node's next pointer
            if (current->next) current->next->prev = current->prev; // Update next node's prev pointer
            if (current == myDLL.head) myDLL.head = current->next; // Update head if necessary
            if (current == myDLL.tail) myDLL.tail = current->prev; // Update tail if necessary
            
            current->key = 0; // Mark node as unused
            myDLL.count--;
            return 0; // Success
        }
        current = current->next;
    }
    return -1; // Not found
}

// Find an element in the DLL by key
int MyDLLFind(uint16_t key) {
    DLLNode* current = myDLL.head;
    while (current) {
        if (current->key == key) {
            printf("\nElement with key %hu found. Data: %s\n", key, current->data);
            return 0; // Found
        }
        current = current->next;
    }
    printf("\nElement with key %hu not found.\n", key);
    return -1; // Not found
}

// Find the next and previous elements by key
void MyDLLFind_N_P(uint16_t key) {
    DLLNode* current = myDLL.head;
    while (current) {
        if (current->key == key) {
            if (current->prev) {
                printf("\nPrevious Element -> Key: %hu, Data: %s\n", current->prev->key, current->prev->data);
            } else {
                printf("\nNo previous element.\n");
            }
            
            if (current->next) {
                printf("Next Element -> Key: %hu, Data: %s\n", current->next->key, current->next->data);
            } else {
                printf("No next element.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("\nElement with key %hu not found.\n", key);
}

int main() {
    MyDLLInit(); // Initialize the list
    int choice;
    uint16_t key;
    unsigned char data[ELEMENT_SIZE];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Remove Element\n");
        printf("3. Find Element\n");
        printf("4. Find Next & Previous Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%hu", &key);
                printf("Enter data: ");
                scanf("%s", data);
                if (MyDLLInsert(key, data) == 0) {
                    printf("Element inserted successfully.\n");
                } else {
                    printf("Failed to insert element.\n");
                }
                break;
            
            case 2:
                printf("Enter key to remove: ");
                scanf("%hu", &key);
                if (MyDLLRemove(key) == 0) {
                    printf("Element removed successfully.\n");
                } else {
                    printf("Element not found.\n");
                }
                break;
            
            case 3:
                printf("Enter key to find: ");
                scanf("%hu", &key);
                MyDLLFind(key);
                break;
            
            case 4:
                printf("Enter key to find next and previous: ");
                scanf("%hu", &key);
                MyDLLFind_N_P(key);
                break;
            
            case 5:
                return 0; // Exit program
            
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
