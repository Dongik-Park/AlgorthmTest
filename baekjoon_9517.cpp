#include<iostream>
#define BOMB 210
using namespace std;

int main(){
	int target, time;
	int N;
	cin >> target >> N;
	time = 0;
	
	for (int i = 0; i < N; ++i){
		int curTime;
		char result;
		cin >> curTime >> result;
		// �ð�������
		time += curTime;
		// ����ϴµ� �ɸ� �ð��� 3��30�� �̻��� ���
		if (time >= BOMB){
			break;
		}
		// ���� ����� ���
		if (result == 'T'){
			// ���� ������� ����
			++target;
			if (target == 9)
				target = 1;
		}
	}
	cout << target;
	return 0;
}