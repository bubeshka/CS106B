#include "OurStack.h"
#include "error.h"

/* Constant controlling the default size of our stack. */
const int kDefaultSize = 4;

/* Constructor initializes the fields of the stack to
 * appropriate defaults.
 */
OurStack::OurStack() {
	logicalLength = 0;
	allocatedLength = kDefaultSize;
	elems = new int[allocatedLength];
}

/* Destructor cleans up memory allocated by the stack. */
OurStack::~OurStack() {
	delete[] elems;
}

int OurStack::size() {
	return logicalLength;
}

bool OurStack::isEmpty() {
	return size() == 0;
}

void OurStack::push(int value) {
	if (allocatedLength == logicalLength) {
		grow();
	}

	elems[logicalLength] = value;
	logicalLength++;
}

int OurStack::peek() {
	if (isEmpty()) {
		error("What is the sound of one hand clapping?");
	}

	return elems[logicalLength - 1];
}

int OurStack::pop() {
	/* This line both does bounds checking and obtains the
	 * return value.
	 */
	int result = peek();
	
	logicalLength--;
	return result;
}

void OurStack::grow() {
	int *tmp = new int[++allocatedLength];
	for (int i=0; i<allocatedLength-1; i++) {
		 tmp[i] = elems[i];
	} 
	delete [] elems;
	elems = tmp;
}


