/*
//���������������ʵ��
#include<iostream>
using namespace std;
typedef int ElemType;
//������Ĵ洢�ṹ
typedef struct LNode
{
    ElemType data;      //������
    struct LNode* next; //����ָ����
}LNode,*LinkList;        //LinkListΪָ��ṹ��LNode��ָ�����ͣ�LNode*��LinkList�ȼۣ�

//������ĳ�ʼ��
void InitList(LinkList &L)
{
    L=new LNode;    //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
    L->next=NULL;   //ͷ����ָ�����ÿ�
}
*/
//�������ʵ��https://blog.csdn.net/weixin_38499215/article/details/79425470
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
