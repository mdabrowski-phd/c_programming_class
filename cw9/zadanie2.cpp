#include <iostream>
using std::cout;

struct listNode {
	int studentNum;
	int grade;
	listNode * next;
};

typedef listNode * studentCollection;

void addRecord(studentCollection& sc, int stuNum, int gr) {
	listNode * newNode = new listNode;
	newNode->studentNum = stuNum;
	newNode->grade = gr;
	newNode->next = sc;
	sc = newNode;
}

double averageRecord(studentCollection sc) {
	if (sc == NULL) return 0;
	int count = 0;
	double sum = 0;
	listNode * loopPtr = sc;
	while (loopPtr != NULL) {
		sum += loopPtr->grade;
		count++;
		loopPtr = loopPtr->next;
	}
	double average = sum / count;
	return average;
}

int main() {
	
	//testowanie tworzenia listy studentow
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
	
	//tu mozna uzyc funkcji addRecord() dla kazdego studenta
	studentCollection sc = NULL;
	addRecord(sc, 1001, 78);
	addRecord(sc, 1012, 93);
	addRecord(sc, 1076, 85);

	int avg = averageRecord(sc);
	cout << avg << "\n";
	
	addRecord(sc, 1274, 91);
	cout << averageRecord(sc) << "\n";

	return 0;
}
