#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>

typedef struct node *NodePointer;
typedef struct node {
	char *data;//������ ��
	int x;//x��
	int y;//y��
	int modeset;//��� ����
	int mode; // ��� ���� ����
	NodePointer after;//���� ������ �ܾ�
};

char *word[] = { "anxiety","boredom","conpuse","dragon","excitement","frustrate","greed","happiness","impatience","jealousy","kindess","loyalty","master","necessary","overwhelming","pessimism","quietus","relief","satisfaction","thrill","union","view","worriation","yell","zealot" };

void reverse(NodePointer node)//����� �����͸� �ݴ�� ǥ��.
{
	node->y += 1; // �Ʒ��� 1ĭ
	char k;

	if (node->mode == 0)//��忡 �°� �������� �ʾҴٸ�
	{
		node->mode = 1;//����
		for (int i = 0; i < strlen(node->data) - 1; i++)
		{
			k = node->data[i];
			node->data[i] = node->data[strlen(node->data) - 1 - i];
			node->data[strlen(node->data) - 1 - i] = k;
		}//������ �� ��ȯ
	}

}

void diagonal(NodePointer node)//�밢�� �̵�
{
	srand(time(NULL));
	int n = rand() % 3 - 1;// -1(��), 0(�Ʒ�) , 1(����)

	setupterm(NULL, fileno(stdout), (int *)0);
	int rows = tigetnum("lines");
	int columns = tigetnum("cols");
	//�ػ� �ľ�

	node->y += 1;

	if (n == -1)
		if (node->x != 0)
			node->x -= 1;
	
	if (n == 1)
		if (node->x != columns)
			node->x += 1;

	//���� ������Ʈ �� ���ɼ� �ִ� �κ�
	//�ٸ� ���� �浹 ���� �κ�
}