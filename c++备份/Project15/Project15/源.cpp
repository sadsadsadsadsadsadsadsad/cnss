#include<iostream>

#include <stdlib.h>

#include <string.h>
using namespace std;
typedef  struct node

{
	char name[20];        /*姓名*/

	char address[40];    /*住址*/

	char phone[15];     /*电话*/

	char email[25];    /*邮箱*/

	struct node *next;

}add_list;

struct person

{
	char name[20];

	char address[50];

	char phone[20];

	char email[25];

};

FILE *fp;

add_list *tail, *head;    /*定义链表尾结点指针和头指针*/

						  /*从文件中读出数据生成通讯录链表，如果文件不存在，生成空链表*/

add_list *load(char filename[])

{

	add_list *year, *head;

	struct person t;

	head = (add_list *)malloc(sizeof(add_list));

	tail = head = NULL;

	if ((fp = fopen_s(NULL,filename, "rb")) == NULL)

		return head;

	else

		if (!feof(fp))

			if (fread(&t, sizeof(struct person), 1, fp) == 1)

			{

				year = (add_list *)malloc(sizeof(add_list));   /*连入链表第一个结点*/

				strcpy(year->name, t.name);

				strcpy(year->address, t.address);

				strcpy(year->phone, t.phone);

				strcpy(year->email, t.email);

				head = tail = year;

				year->next = NULL;

				/*连入链表其余结点*/

				while (!feof(fp))

				{

					if (fread(&t, sizeof(struct person), 1, fp) == 1)

					{

						year = (add_list *)malloc(sizeof(add_list));

						strcpy(year->name, t.name);

						strcpy(year->address, t.address);

						strcpy(year->phone, t.phone);

						strcpy(year->email, t.email);

						tail->next = year;

						year->next = NULL;

						tail = year;



					}



				}



			}

	fclose(fp);

	return head;

}

/******************************************************************************

******************************************************************************/

/*增加一条通讯录记录*/

void insert(add_list **head)

{
	add_list *year;

	year = (add_list *)malloc(sizeof(add_list));

	printf("\n请输入姓名:"); getchar(); gets_s(year->name);

	printf("\n请输入住址:"); gets_s(year->address);

	printf("\n请输入电话:"); scanf("%s", year->phone);

	printf("\n请输入邮箱:"); scanf("%s", year->email);

	if (*head == NULL)

	{
		*head = year;

		year->next = NULL;

		tail = year;

	}

	else

	{
		tail->next = year;

		year->next = NULL;

		tail = year;

	}

	getchar();

}

/**********************************************************************************************************************************************************/

/*将通讯录链表中的内容保存到指定文件中*/

void save(add_list *head, char filename[])

{
	add_list *p;

	struct person t;

	if ((fp = fopen_s(filename, "wb")) == NULL)

	{

		printf("error:cannot open file %s\n", filename);

		exit(1);

	}

	else

	{

		p = head;

		while (p != NULL)

		{

			strcpy(t.name, p->name);

			strcpy(t.address, p->address);

			strcpy(t.phone, p->phone);

			strcpy(t.email, p->email);

			fwrite(&t, sizeof(struct person), 1, fp);

			p = p->next;

		}

	}

	fclose(fp);

}

/******************************************************************************

******************************************************************************/

/*显示通讯录内容*/

void display(add_list *head)

{
	add_list *p;

	p = head;

	while (p != NULL)

	{

		printf("************************通讯成员*********************************\n");

		printf("姓名：%-20s\t住址：%-40s\n", p->name, p->address);

		printf("邮箱：%-25s\t电话：%-15s\n", p->email, p->phone);

		printf("*****************************************************************\n");

		p = p->next;

	}

}

/******************************************************************************

******************************************************************************/

/*按姓名查询通讯录记录*/

int search(add_list *head)

{

	add_list *p;

	char name[20];

	int flag = 0;

	printf("输入要查找人的姓名:\n ");

	getchar();

	gets_s(name);

	p = head;

	while (p != NULL)

	{

		if (strcmp(name, p->name) == 0)

		{

			printf("姓名：%s\t住址：%s\n", p->name, p->address);

			printf("邮箱：%s\t电话：%s\n", p->email, p->phone);

			flag = 1;

		}

		p = p->next;

	}

	return flag;

}

/******************************************************************************

******************************************************************************/

/*按姓名删除一条通讯录记录*/

int hh(add_list **head)

{
	add_list *p, *q, *t;

	char name[20], c;

	int flag = 0;

	printf("请输入要删除人的姓名:\n");

	getchar();

	gets_s(name);

	q = p = *head;

	while (p != NULL)

	{

		if (strcmp(name, p->name) == 0)

		{

			printf("姓名：%s\t住址：%s\n", p->name, p->address);

			printf("邮箱：%s\t电话：%s\n", p->email, p->phone);

			printf("真的要删除吗？（Y：是N：否）\n");

			c = getchar(); getchar();

			if (c == 'y' || c == 'Y')

			{

				if (p == *head)

					*head = p->next;

				else

					q->next = p->next;

				t = p;

				p = p->next;

				free(t);

				flag = 1;

				printf("已删除确认项！\n");

			}

			else

			{

				q = p;

				p = p->next;

			}

		}

		else

		{

			q = p;

			p = p->next;

		}

	}

	return flag;

}

