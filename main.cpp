#include <iostream>
using namespace std;


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
		cout << " Стек пуст!" << endl;
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



int get_midle(Stack* s)
{
	int count = 0;
	int summ = 0;
	while (s != NULL)
	{
		count++;
		summ += s->info;
		s = s->next;
	}

	return summ / count;
}

Stack* Del_elements(Stack* p, int midle)
{
	int count = 0;

	Stack* t;
	t = p;
	while (t != NULL) {
		if (t->info < midle) {
			count++;
			p->next = t->next;
			t = p->next;
		}
		else {
			p = t;
			t = t->next;
		}
	}
	delete t;
	if (p != NULL && p->info < midle)
		p = p->next;

	cout << "количество удаленных элементов: " << count << endl;
	return p;
}
int main()
{
	setlocale(LC_ALL, "rus");
	Stack* begin = NULL;
	int k, lo;
	cout << "Введите количество элементов ";
	cin >> k;
	cout << endl;
	cout << "Введите элементы ";

	for (int i = 0; i < k; i++)
	{
		cin >> lo;
		begin = InStack(begin, lo);
	}
	Sort_p(&begin);
	Sort_info(begin);
	cout << endl;
	//cout << get_middle(begin);
	//View(begin);
	begin = Del_elements(begin, get_midle(begin));

	cout << endl;
	View(begin);
	Del_All(&begin);

	return 0;
}
