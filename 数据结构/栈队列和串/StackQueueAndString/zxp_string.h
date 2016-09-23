// zxp_string.h
// ��Ҫ�ṩһЩ�й��ַ������㷨
#ifndef ZXP_STRING_H_H
#define ZXP_STRING_H_H
#include <string>
// �Ӵ��������е�����ģʽƥ���㷨
// ����˼��:�������ĵ�һ���ַ���ʼ,�������Ӵ���һ���ַ���ʼ�Ƚ�.����Ƚϵ��Ӵ�ĩβ�����,���رȽ�λ��.
// ����,�������ڶ����ַ���ʼ�Ƚ�;���ܹ����Ӵ������ַ��Ƚ����,��ƥ��ɹ�,����ƥ��ʧ�ܡ�
// α����
// 1)����i,j�ֱ�Ϊ�������Ӵ��ıȽ�λ��;
// 2���Ƚ�S[i],T[i],���,�Ƚ���һ��,����;j��λ��ʼλ��,i����һ���ַ�
// 3) ��T�������ַ��Ƚ����,���رȽ���ʼ�±�i;ƥ��ʧ��,����-1;
int BF(char S[], char T[])
{
	int i = 0;
	int j = 0;
	int nStart = i;
	while (S[i] != '\0' && T[j] != '\0')
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}else
		{
			j = 0;
			nStart++;
			i = nStart;
		}
	}
	if (T[j] == '\0')
	{
		return nStart;
	}
	return -1;
}

// KMP�㷨
// ����T����next[i]����
void makeNext(const char P[],int next[])
{
	int q,k;
	int m = strlen(P);
	next[0] = 0;
		for (q = 1,k = 0; q < m; ++q)
		{
				while(k > 0 && P[q] != P[k])
					k = next[k-1];
				if (P[q] == P[k])
				{
					k++;
				}
			   next[q] = k;
		 }
 }

 int kmp(const char T[],const char P[],int next[])
 {
	     int n,m;
	     int i,q;
	     n = strlen(T);
	     m = strlen(P);
	     makeNext(P,next);
		 for (i = 0,q = 0; i < n; ++i)
		 {
				while(q > 0 && P[q] != T[i])
					q = next[q-1];
				if (P[q] == T[i])
				{
					q++;
				}
				if (q == m)
				{
									printf("Pattern occurs with shift:%d\n",(i-m+1));
				}
		 }   
		 return 0;
 }
#endif // ZXP_STRING_H_H