#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define PRINT(X) printf("arr["#X"]=%d\n",rand())

int main()
{
	int arr[10] = { 0 };
	srand((unsigned)time(NULL));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		/*arr[i] = rand();
		printf("arr%d\n", arr[i]);*/
		int j = i;
		PRINT(i);
	}

	return 0;
}

#define PRINT(X) printf("the value of " #X " is %d\n",X)

int main()
{
	int a = 10;
	int b = 20;
	PRINT(a);// printf("the value of " "a" " is %d\n",X);
	PRINT(b);// printf("the value of " "b" " is %d\n",X);
	return 0;
}

#define MAX(X,Y)  ((X)>(Y)?(X):(Y))
int main()
{
	int a = 10;
	int b = 11;
	int max1 = MAX(a, b);
	int max2 = MAX(a++, b++);	// ���и����õĺ����	+1û�У�++��
		�����ȫ�滻:
			   ((a++)>(b++)	?	(a++)	:	(b++))
				  11	12    ��ִ��a11		  ��ʹ��12����max����++���13����b
	printf("%d\n", max1);
	printf("%d\n", max2);
	printf("%d\n", a);
	printf("%d\n", b);

	return 0;
}

 ����
int Max1(int x, int y)
{
	return ((x > y ? x : y));
}
float Max2(float x, float y)	// �ڵ��úͷ���ʱ���ж��⿪������Ϊ���������ʱ�䳤
{			//	������������Ϊ�ض�������
	return ((x > y ? x : y));
}
 ��
#define MAX(X,Y)  ((X)>(Y)?(X):(Y))
		�˴��ŵ�:1.��ģ���ٶȸ���	2.��Ϊ��ֱ���滻�����������޹�
					3.��������Գ������ͣ�����������
#define SIZEOF(type) sizeof(type)
int main()
{
	int ret = SIZEOF(int);
	printf("%d ", ret);
	return 0;
}
 
#define MALLOC(num,type) malloc(num*sizeof(type))
int main()
{
	int* p1 = malloc(10 * sizeof(int));

	int* p2 = MALLOC(10, int);
	���ߵȼۣ��Һ������
	return 0;
}
	ȱ��:
		1.ÿ��ʹ�ú꣬���궨��Ĵ�������������궨��Ĵ���ǳ���������ܻ������ӳ��򳤶�
		2.���޷�����
	test.c	- ����+���� -> test.exe����
		  Ԥ����  ��ʱ�Ѿ��Ѻ�������滻,�޷�������ĵ���
		3.�������������޹أ����Բ����Ͻ�
		4.������ڴ������ʽ������������ͺ�����������˳��һ��������ܳ���
		5.���ܵݹ�
int main()
{
	int a = 10;
	int b = 20;
	float c = 10.0;
	float d = 20.0;
	int max1 = Max1(a, b);
	float max2 = Max2(a, b);
	printf("%d\n", max1);
	printf("%f\n", max2);
	printf("%d\n", MAX(a, b));
	printf("%f\n", MAX(c, d));

	return 0;
}

#define MAX 100
int main()
{
	printf("%d ", MAX);
	return 0;
}
#undef MAX 100
  #undef �Ƴ�һ���궨��
int main()
{
	printf("%d ", MAX);	//	δ����
	return 0;
}