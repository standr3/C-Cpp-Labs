#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef struct packet{
	int type;
	int age;
} packet_t;

int main() {

	packet_t* packets = (packet_t*) malloc(sizeof(packet_t) * 10);

	//packet_t* p2 = packets + 2 * sizeof(packet_t); // incorrect; it moves 2 times the size of the struct
	//printf(
	//	"packets = %p, p2 = %p, sizeof(packet_t) = %lu\n",
	//	packets,
	//	p2,
	//	sizeof(packet_t));
	packet_t* p2 = packets + 2; // incorrect
	printf(
		"packets = %p, p2 = %p, sizeof(packet_t) = %lu\n",
		packets,
		p2,
		sizeof(packet_t));

	/* second way to move the pointer  - cast to (char*) type */
	packet_t* p3 =  (packet_t*) (((char *)packets) + (2 * sizeof(packet_t))); // incorrect
	printf(
		"packets = %p, p3 = %p, sizeof(packet_t) = %lu\n",
		packets,
		p3,
		sizeof(packet_t));

	return 0;
}
