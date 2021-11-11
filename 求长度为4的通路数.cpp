#include<stdio.h>
#include<stdlib.h>
#define v 4
void Init(int (&Matrix)[v][v])//��ʼ������
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
void Enter(int (&Matrix)[v][v])//�������
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
void Mult_Matrix(int (&En_Matrix)[v][v],int (&Matrix)[v][v])//����˷�
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
int Comparison(int (&Matrix1)[v][v],int (&Matrix2)[v][v])//�Ƚ����������Ƿ����
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
void Disply(int (&Matrix)[v][v])//�������ͼ
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
void Result(int Out_Matrix[][v])//���㳤��Ϊ4��ͨ·����
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
void Trans(int (&Matrix)[v][v])//�õ��ɴ���� 
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
	Init(En_Matrix);//��ʼ������
	Init(Out_Matrix);//��ʼ������
	Init(tmp);//��ʼ������
	printf("Please enter the matrix\n");
	Enter(En_Matrix);//�������
	printf("The original matrix is\n"); 
	Disply(En_Matrix);//���ԭʼ����ͼ 
	Mult_Matrix(En_Matrix,tmp);//�õ�A2
	Mult_Matrix(En_Matrix,Out_Matrix);//�õ�A4
	printf("\nA4 is\n");
	Disply(Out_Matrix);//���A4 
	printf("\nThe result is\n");
	Result(Out_Matrix);//����Ϊ4��ͨ·���� 
	while(1)//ѭ������˷�ֱ�������ٱ仯 
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
