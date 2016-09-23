// StackQueueAndString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "zxp_stack.h"
#include "zxp_queue.h"
#include "zxp_string.h"
int _tmain(int argc, _TCHAR* argv[])
{
	// 共享栈测试
	/*CBothStack<int> bothStack;
	for (int i = 0; i<5; i++)
	{
		bothStack.Push(1,i);
		bothStack.Push(2,i);
	}
	bothStack.PrintStack();*/
	// 链栈测试
	/*CLinkStack<int> linkStack;
	for (int i = 0; i<10; i++)
	{
		linkStack.Push(i);
	}
	for (int j = 0; j<10;j++)
	{
		int nValue = linkStack.Pop();
		printf("%d, ", nValue);
	}*/
	// 循环队列测试
	/*CCirQueue<int> MyCirQueue;
	for (int i = 0; i<9; i++)
	{
		MyCirQueue.EnQueue(i);
		if ((i != 0) && (i % 3) == 0)
		{
			MyCirQueue.DeQueue();
		}
	}
	while (!MyCirQueue.Empty())
	{
			printf("%d, ", MyCirQueue.DeQueue());
	}*/

	// 链队列测试
	/*CLinkQueue<int> MyLinkQueue;
	for (int i = 0; i<15; i++)
	{
		MyLinkQueue.EnQueue(i);
	}
	while (!MyLinkQueue.Empty())
	{
			printf("%d, ",MyLinkQueue.DeQueue());
	}
	for (int i = 0; i<15; i++)
	{
		MyLinkQueue.EnQueue(i);
	}*/

	// 朴素模式匹配算法测试
	/*char S[] = "abcdekdefgh";
	char T[] = "def";
	int n = BF(S, T);
	printf("%d\r\n", n);*/


	// KMP算法测试
	int i;
	int next[20]={0};
	char T[] = "ababxbababcadfdsss";
	char P[] = "abcad";
	printf("%s\n",T);
	printf("%s\n",P );
	makeNext(P,next);
	kmp(T,P,next);
	for (i = 0; i < strlen(P); ++i)
	{
			 printf("%d ",next[i]);
	}
	printf("\n");
	getchar();
	return 0;
}

