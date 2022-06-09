#include <stdio.h>
#include "ZHKU.h"
#include "string.h"//字符串函数头文件
#include <iostream>//c++标准输入输出流
using namespace std;
#include "conio.h"//getch()
#include <stdlib.h>//定义了C，C++语言的五种变量类型、一些宏和通用工具函数。

int main()
{
	int x,y,n;
	char choose;
	mark=fopen("E:\\ZHKU\\mark.txt","r+");
		if(mark==NULL) 
	{
		cout<<"mark.txt is NULL"<<endl;
		getch();
        exit(1);
	}
	fscanf(mark,"%d",&marksign);
	if(marksign==0)
	{
		Createnode(NUM);
		cout<<"\n创建景点数："<<M.nownode<<endl;
		cout<<"\n\t\t----------------------初始化地图成功----------------------\n";
	}
	fclose(mark);
	do
	{
	guidance();
	choose = ZHKUMENU();
	switch(choose)
		{
		case'1':{
					do
					{
						printf("\n\n\t\t请选择起点（0～%d）：",M.nownode - 1);
						scanf("%d",&x);						
					}
					while(x >= M.nownode || x< 0);
					do
					{
						printf("\t\t请选择终点（0～%d）：",M.nownode - 1);
						scanf("%d",&y);						
					}
					while(y >= M.nownode || y < 0);
					calculation(x);
					caloutput(x,y);
					printf("\n\n\t\t\t\t请按回车键继续...\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
		case'2':{
					do
					{
						printf("\n\n\t\t请输入要查询的景点序号（0～%d）：\n",M.nownode - 1);
						scanf("%d",&n);						
					}
					while(n >= M.nownode || n<0 );
					description(n);
					printf("\n\n\t\t\t\t请按回车键继续...\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
		case'4':{
					changemap();
					printf("\n\n\t\t\t\t请按回车键继续...\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
		case'3':{
			     	cout<<"\n\t\t原始地图路线概览如下："<<endl;
					ZHKUmap();
					printf("\n\n\t\t\t\t请按回车键继续...\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
		}	
	}while(choose != 'r');
	cout<<"\n\t\t如果您想保存记录请按①，不保存请按'0'"<<endl;
	scanf("%d",&marksign);
	if(marksign)
	{
		mark=fopen("E:\\ZHKU\\mark.txt","r+");
		fprintf(mark,"%d",marksign);
		fclose(mark);
		cout<<"\t\t保存记录成功！"<<endl;
		getch();
	}
	else
	{
		mark=fopen("E:\\ZHKU\\mark.txt","r+");
		fprintf(mark,"%d",marksign);
		fclose(mark);
		cout<<"\t\t不保存记录！"<<endl;
		getch();
	}
}

char ZHKUMENU()
{
	char chos;
	int menu;
	do
	{
		menu=1;
		printf("\n\t\t\t--------------------------------\n");
		printf("\t\t\t|                               |\n");
		printf("\t\t\t|     ① 导航最优路径             |\n");
		printf("\t\t\t|     ② 查导航点信息             |\n");
		printf("\t\t\t|     ③ 校园导航图               |\n");
		printf("\t\t\t|     ④ 修改校园地图             |\n");
		printf("\t\t\t|     ● 退出(请按'r')            |\n");
		printf("\t\t\t|                               |\n");
		printf("\t\t\t--------------------------------\n");
		printf("\t\t\t\t请输入您的选择：");
		chos=getch();
		if(chos == '1' || chos == '2'|| chos == '3' || chos == '4' || chos == 'r' )
				menu=0;
	}
	while(menu);
	return chos;//将c作为返回到主函数执行特定功能
}

void ZHKUmap()
{
	cout<<endl;
	printf("\t\t               大正门   \n");
	printf("\t\t                 |       \n"); 
	printf("\t\t                 |       \n"); 
	printf("\t\t                仲恺像   \n");
	printf("\t\t                 |       \n");
	printf("\t\t                 |       \n");
	printf("\t\t                 |       \n");
	printf("\t\t               何香凝像    \n");
	printf("\t\t                 \        \n");
	printf("\t\t                  \        \n");
	printf("\t\t                   \        \n");
	printf("\t\t     22栋宿舍--------\       \n");
	printf("\t\t        \           新饭堂       \n");
	printf("\t\t       多功能饭堂 --/ ╱╲          \n");
	printf("\t\t          \         /  ╲          \n");
	printf("\t\t           \       /    \          \n");
	printf("\t\t       鸟笼篮球场--       \         \n");
	printf("\t\t            \             \         \n");
	printf("\t\t             \             \         \n");
	printf("\t\t              \             \         \n");
	printf("\t\t               \             \         \n");
	printf("\t\t                ----------- 前门             \n");
	printf("\t\t                             |                \n");
	printf("\t\t                          旧饭堂                  \n");
	printf("\t\t                             |         \n");
	printf("\t\t                             |          \n");
	printf("\t\t              -----------1-6栋宿舍       \n");
	printf("\t\t              |              |         \n");
	printf("\t\t              |              |         \n");
	printf("\t\t              |              |        \n");
	printf("\t\t            小礼堂----------后门          \n");
	printf("\t\t                             |       \n");
	printf("\t\t                             |      \n");
	printf("\t\t                          足球场       \n");
	printf("\t\t                            |    \n");
	printf("\t\t                          网球场         \n");
	printf("\t\t                            |      \n");
	printf("\t\t                          排球场          \n");

}

void Createnode(int v)
{
	int i,j;
	M.nownode=v;

	for(i = 0;i < M.nownode;i++)
		M.vnode[i].number=i;

	strcpy(M.vnode[0].sight,"大正门");
	strcpy(M.vnode[1].sight,"仲恺像");
	strcpy(M.vnode[2].sight,"何香凝像");
	strcpy(M.vnode[3].sight,"22栋宿舍");
	strcpy(M.vnode[4].sight,"多功能饭堂");
	strcpy(M.vnode[5].sight,"新饭堂");
	strcpy(M.vnode[6].sight,"鸟笼篮球场");
	strcpy(M.vnode[7].sight,"前门");
	strcpy(M.vnode[8].sight,"旧饭堂");
	strcpy(M.vnode[9].sight,"1-6栋宿舍");
	strcpy(M.vnode[10].sight,"后门");
	strcpy(M.vnode[11].sight,"小礼堂");
	strcpy(M.vnode[12].sight,"足球场");
	strcpy(M.vnode[13].sight,"网球场");
	strcpy(M.vnode[14].sight,"排球场");


	strcpy(M.vnode[0].description,"白云官方正门，已建好，可少人出入");
	strcpy(M.vnode[1].description,"为纪念伟大爱国者廖仲恺");
	strcpy(M.vnode[2].description,"为纪念第一任校长何香凝");
	strcpy(M.vnode[3].description,"主要住宿者为20届自动化先生与经贸学生");
	strcpy(M.vnode[4].description,"广东最好看的饭堂之一");
	strcpy(M.vnode[5].description,"ZHKU第四第五饭堂");
	strcpy(M.vnode[6].description,"仅有一个篮球场，许多篮球比赛在此举办");
	strcpy(M.vnode[7].description,"主要出入的前门");
	strcpy(M.vnode[8].description,"许多好吃的店家都在这，便宜好吃，性价比较高");
	strcpy(M.vnode[9].description,"以女生宿舍为主，是稍简陋一点的宿舍");
	strcpy(M.vnode[10].description,"可去菜鸟驿站，和后门美食街");
	strcpy(M.vnode[11].description,"当下许多重要活动在此举行");
	strcpy(M.vnode[12].description,"ZHKU唯一足球场，许多活动都要在此进行");
	strcpy(M.vnode[13].description,"有4个网球场");
	strcpy(M.vnode[14].description,"有4个排球场，四周布置了各个学院排球队海报，非常气派");

	nodemassage=fopen("E:\\ZHKU\\nodemassage.txt","r+");//将创建的的节点信息输出到save_vex.txt文件
	if(nodemassage==NULL) 
	{
		cout<<"nodemassage.txt is NULL"<<endl;
		getch();
        exit(1);
	}
	for(i = 0;i < M.nownode;i++)
	{
		fprintf(nodemassage,"%d %s %s\n",M.vnode[i].number,M.vnode[i].sight,M.vnode[i].description);
	}
	fclose(nodemassage);

	for(i=0;i<MAXNUM;i++)//节点间道路的值
	{
		for(j=0;j<MAXNUM;j++)
		{
			M.arc[i][j]=MAXROU;
		}
	}

	M.arc[0][1] = M.arc[1][0] = 100;
	M.arc[1][2] = M.arc[2][1] = 200;
	M.arc[2][3] = M.arc[3][2] = 150;
	M.arc[2][5] = M.arc[5][2] = 150;
	M.arc[3][4] = M.arc[4][3] = 50;
	M.arc[3][5] = M.arc[5][3] = 150;
	M.arc[4][5] = M.arc[5][4] = 100;
	M.arc[4][6] = M.arc[6][4] = 150;
	M.arc[5][6] = M.arc[6][5] = 100;
	M.arc[5][7] = M.arc[7][5] = 200;
	M.arc[6][7] = M.arc[7][6] = 150;
	M.arc[7][8] = M.arc[8][7] = 20;
	M.arc[8][9] = M.arc[9][8] = 70;
	M.arc[9][10] = M.arc[10][9] = 70;
	M.arc[9][11] = M.arc[11][9] = 180;
	M.arc[10][11] = M.arc[11][10] = 60;
	M.arc[10][12] = M.arc[12][10] = 20;
	M.arc[12][13] = M.arc[13][12] = 10;
	M.arc[13][14] = M.arc[14][13] = 10;

	nodemub=fopen("E:\\ZHKU\\nodemub.txt","r+");
	if(nodemub==NULL) 
	{
		cout<<"nodemub.txt is NULL"<<endl;
		getch();
        exit(1);
	}
	for(i = 0;i < M.nownode;i++)
	{
		for(j = 0;j < M.nownode;j++)
		{
			fprintf(nodemub,"%d  ",M.arc[i][j]);
			if(j == M.nownode - 1)
	            fprintf(nodemub,"%c%c",'\n','\r');
		}
	}
	fclose(nodemub);
}

void description(int d)
{
	int i,j=0,nnew[NUM];
	printf("\t\t您要查询的景点信息如下：\n");
	printf("\t\t(%d)%s：%s\n",d,M.vnode[d].sight,M.vnode[d].description);
	for(i=0;i<M.nownode;i++)
		if(M.arc[d][i] < 65535 && M.arc[d][i] > 0)
			nnew[j++]=i;
	j--;
	for(;j>=0;j--)
	{
		printf("\t\t(%d)\"%s\"与(%d)\"%s\"直接相连，距离为：%d(m)\n",d,M.vnode[d].sight,nnew[j],M.vnode[nnew[j]].sight,M.arc[d][nnew[j]]);
	}
}

void calculation(int mynum)
{
	int i,j,x,y;
	int lastdata[MAXNUM];//是否确定最短路径，1确定
	for(i = 0;i < M.nownode;i++)
	{
		lastdata[i]=0;
		minrou[i]=M.arc[mynum][i];//记录当前最短路径长度
		bef[i]=0;//直接前驱顶点序号
	}
	minrou[mynum]=0;
	lastdata[mynum]=1;//自身确定

	for(i = 1;i < M.nownode;i++)
	{
		x=MAXROU;
		for(j = 0;j < M.nownode;j++)
		{
			if(!lastdata[j] && (minrou[j] < x))
			{
				y = j;
				x = minrou[j];
			}
		}
		lastdata[y]=1;//k为已确定最短距离
		for(j = 0;j < M.nownode;j++)//循环继续修改的最短距离
		{
			if(!lastdata[j] && (x + M.arc[y][j] < minrou[j]))
			{
				minrou[j] = x + M.arc[y][j];
				bef[j] = y;
			} 
		}
	}
}

void caloutput(int fr,int end)
{
	int x=bef[end],y=0,short_dis[NUM]={0};
	short_dis[y] = bef[end];
	while(short_dis[y] != 0)//判断前驱
	{
		x = bef[x];
		short_dis[++y] = x;
	}
		printf("\t\t从\"%s\"到\"%s\"的最短路线是：",M.vnode[fr].sight,M.vnode[end].sight);
		printf("%s",M.vnode[fr].sight);
		for(;short_dis[y-1]!=0 && (y-1)>=0;y--)
		{
			printf("->%s",M.vnode[short_dis[y-1]].sight);
		}
		printf("->%s",M.vnode[end].sight);
	printf("\n");
	printf("\t\t预计路程为：%d(m)",minrou[end]);
	cout<<endl;
}

void guidance()
{
	int i,j,sum=1;
	if(marksign)//判断是否使用历史数据
	{
		nodemassage=fopen("E:\\ZHKU\\nodemassage.txt","r+");
		if(nodemassage==NULL) 
		{
			cout<<"nodemassage.txt is NULL"<<endl;
			getch();
		    exit(1);
		}
		for(i = 0;i < MAXNUM;i++)
		{
			fscanf(nodemassage,"%d %s %s\n",&M.vnode[i].number,M.vnode[i].sight,M.vnode[i].description);//将读取到的节点信息写入图G
			if(M.vnode[i].number!=0)
			{
			sum++;//计算图的节点个数，sum的初值为1
			}
		}
		M.nownode = sum;
		fclose(nodemassage);

		nodemub = fopen("E:\\ZHKU\\nodemub.txt","r+");
		if(nodemub == NULL) 
		{
			cout<<"nodemub.txt is NULL"<<endl;
			getch();
		    exit(1);
		}
		for(i = 0;i < M.nownode;i++)
		{
			for(j = 0;j < M.nownode;j++)
			{
				fscanf(nodemub,"%d  ",&M.arc[i][j]);//将读取到的边信息写入图G
			}
		}
		fclose(nodemub);
		printf("\n\t\t----------ZHKU仲恺农业工程学院校园导游系统----------\n");
		printf("\t\t---------------------------------------------------------\n");
		printf("\t\t导游点序号\t|导游点名称\n");
		printf("\t\t---------------------------------------------------------\n");
		for(i = 0;i < M.nownode;i++)
		{
			printf("\t\t%d\t\t|%s\n",M.vnode[i].number,M.vnode[i].sight);
		}
		cout<<"读取历史导游点数："<<M.nownode<<endl;
		printf("\n\t\t---------------------载入已创建导游点成功---------------------\n");
		printf("\n\t\t---------------------ZHKU导游图菜单--------------------------\n");
	}
	else
	{
		printf("\n\t\t----------ZHKU仲恺农业工程学院校园导游系统----------\n");
		printf("\t\t---------------------------------------------------------\n");
		printf("\t\t导游点序号\t|导游点名称\n");
		printf("\t\t---------------------------------------------------------\n");
		for(i = 0;i < M.nownode;i++)
		{
			printf("\t\t%d\t\t|%s\n",M.vnode[i].number,M.vnode[i].sight);
		}
		cout<<endl;
		printf("\n\t\t---------------------ZHKU导游图菜单----------------------\n");
	}
}

void changemap()
{
	char passw[7];
	int x = 3,y = 0,signn = 1,flag = 1;
	while(x>0 && flag)
	{
		cout<<endl<<"\t\t管理员密码:"<<"(剩余次数):"<<x<<endl;
		x--;
		scanf("%s",passw);
		if(strcmp(passw,ID)==0)
		{
			cout<<"\t\t━━━━━━━━━━━━━━━\n";
			cout<<"\t\t|   验证成功   |"<<endl;
			cout<<"\t\t━━━━━━━━━━━━━━━\n";
			flag=0;
		}
		memset(passw,'\0',sizeof(passw));
		if(x == 0)
		{
			cout<<"密码错误！！"<<endl;
			getch();
			exit(1);
		}
	}
	cout<<endl;
	do
	{
		printf("\n\t\t━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("\t\t|  ①增加导游点--1'     |\n");
		printf("\t\t|  ②修改导游点信息--2  |\n");
		printf("\t\t|  ③退出--0           |\n");
		printf("\t\t━━━━━━━━━━━━━━━━━━━━━━━\n");
		scanf("%d",&signn);
		switch(signn)
		{
		case 1:
			{
				if(addnode()==0) cout<<"\n\t\t增加导游点成功!"<<endl;
				else cout<<"\n\t\t增加失败!"<<endl;
				break;
			}
		case 2:
			{
				if(modifynode()==0) cout<<"\n\t\t修改导游点成功!"<<endl;
				else cout<<"\n\t\t修改失败!"<<endl;
				break;
			}
		}
	}while(signn);
}

int addnode()
{
	int i,j,x = 0,nnx[NUM],flag=1;
	char newsign[10],newd[50];
	cout<<"\t\t最多可加导游点数："<<(MAXNUM-M.nownode)<<endl;
	if(M.nownode > MAXNUM)//有效性判断
		return 1;//不正常返回1
		printf("\t\t增加导游点序号为：(%d) ",M.nownode);
		cout<<"\n\t\t添加的导游点名称："<<endl;
		scanf("%s",newsign);
		cout<<"\t\t添加的导游点描述："<<endl;
		scanf("%s",newd);
		M.vnode[M.nownode].number = M.nownode;
		strcpy(M.vnode[M.nownode].sight,newsign);
		strcpy(M.vnode[M.nownode].description,newd);
		for(i = 0;i < M.nownode + 1;i++)
			for(j = 0;j < M.nownode;j++)
			{
				if(i == M.nownode || j == M.nownode)
					M.arc[i][j] = M.arc[j][i] = MAXROU;//节点路径赋值无穷大
			}
		do
		{
			cout<<"\t\t新导游点连接的导游点序号()："<<endl;
			scanf("%d",&nnx[x]);//存放连接的节点序号
			cout<<"\t\t连接导游点的路程(m)："<<endl;
			scanf("%d",&M.arc[M.nownode][nnx[x]]);
			M.arc[nnx[x]][M.nownode]=M.arc[M.nownode][nnx[x]];//道路赋值
			x++;
			cout<<"\t\t继续添加路径请按--1，否则按--0"<<endl;
			scanf("%d",&flag);
		}while(flag);
		cout<<"\t\t增加的导游点的全部信息："<<endl;
		cout<<"\t\t导游点序号："<<M.nownode<<endl;
		cout<<"\t\t导游点名称："<<newsign<<endl;
		cout<<"\t\t导游点描述："<<newd<<endl;
		x--;
		for(;x >= 0;x--)
		{
			printf("\t\t导游点:(%d)%s<->(%d)%s\t相距%d(m)\n\n",M.nownode,M.vnode[M.nownode].sight,nnx[x],M.vnode[nnx[x]].sight,M.arc[M.nownode][nnx[x]]);
		}
		x=0;
		M.nownode++;
		nodemassage=fopen("E:\\ZHKU\\nodemassage.txt","r+");
		if(nodemassage==NULL) 
		{
			cout<<"nodemassage.txt is NULL"<<endl;
			getch();
		    exit(1);
		}
		for(j = 0;j < M.nownode;j++)//写入文件
		{
			fprintf(nodemassage,"%d %s %s\n",M.vnode[j].number,M.vnode[j].sight,M.vnode[j].description);
		}
		fclose(nodemassage);


		nodemub=fopen("E:\\ZHKU\\nodemub.txt","r+");
		if(nodemub==NULL) 
		{
			cout<<"nodemub.txt is NULL"<<endl;
			getch();
		    exit(1);
		}
		for(i = 0;i < M.nownode;i++)//将增加的节点道路写入文件中
			for(j = 0;j < M.nownode;j++)
			{
				fprintf(nodemub,"%d  ",M.arc[i][j]);
				if(j == M.nownode - 1)
				{
	            fprintf(nodemub,"%c%c",'\n','\r');
				}
			}
		fclose(nodemub);
	return 0;//正常返回0
}

int modifynode()
{
	int x,i,j,oter,newrou,fl = 1,flag;
	char signn[10],newd[50];
	printf("\n\t\t需要更改导游点的序号：（0～%d）",M.nownode-1);
	scanf("%d",&x);
	if(x > M.nownode || x<0) return 1;
	printf("\n\t\t导游点信息：\n");
	printf("\t\t(%d)%s：%s\n",M.vnode[x].number,M.vnode[x].sight,M.vnode[x].description);
	cout<<"\t\t导游点新名称："<<endl;
	scanf("%s",signn);
	strcpy(M.vnode[x].sight,signn);
	cout<<"\t\t导游点新描述："<<endl;
	scanf("%s",newd);
	strcpy(M.vnode[x].description,newd);
	cout<<"\t\t修改后导游点信息："<<endl;
	printf("\t\t(%d)%s：%s\n",x,M.vnode[x].sight,M.vnode[x].description);
	cout<<"若修改距离请按--1,否则按--0"<<endl;
	scanf("%d",&flag);
	while(fl && flag)
	{
		cout<<"\t\t另一个导游点序号和修改的距离：  (如：1,100)"<<endl;
		scanf("%d,%d",&oter,&newrou);
		M.arc[oter][x] = M.arc[x][oter] = newrou;
		printf("\t\t(%d)%s与(%d)%s的距离为：%d（m）\n",x,M.vnode[x].sight,oter,M.vnode[oter].sight,M.arc[x][oter]);
		cout<<"\t\t继续修改距离--1,否则--0："<<endl;
		scanf("%d",&fl);
	}

	nodemassage=fopen("E:\\ZHKU\\nodemassage.txt","r+");
	if(nodemassage==NULL) 
	{
		cout<<"nodemassage.txt is NULL"<<endl;
		getch();
        exit(1);
	}
	for(i = 0;i < M.nownode;i++)
	{
		fprintf(nodemassage,"%d %s %s\n",M.vnode[i].number,M.vnode[i].sight,M.vnode[i].description);
	}
	fclose(nodemassage);
	if(flag)
	{
		nodemub=fopen("E:\\ZHKU\\nodemub.txt","r+");
		if(nodemub==NULL) 
		{
			cout<<"nodemub.txt is NULL"<<endl;
			getch();
    	    exit(1);
		}
		for(i = 0;i < M.nownode;i++)
		{
			for(j = 0;j < M.nownode;j++)
			{
				fprintf(nodemub,"%d  ",M.arc[i][j]);
				if(j == M.nownode-1)
				{
					fprintf(nodemub,"%c%c",'\n','\r');
				}
			}
		}
		fclose(nodemub);
	}
	return 0;
}
