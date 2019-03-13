//�ó���ʵ�������Ա����ʽ�洢�ṹ֮������͸������
#include<iostream>
#include<tchar.h>
using namespace std;

//****���Ա��һЩ�����Ķ���*****
#define ElemType int    /*��������Ԫ������*/
typedef struct Node{
    ElemType data;
    Node* next;
}LNode,* LinkList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;   //StatusΪ�������ͣ���ֵ�Ǻ������״̬���룬��OK��


//��õ�����ĳ���
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

//��ñ��е�i��λ�õ�Ԫ�أ���e����,��ȡ��ʱ����OK����ȡ��������ERROR
Status GetElem(const LinkList L, int i, ElemType &e) {
    Status count;
    LNode* p;
    if (L==NULL ||i<1||i>GetLen(L))
        return ERROR;
/*  ����д�����ã�û�п���count>i��������������д��
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


//�����Ա��е�i��λ�ò���һ��Ԫ��e�����ڵ�i��λ��֮ǰ����Ԫ�أ�����ɹ��򷵻�OK������ʧ�ܷ���ERROR
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

//�����Ա��е�i��λ��ɾ��һ��Ԫ�أ���ɾ����i��λ��֮ǰ��Ԫ�أ���ɾ���ɹ��򷵻�OK�����򷵻�ERROR��ɾ����Ԫ����e����
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

//��һ�������ʼ��һ��������,ͷ�巨
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

//��һ�������ʼ��һ��������,β�巨
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

//����ɾ��
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

Status PrintList(LinkList L) {//��ӡ������
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
    L->next = NULL;//��ʼ��ͷ���

    CreateListHead(A,2,L);//����ͷ�巨
    PrintList(L);
    cout << "*********" << endl;

    InsertElem(L,2,e);//���Բ���Ԫ��
    GetElem(L,2,c);//���Ի�ȡԪ��
    cout << "the element got is" << c << endl;
    PrintList(L);
    cout << "*********" << endl;

    DeleteElem(L,e,b);//����ɾ��Ԫ��
    cout << "b=" << b<<endl;
    PrintList(L);
    cout << "*********" << endl;

    ClearList(L);//������ձ�
    cout << "*********" << endl;

    CreateListTail(A,2,L);//����β�巨
    PrintList(L);
    delete L;
    return 0;
}
