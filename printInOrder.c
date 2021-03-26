#include <sched.h>

/*
	dummy c solution for scheduling threads
	question's url = https://leetcode.com/problems/print-in-order
	
	it's an accepted solution but it's dummy because it makes the program slower
*/

typedef struct {
    // User defined data may be declared here.
    int order;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    obj->order = 0;
    return obj;
}

void first(Foo* obj) {
    obj->order = 0;
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj->order++;
}

void second(Foo* obj) {
    while(obj->order < 1) 
        sched_yield();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    obj->order++;
}

void third(Foo* obj) {
    while(obj->order<2)
        sched_yield();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    
}
