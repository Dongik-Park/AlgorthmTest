#include<cstdio>
#include<queue>
#define MAX_N 50
#define MAX_K 300
#define MAX_SIZE (MAX_N + MAX_K * 2)
using namespace std;

struct Cell{
	int row;
	int col;
	int weight; // ���� �����
	int life; // ������ Ȱ��ȭ�Ǵ� �ð�
};

int N, M, K; // �ʱ� ���¿����ٱ� ������ ������ ���� ũ�� N, ���� ũ�� M, ��� �ð� K
int map[MAX_SIZE + 1][MAX_SIZE + 1]; // �ٱ� ���� ��
int temp_map[MAX_SIZE + 1][MAX_SIZE + 1]; // �ٱ� ���� ��
int dx[4] = { 1, -1, 0, 0 }; // �����¿�
int dy[4] = { 0, 0, -1, 1 }; // �����¿�
queue<Cell> deact_cells; // ��Ȱ��ȭ ���� ť
queue<Cell> act_cells; // Ȱ��ȭ ����ť

bool inRange(int row, int col){
	if (row >= 0 && row <= MAX_SIZE && col >= 0 && col <= MAX_SIZE)
		return true;
	return false;
}
// �� �ʱ�ȭ �� ���� �ʱ�ȭ
void init(){
	for (int i = 0; i <= MAX_SIZE; ++i)
		for (int j = 0; j <= MAX_SIZE; ++j)
			map[i][j] = 0;
	while (!deact_cells.empty()) deact_cells.pop();
	while (!act_cells.empty()) act_cells.pop();
}
void deactivateCheck(){
	// ��Ȱ��ȭ ���� ����
	int size = deact_cells.size();
	for (int i = 0; i < size; ++i){
		Cell cur_cell = deact_cells.front(); deact_cells.pop();
		// Ȱ��ȭ�Ǵ� ������ ���� Ȱ������ ť�� �߰�
		if (map[cur_cell.row][cur_cell.col] == 1){
			cur_cell.life = cur_cell.weight; 
			act_cells.push(cur_cell);
			map[cur_cell.row][cur_cell.col] = -1;
		}
		// ������� ���� ��� ����� 1���� �� ��Ȱ��ȭ ť�� ���߰�
		else if(map[cur_cell.row][cur_cell.col] > 1){
			--map[cur_cell.row][cur_cell.col];
			deact_cells.push(cur_cell);
		}
	}
}
vector<Cell> activateCheck(){
	// �ߺ� ��ǥ ������ �����ϴ� temp list
	vector<Cell> temp_list;
	int size = act_cells.size();
	for (int i = 0; i < size; ++i){
		Cell cur_cell = act_cells.front(); act_cells.pop();
		// ���� Ȱ��ȭ�ð��� ���Ҷ����� ť�� ������Ų��.
		if (--cur_cell.life > 0)
			act_cells.push(cur_cell);
		// �����¿쿡 ���� ���� ���� Ȯ��
		for (int j = 0; j < 4; ++j){
			int n_row = cur_cell.row + dx[j];
			int n_col = cur_cell.col + dy[j];
			// ���ٰ����� ��ǥ�̸鼭 map�� ���ٰ����� ��� ��Ȱ��ȭ ���� ť �ĺ� ��Ͽ� �߰�
			if (inRange(n_row, n_col) && map[n_row][n_col] == 0){
				Cell new_cell;
				new_cell.row = n_row;
				new_cell.col = n_col;
				new_cell.weight = cur_cell.weight;
				temp_list.push_back(new_cell);
				++temp_map[n_row][n_col];
			}
		}
	}
	// �ߺ��Ǵ� ������ ������ ��� ���� ����� ū ���� �����Ͽ� deactive_list�� �߰��Ѵ�.
	vector<Cell> deactivate_list;
	for (int i = 0; i < temp_list.size(); ++i){
		Cell cur_cell = temp_list[i];
		// �ߺ��Ǵ� ���� ������ ���
		if (temp_map[cur_cell.row][cur_cell.col] > 1){
			Cell max_cell = cur_cell;
			for (int j = 0; j < temp_list.size(); ++j){
				if (max_cell.weight < temp_list[j].weight &&
					max_cell.row == temp_list[j].row &&
					max_cell.col == temp_list[j].col)
						max_cell = temp_list[j];
			}
			temp_map[max_cell.row][max_cell.col] = 0;
			deactivate_list.push_back(max_cell);
		}
		else if (temp_map[cur_cell.row][cur_cell.col] == 1)
			deactivate_list.push_back(cur_cell);
	}
	return deactivate_list;
}

int solve(){
	int cnt = 0;
	while (++cnt <= K){
		// Ȱ��ȭ ���� üũ �� ��Ȱ��ȭ�� ��� ��ȯ
		vector<Cell> deactivate_list = activateCheck();
		// ��Ȱ��ȭ ���� üũ 
		deactivateCheck();
		// ��Ȱ��ȭ�� ����Ʈ ť�� �߰�
		for (int i = 0; i < deactivate_list.size(); ++i){
			Cell cur_cell = deactivate_list[i];
			map[cur_cell.row][cur_cell.col] = cur_cell.weight;
			temp_map[cur_cell.row][cur_cell.col] = 0;
			deact_cells.push(cur_cell);
		}
	}
	// ���� ť�� �����ϴ� ������ ��ȯ
	return deact_cells.size() + act_cells.size();
}

int main(){
	int T, test_case;
	scanf("%d", &T);
	setbuf(stdout, NULL);

	for (test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d %d", &N, &M, &K);
		N += MAX_K;
		M += MAX_K;
		// �� �� ���� �ʱ�ȭ
		init();
		// ��Ȱ��ȭ ���� �ٱ⼼�� ��� �Է�
		for (int i = MAX_K; i < N; ++i)
			for (int j = MAX_K; j < M; ++j){
				int weight;
				scanf("%d", &weight);
				Cell cell;
				if(weight != 0){
					cell.row = i;
					cell.col = j;
					cell.weight = weight;
					// ��Ȱ��ȭ ť�� �߰� �� �ʿ� ǥ��
					deact_cells.push(cell);
					map[i][j] = weight;
				}
			}
		// ��� ���
		printf("#%d %d\n", test_case, solve());
	}

	return 0;
}