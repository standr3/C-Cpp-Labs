#include <iostream>

using namespace std;

size_t resize1(int** array, size_t oldsize, size_t amount) {

	size_t new_size = oldsize + amount;
	int* new_array = new int[new_size]; // allocating new array 

	memcpy(new_array, array, oldsize * sizeof(int));  // copying old array into new array;
	delete[] * array; // delete old array
	*array = new_array; // the reason why we used double pointer -> we change the value that [*array] points to

	return new_size;
}
// -> malloc uses size_t type

size_t resize2(int** array, size_t oldsize, size_t amount){

	size_t new_size = oldsize + amount;
	//realloc might return null
	int* new_array = (int*)realloc(*array, new_size * sizeof(int));
	if (new_array) {
		*array = new_array;
		return new_size;
	} else {
		printf("realloc failed with null pointer returned\n");
		return oldsize;
	}
}
int main() {
	size_t arrsize = 50;
	int* myarray1 = new int[arrsize];
	int* myarray2 = (int*)malloc(sizeof(int) * arrsize);
	int* myarray3 = (int*)malloc(sizeof(int) * arrsize);

	printf("B: %p, %lu, A:%p \n",
			myarray1,
			resize1(&myarray1, arrsize, 5),
			myarray1);  // add 5 ints to this array;

	printf("B: %p, %lu, A:%p \n",
			myarray2,
			resize1(&myarray2, arrsize, 5),
			myarray2);  // add 5 ints to this array;

	for (int i = 0; i < 50; i++) {
		arrsize = resize2(&myarray3, arrsize, 1); // add 1 int
			printf("A: %p, S:%lu\n",
					myarray3,
					arrsize);
	}


	delete[] myarray1;
	free(myarray2);
	free(myarray3);

	return 0;
}
