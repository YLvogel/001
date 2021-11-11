#include<stdio.h>
#include<stdlib.h>
#define v 4
void Init(int (&Matrix)[v][v])//初始化矩阵
{
	int i=0,j=0;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			Matrix[i][j] = 0;
		}
	}
}
void Enter(int (&Matrix)[v][v])//输入矩阵
{
	int i=0,j=0;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			scanf("%d",&Matrix[i][j]);
		}
	}
	//return En_Matrix;
}
void Mult_Matrix(int (&En_Matrix)[v][v],int (&Matrix)[v][v])//矩阵乘法
{
	int i = 0,j = 0,k = 0; 
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				Matrix[k][i]+=En_Matrix[k][j]*En_Matrix[j][i];
			}
		}
	}
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			En_Matrix[i][j]=Matrix[i][j];
		}
	}
}
int Comparison(int (&Matrix1)[v][v],int (&Matrix2)[v][v])//比较两个矩阵是否相等
{
	int i = 0,j = 0;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(Matrix1[i][j]!=Matrix2[i][j])
			return 1;
			else return 0;
		}
	}
}
void Disply(int (&Matrix)[v][v])//输出矩阵图
{
	int i=0,j=0;
	printf("------------\n");
	for(i=0;i<v;i++)
	{
		printf("|");
		for(j=0;j<v;j++)
		{
			printf("%d ",Matrix[i][j]);
		}
		printf("|\n");
	}
	printf("------------\n");
}
void Result(int Out_Matrix[][v])//计算长度为4的通路个数
{
	int i=0,j=0,res=0;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			res+=Out_Matrix[i][j];
		}
	}
	printf("%d\n",res);
}
void Trans(int (&Matrix)[v][v])//得到可达矩阵 
{
	int i=0,j=0,res=0;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(Matrix[i][j])
			Matrix[i][j]=1;
		}
	}
}
int main()
{
	int En_Matrix[v][v],path4 = 0,Out_Matrix[v][v],tmp[v][v];
	Init(En_Matrix);//初始化数组
	Init(Out_Matrix);//初始化数组
	Init(tmp);//初始化数组
	printf("Please enter the matrix\n");
	Enter(En_Matrix);//输入矩阵
	printf("The original matrix is\n"); 
	Disply(En_Matrix);//输出原始矩阵图 
	Mult_Matrix(En_Matrix,tmp);//得到A2
	Mult_Matrix(En_Matrix,Out_Matrix);//得到A4
	printf("\nA4 is\n");
	Disply(Out_Matrix);//输出A4 
	printf("\nThe result is\n");
	Result(Out_Matrix);//长度为4的通路个数 
	while(1)//循环矩阵乘法直到矩阵不再变化 
	{
		Init(tmp);
		Mult_Matrix(En_Matrix,tmp);
		if(!Comparison(En_Matrix,tmp))
		break;
	}
	Trans(En_Matrix);
	printf("The reachable matrix is\n");
	Disply(En_Matrix); 
	return 0;
} 
