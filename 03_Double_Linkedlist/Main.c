#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <stdio.h>

#define ElemType int

typedef struct DNode
{
    ElemType data;
    struct DNode *prev, *next;
} DNode, *DLinkList;

void DLinkList_Init(DLinkList *DL)
{
    (*DL) = (DNode*)malloc(sizeof(DNode));
    (*DL)->prev = NULL;
    (*DL)->data = 0;
    (*DL)->next = NULL;
}

void DLinkList_HeadIns(DLinkList *DL, ElemType x)
{
    DNode *NewNode = (DNode*)malloc(sizeof(DNode));
    
    NewNode->data = x;

    while((*DL)->prev != NULL)
    {
        (*DL) = (*DL)->prev;
    }

    NewNode->next = (*DL)->next;
    (*DL)->next->prev = NewNode;
    NewNode->prev = *DL;
    (*DL)->next = NewNode;
}

void DLinkList_TailIns(DLinkList *DL, ElemType x)
{
    DLinkList Temp = *DL;
    DLinkList Temp_Head = Temp;
    while(Temp->next != NULL)
    {
        Temp = Temp->next;
    }

    DNode *NewNode = (DNode*)malloc(sizeof(DNode));
    
    NewNode->data = x;

    NewNode->prev = Temp;
    Temp->next = NewNode;
    NewNode->next = NULL;
    (*DL) = Temp_Head;
}

void DLinkList_Ins(DLinkList *DL, ElemType x, int posi)
{
    DLinkList Temp = *DL;
    DLinkList Temp_Head = Temp;
    for(int i=1;i<=posi-1;++i)
    {
        Temp = Temp->next;
    }

    if(posi == 1)
    {
        DLinkList_HeadIns(DL,x);
        return;
    }

    if(Temp->next == NULL){
        DLinkList_TailIns(DL,x);
        return;
    }

    DNode *NewNode = (DNode*)malloc(sizeof(DNode));

    NewNode->data = x;

    Temp->prev->next = NewNode;
    NewNode->next = Temp;
    NewNode->prev = Temp->prev;
    Temp->prev = NewNode;
    (*DL) = Temp_Head;
}

void Display_DLinkList(DLinkList *DL)
{
    DLinkList Temp = *DL;
    while(Temp != NULL)
    {
        printf("%d ",Temp->data);
        Temp = Temp->next;
    }
    putchar('\n');
}

int main()
{
    DLinkList DL;
    DLinkList_Init(&DL);

    int sw = 0;
    int elem,posi;

    while(scanf("%d",&sw) == 1)
    {
        switch(sw)
        {
            case 1:
                scanf("%d",&elem);
                DLinkList_HeadIns(&DL,elem);
                break;
            
            case 2:
                scanf("%d",&elem);
                DLinkList_TailIns(&DL,elem);
                break;
            
            case 3:
                scanf("%d %d",&elem,&posi);
                DLinkList_Ins(&DL,elem,posi);
                break;
        }

        Display_DLinkList(&DL);
    }
    
}