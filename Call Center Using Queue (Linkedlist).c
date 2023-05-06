#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addCustomer();
void removeCustomer();
void displayCustomerList();

typedef struct Node
{
    int callTime;
    int callID;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;
int count = 0;

void addCustomer()
{
    if (count == 10)
    {
        printf("\nQueue is full. Cannot add more calls.\n");
        return;
    }

    int callTime = rand() % 10 + 1;
    int callID = rand() % 90000 + 10000;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->callTime = callTime;
    newNode->callID = callID;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("New customer added to the queue\n");
    printf("- Customer ID: %d \n- Call Duration: %d minute(s)\n", callID, callTime);

    count++;
}

void removeCustomer()
{
    if (front == NULL)
    {
        printf("\nQueue is empty. No calls to Remove.\n");
        return;
    }

    Node *temp = front;
    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    printf("\nCustomer ID %d is removed from the queue.\n", temp->callID);
    free(temp);

    count--;
}

void displayCustomerList()
{
    if (front == NULL)
    {
        printf("\nQueue is empty. No calls to display.\n");
        return;
    }

    printf("\nCalls in the queue:\n");

    Node *temp = front;
    while (temp != NULL)
    {
        printf("Call ID: %d, Time: %d minute(s)\n", temp->callID, temp->callTime);
        temp = temp->next;
    }
}

int main()
{
    srand(time(NULL));
    int operation;

    while (1)
    {
        printf("\n-- Welcome to Call Center --\n\n");
        printf("- Press 1 : Add a new customer call to the queue.\n");
        printf("- Press 2 : Remove the customer call from the queue.\n");
        printf("- Press 3 : Display all the customer calls in the queue.\n");
        printf("- Press 4 : Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            addCustomer();
            break;

        case 2:
            removeCustomer();
            break;

        case 3:
            displayCustomerList();
            break;

        case 4:
            printf("\nExiting the program...\n");
            return 0;

        default:
            printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}
