#include <stdio.h>
#include "ZHKU.h"
#include "string.h"//�ַ�������ͷ�ļ�
#include <iostream>//c++��׼���������
using namespace std;
#include "conio.h"//getch()
#include <stdlib.h>//������C��C++���Ե����ֱ������͡�һЩ���ͨ�ù��ߺ�����

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
		cout<<"\n������������"<<M.nownode<<endl;
		cout<<"\n\t\t----------------------��ʼ����ͼ�ɹ�----------------------\n";
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
						printf("\n\n\t\t��ѡ����㣨0��%d����",M.nownode - 1);
						scanf("%d",&x);						
					}
					while(x >= M.nownode || x< 0);
					do
					{
						printf("\t\t��ѡ���յ㣨0��%d����",M.nownode - 1);
						scanf("%d",&y);						
					}
					while(y >= M.nownode || y < 0);
					calculation(x);
					caloutput(x,y);
					printf("\n\n\t\t\t\t�밴�س�������...\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
		case'2':{
					do
					{
						printf("\n\n\t\t������Ҫ��ѯ�ľ�����ţ�0��%d����\n",M.nownode - 1);
						scanf("%d",&n);						
					}
					while(n >= M.nownode || n<0 );
					description(n);
					printf("\n\n\t\t\t\t�밴�س�������...\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
		case'4':{
					changemap();
					printf("\n\n\t\t\t\t�밴�س�������...\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
		case'3':{
			     	cout<<"\n\t\tԭʼ��ͼ·�߸������£�"<<endl;
					ZHKUmap();
					printf("\n\n\t\t\t\t�밴�س�������...\n");
					getchar();
					getchar();
					system("cls");
					break;
				}
		}	
	}while(choose != 'r');
	cout<<"\n\t\t������뱣���¼�밴�٣��������밴'0'"<<endl;
	scanf("%d",&marksign);
	if(marksign)
	{
		mark=fopen("E:\\ZHKU\\mark.txt","r+");
		fprintf(mark,"%d",marksign);
		fclose(mark);
		cout<<"\t\t�����¼�ɹ���"<<endl;
		getch();
	}
	else
	{
		mark=fopen("E:\\ZHKU\\mark.txt","r+");
		fprintf(mark,"%d",marksign);
		fclose(mark);
		cout<<"\t\t�������¼��"<<endl;
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
		printf("\t\t\t|     �� ��������·��             |\n");
		printf("\t\t\t|     �� �鵼������Ϣ             |\n");
		printf("\t\t\t|     �� У԰����ͼ               |\n");
		printf("\t\t\t|     �� �޸�У԰��ͼ             |\n");
		printf("\t\t\t|     �� �˳�(�밴'r')            |\n");
		printf("\t\t\t|                               |\n");
		printf("\t\t\t--------------------------------\n");
		printf("\t\t\t\t����������ѡ��");
		chos=getch();
		if(chos == '1' || chos == '2'|| chos == '3' || chos == '4' || chos == 'r' )
				menu=0;
	}
	while(menu);
	return chos;//��c��Ϊ���ص�������ִ���ض�����
}

void ZHKUmap()
{
	cout<<endl;
	printf("\t\t               ������   \n");
	printf("\t\t                 |       \n"); 
	printf("\t\t                 |       \n"); 
	printf("\t\t                ������   \n");
	printf("\t\t                 |       \n");
	printf("\t\t                 |       \n");
	printf("\t\t                 |       \n");
	printf("\t\t               ��������    \n");
	printf("\t\t                 \        \n");
	printf("\t\t                  \        \n");
	printf("\t\t                   \        \n");
	printf("\t\t     22������--------\       \n");
	printf("\t\t        \           �·���       \n");
	printf("\t\t       �๦�ܷ��� --/ �u�v          \n");
	printf("\t\t          \         /  �v          \n");
	printf("\t\t           \       /    \          \n");
	printf("\t\t       ��������--       \         \n");
	printf("\t\t            \             \         \n");
	printf("\t\t             \             \         \n");
	printf("\t\t              \             \         \n");
	printf("\t\t               \             \         \n");
	printf("\t\t                ----------- ǰ��             \n");
	printf("\t\t                             |                \n");
	printf("\t\t                          �ɷ���                  \n");
	printf("\t\t                             |         \n");
	printf("\t\t                             |          \n");
	printf("\t\t              -----------1-6������       \n");
	printf("\t\t              |              |         \n");
	printf("\t\t              |              |         \n");
	printf("\t\t              |              |        \n");
	printf("\t\t            С����----------����          \n");
	printf("\t\t                             |       \n");
	printf("\t\t                             |      \n");
	printf("\t\t                          ����       \n");
	printf("\t\t                            |    \n");
	printf("\t\t                          ����         \n");
	printf("\t\t                            |      \n");
	printf("\t\t                          ����          \n");

}

void Createnode(int v)
{
	int i,j;
	M.nownode=v;

	for(i = 0;i < M.nownode;i++)
		M.vnode[i].number=i;

	strcpy(M.vnode[0].sight,"������");
	strcpy(M.vnode[1].sight,"������");
	strcpy(M.vnode[2].sight,"��������");
	strcpy(M.vnode[3].sight,"22������");
	strcpy(M.vnode[4].sight,"�๦�ܷ���");
	strcpy(M.vnode[5].sight,"�·���");
	strcpy(M.vnode[6].sight,"��������");
	strcpy(M.vnode[7].sight,"ǰ��");
	strcpy(M.vnode[8].sight,"�ɷ���");
	strcpy(M.vnode[9].sight,"1-6������");
	strcpy(M.vnode[10].sight,"����");
	strcpy(M.vnode[11].sight,"С����");
	strcpy(M.vnode[12].sight,"����");
	strcpy(M.vnode[13].sight,"����");
	strcpy(M.vnode[14].sight,"����");


	strcpy(M.vnode[0].description,"���ƹٷ����ţ��ѽ��ã������˳���");
	strcpy(M.vnode[1].description,"Ϊ����ΰ�󰮹���������");
	strcpy(M.vnode[2].description,"Ϊ�����һ��У��������");
	strcpy(M.vnode[3].description,"��Ҫס����Ϊ20���Զ��������뾭óѧ��");
	strcpy(M.vnode[4].description,"�㶫��ÿ��ķ���֮һ");
	strcpy(M.vnode[5].description,"ZHKU���ĵ��巹��");
	strcpy(M.vnode[6].description,"����һ�����򳡣������������ڴ˾ٰ�");
	strcpy(M.vnode[7].description,"��Ҫ�����ǰ��");
	strcpy(M.vnode[8].description,"���óԵĵ�Ҷ����⣬���˺óԣ��Լ۱Ƚϸ�");
	strcpy(M.vnode[9].description,"��Ů������Ϊ�������Լ�ªһ�������");
	strcpy(M.vnode[10].description,"��ȥ������վ���ͺ�����ʳ��");
	strcpy(M.vnode[11].description,"���������Ҫ��ڴ˾���");
	strcpy(M.vnode[12].description,"ZHKUΨһ���򳡣������Ҫ�ڴ˽���");
	strcpy(M.vnode[13].description,"��4������");
	strcpy(M.vnode[14].description,"��4�����򳡣����ܲ����˸���ѧԺ����Ӻ������ǳ�����");

	nodemassage=fopen("E:\\ZHKU\\nodemassage.txt","r+");//�������ĵĽڵ���Ϣ�����save_vex.txt�ļ�
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

	for(i=0;i<MAXNUM;i++)//�ڵ���·��ֵ
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
	printf("\t\t��Ҫ��ѯ�ľ�����Ϣ���£�\n");
	printf("\t\t(%d)%s��%s\n",d,M.vnode[d].sight,M.vnode[d].description);
	for(i=0;i<M.nownode;i++)
		if(M.arc[d][i] < 65535 && M.arc[d][i] > 0)
			nnew[j++]=i;
	j--;
	for(;j>=0;j--)
	{
		printf("\t\t(%d)\"%s\"��(%d)\"%s\"ֱ������������Ϊ��%d(m)\n",d,M.vnode[d].sight,nnew[j],M.vnode[nnew[j]].sight,M.arc[d][nnew[j]]);
	}
}

void calculation(int mynum)
{
	int i,j,x,y;
	int lastdata[MAXNUM];//�Ƿ�ȷ�����·����1ȷ��
	for(i = 0;i < M.nownode;i++)
	{
		lastdata[i]=0;
		minrou[i]=M.arc[mynum][i];//��¼��ǰ���·������
		bef[i]=0;//ֱ��ǰ���������
	}
	minrou[mynum]=0;
	lastdata[mynum]=1;//����ȷ��

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
		lastdata[y]=1;//kΪ��ȷ����̾���
		for(j = 0;j < M.nownode;j++)//ѭ�������޸ĵ���̾���
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
	while(short_dis[y] != 0)//�ж�ǰ��
	{
		x = bef[x];
		short_dis[++y] = x;
	}
		printf("\t\t��\"%s\"��\"%s\"�����·���ǣ�",M.vnode[fr].sight,M.vnode[end].sight);
		printf("%s",M.vnode[fr].sight);
		for(;short_dis[y-1]!=0 && (y-1)>=0;y--)
		{
			printf("->%s",M.vnode[short_dis[y-1]].sight);
		}
		printf("->%s",M.vnode[end].sight);
	printf("\n");
	printf("\t\tԤ��·��Ϊ��%d(m)",minrou[end]);
	cout<<endl;
}

void guidance()
{
	int i,j,sum=1;
	if(marksign)//�ж��Ƿ�ʹ����ʷ����
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
			fscanf(nodemassage,"%d %s %s\n",&M.vnode[i].number,M.vnode[i].sight,M.vnode[i].description);//����ȡ���Ľڵ���Ϣд��ͼG
			if(M.vnode[i].number!=0)
			{
			sum++;//����ͼ�Ľڵ������sum�ĳ�ֵΪ1
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
				fscanf(nodemub,"%d  ",&M.arc[i][j]);//����ȡ���ı���Ϣд��ͼG
			}
		}
		fclose(nodemub);
		printf("\n\t\t----------ZHKU����ũҵ����ѧԺУ԰����ϵͳ----------\n");
		printf("\t\t---------------------------------------------------------\n");
		printf("\t\t���ε����\t|���ε�����\n");
		printf("\t\t---------------------------------------------------------\n");
		for(i = 0;i < M.nownode;i++)
		{
			printf("\t\t%d\t\t|%s\n",M.vnode[i].number,M.vnode[i].sight);
		}
		cout<<"��ȡ��ʷ���ε�����"<<M.nownode<<endl;
		printf("\n\t\t---------------------�����Ѵ������ε�ɹ�---------------------\n");
		printf("\n\t\t---------------------ZHKU����ͼ�˵�--------------------------\n");
	}
	else
	{
		printf("\n\t\t----------ZHKU����ũҵ����ѧԺУ԰����ϵͳ----------\n");
		printf("\t\t---------------------------------------------------------\n");
		printf("\t\t���ε����\t|���ε�����\n");
		printf("\t\t---------------------------------------------------------\n");
		for(i = 0;i < M.nownode;i++)
		{
			printf("\t\t%d\t\t|%s\n",M.vnode[i].number,M.vnode[i].sight);
		}
		cout<<endl;
		printf("\n\t\t---------------------ZHKU����ͼ�˵�----------------------\n");
	}
}

