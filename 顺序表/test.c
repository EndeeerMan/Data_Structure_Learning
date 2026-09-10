#include <stdlib.h>
#include <stdio.h>

#define INITSIZE 10

typedef struct{
    int *Data;
    int MaxSize;
    int Len;
}SqList;

int InitSqList(SqList *db){
    db->MaxSize = INITSIZE;
    
    db->Data = malloc(db->MaxSize*sizeof(int));

    if(db->Data == NULL){
        return 0;
    }

    for(int i=0;i<INITSIZE;++i){
        db->Data[i] = 0;
    }

    db->Len = 0;

    return 1;
}

int ExtendSqList(SqList *db, int x){
    int *p = db->Data;      //临时指针保存数据
    db->Data = malloc((db->MaxSize + x)*sizeof(int));   //分配新空间

    if(db->Data == NULL){
        free(p);
        return 0;
    }

    for(int i=0;i<db->Len;++i){     //复制数据
        db->Data[i] = p[i];
    }

    db->MaxSize += x;
    
    free(p);

    return 1;
}

int InsertSqList(SqList *db, int x, int element){
    if(x < 0 || x > db->Len){
        printf("错误：下标数非法！\n");
        return 0;       // 下标非法，拦截！
    }

    if(db->MaxSize < db->Len + 1){
        if(ExtendSqList(db,db->Len*2) == 0){
            return 0;
        }
    }
    
    for(int i=db->Len;i>x;--i){
        db->Data[i] = db->Data[i-1];
    }
    
    db->Data[x] = element;

    db->Len += 1;

    return 1;
}

int DelSqList(SqList *db, int x){
    if(x < 0 || x >= db->Len){
        printf("错误：下标数非法！\n");
        return 0;
    }

    for(int i=x;i<db->Len-1;i++){
        db->Data[i] = db->Data[i+1];
    }

    db->Data[db->Len-1] = 0;

    db->Len -= 1;

    return 1;
}

int* Search_by_position(SqList *db, int x){
    if(x < 0 || x >= db->Len){
        printf("错误：下标数非法！\n");
        return NULL;
    }

    return &(db->Data[x]);
}

int Search_by_num(SqList *db, int target){
    for(int i=0;i<db->Len;++i){
        if(db->Data[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    SqList db;

    if(InitSqList(&db)){
        printf("初始化线性表成功！\n");
    }else{
        printf("初始化线性表失败！\n");
    }

    int position,element,operation;
    
    while(scanf("%d",&operation) == 1){ //position均为数组下标位置，operation 1为插入，2为删除。
        switch(operation){

            case 1:                                 //插入某元素
                printf("请输入要插入的位置及其元素：");
                scanf("%d %d",&position,&element);
                if(InsertSqList(&db,position,element)){
                    printf("线性表插入成功！\n");
                    for(int i=0;i<db.Len;++i){
                        printf("%d ",db.Data[i]);
                    }
                    printf("\n");
                }else{
                    printf("线性表插入失败！\n");
                }
                break;

            case 2:                                 //删除某元素
                printf("请输入要删除的位置：");
                scanf("%d",&position);
                if(DelSqList(&db,position)){
                    printf("线性表元素删除成功！\n");
                    for(int i=0;i<db.Len;++i){
                        printf("%d ",db.Data[i]);
                    }
                    printf("\n");
                }else{
                    printf("线性表元素删除失败！\n");
                }
                break;
                
            case 3:{                                 //按位查找某元素
                printf("请输入要查询的位置：");
                scanf("%d",&position);

                int *val = Search_by_position(&db,position);

                if(val == NULL){
                    printf("查找失败！\n");
                }else{
                    printf("你要查找的是：%d\n",*val);
                }
                break;
            }

            case 4:{                                 //按目标数查找
                printf("请输入要查找的元素：");
                scanf("%d",&element);
                int result = Search_by_num(&db,element);
                if(result == -1){
                    printf("查找失败！\n");
                }else{
                    printf("查找成功！位于 %d 位\n",result);
                }
                break;
            }

            default:
                printf("操作数有误，请重新输入！\n");
            
        }
    }
    
    free(db.Data);

    printf("程序运行结束！\n");
}