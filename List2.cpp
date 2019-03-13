/*
//单链表基本操作的实现
#include<iostream>
using namespace std;
typedef int ElemType;
//单链表的存储结构
typedef struct LNode
{
    ElemType data;      //数据域
    struct LNode* next; //结点的指针域
}LNode,*LinkList;        //LinkList为指向结构体LNode的指针类型（LNode*与LinkList等价）

//单链表的初始化
void InitList(LinkList &L)
{
    L=new LNode;    //生成新结点作为头结点，用头指针L指向头结点
    L->next=NULL;   //头结点的指针域置空
}
*/
//单链表的实现https://blog.csdn.net/weixin_38499215/article/details/79425470
#include<iostream>
using namespace std;

typedef struct LNode* List;
struct LNode{
    double list;
    List Next;
};

//struct LNote L;
List PtrL;

int ListLength(List PtrL){
    List p = PtrL;
    int j=0;
    while(p){
        p=p->Next;
        j++;
    }
    return j;
}
int main(){
    struct LNode ss;
    cout<<ListLength(ss.Next);
    return 0;
}
















int main()
{

    return 0;
}
