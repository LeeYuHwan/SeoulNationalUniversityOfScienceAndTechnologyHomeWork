#include <iostream>
#include <ctime>
using namespace std;

struct infoArea {
	int val[5][5]; // 값은 0 또는 1 → 랜덤하게 발생하여 지정
	int count_val1; // val[5][5]에서 1인 값의 개수
};

int setArea(int(*val)[5]) {
	int count = 0;
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			val[i][j] = rand() % 2;
			if (val[i][j] == 1) count++;
			
		}
	}
	return count;
}

void printArea(int(*val)[5], int count_val1) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << val[i][j] << " ";
		}
		cout << endl;
	}
	cout << "1의 개수" << count_val1 << endl;
}

int main()
{
	infoArea areas[10];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		
		areas[i].count_val1 = setArea(areas[i].val);
	}

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << "번째 구조체 내용 출력" << endl;
		printArea(areas[i].val, areas[i].count_val1);
	}	
}

