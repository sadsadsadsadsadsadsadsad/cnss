#include<iostream>

#include <stdlib.h>

#include <string.h>
using namespace std;
typedef  struct node

{
	char name[20];        /*����*/

	char address[40];    /*סַ*/

	char phone[15];     /*�绰*/

	char email[25];    /*����*/

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

add_list *tail, *head;    /*��������β���ָ���ͷָ��*/

						  /*���ļ��ж�����������ͨѶ¼��������ļ������ڣ����ɿ�����*/

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

				year = (add_list *)malloc(sizeof(add_list));   /*���������һ�����*/

				strcpy(year->name, t.name);

				strcpy(year->address, t.address);

				strcpy(year->phone, t.phone);

				strcpy(year->email, t.email);

				head = tail = year;

				year->next = NULL;

				/*��������������*/

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

/*����һ��ͨѶ¼��¼*/

void insert(add_list **head)

{
	add_list *year;

	year = (add_list *)malloc(sizeof(add_list));

	printf("\n����������:"); getchar(); gets_s(year->name);

	printf("\n������סַ:"); gets_s(year->address);

	printf("\n������绰:"); scanf("%s", year->phone);

	printf("\n����������:"); scanf("%s", year->email);

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

/*��ͨѶ¼�����е����ݱ��浽ָ���ļ���*/

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

/*��ʾͨѶ¼����*/

void display(add_list *head)

{
	add_list *p;

	p = head;

	while (p != NULL)

	{

		printf("************************ͨѶ��Ա*********************************\n");

		printf("������%-20s\tסַ��%-40s\n", p->name, p->address);

		printf("���䣺%-25s\t�绰��%-15s\n", p->email, p->phone);

		printf("*****************************************************************\n");

		p = p->next;

	}

}

/******************************************************************************

******************************************************************************/

/*��������ѯͨѶ¼��¼*/

int search(add_list *head)

{

	add_list *p;

	char name[20];

	int flag = 0;

	printf("����Ҫ�����˵�����:\n ");

	getchar();

	gets_s(name);

	p = head;

	while (p != NULL)

	{

		if (strcmp(name, p->name) == 0)

		{

			printf("������%s\tסַ��%s\n", p->name, p->address);

			printf("���䣺%s\t�绰��%s\n", p->email, p->phone);

			flag = 1;

		}

		p = p->next;

	}

	return flag;

}

/******************************************************************************

******************************************************************************/

/*������ɾ��һ��ͨѶ¼��¼*/

int hh(add_list **head)

{
	add_list *p, *q, *t;

	char name[20], c;

	int flag = 0;

	printf("������Ҫɾ���˵�����:\n");

	getchar();

	gets_s(name);

	q = p = *head;

	while (p != NULL)

	{

		if (strcmp(name, p->name) == 0)

		{

			printf("������%s\tסַ��%s\n", p->name, p->address);

			printf("���䣺%s\t�绰��%s\n", p->email, p->phone);

			printf("���Ҫɾ���𣿣�Y����N����\n");

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

				printf("��ɾ��ȷ���\n");

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

/*�ж�S1��S2��ϵ�Ƿ����*/

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

/*�Ƚ����ַ����Ƿ����*/

int compare(char *s1, char *s2) //����ֵΪ1���Ӵ�������ֵΪ0����

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

/*�޸�ͨѶ��Ա���Ϻ���*/

void rework()

{

	add_list *p;

	int num;

	long weizhi;

	char del[20], g, que;

	p = head;

	if ((fp = fopen_s("filename", "rb")) == NULL)

	{

		printf("���ܴ��ļ�!");

	}

	else

	{

		printf("����Ҫ�޸ľɼ�¼������:");

		scanf("%s", &del);

		num = 0;

		while (!feof(fp))

		{

		duqu: weizhi = ftell(fp);//���ص�ǰָ���λ�ã����������޸�λ��

			fscanf(fp, "%s%s%s%s\n", p->name, p->address, p->phone, p->email);

			printf("%-20s%-10s%-25s%-40s\n", p->name, p->address, p->phone, p->email);

			if (compare(del, p->name) == 1)

			{

				fprintf(fp, "%-12s%-15s%-20s%-40s\n", p->name, p->address, p->phone, p->email);

				printf("��������¼��?(�ǰ�y�������ǰ������!)\n");

				g = getchar();

				if (g == 'y' || g == 'Y')

				{

					printf("����:"); scanf("%s", &p->name);

					printf("סַ:"); scanf("%s", &p->address);

					printf("�绰:"); scanf("%s", &p->phone);

					printf("����:"); scanf("%s", &p->email);

					printf("ȷʵҪ�޸�Ϊ:");

					printf("%-20s%-10s%-25s%-40s\n", p->name, p->address, p->phone, p->email);

					getchar();

					printf("ȷ����Y,���ǰ������:");

					que = getchar();

					if (que == 'y' || que == 'Y')

					{

						fseek(fp, weizhi, SEEK_SET);

						fprintf(fp, "%s--%s--%s--%\n", p->name, p->address, p->phone, p->email);

						printf("�޸ĳɹ�!");

					}

					goto over;

				}

				else goto duqu;

				num++;

			}

		}

		if (num == 0)printf("�������,û�������޸ĵļ�¼!");

	}

over:fclose(fp);

	getchar(); getchar();

}

/******************************************************************************

******************************************************************************/

/*������*/

void main(void)

{
	char filename[20];

	char c;

	int t;

	printf("������ͨѶ¼�ļ�����(��Ч·��)\n");

	scanf("%s", filename);

	getchar();

	head = load(filename);

	if ((fp = fopen_s("filename", "ab+")) == NULL)

		printf("���ܴ��ļ�!\n");

	else

	{

		printf("=============================================\n");

		printf("===           ��ӭʹ���ҵ�ͨѶ¼          ===\n");

		printf("===  �������Զ���0702-�ܶ���07060150207  ===\n");

		printf("=============================================\n");

		printf("===           1 ����ͨѶ��Ա              ===\n");

		printf("===           2 ɾ��ͨѶ��Ա              ===\n");

		printf("===           3 ��ѯͨѶ��Ա              ===\n");

		printf("===           4 ����ͨѶ�ļ�              ===\n");

		printf("===           5 ��ʾͨѶ��Ա              ===\n");

		printf("===           6 �޸ĳ�Ա����              ===\n");

		printf("===           0 �˳����β���              ===\n");

		printf("=============================================\n");

	jiedian:

		printf("��������ѡ��Ĳ���:\n");

		c = getchar();

		switch (c)

		{

		case '1':   insert(&head);

			printf("�뾡�챣��!\n"); getchar(); goto jiedian;     break;

		case '2':   t = hh(&head);

			if (!t)

				printf("���޴���\n"); goto jiedian;     break;

		case '3':   t = search(head);

			if (!t)

				printf("���޴���\n"); getchar(); goto jiedian;     break;

		case '4':   save(head, filename);

			printf("����ɹ�!\n"); getchar(); goto jiedian;    break;

		case '5':   display(head);            getchar(); goto jiedian;    break;

		case '6':   rework();                           goto jiedian;    break;

		case '0':   exit(0);

		default:  printf("����ָ����Ч!�����������!"); getchar(); goto jiedian;

		}

	}

}

