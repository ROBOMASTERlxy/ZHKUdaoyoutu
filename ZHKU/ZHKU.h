#ifndef _ZHKU_h_
#define _ZHKU_h_

#define NUM 15
#define MAXNUM 20
#define MAXROU 65535
#define ID "101010"

typedef struct VertexType
{
 int number;
 char sight[20];
 char description[100];
}VertexType;

typedef struct
{
 VertexType vnode[MAXNUM];
 int arc[MAXNUM][MAXNUM];
 int nownode;
}Map;

Map M;

FILE *nodemassage;
FILE *nodemub;
FILE *mark;

int marksign=0;
int minrou[MAXNUM];
int bef[MAXNUM];

char ZHKUMENU();
void ZHKUmap();
void Createnode(int v);
void description(int a);
void calculation(int num);
void caloutput(int fr,int end);
void guidance();
void changemap();
int addnode();
int modifynode();

#endif
