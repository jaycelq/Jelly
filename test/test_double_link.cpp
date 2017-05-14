#include "stdio.h"
#include <utils/double_link.h>

class IntDoubleListNode : public DoubleLinkNode
{
public:
    IntDoubleListNode(int n) : n(n) {}
    int n;
};

void PrintDoubleList(DoubleLink &list)
{
    IntDoubleListNode *p = (IntDoubleListNode *)list.GetHead();
    printf("head->");
    while (p != list.GetTail())
    {
        printf("%d->", p->n);
        p = (IntDoubleListNode *)p->pNext;
    }
    printf("tail\n");
}

int main()
{
    DoubleLink tlist;    
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());

    IntDoubleListNode node1(1);
    IntDoubleListNode node2(2);
    IntDoubleListNode node3(3);
    IntDoubleListNode node4(4);
    IntDoubleListNode node5(5);

    tlist.Push(&node1);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
 
    tlist.Push(&node1);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
 
    tlist.Push(&node1);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
 

    tlist.Push(&node2);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
 
    tlist.Push(&node3);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
 
    tlist.PushFront(&node5);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
 
    tlist.PushFront(&node4);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
    
    DoubleLink::Remove(&node3);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
 
    DoubleLink::Remove(&node3);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
    

    DoubleLink::Remove(&node4);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
    

    DoubleLink::Remove(&node1);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
    

    DoubleLink::Remove(&node2);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
    

    DoubleLink::Remove(&node5);
    printf("Size:%u\n", tlist.Size());
    printf("Empty:%d\n", tlist.Empty());
    PrintDoubleList(tlist);
    
    return 0;
}
