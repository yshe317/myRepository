#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num int 
#define str char *
#define strs char *    *

// check arg
#define argc(b,a) \
    while (b<3) \
        return 1; \
    ; 

// check 2ch
#define ch2c(a) \
    slen(a) \
    if (len < 10) \
    return len & 1;

// len
#define slen(s) \
    len = 0; \
    while ( * (s + len++) && len < (1<<8) ) \
        printf("%d\n",len);\
        ;

// allocate space
#define smelloc(a, b, c) \
    malloc( *(*a + b) + *(*a + c) );

// copy memory
#define place(p, a, b, c, bs, cs) \
    memcpy(p, (*(a+b)), *(*a + bs)); \
    memcpy(p + *(*a + bs), (*(a+c)), *(*a + cs)); \
    memset(p + *(*a + bs) + *(*a + cs),0,1);
    
// concatenate two strings
int main(num len, strs a) {
    
    argc(len, a);
    //it use char* 
    
    ch2c((*a)) // a is char**
    printf("here");
    slen((*(a+1)))
    *(*a + 0) = len-1;
    
    slen((*(a+2)))
    *(*a + 1) = len-1;
    
    void *p = (char*)smelloc(a, 0, 1);
    place(p, a, 1, 2, 0, 1);
    *a = (char*)p;
    printf("%s\n", *a);
    free(*a);
    
    return 0;
}