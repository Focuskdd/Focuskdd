//��¼����ҳ��
#include<iostream>
#include<fstream>
#include<cstring>
#include"setup.h"
using namespace std ;
Scenic *A=new Scenic;

void change_graph() {
	while (1) {
		cout << "���㶯̬�滮"<<endl;
		for (int i = 0; i < 25; i++) {
			printf("*");
		}
		printf("\n");
		printf("*  1:���ӵ�·		*\n");
		printf("*  2:ɾ����·		*\n");
		printf("*  3:�޸ĵ�·����       *\n");
		printf("*  4:���Ӿ���		*\n");
		printf("*  5:ɾ������		*\n");
		printf("*  6:�޸ľ�����Ϣ	*\n");
		printf("*  7:�˳����㶯̬�滮   *\n");
		for (int i = 0; i < 25; i++) {
			printf("*");
		}
		cout << endl;
		printf("��������ѡ��ķ���");
		int in;
		cin >> in;
		printf("%d", in);
		if (in == 7) { printf("�ص����˵�"); break; }
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
	printf("����ɽ����ϵͳ��ӭ��\n");
	for (int i = 0;i < 25; i++){
	printf("*");}
	printf("\n");
	printf("*  1:��ѯ����           *\n");
	printf("*  2:����������̾��� *\n");
	printf("*  3:�������Ķ���·�� *\n");
	printf("*  4:������ѵ�·�滮   *\n");
	printf("*  5:���㶯̬�滮       *\n");
	printf("*  6:�˳�����ϵͳ       *\n");
	for (int i = 0; i < 25; i++) {
		printf("*");
	}
	cout << endl;
	printf("��������ѡ��ķ���");
	int in;
	cin >> in;
	printf("%d", in);
	if (in == 6) { printf("��ӭ�´�ʹ��"); break; }
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