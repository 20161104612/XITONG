#include<iostream>
#include<string.h>
#include<fstream>
#include<sstream>
#include<strstream>
#include<Windows.h>
#include <stdlib.h>
#include<iomanip>


#include <vector>

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0
#define	MAXSIZE  100   /*�˴��ĺ궨�峣����ʾ���Ա���ܴﵽ����󳤶�*/

using namespace std;

struct athelet
{
	char num[15];
	char name[20];
	char sex[15];
	char tel[30];
	char clas[5];
	char program[30];
	char program_cls[15];

	double score[5];
	double sum;
	double avg;
	double max;
};
typedef struct athelet ElemType;

typedef  struct
{
	ElemType  elem[MAXSIZE];  /*���Ա�ռ�õ�����ռ�*/
	int       last;    /*��¼���Ա������һ��Ԫ��������elem[ ]�е�λ�ã��±�ֵ�����ձ���Ϊ0*/
}SeqList;

int menu()
{
	int MenuItem;
	cout <<"\n";
	cout <<"          |***********    ����ϵͳ    ***********|            \n";
	cout <<"          | ------------------------------------ |            \n";
	cout <<"          |               �˵���                 |            \n";
	cout <<"          | ------------------------------------ |            \n";
	cout <<"          |	     1 --- ���ѡ������.         |            \n";
	cout << "          |	       (��������ƽ���֣�.        |            \n";
	cout <<"          |	     2 --- ��ʾѡ������.         |            \n";
	cout <<"          |	     4 --- ��ѧ��ƽ��������.     |            \n";
	cout <<"          |--------------------------------------|            \n";
	cout <<"          |	     5 --- ��ȡԭ��ѡ������. 	 |            \n";
	cout <<"          |	     6 --- ����ѡ�����ݵ��ļ�. 	 |            \n";
	cout <<"          |	     7 --- �˳�ϵͳ.             |            \n";
	cout << "\n";
	cout << "\n	  ������ѡ�1��9����";
	cin >> MenuItem;
	return MenuItem;
}

int Insert(SeqList *L)
{
	int p,s,j,n;
	int i = 0;
	double sum = 0;
	double max = 0;
	double min = 10;

	char s1[] = "��";
	char s2[] = "Ů";

	char p1[] = "1.����";
	char p2[] = "2.����";
	char p3[] = "3.СƷ";

	if (L->last == MAXSIZE) 
	{
		cout << "����";
		return FALSE;
	}

	else
	{
		cout << "\n���������ѡ����ţ�";
		cin >> L->elem[L->last].num;
		cout << "\n���������ѡ��������";
		cin >> L->elem[L->last].name;
		cout << "\n���������ѡ���Ա�(1.��|2.Ů) ";
		cout << "\n(����������!)   ";
		cin >> s;
		switch (s)
		{
			case 1:
				strcpy_s(L->elem[L->last].sex, s1);
				break;
			case 2:
				strcpy_s(L->elem[L->last].sex, s2);
				break;
		}
		cout << "\n������ѧ���ĵ绰: ";
		cin >> L->elem[L->last].tel;
		cout << "\n������ѧ���İ༶: ";
		cin >> L->elem[L->last].clas;
		cout << "\n���������ѡ�ֵĽ�Ŀ����: ";
		cin >> L->elem[L->last].program;
		cout << "\n���������ѡ�ֵĽ�Ŀ����:(1.����|2.����|3.СƷ) ";
		cout << "\n(����������!)   ";
		cin >> p;
		switch (p)
		{
		case 1:
			strcpy_s(L->elem[L->last].program_cls ,p1);
			break;
		case 2:
			strcpy_s(L->elem[L->last].program_cls, p2);
			break;
		case 3:
			strcpy_s(L->elem[L->last].program_cls, p3);
			break;
		}
		cout << "\n>>>>>>>>>>>�����һ��ѡ����Ϣ��¼�룡";

		cout << "\n��Ҫ��ʼ����ƽ����\n";
		system("pause");

		cout << "\n��������ί��������������Ϊ3��: ";
		cin >> n;

		for (j = 0;j < n;j++)
		{
			cout << "\n��" << j + 1 << "λ��ί�����ĵ÷���: ";
			cin >> L->elem[L->last].score[i];
			sum = sum + L->elem[L->last].score[i];

			if (L->elem[L->last].score[i] > max)
			{
				max = L->elem[L->last].score[i];
			}
			if (L->elem[L->last].score[i] < min)
			{
				min = L->elem[L->last].score[i];
			}
			i++;
			
		}

		double avg = (sum - max - min) / (n - 2);
		L->elem[L->last].sum = sum;
		L->elem[L->last].avg = avg;
		cout << "\n��ѡ�ַ����ܺ�Ϊ: " << sum <<endl;
		cout << "ȥ������߷�Ϊ: " << max << endl;
		cout << "ȥ������ͷ�Ϊ; " << min << endl;
		cout << "��ѡ�����յ÷�Ϊ: " << avg << endl;
		cout << "\n";
	}
	L->last++;
	return TRUE;
}

