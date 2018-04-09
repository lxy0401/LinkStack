#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char LinkType;
typedef struct LinkStack
{
    LinkType data;
    struct LinkStack* next;
}LinkStack;


//栈初始化
void LinkStackInit(LinkStack** stack);

//销毁栈
void LinkStackDestroy(LinkStack** stack);

//入栈
void LinkStackPush(LinkStack** stack,LinkType value);

//出栈
void LinkStackPop(LinkStack** stack);

//取栈顶元素
int LinkStackTop(LinkStack* stack,LinkType* value);
