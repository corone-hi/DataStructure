#include <stdio.h>

int binarySearch(int A[], int low, int high, int key) {
	while (low <= high) {
		int mid = (low + high) / 2;
		
		if (A[mid] == key) return mid;
		printf("mid:%d low:%d high:%d \n", mid, low, high);
		if (A[mid] > key) {
			high = mid - 1;
			printf("mid:%d low:%d high:%d \n", mid, low, high);
		}
		else {
			low = mid + 1;
			printf("mid:%d low:%d high:%d \n", mid, low, high);
		}
	}
	return -1;
}

int main(void) {
	int A[30] = { 1, 3, 5, 6, 7, 8, 11, 12, 14, 15, 24, 26, 42, 43, 48, 49, 51, 55, 56, 59,66, 67, 69, 70, 71, 73, 75, 80, 96, 99 };

	int first = binarySearch(A, 0, 29, 3);
	printf("KEY: %d\n\n",first);

	int second = binarySearch(A, 0, 29, 96);
	printf("KEY: %d\n\n", second);

	int third = binarySearch(A, 0, 29, 15);
	printf("KEY: %d\n\n", third);

	int fourth = binarySearch(A, 0, 29, 66);
	printf("KEY: %d\n\n", fourth);

	int fifth = binarySearch(A, 0, 29, 99);
	printf("KEY: %d\n\n", fifth);

	return 0;
}