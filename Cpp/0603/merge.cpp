#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *list1, *list2;

    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *pa=list1,*pb = list2,*pc;
    struct ListNode *head =(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=NULL;
    pc=head;
    while (pa&&pb){// La和Lb均未到达表尾，依次摘取两表中值较小的结点插入到Lc的最后
     		if (pa->data <= pb->data){
       		pc->next = pa;  pc = pa;  pa = pa->next;
     		}
     		else{
       		pc->next = pb;  pc = pb;  pb = pb->next;
     		}
	    }
    pc->next = (pa ? pa : pb); // 插入剩余段
   	  
    return head->next;

}