#include<iostream>
#include<string>
#include<malloc.h>
#include<sstream>
#include<fstream>

#define MAXSIZE 100
#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0


using namespace std;

struct athlete
{
	char num[10];        /*���*/
	char name[20];       /*����*/
	char sex[10];         /*�Ա�*/
	int  cls;            /*�༶*/
	char tel[25];        /*�绰*/
	char program[25];    /*���ݽ�Ŀ*/
	char program_cls[15]; /*��Ŀ���*/

	double score[10];
	double avg;
};
typedef struct athlete ElemType;

struct SeqList
{
	ElemType  elem[MAXSIZE];  /*���Ա�ռ�õ�����ռ�*/
	int       last;    /*��¼���Ա������һ��Ԫ��������elem[ ]�е�λ�ã��±�ֵ�����ձ���Ϊ-1*/
};

struct rater
{
	char name[20];
	char sex[10];
	char tel[25];

	struct rater *next;
};

int menu()
{
	int menu_n;
	cout << "\n";
	cout << "|***************��������ϵͳ***************|\n";
	cout << "|              1-���ѡ����Ϣ              |\n";
	cout << "|           (�������д�ּ���ƽ����        |\n";
	cout << "|              2-��ʾѡ����Ϣ              |\n";
	cout << "|              3-�Ա��ݷ�����������        |\n";
	cout << "|              6-��ѡ����Ϣ���в���        |\n";
	cout << "|              7-��ѡ����Ϣ�����޸�        |\n";
	cout << "|              8-��ѡ����Ϣ����ɾ��        |\n";
	cout << "|              9-��ѡ����Ϣ���б���        |\n";
	cout << "|              10-�˳�ϵͳ                 |\n";


	cout << "������ѡ�0-10����";
	cin >> menu_n;
	return menu_n;
}

int input(SeqList *L)
{

	char cContinue;
	int i,n,j=0;
	int flag = 1;
	char id[15];
	double sum = 0;
	double max = 0;
	double min = 100;
	if (L->last == MAXSIZE) {
		printf("����");
		return FALSE;
	}
	else
	{
		/*cout << "�������Ŀ����ţ�";
		cin >> id;
		while (j < L->last&&strcmp(L->elem[j].num, id))
		j++;
		if(j<L->last)
		{
			cout << "������Ѵ��ڣ�,����������";
		}
		else
		*/
			cout << "\n�������Ŀ������������";
			cin >> L->elem[L->last].name;
			cout << "\n�������Ŀ�������Ա�(��/Ů)��";
			cin >> L->elem[L->last].sex;
			cout << "\n��������������ڰ༶��";
			cin >> L->elem[L->last].cls;
			cout << "\n����������ߵĵ绰����:";
			cin >> L->elem[L->last].tel;
			cout << "\n����������������ݵĽ�Ŀ���ƣ�";
			cin >> L->elem[L->last].program;
			cout << "\n����������������ݵĽ�Ŀ���";
			cin >> L->elem[L->last].program_cls;

			cout << "\n>>>>>>>>>>>>>>>>>>>��ʾ:�����һ��ѡ����Ϣ��¼�룡";


	}
			

		/*
			
			
			

			cout << "\n";
			cout << "\n��Ҫ��ʼ����ƽ����\n";
			system("pause");

			cout << "�������м�λ��ί";
			cin >> n;
			for (i = 1;i <= n;i++)
			{
				cout << "\n�������" << i << "λ��ί������:";
				cin >> s->score[i];
				sum = sum + s->score[i];
				if (max < s->score[i])
				{
					max = s->score[i];
				}
				if (min > s->score[i])
				{
					min = s->score[i];
				}
			}

			s->avg = (sum - max - min) / (n - 2);
			cout << "��ѡ�����յ÷�Ϊ:" << sum << endl;
			cout << "ȥ������߷�Ϊ��" << max << endl;
			cout << "ȥ������ͷ�Ϊ��" << min << endl;
			cout << "���ѡ�ֵ�ƽ����Ϊ��" << s->avg << endl;
			
			s->next = NULL;
			rear->next = s;
			rear = s;

			cout << "��Ҫ����¼����y/n��";
			cin >> cContinue;
			switch (cContinue)
			{
				case 'Y':
				case 'y':
					flag = 1;
					break;
				case 'N':
				case 'n':
					flag = 0;
					break;
			}
		}
	}*/
}

/*void displayath(athlete *ath)
{
	athlete *p;
	p = ath->next;

	if (!p)
	{
		cout<<"\n           >>>>>>>>>>>>>>>>>>>��ʾ:û�����Ͽ�����ʾ��\n";
		return;
	}

	else
	{
			cout << "|  ���  |  ����  |  �Ա�  |  �༶  |  �绰����  |  ��Ŀ����  |  ��Ŀ���  |  ƽ����  |\n";
			while (p != NULL)
			{
				cout << p->num << "|" << p->name << "|" << p->sex << "|";
				cout << p->cls << "|" << p->tel << "|" << p->program << "|" << p->program_cls << "|"<<p->avg << "|\n";
				p = p->next;
			}
	}
}

void sortbyavg(athlete *ath)
{
	athlete *p;
	p = ath->next;
	if (!p)
	{
		cout<<"\n           >>>>>>>>>>>>>>>>>>>��ʾ:û�����Ͽ�����ʾ��\n";
	}
	else
	{

	}
}



/*void displayrat(rater *rat)
{
	rater *q;
	q = rat->next;
	if (!q)
	{
		cout << "\nû�в�����Ϣ��\n";
	}
	else
	{
		cout<<"|  ����  |  �Ա�  |  �绰����  |\n";
		while (q != NULL)
		{
			cout<<q->name<<"|"<<q->sex<<"|"<<q->tel<<"|\n";
			q = q->next;
		}
	}
}*/



int main()
{
	SeqList l;
/*	athlete *ath= (athlete *)malloc(sizeof(athlete));
	rater *rat = (rater *)malloc(sizeof(rater));
	ath->next = NULL;*/
	while (1)
	{
		switch (menu())
		{
		case 1:
			input(&l);
			break;
		/*case 2:
			displayath(ath);
			break;
		case 3:
			sortbyavg(ath);
			break;
		/*case 4:
			countavg(ath);
			break;*/
		case 5:cout << "1";
			break;
		case 6:cout << "1";
			break;
		case 7:cout << "1";
			break;
		case 8:cout << "1";
			break;
		case 9:cout << "1";
			break;
		case 10:
			cout << "��ӭ�ٴ�ʹ�ñ�ϵͳ\n";
			cout << "�ټ�";
			return 0;
		default:
			break;
		}
	}
}