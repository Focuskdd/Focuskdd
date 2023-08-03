//�����������Ҳ��Ҿ���;�����Χ�ľ���
#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include <queue>
using namespace std; 
struct Matrix
{
	string Sname;//��������
	int count;//����������
	int edge;//��·����
	int m[100][100]={0};//�����ά����
	string Pname[100]={"0"};//�������������
};
struct Scenic
{
	Matrix mat;
};

struct Lnode
{
	string data;
	struct Lnode* next= NULL;
};
void cin_scenic_info(Scenic*& p);
void print_graph(Scenic*& p);

void min_distance(Scenic*& p);
void guide_line(Scenic*& p);
void change_graph(Scenic*& p);
void creat_v(Scenic*& p);
void delete_v(Scenic*& p);
void change_v(Scenic*& p);
void creat_e(Scenic*& p);
void delete_e(Scenic*& p);
void change_e(Scenic*& p);
int allpath(Scenic*& p);
void path(Scenic*& p, int l, int n, int k);
int locatevet(Scenic*& p, string v);
void searchTSP(Scenic*& p);
void showPath(Scenic*& p, int* path, int begin, int end);
void tracebackPath(int* path, int begin, int end, int* track, int pos);
int* bfsPath(Scenic*& p, int begin, int end);
void minpath(Scenic*& p);
int search_load(Scenic*& p, int x);
void Floyd1(int a, int b, struct Scenic*& p);
