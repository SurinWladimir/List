#include "stdafx.h"

#include "Word.h"
#include "IList.h"
#include "DuoList.h"

CDuoList::CDuoList()
{
}

CDuoList::~CDuoList()
{
	while (pHead)
	{
		pCurrent = pHead->pNext;
		delete pHead;
		pHead = pCurrent;
	}
}

CWord*  CDuoList::prev_elem()
{
	if (pCurrent) {
		pCurrent = pCurrent->pPrev;
	}
	else {
		pCurrent = pTail;
	}
	return pCurrent;
}

void  CDuoList::insert_elem(std::string sData)
{
	CWord *pNewCWord = new CWord(sData);

	if (pCurrent != pTail)
	{
		pNewCWord->pNext = pCurrent->pNext;
		pNewCWord->pPrev = pCurrent;
		pCurrent->pNext->pPrev = pNewCWord;
		pCurrent->pNext = pNewCWord;
	}
	else
	{
		pTail->pNext = pNewCWord;
		pNewCWord->pPrev = pTail;
		pTail = pNewCWord;
	}
	pCurrent = pNewCWord;
	inc_size();
}

void  CDuoList::push_back(std::string sData)
{
	CWord *pNewCWord = new CWord(sData);

	if (pHead != NULL)
	{
		pNewCWord->pPrev = pTail;
		pTail->pNext = pNewCWord;
		pTail = pNewCWord;
	}
	else
	{
		pNewCWord->pPrev = NULL;//
		pCurrent = pHead = pTail = pNewCWord;
	}
	inc_size();
}

void  CDuoList::move_back(CWord *pElem)
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
		pElem->pPrev->pNext = pElem->pNext;
		pElem->pNext->pPrev = pElem->pPrev;
	}

	pTail->pNext = pElem;
	pElem->pNext = NULL;
	pElem->pPrev = pTail;
	pTail = pElem;
	inc_size();
}
