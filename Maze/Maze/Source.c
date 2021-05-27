#include <stdio.h>
#define FALSE 0
#define TRUE  1
#define M 9
#define N 9

typedef struct
{
	int x, y, dir;
} data;
data stack[M*N];

typedef struct
{
	int  vert, horiz;
} Move;
Move move[4];
char maze[M + 2][N + 2] = {
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
 {1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
 {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
 {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
 {1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
 {1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
 {1, 1, 0, 1, 0, 0, 0, 0, 1, 1},
 {1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

char mark[M + 2][N + 2] = {0};

void push(int* top, data store)
{
	(*top)++;
	stack[*top].x = store.x;
	stack[*top].y = store.y;
	stack[*top].dir = store.dir;
}

data pop(int* top)
{
	data result;
	result = stack[*top];
	(*top)--;
	return result;
}﻿;

void mazepath(void)
{
	int top;
	int i, j, next_i, next_j, dir, found = FALSE;
	data store;
	int k, m;
	mark[1][1] = 1; 
	top = 0;
	stack[0].x = 1;
	stack[0].y = 1;
	stack[0].dir = 1;
	while (top > -1 && !found) 
	{
		store = pop(&top);
		i = store.x;
		j = store.y;
		dir = store.dir;
		while (dir < 4 && !found)
		{
			next_i = i + move[dir].vert;
			next_j = j + move[dir].horiz;
			if (next_i == M && next_j == N) {
				found = TRUE;

				printf("The path is as follow :\n");
				for (k = 0; k <= top; k++)
					printf("(%d, %d) ", stack[k].x, stack[k].y);
				printf("(%d, %d) ", i, j);
				printf("(%d, %d) \n", M, N);
			}
			else if (!maze[next_i][next_j] && !mark[next_i][next_j]) {
				mark[next_i][next_j] = 1;
				store.x = i;
				store.y = j;
				store.dir = ++dir;
				push(&top, store);
				i = next_i;
				j = next_j;
				dir = 0;
			}
			else dir++;
		}
	}
	if (!found) {
		printf("The Maze does not have a path\n");
	}


}
int main(void)
{

	move[0].vert = -1; move[0].horiz = 0;
	move[1].vert = 0;  move[1].horiz = 1;
	move[2].vert = 1;  move[2].horiz = 0;
	move[3].vert = 0;  move[3].horiz = -1;

	mazepath();
}


