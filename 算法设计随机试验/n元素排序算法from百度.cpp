#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

template<class T>void permutation(T list[], int k, int m){
	if (k == m)
	{
	copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
    //将当前list排序
	cout << endl;
	}
	else
	{
		for (int i = k; i <= m; i++)
		{
		swap(list[i], list[k]);     
		//将下标为i的元素交换到k位置，类似从list[k:m]中剔除操作
		permutation(list, k + 1, m);
		swap(list[i], list[k]);
		}
	}
}

int main(int argc, char* argv[]){
	char arr[4] = { 'a', 'b', 'c', 'd' };
	cout << "排序结果如下：" << endl;
	permutation(arr, 0, 3);
	return 0;
}
