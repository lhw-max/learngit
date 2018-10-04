#include <stdio.h>
#include <stdlib.h>

//函数结果状态代码
#define TURE            1
#define FALSE           1
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2

typedef int Status;
typedef int ElemType;

#define LIST_INIT_SIZE  100     //初始分配量
#define LISTINCREMENT   10      //分配增量

typedef struct {
    ElemType *elem;     //储存空间基址
    int length;         //当前长度
    int listsize;       //当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

Status InitList(SqList &L);
Status ListDelete(SqList *L,int i,ElemType *e);
Status ListDelect(SqList &L, int i, ElemType &e);
int main()
{
    return 0;
}

//线性表的初始化
Status InitList(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if( !L->elem)
        {
            exit(OVERFLOW);              //分配失败
        }
    L.length = 0;                       //空表长度为0
    L.listsize = LIST_INIT_SIZE;        //初始存储容量
    return OK;
}

//线性表的插入
Status ListDelete(SqList &L,int i,ElemType e){
    ElemType *p, *q;
    //在L的第i个位置前插入e
    // 0<i<ListLength(L)+2
    if(i<1 || i > L->length + 1)
        {
            return ERROR;           //i值不合法
        }
    if(L->length >= L->listsize)    //存储空间满了,增加空间
        {
            ElemType newbase = (ElemType *)realloc(L->elem,(L->listsize  + LISTINCREMENT)*sizeof(ElemType));

            if(!newbase)
            {
                exit(OVERFLOW);         //存储分配失败
            }
        L->elem = newbase;              //新基址
        L->listsize += LISTINCREMENT;   //增加存储容量

    }
    q = *(L->elem[i-1]);                //q为插入地址
    for(p = *(L->elem[L->length-1]); p >= q; --p)
        {
            *(p+1) = *p;
        }
    *q = e;             //插入e
    ++L->length;      //表长加一
    return OK;

}
//删除
Status ListDelect(SqList &L,int i, ElemType &e){
    //删除L中的第i个元素,并用e返回其值
    //0<i<ListLength(L)+1
    if((i<1) || (i>L.length))
        {
            return ERROR;
        }
    p = &(L.elem[i-1]);
    e = *p;
    q = L.elem + L.length-1;        //表尾元素的位置
    for(++p; p <= q; ++p)
        {
            *(p-1) = *p;
        }
    --L.length;
    return OK;
}
