//该程序实现了线性表的链式存储结构之单链表和各项操作
#include<iostream>
#include<tchar.h>
using namespace std;

//****线性表和一些基础的定义*****
#define ElemType int    /*表中数据元素类型*/
typedef struct Node{
    ElemType data;
    Node* next;
}LNode,* LinkList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;   //Status为函数类型，其值是函数结果状态代码，如OK等


//获得单链表的长度
Status GetLen(LinkList L) {
    Status len=0;
    LNode* p=L;
    if (L == NULL)
        return ERROR;
    while (p->next != NULL)
        {
            p = p->next;
            len++;
        }
    return len;
}

//获得表中第i个位置的元素，以e返回,获取到时返回OK，获取不到返回ERROR
Status GetElem(const LinkList L, int i, ElemType &e) {
    Status count;
    LNode* p;
    if (L==NULL ||i<1||i>GetLen(L))
        return ERROR;
/*  这种写法不好，没有考虑count>i的情况，用下面的写法
while (p->next != NULL)
    {
        p = p->next;
        count++;
        if (count == i)
        {
            e = p->data;
            break;
        }
    }
*/
    p = L->next;
    count = 1;
    while (p&&count<i)
    {
        p = p->next;
        ++count;
    }
    if (!p||count > i)
        return ERROR;
    e = p->data;
    return OK;
}


//向线性表中第i个位置插入一个元素e，即在第i个位置之前插入元素，插入成功则返回OK，插入失败返回ERROR
Status InsertElem(LinkList L, int i, ElemType &e) {
    LinkList p;
    LinkList s;
    Status count;
    if (i<1 || i>GetLen(L) || L==NULL)
        return ERROR;
    p = L;
    count = 1;
    while (p&&count < i)
    {
        p = p->next;
        ++count;
    }
    if (!p|| count > i)
        return ERROR;
    s = new LNode;
    s->data = e;
    s->next =p->next ;
    p->next = s;
    return OK;
}

//从线性表中第i个位置删除一个元素（即删除第i个位置之前的元素），删除成功则返回OK，否则返回ERROR，删除的元素用e返回
Status DeleteElem(LinkList L, int i,ElemType& e) {
    LinkList p,q;
    Status count;
    if (!L||i<1 || i>GetLen(L))
        return ERROR;
    p = L;
    count = 1;
    while (p->next&&count<i)
    {
        p = p->next;
        ++count;
    }
    if (!(p->next) || count > i)
        return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}

//用一个数组初始化一个单链表,头插法
void CreateListHead(ElemType Array[],int N, LinkList L) {
    LinkList p;
    int i;
    for (i = N-1; i>=0; i--) {
        p = new LNode;
        p->data = Array[i];
        cout << "CreateHead:"<<p->data << endl;
        p->next =L->next;
        L->next = p;
    }
}

//用一个数组初始化一个单链表,尾插法
void CreateListTail(ElemType Array[], int N, LinkList L) {
    LinkList p,r;
    int i;
    r = L;
    for (i = 0; i <N; i++) {
        p = new LNode;
        p->data = Array[i];
        cout <<"CreateTail:"<< p->data<<endl;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

//整表删除
Status ClearList(LinkList L) {
    LinkList p, q;
    if (L == NULL)
        return ERROR;
    p=L->next;

    while (p) {
        cout <<"clear:"<< p->data << endl;
        q = p->next;
        delete p;
        p = q;
        L->next = p;
    }
    if (!p)
        return ERROR;
    L->next = NULL;
    return OK;
}

Status PrintList(LinkList L) {//打印单链表
    LinkList p;
    if (L == NULL)
        return ERROR;
    p = L->next;
    while (p)
    {
        cout <<"print:"<< p->data << endl;
        p = p->next;
    }
    if (!p)
        return ERROR;
    return OK;
}


int main() {
    int A[2] = {0,1};
    int e = 3;
    int b,c;
    LinkList L=new LNode;
    L->next = NULL;//初始化头结点

    CreateListHead(A,2,L);//测试头插法
    PrintList(L);
    cout << "*********" << endl;

    InsertElem(L,2,e);//测试插入元素
    GetElem(L,2,c);//测试获取元素
    cout << "the element got is" << c << endl;
    PrintList(L);
    cout << "*********" << endl;

    DeleteElem(L,e,b);//测试删除元素
    cout << "b=" << b<<endl;
    PrintList(L);
    cout << "*********" << endl;

    ClearList(L);//测试清空表
    cout << "*********" << endl;

    CreateListTail(A,2,L);//测试尾插法
    PrintList(L);
    delete L;
    return 0;
}
