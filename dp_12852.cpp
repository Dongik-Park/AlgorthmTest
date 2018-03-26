#include<cstdio>
#include<algorithm>
using namespace std;
int ary[1000001];
int output[1000001];
int N;
int dp_cases(int num){

	int min = numeric_limits<int>::max();
	int temp, temp_output;

	if (num <= 1)
		return 0;

	if (num % 3 == 0){
		temp = dp_cases(num / 3);
		if (temp < min){
			temp_output = num / 3;
			min = temp;
		}
	}
	if (num % 2 == 0){
		temp = dp_cases(num / 2);
		if (temp < min){
			temp_output = num / 2;
			min = temp;
		}
	}
	temp = dp_cases(num - 1);
	if (temp < min){
		temp_output = num - 1;
		min = temp;
	}
	
	output[num] = temp_output;
	return ary[num] = min + 1;
}
void printPath(){
	int temp = N;
	printf("%d ", N);
	while (output[temp]){
		printf("%d ", output[temp]);
		temp = output[temp];
	}
}
int main(){
	scanf("%d", &N);
	printf("%d\n", dp_cases(N));
	printPath();
	return 0;
}