void display(SeqList *L)
{
	int i = 0;
	if (L->last==0)
	{
		cout << "\n     athlete.csv��Ϊ�գ�";
	}
	else
	{
		cout<<"\n   | ��� | ���� | �Ա� |      �绰      | �༶ |    ��Ŀ����   | ��Ŀ��� |-----| �ܷ� | ���÷� |\n";
		cout << "\n";
		for (i = 0;i < L->last;i++)
		{
			cout <<"   "<< setiosflags(ios::left) << "|" << setw(6) << L->elem[i].num << "|" << setw(6) << L->elem[i].name << "|" << setw(6) << L->elem[i].sex << "|";
			cout << setiosflags(ios::left) << setw(16) << L->elem[i].tel << "|" << setw(6) << L->elem[i].clas << "|" << setw(15) << L->elem[i].program << "|" << setw(10) << L->elem[i].program_cls << "|";
			cout << "-----" << setiosflags(ios::left) << "|" << setw(6) << L->elem[i].sum << "|" << setw(10) << L->elem[i].avg << "|" << "\n";
		}
		cout<<"\n";
	}
}

void sort(SeqList *L)
{
	ElemType s;
	int i, j;
	for (j = 0;j < L->last;j++)
	{
		for (i = 0;i<L->last - j -1;i++)
		{
			if (L->elem[i].avg<L->elem[i + 1].avg)
			{
				s = L->elem[i];
				L->elem[i] = L->elem[i + 1];
				L->elem[i + 1] = s;
			}
		}
	}
	cout << "\n   | ��� | ���� | �Ա� |      �绰      | �༶ |    ��Ŀ����   | ��Ŀ��� |-----| �ܷ� | ���÷� |\n";
	cout << "\n";
	for (i = 0; i<L->last; i++)
	{
		cout << "   " << setiosflags(ios::left) << "|" << setw(6) << L->elem[i].num << "|" << setw(6) << L->elem[i].name << "|" << setw(6) << L->elem[i].sex << "|";
		cout << setiosflags(ios::left) << setw(16) << L->elem[i].tel << "|" << setw(6) << L->elem[i].clas << "|" << setw(15) << L->elem[i].program << "|" << setw(10) << L->elem[i].program_cls << "|";
		cout << "-----" << setiosflags(ios::left) << "|" << setw(6) << L->elem[i].sum << "|" << setw(10) << L->elem[i].avg << "|" << "\n";
	}
	cout << "\n";
}

string Trim(string& str)
{
	//str.find_first_not_of(" \t\r\n"),���ַ���str�д�����0��ʼ�������״β�ƥ��"\t\r\n"��λ��
	str.erase(0, str.find_first_not_of(" \t\t\t\t\t\t\t\t\n"));
	str.erase(str.find_last_not_of(" \t\t\t\t\t\t\t\t\n") + 1);
	return str;
}

