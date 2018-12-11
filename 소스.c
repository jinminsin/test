#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>

typedef struct node *NodePointer;
typedef struct node {
	char *data;//데이터 값
	int x;//x값
	int y;//y값
	int modeset;//모드 설정
	int mode; // 모드 실행 여부
	NodePointer after;//다음 순서의 단어
};

char *word[] = { "anxiety","boredom","conpuse","dragon","excitement","frustrate","greed","happiness","impatience","jealousy","kindess","loyalty","master","necessary","overwhelming","pessimism","quietus","relief","satisfaction","thrill","union","view","worriation","yell","zealot" };

void reverse(NodePointer node)//노드의 데이터를 반대로 표현.
{
	node->y += 1; // 아래로 1칸
	char k;

	if (node->mode == 0)//모드에 맞게 설정되지 않았다면
	{
		node->mode = 1;//설정
		for (int i = 0; i < strlen(node->data) - 1; i++)
		{
			k = node->data[i];
			node->data[i] = node->data[strlen(node->data) - 1 - i];
			node->data[strlen(node->data) - 1 - i] = k;
		}//데이터 값 변환
	}

}

void diagonal(NodePointer node)//대각선 이동
{
	srand(time(NULL));
	int n = rand() % 3 - 1;// -1(왼), 0(아래) , 1(오른)

	setupterm(NULL, fileno(stdout), (int *)0);
	int rows = tigetnum("lines");
	int columns = tigetnum("cols");
	//해상도 파악

	node->y += 1;

	if (n == -1)
		if (node->x != 0)
			node->x -= 1;
	
	if (n == 1)
		if (node->x != columns)
			node->x += 1;

	//추후 업데이트 될 가능성 있는 부분
	//다른 노드와 충돌 관련 부분
}