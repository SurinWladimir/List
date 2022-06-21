#include "stdafx.h"

#include <iostream>
#include <fstream>

//#include "Word.h"
#include "IList.h"

C_IList::C_IList() :
	pCurrent(NULL),
	pHead(NULL),
	pTail(NULL),
	Cnt(NULL)
{
}

C_IList::~C_IList()
{
}

CWord*  C_IList::next_elem()
{
	if (pCurrent) {
		pCurrent = pCurrent->pNext;
	}
	else {
		pCurrent = pHead;
	}
	return pCurrent;
}

CWord* C_IList::current_elem()
{
	return pCurrent;
}

void C_IList::show()
{
	CWord *tmp = pHead;
	while (tmp)
	{
		std::cout << tmp->GetData() << " ";
		tmp = tmp->pNext;
	}
	std::cout << "\n";
}

void C_IList::show(std::ofstream &fout)
{
	CWord *tmp = pHead;
	while (tmp)
	{
		fout << tmp->GetData() << " ";
		tmp = tmp->pNext;
	}
	std::cout << "\n";
}