void changemap()
{
	char passw[7];
	int x = 3,y = 0,signn = 1,flag = 1;
	while(x>0 && flag)
	{
		cout<<endl<<"\t\t����Ա����:"<<"(ʣ�����):"<<x<<endl;
		x--;
		scanf("%s",passw);
		if(strcmp(passw,ID)==0)
		{
			cout<<"\t\t������������������������������\n";
			cout<<"\t\t|   ��֤�ɹ�   |"<<endl;
			cout<<"\t\t������������������������������\n";
			flag=0;
		}
		memset(passw,'\0',sizeof(passw));
		if(x == 0)
		{
			cout<<"������󣡣�"<<endl;
			getch();
			exit(1);
		}
	}
	cout<<endl;
	do
	{
		printf("\n\t\t����������������������������������������������\n");
		printf("\t\t|  �����ӵ��ε�--1'     |\n");
		printf("\t\t|  ���޸ĵ��ε���Ϣ--2  |\n");
		printf("\t\t|  ���˳�--0           |\n");
		printf("\t\t����������������������������������������������\n");
		scanf("%d",&signn);
		switch(signn)
		{
		case 1:
			{
				if(addnode()==0) cout<<"\n\t\t���ӵ��ε�ɹ�!"<<endl;
				else cout<<"\n\t\t����ʧ��!"<<endl;
				break;
			}
		case 2:
			{
				if(modifynode()==0) cout<<"\n\t\t�޸ĵ��ε�ɹ�!"<<endl;
				else cout<<"\n\t\t�޸�ʧ��!"<<endl;
				break;
			}
		}
	}while(signn);
}

