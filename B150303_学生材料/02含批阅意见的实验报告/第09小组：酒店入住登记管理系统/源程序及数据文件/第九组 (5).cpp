#include<windows.h>															/*头文件*/
#include <time.h>															/*头文件*/
#include <stdio.h>															/*头文件*/
#include <conio.h>															/*头文件*/
#include <string.h>															/*头文件*/
#include <stdlib.h>															/*头文件*/
# pragma comment (lib, "Winmm.lib")
void Checkin( );															/*函数原型声明*/
void Delete();
void modify();
void Room();
void informationservices( );
void ReadInfo();
void WriteInfo();
void dqsj();
void bjyy();


struct Check																/*定义客户结构体*/
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
struct Check guests[600];													/*声明客户数组及客户数量*/
int nums=0;
int searchbyroom(char no[])													/*通过房间号码返回数组下标*/
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
int searchbyname(char Name[])												/*通过姓名返回数组下标*/
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
void display()																/*显示所有客户信息*/
{	
	system("cls");
	int i;
	do
	{
		system("cls");
		printf("\n\n   房号        姓名        性别        身份证号        \n");
		printf("-----------------------------------------------------------\n");
		for(i=0;i<nums;i++)
		printf("%10s%10s%10s%20s\n\n",guests[i].room,guests[i].name,guests[i].sex,guests[i].id);
		printf("-----------------------------------------------------------\n\n");
		printf("              返回主界面按回车键");
	}
	while (getchar()=='N'||getchar()=='n');

system("cls");
}
void displaysingle(int index)												/*显示单条客户信息*/
{
	printf("\n\n   房号        姓名        性别        身份证号        \n");
	printf("-----------------------------------------------------------\n");
	printf("   %10s%10s%10s%20s\n\n",guests[index].room,guests[index].name,guests[index].sex,guests[index].id);
	printf("-----------------------------------------------------------\n\n");
}
void main( )																/*主程序*/							
{
	bjyy();
   ReadInfo();
   while(1)
  {
	int m,b,x,h;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	dqsj();
	printf("\n\n\t\t------------欢迎来到**酒店-----------\n\n");			/*主菜单*/
	printf("\t\t\t 1. 增加客户记录\n\n");
	printf("\t\t\t 2. 修改客户记录\n\n");
	printf("\t\t\t 3. 删除客户记录\n\n");
	printf("\t\t\t 4. 客户房间查询 \n\n");
	printf("\t\t\t 5. 客户信息查询 \n\n");  
	printf("\t\t\t 6. 输出所有客户 \n\n");
	printf("\t\t\t 0. 退出管理系统 \n\n");

	printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\t\t\t 请选择您所需的服务: ");
    scanf("%d",&m);
	system("cls");
	switch(m)
	{
	case 1:																	/*增加客户记录*/
		{
			system("cls");
			dqsj();
			while(1)
			{
				printf("\t\t   \n");
				printf("      ********        编号        房号        价格        ********\n");
				printf("*************************************************************************\n");
				printf("*************************************************************************\n");
				printf("      ********         1         单人间      150/夜       ********\n");
				printf("      ********         2         双人间      200/夜       ********\n");
				printf("      ********         3         标准间      300/夜       ********\n");
				printf("      ********         4         总统套房    600/夜       ********\n");
				printf("*************************************************************************\n");
				printf("*************************************************************************\n");
				printf("\t\t   \n");
				printf("              请选择预订种类的编号 1--4:");
				scanf("%d",&b);
				if(b>0&&b<5)
					break;
				else
				{
					system("cls");
					printf("\n\n          您的输入有错请您重新输入！\n");
				}
			}
			getchar();
			switch(b)
			{
				case 1:														/*单人间*/
					printf("              请输入预订天数:");
					scanf("%d",&x);
					printf("\n");
					printf("              预交款为%d元\n",x*150);
					printf("              1.确定       2.返回");
					scanf("%d",&h);
					printf("\n");
					  switch(h)
					  {case 1:
					{
						   
					       printf("              您已成功预订！\n");
						   printf("\n");
						   printf("可选房间列表   101--120\n");
						     Checkin();
					   }
					      
					break;
					  case 2:break;}
					  system("cls");
					  break;
				case 2:														/*双人间*/
					printf("              请输入预订天数:");
					scanf("%d",&x);
					printf("\n");
					printf("              预交款为%d元\n",x*200);
					printf("              1.确定       2.返回");
					scanf("%d",&h);
					printf("\n");
					 switch(h)
					 {case 1:
						{
						   
					       printf("              您已成功预订！\n");
						   printf("\n");
						   printf("可选房间列表   201--220\n");
						     Checkin();
					   }
					      
					break;
					 case 2:break;}
					 system("cls");
					 break;
				case 3:														/*标准间*/
					printf("              请输入预订天数:");
					scanf("%d",&x);
					printf("\n");
					printf("              预交款为%d元\n",x*300);
					printf("              1.确定       2.返回");
					scanf("%d",&h);
					 switch(h)
					 {case 1:
						{
						  
					       printf("              您已成功预订！\n");
						   printf("\n");
						   printf("可选房间列表   301--320\n");
						     Checkin();
					   }
					      
					break;
					 case 2:break;}
					 system("cls");
					 break;
				case 4:														/*总统套房*/
					printf("              请输入预订天数:");
					scanf("%d",&x);
					printf("\n");
					printf("              预交款为%d元\n",x*600);
					printf("              1.确定       2.返回");
					scanf("%d",&h);
					printf("\n");
				 switch(h)
				 {
				   case 1:
					   {
						   
					       printf("              您已成功预订！\n");
						   printf("\n");
						   printf("可选房间列表   401--420\n");
						     Checkin();
					   }
					       break;
				 case 2:break;}
				 system("cls");
				 break;
			}
			
		}break;
	case 2:modify();break;													/*修改客户记录*/
	case 3:Delete();break;													/*删除客户记录*/
	case 4:Room();break;													/*按客户房间查询*/
	case 5:informationservices( );break;									/*按客户信息查询*/
	case 6:display();break;													/*输出所有客户信息*/
	case 0:exit(0);															/*退出系统*/
	default:printf("           您输入有误，请重新输入");
		system("cls");}														/*清屏*/
	WriteInfo();}
	getchar();
}
void Checkin( )																/*插入客户信息*/
{
	char a;
 while(1)
 {
	printf("\n");
	printf("              请输入房号:");
	scanf("%s",guests[nums].room);
	getchar();
	printf("\n");
	printf("              请输入姓名:");
	scanf("%s",guests[nums].name);
	getchar();
	printf("\n");
	printf("              请输入性别:");
	scanf("%s",guests[nums].sex);
	getchar();
	printf("\n");
	printf("              请输入身份证号:");
	scanf("%s",guests[nums].id);
	while(strlen(guests[nums].id)!=18)
	{
		printf("              请输入18位身份证号:");
		scanf("%s",guests[nums].id);
	}
	getchar();
	nums++;
	printf("\n");
	printf("              是否继续？请输入y/n");
	scanf("%s",&a);
	if(a=='n'||a=='N')
			break;
	}
 system("cls");
}	
void modify()																/*修改客户信息*/
{
	char a;
	while(1)
	{
		dqsj();
		char no[20];
		int index;
		printf("\n请输入要修改的客户的房号:");
		scanf("%s",no);
		getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("该客户不存在！\n");
		else
		{
			system("cls");
			printf("你要修改的客户信息为:\n");
			displaysingle(index);
			printf("--- 请输入新值 ---\n\n");
			printf("请输入房号:");
			scanf("%s",guests[index].room);
			getchar();
			printf("请输入姓名:");
			scanf("%s",guests[index].name);
			getchar();
			printf("      请输入性别:");
			scanf("%s",guests[nums].sex);
			getchar();
			printf("      请输入身份证号:");
			scanf("%s",guests[nums].id);
			while(strlen(guests[nums].id)!=18)
			{
				printf("      请输入18位身份证号:");
				scanf("%s",guests[nums].id);
			}
			getchar();
		}
		printf("    是否继续？(请输入y/n)\n");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void Delete()																/*删除客户信息*/
{
	char a;
	int i;
	while(1)
	{
		dqsj();
		char no[20];
		int index;
		printf("\n请输入要删除的客户的房号:");
		scanf("%s",no);
		getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("该房间无客户居住！\n");
		else
		{
			system("cls");
			printf("你要删除的客户信息为:\n");
			displaysingle(index);
			printf("--- 是否真的要删除 (y/n)---\n");
			if(getchar()=='y')
			{
				for(i=index;i<nums-1;i++)
					guests[i]=guests[i+1];
				nums--;
			}
			getchar();
		}
		printf("    是否继续？请输入y/n\n");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void Room()																	/*按房间号码查询*/
{
	dqsj();
	while(1)
	{
		char no[20];
		char index;
		char a;
		printf("请输入要查询的房间号码:\n ");
		scanf("%s",no);
		 getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("该房间为空！\n");
		else
		{
			system("cls");
			printf("\t\t你要查询的客户信息为：\n");
            displaysingle(index);
		}
		printf("是否继续？（y/n)");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void informationservices( )													/*按姓名查询*/
{
	dqsj();
	while(1)
	{
		char Name[20];
		int  index;
		char a;
		printf("\t##########请输入您的姓名##########\n\n");
		scanf("%s",Name);
		getchar();
		index=searchbyname(Name);
		if(index==-1)
			printf("该用户不存在！\n");
		else
		{
			system("cls");
			printf("\t您要查询的客户信息为\n");
			displaysingle(index);
		}
		printf("是否继续？y/n\n");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void dqsj()																	/*显示北京时间*/  
    {  
        char * wday[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};  
        time_t t;  
        struct tm *p;  
        t = time(NULL);  
        p = gmtime(&t);  
        printf("现在是北京时间：");   
        printf("%d年%2d月%2d日", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);  
        printf(" %s ", wday[p->tm_wday]);  
        printf("%02d:%02d:%02d\n", (8+p->tm_hour), p->tm_min, p->tm_sec);    
    }
void bjyy()  
    {  
		sndPlaySound("You Took My Heart Away 无损.wav",SND_ASYNC);          /*播放背景音乐*/ 
    }    

void ReadInfo()																/*将客户信息从文件读出*/
{	FILE *fp;
	int i;
	if((fp=fopen("D://CXSJ.txt","rb"))==NULL)
	{
		printf("无文件信息!\n");
		return;
	}
	if(fread(&nums,sizeof(int),1,fp)!=1)
		nums=-1;
	else
		for(i=0;i<nums;i++)
			fread(&guests[i],sizeof(struct Check),1,fp);
		fclose(fp);															/*关闭文件*/
}
void WriteInfo()															/*将客户信息写入文件*/
{
	FILE *fp;
	int i;
	if((fp=fopen("D://CXSJ.txt","wb"))==NULL)
	{
		printf("无文件信息!\n");
		return;
	}
	if(fwrite(&nums,sizeof(int),1,fp)!=1)
		printf("写入文件错误!\n");
	for(i=0;i<nums;i++)
		if(fwrite(&guests[i],sizeof(struct Check),1,fp)!=1)
			printf("写入文件错误！\n");
	fclose(fp);																/*关闭文件*/
}
