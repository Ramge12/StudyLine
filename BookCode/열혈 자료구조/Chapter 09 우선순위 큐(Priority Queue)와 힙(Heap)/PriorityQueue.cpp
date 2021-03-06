#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

include "PriorityQueue.h"
include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue * ppq, PriorityComp pc)
{
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue * ppq)
{
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue * ppq, PQData data)
{
	HInsert(ppq, data);
}
PQData PDequeue(PQueue * ppq)
{
	return HDelete(ppq);
}


int main()
{

    return 0;
}

