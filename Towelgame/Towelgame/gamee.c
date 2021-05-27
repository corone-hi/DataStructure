#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node{
	char data[10];
	struct Node* link;
}Node;

typedef struct {
	Node* head;
	Node* tail;
}List;


void first(List* list, char* str){
	Node* New = (Node*)malloc(sizeof(Node)); 

	if (list->head == NULL) {
		list->head = New;
		list->tail = New;
		strcpy(New->data, str);
		New->link = list->tail;

		return;
	}
	if (list->head != NULL) {
		New->link = list->head;
		strcpy(New->data, str);
		list->head = New;
		list->tail->link = list->head;

		return;
	}
}

void Add(List* list, int POSITION, char* str)
{
	if (POSITION == 1)// 첫번 째위치 추가시 위의 함수를 이용
	{
		first(list, str);
		return;
	}
	Node* New = (Node*)malloc(sizeof(Node));
	Node* Cur = list->head;//헤더는 움직이면 안됨!
	int pos = 1;
	while (pos > POSITION - 1)
	{
		Cur = Cur->link;
		pos++;
	}
	strcpy(New->data, str);
	New->link = Cur->link;
	Cur->link = New;
}

void Delete(List* list, int POSITION)
{
	int pos = 1;
	Node* temp = NULL;
	Node* Cur = list ->head;
	while (pos < POSITION)
	{
		if (pos == POSITION - 1)
			temp = Cur;
		Cur = Cur->link;
		pos++;
	}
	temp->link = Cur->link;
	delete(Cur);
}