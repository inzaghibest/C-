// CatchMemroy.cpp : 定义控制台应用程序的入口点。
// #define 语句将 CRT 堆函数的基版本映射到对应的“Debug”版本。 并非绝对需要该语句；但如果没有该
// 语句，内存泄漏转储包含的有用信息将较少。
#include "stdafx.h"
#include <malloc.h>
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC
/*__LINE__：在源代码中插入当前源代码行号；

__FILE__：在源文件中插入当前源文件名；

__DATE__：在源文件中插入当前的编译日期

__TIME__：在源文件中插入当前编译时间；

__STDC__：当要求程序严格遵循ANSI C标准时该标识被赋值为1；

__cplusplus：当编写C++程序时该标识符被定义。*/

// 将 malloc 和 free 函数映射到它们的调试版本，即 _malloc_dbg 和 _free_dbg，这两个函数将跟踪内存
// 分配和释放。 此映射只在调试版本（在其中定义了_DEBUG）中发生。 发布版本使用普通的 malloc 和 free 函数。
#include <crtdbg.h>
/* windows下检测内存泄露的原理:
Windows平台下面Visual Studio 调试器和 C 运行时 (CRT) 库为我们提供了检测和识别内存泄漏的有效方法，
原理大致如下：内存分配要通过CRT在运行时实现，只要在分配内存和释放内存时分别做好记录，程序结束时
对比分配内存和释放内存的记录就可以确定是不是有内存泄漏 */
/*未定义 _CRTDBG_MAP_ALLOC 时，所显示的会是：
内存分配编号（在大括号内）。
块类型（普通、客户端或 CRT）。
“普通块”是由程序分配的普通内存。
“客户端块”是由 MFC 程序用于需要析构函数的对象的特殊类型内存块。 MFC new 操作根据正在创建的对象的需要
创建普通块或客户端块。
“CRT 块”是由 CRT 库为自己使用而分配的内存块。 CRT 库处理这些块的释放，因此您不大可能在内存泄漏报告中
看到这些块，除非出现严重错误（例如 CRT 库损坏）。
从不会在内存泄漏信息中看到下面两种块类型：
“可用块”是已释放的内存块。
“忽略块”是您已特别标记的块，因而不出现在内存泄漏报告中。
十六进制形式的内存位置。
以字节为单位的块大小。
前 16 字节的内容（亦为十六进制）。
定义了 _CRTDBG_MAP_ALLOC 时，还会显示在其中分配泄漏的内存的文件。 文件名后括号中的数字（本示例中为 10）
是该文件中的行号。

注意：如果程序总是在同一位置退出，调用 _CrtDumpMemoryLeaks 将非常容易。 如果程序从多个位置退出，则无需
在每个可能退出的位置放置对 _CrtDumpMemoryLeaks 的调用，而可以在程序开始处包含以下调用：
_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
该语句在程序退出时自动调用 _CrtDumpMemoryLeaks。 必须同时设置 _CRTDBG_ALLOC_MEM_DF 和 _CRTDBG_LEAK_CHECK_DF
两个位域，如前面所示。*/

class A
{

};

_CrtMemState s1, s2, s3;
void GetMemory(char**p , int nSize)
{
	*p = (char*)malloc(sizeof(char)*nSize);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* str = NULL;
	int j = 100;
	while (j--)
	{
		GetMemory(&str, 10);
		A* pa = new A;
		printf("Memory Get!\r\n");
	}
	/*while (1)
	{
	}*/
	_CrtDumpMemoryLeaks();
	printf("%d,%s,%s,%s",__LINE__, __FILE__,__DATE__, __TIME__);
	getchar();
	return 0;
}

