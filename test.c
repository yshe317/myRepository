/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int converte(struct ListNode* n) {
    int result = 0;
    struct ListNode* temp = n;
    int digit = 0;
    while(temp != NULL) {
        
        result += temp->val * pow(10,digit);
        digit ++;
        temp = temp -> next;
        
    }
    
    return result;
}



struct ListNode* node_init(int val) {
    struct ListNode* newnode = calloc(1,sizeof(struct ListNode));
    newnode->val = val;
    return newnode;
}





int get_digit(int sum) {
    int digit = 1;
    while(1) {
        if(sum < pow(10,digit)) {break;}
        digit++;
    }
    return digit;
}
struct ListNode* int_to_list(int sum,int digit) {
    struct ListNode head;
    struct ListNode* last = &head;
    int helper = 0;
    for(int i = 1;i<digit+1;i++) {
        int remain = sum % (int)pow(10,i) - helper;
        // printf("the len is %d\n",remain);
        helper+=remain;
        last->next = node_init(remain/(int)pow(10,i-1));
        last = last->next;
        
    }
    return head.next;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    // int sum = converte(l1) + converte(l2);
    // int digit = get_digit(sum);
    // return int_to_list(sum,digit);
    struct ListNode head;
    struct ListNode* last = &head;
    struct ListNode* cursor1 = l1;
    struct ListNode* cursor2 = l2;
    int o = 0;
    int c1;
    int c2;
    while( (cursor1 != NULL) || (cursor2 != NULL)) {
        if(cursor1 == NULL) {
            c1= 0;
        }else{
            c1 = cursor1->val;
        }
        if(cursor2 == NULL) {
            c2= 0;
        }else{
            c2 = cursor2 ->val;
        }
        int sum = c1+c2+o;
        if(sum >= 10) {
            o = 1;
            sum = sum-10;
        }else{
            o = 0;
        }
        last->next = node_init(sum);
        last = last->next;
        
        if(cursor1!= NULL) {
            cursor1 = cursor1->next;
        }
        if(cursor2!= NULL) {
            cursor2 = cursor2->next;
        }
    }
    return head.next;
}

int main() {
    struct ListNode* head = int_to_list(18,2);
    struct ListNode* head2 = int_to_list(0,1);
    struct ListNode* result = addTwoNumbers(head,head2);
    printf("the result is %d\n",converte(result));
}