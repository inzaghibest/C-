// zxp_string.h
// 主要提供一些有关字符串的算法
#ifndef ZXP_STRING_H_H
#define ZXP_STRING_H_H
// 子串在主串中的朴素模式匹配算法
// 基本思想:从主串的第一个字符开始,依次与子串第一个字符开始比较.如果比较到子串末尾均相等,返回比较位置.
// 否则,从主串第二个字符开始比较;若能够将子串所有字符比较完毕,则匹配成功,否则匹配失败。
// 伪代码
// 1)设置i,j分别为主串和子串的比较位置;
// 2）比较S[i],T[i],相等,比较下一个,否则;j置位开始位置,i到下一个字符
// 3) 若T中所有字符比较完毕,返回比较起始下表i;匹配失败,返回-1;
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
#endif // ZXP_STRING_H_H