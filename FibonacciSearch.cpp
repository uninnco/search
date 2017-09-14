#include <iostream>
#include <algorithm>

using namespace std;

void fibonacci(int *f,size_t n)
{
	f[0] = 1;
	f[1] = 1;
	for(int i = 2;i < n;++i)
		f[i] = f[i - 2] + f[i - 1];
}
template<class T>
int FibonacciSearch(T *a,size_t n,T key){
	int low(0),
	    high(n - 1),
	    mid(0),
	    k(0);
	int F[n];

	fibonacci(F,n);
	while(n > F[k] - 1) //计算出n在斐波那契中的数列
		++k;

	T temp[F[k] - 1];
	copy_n(a,n,temp);
	fill_n(temp+n,F[k]-1-n,a[high]);//把数组补全

	while(low <= high){
		mid = low + F[k-1] - 1;  //根据斐波那契数列进行黄金分割
		cout <<"k:" << k << ",mid:" << mid << ",arr[mid]:" << temp[mid] << endl;
		if(temp[mid] > key){
			high = mid - 1;
			k = k - 1;
		}else if(temp[mid] < key){
			low = mid + 1;
			k = k - 2;
		}else{
			//如果为真则找到相应的位置
			return mid <= high?mid:high;
		}
	}
	return -1;
}
int main() {
	int a[] = {1,3,5,7,9,11,13,15,17};
	cout << "请输入要查找的数字:";
	int k;
	cin >> k;
	int pos = FibonacciSearch(a,sizeof(a)/sizeof(a[0]),k);
	if(pos != -1)
		cout << "在数组的第"<< pos <<"个位置找到元素:" << k << endl;
	else
		cout << "未在数组中找到元素:" << k << endl;
}
