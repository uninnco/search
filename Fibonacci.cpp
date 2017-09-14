#include <iostream>

using namespace std;
#ifdef RECURSION
/**
* @brief 朴素递归算法
*/
unsigned long long Fibonacci(int n){
    int result[2] = {0,1};
    if (n<2)       //退出条件
       return {0,1}[n];
    return (Fibonacci(n-1)+ Fibonacci(n-2));//递归调用
}
#endif
/**
* @brief 自底向上算法
*/
unsigned long long Fibonacci(int n){
	int result[2] = {0, 1};
    if(n < 2)
        return result[n];

    unsigned long long  fibNMinusN_1(1);
    unsigned long long  fibNMinusN_2(0);
    unsigned long long  fibN(0);
    for(int i = 2; i <= n; ++ i){ //从底到上逐次计算出数列值
        fibN = fibNMinusN_1 + fibNMinusN_2;
        fibNMinusN_2 = fibNMinusN_1;
        fibNMinusN_1 = fibN;
    }

    return fibN;//返回数组值
}

int main(){
	for(size_t i=0;i<60;i++){
		cout << i << ":"<< Fibonacci(i) << endl;
	}
}