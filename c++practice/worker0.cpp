#define CRT_SECURE_NO_WARNINGS
#include "worker0.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Set()
{
	cout << "��� �̸��� �Է��Ͻʽÿ�: ";
	getline(cin, fullname);
	cout << "��� ��ȣ�� �Է��Ͻʽÿ�: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}
void Worker::Show() const
{
	cout << "��� �̸�: " << fullname << "\n";
	cout << "��� ��ȣ: " << id << "\n";
}
void Waiter::Set()
{
	Worker::Set();
	cout << "������ ����� �Է��Ͻʽÿ�: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Show() const
{
	cout << "����: ������\n";
	Worker::Show();
	cout << "������ ���: " << panache << "\n";
}

 char * Singer::pv[] = { "other", "alto", "contralto",
"soprano", "bass", "baritone", "tenor" };
void Singer::Set()
{
	Worker::Set();
	cout << "������ ��Ҹ� ���� ��ȣ�� �Է��Ͻʽÿ�::\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "0���� ũ�ų� ���� " << Vtypes << "���� ���� ���� �Է��Ͻʽÿ�" << endl;
	while (cin.get() != '\n')
		continue;
}

void Singer::Show() const
{
	cout << "����: ����\n";
	Worker::Show();
	cout << "��Ҹ� ����: " << pv[voice] << endl;
}