int loadathy(SeqList *L)
{
	int i;
	int recordNum = 0;
	ifstream fin("C:\\Users\\Li\\Desktop\\������1.csv"); //���ļ�������
	string line;
	while (getline(fin, line))   //���ж�ȡ�����з���\n�����֣������ļ�β��־eof��ֹ��ȡ
	{
		istringstream sin(line); //�������ַ���line���뵽�ַ�����istringstream��
		vector<string> fields; //����һ���ַ�������
		string field;
		while (getline(sin, field, ',')) //���ַ�����sin�е��ַ����뵽field�ַ����У��Զ���Ϊ�ָ���
		{
			fields.push_back(field); //���ոն�ȡ���ַ�����ӵ�����fields��
		}
		string num = Trim(fields[0]); //���������fields�е�һ��Ԫ�ص���Ч�ַ�������ֵ������name
		string name = Trim(fields[1]); //���������fields�еڶ���Ԫ�ص���Ч�ַ�������ֵ������age
		string sex = Trim(fields[2]); //���������fields�е�����Ԫ�ص���Ч�ַ�������ֵ������birthday
		string tel = Trim(fields[3]);
		string clas = Trim(fields[4]);
		string program = Trim(fields[5]);
		string program_cls = Trim(fields[6]);
		recordNum++;
		cout << "\n" << "          " << num << "\t" << name << "\t" << sex << "\t" << tel << "\t" << clas << "\t" << program << "\t" << program_cls << endl;
	}
	cout << "          ������1.csv�ļ��ﹲ��" << recordNum - 1 << "��ѡ�ּ�¼:" << endl;
	cout << "          ���סѡ����Ϣ���ڲ˵������н������룡" << endl;
	return EXIT_SUCCESS;
}

void save(SeqList *L)
{
	int i;
	fstream file("C:\\Users\\Li\\Desktop\\athlete.csv",ios::out|ios::trunc);

	if (!file.fail())
	{
		cout << "����д�롣����" << endl;
		file << "���" << ',' << "����" << ',' << "�Ա�" << ',' << "�绰" << ',' << "�༶" << ',' << "��Ŀ����" << ',' << "��Ŀ���" << ',' << "�ܷ�" << ',' << "���÷�" << "\n";
		for (i = 0;i < L->last;i++)
		{
			file << L->elem[i].num << ',' << L->elem[i].name << ',' << L->elem[i].sex << ',' << L->elem[i].tel << ',' << L->elem[i].clas << ',' << L->elem[i].program << ',';
			file << L->elem[i].program_cls << ',' << L->elem[i].sum << ',' << L->elem[i].avg << "\n";
		}
		system("pause");
		cout << "�ѳɹ�д�룬����athlete.csv�в鿴";
		cout << "\n";
	}
	else
	{
		cout << "�޷��򿪴��ļ���" << endl;
	}
	file.close();
}

int main()
{
	int flag = 1;
	SeqList l;
	l.last = 0;
	while (1) {
		switch (menu())
		{
		case 1:
			system("cls");
			Insert(&l);
			system("pause");
			save(&l);
			system("cls");
			break;
		case 2:
			system("cls");
			display(&l);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			sort(&l);
			system("pause");
			save(&l);
			system("cls");
			break;
		case 5:
			cout << "���ڶ�ȡ��";
			system("pause");
			system("cls");
			loadathy(&l);
			display(&l);
			system("pause");
			system("cls");
			break;
		case 6:
			save(&l);
			break;
		case 7:
			cout<<"\n";
			cout<<"        ��л��ʹ������ϵͳ��\n";
			cout<<"\n";
			cout<<"                    �ټ�            ";
			system("pause");
			return 0;
			break;
		}
	}
}