#include<windows.h>															/*ͷ�ļ�*/
#include <time.h>															/*ͷ�ļ�*/
#include <stdio.h>															/*ͷ�ļ�*/
#include <conio.h>															/*ͷ�ļ�*/
#include <string.h>															/*ͷ�ļ�*/
#include <stdlib.h>															/*ͷ�ļ�*/
# pragma comment (lib, "Winmm.lib")
void Checkin( );															/*����ԭ������*/
void Delete();
void modify();
void Room();
void informationservices( );
void ReadInfo();
void WriteInfo();
void dqsj();
void bjyy();


struct Check																/*����ͻ��ṹ��*/
{
	char id[20];											
	char name[20];												
	char sex[10];											
	char room[5];												
	char style[20] ;                                      	
	char  price[3];                                         	
    char  num[20];
	char  time[20];
	char checkintime[20];                                
};
struct Check guests[600];													/*�����ͻ����鼰�ͻ�����*/
int nums=0;
int searchbyroom(char no[])													/*ͨ��������뷵�������±�*/
{
	int i,k=1;
	for(i=0;i<nums;i++)
	{
		if(strcmp(guests[i].room,no)==0)
		{
			return i;
			k=0;
		}
	}
	if(k)
	{
		return -1;
	}else{
		return NULL;
	}
}
int searchbyname(char Name[])												/*ͨ���������������±�*/
{
	int i,k=1;
	for(i=0;i<nums;i++)
	{
		if(strcmp(guests[i].name,Name)==0)
		{
			return i;
			k=0;
		}
	}
	if(k)
	{
		return -1;
	}else{
		return NULL;
	}
}
void display()																/*��ʾ���пͻ���Ϣ*/
{	
	system("cls");
	int i;
	do
	{
		system("cls");
		printf("\n\n   ����        ����        �Ա�        ���֤��        \n");
		printf("-----------------------------------------------------------\n");
		for(i=0;i<nums;i++)
		printf("%10s%10s%10s%20s\n\n",guests[i].room,guests[i].name,guests[i].sex,guests[i].id);
		printf("-----------------------------------------------------------\n\n");
		printf("              ���������水�س���");
	}
	while (getchar()=='N'||getchar()=='n');

system("cls");
}
void displaysingle(int index)												/*��ʾ�����ͻ���Ϣ*/
{
	printf("\n\n   ����        ����        �Ա�        ���֤��        \n");
	printf("-----------------------------------------------------------\n");
	printf("   %10s%10s%10s%20s\n\n",guests[index].room,guests[index].name,guests[index].sex,guests[index].id);
	printf("-----------------------------------------------------------\n\n");
}
void main( )																/*������*/							
{
	bjyy();
   ReadInfo();
   while(1)
  {
	int m,b,x,h;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	dqsj();
	printf("\n\n\t\t------------��ӭ����**�Ƶ�-----------\n\n");			/*���˵�*/
	printf("\t\t\t 1. ���ӿͻ���¼\n\n");
	printf("\t\t\t 2. �޸Ŀͻ���¼\n\n");
	printf("\t\t\t 3. ɾ���ͻ���¼\n\n");
	printf("\t\t\t 4. �ͻ������ѯ \n\n");
	printf("\t\t\t 5. �ͻ���Ϣ��ѯ \n\n");  
	printf("\t\t\t 6. ������пͻ� \n\n");
	printf("\t\t\t 0. �˳�����ϵͳ \n\n");

	printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\t\t\t ��ѡ��������ķ���: ");
    scanf("%d",&m);
	system("cls");
	switch(m)
	{
	case 1:																	/*���ӿͻ���¼*/
		{
			system("cls");
			dqsj();
			while(1)
			{
				printf("\t\t   \n");
				printf("      ********        ���        ����        �۸�        ********\n");
				printf("*************************************************************************\n");
				printf("*************************************************************************\n");
				printf("      ********         1         ���˼�      150/ҹ       ********\n");
				printf("      ********         2         ˫�˼�      200/ҹ       ********\n");
				printf("      ********         3         ��׼��      300/ҹ       ********\n");
				printf("      ********         4         ��ͳ�׷�    600/ҹ       ********\n");
				printf("*************************************************************************\n");
				printf("*************************************************************************\n");
				printf("\t\t   \n");
				printf("              ��ѡ��Ԥ������ı�� 1--4:");
				scanf("%d",&b);
				if(b>0&&b<5)
					break;
				else
				{
					system("cls");
					printf("\n\n          ���������д������������룡\n");
				}
			}
			getchar();
			switch(b)
			{
				case 1:														/*���˼�*/
					printf("              ������Ԥ������:");
					scanf("%d",&x);
					printf("\n");
					printf("              Ԥ����Ϊ%dԪ\n",x*150);
					printf("              1.ȷ��       2.����");
					scanf("%d",&h);
					printf("\n");
					  switch(h)
					  {case 1:
					{
						   
					       printf("              ���ѳɹ�Ԥ����\n");
						   printf("\n");
						   printf("��ѡ�����б�   101--120\n");
						     Checkin();
					   }
					      
					break;
					  case 2:break;}
					  system("cls");
					  break;
				case 2:														/*˫�˼�*/
					printf("              ������Ԥ������:");
					scanf("%d",&x);
					printf("\n");
					printf("              Ԥ����Ϊ%dԪ\n",x*200);
					printf("              1.ȷ��       2.����");
					scanf("%d",&h);
					printf("\n");
					 switch(h)
					 {case 1:
						{
						   
					       printf("              ���ѳɹ�Ԥ����\n");
						   printf("\n");
						   printf("��ѡ�����б�   201--220\n");
						     Checkin();
					   }
					      
					break;
					 case 2:break;}
					 system("cls");
					 break;
				case 3:														/*��׼��*/
					printf("              ������Ԥ������:");
					scanf("%d",&x);
					printf("\n");
					printf("              Ԥ����Ϊ%dԪ\n",x*300);
					printf("              1.ȷ��       2.����");
					scanf("%d",&h);
					 switch(h)
					 {case 1:
						{
						  
					       printf("              ���ѳɹ�Ԥ����\n");
						   printf("\n");
						   printf("��ѡ�����б�   301--320\n");
						     Checkin();
					   }
					      
					break;
					 case 2:break;}
					 system("cls");
					 break;
				case 4:														/*��ͳ�׷�*/
					printf("              ������Ԥ������:");
					scanf("%d",&x);
					printf("\n");
					printf("              Ԥ����Ϊ%dԪ\n",x*600);
					printf("              1.ȷ��       2.����");
					scanf("%d",&h);
					printf("\n");
				 switch(h)
				 {
				   case 1:
					   {
						   
					       printf("              ���ѳɹ�Ԥ����\n");
						   printf("\n");
						   printf("��ѡ�����б�   401--420\n");
						     Checkin();
					   }
					       break;
				 case 2:break;}
				 system("cls");
				 break;
			}
			
		}break;
	case 2:modify();break;													/*�޸Ŀͻ���¼*/
	case 3:Delete();break;													/*ɾ���ͻ���¼*/
	case 4:Room();break;													/*���ͻ������ѯ*/
	case 5:informationservices( );break;									/*���ͻ���Ϣ��ѯ*/
	case 6:display();break;													/*������пͻ���Ϣ*/
	case 0:exit(0);															/*�˳�ϵͳ*/
	default:printf("           ��������������������");
		system("cls");}														/*����*/
	WriteInfo();}
	getchar();
}
void Checkin( )																/*����ͻ���Ϣ*/
{
	char a;
 while(1)
 {
	printf("\n");
	printf("              �����뷿��:");
	scanf("%s",guests[nums].room);
	getchar();
	printf("\n");
	printf("              ����������:");
	scanf("%s",guests[nums].name);
	getchar();
	printf("\n");
	printf("              �������Ա�:");
	scanf("%s",guests[nums].sex);
	getchar();
	printf("\n");
	printf("              ���������֤��:");
	scanf("%s",guests[nums].id);
	while(strlen(guests[nums].id)!=18)
	{
		printf("              ������18λ���֤��:");
		scanf("%s",guests[nums].id);
	}
	getchar();
	nums++;
	printf("\n");
	printf("              �Ƿ������������y/n");
	scanf("%s",&a);
	if(a=='n'||a=='N')
			break;
	}
 system("cls");
}	
void modify()																/*�޸Ŀͻ���Ϣ*/
{
	char a;
	while(1)
	{
		dqsj();
		char no[20];
		int index;
		printf("\n������Ҫ�޸ĵĿͻ��ķ���:");
		scanf("%s",no);
		getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("�ÿͻ������ڣ�\n");
		else
		{
			system("cls");
			printf("��Ҫ�޸ĵĿͻ���ϢΪ:\n");
			displaysingle(index);
			printf("--- ��������ֵ ---\n\n");
			printf("�����뷿��:");
			scanf("%s",guests[index].room);
			getchar();
			printf("����������:");
			scanf("%s",guests[index].name);
			getchar();
			printf("      �������Ա�:");
			scanf("%s",guests[nums].sex);
			getchar();
			printf("      ���������֤��:");
			scanf("%s",guests[nums].id);
			while(strlen(guests[nums].id)!=18)
			{
				printf("      ������18λ���֤��:");
				scanf("%s",guests[nums].id);
			}
			getchar();
		}
		printf("    �Ƿ������(������y/n)\n");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void Delete()																/*ɾ���ͻ���Ϣ*/
{
	char a;
	int i;
	while(1)
	{
		dqsj();
		char no[20];
		int index;
		printf("\n������Ҫɾ���Ŀͻ��ķ���:");
		scanf("%s",no);
		getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("�÷����޿ͻ���ס��\n");
		else
		{
			system("cls");
			printf("��Ҫɾ���Ŀͻ���ϢΪ:\n");
			displaysingle(index);
			printf("--- �Ƿ����Ҫɾ�� (y/n)---\n");
			if(getchar()=='y')
			{
				for(i=index;i<nums-1;i++)
					guests[i]=guests[i+1];
				nums--;
			}
			getchar();
		}
		printf("    �Ƿ������������y/n\n");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void Room()																	/*����������ѯ*/
{
	dqsj();
	while(1)
	{
		char no[20];
		char index;
		char a;
		printf("������Ҫ��ѯ�ķ������:\n ");
		scanf("%s",no);
		 getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("�÷���Ϊ�գ�\n");
		else
		{
			system("cls");
			printf("\t\t��Ҫ��ѯ�Ŀͻ���ϢΪ��\n");
            displaysingle(index);
		}
		printf("�Ƿ��������y/n)");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void informationservices( )													/*��������ѯ*/
{
	dqsj();
	while(1)
	{
		char Name[20];
		int  index;
		char a;
		printf("\t##########��������������##########\n\n");
		scanf("%s",Name);
		getchar();
		index=searchbyname(Name);
		if(index==-1)
			printf("���û������ڣ�\n");
		else
		{
			system("cls");
			printf("\t��Ҫ��ѯ�Ŀͻ���ϢΪ\n");
			displaysingle(index);
		}
		printf("�Ƿ������y/n\n");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void dqsj()																	/*��ʾ����ʱ��*/  
    {  
        char * wday[] = {"������", "����һ", "���ڶ�", "������", "������", "������", "������"};  
        time_t t;  
        struct tm *p;  
        t = time(NULL);  
        p = gmtime(&t);  
        printf("�����Ǳ���ʱ�䣺");   
        printf("%d��%2d��%2d��", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);  
        printf(" %s ", wday[p->tm_wday]);  
        printf("%02d:%02d:%02d\n", (8+p->tm_hour), p->tm_min, p->tm_sec);    
    }
void bjyy()  
    {  
		sndPlaySound("You Took My Heart Away ����.wav",SND_ASYNC);          /*���ű�������*/ 
    }    

void ReadInfo()																/*���ͻ���Ϣ���ļ�����*/
{	FILE *fp;
	int i;
	if((fp=fopen("D://CXSJ.txt","rb"))==NULL)
	{
		printf("���ļ���Ϣ!\n");
		return;
	}
	if(fread(&nums,sizeof(int),1,fp)!=1)
		nums=-1;
	else
		for(i=0;i<nums;i++)
			fread(&guests[i],sizeof(struct Check),1,fp);
		fclose(fp);															/*�ر��ļ�*/
}
void WriteInfo()															/*���ͻ���Ϣд���ļ�*/
{
	FILE *fp;
	int i;
	if((fp=fopen("D://CXSJ.txt","wb"))==NULL)
	{
		printf("���ļ���Ϣ!\n");
		return;
	}
	if(fwrite(&nums,sizeof(int),1,fp)!=1)
		printf("д���ļ�����!\n");
	for(i=0;i<nums;i++)
		if(fwrite(&guests[i],sizeof(struct Check),1,fp)!=1)
			printf("д���ļ�����\n");
	fclose(fp);																/*�ر��ļ�*/
}
