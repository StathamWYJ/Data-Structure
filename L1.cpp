//˳������������ʵ��
#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
using namespace std;
typedef struct
{
    ElemType *elem;//�洢�ռ�Ļ���ַ
    int length;//��ǰ����
}SqList;

//˳����ʼ����Ϊ˳������һ��Ԥ����С������ռ�
void InitList(SqList &L)
{
    L.elem = new ElemType(MAXSIZE);
    L.length=0;
    if(!L.elem){
        cout<<"�洢����ʧ�ܣ�"<<endl;
        return;
    }
    cout<<"������Ԫ�ظ�����"<<endl;
    cin>>L.length;
    for(int i=0;i<L.length;i++)
    {
        cout<<"�������"<<i+1<<"��Ԫ�أ�"<<endl;
        cin>>L.elem[i];
    }

}
//˳����ȡֵ
ElemType GetElem(SqList L,int i)
{
    if(i<1||i>L.length)
    {
        cout<<"λ�����벻�Ϸ���";
        return 0;
    }
    return L.elem[i-1];
}
//˳���Ĳ���
int LocateElem(SqList L,ElemType e)
{
    for(int i=0;i<L.length;i++){
        if(L.elem[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}
//˳���Ĳ���
void ListInsert(SqList &L,int i,ElemType e)
{
    if((i<1)||(i>L.length+1))
    {
        cout<<"����λ�ò��Ϸ���"<<endl;
        return;
    }
    if(L.length==MAXSIZE)
    {
        cout<<"��ǰ�洢�ռ�������"<<endl;
        return;
    }
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];//����λ���Լ�֮���Ԫ�غ���
    }
    L.elem[i-1]=e;//����Ԫ��e�����i��λ��
    ++L.length;
    cout<<"��Ԫ�ز���ɹ���"<<endl;
}
//˳����ɾ��
void ListDelete(SqList &L,int i)
{
    if((i<1)||(i>L.length))
    {
        cout<<"ɾ��λ�ò��Ϸ���"<<endl;
        return;
    }
    for(int j=i;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];//��ɾ��Ԫ��֮���Ԫ��ǰ��
    }
    --L.length;
    cout<<"ɾ���ɹ���"<<endl;
}
//˳���Ĳ���
void unionList(SqList &LA, SqList &LB, SqList &LC)
{
    int lena,i;
    ElemType e;
    InitList(LC);
    for (i=1; i<=LA.length; i++) //��LA������Ԫ�ز��뵽Lc��
    {
        e=GetElem(LA,i);
        ListInsert(LC,i,e);
    }
    lena=LA.length;         //�����Ա�LA�ĳ���
    for (i=1; i<=LB.length; i++)
    {
        e=GetElem(LB,i);         //ȡLB�е�i������Ԫ�ظ���e
        if (!LocateElem(LA,e)) //LA�в����ں�e��ͬ��,���뵽LC��
            ListInsert(LC,++lena,e);
    }
}

//���˳���,�۲�״̬
void OutList(SqList L)
{
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}
int main(){
    SqList list;//˳���
    ElemType e=8;//����Ԫ��
    InitList(list);
    OutList(list);
    cout<<GetElem(list,2)<<endl;
    OutList(list);
    ListInsert(list,2,e);
    OutList(list);
    cout<<LocateElem(list,e)<<endl;
    OutList(list);
    ListDelete(list,5);
    OutList(list);
    return 0;
}