/******************************************************************************

******************************************************************************/

/*判断S1、S2关系是否包含*/

void sub(char *s1, char *s2, int pos, int len)



{

	int i, l2;

	l2 = strlen(s2);

	if (pos<0 || pos>l2 || len<1 || len>l2 - pos)

	{

		s1[0] = '\0';

	}

	else

	{

		for (i = 0; i<len; i++)

			s1[i] = s2[i + pos];

		s1[len] = '\0';

	}

}

/******************************************************************************

******************************************************************************/

/*比较俩字符串是否相等*/

int compare(char *s1, char *s2) //返回值为1是子串，返回值为0不是

{

	char cs[40];

	int i, len1, len2, fan;

	fan = 0;

	len1 = strlen(s1);

	len2 = strlen(s2);

	if (len1>len2)return(0);

	if (len1 == len2)

	{

		if (strcmp(s1, s2) == 0)return(1);

		else return(0);

	}

	if (len1<len2)

	{

		for (i = 0; i <= len2 - len1; i++)

		{

			sub(cs, s2, i, len1);

			if (strcmp(s1, cs) == 0) { fan = 1; goto end; }

		}

	}

end: return fan;

}

/******************************************************************************

******************************************************************************/

/*修改通讯成员资料函数*/

void rework()

{

	add_list *p;

	int num;

	long weizhi;

	char del[20], g, que;

	p = head;

	if ((fp = fopen_s("filename", "rb")) == NULL)

	{

		printf("不能打开文件!");

	}

	else

	{

		printf("输入要修改旧记录的姓名:");

		scanf("%s", &del);

		num = 0;

		while (!feof(fp))

		{

		duqu: weizhi = ftell(fp);//返回当前指针的位置，用于设置修改位置

			fscanf(fp, "%s%s%s%s\n", p->name, p->address, p->phone, p->email);

			printf("%-20s%-10s%-25s%-40s\n", p->name, p->address, p->phone, p->email);

			if (compare(del, p->name) == 1)

			{

				fprintf(fp, "%-12s%-15s%-20s%-40s\n", p->name, p->address, p->phone, p->email);

				printf("是这条记录吗?(是按y键，不是按任意键!)\n");

				g = getchar();

				if (g == 'y' || g == 'Y')

				{

					printf("姓名:"); scanf("%s", &p->name);

					printf("住址:"); scanf("%s", &p->address);

					printf("电话:"); scanf("%s", &p->phone);

					printf("邮箱:"); scanf("%s", &p->email);

					printf("确实要修改为:");

					printf("%-20s%-10s%-25s%-40s\n", p->name, p->address, p->phone, p->email);

					getchar();

					printf("确定按Y,不是按任意键:");

					que = getchar();

					if (que == 'y' || que == 'Y')

					{

						fseek(fp, weizhi, SEEK_SET);

						fprintf(fp, "%s--%s--%s--%\n", p->name, p->address, p->phone, p->email);

						printf("修改成功!");

					}

					goto over;

				}

				else goto duqu;

				num++;

			}

		}

		if (num == 0)printf("查找完毕,没有您想修改的记录!");

	}

over:fclose(fp);

	getchar(); getchar();

}

/******************************************************************************

******************************************************************************/

/*主函数*/

void main(void)

{
	char filename[20];

	char c;

	int t;

	printf("请输入通讯录文件名称(有效路径)\n");

	scanf("%s", filename);

	getchar();

	head = load(filename);

	if ((fp = fopen_s("filename", "ab+")) == NULL)

		printf("不能打开文件!\n");

	else

	{

		printf("=============================================\n");

		printf("===           欢迎使用我的通讯录          ===\n");

		printf("===  制作：自动化0702-曹冬星07060150207  ===\n");

		printf("=============================================\n");

		printf("===           1 插入通讯成员              ===\n");

		printf("===           2 删除通讯成员              ===\n");

		printf("===           3 查询通讯成员              ===\n");

		printf("===           4 保存通讯文件              ===\n");

		printf("===           5 显示通讯成员              ===\n");

		printf("===           6 修改成员资料              ===\n");

		printf("===           0 退出本次操作              ===\n");

		printf("=============================================\n");

	jiedian:

		printf("请输入您选择的操作:\n");

		c = getchar();

		switch (c)

		{

		case '1':   insert(&head);

			printf("请尽快保存!\n"); getchar(); goto jiedian;     break;

		case '2':   t = hh(&head);

			if (!t)

				printf("查无此人\n"); goto jiedian;     break;

		case '3':   t = search(head);

			if (!t)

				printf("查无此人\n"); getchar(); goto jiedian;     break;

		case '4':   save(head, filename);

			printf("保存成功!\n"); getchar(); goto jiedian;    break;

		case '5':   display(head);            getchar(); goto jiedian;    break;

		case '6':   rework();                           goto jiedian;    break;

		case '0':   exit(0);

		default:  printf("输入指令无效!按任意键继续!"); getchar(); goto jiedian;

		}

	}

}

