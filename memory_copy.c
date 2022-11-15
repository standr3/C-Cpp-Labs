#include <stdio.h>
#include <string.h> // for memcpy

#define NODE_OFFSET 10
#define BUFFER_SIZE 4096

// Bit fields are used here in the node structure declaration 

typedef struct node {
	unsigned int isValid : 1;
	unsigned int size : 15;
	struct node* next;
} node_t;


int main() {
	node_t n = {n.isValid = 1, n.size = 367, n.next = NULL };
	node_t n2;

	/*
		Verbose method of copying the value of n2 to n
	*/
	n2.isValid = n.isValid;
	n2.size = n.size;
	n2.next = n.next;
	/*
		Compact method of copying the value of n2 to n
	*/
	n2 = n;
	/*
		memcpy method of copying the value of n2 to n
	*/
	memcpy(&n2, &n, sizeof(node_t)); //this copies a block of memory from address of n to address n2
	printf("n2 = %d, %d, %p\n", n2.isValid, n2.size, n2.next);

	/*
		memcpy copies struct content inside a buffer
	*/

	node_t *n3;
	char buffer[BUFFER_SIZE]; // we assume this is a network packet payload

	memcpy(buffer + NODE_OFFSET, &n, sizeof(node_t)); // we copy the node at new location 
	n3 = (node_t*)(buffer + NODE_OFFSET); // we decide  n3 will point to that location in our buffer

	printf("n3 = %d, %d, %p\n", n3->isValid, n3->size, n3->next);
	// we get garbage values because buffer is allocated on stack memory

	// we set all values inside the buffer to 0xFF
	memset(buffer, 0xFF, BUFFER_SIZE);

	printf("after memset -> n3 = %d, %d, %p\n", n3->isValid, n3->size, n3->next);
	

	return 0;
}
