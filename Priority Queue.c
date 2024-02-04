#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int priority;
    struct node* next;
};

struct node* head = NULL;

void enqueuePriority() {
    struct node* ptr, * s, * w;
    int d, p, f = 0;
    printf("Enter the data of the queue: ");
    scanf("%d", &d);
    printf("Enter the priority of the queue: ");
    scanf("%d", &p);
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->priority = p;
    ptr->next = NULL;

    if (head == NULL || p > head->priority) {
        ptr->next = head;
        head = ptr;
    } else {
        w = head;
        s = head->next;
        while (s != NULL && s->priority > p) {
            w = w->next;
            s = s->next;
        }
        w->next = ptr;
        ptr->next = s;
    }
}

int deletePriority() {
    if (head == NULL) {
        printf("Queue is empty. Deletion not possible.\n");
        return -1; // Return a special value to indicate an empty queue
    }

    struct node* s;
    int t;
    s = head;
    t = s->data;
    head = head->next;
    free(s);
    return t;
}

void display() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node* s;
    s = head;
    while (s != NULL) {
        printf("\t%d", s->data);
        s = s->next;
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("0. Exit\n");
        printf("1. Insert in a priority queue\n");
        printf("2. Delete from a priority queue\n");
        printf("3. Display\n");
        printf("Enter your choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 0:
                printf("Exiting the program.\n");
                exit(0);

            case 1:
                enqueuePriority();
                break;

            case 2:
                {
                    int deletedElement = deletePriority();
                    if (deletedElement != -1) {
                        printf("The deleted element: %d\n", deletedElement);
                    }
                }
                break;

            case 3:
                display();
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
 }
}
}
