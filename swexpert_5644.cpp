#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

#define MAX_M 100
#define MAX_A 8
#define MAX_C 4
#define MAP_LEN 10

using namespace std;

struct BC{
	int x;
	int y;
	int C;
	int P;
};

int M, A;
int a_path[MAX_M];
int b_path[MAX_M];
int dx[5] = {0, -1, 0, 1, 0}; // 0,↑,→,↓,←
int dy[5] = {0, 0, 1, 0, -1}; // 0,↑,→,↓,←
BC bc_list[MAX_A]; // BC 목록

void findMaxAndSum(pair<int, int> a, pair<int, int> b, int *sum){
	int a_row = a.first;
	int a_col = a.second;
	int b_row = b.first;
	int b_col = b.second;

	vector<int> a_vec;
	vector<int> b_vec;

	for (int i = 0; i < A; ++i){
		BC cur_bc = bc_list[i];

		// A 범위 안에 있을 경우
		if (cur_bc.C >= abs(cur_bc.x - a_row) + abs(cur_bc.y - a_col))
			a_vec.push_back(i);

		// B 범위 안에 있을 경우
		if (cur_bc.C >= abs(cur_bc.x - b_row) + abs(cur_bc.y - b_col))
			b_vec.push_back(i);
	}
	// 아무것도 포함안되었을 경우
	if (a_vec.size() == 0 && b_vec.size() == 0)
		return;
	// 각 벡터를 내림차순으로 sorting한다.
	if (a_vec.size() > 1)
		for (int i = 0; i < a_vec.size() - 1; ++i)
			for (int j = 0; j < a_vec.size() - i - 1; ++j)
				if (bc_list[a_vec[j]].P < bc_list[a_vec[j + 1]].P){
					int temp = a_vec[j];
					a_vec[j] = a_vec[j + 1];
					a_vec[j + 1] = temp;
				}
	if (b_vec.size() > 1)
		for (int i = 0; i < b_vec.size() - 1; ++i)
			for (int j = 0; j < b_vec.size() - i - 1; ++j)
				if (bc_list[b_vec[j]].P < bc_list[b_vec[j + 1]].P){
					int temp = b_vec[j];
					b_vec[j] = b_vec[j + 1];
					b_vec[j + 1] = temp;
				}

	int max_val = 0;
	int a_index = -1;
	int b_index = -1;
	// 최대값 추출
	if (a_vec.size() > 0)
		a_index = a_vec[0];
	if (b_vec.size() > 0)
		b_index = b_vec[0];
	// 두 개의 값이 중복될 경우 최대값을 정한다.
	if (a_index == b_index){
		if (a_vec.size() > 1){
			if (b_vec.size() > 1)
				max_val = max(bc_list[a_vec[0]].P + bc_list[b_vec[1]].P,
				bc_list[b_vec[0]].P + bc_list[a_vec[1]].P);
			else
				max_val = bc_list[b_vec[0]].P + bc_list[a_vec[1]].P;
		}
		else if (a_vec.size() == 1 && b_vec.size() == 1)
			max_val = bc_list[a_vec[0]].P;

		else
			max_val = bc_list[a_vec[0]].P + bc_list[b_vec[1]].P;
	}
	// A만 범위 안인 경우
	else if (b_index == -1 && a_index != -1)
		max_val = bc_list[a_vec[0]].P;
	// B만 범위 안인 경우
	else if (a_index == -1 && b_index != -1)
		max_val = bc_list[b_vec[0]].P;
	// 둘다 서로 다른 범위 안인 경우
	else
		max_val = bc_list[a_vec[0]].P + bc_list[b_vec[0]].P;
	// 결과 누적
	*sum += max_val;

}

int solve(){

	int sum = 0;

	pair <int, int> a = { 1, 1 };
	pair <int, int> b = { 10, 10 };

	// find max cases and accumulate
	findMaxAndSum(a, b, &sum);

	for (int i = 0; i < M; ++i){
		// make new location
		int a_dir = a_path[i];
		int b_dir = b_path[i];
		a.first = a.first + dx[a_dir];
		a.second = a.second + dy[a_dir];
		b.first = b.first + dx[b_dir];
		b.second = b.second + dy[b_dir];
		// find max cases and accumulate
		findMaxAndSum(a, b, &sum);
	}

	return sum;
}

int main(){

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d", &M, &A);

		for (int i = 0; i < M; ++i)
			scanf("%d", a_path + i);
		for (int i = 0; i < M; ++i)
			scanf("%d", b_path + i);
		for (int i = 0; i < A; ++i){
			BC input;
			scanf("%d %d %d %d", &input.y, &input.x, &input.C, &input.P);
			bc_list[i] = input;
		}

		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}