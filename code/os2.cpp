# include "stdio.h"
# define M 50 
int max[M][M];  
int allocation[M][M]; 
int need[M][M]; 
int available[M];     
int i, j,  n, m, anquan,x=0;  
main()     
{   void check(); 
int p,q,control;  
int req[M],allocation1[M][M],need1[M][M],available1[M]; 
printf("�����������:"); 
scanf("%d", &n);   
printf("������Դ��������:"); 
scanf("%d", &m);  
printf("�����������Max:\n"); 
for(i=0;i<n; i++) for(j=0;j<m; j++)  
scanf("%2d",&max[i][j]);   
printf("�����ѷ������Allocation:\n"); 
for(i=0;i<n; i++) for(j=0;j<m; j++)  
scanf("%d", &allocation[i][j]);               
for (i=0;i<n; i++) 
for(j=0;j<m; j++)  
need[i][j]=max[i][j]-allocation[i][j]; 
printf("������Դ��ϵͳ��ʼֵ:\n"); 
for (j=0;j<m;j++)  
scanf("%d", &available[j]);    
for (j=0;j<m;j++)   
for(i=0;i<n;i++) 
  available[j]=available[j]-allocation[i][j];              
check();                                       
if (anquan==1)                          {  
for(control=0;;control++)  
{  p=0,q=0;  printf("��������Ľ��̺�: "); 
scanf("%d", &i);                
printf("����ý��̵�������Դ����:"); 
for(j=0;j<m; j++)  
scanf("%d",&req[j]);         
for(j=0;j<m; j++) 
if(req[j]>need[i][j])               
p=1;          
if(p)  
printf("������Դ���ڸý��̻���Ҫ����Դ\n"); 
else            
{ for(j=0;j<m; j++)               
if(req[j]>available[j])                 
q=1;   
if(q)  printf("������Դ������������\n"); 
else                
{                  
for(j=0;j<m; j++)                       
{          
available1[j]=available[j];        
allocation1[i][j]=allocation[i][j]; 
need1[i][j]=need[i][j];                           
available[j]=available[j]-req[j]; 
allocation[i][j]=allocation[i][j]+req[j]; 
need[i][j]=need[i][j]-req[j]; 
if(need[i][j]==0)       
x=x+1;                                    
} 
if(x==m)  
for(j=0;j<m;j++)   
{      
available[j]=available[j]+allocation[i][j];      
allocation[i][j]=0; 
     available1[j]=available[j];       
x--;                         
} 
else x=0;  
check();                           
if(anquan==0)                                           
{for (j=0;j<m; j++)                       
{    available[j]=available1[j]; 
allocation[i][j]=allocation1[i][j]; 
need[i][j]=need1[i][j];                       
}  
printf("ִ�иý��̲���ȫ ���ؼ�������\n");                     
}                
}             
}  
printf("�Ƿ��������?\n");        
}     
} 
}  
void check()  
{  int k, f, no=0; 
int work[M],a[M]; 
char  finish[M]; 
anquan=1;  
for(i=0;i<n; i++) 
finish[i]='F';        
for(j=0;j<m; j++)  
work[j]=available[j];          
k=n; 
do          
{  
for (i=0;i<n; i++)                
{if (finish[i]=='F') 
{  f=1;  
for (j=0;j<m; j++) 
if (need[i][j]>work[j])                         
f=0;                      
if (f==1)   
{  finish[i]='T';                                
a[no++]=i;     
for (j=0;j<m; j++)                           
work[j]=work[j]+allocation[i][j]; 
available[j] =work[j];                      
}                    
}                 
} 
k--;  
}while(k>0);            
f=1;        
for (i=0;i<n; i++)               
{  
if (finish[i]=='F')             
{                 
f=0; 
break;              
}          
}  
if (f==0)                    
{  
printf("����ȫ״̬��\n"); 
anquan=0;           
} 
else           
{    
printf("���ڰ�ȫ״̬."); 
printf("��ȫ���к�:"); 
for (i=0;i<n;i++)  
printf ("%d ",a[i]);         
printf("\n");  
printf("����");   
printf("   ");   
printf("  Max  ");   
printf("   ");   
printf("allocation");   
printf("    ");   
printf("need");   
printf("    ");   
printf("available");   
printf("\n");  
for (i=0;i<n; i++)                
{ 
printf("%2d",i); 
printf("     "); 
for(j=0;j<m; j++)  
printf("%2d",max[i][j]); 
printf("     "); 
for(j=0;j<m; j++)  
printf("%2d",allocation[i][j]); 
printf("     "); 
for(j=0;j<m; j++)  
printf("%2d",need[i][j]); 
printf("     ");      
for(j=0;j<m; j++)
{      
if(i>0)      
break;     
printf("%2d",available[j]);     
} 
printf("\n");               
}           
}    
}
