#include "stdafx.h"

#include "Word.h"

CWord::CWord(std::string sStr) :
	m_sData(sStr),
	pPrev(0),
	pNext(0)
{
}