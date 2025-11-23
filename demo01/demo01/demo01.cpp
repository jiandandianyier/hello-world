

#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Array
{
public:
	Array(int size = 10) :mCur(0), mCap(size)//构造函数，对mCap_和mCur进行初始化
	{
		mpArr = new int[mCap]();//()表示初始化数组元素为0,不加()则不初始化
	}
	~Array()
	{
		delete[] mpArr;//析构函数，释放堆上的内存,防止内存泄漏
		mpArr = nullptr;//指针本身还存了释放掉的堆内存的地址，将指针置空，防止野指针
	}
public:
	void push_back(int val)//末尾增加元素，时间复杂度O(1)
	{
		if(mCur==mCap)//如果当前元素个数等于容量，则需要扩容
		{
			expand(2*mCap);
		}
		mpArr[mCur++] = val;
	}
	void pop_back()//末尾删除元素，时间复杂度O(1)
	{
		if(mCur==0)
		{
			return;//如果当前元素个数为0，则不能删除，直接返回
		}
		mCur--;//将当前元素个数减1即可
	}
	void insert(int pos, int val)//在pos位置插入元素，时间复杂度O(n)
	{
		if(pos<0 || pos>mCur)//如果pos位置不合法，则直接返回
		{
			return;
		}
		if(mCur==mCap)//如果当前元素个数等于容量，则需要扩容
		{
			expand(2*mCap);
		}
		for(int i=mCur-1; i>=pos; --i)//从后往前移动元素
		{
			mpArr[i+1] = mpArr[i];
		}
		mpArr[pos] = val;//在pos位置插入元素
		mCur++;//当前元素个数加1
	}
	void erase(int pos)//删除val位置的元素，时间复杂度O(n)
	{
		if(pos<0 || pos>=mCur)//如果pos位置不合法，则直接返回
		{
			return;
		}
		for(int i=pos; i<mCur-1; ++i)//从pos位置开始往前移动元素
		{
			mpArr[i] = mpArr[i+1];
		}
		mCur--;//当前元素个数减1
	}
	int find(int val)//查找val位置的元素，时间复杂度O(n)
	{
		for (int i = 0; i < mCur; ++i)
		{
			if (mpArr[i] == val)
			{
				return i;//找到返回下标
			}
		}
		return -1;//没找到返回-1
	}
	void show()const//打印数组元素
	{
		for(int i = 0; i < mCur; ++i)
		{
			cout << mpArr[i] << " ";
		}
		cout << endl;
	}
private:
	void expand(int size)//扩容函数
	{
		int* p = new int[size]();//申请新的堆内存
		memcpy(p, mpArr, sizeof(int) * mCap);//将原数组元素拷贝到新数组
		delete[] mpArr;//释放原数组内存
		mpArr = p;//指针指向新数组
		mCap = size;//更新容量
	}
private://在private区域定义成员变量
    int* mpArr;
    int mCap;
    int mCur;
};
int main()
{
	Array arr;

	srand(time(0));//设置随机数种子
	for(int i = 0; i < 10; ++i)
	{
		int val = rand() % 100;//生成0-99的随机数
		arr.push_back(val);
	}
	arr.show();
}

