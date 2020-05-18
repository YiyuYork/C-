#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

template<class T>void permutation(T list[], int k, int m){
	if (k == m)
	{
	copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
    //����ǰlist����
	cout << endl;
	}
	else
	{
		for (int i = k; i <= m; i++)
		{
		swap(list[i], list[k]);     
		//���±�Ϊi��Ԫ�ؽ�����kλ�ã����ƴ�list[k:m]���޳�����
		permutation(list, k + 1, m);
		swap(list[i], list[k]);
		}
	}
}

int main(int argc, char* argv[]){
	char arr[4] = { 'a', 'b', 'c', 'd' };
	cout << "���������£�" << endl;
	permutation(arr, 0, 3);
	return 0;
}
