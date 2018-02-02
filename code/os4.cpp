#include<iostream>
#include<cctype>
using namespace std;
//宏定义 
#define  M 4 //主存块数
#define  N 7 //作业的页数 
#define  Q 5 //页表列数
/***********全局变量***********/ 
int P[M];//已装入内存的页号 ，共四个 
int work[N][Q];//作业的页表 ，7页
/***指令的三元素********/ 
char oper;//操作 
int  number;//页号 
int  Padrs;//页内地址 
int  k=0;//指示要装入新页时应调出的页在数组的位置 ，初值为0 
int  L;//存放指令中访问的页号的全局变量 
int  J;//用来存放P[k] 
int temp;//暂时性变量 
/**********函数声名*********/ 
void Init();//初始化程序 
void display();//显示页表情况的函数 
void Input();//输入指令程序 
void check(int t);//查页表程序 
void Interp(int m);//缺页中断处理程序 
void Abadd(int w);//处理绝对地址函数 
void change();//修改页表函数
/*******************主函数*********************/ 
int main(){
    Init(); //调用初始化函数 
    cout<<"*******************页表初始状态:******************"<<endl;
    display();//显示初始页表情况 
lop:  
    Input(); //调用指令输入函数 
    L=number;//将指令中的页号赋给全局变量L 
    check(L); //调用查页表函数 
    if(temp==1)
          goto lop;//如果有后继指令，返回lop部分，继续输入 
    system("pause");//否则的话，结束程序 
    }
void Init(){  //初始化程序 
     for(int i=0;i<M;i++)
	 { P[i]=i; //主存块数组初始化 
     for(int a=0;a<N;a++) //页表初始化 
        { work[a][0]=a;
          if(i<M) work[a][1]=1;
          else    work[a][1]=0; 
          work[a][3]=0;  
        }
	 }
     work[0][2]=5; work[0][4]=11;
     work[1][2]=8; work[1][4]=12;
     work[2][2]=9; work[2][4]=13;
     work[3][2]=1; work[3][4]=21;
     work[4][2]=0; work[4][4]=22;
     work[5][2]=0; work[5][4]=23;
     work[6][2]=0; work[6][4]=121;
}
void display(){  //显示页表情况的函数 
     cout<<"页号  "<<"标志  "<<"主存块号  "<<"修改标志  "<<"在磁盘上的位置  "<<endl;
     for(int i=0;i<N;i++)
      { for(int j=0;j<Q;j++)
         { if(j==2&&work[i][2]==0)//当主存块号为0时，输出为空 
              cout<<" \t";
           else
              cout<<work[i][j]<<"\t";             
         }
         cout<<endl;
      }
     }
void Input(){ //指令输入函数 
     cout<<"请输入指令序列：\n操作  页号   页内地址  "<<endl;cin>>oper>>number>>Padrs;
     }
void check(int  t){ //查页表函数 
     if(work[t][1]==1) //如果该页的页标志为1，调用绝对地址函数   
           Abadd(t);
     else  Interp(t);//否则调用缺页中断处理函数 
}
void Abadd(int w){//绝对地址函数  
      int  address=work[w][2]*1024+Padrs;// 计算绝对地址  
      if(oper=='c') {work[w][3]=1;}//C代表存，如果是存指令，置L页的修改标志为1 
      cout<<"绝对地址："<<address<<endl; //输出绝对地址 
      cout<<"************指令执行后页表情况如下：**************"<<endl;
      display();//输出指令执行后的页表情况   
      cout<<endl<<"还有后继指令吗 1：有， 0：无"<<endl;//提示还有后继指令吗 ，1为有，0为无 
      cin>>temp;      }void Interp(int m){ //缺页中断处理程序  
      cout<<"该页页号* "<<m<<endl;//输出该页页号 
      //模拟FIFO页面调度 
      J=P[k]; //暂存P[k]值 
      if(work[J][3]==1)//判断J页的修改标志是否为1 
                cout<<"OUT "<<J<<endl;//是的话，输出OUT J                    
      cout<<"IN "<<L<<endl;//L页进入主存空间 
      P[k]=L; //修改P[k]为当前指令中的页号L 
      change();//调用修改页表函数，进行页表修改 
      k=(k+1)%M;//k值修改 
      check(L);//继续查看页表 
      }void change(){ //修改页表函数       
      int p;for(int i=1;i<=2;i++)
       {p=work[L][i];//修改页标志、主存块号 
        work[L][i]=work[J][i];work[J][i]=p;
       }      
    }
