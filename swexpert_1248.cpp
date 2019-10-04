#include<iostream>

using namespace std;

struct Node{
	int s1;
	int s2;
	int parent;
};
Node V[10001];
int cnt;

void calc(int v) {
	if (V[v].s1 == 0 && V[v].s2 == 0) { // leaf node일 경우
		return;
	}
	else if (V[v].s1 != 0 && V[v].s2 != 0) {
		cnt += 2;
		calc(V[v].s1);
		calc(V[v].s2);
		return;
	}
	else if (V[v].s1 != 0) {
		++cnt;
		calc(V[v].s1);
		return;
	}
	else {
		++cnt;
		calc(V[v].s2);
		return;
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int v, E;
		int v1, v2;
		// data input
		cin >> v >> E >> v1 >> v2;
		for (int i = 0; i < E; ++i) {
			int n1, n2;
			cin >> n1 >> n2;
			if (V[n1].s1 != 0)
				V[n1].s2 = n2;
			else
				V[n1].s1 = n2;
			V[n2].parent = n1; // 부모 지정
		}

		// solve
		bool visited[10001] = { false, };
		cnt = 1;
		while (V[v1].parent != 0) { // v1의 부모 체킹
			visited[V[v1].parent] = true;
			v1 = V[v1].parent;
		}

		while (V[v2].parent != 0 && !visited[v2]) { // v2의 부모 중 체킹된 노드 검색
			v2 = V[v2].parent;
		}

		calc(v2);
		for (int i = 1; i <= v; ++i) {
			V[i].s1 = V[i].s2 = V[i].parent = 0;
		}
		
		// data output
		cout << "#" << tc << " " << v2 << " " << cnt << endl;

	} // end of tc

	return 0;
}