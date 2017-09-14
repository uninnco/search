#include <iostream>

using namespace std;

/**
* 顺序表查找 -- for循环
*/
template<class T>
int SequentialSearch(T* arr,size_t len,T key){
	for(size_t i=0;i<len;i++){
		if(key == arr[i]){
			return i;
		}
	}
	return -1;
}

/**
* 顺序表查找 -- while循环哨兵
*/
template<class T>
T* SequentialSearch(T* first,T* last,T key){
	while(first != last){
		if(*first == key){
			return first;
		}
		first++;
	}
	return NULL;
}

/**
* 有序表查找 -- 折半查找
*/
template<class T>
int BinarySearch(T* arr,size_t len,T key){      
	int low(0),     // 最低下标
	    high(len-1);// 最高下标
    while(low < high) { 
          int mid((low + high)/2); // 中值
          if(arr[mid] == key) return mid;  
          if(arr[mid] > key) high = mid - 1;  
          if(arr[mid] < key) low = mid + 1;
     }  
     return -1;  	
}
/**
* 有序表查找 -- 插值查找
*/
template<class T>
int InterpolationSearch(T* arr,size_t len,T key){      
	int low(0),     // 最低下标
	    high(len-1);// 最高下标
    while(low < high) {
          int mid(low+(high-low)*(key-arr[low])/(arr[high]-arr[low])); // 插值
          if(arr[mid] == key) return mid;  
          if(arr[mid] > key) high = mid - 1;  
          if(arr[mid] < key) low = mid + 1;
     }  
     return -1;  	
}
/**
* 有序表查找 -- 斐波那契查找
*/
template<class T>
int FbonacciSearch(T* arr,size_t len,T key){      
	// TODO
}

int main(){
	
}
