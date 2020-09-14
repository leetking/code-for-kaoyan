#include "stack.h"
#define CapacityMax 4096
bool IsBracketsValid(char *brackets)
{
    bool valid = true;
    SeqStack stack;
    InitStack(&stack, CapacityMax);
    int ch;
    for (int i = 0; '\0' != brackets[i]; i++) {
        switch (brackets[i]) {
        /* 左“括号”入栈 */
        case '(': Push(&stack, '('); break;
        case '[': Push(&stack, '['); break;
        case '{': Push(&stack, '{'); break;
        /* 右“括号”出栈 */
        case ')':
            if (Empty(&stack)) {
                DestroyStack(&stack);
                return false;
            }
            Pop(&stack, &ch);
            if ('(' != ch) {
                DestroyStack(&stack);
                return false;
            }
            break;
        case ']':
            if (Empty(&stack)) {
                DestroyStack(&stack);
                return false;
            }
            Pop(&stack, &ch);
            if ('[' != ch) {
                DestroyStack(&stack);
                return false;
            }
            break;
        case '}':
            if (Empty(&stack)) {
                DestroyStack(&stack);
                return false;
            }
            Pop(&stack, &ch);
            if ('{' != ch) {
                DestroyStack(&stack);
                return false;
            }
            break;
            break;
        default:
            break;
        }
    }
    if (!Empty(&stack)) {
        DestroyStack(&stack);
        return false;
    }

    DestroyStack(&stack);
    return true;
}
