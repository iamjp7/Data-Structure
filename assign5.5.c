#include <stdio.h>
#include <stdlib.h>
struct dnode
{
    struct dnode *prev;
    int data;
    struct dnode *next;
};
typedef struct dnode node;
node *start = NULL;

void Insertlast(int num)
{
    struct dnode *nptr,  *temp = start;

    nptr = malloc(sizeof(struct dnode));
    nptr->data = num;
    nptr->next = NULL;
    nptr->prev = NULL;

    if (start == NULL)
    {
        start = nptr;
    } 
    else
    {
  
        while (temp->next != NULL)
            temp = temp->next;

        nptr->prev = temp;
        temp->next = nptr;
    }
}
void addatbeg(int num)
{
    struct dnode *nptr;
    nptr = malloc(sizeof(struct dnode));
    nptr->prev = NULL;
    nptr->data = num;
    nptr->next = start;

    if (start != NULL)
        start->prev = nptr;
    start = nptr;
}

void deletenum(int num)
{
    struct dnode *temp = start;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            if (temp == start)
            {
                start = start->next;
                start->prev = NULL;
            } 
            else
            {
                if (temp->next == NULL)
                    temp->prev->next = NULL;
                else
                
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                free(temp);
            }
            return ; 
        }
        temp = temp->next; 
    }
    printf("\n%d not found.", num);
}

void display()
{
	struct dnode *temp = start;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } 
}

int main()
{
    int n, ch;
  while(1)
    {
        printf("1.Insert at beginning \n2.Insert at last\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter Choice ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter number: ");
                scanf("%d", &n);
                 addatbeg(n);
                break;
            case 2:
                printf("\nEnter number: ");
                scanf("%d", &n);
              Insertlast(n);
                break;
            case 3:
            	printf("\nEnter number to delete: ");
                scanf("%d", &n);
                deletenum(n);
                break;
            case 4:
                display();
                break;
            case 5:exit(1);
                break;
            default:printf("Enter valid choice\n");

        }
    }
    return 0;
}