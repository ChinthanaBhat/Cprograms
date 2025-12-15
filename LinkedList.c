#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL, *q, *t;

int main()
{
    int ch;
    void insert_beg();
    void display();
    void delete_beg();
    void delete_end();
    int delete_given_element();

    while (1)
    {
        printf("\n\n---- Singly Linked List(SLL) Menu ----");
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n\n");
        printf("Enter your choice(1-4):");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\n---- Insert Menu ----");
            printf("\n1.Insert at beginning \n 2.Exit");
            printf("\n\nEnter your choice(1-2):");
            scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                insert_beg();
                break;
            case 2:
                exit(0);
            default:
                printf("Wrong Choice!!");
            }
            break;

        case 2:
            display();
            break;

        case 3:
            printf("\n---- Delete Menu ----");
            printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete a given element\n4.Exit");
            printf("\n\nEnter your choice(1-4):");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                delete_beg();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                delete_given_element();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice!!");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice!!");
        }
    }
    return 0;
}

void insert_beg()
{
    int num;
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &num);
    t->data = num;

    if (start == NULL) // If list is empty
    {
        t->next = NULL;
        start = t;
    }
    else
    {
        t->next = start;
        start = t;
    }
}

void display()
{
    if (start == NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        q = start;
        printf("The linked list is:\n");
        while (q != NULL)
        {
            printf("%d->", q->data);
            q = q->next;
        }
    }
}

void delete_beg()
{
    if (start == NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q = start;
        start = start->next;
        printf("Deleted element is %d", q->data);
        free(q);
    }
}
void delete_end()
{
    if (start == NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q = start;
        while (q->next->next != NULL)
            q = q->next;
        t = q->next;
        q->next = NULL;
        printf("Deleted element is %d", t->data);
        free(t);
    }
}
int delete_given_element()
{
    int ele, i;

    if (start == NULL)
    {
        printf("List is empty!!");
        return 0;
    }

    printf("Enter the element to delete:");
    scanf("%d", &ele);

    q = start;
    t = NULL;

    if (start->data == ele)
    {
        printf("\nThe deleted element is %d", start->data);
        start = start->next;
        free(q);
    }

    while (q != NULL)
    {
        if (q->data == ele)
        {
            printf("\nThe deleted element is % d", q->data);
            t->next = q->next;
            free(q);
            return 0;
        }
        t = q;
        q = q->next;
    }
    if (q == NULL)
    {
        printf("\nThe deleted element is not found");
        return 0;
    }
}