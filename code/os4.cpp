#include<iostream>
#include<cctype>
using namespace std;
//�궨�� 
#define  M 4 //�������
#define  N 7 //��ҵ��ҳ�� 
#define  Q 5 //ҳ������
/***********ȫ�ֱ���***********/ 
int P[M];//��װ���ڴ��ҳ�� �����ĸ� 
int work[N][Q];//��ҵ��ҳ�� ��7ҳ
/***ָ�����Ԫ��********/ 
char oper;//���� 
int  number;//ҳ�� 
int  Padrs;//ҳ�ڵ�ַ 
int  k=0;//ָʾҪװ����ҳʱӦ������ҳ�������λ�� ����ֵΪ0 
int  L;//���ָ���з��ʵ�ҳ�ŵ�ȫ�ֱ��� 
int  J;//�������P[k] 
int temp;//��ʱ�Ա��� 
/**********��������*********/ 
void Init();//��ʼ������ 
void display();//��ʾҳ������ĺ��� 
void Input();//����ָ����� 
void check(int t);//��ҳ����� 
void Interp(int m);//ȱҳ�жϴ������ 
void Abadd(int w);//������Ե�ַ���� 
void change();//�޸�ҳ����
/*******************������*********************/ 
int main(){
    Init(); //���ó�ʼ������ 
    cout<<"*******************ҳ���ʼ״̬:******************"<<endl;
    display();//��ʾ��ʼҳ����� 
lop:  
    Input(); //����ָ�����뺯�� 
    L=number;//��ָ���е�ҳ�Ÿ���ȫ�ֱ���L 
    check(L); //���ò�ҳ���� 
    if(temp==1)
          goto lop;//����к��ָ�����lop���֣��������� 
    system("pause");//����Ļ����������� 
    }
void Init(){  //��ʼ������ 
     for(int i=0;i<M;i++)
	 { P[i]=i; //����������ʼ�� 
     for(int a=0;a<N;a++) //ҳ���ʼ�� 
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
void display(){  //��ʾҳ������ĺ��� 
     cout<<"ҳ��  "<<"��־  "<<"������  "<<"�޸ı�־  "<<"�ڴ����ϵ�λ��  "<<endl;
     for(int i=0;i<N;i++)
      { for(int j=0;j<Q;j++)
         { if(j==2&&work[i][2]==0)//��������Ϊ0ʱ�����Ϊ�� 
              cout<<" \t";
           else
              cout<<work[i][j]<<"\t";             
         }
         cout<<endl;
      }
     }
void Input(){ //ָ�����뺯�� 
     cout<<"������ָ�����У�\n����  ҳ��   ҳ�ڵ�ַ  "<<endl;cin>>oper>>number>>Padrs;
     }
void check(int  t){ //��ҳ���� 
     if(work[t][1]==1) //�����ҳ��ҳ��־Ϊ1�����þ��Ե�ַ����   
           Abadd(t);
     else  Interp(t);//�������ȱҳ�жϴ����� 
}
void Abadd(int w){//���Ե�ַ����  
      int  address=work[w][2]*1024+Padrs;// ������Ե�ַ  
      if(oper=='c') {work[w][3]=1;}//C����棬����Ǵ�ָ���Lҳ���޸ı�־Ϊ1 
      cout<<"���Ե�ַ��"<<address<<endl; //������Ե�ַ 
      cout<<"************ָ��ִ�к�ҳ��������£�**************"<<endl;
      display();//���ָ��ִ�к��ҳ�����   
      cout<<endl<<"���к��ָ���� 1���У� 0����"<<endl;//��ʾ���к��ָ���� ��1Ϊ�У�0Ϊ�� 
      cin>>temp;      }void Interp(int m){ //ȱҳ�жϴ������  
      cout<<"��ҳҳ��* "<<m<<endl;//�����ҳҳ�� 
      //ģ��FIFOҳ����� 
      J=P[k]; //�ݴ�P[k]ֵ 
      if(work[J][3]==1)//�ж�Jҳ���޸ı�־�Ƿ�Ϊ1 
                cout<<"OUT "<<J<<endl;//�ǵĻ������OUT J                    
      cout<<"IN "<<L<<endl;//Lҳ��������ռ� 
      P[k]=L; //�޸�P[k]Ϊ��ǰָ���е�ҳ��L 
      change();//�����޸�ҳ����������ҳ���޸� 
      k=(k+1)%M;//kֵ�޸� 
      check(L);//�����鿴ҳ�� 
      }void change(){ //�޸�ҳ����       
      int p;for(int i=1;i<=2;i++)
       {p=work[L][i];//�޸�ҳ��־�������� 
        work[L][i]=work[J][i];work[J][i]=p;
       }      
    }
