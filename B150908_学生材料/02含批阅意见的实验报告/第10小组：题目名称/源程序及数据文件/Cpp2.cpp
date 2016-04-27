#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"play.h"

voidprintHead( )      /*打印球员信息的表头*/
{
printf("%8s%10s%8s%6s%6s%8s%6s%6s\n","球员号","姓名","国籍","得分","助攻","篮板");
}

voidmenu( )         /*顶层菜单函数*/
{
		printf("******** 1. 显示基本信息 ********\n");
		printf("******** 2. 基本信息管理 ********\n");
		printf("******** 3. 球员技术统计管理 ********\n");
		printf("******** 4. 球员技术统计 ********\n");
printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

voidmenuBase( )     /*2、基本信息管理菜单函数*/
{
		printf("%%%%%%%% 1. 插入球员记录%%%%%%%%\n");
		printf("%%%%%%%% 2. 删除球员记录%%%%%%%%\n");
		printf("%%%%%%%% 3. 修改球员记录%%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单%%%%%%%%\n");
}

voidmenuScore( )     /*3、球员信息管理菜单函数*/
{
		printf("@@@@@@@@ 1. 计算球队总分 @@@@@@@@\n");

		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}

voidmenuCount( )    /*4、球员技术统计菜单函数*/
{
		printf("&&&&&&&& 1. 求球员最高分&&&&&&&&\n");
		printf("&&&&&&&& 2. 求球员最高篮板&&&&&&&&\n");
		printf("&&&&&&&& 3. 求球员最高助攻&&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单&&&&&&&&\n");
}

voidmenuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按球号查询   ########\n");
		printf("######## 2. 按姓名查询   ########\n");
		printf("######## 3. 按国籍查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}

intbaseManage(Playerpla[],int n)    	/*该函数完成基本信息管理*/
/*按球号进行插入删除修改，球号不能重复*/
{  
		intchoice,t,find[NUM];
Player s;
do
{	
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	/*读入选项*/
		switch(choice)
}
			case1:	readPla(&s,1);       /*读入一条待插入的球员记录*/
					 n=insertPla(stu,n,s);   /*调用函数插入球员记录*/
					break;
			case2:  printf("Input the number deleted\n");
					scanf("%ld",&s.num);  /*读入一个待删除的球员球号*/
					 n=deletePla(pla,n,s);   /*调用函数删除指定球号的球员记录*/
					break;
			case3:  printf("Input the number modified\n");
					scanf("%ld",&s.num);  /*读入一个待修改的球员球号*/
				      t=searchPla(pla,n,s,1,find) ; /*调用函数查找指定球号的球员记录*/
				if (t)                 /*如果该球号的记录存在*/
					 {
						readPla(&s,1);   /*读入一条完整的球员记录信息*/
					pla[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/					
					  }					
					else/*如果该球号的记录不存在*/
printf("this palyer is not in,can not be modified.\n"); /*输出提示信息*/
					break;
			case0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

voidscoreManage(Playerpla[],int n)          /*该函数完成球员技术统计管理功能*/
{  
	int choice;
	do
	{
		menuScore( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	/*读入二级选项*/
		switch(choice)
		{
			case1:   calcuTotal(pla,n);         /*球队的总得分*/
					break;

						
			case0:   break;
		}
	}while(choice);
}

voidprintscore(char *s,double m[3][3],int k)   /*打印分数通用函数，被countManage调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应最高得分、最高篮板、最高助攻*/
inti;
printf(s);                                  /*这里的s传入的是输出分数的提示信息*/
for (i=0;i<3;i++)                           /*i控制哪一类数据*/
		printf("%10.2lf",m[i][k]);
	printf("\n");
}

voidcountManage(Playerpla[],int n)               /*该函数完成考试成绩统计功能*/
{
		int choice;
		doublescore[3][3];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuscorek(score,pla,n);                 /*调用此函数求三项的最高数据*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case1:   printScore("最高分分别是:\n",score,0);  /*输出最高得分*/
				break;
				case2:   printScore("最高篮板分是:\n",score,1);  /*输出最高篮板*/
				break;
				case3:   printScore("最高助攻分是:\n",score,2);  /*输出最高助攻*/
				break;
				case0:   break;
			}
		}while (choice);
}

voidsearchManage(Playerpla[],int n)               /*该函数完成根据条件查询功能*/
{
inti,choice,findnum,f[NUM];
Player s;
	do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case1:   printf("Input a player\'s num will be searched:\n");
				scanf("%ld",&s.num);         /*输入待查询球员的球号*/
					break;
				case2:   printf("Input a player\'s name will be searched:\n");
				scanf("%s",s.name);	/*输入待查询球员的姓名*/		
				break;   
				case3:   printf("Input a nation will be searched:\n");
				scanf("%d",&s.nation);          /*输入待查询球员的国籍*/
					break;
				case0:   break;
			}
			if (choice>=1&&choice<=3)
			{ 
				findnum=searchPla(pla,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				/*如果查找成功*/
				{
					printHead( );                  /*打印表头*/
					for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
		printPla(&pla[f[i]],1);      /*每次输出一条记录*/
				}
				else
				printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

intrunMain(Playerpla[],intn,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case1: printHead( );           /* 1. 显示基本信息*/
				sortPla(pla,n,1);         /*按学号由小到大的顺序排序记录*/
	printStu(pla,n);          /*按球号由小到大的顺序输出所有记录*/
					break;
			case2: n=baseManage(pla,n);    /* 2. 基本信息管理*/
				break;
			case3: scoreManage(pla,n);     /* 3. 球员技术统计管理*/
					break;
			case4: countManage(pla,n);     /* 4. 球员技术统计*/
					break;
			case5: searchManage(pla,n);     /* 5. 根据条件查询*/
				break;
case0: break;
		}
		return n;
}

intmain( )
{
		Playerpla[NUM];                /*定义实参一维数组存储球员记录*/
intchoice,n;
	 n=readFile(pla);                  /*首先读取文件，记录条数返回赋值给n*/
	if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(pla);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}		
	do
	     {
	menu();                      /*显示主菜单*/
	printf("Please input your choice: ");
	scanf("%d",&choice);
	if (choice>=0&&choice<=5)
	              n=runMain(pla,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	else
		printf("error input,please input your choice again!\n");
	} while (choice);
	sortPla(pla,n,1);                   /*存入文件前按球号由小到大排序*/
	saveFile(pla,n);                   /*将结果存入文件*/
return0;
}
