// CrossBridge.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/* ��������:
�ĸ��˲����ٶȷֱ�Ϊ1,2,5,10����.��������һ�����,�ҹ���ʱ��������ֵ�Ͳ.
���Ա������˰��ֵ�Ͳ������.����ͬ���Բ�������Ϊ׼,������̶��ٷ��ӹ���.*/
// ����:
// �Ƚ���һ����������������.
int array[] = {1,2,5,10};
// ȡǰ�����ȹ���,
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

