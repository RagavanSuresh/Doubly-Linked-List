/*  Complete program of implementation and algorithms of
             doubly linked list
                                -K.S.Ragavan
*/

/*
    pre-requisite: Singly Linked List
    A doubly linked list contains a pointer to the next node as well as the previous node.
    This ensures that the list can be traversed in both directions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
}*head = NULL,*temp,*newnode,*tail=NULL;

void create(int); // to create new nodes in linked list
void insertlast(); // insert the created node in the last position
void deletelast(); // delete the last node of the linked list
bool search(int); // to search for a particular node using the value of the data
void display(); // to display the linked list
void reversedisplay(); // to display the linked list in reverse order
void insertfirst(); // to insert the created node at the first position
void insertafter(int); // to insert the node after a particular node using value of the node
void discard(int); // to delete a node in the list by entering the value of the node
void middlenode(); // to find the middle node of the linked list
void lasttofirst(); // to move the last node to the first position

void create(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
}

void insertfirst()
{
    printf("Enter the number to be inserted at first: ");
    int key;
    scanf("%d",&key);
    if(head==NULL)
    {
        create(key);
        head = (struct node*)malloc(sizeof(struct node));
        head = tail = newnode;
    }
    else
    {
        create(key);
        temp = newnode;
        temp->next = head;
        head = temp;
        temp->next->prev = temp;
    }
}

void insertlast()
{
    printf("Enter the number to be inserted at last: ");
    int key;
    scanf("%d",&key);
    if(head==NULL)
    {
        create(key);
        head = (struct node*)malloc(sizeof(struct node));
        head = newnode;
    }
    else
    {
        create(key);
        temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
    }
}


void insertafter(int data)
{
    printf("Enter the number to be inserted: ");
    int key;
    scanf("%d",&key);
    if(head==NULL)
    {
        create(key);
        head = (struct node*)malloc(sizeof(struct node));
        head = newnode;
    }
    else
    {
        temp=head;
        while(temp->data!=data&&temp->next!=NULL)
            temp=temp->next;
        create(key);
        struct node* temp1 = (struct node*)malloc(sizeof(struct node));
        temp1 = newnode;
        temp1->next = temp->next;
        temp->next->prev = temp1;
        temp1->prev=temp;
        temp->next = temp1;
        if(temp1->next==NULL)
            tail = temp1;
    }
}

void display()
{
    temp = head;
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
            printf("%d ",temp->data);
        else
            printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void reversedisplay()
{
    temp = tail;
    while(temp!=NULL)
    {
        if(temp->prev!=NULL)
            printf("%d ",temp->data);
        else
            printf("%d\n",temp->data);
        temp = temp->prev;
    }
}


bool search(int key)
{
    temp = head;
    while(temp!=NULL)
    {
        if(temp->data==key)
            return true;
        temp = temp->next;
    }
    return false;
}

void deletelast()
{
    temp = head;
    if(temp==NULL)
        printf("Stack Underflow\n");
    else if(temp->next==NULL)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
            temp=temp->next;
        free(temp->next);
        temp->next=NULL;
        tail = temp;
    }
}

void discard(int data)
{
    if(search(data))
    {
        if(head == NULL)
        {
            printf("List doesn't exist to delete.\n");
        }
        else
        {
            temp = head;
            if(temp->data==data)
            {
                head = head->next;
                free(temp);
                return;
            }
            while(temp!=NULL)
            {
                if(temp->next->data==data)
                {
                    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
                    temp1 = temp->next;
                    if(temp1->next==NULL)
                    {
                        temp->next = temp1->next;
                        tail = temp;
                    }
                    else
                    {
                        temp->next = temp1->next;
                        temp1->next->prev=temp;
                    }
                    free(temp1);
                    return;
                }
                temp = temp->next;
            }
        }
    }
    else
    {
        printf("Data entered doesn't exist in the list.\n");
    }
}


void middlenode()
{
    if(head==NULL)
    {
        printf("List doesn't exist.\n");
        return;
    }
    else
    {
        int count=0; // keeps the number of nodes in the list
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        } // count is now updated with the number of the nodes in the list
        temp=head;
        for(int i=0;i<count/2;i++)
            temp=temp->next; // middle node is found and arrived
        printf("The middle node is %d.\n",temp->data);
    }
}

void lasttofirst()
{
    if(head==NULL)
    {
        printf("List doesn't exist\n");
        return;
    }
    else if(head->next==NULL)
        return;
    else
    {
        temp = head;
        while(temp->next->next!=NULL)
            temp=temp->next;
        struct node* temp1 = (struct node*)malloc(sizeof(struct node)); // new node is temporarily created to keep track of the last node
            temp1 = temp->next; //last node assigned to the created node
        temp->next=temp1->next;  // null being assigned to the penultimate node making it the final node
        tail = temp;
        temp1->next = head;// inserting the last node as the first node
        head->prev = temp1;
        head = temp1;// assigning the last node as the first node
        head->prev = NULL;
    }
}

int main()
{
    printf("\t\t\tMENU BAR!!!\n"); // to guide user through various functions of the list
    printf("1. Insert Element at last\n");
    printf("2. Insert Element at first\n");
    printf("3. Insert Element after a specific element\n");
    printf("4. Delete Element at last\n");
    printf("5. Delete a specific Element\n");
    printf("6. Display\n");
    printf("7. Display in reverse order\n");
    printf("8. Search\n");
    printf("9. Finding the Middle Node\n");
    printf("10. Move Last node to first place\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            insertlast();
            break;
        case 2:
            insertfirst();
            break;
        case 3:
            {
                int key;
                printf("After which element should the new element be inserted: ");
                scanf("%d",&key);
                insertafter(key);
            }
            break;
        case 4:
            deletelast();
            break;
        case 5:
            {
                int key;
                printf("Which element should be deleted: ");
                scanf("%d",&key);
                discard(key);
            }
            break;
        case 6:
            display();
            break;
        case 7:
            reversedisplay();
            break;
        case 8:
        {
            printf("Enter element to be searched for: ");
            int key;
            scanf("%d",&key);
            if(search(key))
                printf("%d is found.\n",key);
            else
                printf("%d is not found.\n",key);
        }
        break;
        case 9:
            middlenode();
            break;
        case 10:
            lasttofirst();
            break;
        default:
            printf("Invalid input found!!!\n");
    }
    printf("Do you want to continue[Y/N]: ");
    char control;
    scanf(" %c",&control);
    if(control=='y'||control=='Y')
    {
        system("pause");
        system("cls");
        main();
    }
    return 0;
}

/*
    For further documentation and explanation on logic
    Pls refer previous program on Singly Linked List
*/
