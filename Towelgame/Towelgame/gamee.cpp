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


void Initializer(List* list) {
	list->head = NULL;
	list->tail = NULL;
}
void first(List* list, char* str){
	Node* New = (Node*)malloc(sizeof(Node)); 

	if (list->head == NULL) {
		list->head = New;
		list->tail = New;
		strcpy_s(New->data, str);
		New->link = list->tail;

		return;
	}
	if (list->head != NULL) {
		New->link = list->head;
		strcpy_s(New->data, str);
		list->head = New;
		list->tail->link = list->head;

		return;
	}
}

void Add(List* list, int key, char* str)
{
	if (key == 1)
	{
		first(list, str);
		return;
	}
	Node* New = (Node*)malloc(sizeof(Node));
	Node* Cur = list->head;
	int pos = 1;
	while (pos > key - 1)
	{
		Cur = Cur->link;
		pos++;
	}
	strcpy_s(New->data, str);
	New->link = Cur->link;
	Cur->link = New;
}

void Delete(List* list, int key)
{
	int pos = 1;
	Node* temp = NULL;
	Node* Cur = list ->head;
	while (pos < key)
	{
		if (pos == key - 1)
			temp = Cur;
		Cur = Cur->link;
		pos++;
	}
	printf("%d -  %s\n", key, Cur->data);
	temp->link = Cur->link;
	delete(Cur);
}


void Print(List* list)
{
	Node* Cur = list->head;
	printf("명단:  %s ", Cur->data);
	Cur = Cur->link;

	while (Cur != list->head)
	{
		printf("%s ", Cur->data);
		Cur = Cur->link;
	}

	printf("\n\n");
}

List* list;

int main(void) {

	
	list = (List*)malloc(sizeof(List));
	Initializer(list);

	char name[10] = "Kim";
	Add(list, 1, name);
	char name1[10] = "Park";
	Add(list, 2, name1);
	char name2[10] = "Kang";
	Add(list, 3, name2);
	char name3[10] = "Shin";
	Add(list, 4, name3);
	char name4[10] = "Paek";
	Add(list, 5, name4);
	char name5[10] = "Choi";
	Add(list, 6, name5);
	char name6[10] = "Lee";
	Add(list, 7, name6);
	char name7[10] = "Han";
	Add(list, 8, name7);
	char name8[10] = "Song";
	Add(list, 9, name8);
	char name9[10] = "yoo";
	Add(list, 10, name9);
	char name10[10] = "Oh";
	Add(list, 11, name10);
	char name11[10] = "Kong";
	Add(list, 12, name11);
	char name12[10] = "Woo";
	Add(list, 13, name12);

	//Print(list);


	Delete(list, (rand() % 13) + 1);
	Print(list);

	Delete(list, (rand() % 13) + 1);
	Print(list);

	Delete(list, (rand() % 13) + 1);
	Print(list);

	Delete(list, (rand() % 13) + 1);
	Print(list);

	Delete(list, (rand() % 13) + 1);
	Print(list);

	Delete(list, 5);
	Print(list);

	Delete(list, 13);
	Print(list);

	Delete(list, 9);
	Print(list);

	Delete(list, 7);
	Print(list);

	Delete(list, 2);
	Print(list);

	Delete(list, 11);
	Print(list);

	printf("\n\n");
	
	printf("<게임종료>\n");

	Print(list);
	

	return 0;
}

