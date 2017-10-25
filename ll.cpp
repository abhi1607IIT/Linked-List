#include <iostream>
#include "Node.cpp"
using namespace std;

void changeLL(Node<int>* head) {
	int max = 0;
	Node<int>* temp = head;
	while (temp != NULL) {
		if (temp->data > max) {
			max = temp->data;
		}
		temp = temp->next;
	}
	bool* done = new bool[max + 1];
	for (int i = 0; i <= max; i++) {
		done[i] = false;
	}
	temp = head;
	while (temp != NULL) {
		if (done[temp->data]) {
			temp->data = max + 1;
			max++;
		} else {
			done[temp->data] = true;
		}
		temp = temp->next;
	}
	delete [] done;
}


int lengthR(Node<int>* head) {
	if (head == NULL) {
		return 0;
	}
	return 1 + lengthR(head->next);
}

int length(Node<int>* head) {
	int l = 0;
	while (head != NULL) {
		l++;
		head = head->next;
	}
	return l;
}


Node<int>* takeLLInput() {
	/*
	int* p;
	if (true) {
		int i = 10;
		p = &i;
	}
	*p = 1000;
	int j = 10;

	int k = 1000;

*/

	Node<int>* head = NULL;
	int n;
	cin >> n;
	while (n != -1) {
		Node<int>* node = new Node<int>(n);
	//	Node<int> node(n);
		if (head == NULL) {
			head = node;
		} else {
			Node<int>* tail = head;
			while (tail->next != NULL) {
				tail = tail->next;
			}
			tail->next = node;
		}
		cin >> n;
	}
	return head;
}

class DoubleNode {
	public:
		Node<int>* head;
		Node<int>* tail;
		DoubleNode(Node<int>* h, Node<int>* t) {
			head = h;
			tail = t;
		}
};

Node<int>* reverse4(Node<int>* head) {
	Node<int>* prev = NULL;
	Node<int>* current = head;
	while (current != NULL) {
		Node<int>* nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
	}
	return prev;
}

Node<int>* reverse3(Node<int>* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node<int>* smallReverse = reverse3(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallReverse;
}

DoubleNode* reverse2(Node<int>* head) {
	if (head == NULL || head->next == NULL) {
		DoubleNode* ans = new DoubleNode(head, head);
		return ans;
	}

	DoubleNode* output = reverse2(head->next);
	output->tail->next = head;
	head->next = NULL;
	output->tail = head;
	return output;
}

Node<int>*kreverse(Node<int>*head,int k)
{
    int l=length(head);
    if(k>l){
        return head;
    }
    int work=l/k;
    int check=1;
    Node<int>*temp=head;
    Node<int>*temphead=head;
    Node<int>*currtail=NULL;
    Node<int>*perhead=NULL;
    while(check<=work){
        int kcheck=1;
        while(kcheck<k){
            temp=temp->next;
            kcheck++;
        }
        Node<int>*temparary=temp->next;
        temp->next=NULL;
        DoubleNode* output=reverse2(temphead);
        if(perhead==NULL){
            perhead=output->head;
            currtail=output->tail;
        }
        else{
            currtail->next=output->head;
            currtail=output->tail;
        }
        temphead=temparary;
        temp=temparary;
        check++;
    }

    currtail->next=temp;
    return perhead;
}






Node<int>* reverse(Node<int>* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node<int>* smallReverse = reverse(head->next);
	Node<int>* tail = smallReverse;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = head;
	head->next = NULL;
	return smallReverse;
}

Node<int>* insert(Node<int>* head, Node<int>* node) {
	if(head == NULL) {
		node->next = NULL;
		return node;
	}

	Node<int>* prev = NULL;
	Node<int>* current = head;
	while (current != NULL) {
		if (current->data > node->data) {
			break;
		}
		prev = current;
		current = current->next;
	}
	if (prev == NULL) {
		node->next = current;
		return node;
	} else {
		prev->next = node;
		node->next = current;
		return head;
	}
}

Node<int>* insertionSort(Node<int>* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node<int>* current = head->next;
	Node<int>* sortedHead = head;
	sortedHead->next = NULL;
	while (current != NULL) {
		Node<int>* nextCurrent = current->next;
		sortedHead = insert(sortedHead, current);
		current = nextCurrent;
	}
	return sortedHead;
}


void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << endl;
}

int main() {
	//Node<int>* abc = new Node<int>(10);
	//Node<int>* def = new Node<int>(20);
	//abc->next = def;
	//printLL(abc);
	Node<int>* head = takeLLInput();
	printLL(head);
	//changeLL(head);
	//printLL(head);
	//head = insertionSort(head);
	//printLL(head);
/*	while (head != NULL) {
		Node<int>* temp = head->next;
		delete head;
		head = temp;
	}*/
	//delete head;
	// TODO delete abc and head linkedlist
	cout<<endl;
	Node<int>*head2=kreverse(head,4);
	printLL(head2);
}
