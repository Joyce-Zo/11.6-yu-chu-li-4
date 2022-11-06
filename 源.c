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
	int max2 = MAX(a++, b++);	// 带有副作用的宏参数	+1没有，++有
		宏的完全替换:
			   ((a++)>(b++)	?	(a++)	:	(b++))
				  11	12    不执行a11		  先使用12传给max，后++变成13，即b
	printf("%d\n", max1);
	printf("%d\n", max2);
	printf("%d\n", a);
	printf("%d\n", b);

	return 0;
}

 函数
int Max1(int x, int y)
{
	return ((x > y ? x : y));
}
float Max2(float x, float y)	// 在调用和返回时会有额外开销，更为繁琐，相对时间长
{			//	参数必须声明为特定的类型
	return ((x > y ? x : y));
}
 宏
#define MAX(X,Y)  ((X)>(Y)?(X):(Y))
		此处优点:1.规模与速度更快	2.因为是直接替换，宏与类型无关
					3.宏参数可以出现类型，但函数不行
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
	二者等价，且宏更方便
	return 0;
}
	缺点:
		1.每次使用宏，将宏定义的代码插入程序，如果宏定义的代码非常长，则可能会大幅增加程序长度
		2.宏无法调试
	test.c	- 编译+链接 -> test.exe调试
		  预编译  此时已经把宏的内容替换,无法到后面的调试
		3.由于其与类型无关，所以不够严谨
		4.如果宏内传来表达式且其中运算符和宏的运算符操作顺序不一样，则可能出错
		5.不能递归
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
  #undef 移除一个宏定义
int main()
{
	printf("%d ", MAX);	//	未定义
	return 0;
}