// LinearTable.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "zxp_linklist.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		// Լɪ������
	//	Circle(4, 2);

		// �����ཻ����
		
	/*	CLinkList<int> MyLinkList(5,1);
		MyLinkList.PrintList();
		printf("������%d\r\n", MyLinkList.GetLength());
		printf("ɾ����3�����%d\r\n", MyLinkList.Delete(1));
		MyLinkList.Insert(1, 10);
		MyLinkList.Insert(7, 9);
		MyLinkList.Insert(3, 33);
		MyLinkList.PrintList();
		printf("��3��Ԫ����%d", MyLinkList.GetLocate(3));
		printf("ֵΪ10��Ԫ��λ��%d, ֵΪ4��Ԫ��λ��%d", MyLinkList.GetValue(10), MyLinkList.GetValue(4));
		MyLinkList.PrintList();
		printf("\r\n����������:");
		MyLinkList.Reverse();
		MyLinkList.PrintList();*/

		/*CLinkList<elem> MyLinkListA;
		CLinkList<elem> MyLinkListB;
		elem em1;
		em1.coef = 3;
		em1.exp = 1;
		MyLinkListA.Insert(1, em1);
		elem em2;
		em2.coef = 4;
		em2.exp = 2;
		MyLinkListA.Insert(2, em2);
		elem em3;
		em3.coef = 5;
		em3.exp = 5;
		MyLinkListA.Insert(3, em3);
		MyLinkListA.PrintList();
		elem em4;
		em4.coef = 2;
		em4.exp = 2;
		MyLinkListB.Insert(1, em4);
		em4.coef = 3;
		em4.exp = 3;
		MyLinkListB.Insert(2, em4);
		em4.coef = 4;
		em4.exp = 4;
		MyLinkListB.Insert(3, em4);
		em4.coef = 5;
		em4.exp = 6;
		MyLinkListB.Insert(4, em4);
		em4.coef = 8;
		em4.exp = 7;
		MyLinkListB.Insert(5, em4);
		MyLinkListB.PrintList();
		Add(MyLinkListA, MyLinkListB);
		MyLinkListA.PrintList();*/
	//	int array[] = {1,2,3,4,5,6,7,8};
		//MoveArrayK(array, sizeof(array)/sizeof(int), 4);
	/*	DevisionOddAndEven(array, sizeof(array)/sizeof(int));
		for (int i = 0; i<sizeof(array)/sizeof(int); i++)
		{
			printf("%d, ", array[i]);
		}*/
	}
	catch(CError& e)
	{
		string str = e.GetErrorMsg();
		printf("%s\r\n", str.c_str());
	}
	catch(...)
	{
		printf("δ֪�쳣\r\n");
	}
	getchar();
	return 0;
}

