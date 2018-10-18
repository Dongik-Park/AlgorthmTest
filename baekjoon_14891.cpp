#include<iostream>
#include<string>
#define LEN 8
#define MAX_K 100
using namespace std;

int first[LEN];
int second[LEN];
int third[LEN];
int fourth[LEN];
int num[MAX_K];
int dir[MAX_K];
int K;
int idx1, idx2, idx3, idx4;

void turn4(int d, int prev);
void turn3(int d, int prev);
void turn2(int d, int prev);
void turn1(int d, int prev);

void turn4(int d, int prev){
	int t_f = (idx3 + 2) % LEN;
	int f_t = (idx4 + 6) % LEN;

	if (prev == 4) 
		if (third[t_f] != fourth[f_t]) turn3(d * -1, 4);

	if (d == 1) idx4 = (idx4 + 7) % LEN;
	else	    idx4 = (idx4 + 1) % LEN;
}
void turn3(int d, int prev){
	int s_t = (idx2 + 2) % LEN;
	int t_s = (idx3 + 6) % LEN;
	int t_f = (idx3 + 2) % LEN;
	int f_t = (idx4 + 6) % LEN;

	if (prev == 2){ // if came from 2
		if (third[t_f] != fourth[f_t]) turn4(d * -1, 3);
	}
	else if (prev == 3){
		if (second[s_t] != third[t_s]) turn2(d * -1, 3);
		if (third[t_f] != fourth[f_t]) turn4(d * -1, 3);
	}
	else{ // if came from 4
		if (second[s_t] != third[t_s]) turn2(d * -1, 3);
	}
	if (d == 1) idx3 = (idx3 + 7) % LEN;
	else	    idx3 = (idx3 + 1) % LEN;
}
void turn2(int d, int prev){
	int f_s = (idx1 + 2) % LEN;
	int s_f = (idx2 + 6) % LEN;
	int s_t = (idx2 + 2) % LEN;
	int t_s = (idx3 + 6) % LEN;

	if (prev == 1){ // if came from 1
		if (second[s_t] != third[t_s]) turn3(d * -1, 2);
	}
	else if (prev == 2){
		if (first[f_s] != second[s_f]) turn1(d * -1, 2);
		if (second[s_t] != third[t_s]) turn3(d * -1, 2);
	}
	else{ // if came from 3
		if (first[f_s] != second[s_f]) turn1(d * -1, 2);
	}
	if (d == 1) idx2 = (idx2 + 7) % LEN;
	else	    idx2 = (idx2 + 1) % LEN;
}
void turn1(int d, int prev){
	int f_s = (idx1 + 2) % LEN;
	int s_f = (idx2 + 6) % LEN;

	if (prev == 1) // started from 1
		if (first[f_s] != second[s_f]) turn2(d * -1, 1); 

	if (d == 1) idx1 = (idx1 + 7) % LEN;
	else	    idx1 = (idx1 + 1) % LEN;
}
int solve(){
	idx1 = idx2 = idx3 = idx4 = 0;
  
	for (int i = 0; i < K; ++i){
		switch (num[i])
		{
		case 1: turn1(dir[i], 1); break;
		case 2: turn2(dir[i], 2); break;
		case 3: turn3(dir[i], 3); break;
		case 4: turn4(dir[i], 4); break;
		}
	}

	return first[idx1] * 1 + second[idx2] * 2 + third[idx3] * 4 + fourth[idx4] * 8;
}
int main(){

	string str;

	getline(cin, str);
	for (int i = 0; i < LEN; ++i) first[i] = str[i] - '0';
	getline(cin, str);
	for (int i = 0; i < LEN; ++i) second[i] = str[i] - '0';
	getline(cin, str);
	for (int i = 0; i < LEN; ++i) third[i] = str[i] - '0';
	getline(cin, str);
	for (int i = 0; i < LEN; ++i) fourth[i] = str[i] - '0';

	cin >> K;	
	for (int i = 0; i < K; ++i)
		cin >> num[i] >> dir[i];

	cout << solve() << endl;
	return 0;
}