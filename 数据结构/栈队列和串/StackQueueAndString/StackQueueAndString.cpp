// StackQueueAndString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "zxp_stack.h"
#include "zxp_queue.h"
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
	CLinkQueue<int> MyLinkQueue;
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
	}



	getchar();
	return 0;
}

