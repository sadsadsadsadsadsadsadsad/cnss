#include<iostream>
using namespace std;
#include<stdlib.h>
class whole
{
public:
	char name[20];
	int num;
	char att[20];
	void find();
	void motify();
	void add();
	void del();
};
class company : public whole
{
	char comname[20];
	char partname[20];
	char state[20];
	char salarynum[20];
};

