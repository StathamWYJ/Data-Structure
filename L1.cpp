//顺序表基本操作的实现
#include<iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
using namespace std;
typedef struct
{
    ElemType *elem;//存储空间的基地址
    int length;//当前长度
}SqList;

//顺序表初始化，为顺序表分配一个预定大小的数组空间
void InitList(SqList &L)
{
    L.elem = new ElemType(MAXSIZE);
    L.length=0;
    if(!L.elem){
        cout<<"存储分配失败！"<<endl;
        return;
    }
    cout<<"请输入元素个数："<<endl;
    cin>>L.length;
    for(int i=0;i<L.length;i++)
    {
        cout<<"请输入第"<<i+1<<"个元素："<<endl;
        cin>>L.elem[i];
    }

}
//顺序表的取值
ElemType GetElem(SqList L,int i)
{
    if(i<1||i>L.length)
    {
        cout<<"位置输入不合法！";
        return 0;
    }
    return L.elem[i-1];
}
//顺序表的查找
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
//顺序表的插入
void ListInsert(SqList &L,int i,ElemType e)
{
    if((i<1)||(i>L.length+1))
    {
        cout<<"插入位置不合法！"<<endl;
        return;
    }
    if(L.length==MAXSIZE)
    {
        cout<<"当前存储空间已满！"<<endl;
        return;
    }
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];//插入位置以及之后的元素后移
    }
    L.elem[i-1]=e;//将新元素e放入第i个位置
    ++L.length;
    cout<<"新元素插入成功！"<<endl;
}
//顺序表的删除
void ListDelete(SqList &L,int i)
{
    if((i<1)||(i>L.length))
    {
        cout<<"删除位置不合法！"<<endl;
        return;
    }
    for(int j=i;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];//被删除元素之后的元素前移
    }
    --L.length;
    cout<<"删除成功！"<<endl;
}
//顺序表的并集
void unionList(SqList &LA, SqList &LB, SqList &LC)
{
    int lena,i;
    ElemType e;
    InitList(LC);
    for (i=1; i<=LA.length; i++) //将LA的所有元素插入到Lc中
    {
        e=GetElem(LA,i);
        ListInsert(LC,i,e);
    }
    lena=LA.length;         //求线性表LA的长度
    for (i=1; i<=LB.length; i++)
    {
        e=GetElem(LB,i);         //取LB中第i个数据元素赋给e
        if (!LocateElem(LA,e)) //LA中不存在和e相同者,插入到LC中
            ListInsert(LC,++lena,e);
    }
}

//输出顺序表,观察状态
void OutList(SqList L)
{
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}
int main(){
    SqList list;//顺序表
    ElemType e=8;//测试元素
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
