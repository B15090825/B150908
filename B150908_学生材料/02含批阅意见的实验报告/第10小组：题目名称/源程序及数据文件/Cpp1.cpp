#ifndef _PLAYER             /*�������룬��ֹ�ظ������Ĵ���*/
	#define_PLAYER
	#include<string.h>
	#defineNUM20/*������Ա�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
	struct Player                   /*��Աͳ�Ƶ�������*/
	{
			longnum;
			char name[20];
			char nation[10];
			int score[3];
			int total;
	};
	typedefstruct Player Player;
	#definesizePlasizeof(Player)      /*һ����Ա��¼����Ҫ���ڴ�ռ��С*/
	intreadPla(Player Pla[],int n);       /*������Ա��¼ֵ�������涨������¼ʱֹͣ*/
	voidprintPla(Player  *pla , int n);   /*���������Ա��¼��ֵ*/
	
	intequal(Player s1,Player s2,int condition);  /*����condition�����ж�����Player����������ȷ�*/
	intlarger(Player s1��Player s2,int condition);  /*����condition�Ƚ�Player�������ݴ�С*/
	voidreverse(Player pla[],int n);             /*��Ա��¼����Ԫ������*/
	
	voidcalcuTotal(Player pla[],int n);           /*������ӵ��ܷ�*/
	voidcalcuscore(double m[3][3],Player pla[],int n); /*��÷֣��������������ߡ���͡�ƽ����m�����һά*/
	/*��ʾ�������ݣ��ڶ�ά��ʾ��ߡ���͡�ƽ��*/
	
	voidsortPla(Player pla[],intn,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/
	
	intsearchPla(Player pla[],intn,Players,intcondition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
	/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
	intinsertPla(Player stu[],intn,Player s);                   /*�������в���һ��Ԫ�ذ�ѧ������*/
	intdeletePla(Player stu[],intn,Player s);                   /*��������ɾ��һ��ָ��ѧ�ŵ�Ԫ��*/
	#endif

