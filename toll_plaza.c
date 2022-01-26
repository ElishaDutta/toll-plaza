#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char data[30];
    int status;
    struct Node *next;
    struct Node *back;
};
struct deque
{
    struct Node *front, *rear;
};

void insert_at_front(struct deque *q)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Car Model:\t");
    scanf("%s", temp->data);
    temp->next = NULL;
    temp->back=NULL;
    if(q->front==NULL)
    {
        q->front=temp;
        q->rear=temp;
    }
    else
    {
        q->front->back=temp;
        temp->next=q->front;
        q->front=temp;
    }
}
void delete_from_front(struct deque *q)
{
    if(q->front==NULL)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        struct Node *temp=q->front;
        q->front=q->front->next;
        printf("\nProcessed Car is %s",temp->data);
        free(temp);
        if(q->front!=NULL)
           q->front->back=NULL;
        else
           q->rear=NULL;
    }

}
void insert_at_rear(struct deque *q,int choice)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter Car Model:\t");
    scanf("%s", temp->data);
    temp->status=choice;
    temp->next = NULL;
    temp->back = NULL;
    if (q->front == NULL)
    {
        q->front = temp;
        q->rear = temp;
    }
    else
    {
        q->rear->next = temp;
        temp->back = q->rear;
        q->rear = temp;
    }
}
void delete_from_rear(struct deque *q)
{
    if (q->front == NULL)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        struct Node *temp = q->rear;
        q->rear=q->rear->back;
        printf("\nSkipped Car is %s",temp->data);
        free(temp);
        if(q->rear!=NULL)
           q->rear->next = NULL;
        else
           q->front=NULL;
    }
}
int main()
{
        struct deque q;
        q.front=NULL;
        q.rear=NULL;
        while (1)
        {
            printf("\nEnter 0 to Exit");
            printf("\nEnter 1 for Two Wheeler");
            printf("\nEnter 2 for Four Wheeler");
            printf("\nEnter 3 for Bus");
            printf("\nEnter 4 for Truck");
            printf("\nEnter 5 for Ambulance");
            printf("\nEnter 6 for Firebrigade");
            printf("\nEnter 7 for High Security");
            int choice;
            printf("\nEnter choice:\t");
            scanf("%d", &choice);
            if (choice == 0)
            {
                break;
            }
            insert_at_rear(&q,choice);
            switch (choice)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                delete_from_rear(&q);
                break;
            case 6:
                delete_from_rear(&q);
                break;
            case 7:
                delete_from_rear(&q);
                break;
            default:
                printf("\nInvalid Choice");
            };
        }
        while (q.front != NULL)
        {
            delete_from_front(&q);
        }
        return 0;
    }
    /*
                            This    Code     is     Written  by
 _____  _      _                      _                    ___         _
/  __ \| |    (_)                    | |                  / _ \       | |
| /  \/| |__   _  _ __   __ _  _ __  | |_   __ _  _ __   / /_\ \  ___ | |__    __ _  _ __  _   _  _   _   __ _
| |    | '_ \ | || '__| / _` || '_ \ | __| / _` || '_ \  |  _  | / __|| '_ \  / _` || '__|| | | || | | | / _` |
| \__/\| | | || || |   | (_| || | | || |_ | (_| || | | | | | | || (__ | | | || (_| || |   | |_| || |_| || (_| |
 \____/|_| |_||_||_|    \__,_||_| |_| \__| \__,_||_| |_| \_| |_/ \___||_| |_| \__,_||_|    \__, | \__, | \__,_|
                                                                                            __/ |  __/ |
                                                                                           |___/  |___/
*/
