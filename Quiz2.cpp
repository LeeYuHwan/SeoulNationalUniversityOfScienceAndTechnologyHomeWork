#include <iostream>
#include <cstdlib>
using namespace std;

void set_numberArray(int(*number)[5], int(*tmp_number)[5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			number[i][j] = tmp_number[i][j];
		}
	}
}

void setNumber(int(*number)[5], int input) {
	if (input == 0) {
		int tmp_number[5][5] = { {1,1,1,1,1},
								 {1,0,0,0,1},
								 {1,0,0,0,1},
								 {1,0,0,0,1},
								 {1,1,1,1,1}, };
		set_numberArray(number, tmp_number);
	}
	else if (input == 1) {
		int tmp_number[5][5] = { {0,0,1,0,0},
								 {0,0,1,0,0},
								 {0,0,1,0,0},
								 {0,0,1,0,0},
								 {0,0,1,0,0}, };
		set_numberArray(number, tmp_number);
	}
	else if (input == 2) {
		int tmp_number[5][5] = { {1,1,1,1,1},
								 {0,0,0,0,1},
								 {1,1,1,1,1},
								 {1,0,0,0,0},
								 {1,1,1,1,1}, };
		set_numberArray(number, tmp_number);
	}
	else if (input == 3) {
		int tmp_number[5][5] = { {1,1,1,1,1},
								 {0,0,0,0,1},
								 {1,1,1,1,1},
								 {0,0,0,0,1},
								 {1,1,1,1,1}, };
		set_numberArray(number, tmp_number);
	}
	else if (input == 4) {
		int tmp_number[5][5] = { {1,0,0,0,1},
								 {1,0,0,0,1},
								 {1,1,1,1,1},
								 {0,0,0,0,1},
								 {0,0,0,0,1}, };
		set_numberArray(number, tmp_number);
	}
	else if (input == 5) {
			int tmp_number[5][5] = { {1,1,1,1,1},
									 {1,0,0,0,0},
									 {1,1,1,1,1},
									 {0,0,0,0,1},
									 {1,1,1,1,1}, };
			set_numberArray(number, tmp_number);
	}
	else if (input == 6) {
		int tmp_number[5][5] = { {1,1,1,1,1},
								 {1,0,0,0,0},
								 {1,1,1,1,1},
								 {1,0,0,0,1},
								 {1,1,1,1,1}, };
		set_numberArray(number, tmp_number);
	}
	else if (input == 7) {
		int tmp_number[5][5] = { {1,1,1,1,1},
								 {0,0,0,0,1},
								 {0,0,0,0,1},
								 {0,0,0,0,1},
								 {0,0,0,0,1}, };
		set_numberArray(number, tmp_number);
	}
	else if (input == 8) {
		int tmp_number[5][5] = { {1,1,1,1,1},
								 {1,0,0,0,1},
								 {1,1,1,1,1},
								 {1,0,0,0,1},
								 {1,1,1,1,1}, };
		set_numberArray(number, tmp_number);
	}
	else if (input == 9) {
		int tmp_number[5][5] = { {1,1,1,1,1},
								 {1,0,0,0,1},
								 {1,1,1,1,1},
								 {0,0,0,0,1},
								 {1,1,1,1,1}, };
		set_numberArray(number, tmp_number);
	}
}

int setDistanceNumber(int d_input1, int d_input2) {
	int distance = 0;
	int tmp_number1[5][5];
	int tmp_number2[5][5];

	setNumber(tmp_number1, d_input1);
	setNumber(tmp_number2, d_input2);
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			distance += ((tmp_number1[i][j] - tmp_number2[i][j]) * (tmp_number1[i][j] - tmp_number2[i][j]));
		}
	}
	return distance;
}

void printNumber(int(*number)[5], int distance) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << number[i][j] << " ";
		}
		cout << endl;
	}
	
}
	
int main()
{
	int number[5][5];
	int input = 0;
	int distance = 0;

	int d_input1 = 0;
	int d_input2 = 0;

	cout << "출력할 숫자를 입력하시오(0~9) :";
	cin >> input;
	cout << endl;
	
	setNumber(number, input);
	printNumber(number, distance);
	cout << "거리를 구하고 싶은 두 숫자를 입력하세요(0~9) :";
	cin >> d_input1;
	cin >> d_input2;
	cout << endl;

	distance = setDistanceNumber(d_input1, d_input2);
	cout << "두 숫자 사이의 거리는" << distance << "입니다" << endl;
}