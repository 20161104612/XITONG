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
#define	MAXSIZE  100   /*此处的宏定义常量表示线性表可能达到的最大长度*/

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
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
	int       last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为0*/
}SeqList;

int menu()
{
	int MenuItem;
	cout << "\n";
	cout << "          |***********    评分系统    ***********|            \n";
	cout << "          | ------------------------------------ |            \n";
	cout << "          |               菜单项                 |            \n";
	cout << "          | ------------------------------------ |            \n";
	cout << "          |	     1 --- 添加选手数据.         |            \n";
	cout << "          |	       (包含计算平均分）.        |            \n";
	cout << "          |	     2 --- 显示选手数据.         |            \n";
	cout << "          | 	     3 --- 修改选手数据.         |            \n";
	cout << "          |	     4 --- 对学生平均分排序.     |            \n";
	cout << "          |--------------------------------------|            \n";
	cout << "          |	     5 --- 读取原有选手数据. 	 |            \n";
	cout << "          |	     6 --- 保存选手数据到文件. 	 |            \n";
	cout << "          |	     7 --- 读取并显示评委. 	 |            \n";
	cout << "          |	     8 --- 退出系统.             |            \n";
	cout << "\n";
	cout << "\n	  请输入选项（1－9）：";
	cin >> MenuItem;
	return MenuItem;
}

