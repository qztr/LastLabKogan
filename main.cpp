/*
сведения о каждом автобусе :
	1) номер
	2) имя водителя
	3) номер маршрута
что делает:
	1) список автобусов в парке
	2) при выезде авт из парка добавить в список авт на маршр
	3) при въезде аналог
	4) вывод обоих списков по завпросу.

*/



/*
Двусвязный линейный список с двумя сторожами заполнить
случайными целыми числами.
Удалить все элементы, содержащие отрицательные числа.
Переместить в начало списка все элементы с нечетным значением.

*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale.h>
#include <string>


#define NULL 0

using namespace std;

struct List
{
	int busNumber;
	string driverName;
	int marchNum;
	int info;
	List * pred, *next;
};

//Функция вставляет элемент p в список после элемента last
// возвращает указатель на вставленный в список элемент
List * InsertElementIntoList(List * last, List * p)
{
	if (last && p)
	{
		p->pred = last;
		p->next = last->next;
		last->next = p;
		p->next->pred = p;
		return p;
	}
	else
		return NULL;
}

// Функция создает двусвязный список из n элементов с двумя сторожами
// Через head возвращает указатель на головного сторожа, 
// через tail - на хвостового сторожа
void CreateRandomList(List * &head, List * &tail)
{
	head = new List;
	tail = new List;

	head->next = tail;
	tail->pred = head;

	List * last = head;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		List * p = new List;
		p->info = rand() % 200 - 100;
		p->driverName = ("Driver{i} ");
		p->marchNum = i;

		last = InsertElementIntoList(last, p);
	}

	return;
}

void CreateEmptyList(List * &head1, List * &tail1) {
	head1 = new List;
	tail1 = new List;

	head1->next = tail1;
	tail1->pred = head1;

	List * last1 = head1;
	srand(time(NULL));
	for (int i = 0; i < 1; i++)
	{
		List * p = new List;
		p->info = NULL;
		p->driverName = "";
		p->marchNum = NULL;

		last1 = InsertElementIntoList(last1, p);
	}
}

// Функция печатает на консоль значения двусвязного списка
// с двумя сторожами head и tail

void PrintList(List * head, List * tail)
{
	List * p = head->next;
	while (p != tail)
	{
		cout << "bus number: " << p->info << endl;
		cout << "march number: " << p->marchNum << endl;
		cout << "driver name: " << p->driverName << endl;
		cout << endl;

		p = p->next;
	}
	cout << endl;
	return;
}

// Функция исключает элемент р из списка, возвращает указатель на
// элемент, следовавший после него
List * RemoveElement(List *p)
{
	if (p)
	{
		List * p1 = p->pred;
		List * p2 = p->next;
		p1->next = p2;
		p2->pred = p1;
		p->pred = p->next = NULL;
		return p2;
	}
	else
		return NULL;
}

// Функция удаляет из списка элементы с отрицательным значением
// head - головной сторож, tail - хвостовой сторож
void DeleteNegativeElementsFromList(List * head, List * tail)
{
	List * p = head->next;
	while (p != tail)
	{
		if (p->info < 0)
		{
			List * q = RemoveElement(p);
			delete p;
			p = q;
		}
		else
			p = p->next;
	}

	return;
}

void FindandDel(List * head, List * tail, int xey)
{
	List * p = head->next;
	while (p != tail)
	{
		if (p->info == xey)
		{
			List * q = RemoveElement(p);

			delete p;
			p = q;
		}
		else
			p = p->next;
	}

	return;
}

void FindandDel69(List * head, List * tail, int xey, List *head1, List *tail1)
{
	List * p = head->next;
	while (p != tail)
	{
		if (p->info == xey)
		{
			p->pred = tail1;
			p->next = tail1->next;
			tail1->next = p;

			tail1->next = p;
			p->pred = tail->pred;

			//p->next->pred = p;

			List * q = RemoveElement(p);
			delete p;
			p = q;
		}
		else
			p = p->next;
	}

	return;
}

void PushFromRtoE(List * head, List * tail, int xey, List *head1, List *tail1) {
	List * p = head->next;
	List *p1 = head1->next;
	while (p != tail)
	{
		if (p->info == xey) {
			head1 = new List;
			List * last = tail1;
			last = InsertElementIntoList(last, p);
			List * q = RemoveElement(p);
			delete p;
			p = q;
		}
		else
			p = p->next;
	}


}

// Функция перемещает в начало списка все элементы 
// с нечетным значением.
// head - головной сторож, tail - хвостовой сторож 
void MoveOddElemetsToEndOfList(List * head, List * tail)
{
	List * p = head->next;
	while (p != tail)
	{
		if (p->info % 2 == 1)
		{
			List * q = RemoveElement(p);
			InsertElementIntoList(head, p);
			p = q;
		}
		else
			p = p->next;
	}

}

void main()
{
	setlocale(LC_ALL, "Rus");

	List * head = NULL, *tail = NULL;
	List * head1 = NULL, *tail1 = NULL;

	cout << "Исходный список" << endl;
	CreateRandomList(head, tail);
	PrintList(head, tail);
	CreateEmptyList(head1, tail1);

	

	int mnm;
	cout << "Enter N" << endl;
	cin >> mnm;
	FindandDel(head, tail, mnm);
	//justAdd(head1, tail1, mnm);
	//PushFromRtoE(head,tail,mnm,head1,tail1);
	PrintList(head, tail);
	
	
	FindandDel69(head, tail, mnm, head1, tail1);
	PrintList(head1, tail1);





	system("pause");
	return;
}
