#ifndef ZXP_SEQLIST_H_H
#define ZXP_SEQLIST_H_H
#define MAX_SIZE 1024
template <class T>
class SeqList
{
private:
	T m_array[MAX_SIZE];
	int nLength;
public:
	SeqList();
	~SeqList();
	// 获取线性表长度
	int GetLength();
	// 获取小标为ndex的元素值
	T GetIndex(int ndex);
	// 获取指定值元素的下标
	int GetValue(T value);
	// 插入元素
	bool InsertValue(T value)
	
};
#endif