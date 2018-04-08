#include "linkstack.h"
#include <stdlib.h>

//栈初始化
void LinkStackInit(LinkStack** node)
{
    *node=NULL;
}

LinkStack* CreateLinkNode(LinkType value)
{
    LinkStack* new_node=(LinkStack*)malloc(sizeof(LinkStack));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}

//销毁栈
void LinkStackDestroy(LinkStack** stack)
{
    free(*stack);
}

//入栈(头插法)
void LinkStackPush(LinkStack** stack,LinkType value)
{
    if(stack == NULL)
    {
        //非法操作
        return ;
    }
    LinkStack* new_node=CreateLinkNode(value);
    new_node->next=*stack;
    *stack=new_node;
}
//出栈
void LinkStackPop(LinkStack** stack)
{
    if(stack == NULL)
    {
        //非法输入
        return ;
    }
    if(*stack == NULL)
    {
        //空链表
        return;
    }
    LinkStack* to_erase=*stack;
    *stack=(*stack)->next;
    free(to_erase);
    return;
}
//取栈顶元素
int LinkStackTop(LinkStack** stack,LinkType* value)
{
    if(stack == NULL || value == NULL)
    {
        //非法操作
        return 0;
    }
    //value=stack->data;
    return 1;
}
/*
LinkStack* LinkStackTop(LinkStack* stack)
{
   // if(stack == NULL || value == NULL)
   // {
   //     //非法操作
   //     return ;
   // }
    
    return stack;
}
*/



/*****
 *
 * 以下为测试代码
 *
 * ****/

#include<stdio.h>
#define TEST_HEADER printf("\n========%s========\n",__FUNCTION__)
void LinkStackPrintChar(LinkStack *head,const char *msg)
{
    printf("[%s]\n",msg);
    LinkStack *cur=head;
    for(;cur!=NULL;cur=cur->next)
    {
        printf("[%c]",cur->data);
    }
    printf("\n");
}

void TestInit()
{
    TEST_HEADER;
    LinkStack *stack;
    LinkStackInit(&stack);
    LinkStackPrintChar(stack,"栈的初始化");
}

void TestPush()
{
    TEST_HEADER;
    LinkStack *stack;
    LinkStackInit(&stack);
    LinkStackPush(&stack,'a');
    LinkStackPush(&stack,'b');
    LinkStackPush(&stack,'c');
    LinkStackPush(&stack,'d');
    LinkStackPrintChar(stack,"入栈四个元素");
}

void TestPop()
{ 
    TEST_HEADER;
    LinkStack *stack;
    LinkStackInit(&stack);
    LinkStackPush(&stack,'a');
    LinkStackPush(&stack,'b');
    LinkStackPush(&stack,'c');
    LinkStackPush(&stack,'d');
    LinkStackPrintChar(stack,"入栈四个元素");
    LinkStackPop(&stack);
    LinkStackPop(&stack);
    LinkStackPrintChar(stack,"出栈两个元素");
    LinkStackPop(&stack);
    LinkStackPop(&stack);
    LinkStackPrintChar(stack,"再出栈两个元素");
    LinkStackPop(&stack);
    //LinkStackPop(&stack);
    LinkStackPrintChar(stack,"尝试对空栈进行出栈操作");
}
/*
void TestTop()
{
    TEST_HEADER;
    LinkStack *stack;
    LinkStackInit(&stack);
    LinkStackPush(&stack,'a');
    LinkStackPush(&stack,'b');
    LinkStackPush(&stack,'c');
    LinkStackPush(&stack,'d');
    LinkStackPrintChar(stack,"入栈四个元素");
    LinkStackTop(stack);
    //LinkType value;
    //int ret = LinkStackTop(&stack,&value);
    printf("The top value expected d,actual %c\n",stack);
    //printf("ret expected 1,actual %d\n",ret);
    LinkStackPop(&stack);
    LinkStackPop(&stack);
    //printf("value expected b,actual %c\n",value);
   // printf("ret expected 1,actual %d\n",ret);
    LinkStackPop(&stack);
    LinkStackPop(&stack);
    //printf("value expected b,actual %c\n",value);
    //printf("ret expected 0,actual %d\n",ret);
}
*/

void TestTop()
{
    TEST_HEADER;
    LinkStack *stack;
    LinkStackInit(&stack);
    LinkStackPush(&stack,'a');
    LinkStackPush(&stack,'b');
    LinkStackPush(&stack,'c');
    LinkStackPush(&stack,'d');
    LinkStackPrintChar(stack,"入栈四个元素");
    //LinkStackTop(stack);
    LinkType value;
    //int ret = LinkStackTop(stack,value);
    
    int ret=LinkStackTop(&stack,&value);
    //printf("value expected d,actuall %c\n",value);
    printf("ret expected 1,actual %d\n",ret);
    LinkStackPop(&stack);
    LinkStackPop(&stack);
    //printf("The top value expected d,actual %c\n",stack);
    printf("ret expected 1,actual %d\n",ret);
    LinkStackPop(&stack);
    LinkStackPop(&stack);
    //printf("value expected b,actual %c\n",value);
    printf("ret expected 1,actual %d\n",ret);
    LinkStackPop(&stack);
    printf("ret expected 0,actual %d\n",ret);
}
int main()
{
    TestInit();
    TestPush();
    TestPop();
    TestTop();
    return 0;
}
