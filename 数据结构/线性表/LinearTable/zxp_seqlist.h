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
	// ��ȡ���Ա���
	int GetLength();
	// ��ȡС��Ϊndex��Ԫ��ֵ
	T GetIndex(int ndex);
	// ��ȡָ��ֵԪ�ص��±�
	int GetValue(T value);
	// ����Ԫ��
	bool InsertValue(T value)
	
};
#endif