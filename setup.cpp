#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#include"setup.h"
#define INF 10000
//��������
void cin_scenic_info(Scenic*& p)
{
        p->mat.Sname = "����ɽ"; p->mat.count = 8; p->mat.edge = 13;
        string str;
        ifstream infile;
        infile.open("����������Ϣ��.txt", ios::in);  //�����ļ���·����ios::in����ʡ��
        
        for(int i =1;i<9;i++ ){
        cout << "*"  ;
        }
        cout << endl;
        cout << "*����ɽ*���������ż��������£�"<<endl;
        for (int i = 1; i < 9; i++) {
            cout << "*" ;
        }
        cout << endl;
        string a[100] = { "0" };int i = 1;
        infile >> i >> str;
        a[1] = str;
        cout << i << str << endl;
    //��ȡ�ļ��е��ַ��� 
        
        while (infile >> i >> str)
        {
          
         cout << i << str << endl ;
            a[i] = str;
      }
         for (int j = 1; j <= p->mat.count; j++)
        {
         p->mat.Pname[j] = a[j];
         }

    infile.close();   //����close���������ر��ļ�
        
    
   
    string str1, str2, m;
   
    infile.open("������·��Ϣ��.txt", ios::in);  //�����ļ���·����ios::in����ʡ��
    int x = 1, y = 1, s[100][100] = { 0 };
    double dis = 0.0;
    infile >> x >> str1 >> y >> str2 >> dis >> m;
   
    s[x][y] = dis;
    //��ȡ�ļ��е��ַ���  
    while (infile >> x >> str1 >> y >> str2 >> dis >> m)
    {
        
        s[x][y] = dis;
        //��ȡ�ļ��е��ַ���
    }
    for (int a = 1; a <=p->mat.count;a++) {
        for (int b = 1;b <=p->mat.count; b++) {
            p->mat.m[a][b] = s[a][b];
           
            }
        }
    for (int a = 1; a <= p->mat.count; a++) {
        for (int b = 1; b <= p->mat.count; b++) {
            p->mat.m[b][a] = p->mat.m[a][b];

        }
    }
    infile.close();   //����close���������ر��ļ�
    //�����ļ�����

   
    }
    
    




//�������ֲ�����ά�������ʽ�����
void print_graph(Scenic*& p)
{
    string name;
    
    cout << "*�������ƣ�" << endl;
    cin >> name;
    getchar();

      if (p->mat.Sname == name)//�ҵ��ĵ�ַ��Ϊ�գ�ֻ��������ͬʱ�ţ���������й���Ϣ
        {
            cout << "*******************��ѯ��������Ϊ " << name << " �ĸ�����ֲ�ͼ���£��Զ�ά�����ʾ���� " << endl;
            cout << "������Ķ�ά�����ʾ���Ϊi�ľ��㵽���Ϊj�ľ���ľ��룬0���ʾ���������·���� " << endl;
            for (int i = 1; i <= p->mat.count; ++i)
            {
                cout << "�������� " << p->mat.Pname[i]<<"    " << "\t";
                for (int j = 1; j <= p->mat.count; ++j)
                    cout << ' ' << p->mat.m[i][j] << "\t";
                cout << endl;
            }

            //��ѯ���㼰������Χ״��
            cout << "���������������ľ��㣺";
            string wantname;
            cin >> wantname;
            cout << endl;
            for (int i = 0; i <= p->mat.count; ++i)
            {
                if (p->mat.Pname[i] == wantname) {
                    cout << "�þ������,������Ϊ" << i << ",��������Ϊ" << p->mat.Pname[i] << endl;
                    cout << "�þ�����Χ�����У�";
                    for (int j = 1; j <= p->mat.count; ++j) {
                        if (p->mat.m[i][j] > 0) {
                            cout << " " << p->mat.Pname[j];
                        }
                    
                    }
                    break;
                }

            }
            

            
        }
       
      else
        cout << "\n*��������ֲ�ͼΪ" << name << "�ľ�����ѯ���ɹ���\n";
      cout << endl;
}



