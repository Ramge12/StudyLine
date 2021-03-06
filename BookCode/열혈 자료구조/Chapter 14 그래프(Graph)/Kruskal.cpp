#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Edge
{
	int v1;		//간선이 연결하는 첫 번째 정점
	int v2;		//간선이 연결하는 두 번쨰 정점
	int weight;	//간선의 가중치
};

enum {A,B,C,D,E,F,G,H,I,J};

struct ALGraph
{
	int numV;
	int numE;
	List * adjList;
	int * visitInfo;
	PQueue pqueue;		//간선의 가중치 정보 저장
};

int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}

void GraphInit(ALGraph * pg, int nv) {
	//이전과 동일

	//우선순위 큐의 초기화
	PQueueInit(&(pg->pqueue), PQWeightComp);	//추가된 문장
}

void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV,toV,weight };	//간선의 가중치 정보를 담음

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	//간선의 가중치 정보를 우선순위 큐에 저장
	PEnqueue(&(pg->pqueue), edge);
}

void ConKruskalMST(ALGraph * pg)	//최소 비용 신장 트리의 구성
{
	//크루스칼 알고리즘 기반 MST의 구성
	Edge recvEdge[20];	//복원할 간선의 정보 저장
	Edge edge;
	int eidx = 0;

	//MST를 형성할 때까지 아래의 while문을 반복
	while (pg->numE + 1 > pg->numV)	//MST 간선의 수 +1 == 정점의 수
	{
		//우선순위 큐에서 가중치가 제일 높은 간선의 정보를 꺼낸다.
		edge = PDequeue(&(pg->pqueue));

		//우선순위 큐에서 꺼낸 간선을 실제로 그래프에서 삭제한다.
		RemoveEdge(pg, edge.v1, edge.v2);

		//간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인한다.
		if (!IsConnVertex(pg, edge.v1, edge.v2))
		{
			//경로가 없다면 삭제한 간선을 복원한다
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);

			//복원한 간선의 정보를 별도로 저장한다.
			recvEdge[eidx++] = edge;
		}
	}
	//우선순위 큐에서 삭제된 간선의 정보를 회복
	for (int i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph * pg)	//가중치 정보 출력
{
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		cout << edge.v1 + 65 << edge.v2 + 65 << edge.weight << endl;
	}
}

void RemoveEdge(ALGraph * pg, int fromV, int toV)		//간선의 소멸
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void RemoveWayEdge(ALGraph * pg, int fromV, int toV)	//한쪽 방향의 간선 소멸
{
	int edge;

	if (LFirst(&(pg->adjList[fromV]), &edge))
	{
		if (edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while (LNext(&(pg->adjList[fromV]), &edge))
		{
			if (edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

//인자로 전달된 두 정점이 연결되어 있다면 true, 그렇지 않다면 false 반환
int IsConnVertex(ALGraph * pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == true)
	{
		int visitFlag = false;

		//정점을 돌아다니는 도중에 목표를 찾는다면 true를 반환한다.
		if (nextV == v2)
		{
			//함수가 반환하기 전에 초기화를 진행한다.
			memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
			return true;		//목표를 찾았으니 true를 반환
		}

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
				//정점을 돌아다니는 도중에 목표를 찾는다면 true를 반환한다.
				if (nextV == v2)
				{
					//함수가 반환하기 전에 초기화를 진행한다.
					memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
					return true;		//목표를 찾았으니 true를 반환
				}

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
				visitV = Spop(&stack);
		}
	}
}