//登录服务页面
#include<iostream>
#include<fstream>
#include<cstring>
#include"setup.h"
using namespace std ;
Scenic *A=new Scenic;

void change_graph() {
	while (1) {
		cout << "景点动态规划"<<endl;
		for (int i = 0; i < 25; i++) {
			printf("*");
		}
		printf("\n");
		printf("*  1:增加道路		*\n");
		printf("*  2:删除道路		*\n");
		printf("*  3:修改道路长度       *\n");
		printf("*  4:增加景点		*\n");
		printf("*  5:删除景点		*\n");
		printf("*  6:修改景点信息	*\n");
		printf("*  7:退出景点动态规划   *\n");
		for (int i = 0; i < 25; i++) {
			printf("*");
		}
		cout << endl;
		printf("输入您想选择的服务：");
		int in;
		cin >> in;
		printf("%d", in);
		if (in == 7) { printf("回到主菜单"); break; }
		else {
			switch (in)
			{
			case 1:
				creat_v(A); break;
			case 2:
				delete_v(A); break;
			case 3:
				change_v(A); break;
			case 4:
				creat_e(A); break;
			case 5:
				delete_e(A); break;
			case 6:
				change_e(A); break;
			

			default:
				break;
			}
		}
	}
}



int main() {
	
	
	cin_scenic_info(A);    
	
	while(1){
	for (int i = 0; i < 25; i++) {
			printf("*");}
	printf("\n");
	printf("井冈山导游系统欢迎您\n");
	for (int i = 0;i < 25; i++){
	printf("*");}
	printf("\n");
	printf("*  1:查询景点           *\n");
	printf("*  2:两景点间的最短距离 *\n");
	printf("*  3:两景点间的多条路径 *\n");
	printf("*  4:旅游最佳道路规划   *\n");
	printf("*  5:景点动态规划       *\n");
	printf("*  6:退出旅游系统       *\n");
	for (int i = 0; i < 25; i++) {
		printf("*");
	}
	cout << endl;
	printf("输入您想选择的服务：");
	int in;
	cin >> in;
	printf("%d", in);
	if (in == 6) { printf("欢迎下次使用"); break; }
	else{
	switch (in)
	{
	case 1:
		print_graph(A); break;
	case 2:
		min_distance(A);break;
	case 3:
		 allpath(A);    break;
	case 4:
		guide_line(A); break;
		
		//minpath(A); break;
	case 5:
		change_graph(); break;
	default:
		break;
}}

	
}

}