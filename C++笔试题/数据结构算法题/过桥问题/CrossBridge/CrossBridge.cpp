// CrossBridge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/* 问题描述:
四个人步行速度分别为1,2,5,10分钟.做多两人一起过桥,且过桥时必须持有手电筒.
所以必须有人把手电筒带回来.两人同行以步行慢的为准,请问最短多少分钟过桥.*/
// 分析:
// 先建立一个递增的有序数组.
int array[] = {1,2,5,10};
// 取前两个先过河,
int crossBridge(int array[], int nLen)
{
}

int BinarySearch(int array[], int K, int n)
{
	int nMiddle = n/2;
	if (nMiddle == 0)
	{
		return -1;
	}
	if (array[nMiddle] == K)
	{
		return nMiddle;
	}else if (array[nMiddle] > K)
	{
		return BinarySearch(array, K, nMiddle);
	}else
	{
		return BinarySearch(array+nMiddle+1, K, nMiddle)
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

