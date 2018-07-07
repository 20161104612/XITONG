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
	char num[10];        /*序号*/
	char name[20];       /*姓名*/
	char sex[10];         /*性别*/
	int  cls;            /*班级*/
	char tel[25];        /*电话*/
	char program[25];    /*表演节目*/
	char program_cls[15]; /*节目类别*/

	double score[10];
	double avg;
};
typedef struct athlete ElemType;

struct SeqList
{
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
	int       last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
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
	cout << "|***************裁判评分系统***************|\n";
	cout << "|              1-添加选手信息              |\n";
	cout << "|           (包含裁判打分及算平均）        |\n";
	cout << "|              2-显示选手信息              |\n";
	cout << "|              3-对表演分数进行排序        |\n";
	cout << "|              6-对选手信息进行查找        |\n";
	cout << "|              7-对选手信息进行修改        |\n";
	cout << "|              8-对选手信息进行删除        |\n";
	cout << "|              9-对选手信息进行保存        |\n";
	cout << "|              10-退出系统                 |\n";


	cout << "请输入选项（0-10）：";
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
		printf("表满");
		return FALSE;
	}
	else
	{
		/*cout << "请输入节目的序号：";
		cin >> id;
		while (j < L->last&&strcmp(L->elem[j].num, id))
		j++;
		if(j<L->last)
		{
			cout << "该序号已存在！,请重新输入";
		}
		else
		*/
			cout << "\n请输入节目表演者姓名：";
			cin >> L->elem[L->last].name;
			cout << "\n请输入节目表演者性别(男/女)：";
			cin >> L->elem[L->last].sex;
			cout << "\n请输入表演者所在班级：";
			cin >> L->elem[L->last].cls;
			cout << "\n请输入表演者的电话号码:";
			cin >> L->elem[L->last].tel;
			cout << "\n请输入表演者所表演的节目名称：";
			cin >> L->elem[L->last].program;
			cout << "\n请输入表演者所表演的节目类别：";
			cin >> L->elem[L->last].program_cls;

			cout << "\n>>>>>>>>>>>>>>>>>>>提示:已完成一条选手信息的录入！";


	}
			

		/*
			
			
			

			cout << "\n";
			cout << "\n将要开始计算平均分\n";
			system("pause");

			cout << "请输入有几位评委";
			cin >> n;
			for (i = 1;i <= n;i++)
			{
				cout << "\n请输入第" << i << "位评委的评分:";
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
			cout << "该选手最终得分为:" << sum << endl;
			cout << "去掉的最高分为：" << max << endl;
			cout << "去掉的最低分为：" << min << endl;
			cout << "最后选手的平均分为：" << s->avg << endl;
			
			s->next = NULL;
			rear->next = s;
			rear = s;

			cout << "需要继续录入吗（y/n）";
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
		cout<<"\n           >>>>>>>>>>>>>>>>>>>提示:没有资料可以显示！\n";
		return;
	}

	else
	{
			cout << "|  序号  |  姓名  |  性别  |  班级  |  电话号码  |  节目名称  |  节目类别  |  平均分  |\n";
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
		cout<<"\n           >>>>>>>>>>>>>>>>>>>提示:没有资料可以显示！\n";
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
		cout << "\n没有裁判信息！\n";
	}
	else
	{
		cout<<"|  姓名  |  性别  |  电话号码  |\n";
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
			cout << "欢迎再次使用本系统\n";
			cout << "再见";
			return 0;
		default:
			break;
		}
	}
}