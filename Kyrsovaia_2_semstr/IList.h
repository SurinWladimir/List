#pragma once

#include <string>

//using namespace std;
#include "Word.h"
//class CWord;

class C_IList
{
	unsigned   Cnt;

public:
	CWord     *pCurrent, *pHead, *pTail;

	C_IList();
	virtual ~C_IList();

	virtual CWord*  next_elem();
	virtual	CWord*  current_elem();
	virtual void    insert_elem(std::string sData) = 0;
	virtual void    push_back(std::string sData) = 0;
	virtual void    move_back(CWord *pElem) = 0;
	virtual void    show();                    // вывод на экран 
	virtual void    show(std::ofstream &fout); // вывод в открытый файл 
	int             size() const { return Cnt; }
	void            inc_size() { Cnt++; }
};