//Floyd�㷢�����·
void Floyd(int a, int b, struct Scenic*& p)
{
    int i, j, k;
    int A[100][100], path[100][100];
    for (i = 1; i <= p->mat.count; i++)//�Խ��������·�ľ�����д���
    {
        for (j = 1; j <= p->mat.count; j++)
        {
            if (p->mat.m[i][j] == 0 && i != j)
                A[i][j] = INF;
            else if (i == j)
                A[i][j] = 0;
            else
                A[i][j] = p->mat.m[i][j];
            if (i != j && p->mat.m[i][j] < INF)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }
    for (k = 1; k <= p->mat.count; k++)
    {
        for (i = 1; i <= p->mat.count; i++)
        {
            for (j = 1; j <= p->mat.count; j++)
            {
                if (A[i][j] > A[i][k] + A[k][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    int apath[100], d;
    if (A[a][b] < INF && a != b)
    {
        cout << "\n*�� " << p->mat.Pname[a] << " �� " << p->mat.Pname[b] << " �����·��Ϊ��";
        k = path[a][b];
        d = 0;
        apath[d] = b;
        while (k != -1 && k != a)//ѭ��ʵ�ּ�¼��Ӧ�Ľڵ���
        {
            d++;
            apath[d] = k;
            k = path[a][k];
        }
        d++;
        apath[d] = a;
        cout << p->mat.Pname[apath[d]];       

        for (int s = d - 1; s >= 0; s--)//����ڵ�����
        {
            cout << " --> " << p->mat.Pname[apath[s]];
            
        }
        cout << " ����̾���Ϊ��" << A[a][b] << endl;
    }
    else if (a == b)
        cout << "\n*���������벻�Ϸ���\n";
    else
        cout << "\n*����������䲻����·��\n";
}
//���·��������
void min_distance(Scenic*& p)
{
    
    string name;
    int a, b;
    cout << "*�������ƣ�" << endl;
    cin >> name;
    getchar();

            if (p->mat.Sname == name)
            {
                cout << "*******����Ϊ�þ�����һЩ��Ϣ��" << endl;
                cout << "*******�������ƣ�" << p->mat.Sname << endl;
                for (int i = 1; i <= p->mat.count; ++i)
                {
                    cout << "���Ϊ " << i << ' ' << "�ľ�������Ϊ " << p->mat.Pname[i]<<"     " << "\t";
                    for (int j = 1; j <= p->mat.count; ++j)
                        cout << ' ' << p->mat.m[i][j]<<"\t";
                    cout << endl;
                }
                cout << "*������Ҫ��ѯ�� ���·������̾��� ����������ı�ţ�\n";
                cout << "\t-���� 1��";
                cin >> a;
                getchar();
                cout << "\t-���� 2��";
                cin >> b;
                getchar();
                Floyd(a, b, p);
               
            }
            else
                cout << "\n*��������ֲ�ͼ��ѯ���ɹ���\n";
}



//�����������������·
int visited[100] = { 0 };
int np;//�ҵ��ľ�������������ڵݹ�ʱ�ҵ�����
void DFS(int c, struct Scenic* p)
{
    np++;
    if (np == p->mat.count)
    {
        cout << p->mat.Pname[c] << endl;
        
    }
    else
        cout << p->mat.Pname[c] << " --> ";
    visited[c] = 1;
    for (int i = 1; i <= (p->mat.count); i++)
    {
        if (p->mat.m[c][i] > 0 && !visited[i])
        {
            DFS(i, p);
            if (p->mat.count > np)
            {
                cout << p->mat.Pname[c] << "-->";
            }
        }
    }
    if (np == p->mat.count)
        return;
}
//������·
void guide_line(Scenic*& p)
{
    //checked();
    
    int c;
    cout << "\n*�������Ӧ���������ƣ�";
    string name;
    cin >> name;
    getchar();
      
            if (p->mat.Sname == name)
            {
                memset(visited, 0, sizeof(visited));
                np = 0;
                cout << "�����Ӧ����ı��" << endl;
                cin >> c;
                cout << "*�γɵĵ�����·ͼ������������Ȳ��ԣ�������ʾ��\n\n\t";
                DFS(c, p);
                
               
            }
            
            else
            cout << "\n*��������ֲ�ͼΪ" << name << "�ľ�����ѯ���ɹ���\n";
   
}
int DFS_Count;
int vis[100];
void dfs(int i, struct Scenic* p)
{
    vis[i] = 1;//��Ƕ���i������
    for (int j = 1; j <= p->mat.count; j++)
    {
        if (p->mat.m[i][j] != 0 && vis[j] == 0)
            dfs(j, p);
    }
}
//����·��
void creat_v(Scenic*& p) {
    int i, j,dis;
    cout << "������������������������֮��ĵ�·�ı�ţ�"<<endl;
    cout << "����1�ı��Ϊ��";
    cin >> i ;
    cout << endl;
    cout << "����2�ı��Ϊ��";
    cin >> j;
    cout << endl;
    cout << "������õ�·�ĳ��ȣ�" << endl;
    cin >> dis;
    cout << endl;
    p->mat.m[i][j] = dis; p->mat.m[j][i] = dis;
    ofstream outFile;  //���������
    outFile.open("����������Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("����������Ϣ��.txt", ios::app);
    
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    outFile.open("������·��Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("������·��Ϣ��.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if (j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
    cout << "�޸ĵ�·��Ϣ�ɹ�" << endl;
}

//ɾ��·��
void delete_v(Scenic*& p) {
    int i, j;
    cout << "����������ɾ������������֮��ĵ�·�ı�ţ�" << endl;
    cout << "����1�ı��Ϊ��";
    cin >> i;
    cout << endl;
    cout << "����2�ı��Ϊ��";
    cin >> j;
    cout << endl;
    p->mat.m[i][j] = 0; p->mat.m[i][j] = 0;
    ofstream outFile;  //���������
    outFile.open("����������Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("����������Ϣ��.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    outFile.open("������·��Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("������·��Ϣ��.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if (j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
    cout << "�޸ĵ�·��Ϣ�ɹ�" << endl;
}

//�޸ĵ�·����
void change_v(Scenic*& p) {
    int i, j, dis;
    cout << "�����������޸�����������֮��ĵ�·�ı�ţ�" << endl;
    cout << "����1�ı��Ϊ��";
    cin >> i;
    cout << endl;
    cout << "����2�ı��Ϊ��";
    cin >> j;
    cout << endl;
    cout << "�������޸ĺ��·�ĳ��ȣ�" << endl;
    cin >> dis;
    cout << endl;
    p->mat.m[i][j] = dis; p->mat.m[j][i] = dis;
    ofstream outFile;  //���������
    outFile.open("����������Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("����������Ϣ��.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    outFile.open("������·��Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("������·��Ϣ��.txt", ios::app);
   
    for (int i = 1; i <= p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if ( j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] <<" "<< p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
    cout << "�޸ĵ�·��Ϣ�ɹ�" << endl;
}

//ɾ������
void delete_e(Scenic*& p) {
    string s,o[100];
    for (int i = 0; i < 100; i++) {
        o[i] = p->mat.Pname[i];
    }
    int n;//��¼ɾ���ľ������һ������
    Lnode *q=new Lnode;
    q->data = "0";
    Lnode* h = q;
    Lnode* w = q;
    
    for(int i=1;i<=p->mat.count;i++)
   {
    Lnode* d = new Lnode;
    d->data = p->mat.Pname[i];
    q->next = d;
    q = d;
   }
    cout << "����������ɾ���ľ������ƣ�";
    cin >> s; cout << endl;
    for (int i = 1; i <= p->mat.count; i++)
    {
        if (p->mat.Pname[i] == s) { n = i - 1; break; }
    }
    //h = h->next;
    for (;;) {
        if (h->data == p->mat.Pname[n])break;
        h = h->next;
        }
    h->next = h->next->next;
    w = w->next;
    for (int i = 1; i <p->mat.count; i++)
    {
      p->mat.Pname[i] =  w->data ;
       w = w->next;
    }
    //�޸Ķ�ά��ֵ
    p->mat.count--;
    int a[100][100]={0};
    for (int i = 1; i < p->mat.count+1; i++) {
        if (o[i] == s) { i++;  }
        for (int j = 1; j < p->mat.count+1; j++) {
            if (o[j] == s) { j++; }
            a[i][j] = p->mat.m[i][j];
        }
    }
    for (int i = 1; i <=p->mat.count + 1; i++) {
        for (int j = 1; j <=p->mat.count + 1; j++) {
           p->mat.m[i][j]= a[i][j] ;
        }
    }
    ofstream outFile;  //���������
    outFile.open("����������Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("����������Ϣ��.txt", ios::app);
    
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    cout << "�޸ľ�����Ϣ�ɹ�" << endl;
    outFile.open("������·��Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("������·��Ϣ��.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if (j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
}
//���Ӿ���
void creat_e(Scenic*& p) {

    p->mat.count++;
    int y = p->mat.count;
    string creat;
    cout << "�������������ӵľ�������ƣ�";
    cin >> creat;
    p->mat.Pname[p->mat.count] = creat;
    int x;
    cout << "�������¾��㵽��������ĵ�·����";
    cin >> x;
    p->mat.edge = p->mat.edge + x;
    for (int i = 1; i < p->mat.count; i++) {
        
            int dis;
            cout << "�������¾��㵽����" << p->mat.Pname[i] << "�ľ��룺";
            cin >> dis;
            p->mat.m[y][i] = p->mat.m[i][y] =dis;
           


    }
    ofstream outFile;  //���������
    outFile.open("����������Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("����������Ϣ��.txt", ios::app);
   
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    cout << "�޸ľ�����Ϣ�ɹ�" << endl;
    outFile.open("������·��Ϣ��.txt", ios::trunc);
    outFile.close();
    outFile.open("������·��Ϣ��.txt", ios::app);
    for (int i = 1; i <=p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if (j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
  
    }

    
 void change_e(Scenic*& p){
     cout << "�����뾰���޸�ǰ�����ƣ�";
     string x;
     cin >> x;
     cout << endl;

     cout << "�����뾰���޸ĺ�����ƣ�";
     string y;
     cin >> y;
     cout << endl;
     for (int i = 0; i <= p->mat.count; i++)
     {  
         if (p->mat.Pname[i] == x) { p->mat.Pname[i] = y; break; }
       
     }
     ofstream outFile;  //���������
     outFile.open("����������Ϣ��.txt", ios::trunc);
     outFile.close();
     outFile.open("����������Ϣ��.txt", ios::app);
     
     for (int i = 1; i <= p->mat.count; i++) {
         outFile << i << p->mat.Pname[i] << endl;
     }
     outFile.close(); cout << "�޸ľ�����Ϣ�ɹ�" << endl;
     outFile.open("������·��Ϣ��.txt", ios::trunc);
     outFile.close();
     outFile.open("������·��Ϣ��.txt", ios::app);
     for (int i = 1; i <= p->mat.count; i++) {
         for (int j = 1; j <= p->mat.count; j++) {
             if (j > i && p->mat.m[i][j] > 0) {
                 outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
             }
         }
     }

     outFile.close();
    
 }
 //�ж�·���Ƿ����

 int visited1[50]; int d[30];
 int locatevet(Scenic*& p, string v)
 {
     int i;
     for (i = 0; i <= p->mat.count; i++)
         if (v == p->mat.Pname[i])return i;//�ҵ����ض���i
     return -1;//δ�ҵ�
 }
 //��ѯ�������l,n�侰���·��
 void path(Scenic*& p, int l, int n, int k)
 {
     int s, t = k + 1; int length = 0;//t���ڴ洢·������һ�����Ӧ��d[]����Ԫ�ص��±�
     if (d[k] == n && k <= 8)//��d[k]���յ��Ҿ������<8���������·��
     {
         for (s = 0; s < k; s++)
         {
             length = length + p->mat.m[d[s]][d[s + 1]];
         }
        
             for (s = 0; s < k; s++)//�����·����s=0ʱΪ���m
             {
                
                 cout << d[s] << p->mat.Pname[d[s]] << "--->";
             }
           
             cout << d[s] << p->mat.Pname[d[s]] ;
        
             cout << "��·�߳�Ϊ" << length << endl;
         
     }
     else
     {
         s = 1;
         while (s <= p->mat.count)//�ӵ�m�����㣬�������ж����Ƿ���·��
         {
             if ((p->mat.m[d[k]][s]) && (visited1[s] == 0))//�����б���δ������
             {
                 visited1[s] = 1;
                 d[k + 1] = s;//�洢������
                 path(p, l, n, t);
                 visited1[s] = 0;//���ҵ���·���ϵĶ���ķ��ʱ�־��������Ϊ������̽���µ�·��
             }
             s++;//������һ����s��ʼ�Ƿ��е��յ��·����
         }
     }
 }
 //��ѯ�����������·��
 int allpath(Scenic*& p)
 {
     int k, l, n; string i, j;
     printf("\n\n����������Ҫ��ѯ��������������ƣ�\n\n");
     cin >> i;
     cin>>j; 
     printf("\n\n");
     l = locatevet(p, i);//locatevet ȷ���ö����Ƿ���ڡ������ڣ����ظö����š� 
     n = locatevet(p, j);
     d[0] = 1;//·�����l(��ĸ).(d[]����Ϊȫ�ֱ���)
     for (k = 0; k < p->mat.count; k++)
         visited1[k] = 0;
     visited1[l] = 1;
     path(p, l, n, 0);
     return 1;
 }



 //���·��
 //������������㷨

 int* bfsPath(Scenic*& p, int begin, int end) {

     int* visit = new int[p->mat.count];
     int* path = new int[p->mat.count];
     for (int index = 0; index < p->mat.count; ++index) {
         visit[index] = 0;
         path[index] = -1;
     }

     queue<int> queue;
     queue.push(begin);

     while (!queue.empty()) {
         int cursor = queue.front();
         queue.pop();
         if (cursor == end) {
             break;
         }
         else {
             if (visit[cursor] == 0) {
                 visit[cursor] = 1;
                 for (int index = 0; index < p->mat.count; ++index) {
                     if (visit[index] == 0 && p->mat.m[cursor][index] != 0) {
                         path[index] = cursor;
                         queue.push(index);
                     }
                 }
             }
         }
     delete[] visit;
     if (path[end] == -1) {
         delete[] path;
     }
     else {
         return path;
     }
 }
     return 0 ;
}
//����·��
void tracebackPath(int* path, int begin, int end, int* track, int pos) {
    if (begin != end) {
        int cursor = end;
        track[pos] = cursor;
        tracebackPath(path, begin, path[cursor], track, pos + 1);
    }
    else {
        int count = pos + 1;
        int index;
        track[pos] = end;
        track[count] = -1;
        for (index = 0; index < count / 2; ++index) {
            int temp = track[index];
            track[index] = track[count - index - 1];
            track[count - index - 1] = temp;
        }
    }
}

void showPath(Scenic*& p, int* path, int begin, int end) {
    int* track = new int[p->mat.count + 1];
    int index;
    tracebackPath(path, begin, end, track, 0);
    printf("\n");
    for (index = 0; track[index] != -1; ++index) {
        if (index > 0) {
            printf("-> ");
        }
        cout << p->mat.Pname[track[index]];
    }
    cout << "\n";
    cout << endl;
    delete[] track;
}



