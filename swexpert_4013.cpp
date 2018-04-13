#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

// ------ �Լ� ��� ���� ------
void fourthTurn(int, int);
void thirdTurn(int, int);
void secondTurn(int, int);
void firstTurn(int, int);
// ------ �Լ� ��� ���� ------

int K;		   // ������ �ڼ� ����
int first[8];  // 1�� �ڼ� ����
int second[8]; // 2�� �ڼ� ����
int third[8];  // 3�� �ڼ� ����
int fourth[8]; // 4�� �ڼ� ����
int fst_stand; // 1�� ����
int snd_stand; // 2�� ����
int tth_stand; // 3�� ����
int fth_stand; // 4�� ����
queue<pair<int,int>> dirQue; // �ڼ� ��ȣ, ���� ( �ð� : 1, �ݽð� -1 )

// 4�� ȸ�� ��ƾ
void fourthTurn(int dir, int prevTurn){
	// 4�� - 3���� ������ index
	int ftNearIndex = (fth_stand + 6) % 8;
	// 3�� - 4���� ������ index
	int tfNearIndex = (tth_stand + 2) % 8;

	// ���� 4���� ������ �ִ� ���̸� 
	if (prevTurn == 4){
		// 4�� ���� ���� �ƴ� ��츸 3���� �����ش�.( �ݴ� �������� ȸ�� )
		if (third[tfNearIndex] != fourth[ftNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			thirdTurn(nextDir, 4);
		}
		// �ð���� �� ���
		if (dir == 1)
			fth_stand = (fth_stand + 7) % 8;
		// �ݽð���� �� ���
		else
			fth_stand = (fth_stand + 1) % 8;
	}
	// ���� 4�� ������ ���� �ƴ϶��
	else{
		// 3���� ������ �ڼ��� ���� �ٸ� ��� ȸ���Ѵ�.
		if (third[tfNearIndex] != fourth[ftNearIndex]){
			// �ð���� �� ���
			if (dir == 1)
				fth_stand = (fth_stand + 7) % 8;
			// �ݽð���� �� ���
			else
				fth_stand = (fth_stand + 1) % 8;
		}
		else
			return;
	}
}
// 3�� ȸ�� ��ƾ
void thirdTurn(int dir, int prevTurn){
	// 2�� - 3���� ������ index
	int stNearIndex = (snd_stand + 2) % 8;
	// 3�� - 2���� ������ index
	int tsNearIndex = (tth_stand + 6) % 8;
	// 3�� - 4���� ������ index
	int tfNearIndex = (tth_stand + 2) % 8;
	// 4�� - 3���� ������ index
	int ftNearIndex = (fth_stand + 6) % 8;

	// ���� 3���� ������ �ִ� ���̸� 
	if (prevTurn == 3){
		// 3�� ���� ���� �ƴ� ��츸 2���� �����ش�.( �ݴ� �������� ȸ�� )
		if (second[stNearIndex] != third[tsNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			secondTurn(nextDir, 3);
		}
		// 3�� ���� ���� �ƴ� ��츸 4���� �����ش�.( �ݴ� �������� ȸ�� )
		if (fourth[ftNearIndex] != third[tfNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			fourthTurn(nextDir, 3);
		}
		// �ð���� �� ���
		if (dir == 1)
			tth_stand = (tth_stand + 7) % 8;
		// �ݽð���� �� ���
		else
			tth_stand = (tth_stand + 1) % 8;
	}
	// ���� 2������ ���� ���� ���
	else if (prevTurn == 2){
		// 2���� ������ �ڼ��� ���� �ٸ� ��� ȸ���Ѵ�.
		if (second[stNearIndex] != third[tsNearIndex]){
			// �ð���� �� ���
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			// �ݽð���� �� ���
			else
				nextDir = 1;
			// 4������ �̵��Ͽ� Ȯ���Ѵ�.
			fourthTurn(nextDir, 3);

			// 3�� ���� ����
			if (dir == 1)
				tth_stand = (tth_stand + 7) % 8;
			// �ݽð���� �� ���
			else
				tth_stand = (tth_stand + 1) % 8;
		}
		else
			return;
	}
	// ���� 4������ ���� ���� ���
	else if (prevTurn == 4){
		// 3���� ������ �ڼ��� ���� �ٸ� ��� ȸ���Ѵ�.
		if (fourth[ftNearIndex] != third[tfNearIndex]){
			int nextDir;
			// �ð���� �� ���
			if (dir == 1)
				nextDir = -1;
			// �ݽð���� �� ���
			else
				nextDir = 1;

			// 2������ �̵��Ͽ� Ȯ���Ѵ�.
			secondTurn(nextDir, 3);

			// 3�� ���� ����
			if (dir == 1)
				tth_stand = (tth_stand + 7) % 8;
			// �ݽð���� �� ���
			else
				tth_stand = (tth_stand + 1) % 8;
		}
		else
			return;
	}
}
// 2�� ȸ�� ��ƾ
void secondTurn(int dir, int prevTurn){
	// 1�� - 2���� ������ index
	int fsNearIndex = (fst_stand + 2) % 8;
	// 2�� - 1���� ������ index
	int sfNearIndex = (snd_stand + 6) % 8;
	// 2�� 3���� ������ index
	int stNearIndex = (snd_stand + 2) % 8;
	// 3�� - 2���� ������ index
	int tsNearIndex = (tth_stand + 6) % 8;

	// ���� 2���� ������ �ִ� ���̸� 
	if (prevTurn == 2){
		// 2�� ���� ���� �ƴ� ��츸 1���� �����ش�.( �ݴ� �������� ȸ�� )
		if (first[fsNearIndex] != second[sfNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			firstTurn(nextDir, 2);
		}
		// 2�� ���� ���� �ƴ� ��츸 3���� �����ش�.( �ݴ� �������� ȸ�� )
		if (third[tsNearIndex] != second[stNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			thirdTurn(nextDir, 2);
		}
		// �ð���� �� ���
		if (dir == 1)
			snd_stand = (snd_stand + 7) % 8;
		// �ݽð���� �� ���
		else
			snd_stand = (snd_stand + 1) % 8;
	}
	// ���� 1������ ���� ���� ���
	else if (prevTurn == 1){
		// 2���� ������ �ڼ��� ���� �ٸ� ��� ȸ���Ѵ�.
		if (first[fsNearIndex] != second[sfNearIndex]){
			// �ð���� �� ���
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			// �ݽð���� �� ���
			else
				nextDir = 1;

			// 3������ �̵��Ͽ� Ȯ���Ѵ�.
			thirdTurn(nextDir, 2);

			// 2�� ���� ȸ��
			if (dir == 1)
				snd_stand = (snd_stand + 7) % 8;
			// �ݽð���� �� ���
			else
				snd_stand = (snd_stand + 1) % 8;
		}
		else
			return;
	}
	else if (prevTurn == 3){
		// 3���� ������ �ڼ��� ���� �ٸ� ��� ȸ���Ѵ�.
		if (third[tsNearIndex] != second[stNearIndex]){
			// �ð���� �� ���
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			// �ݽð���� �� ���
			else
				nextDir = 1;

			// 3������ �̵��Ͽ� Ȯ���Ѵ�.
			firstTurn(nextDir, 2);

			// 2�� ���� ȸ��
			if (dir == 1)
				snd_stand = (snd_stand + 7) % 8;
			// �ݽð���� �� ���
			else
				snd_stand = (snd_stand + 1) % 8;
		}
		else
			return;
	}
}
// 1�� ȸ�� ��ƾ
void firstTurn(int dir, int prevTurn){
	// 1�� - 2���� ������ index
	int fNearIndex = (fst_stand + 2) % 8;
	// 2�� - 1���� ������ index
	int sNearIndex = (snd_stand + 6) % 8;

	// ���� 1���� ������ �ִ� ���̸� 
	if (prevTurn == 1){
		// 2�� ���� ���� �ƴ� ��츸 2���� �����ش�.( �ݴ� �������� ȸ�� )
		if (first[fNearIndex] != second[sNearIndex]){
			int nextDir;
			if (dir == 1)
				nextDir = -1;
			else
				nextDir = 1;
			secondTurn(nextDir, 1);
		}
		// �ð���� �� ���
		if (dir == 1)
			fst_stand = (fst_stand + 7) % 8;
		// �ݽð���� �� ���
		else
			fst_stand = (fst_stand + 1) % 8;
	}
	// ���� 1�� ������ ���� �ƴ϶��
	else{
		// 2���� ������ �ڼ��� ���� �ٸ� ��� ȸ���Ѵ�.
		if (first[fNearIndex] != second[sNearIndex]){
			// �ð���� �� ���
			if (dir == 1)
				fst_stand = (fst_stand + 7) % 8;
			// �ݽð���� �� ���
			else
				fst_stand = (fst_stand + 1) % 8;
		}
		else
			return;
	}
}
int solve(){
	while (!dirQue.empty()){
		pair<int, int> cur = dirQue.front(); dirQue.pop();

		switch (cur.first){
		case 1: firstTurn(cur.second, 1);  break;
		case 2: secondTurn(cur.second, 2); break;
		case 3: thirdTurn(cur.second, 3);  break;
		case 4: fourthTurn(cur.second, 4); break;
		}
	}
	int fSum = first[fst_stand];
	int sSum = second[snd_stand] * 2;
	int tSum = third[tth_stand] * 4;
	int ffSum = fourth[fth_stand] * 8;

	return fSum + sSum + tSum + ffSum;
}
int main(){
	int T, test_case;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		int i, magnetic, dir;

		// --- ���� �ʱ�ȭ ���� ---
		while (!dirQue.empty())
			dirQue.pop();
		fst_stand = 0;
		snd_stand = 0;
		tth_stand = 0;
		fth_stand = 0;
		// --- ���� �ʱ�ȭ ���� ---

		// ------ �Է� ���� ------
		scanf("%d", &K);
		for (i = 0; i < 8; ++i)
			scanf("%d", &first[i]);
		for (i = 0; i < 8; ++i)
			scanf("%d", &second[i]);
		for (i = 0; i < 8; ++i)
			scanf("%d", &third[i]);
		for (i = 0; i < 8; ++i)
			scanf("%d", &fourth[i]);
		for (i = 0; i < K; ++i){
			scanf("%d %d", &magnetic, &dir);
			dirQue.push(make_pair(magnetic,dir));
		}
		// ------ �Է� ���� ------


		// ------ ��� ��� ------
		printf("#%d %d\n", test_case, solve());

	}
	return 0;
}