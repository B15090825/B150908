#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"play.h"

voidprintHead( )      /*��ӡ��Ա��Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","��Ա��","����","����","�÷�","����","����");
}

voidmenu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ��Ա����ͳ�ƹ��� ********\n");
		printf("******** 4. ��Ա����ͳ�� ********\n");
printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

voidmenuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ������Ա��¼%%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ա��¼%%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ա��¼%%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵�%%%%%%%%\n");
}

voidmenuScore( )     /*3����Ա��Ϣ����˵�����*/
{
		printf("@@@@@@@@ 1. ��������ܷ� @@@@@@@@\n");

		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}

voidmenuCount( )    /*4����Ա����ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ����Ա��߷�&&&&&&&&\n");
		printf("&&&&&&&& 2. ����Ա�������&&&&&&&&\n");
		printf("&&&&&&&& 3. ����Ա�������&&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵�&&&&&&&&\n");
}

voidmenuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. ��������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

intbaseManage(Playerpla[],int n)    	/*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
		intchoice,t,find[NUM];
Player s;
do
{	
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	/*����ѡ��*/
		switch(choice)
}
			case1:	readPla(&s,1);       /*����һ�����������Ա��¼*/
					 n=insertPla(stu,n,s);   /*���ú���������Ա��¼*/
					break;
			case2:  printf("Input the number deleted\n");
					scanf("%ld",&s.num);  /*����һ����ɾ������Ա���*/
					 n=deletePla(pla,n,s);   /*���ú���ɾ��ָ����ŵ���Ա��¼*/
					break;
			case3:  printf("Input the number modified\n");
					scanf("%ld",&s.num);  /*����һ�����޸ĵ���Ա���*/
				      t=searchPla(pla,n,s,1,find) ; /*���ú�������ָ����ŵ���Ա��¼*/
				if (t)                 /*�������ŵļ�¼����*/
					 {
						readPla(&s,1);   /*����һ����������Ա��¼��Ϣ*/
					pla[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/					
					  }					
					else/*�������ŵļ�¼������*/
printf("this palyer is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					break;
			case0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

voidscoreManage(Playerpla[],int n)          /*�ú��������Ա����ͳ�ƹ�����*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	/*�������ѡ��*/
		switch(choice)
		{
			case1:   calcuTotal(pla,n);         /*��ӵ��ܵ÷�*/
					break;

						
			case0:   break;
		}
	}while(choice);
}

voidprintscore(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��ߵ÷֡�������塢�������*/
inti;
printf(s);                                  /*�����s������������������ʾ��Ϣ*/
for (i=0;i<3;i++)                           /*i������һ������*/
		printf("%10.2lf",m[i][k]);
	printf("\n");
}

voidcountManage(Playerpla[],int n)               /*�ú�����ɿ��Գɼ�ͳ�ƹ���*/
{
		int choice;
		doublescore[3][3];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuscorek(score,pla,n);                 /*���ô˺�����������������*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case1:   printScore("��߷ֱַ���:\n",score,0);  /*�����ߵ÷�*/
				break;
				case2:   printScore("����������:\n",score,1);  /*����������*/
				break;
				case3:   printScore("�����������:\n",score,2);  /*����������*/
				break;
				case0:   break;
			}
		}while (choice);
}

voidsearchManage(Playerpla[],int n)               /*�ú�����ɸ���������ѯ����*/
{
inti,choice,findnum,f[NUM];
Player s;
	do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case1:   printf("Input a player\'s num will be searched:\n");
				scanf("%ld",&s.num);         /*�������ѯ��Ա�����*/
					break;
				case2:   printf("Input a player\'s name will be searched:\n");
				scanf("%s",s.name);	/*�������ѯ��Ա������*/		
				break;   
				case3:   printf("Input a nation will be searched:\n");
				scanf("%d",&s.nation);          /*�������ѯ��Ա�Ĺ���*/
					break;
				case0:   break;
			}
			if (choice>=1&&choice<=3)
			{ 
				findnum=searchPla(pla,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				/*������ҳɹ�*/
				{
					printHead( );                  /*��ӡ��ͷ*/
					for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
		printPla(&pla[f[i]],1);      /*ÿ�����һ����¼*/
				}
				else
				printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

intrunMain(Playerpla[],intn,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case1: printHead( );           /* 1. ��ʾ������Ϣ*/
				sortPla(pla,n,1);         /*��ѧ����С�����˳�������¼*/
	printStu(pla,n);          /*�������С�����˳��������м�¼*/
					break;
			case2: n=baseManage(pla,n);    /* 2. ������Ϣ����*/
				break;
			case3: scoreManage(pla,n);     /* 3. ��Ա����ͳ�ƹ���*/
					break;
			case4: countManage(pla,n);     /* 4. ��Ա����ͳ��*/
					break;
			case5: searchManage(pla,n);     /* 5. ����������ѯ*/
				break;
case0: break;
		}
		return n;
}

intmain( )
{
		Playerpla[NUM];                /*����ʵ��һά����洢��Ա��¼*/
intchoice,n;
	 n=readFile(pla);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(pla);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}		
	do
	     {
	menu();                      /*��ʾ���˵�*/
	printf("Please input your choice: ");
	scanf("%d",&choice);
	if (choice>=0&&choice<=5)
	              n=runMain(pla,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	else
		printf("error input,please input your choice again!\n");
	} while (choice);
	sortPla(pla,n,1);                   /*�����ļ�ǰ�������С��������*/
	saveFile(pla,n);                   /*����������ļ�*/
return0;
}
