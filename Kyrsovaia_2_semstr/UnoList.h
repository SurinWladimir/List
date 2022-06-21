#pragma once

#include "IList.h"

class CUnoList : public C_IList
{
public:
	CUnoList();
	~CUnoList();
	void    insert_elem(std::string sData);
	void    push_back(std::string sData);
	void    move_back(CWord *pElem = 0); // 0 - значение по умолчанию,  будем использовать pCurrent
};