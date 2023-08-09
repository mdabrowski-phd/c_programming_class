#include <stddef.h> // included for NULL; not necessary if using iostream, etc.

struct listNode {
	int studentNum;
	int grade;
	listNode * next;
};

typedef listNode * studentCollection;

int main() {
	studentCollection sc;
	listNode * node1 = new listNode;
	node1->studentNum = 1001; node1->grade = 78;
	listNode * node2 = new listNode;
	node2->studentNum = 1012; node2->grade = 93;
	listNode * node3 = new listNode;
	node3->studentNum = 1076; node3->grade = 85;	
	sc = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	node1 = node2 = node3 = NULL;

	return 0;
}