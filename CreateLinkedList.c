#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int val;
    struct node * next;

};

typedef struct node * NodeAddress;



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //




// PRINTING A LINKED LIST
void PrintLinkedList (NodeAddress head) {
    printf("Linked List= ");
    for (NodeAddress c= head; c!= NULL; c=c->next) {
        printf( c==head? "%d" : ", %d", c->val);
    }
}


// GENERATING AN ARRAY
int * generateArray(int n) {
    int * t = malloc( n * sizeof(int) );
    if (t) {
        for( int i=0; i<n; i++) {t[i]=i;}
    }
    return t;
}


// CREATING A LINKED LIST WITH THE GENERATED ARRAY
NodeAddress LinkedListFromArray (int * a, int n) {
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;

    if (n>0) {
        head= malloc(sizeof(struct node));
        head->val= a[0];
        head->next= NULL;
        temp = head;
    }
    for (i=1; i<n; i++) {
        temp = malloc(sizeof( struct node));
        temp = temp->next;
        temp->val = a[i];
        temp->next = NULL;
    }
}


// FREEING THE SPACE, PREVENTING MEMORY LEAKS
void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}



// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

int main(int argc, char **argv) {
    int *a, *list;
    int n = 10;
    NodeAddress list;

    a = generateArray(n);
	list = linkedListFromArray(a,n);
    printLinkedList(list);

	free(a);
	freeLinkedList(list);
    return 0;
}