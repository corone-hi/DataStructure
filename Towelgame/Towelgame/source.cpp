#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char* data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
	int size;
} LinkedList;




LinkedList* makelist() {
	LinkedList* newList;
	newList = (LinkedList*)malloc(sizeof(LinkedList));
	newList->head = NULL;
	newList->size = 0;
	return newList;
}

Node* makenode(char* str) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(str) + 1);
	newNode->data = str;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}



void insertLastNode(LinkedList* list, char* str) {
	Node* newNode = CDLL_Node_Init(str);

	if (list->head == NULL) {
		list->head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else {
		newNode->prev = list->head->prev;
		newNode->next = list->head;
		list->head->prev->next = newNode;
		list->head->prev = newNode;
	}
	list->size++;
}

Node* CDLL_findFastRoot(LinkedList* list, int n) {
    Node* selectNode = list->head;
    int totalNodes = list->size;
    int median = totalNodes >> 1; // 비트 연산 나누기 2 (중앙값)
    int i;

    // n가 노드의 중앙값 이하일 경우 next로 이동
    if(n <= median) {
        printf("next -> %d\n",n);
        for(i=0;i<n;i++) {
            selectNode = selectNode->next;
        }
    }
    // n가 노드 중앙값보다 클경우 prev로 이동
    else {
        printf("prev <- %d\n",totalNodes-n);
        for(i=0;i< totalNodes-n; i++) {
            selectNode = selectNode->prev;
        }
    }

    return selectNode;
}

void removeLastNode(LinkedList* list) {
	Node* selectNode = list->head;

	if (list->head == NULL) return;

	if (list->head->next == list->head) {
		list->head = NULL;
	}
	else if (list->head->next == list->head->prev) {
		selectNode = list->head->next;
		list->head->next = list->head;
		list->head->prev = list->head;
	}
	else {
		selectNode = list->head->prev;
		list->head->prev = list->head->prev->prev;
		list->head->prev->next = list->head;
	}
	free(selectNode->data);
	free(selectNode);
	list->size--;
}

void removeNodeAt(LinkedList* list, int n) {
	Node* selectNode = list->head;
	int totalNodes = list->size;

	if (list->head == NULL || n < 0 || totalNodes - 1 < n) {
		return;
	}
	if (n == 0) {
		selectNode = list->head;
		list->head->next->prev = list->head->prev;
		list->head->prev->next = list->head->next;
		list->head = list->head->next;
	}
	else {
		selectNode = CDLL_findFastRoot(list, n);
		selectNode->prev->next = selectNode->next;
		selectNode->next->prev = selectNode->prev;
	}
	free(selectNode->data);
	free(selectNode);
	list->size--;
}

void searchNodes(LinkedList* list, char* str) {
	int access[100] = { -1 };
	int accessCount = 0, nodeN = 0;
	Node* s_prevNode = list->head->prev;
	Node* s_nextNode = list->head;
	int loopCount = list->size % 2 ? (list->size >> 1) + 1 : list->size >> 1;

	for (int i = 1; i <= loopCount; i++) {
		if (!strcmp(s_nextNode->data, str)) {
			access[accessCount] = nodeN;
			access[accessCount + 1] = -1;
			accessCount++;
		}
		if (i == loopCount && list->size % 2 == 1) {
			break;
		}
		if (!strcmp(s_prevNode->data, str)) {
			access[accessCount] = list->size - i;
			access[accessCount + 1] = -1;
			accessCount++;
		}
		s_prevNode = s_prevNode->prev;
		s_nextNode = s_nextNode->next;
		nodeN++;
	}

	if (access[0] == -1) {
		printf("%s Not Found!\n\n", str);
	}
	else {
		for (int i = 0; i < 100; i++) {
			if (access[i] == -1) {
				break;
			}
			else {
				printf("%d ", access[i]);
			}
		}
		printf("\n\n");
	}
}

void printList(LinkedList* list) {
	Node* selectNode = list->head;
	int i;
	printf("List = ");

	for (i = 0; i < list->size; i++) {
		printf("%s", selectNode->data);
		selectNode = selectNode->next;
		if (i != list->size - 1) {
			printf(", ");
		}
	}
	printf(" (Total = %d)\n\n", list->size);
}



int main() {
	LinkedList* list;

	list = makelist();

	insertLastNode(list, "Kim");
	insertLastNode(list, "Park");
	insertLastNode(list, "Shin");
	insertLastNode(list, "Hong");
	insertLastNode(list, "Lee");
	insertLastNode(list, "Han");
	insertLastNode(list, "Paek");
	insertLastNode(list, "Hwang");
	insertLastNode(list, "Woo");
	insertLastNode(list, "Choi");
	insertLastNode(list, "Kook");
	insertLastNode(list, "Kang");
	insertLastNode(list, "Yu");
	printList(list);


	printf("Search Ali\n");
	searchNodes(list, "Ali");

	printf("Remove node at 2\n");
	removeNodeAt(list, 2);
	printList(list);

	printf("Remove node at 0\n");
	removeNodeAt(list, 0);
	printList(list);


	return 0;
}
