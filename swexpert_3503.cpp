#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
// 1. 내림차순 정렬한다.
// 2. 가운데( 트리 최상단에 ) 가장 큰 수 둔다.
// 3. 왼쪽 및 오른쪽에 오차가 작은 대로 다음 순서대로 배치한다.
// 4. 가장 왼쪽부터 최소값 계산한다.
typedef struct Node{
	Node* left;
	Node* right;
	int val;
	int weight;
};
int len;
int max(int a, int b){
	return a > b ? a : b;
}
int abs(int a){
	return a < 0 ? (a * (-1)) : a;
}

void quickSort(int *ary, int size)
{
	int pivot, temp;
	int i, j;
	if (size <= 1)return; // 구간값이 1이하이면 sort 완료된 것이므로 return

	pivot = ary[size - 1];// 구간의 가장 우측값을 pivot으로 정함
	while (1)
	{
		for (i = 0; i < size; ++i)
			if (pivot >= ary[i])
				break;
		for (j = size - 2; j != 0; --j)
			if (pivot < ary[j])
				break;
		if (i < j)
		{
			temp = ary[i];
			ary[i] = ary[j];
			ary[j] = temp;
		}
		else
		{
			temp = ary[size - 1];
			ary[size - 1] = ary[i];
			ary[i] = temp;
			break;
		}
	}
	quickSort(ary, i); //좌측 소구간에 대한 퀵 정렬 재귀 호출
	quickSort(ary + i + 1, size - i - 1); //우측 소구간에 대한 퀵 정렬 재귀 호출
}
int solve(int arr[]){

	quickSort(arr, len);

	Node * cur_l = new Node;
	cur_l->right = NULL;
	cur_l->left = NULL;
	Node * cur_r = new Node;
	cur_r->right = NULL;
	cur_r->left = NULL;

	Node* cur = new Node;
	cur->left = NULL;
	cur->right = NULL;
	cur->val = arr[0];
	Node* left = new Node;
	left->val = arr[1];
	left->left = NULL;
	left->right = NULL;
	Node* right = new Node;
	right->val = arr[2];
	right->left = NULL;
	right->right = NULL;

	left->right = cur;
	cur->left = left;
	right->left = cur;
	cur->right = right;

	cur->weight = 2;

	cur_l = left;
	cur_l->weight = 1;
	cur_r = right;
	cur_r->weight = 1;

	

	for (int i = 3; i < len; ++i){
		Node * temp = new Node;
		temp->left = NULL;
		temp->right = NULL;
		temp->val = arr[i];

		int l_val = abs(cur_l->val - arr[i]);
		int r_val = abs(cur_r->val - arr[i]);

		//양쪽 공정하게 분배하기 위해 카운트 개수
		if (l_val > r_val){
			cur_l->left = temp;
			temp->right = cur_l;
			temp->weight = cur_l->weight + 1;
			cur_l = temp;
		}
		else if (l_val == r_val){
			// 왼쪽의 가중치가 오른쪽보다 클 경우
			if (cur_l->weight > cur_r->weight){
				cur_r->right = temp;
				temp->left = cur_r;
				temp->weight = cur_r->weight + 1;
				cur_r = temp;
			}
			else{
				cur_l->left = temp;
				temp->right = cur_l;
				temp->weight = cur_l->weight + 1;
				cur_l = temp;
			}
		}
		else{
			cur_r->right = temp;
			temp->left = cur_r;
			temp->weight = cur_r->weight + 1;
			cur_r = temp;
		}
	}

	int max_val = 0;

	Node * temp2 = new Node;
	temp2 = cur_l;
	while (1){
		max_val = max(abs(temp2->val - temp2->right->val), max_val);
		if (temp2->right->right == NULL)
			break;
		temp2 = temp2->right;
	}

	return max_val;
}
int main(){
	int N, test_case;
	scanf("%d", &N);
	for (test_case = 1; test_case <= N; ++test_case){
		int arr[10001];
		scanf("%d", &len);
		for (int i = 0; i < len; ++i)
			scanf("%d", &arr[i]);
		printf("#%d %d\n", test_case, solve(arr));
	}
	return 0;
}