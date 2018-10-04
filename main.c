#include <stdio.h>
#include <stdlib.h>

//�������״̬����
#define TURE            1
#define FALSE           1
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2

typedef int Status;
typedef int ElemType;

#define LIST_INIT_SIZE  100     //��ʼ������
#define LISTINCREMENT   10      //��������

typedef struct {
    ElemType *elem;     //����ռ��ַ
    int length;         //��ǰ����
    int listsize;       //��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;

Status InitList(SqList &L);
Status ListDelete(SqList *L,int i,ElemType *e);
Status ListDelect(SqList &L, int i, ElemType &e);
int main()
{
    return 0;
}

//���Ա�ĳ�ʼ��
Status InitList(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if( !L->elem)
        {
            exit(OVERFLOW);              //����ʧ��
        }
    L.length = 0;                       //�ձ���Ϊ0
    L.listsize = LIST_INIT_SIZE;        //��ʼ�洢����
    return OK;
}

//���Ա�Ĳ���
Status ListDelete(SqList &L,int i,ElemType e){
    ElemType *p, *q;
    //��L�ĵ�i��λ��ǰ����e
    // 0<i<ListLength(L)+2
    if(i<1 || i > L->length + 1)
        {
            return ERROR;           //iֵ���Ϸ�
        }
    if(L->length >= L->listsize)    //�洢�ռ�����,���ӿռ�
        {
            ElemType newbase = (ElemType *)realloc(L->elem,(L->listsize  + LISTINCREMENT)*sizeof(ElemType));

            if(!newbase)
            {
                exit(OVERFLOW);         //�洢����ʧ��
            }
        L->elem = newbase;              //�»�ַ
        L->listsize += LISTINCREMENT;   //���Ӵ洢����

    }
    q = *(L->elem[i-1]);                //qΪ�����ַ
    for(p = *(L->elem[L->length-1]); p >= q; --p)
        {
            *(p+1) = *p;
        }
    *q = e;             //����e
    ++L->length;      //����һ
    return OK;

}
//ɾ��
Status ListDelect(SqList &L,int i, ElemType &e){
    //ɾ��L�еĵ�i��Ԫ��,����e������ֵ
    //0<i<ListLength(L)+1
    if((i<1) || (i>L.length))
        {
            return ERROR;
        }
    p = &(L.elem[i-1]);
    e = *p;
    q = L.elem + L.length-1;        //��βԪ�ص�λ��
    for(++p; p <= q; ++p)
        {
            *(p-1) = *p;
        }
    --L.length;
    return OK;
}
