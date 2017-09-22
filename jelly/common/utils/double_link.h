#ifndef _DOUBLE_LINK_H_
#define _DOUBLE_LINK_H_

#include <stdint.h>
#include <stdio.h>

#define LOG_ERROR printf

// 侵入式双链表
class DoubleLink;

// 双链表节点
struct DoubleLinkNode
{
    DoubleLink *pOwner;
    DoubleLinkNode *pNext;
    DoubleLinkNode *pPrev;

    DoubleLinkNode() : pOwner(NULL), pNext(NULL), pPrev(NULL)
    {
    }

    inline virtual ~DoubleLinkNode();

private:
    DoubleLinkNode(const DoubleLinkNode &o);

    DoubleLinkNode &operator=(const DoubleLinkNode &o);
};

class DoubleLink
{
public:
    DoubleLink() : count(0)
    {
        head.pNext = &tail;
        tail.pPrev = &head;
    }

    ~DoubleLink()
    {
        Clear();
    }

    uint32_t Size()
    {
        return count;
    }

    void Clear()
    {
        DoubleLinkNode *pNode = Pop();
        while (NULL != pNode)
        {
            pNode = Pop();
        }
    }

    DoubleLinkNode *GetFirst()
    {
        return head.pNext;
    }

    DoubleLinkNode *GetHead()
    {
        return &head;
    }

    DoubleLinkNode *GetTail()
    {
        return &tail;
    }

    void Push(DoubleLinkNode *dNode)
    {

        if ((NULL == dNode->pNext && (NULL != dNode->pPrev || NULL != dNode->pOwner)) ||
            (NULL == dNode->pPrev && (NULL != dNode->pNext || NULL != dNode->pOwner)) ||
            (NULL == dNode->pOwner && (NULL != dNode->pNext || NULL != dNode->pPrev)))
        {
            LOG_ERROR("DoubleLink Push error");
        }

        if (NULL != dNode->pNext || NULL != dNode->pPrev || NULL != dNode->pOwner)
        {
            return;
        }
        tail.pPrev->pNext = dNode;
        dNode->pPrev = tail.pPrev;
        tail.pPrev = dNode;
        dNode->pNext = &tail;
        dNode->pOwner = this;
        ++count;
    }

    void PushFront(DoubleLinkNode *dNode)
    {
        if ((NULL == dNode->pNext && (NULL != dNode->pPrev || NULL != dNode->pOwner)) ||
            (NULL == dNode->pPrev && (NULL != dNode->pNext || NULL != dNode->pOwner)) ||
            (NULL == dNode->pOwner && (NULL != dNode->pNext || NULL != dNode->pPrev)))
        {
            LOG_ERROR("DoubleLink Push error");
        }

        if (NULL != dNode->pNext || NULL != dNode->pPrev || NULL != dNode->pOwner)
        {
            return;
        }

        dNode->pPrev = &head;
        dNode->pNext = head.pNext;
        head.pNext->pPrev = dNode;
        head.pNext = dNode;
        dNode->pOwner = this;
        ++count;
    }


    DoubleLinkNode *Pop()
    {
        if (head.pNext == &tail)
        {
            return NULL;
        }
        DoubleLinkNode *ret = head.pNext;
        Remove(ret);
        return ret;
    }

    bool Empty()
    {
        return head.pNext == &tail;
    }

    static void Remove(DoubleLinkNode *dNode)
    {
        if ((NULL != dNode->pNext && (NULL == dNode->pPrev || NULL == dNode->pOwner)) ||
            (NULL != dNode->pPrev && (NULL == dNode->pNext || NULL == dNode->pOwner)) ||
            (NULL != dNode->pOwner && (NULL == dNode->pNext || NULL == dNode->pPrev)))
        {
            LOG_ERROR("DoubleLink Remove error");
        }

        if (NULL == dNode->pPrev || NULL == dNode->pNext || NULL == dNode->pOwner)
        {
            return;
        }

        dNode->pPrev->pNext = dNode->pNext;
        dNode->pNext->pPrev = dNode->pPrev;
        dNode->pNext = dNode->pPrev = NULL;
        --dNode->pOwner->count;
        dNode->pOwner = NULL;
    }

private:
    DoubleLink(const DoubleLink &o);

    DoubleLink &operator=(const DoubleLink &o);

private:
    DoubleLinkNode head;
    DoubleLinkNode tail;
    uint32_t count;
};

inline DoubleLinkNode::~DoubleLinkNode()
{
    if (NULL != pOwner)
    {
        DoubleLink::Remove(this);
    }
}


#endif
