#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string.h>
#define NUM 20                /*������Ա�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Player                   /*��Աͳ�Ƶ�������*/
{
		long num;
		char name[20];
		char nation[10];
		int score[3];
		int total;
};
typedef struct Player Player;
#define sizePla sizeof(Player)      /*һ����Ա��¼����Ҫ���ڴ�ռ��С*/
int readPla(Player Pla[],int n);       /*������Ա��¼ֵ�������涨������¼ʱֹͣ*/
void printPla(Player  *pla , int n);   /*���������Ա��¼��ֵ*/

int equal(Player s1,Player s2,int condition);  /*����condition�����ж�����Player����������ȷ�*/
int larger(Player s1,Player s2,int condition);  /*����condition�Ƚ�Player�������ݴ�С*/
void reverse(Player pla[],int n);             /*��Ա��¼����Ԫ������*/

void calcuTotal(Player pla[],int n);           /*������ӵ��ܷ�*/
void calcuScore(double m[3][3],Player pla[],int n); /*��÷֣��������������ߡ���͡�ƽ����m�����һά*/
/*��ʾ�������ݣ��ڶ�ά��ʾ��ߡ���͡�ƽ��*/

void sortPla(Player pla[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchPla(Player pla[],int n,Player s,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertPla(Player stu[],int n,Player s);                   /*�������в���һ��Ԫ�ذ�ѧ������*/
int deletePla(Player stu[],int n,Player s);                   /*��������ɾ��һ��ָ��ѧ�ŵ�Ԫ��*/



#endif // PLAYER_H_INCLUDED
