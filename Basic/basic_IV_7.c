#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct courseNode
{
  int cID;
  char name[10];
  float credit;
  int semester;
  struct courseNode *next;
}; //创建链表结构体

int main()
{
  struct courseNode *courseCreating(void);
  struct courseNode *courseChange(struct courseNode *, int, float);
  struct courseNode *courseAddings(struct courseNode *);

  struct courseNode *target;
  target = courseCreating();
  courseChange(target, 3, 0.5);
  courseAddings(target);
  printf("test finished\n");
  return 0;
}
struct courseNode *courseChange(struct courseNode *Lc, int c, float t)
{
  struct courseNode *p = Lc;

  while (1)
  {
    if (p == NULL)
      break;
    if (p->cID == c)
    {
      p->credit = t;
    }
    p = p->next;
  }
  return Lc;
}

struct courseNode *courseCreating(void)
{
  struct courseNode *Node = malloc(sizeof(struct courseNode));
  Node->cID = 1;
  strcpy(Node->name, "geography");
  Node->credit = 0.5;
  Node->semester = 1;
  Node->next = NULL; //记得一定要讲原来的next定义为null
  return Node;       //返回一个链表头
}

struct courseNode *courseAddings(struct courseNode *Lc)
{
  struct courseNode *p1, *p2;
  p1 = Lc;
  p2 = malloc(sizeof(struct courseNode));
  p2->cID = 2;
  strcpy(p1->name, "programming");
  p2->credit = 0.5;
  p2->semester = 2;
  p2->next = NULL;
  return Lc;
}