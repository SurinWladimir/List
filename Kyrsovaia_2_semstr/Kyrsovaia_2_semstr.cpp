// Kyrsovaia_2_semstr.cpp : Defines the entry point for the console application.
//
//Методы
//Перемещение по списку на следующий элемент
//Добавление элемента после текущего
//Перемещение по списку назад


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include "UnoList.h"
#include "DuoList.h"

//#define LIST_TO_FILE

int main()
{	
	std::string   sFileName;
	std::ifstream f_in; // поток ввода из файла
	std::ofstream f_out;// поток вывода в файл

	std::cout << "enter input file name : ";
	std::cin >> sFileName;

	f_in.open(sFileName);

	if (!f_in.is_open()) {
		std::cout << "err open file : " << sFileName << "\r\n";
		return 0;
	}

#ifdef LIST_TO_FILE
	std::cout << "enter output file name : ";
	std::cin >> sFileName;
	f_out.open(sFileName);

	if (!f_out.is_open()) {
		std::cout << "err open file : " << sFileName << "\r\n";
		f_in.close();
		return 0;
	}		
#endif

	CUnoList List1;
	CDuoList List2;

// text parser	
	std::string s;
	std::string s2;
	while (f_in >> s) 
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			switch (s[i])
			{
			case '.':
			case ',':
			case '?':
			case '!':
			case '"':
			case '(':
			case ')':
			case ':':
			case ';':
			case ']':
			case '[':
			case '-':
				if (s2.size()) {
					List1.push_back(s2);
					List2.push_back(s2);
					s2 = "";
				}
				break;
			default:
				s2 += s[i]; 
				break;
			}
		}
		if (s2.size()) {
			List1.push_back(s2);
			List2.push_back(s2);
			s2 = "";
		}
	}
	///////////

	std::cout << "singly linked list - 1\r\n"; // односвязный список
	std::cout << "doubly linked list - 2\r\n"; // двусвязный список
	std::cout << "your choice : ";

	unsigned    uListType = 0;
	std::cin >> uListType;
	std::cout <<"\r\n";
	CWord *pCWord = 0;
	switch (uListType)
	{
	case 1: // "singly linked list - 1\r\n";
	{
		List1.show();
		std::cout << "\r\n";
		bool working = true;
		unsigned choose = 0;
		while (working)
		{
			std::cout << "\r\n";
			std::cout << "Current element - 1 \r\n";
			std::cout << "Next element - 2 \r\n";
			std::cout << "Insert element- 3 \r\n";
			std::cout << "Move current element back- 4 \r\n";
			std::cout << "Exit- 5 \r\n\r\n";
			std::cin >> choose;
			switch (choose)
			{
			case 1:
				pCWord = List1.current_elem();
				if (pCWord) {
					std::cout << "Current element: " << pCWord->GetData() << "\r\n";
				}
				else
				{
					std::cout << "Current element: Null" << "\r\n";
				}
				break;
			case 2:
				pCWord = List1.next_elem();
				if (pCWord) {
					std::cout << "Next element: " << pCWord->GetData() << "\r\n";
				}
				else
				{
					std::cout << "Next element: Null" << "\r\n";
				}
				break;
			case 3:
			{
				std::string word;
				std::cout << "Element to insert: ";
				std::cin >> word;
			    List1.insert_elem(word);
				List1.show();
			}
				break;
			case 4:
				List1.move_back();
				List1.show();
				break;
			
			default:
				working = false;
				break;
			}
		}
#ifdef LIST_TO_FILE
		List1.show(f_out);
#endif
	}
		break;
	case 2: // "doubly linked list - 2\r\n";
	{
		List2.show();
		std::cout << "\r\n";
		bool working = true;
		unsigned choose = 0;
		while (working)
		{
			std::cout << "\r\n";
			std::cout << "Current element - 1 \r\n";
			std::cout << "Next element - 2 \r\n";
			std::cout << "Prev element - 3 \r\n";
			std::cout << "Insert element- 4 \r\n";
			std::cout << "Move current element back- 5 \r\n";
			std::cout << "Exit- 6 \r\n\r\n";
			std::cin >> choose;
			switch (choose)
			{
			case 1:
				pCWord = List2.current_elem();
				if (pCWord) {
					std::cout << "Current element: " << pCWord->GetData() << "\r\n";
				}
				else
				{
					std::cout << "Current element: Null" << "\r\n";
				}
				break;
			case 2:
				pCWord = List2.next_elem();
				if (pCWord) {
					std::cout << "Next element: " << pCWord->GetData() << "\r\n";
				}
				else
				{
					std::cout << "Next element: Null" << "\r\n";
				}
				break;
			case 3:			
				pCWord = List2.prev_elem();
				if (pCWord) {
					std::cout << "Prev element: " << pCWord->GetData() << "\r\n";
				}
				else
				{
					std::cout << "Prev element: Null" << "\r\n";
				}
				break;
			case 4:
			{
				std::string word;
				std::cout << "Element to insert: ";
				std::cin >> word;
				List2.insert_elem(word);
				std::cout << "\r\n";
				List2.show();
			}
			break;
			case 5:
				List2.move_back();
				List2.show();
				break;

			default:
				working = false;
				break;	
			}
		}
#ifdef LIST_TO_FILE
		List2.show(f_out);
#endif
	}
		break;
	default:
		std::cout << "wrong choice\r\n";
		break;
	}

	f_in.close();

#ifdef LIST_TO_FILE
	f_out.close();
#endif

	system("pause");
}