int Insert(SeqList *L)
{
	int p, s, j, n;
	int i = 0;
	double sum = 0;
	double max = 0;
	double min = 10;

	char s1[] = "男";
	char s2[] = "女";

	char p1[] = "1.歌舞";
	char p2[] = "2.曲艺";
	char p3[] = "3.小品";

	if (L->last == MAXSIZE)
	{
		cout << "表满";
		return FALSE;
	}

	else
	{
		cout << "\n请输入参赛选手序号：";
		cin >> L->elem[L->last].num;
		cout << "\n请输入参赛选手姓名：";
		cin >> L->elem[L->last].name;
		cout << "\n请输入参赛选手性别：(1.男|2.女) ";
		cout << "\n(请输入数字!)   ";
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
		cout << "\n请输入学生的电话: ";
		cin >> L->elem[L->last].tel;
		cout << "\n请输入学生的班级: ";
		cin >> L->elem[L->last].clas;
		cout << "\n请输入参赛选手的节目名称: ";
		cin >> L->elem[L->last].program;
		cout << "\n请输入参赛选手的节目类型:(1.歌舞|2.曲艺|3.小品) ";
		cout << "\n(请输入数字!)   ";
		cin >> p;
		switch (p)
		{
		case 1:
			strcpy_s(L->elem[L->last].program_cls, p1);
			break;
		case 2:
			strcpy_s(L->elem[L->last].program_cls, p2);
			break;
		case 3:
			strcpy_s(L->elem[L->last].program_cls, p3);
			break;
		}
		cout << "\n>>>>>>>>>>>已完成一条选手信息的录入！";

		cout << "\n将要开始计算平均分\n";
		system("pause");

		cout << "\n请输入评委个数（个数至少为3）: ";
		cin >> n;

		for (j = 0;j < n;j++)
		{
			cout << "\n第" << j + 1 << "位评委给出的得分是: ";
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
		cout << "\n该选手分数总和为: " << sum << endl;
		cout << "去掉的最高分为: " << max << endl;
		cout << "去掉的最低分为; " << min << endl;
		cout << "该选手最终得分为: " << avg << endl;
		cout << "\n";
	}
	L->last++;
	return TRUE;
}

void display(SeqList *L)
{
	int i = 0;
	if (L->last == 0)
	{
		cout << "\n     athlete.csv表为空！";
	}
	else
	{
		cout << "\n   | 序号 | 姓名 | 性别 |      电话      | 班级 |    节目名称   | 节目类别 |-----| 总分 | 最后得分 |\n";
		cout << "\n";
		for (i = 0;i < L->last;i++)
		{
			cout << "   " << setiosflags(ios::left) << "|" << setw(6) << L->elem[i].num << "|" << setw(6) << L->elem[i].name << "|" << setw(6) << L->elem[i].sex << "|";
			cout << setiosflags(ios::left) << setw(16) << L->elem[i].tel << "|" << setw(6) << L->elem[i].clas << "|" << setw(15) << L->elem[i].program << "|" << setw(10) << L->elem[i].program_cls << "|";
			cout << "-----" << setiosflags(ios::left) << "|" << setw(6) << L->elem[i].sum << "|" << setw(10) << L->elem[i].avg << "|" << "\n";
		}
		cout << "\n";
	}
}

void update(SeqList *L)
{
	char Num[15];
	int l = 1;
	cout << "          请输入要查找的学号:";
	cin >> Num;
	int i = 0;        //i为扫描计数器，初值为0，即从第一个元素开始比较
	while ((i<L->last) && (strcmp(L->elem[i].num, Num)))	//顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到
		i++;
	if (i<L->last)
	{
		char x;
		cout << "\n          如继续修改请输入(Y):";
		cout << "\n          如完成修改请输入(N):";
		cin >> x;
		if (x == 'N' || x == 'n')
		{
			l = 0;
		}
		else
		{
			int s,n;
			double max, min;
			char s1[] = "男";
			char s2[] = "女";


			cout << "\n          请输入新的选手序号（原来是" << L->elem[i].num << "): ";
			cin >> L->elem[i].num;
			cout << "\n          请输入新的选手姓名 (原来是" << L->elem[i].name << "): ";
			cin >> L->elem[i].name;
			cout << "\n          请输入新的选手性别(1.男|2.女) (原来是" << L->elem[i].sex << "): ";
			cin >> s;
			switch (s)
			{
			case 1:
				strcpy_s(L->elem[i].sex, s1);
				break;
			case 2:
				strcpy_s(L->elem[i].sex, s2);
				break;
			}
			cout << "\n          请输入新的选手电话 (原来是" << L->elem[i].tel << "): ";
			cin >> L->elem[i].tel;
			cout << "\n          请输入新的选手班级 (原来是" << L->elem[i].clas << "): ";
			cin >> L->elem[i].clas;
			cout << "\n          请输入新的选手总分 (原来是" << L->elem[i].sum << "): ";
			cin >> L->elem[i].sum;

			cout << "\n          请输入最高分:";
			cin >> max;
			cout << "\n          请输入最低分:";
			cin >> min;
			cout << "\n          请输入裁判个数:";
			cin >> n;

			L->elem[i].avg = (L->elem[i].sum - max - min) / (n / 2);
			cout << "\n          平均分为:" << L->elem[i].avg;

			cout << "\n          >>>>>>>>>>>>>>>>>>>提示:该项选手基本信息已经成功修改!\n";

		}
	}
	else
	{
		printf("\n          在此学生表中没有该信息!,无法修改\n");
	}
}

void sort(SeqList *L)
{
	ElemType s;
	int i, j;
	for (j = 0;j < L->last;j++)
	{
		for (i = 0;i<L->last - j - 1;i++)
		{
			if (L->elem[i].avg<L->elem[i + 1].avg)
			{
				s = L->elem[i];
				L->elem[i] = L->elem[i + 1];
				L->elem[i + 1] = s;
			}
		}
	}
	cout << "\n   | 序号 | 姓名 | 性别 |      电话      | 班级 |    节目名称   | 节目类别 |-----| 总分 | 最后得分 |\n";
	cout << "\n";
	for (i = 0; i<L->last; i++)
	{
		cout << "   " << setiosflags(ios::left) << "|" << setw(6) << L->elem[i].num << "|" << setw(6) << L->elem[i].name << "|" << setw(6) << L->elem[i].sex << "|";
		cout << setiosflags(ios::left) << setw(16) << L->elem[i].tel << "|" << setw(6) << L->elem[i].clas << "|" << setw(15) << L->elem[i].program << "|" << setw(10) << L->elem[i].program_cls << "|";
		cout << "-----" << setiosflags(ios::left) << "|" << setw(6) << L->elem[i].sum << "|" << setw(10) << L->elem[i].avg << "|" << "\n";
	}
	cout << "\n";
}

string Trim1(string& str)
{
	//str.find_first_not_of(" \t\t\t\t\t\t\t\t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
	str.erase(0, str.find_first_not_of(" \t\t\t\t\t\t\t\t\r\n"));
	str.erase(str.find_last_not_of(" \t\t\t\t\t\t\t\t\r\n") + 1);
	return str;
}

int load1(SeqList *L)
{
	ifstream fin("C:\\Users\\Li\\Desktop\\athlete.csv"); //打开文件流操作
	string line;
	while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
	{
		istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
		vector<string> fields; //声明一个字符串向量
		string field;
		while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
		{
			fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
		}
		string num = Trim1(fields[0]); //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
		string name = Trim1(fields[1]); //清除掉向量fields中第二个元素的无效字符，并赋值给变量age
		string sex = Trim1(fields[2]); //清除掉向量fields中第三个元素的无效字符，并赋值给变量birthday
		string tel = Trim1(fields[3]);
		string clas = Trim1(fields[4]);
		string program = Trim1(fields[5]);
		string program_cls = Trim1(fields[6]);
		string sum = Trim1(fields[7]);
		string avg = Trim1(fields[8]);

		cout << "\n" << "          " << num << "\t" << name << "\t" << sex << "\t" << tel << "\t" << clas << "\t" << program << "\t" << program_cls << "\t" << sum << "\t" << avg << endl;
	}
	return EXIT_SUCCESS;
}

string Trim2(string& str)
{
	//str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
	str.erase(0, str.find_first_not_of(" \t\t\r\n"));
	str.erase(str.find_last_not_of(" \t\t\r\n") + 1);
	return str;
}

int load2(SeqList *L)
{
	int recordNum = 0;
	ifstream fin("C:\\Users\\Li\\Desktop\\工作簿2.csv"); //打开文件流操作
	string line;
	while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
	{
		istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
		vector<string> fields; //声明一个字符串向量
		string field;
		while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
		{
			fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
		}
		string num = Trim2(fields[0]); //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
		string name = Trim2(fields[1]); //清除掉向量fields中第二个元素的无效字符，并赋值给变量age
		string sex = Trim2(fields[2]); //清除掉向量fields中第三个元素的无效字符，并赋值给变量birthday
		string tel = Trim2(fields[3]);

		recordNum++;
		cout << "\n" << "          " << num << "\t" << name << "\t" << sex << "\t" << tel << endl;
	}
	cout << "          工作簿2.csv文件里共有" << recordNum - 1 << "条裁判记录:" << endl;
	return EXIT_SUCCESS;
}

void save(SeqList *L)
{
	int i;
	fstream file("C:\\Users\\Li\\Desktop\\athlete.csv", ios::out | ios::trunc);

	if (!file.fail())
	{
		cout << "正在写入。。。" << endl;
		file << "序号" << ',' << "姓名" << ',' << "性别" << ',' << "电话" << ',' << "班级" << ',' << "节目名称" << ',' << "节目类别" << ',' << "总分" << ',' << "最后得分" << "\n";
		for (i = 0;i < L->last;i++)
		{
			file << L->elem[i].num << ',' << L->elem[i].name << ',' << L->elem[i].sex << ',' << L->elem[i].tel << ',' << L->elem[i].clas << ',' << L->elem[i].program << ',';
			file << L->elem[i].program_cls << ',' << L->elem[i].sum << ',' << L->elem[i].avg << "\n";
		}
		system("pause");
		cout << "已成功写入，可在athlete.csv中查看";
		cout << "\n";
	}
	else
	{
		cout << "无法打开此文件。" << endl;
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
		case 3:
			system("cls");
			update(&l);
			system("pause");
			save(&l);
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
			cout << "正在读取！";
			system("pause");
			system("cls");
			load1(&l);
			system("pause");
			system("cls");
			break;
		case 6:
			save(&l);
			break;
		case 7:
			cout << "正在读取！";
			system("pause");
			system("cls");
			load2(&l);
			system("pause");
			system("cls");
			break;
		case 8:
			cout << "\n";
			cout << "        感谢您使用评分系统！\n";
			cout << "\n";
			cout << "                    再见            ";
			system("pause");
			return 0;
			break;
		}
	}
}