#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void LinkList_Init(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

void HeadInsert(LinkList *L,int x)
{
    LNode *New_Node;

    printf("Enter %d elements that you want to insert: ",x);

    for(int i=1; i<=x; ++i)
    {
        New_Node = (LNode*)malloc(sizeof(LNode));

        scanf("%d", &New_Node->data);

        New_Node->next = (*L)->next;

        (*L)->next = New_Node;
    }

    return;
}

void TailInsert(LinkList *L,int x)
{
    LNode *New_Node;

    LNode *Tailptr = *L;

    while(Tailptr->next != NULL) Tailptr = Tailptr->next;

    printf("Enter %d elements that you want to insert: ",x);

    for(int i=1;i<=x;++i)
    {
        New_Node = (LNode*)malloc(sizeof(LNode));
        Tailptr->next = New_Node;
        scanf("%d",&New_Node->data);
        New_Node->next = NULL;

        Tailptr = New_Node;
    }
}

void Any_Node_Ins(LinkList *L, int x)
{
    LNode *New_Node = (LNode*)malloc(sizeof(LNode));
    New_Node->next = NULL;

    LNode *Node_ptr = *L;

    for(int i=1;i<=x;++i){
        Node_ptr = Node_ptr->next;
        if(Node_ptr == NULL)
        {
            printf("Position not exist!\n");
            free(New_Node);
            return;
        }
    }

    printf("Input element that you want to insert: ");

    scanf("%d",&New_Node->data);

    New_Node->next = Node_ptr->next;

    Node_ptr->next = New_Node;
}

void Del_Node(LinkList *L, int x)
{
    LNode *L_ptr;
    LNode *R_ptr = *L;
    for(int i=1;i<=x;++i)
    {
        L_ptr = R_ptr;
        R_ptr = R_ptr->next;
        if(R_ptr == NULL)
        {
            printf("Position not exist!\n");
            return;
        }
    }

    L_ptr->next = R_ptr->next;

    free(R_ptr);
    return;
}

void Search_by_Posi(LinkList *L, int x)
{
    LNode *Node_ptr = *L;

    for(int i=1;i<=x;++i){
        Node_ptr = Node_ptr->next;
        if(Node_ptr == NULL)
        {
            printf("Position not exist!\n");
            return;
        }
    }
    
    printf("Found it, data is: %d\n",Node_ptr->data);

    return;
}

void Search_by_Val(LinkList *L, int x)
{
    LNode *Node_ptr = *L;
    int i = 0;
    while(1){
        ++i;
        Node_ptr = Node_ptr->next;
        if(Node_ptr == NULL)
        {
            printf("Value not exist!\n");
            return;
        }
        if(Node_ptr->data == x)
        {
            printf("Found it, data at position: %d\n",i);
            return;
        }
    }
}

int main()
{
    LinkList L;
    LinkList_Init(&L);

    LNode *Temp = L;

    int sw,x;

    printf("Please Enter the operation number: ");

    while(scanf("%d",&sw) == 1)
    {
        switch (sw)
        {
        case 1:
            printf("Enter the number of elements you want to insert at the beginning: ");
            scanf("%d",&x);
            HeadInsert(&L,x);

            printf("Now this linkedlist data is: ");
            while(Temp->next != NULL)
            {
                Temp = Temp->next;

                printf("%d ",Temp->data);
            }
            putchar('\n');

            break;
        
        case 2:
            printf("Enter the number of elements you want to insert at the end: ");
            scanf("%d",&x);
            TailInsert(&L,x);

            printf("Now this linkedlist data is: ");
            while(Temp->next != NULL)
            {
                Temp = Temp->next;

                printf("%d ",Temp->data);
            }
            putchar('\n');

            break;

        case 3:
            printf("Input position that you want to insert: ");
            scanf("%d",&x);
            Any_Node_Ins(&L,x);
            
            printf("Now this linkedlist data is: ");
            while(Temp->next != NULL)
            {
                Temp = Temp->next;

                printf("%d ",Temp->data);
            }
            putchar('\n');

            break;
        
        case 4:
            printf("Input position that you want to check: ");
            scanf("%d",&x);
            Search_by_Posi(&L,x);
            break;

        case 5:
            printf("Input value that you want to search: ");
            scanf("%d",&x);
            Search_by_Val(&L,x);
            break;
            
        case 6:
            printf("Input position that you want to delete: ");
            scanf("%d",&x);
            Del_Node(&L,x);

            printf("Now this linkedlist data is: ");
            while(Temp->next != NULL)
            {
                Temp = Temp->next;

                printf("%d ",Temp->data);
            }
            putchar('\n');

            break;

        default:
            printf("Operation not exist!\n");
            break;
        }

        Temp = L;
        printf("Please Enter the operation number: ");
    }

    free(L);
}