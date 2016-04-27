#ifndef _PLAYER             /*条件编译，防止重复包含的错误*/
	#define_PLAYER
	#include<string.h>
	#defineNUM20/*定义球员人数常量，此处可以根据实际需要修改常量值*/
	struct Player                   /*球员统计的数据域*/
	{
			longnum;
			char name[20];
			char nation[10];
			int score[3];
			int total;
	};
	typedefstruct Player Player;
	#definesizePlasizeof(Player)      /*一个球员记录所需要的内存空间大小*/
	intreadPla(Player Pla[],int n);       /*读入球员记录值，读满规定条数记录时停止*/
	voidprintPla(Player  *pla , int n);   /*输出所有球员记录的值*/
	
	intequal(Player s1,Player s2,int condition);  /*根据condition条件判断两个Player类型数据相等否*/
	intlarger(Player s1，Player s2,int condition);  /*根据condition比较Player类型数据大小*/
	voidreverse(Player pla[],int n);             /*球员记录数组元素逆置*/
	
	voidcalcuTotal(Player pla[],int n);           /*计算球队的总分*/
	voidcalcuscore(double m[3][3],Player pla[],int n); /*求得分，助攻，篮板的最高、最低、平均，m数组第一维*/
	/*表示哪类数据，第二维表示最高、最低、平均*/
	
	voidsortPla(Player pla[],intn,int condition);   /*选择法从小到大排序，按condition所规定的条件*/
	
	intsearchPla(Player pla[],intn,Players,intcondition,int f[]) ;  /*根据条件找数组中与s相等的各元素*/
	/*下标置于f数组中，设f数组是因为查找结果可能不止一条记录*/
	intinsertPla(Player stu[],intn,Player s);                   /*向数组中插入一个元素按学号有序*/
	intdeletePla(Player stu[],intn,Player s);                   /*从数组中删除一个指定学号的元素*/
	#endif

