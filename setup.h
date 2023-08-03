//建立景区并且查找景点和景点周围的景点
#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include <queue>
using namespace std; 
struct Matrix
{
	string Sname;//景区名称
	int count;//景点总数量
	int edge;//道路数量
	int m[100][100]={0};//景点二维数组
	string Pname[100]={"0"};//各个景点的名称
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
