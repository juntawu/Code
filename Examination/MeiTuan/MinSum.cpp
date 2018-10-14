#include <iostream>
#include <vector>
using namespace std;

/*
// 美团 2018-10-09 笔试题：优惠券满减

题目：有一个满X减10的优惠券，一共n个商品，每个只能选择一次，求能使用优惠券的最小价格。就是求n个数选任意几个加起来最接近X且大于等于X的数。1<X<10000，1<n<100,每个商品价格小于等于100。

测试用例

输入：5 20
19 18 17 6 7

输出：23
*/


// 实现一：用sums记录下前k个菜品可能出现的价格和，根据前k个的结果与第k+1个的价格得到前k+1个菜品的可能出现的价格和
int MinSum_one(vector<int> array, int X){
	int result = 10000;  // 可用菜品总价格替换,减少空间开销
	vector<int> sums;
	sums.push_back(0);
	
	int len = array.size();
	for(int i=0; i<len; i++){
		int numOfSums = sums.size();
		// 第 i 个菜不选时就是上一次迭代的结果，如果选的话就要加上当前菜品的价格
		for(int j =0; j<numOfSums; j++){
			int temp = sums[j] + array[i];
			if(temp >= X && temp < result)
				result = temp;
			sums.push_back(temp);
		}
	}	
	
	return result;
}



//实现二：动态规划，构建dp[菜品数量][所有菜品总金额]的矩阵，把所有可能出现的位置标1，dp[i][j]的位置取决于dp[i-1][j]和dp[i-1][j-value[i]]，也就是选和不选第i道菜的两种情况
int MinSum_two(vector<int> array, int X){
	int result = 10000;  // 可用菜品总价格替换,减少空间开销
	int N = array.size();
	vector<vector<int> > dp(N, vector<int>(10000, 0) );
	// 初始化第一行
	dp[0][0] = 1;
	dp[0][array[0]] = 1;
		
	for(int i=1; i<N; i++){
		for(int j=10000-1; j>=0; j--){
			// 不选
			if(dp[i-1][j])
				dp[i][j] = 1;
			// 选
			if(j-array[i] >=0 && dp[i-1][j-array[i]])
				dp[i][j] = 1;
		}
	}	
	
	// 遍历寻找寻找不小于X的最小和
	for(int j=X; j<10000; j++){
		for(int i=0; i<N; i++){
			if(dp[i][j])
				return j;
		}
	}
	
	return result;  // 无解时返回
}




//实现三：动态规划思想,实现二的优化版本
//参考: https://paste.ubuntu.com/p/VWYCvtV9B4/
int MinSum_three(vector<int> array, int X){

	int N = array.size();
	vector<int> dp(10000+100, 0);
	// 初始化第一行
	dp[0]= 1;
		
	for(int i=0; i<N; i++){
		for(int j=10000+100-1; j-array[i]>=0; j--){
			if(dp[j-array[i]])
				dp[j] = 1;
		}
	}	
	
	// 遍历寻找寻找不小于X的最小和
	int ans = X;
	while(!dp[ans]) ++ans;
	
	return ans;
}




int main(){
	int result;
	vector<int> array;
	int N, X;
	cin >> N >> X;
	while(N--){
		int val;
		cin >> val;
		array.push_back(val);
	}
	
	result = MinSum_three(array, X);
	cout << result << endl;
	
	return 0;
}