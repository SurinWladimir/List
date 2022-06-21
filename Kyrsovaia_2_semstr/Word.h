#pragma once

#include <string>

class CWord
{
	std::string m_sData;

public:
	CWord* pPrev;
	CWord* pNext;

	CWord(std::string sStr);
	~CWord() = default;
	std::string&  GetData() { return m_sData; }
};
