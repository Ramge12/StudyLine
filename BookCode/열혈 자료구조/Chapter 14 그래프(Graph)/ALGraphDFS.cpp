#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#include "DLinkedList.h"		//연결 리스트를 가져다 쓴다!

//정점의 이름들을 상수화
enum { A, B, C, D, E, F, G, H, I, J };

struct ALGraph
{
	int numV;			//정점의 수
	int numE;			//간선의 수
	List * adjList;		//간선의 정보
	int * visitInfo;	//탐색이 진행된 정점의 정보
};

//그래프의 초기화
void GraphInit(ALGraph * pg, int nv)	//그래프의 초기화
{
	//위와 동일

	//정점의 수를 길이로 하여 배열을 할당
	pg->visitInfo = new int;
	//배열의 모든 요소를 0으로 초기화!
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

//그래프의 리소스 해제
void GraphDestroy(ALGraph * pg)
{
	//위와 동일

	//할당된 배열의 소멸!
	if (pg->visitInfo != NULL)
		delete(pg->visitInfo);
}

//간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

int WhoIsPrecede(int data1, int data2);

int VisitVertex(ALGraph * pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		cout << visitV + 65 << endl;
		return true;
	}
	return false;
}

//정점의 정보 출력 : Depth Fist Search	기반
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == true)
	{
		int visitFlag = false;

		if (VisitVertex(pg, nextV) == true)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = true;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == true)
			{
				if (VisitVertex(pg, nextV) == true)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = true;
					break;
				}
			}
		}
		if (visitFlag == false)
		{
			if (SIsEmpty(&stack) == true)
				break;
			else
				visitV = SPop(&stack);
		}
		memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
	}
}