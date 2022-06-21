#include "stdafx.h"

#include "Word.h"
#include "UnoList.h"

CUnoList::CUnoList()
{
}

CUnoList::~CUnoList()
{
	while (pHead)
	{
		pCurrent = pHead->pNext;
		delete pHead;
		pHead = pCurrent;
	}
}

void  CUnoList::insert_elem(std::string sData)
{
	CWord *pNewCWord = new CWord(sData);
	if (pCurrent != pTail)
	{
		pNewCWord->pNext = pCurrent->pNext;
		pCurrent->pNext = pNewCWord;
	}
	else
	{
		pTail->pNext = pNewCWord;
		pTail = pNewCWord;
	}
	pCurrent = pNewCWord;
	inc_size();
}

void  CUnoList::push_back(std::string sData)
{
	CWord *pNewCWord = new CWord(sData);

	if (pHead != NULL)
	{
		CWord *tmp = pHead;
		while (tmp->pNext != NULL)
		{
			tmp = tmp->pNext;
		}
		tmp->pNext = pNewCWord;
	}
	else
	{
		pCurrent = pHead = pNewCWord;
	}
	pTail = pNewCWord;
	inc_size();
}

void  CUnoList::move_back(CWord *pElem)
{
	if (!pElem)
		pElem = pCurrent;

	if (pHead == pTail)
		return;
	if (pTail == pElem)
		return;

	if (pElem == pHead)
	{
		pHead = pHead->pNext;
	}
	else {
		CWord *tmp = pHead;
		while (tmp->pNext != pElem) //поиск элемента перед выбранным 
		{
			tmp = tmp->pNext;
		}
		tmp->pNext = pElem->pNext;
	}
	pTail->pNext = pElem;
	pElem->pNext = NULL;
	pTail = pElem;
}
