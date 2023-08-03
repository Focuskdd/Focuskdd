#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#include"setup.h"
#define INF 10000
//创建景区
void cin_scenic_info(Scenic*& p)
{
        p->mat.Sname = "井冈山"; p->mat.count = 8; p->mat.edge = 13;
        string str;
        ifstream infile;
        infile.open("景区景点信息表.txt", ios::in);  //输入文件的路径，ios::in可以省略
        
        for(int i =1;i<9;i++ ){
        cout << "*"  ;
        }
        cout << endl;
        cout << "*井冈山*景区景点编号及名称如下："<<endl;
        for (int i = 1; i < 9; i++) {
            cout << "*" ;
        }
        cout << endl;
        string a[100] = { "0" };int i = 1;
        infile >> i >> str;
        a[1] = str;
        cout << i << str << endl;
    //获取文件中的字符串 
        
        while (infile >> i >> str)
        {
          
         cout << i << str << endl ;
            a[i] = str;
      }
         for (int j = 1; j <= p->mat.count; j++)
        {
         p->mat.Pname[j] = a[j];
         }

    infile.close();   //调用close（）函数关闭文件
        
    
   
    string str1, str2, m;
   
    infile.open("景区道路信息表.txt", ios::in);  //输入文件的路径，ios::in可以省略
    int x = 1, y = 1, s[100][100] = { 0 };
    double dis = 0.0;
    infile >> x >> str1 >> y >> str2 >> dis >> m;
   
    s[x][y] = dis;
    //获取文件中的字符串  
    while (infile >> x >> str1 >> y >> str2 >> dis >> m)
    {
        
        s[x][y] = dis;
        //获取文件中的字符串
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
    infile.close();   //调用close（）函数关闭文件
    //包含文件操作

   
    }
    
    




//输出景点分布（二维数组的形式输出）
void print_graph(Scenic*& p)
{
    string name;
    
    cout << "*景区名称：" << endl;
    cin >> name;
    getchar();

      if (p->mat.Sname == name)//找到的地址不为空，只有名字相同时才，进行输出有关信息
        {
            cout << "*******************查询景区名称为 " << name << " 的各景点分布图如下（以二维数组表示）： " << endl;
            cout << "（输出的二维数组表示编号为i的景点到编号为j的景点的距离，0则表示两景点间无路径） " << endl;
            for (int i = 1; i <= p->mat.count; ++i)
            {
                cout << "景点名称 " << p->mat.Pname[i]<<"    " << "\t";
                for (int j = 1; j <= p->mat.count; ++j)
                    cout << ' ' << p->mat.m[i][j] << "\t";
                cout << endl;
            }

            //查询景点及景点周围状况
            cout << "请输入您想搜索的景点：";
            string wantname;
            cin >> wantname;
            cout << endl;
            for (int i = 0; i <= p->mat.count; ++i)
            {
                if (p->mat.Pname[i] == wantname) {
                    cout << "该景点存在,景点编号为" << i << ",景点名称为" << p->mat.Pname[i] << endl;
                    cout << "该景点周围景点有：";
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
        cout << "\n*景区景点分布图为" << name << "的景区查询不成功！\n";
      cout << endl;
}



//Floyd算发求最短路
void Floyd(int a, int b, struct Scenic*& p)
{
    int i, j, k;
    int A[100][100], path[100][100];
    for (i = 1; i <= p->mat.count; i++)//对进行求最短路的矩阵进行处理
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
        cout << "\n*从 " << p->mat.Pname[a] << " 到 " << p->mat.Pname[b] << " 的最短路径为：";
        k = path[a][b];
        d = 0;
        apath[d] = b;
        while (k != -1 && k != a)//循环实现记录对应的节点编号
        {
            d++;
            apath[d] = k;
            k = path[a][k];
        }
        d++;
        apath[d] = a;
        cout << p->mat.Pname[apath[d]];       

        for (int s = d - 1; s >= 0; s--)//输出节点名称
        {
            cout << " --> " << p->mat.Pname[apath[s]];
            
        }
        cout << " ，最短距离为：" << A[a][b] << endl;
    }
    else if (a == b)
        cout << "\n*景点编号输入不合法！\n";
    else
        cout << "\n*这两个景点间不存在路径\n";
}
//最短路径、距离
void min_distance(Scenic*& p)
{
    
    string name;
    int a, b;
    cout << "*景区名称：" << endl;
    cin >> name;
    getchar();

            if (p->mat.Sname == name)
            {
                cout << "*******下面为该景区的一些信息：" << endl;
                cout << "*******景区名称：" << p->mat.Sname << endl;
                for (int i = 1; i <= p->mat.count; ++i)
                {
                    cout << "编号为 " << i << ' ' << "的景点名称为 " << p->mat.Pname[i]<<"     " << "\t";
                    for (int j = 1; j <= p->mat.count; ++j)
                        cout << ' ' << p->mat.m[i][j]<<"\t";
                    cout << endl;
                }
                cout << "*请输入要查询的 最短路径和最短距离 的两个景点的编号：\n";
                cout << "\t-景点 1：";
                cin >> a;
                getchar();
                cout << "\t-景点 2：";
                cin >> b;
                getchar();
                Floyd(a, b, p);
               
            }
            else
                cout << "\n*景区景点分布图查询不成功！\n";
}



//深度优先搜索导游线路
int visited[100] = { 0 };
int np;//找到的景点个数，用于在递归时找到出口
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
//导游线路
void guide_line(Scenic*& p)
{
    //checked();
    
    int c;
    cout << "\n*请输入对应景区的名称：";
    string name;
    cin >> name;
    getchar();
      
            if (p->mat.Sname == name)
            {
                memset(visited, 0, sizeof(visited));
                np = 0;
                cout << "输入对应景点的编号" << endl;
                cin >> c;
                cout << "*形成的导游线路图（采用深度优先策略）如下所示：\n\n\t";
                DFS(c, p);
                
               
            }
            
            else
            cout << "\n*景区景点分布图为" << name << "的景区查询不成功！\n";
   
}
int DFS_Count;
int vis[100];
void dfs(int i, struct Scenic* p)
{
    vis[i] = 1;//标记顶点i被访问
    for (int j = 1; j <= p->mat.count; j++)
    {
        if (p->mat.m[i][j] != 0 && vis[j] == 0)
            dfs(j, p);
    }
}
//增加路径
void creat_v(Scenic*& p) {
    int i, j,dis;
    cout << "请输入您想增加哪两个景点之间的道路的编号："<<endl;
    cout << "景点1的编号为：";
    cin >> i ;
    cout << endl;
    cout << "景点2的编号为：";
    cin >> j;
    cout << endl;
    cout << "请输入该道路的长度：" << endl;
    cin >> dis;
    cout << endl;
    p->mat.m[i][j] = dis; p->mat.m[j][i] = dis;
    ofstream outFile;  //输出流对象
    outFile.open("景区景点信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区景点信息表.txt", ios::app);
    
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    outFile.open("景区道路信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区道路信息表.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if (j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
    cout << "修改道路信息成功" << endl;
}

//删除路径
void delete_v(Scenic*& p) {
    int i, j;
    cout << "请输入您想删除哪两个景点之间的道路的编号：" << endl;
    cout << "景点1的编号为：";
    cin >> i;
    cout << endl;
    cout << "景点2的编号为：";
    cin >> j;
    cout << endl;
    p->mat.m[i][j] = 0; p->mat.m[i][j] = 0;
    ofstream outFile;  //输出流对象
    outFile.open("景区景点信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区景点信息表.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    outFile.open("景区道路信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区道路信息表.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if (j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
    cout << "修改道路信息成功" << endl;
}

//修改道路长度
void change_v(Scenic*& p) {
    int i, j, dis;
    cout << "请输入您想修改哪两个景点之间的道路的编号：" << endl;
    cout << "景点1的编号为：";
    cin >> i;
    cout << endl;
    cout << "景点2的编号为：";
    cin >> j;
    cout << endl;
    cout << "请输入修改后道路的长度：" << endl;
    cin >> dis;
    cout << endl;
    p->mat.m[i][j] = dis; p->mat.m[j][i] = dis;
    ofstream outFile;  //输出流对象
    outFile.open("景区景点信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区景点信息表.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    outFile.open("景区道路信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区道路信息表.txt", ios::app);
   
    for (int i = 1; i <= p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if ( j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] <<" "<< p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
    cout << "修改道路信息成功" << endl;
}

//删除景点
void delete_e(Scenic*& p) {
    string s,o[100];
    for (int i = 0; i < 100; i++) {
        o[i] = p->mat.Pname[i];
    }
    int n;//记录删除的景点的上一个景点
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
    cout << "请输入您想删除的景点名称：";
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
    //修改二维数值
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
    ofstream outFile;  //输出流对象
    outFile.open("景区景点信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区景点信息表.txt", ios::app);
    
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    cout << "修改景点信息成功" << endl;
    outFile.open("景区道路信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区道路信息表.txt", ios::app);
    for (int i = 1; i <= p->mat.count; i++) {
        for (int j = 1; j <= p->mat.count; j++) {
            if (j > i && p->mat.m[i][j] > 0) {
                outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
            }
        }
    }

    outFile.close();
}
//增加景点
void creat_e(Scenic*& p) {

    p->mat.count++;
    int y = p->mat.count;
    string creat;
    cout << "请输入您想增加的景点的名称：";
    cin >> creat;
    p->mat.Pname[p->mat.count] = creat;
    int x;
    cout << "请输入新景点到其他景点的道路数：";
    cin >> x;
    p->mat.edge = p->mat.edge + x;
    for (int i = 1; i < p->mat.count; i++) {
        
            int dis;
            cout << "请输入新景点到景点" << p->mat.Pname[i] << "的距离：";
            cin >> dis;
            p->mat.m[y][i] = p->mat.m[i][y] =dis;
           


    }
    ofstream outFile;  //输出流对象
    outFile.open("景区景点信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区景点信息表.txt", ios::app);
   
    for (int i = 1; i <= p->mat.count; i++) {
        outFile << i << p->mat.Pname[i] << endl;
    }
    outFile.close(); 
    cout << "修改景点信息成功" << endl;
    outFile.open("景区道路信息表.txt", ios::trunc);
    outFile.close();
    outFile.open("景区道路信息表.txt", ios::app);
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
     cout << "请输入景点修改前的名称：";
     string x;
     cin >> x;
     cout << endl;

     cout << "请输入景点修改后的名称：";
     string y;
     cin >> y;
     cout << endl;
     for (int i = 0; i <= p->mat.count; i++)
     {  
         if (p->mat.Pname[i] == x) { p->mat.Pname[i] = y; break; }
       
     }
     ofstream outFile;  //输出流对象
     outFile.open("景区景点信息表.txt", ios::trunc);
     outFile.close();
     outFile.open("景区景点信息表.txt", ios::app);
     
     for (int i = 1; i <= p->mat.count; i++) {
         outFile << i << p->mat.Pname[i] << endl;
     }
     outFile.close(); cout << "修改景点信息成功" << endl;
     outFile.open("景区道路信息表.txt", ios::trunc);
     outFile.close();
     outFile.open("景区道路信息表.txt", ios::app);
     for (int i = 1; i <= p->mat.count; i++) {
         for (int j = 1; j <= p->mat.count; j++) {
             if (j > i && p->mat.m[i][j] > 0) {
                 outFile << i << " " << p->mat.Pname[i] << " " << j << " " << p->mat.Pname[j] << " " << p->mat.m[i][j] << " " << "m" << endl;
             }
         }
     }

     outFile.close();
    
 }
 //判断路径是否存在

 int visited1[50]; int d[30];
 int locatevet(Scenic*& p, string v)
 {
     int i;
     for (i = 0; i <= p->mat.count; i++)
         if (v == p->mat.Pname[i])return i;//找到返回顶点i
     return -1;//未找到
 }
 //查询输入序号l,n间景点的路径
 void path(Scenic*& p, int l, int n, int k)
 {
     int s, t = k + 1; int length = 0;//t用于存储路径上下一顶点对应的d[]数组元素的下标
     if (d[k] == n && k <= 8)//若d[k]是终点且景点个数<8，则输出该路径
     {
         for (s = 0; s < k; s++)
         {
             length = length + p->mat.m[d[s]][d[s + 1]];
         }
        
             for (s = 0; s < k; s++)//输出该路径，s=0时为起点m
             {
                
                 cout << d[s] << p->mat.Pname[d[s]] << "--->";
             }
           
             cout << d[s] << p->mat.Pname[d[s]] ;
        
             cout << "总路线长为" << length << endl;
         
     }
     else
     {
         s = 1;
         while (s <= p->mat.count)//从第m个顶点，访问所有顶点是否有路径
         {
             if ((p->mat.m[d[k]][s]) && (visited1[s] == 0))//顶点有边且未被访问
             {
                 visited1[s] = 1;
                 d[k + 1] = s;//存储顶点编号
                 path(p, l, n, t);
                 visited1[s] = 0;//将找到的路径上的顶点的访问标志重新设置为，便于探究新的路径
             }
             s++;//试验下一顶点s开始是否有到终点的路径；
         }
     }
 }
 //查询两景点的所有路径
 int allpath(Scenic*& p)
 {
     int k, l, n; string i, j;
     printf("\n\n请输入您想要查询的两个景点的名称：\n\n");
     cin >> i;
     cin>>j; 
     printf("\n\n");
     l = locatevet(p, i);//locatevet 确定该顶点是否存在。若存在，返回该顶点编号。 
     n = locatevet(p, j);
     d[0] = 1;//路径起点l(字母).(d[]数组为全局变量)
     for (k = 0; k < p->mat.count; k++)
         visited1[k] = 0;
     visited1[l] = 1;
     path(p, l, n, 0);
     return 1;
 }



 //最佳路径
 //广度优先搜索算法

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
//回溯路径
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



