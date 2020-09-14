#ifndef LIST_H__
#define LIST_H__

#include "common.h"

#define MaxSize 1024

typedef struct SeqList {
    int *data;
    int maxsize, length;
} SeqList;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;
typedef LinkNode *LinkList;

typedef struct DLinkNode {
    int data;
    struct DLinkNode *prev, *next;
} DLinkNode;
typedef DLinkNode *DLinkList;

typedef struct {
    int data;
    int next;
} StaticLinkList[MaxSize];

#endif /* LIST_H__ */
