#include<iostream>
using namespace std;
class DoubledLinkedList
{
	struct Node {
		int data;
		Node *prev;
		Node *next;

		Node(int data = 0)
		{
			this->data = data;
			prev = next = 0;
		}
	};
	Node *head;
	Node *tail;

public:
	class Iterator//연결 리스트에 보관한 데이터를 탐색하기 위한 반복자
	{
		Node *node;//현재 노드의 위치 정보
	public:
		friend class DoubledLinkedList;//연결리스트에서는 모든 멤버에 접근 권한 부여
		Iterator(Node *node = 0)
		{
			this->node = node;
		}

		int getData()const //현재 노드에 보관한 자료 접근자
		{
			if (node == 0)//현재 노드가 없을 때
			{
				throw "유효한 노드를 가리키고 있지 않습니다.";
			}
			return node->data;
		}

		bool moveNext()//다음 노드의 위치로 이동
		{
			if (node->next)//다음 노드가 있을 때
			{
				node = node->next;//다음 노드 위치 정보로 변경
				return true;
			}
			return false;
		}

		bool operator==(const Iterator &iter)//같은지 판별
		{
			return node == iter.node;
		}

		bool operator!=(const Iterator &iter)//다른지 판별
		{
			return node != iter.node;
		}
	};

	DoubledLinkedList()
	{
		head = new Node();//더미 노드 생성
		tail = new Node();//더미 노드 생성
		head->next = tail;
		tail->prev = head;
	}

	~DoubledLinkedList()
	{
		Node *prev = 0;
		while (head != 0)
		{
			prev = head;
			head = head->next;
			delete prev;
		}
	}

	void pushBack(int data)
	{
		Node *node = new Node(data);
		hangNode(node, tail);
	}

	void pushFront(int data)
	{
		Node *node = new Node(data);
		hangNode(node, head->next);
	}

	void insert(Iterator iter, int data)
	{
		Node *node = new Node(data);
		hangNode(node, iter.node);
	}

	Iterator begin()//탐색에 사용할 시작 반복자
	{
		Iterator iter(head->next);
		return iter;
	}

	Iterator end() //탐색에 사용할 마지막 반복자
	{
		Iterator iter(tail);
		return iter;
	}

	bool erase(int data)
	{
		Node *pos = 0;
		for (pos = head->next; pos != tail; pos = pos->next)
		{
			if (pos->data == data)
			{
				break;
			}
		}
		if (pos == tail)
		{
			return false;
		}

		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;

		return true;
	}

	bool eraseIndex(int index)
	{
		Node *pos = head->next;
		for (int i = 0; i < index; ++i) {
			pos = pos->next;
		}
		if (pos == tail)
		{
			return false;
		}

		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;

		return true;
	}


private:
	void hangNode(Node *now, Node *pos)
	{
		now->prev = pos->prev;
		now->next = pos;
		pos->prev->next = now;
		pos->prev = now;
	}
};

typedef class DoubledLinkedList DList;

int main() {
	for (int tc = 1; tc <= 10; ++tc) {
		DList dl;

		int N; // 원본 암호문 길이
		int cnt; // 명령어 개수
		char ichar;
		int x, y, s;
		int cur;

		// data input
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> cur;
			dl.pushBack(cur);
		}
		cin >> cnt;
		for (int i = 0; i < cnt; ++i) {
			cin >> ichar;
			if (ichar == 'I') {
				cin >> x >> y;
				for (int j = 0; j < y; ++j) {
					cin >> cur;
					DList::Iterator seek = dl.begin();
					DList::Iterator last = dl.end();
					for (int k = 0; k < x + j; ++k) {
						seek.moveNext();
					}
					dl.insert(seek, cur);
				}
			}
			else if(ichar == 'D'){
				cin >> x >> y;
				for (int j = 0; j < y; ++j) {
					dl.eraseIndex(x);
				}
			}
			else {
				cin >> y;
				for (int j = 0; j < y; ++j) {
					cin >> s;
					dl.pushBack(s);
				}
			}
		}

		// data output
		cout << "#" << tc << " ";
		DList::Iterator seek = dl.begin();
		for (int i = 0; i < 10; ++i) {
			cout << seek.getData() << " ";
			seek.moveNext();
		}
		cout << endl;
	}
	return 0;
}