#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * front;
struct node * rear;
int index;
void insert(int item) {
    struct node * new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("OVERFLOW\n");
        return;
    }

    new_node->data = item;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void delete(int index) {
    struct node * temp = front;
    struct node * prev = NULL;

    int i = 0;

    if (index == 0) {
        front = front->next;
        free(temp);
        return;
    }

    while (i < index) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    prev->next = temp->next;
    free(temp);
}

void display() {
    struct node * temp = front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    front = NULL;
    rear = NULL;

    int choice, item;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                printf("Enter the index of the node to be deleted: ");
                scanf("%d",&index);
                delete(index);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
