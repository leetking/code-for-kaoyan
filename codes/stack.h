#ifndef STACK_H__

#include "common.h"

typedef struct SeqStack {
    int *data;
    int top, capacity;
} SeqStack;

bool InitStack(SeqStack *stack, int capacity);
void DestroyStack(SeqStack *stack);
int StackSize(SeqStack *stack);
int StackCapacity(SeqStack *stack);
bool StackEmpty(SeqStack *stack);
bool StackFull(SeqStack *stack);
bool Push(SeqStack *stack, int ele);
bool Pop(SeqStack *stack, int *store);
bool GetTop(SeqStack *stack);

#endif /* STACK_H__ */
