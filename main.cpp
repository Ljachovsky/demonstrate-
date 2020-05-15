#include <iostream>
using namespace std;

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

struct Stack {
	int info;
	Stack* next;
};

Stack* InStack(Stack* p, int  in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return   t;
}



void View(Stack* p) {
	Stack* t = p;
	if (p == NULL) {
		cout << " ���� ����!" << endl;
		return;
	}
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
}

void  Del_All(Stack** p) {
	Stack* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}
void Sort_p(Stack** p)
{
	Stack* t = NULL, * t1, * r;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}
void Sort_info(Stack* p) {
	Stack* t = NULL, * t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {

				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}
Stack* Del_5(Stack* p)
{
	Stack* t;
	t = p;
	while (t != NULL) {
		if (t->info % 10 == 5) {
			p->next = t->next;
			t = p->next;
		}
		else {
			p = t;
			t = t->next;
		}
	}
	delete t;
	if (p != NULL && p->info % 10 == 5)
	{
		Stack* n = p;
		p = p->next;
		delete n;
	}
	return p;
}

/*
Stack* Del_5(Stack* p)
{
	Stack* t;
	t = p;
	while (t != NULL) {
		if (t->info % 10 == 5) {
			p->next = t->next;
			t = p->next;
		}
		else {
			p = t;
			t = t->next;
		}
	}
	return p;
}
*/

int get_middle(Stack* s)
{
	while (s.)
}
int main()
{
	setlocale(LC_ALL, "rus");
	Stack* begin = NULL;
	int k, lo;
	cout << "������� ���������� ��������� ";
	cin >> k;
	cout << endl;
	cout << "������� �������� ";

	for (int i = 0; i < k; i++)
	{
		cin >> lo;
		begin = InStack(begin, lo);
	}
	Sort_p(&begin);
	Sort_info(begin);
	cout << endl;
	View(begin);
	begin = Del_5(begin);

	cout << endl;
	View(begin);
	Del_All(&begin);

	_CrtDumpMemoryLeaks();
	return 0;
}