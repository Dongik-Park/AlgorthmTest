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
	class Iterator//���� ����Ʈ�� ������ �����͸� Ž���ϱ� ���� �ݺ���
	{
		Node *node;//���� ����� ��ġ ����
	public:
		friend class DoubledLinkedList;//���Ḯ��Ʈ������ ��� ����� ���� ���� �ο�
		Iterator(Node *node = 0)
		{
			this->node = node;
		}

		int getData()const //���� ��忡 ������ �ڷ� ������
		{
			if (node == 0)//���� ��尡 ���� ��
			{
				throw "��ȿ�� ��带 ����Ű�� ���� �ʽ��ϴ�.";
			}
			return node->data;
		}

		bool moveNext()//���� ����� ��ġ�� �̵�
		{
			if (node->next)//���� ��尡 ���� ��
			{
				node = node->next;//���� ��� ��ġ ������ ����
				return true;
			}
			return false;
		}

		bool operator==(const Iterator &iter)//������ �Ǻ�
		{
			return node == iter.node;
		}

		bool operator!=(const Iterator &iter)//�ٸ��� �Ǻ�
		{
			return node != iter.node;
		}
	};

	DoubledLinkedList()
	{
		head = new Node();//���� ��� ����
		tail = new Node();//���� ��� ����
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

	Iterator begin()//Ž���� ����� ���� �ݺ���
	{
		Iterator iter(head->next);
		return iter;
	}

	Iterator end() //Ž���� ����� ������ �ݺ���
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

		int N; // ���� ��ȣ�� ����
		int cnt; // ��ɾ� ����
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