int addnode()
{
	int i,j,x = 0,nnx[NUM],flag=1;
	char newsign[10],newd[50];
	cout<<"\t\t���ɼӵ��ε�����"<<(MAXNUM-M.nownode)<<endl;
	if(M.nownode > MAXNUM)//��Ч���ж�
		return 1;//����������1
		printf("\t\t���ӵ��ε����Ϊ��(%d) ",M.nownode);
		cout<<"\n\t\t��ӵĵ��ε����ƣ�"<<endl;
		scanf("%s",newsign);
		cout<<"\t\t��ӵĵ��ε�������"<<endl;
		scanf("%s",newd);
		M.vnode[M.nownode].number = M.nownode;
		strcpy(M.vnode[M.nownode].sight,newsign);
		strcpy(M.vnode[M.nownode].description,newd);
		for(i = 0;i < M.nownode + 1;i++)
			for(j = 0;j < M.nownode;j++)
			{
				if(i == M.nownode || j == M.nownode)
					M.arc[i][j] = M.arc[j][i] = MAXROU;//�ڵ�·����ֵ�����
			}
		do
		{
			cout<<"\t\t�µ��ε����ӵĵ��ε����()��"<<endl;
			scanf("%d",&nnx[x]);//������ӵĽڵ����
			cout<<"\t\t���ӵ��ε��·��(m)��"<<endl;
			scanf("%d",&M.arc[M.nownode][nnx[x]]);
			M.arc[nnx[x]][M.nownode]=M.arc[M.nownode][nnx[x]];//��·��ֵ
			x++;
			cout<<"\t\t�������·���밴--1������--0"<<endl;
			scanf("%d",&flag);
		}while(flag);
		cout<<"\t\t���ӵĵ��ε��ȫ����Ϣ��"<<endl;
		cout<<"\t\t���ε���ţ�"<<M.nownode<<endl;
		cout<<"\t\t���ε����ƣ�"<<newsign<<endl;
		cout<<"\t\t���ε�������"<<newd<<endl;
		x--;
		for(;x >= 0;x--)
		{
			printf("\t\t���ε�:(%d)%s<->(%d)%s\t���%d(m)\n\n",M.nownode,M.vnode[M.nownode].sight,nnx[x],M.vnode[nnx[x]].sight,M.arc[M.nownode][nnx[x]]);
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
		for(j = 0;j < M.nownode;j++)//д���ļ�
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
		for(i = 0;i < M.nownode;i++)//�����ӵĽڵ��·д���ļ���
			for(j = 0;j < M.nownode;j++)
			{
				fprintf(nodemub,"%d  ",M.arc[i][j]);
				if(j == M.nownode - 1)
				{
	            fprintf(nodemub,"%c%c",'\n','\r');
				}
			}
		fclose(nodemub);
	return 0;//��������0
}

int modifynode()
{
	int x,i,j,oter,newrou,fl = 1,flag;
	char signn[10],newd[50];
	printf("\n\t\t��Ҫ���ĵ��ε����ţ���0��%d��",M.nownode-1);
	scanf("%d",&x);
	if(x > M.nownode || x<0) return 1;
	printf("\n\t\t���ε���Ϣ��\n");
	printf("\t\t(%d)%s��%s\n",M.vnode[x].number,M.vnode[x].sight,M.vnode[x].description);
	cout<<"\t\t���ε������ƣ�"<<endl;
	scanf("%s",signn);
	strcpy(M.vnode[x].sight,signn);
	cout<<"\t\t���ε���������"<<endl;
	scanf("%s",newd);
	strcpy(M.vnode[x].description,newd);
	cout<<"\t\t�޸ĺ��ε���Ϣ��"<<endl;
	printf("\t\t(%d)%s��%s\n",x,M.vnode[x].sight,M.vnode[x].description);
	cout<<"���޸ľ����밴--1,����--0"<<endl;
	scanf("%d",&flag);
	while(fl && flag)
	{
		cout<<"\t\t��һ�����ε���ź��޸ĵľ��룺  (�磺1,100)"<<endl;
		scanf("%d,%d",&oter,&newrou);
		M.arc[oter][x] = M.arc[x][oter] = newrou;
		printf("\t\t(%d)%s��(%d)%s�ľ���Ϊ��%d��m��\n",x,M.vnode[x].sight,oter,M.vnode[oter].sight,M.arc[x][oter]);
		cout<<"\t\t�����޸ľ���--1,����--0��"<<endl;
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
