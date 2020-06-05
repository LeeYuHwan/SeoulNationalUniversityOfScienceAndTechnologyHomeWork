#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//양수로만 진행하였습니다.
void setLine(int* line) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 4; i++) {
		line[i] = rand() % 100; // 직선 생성 (직선을 잇는 점 두개는 0 ~ 99 까지로 제한 하였습니다.)
		
	}// 선을 서로 긋는데만 점 두개를 쓰고  ax + by + c = 0 직선 취급
}

void setDot(int(*dot)[2], int row, int col) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			dot[i][j] = rand() % 100; // 점 생성 (0~99 까지로 제한 하였습니다.)
		}
	}
}

int setSlope(int *line, float slope) {
	int x1, x2, y1, y2 = 0;
	x1 = line[0];
	x2 = line[2];
	y1 = line[1];
	y2 = line[3];
	slope = ((y2 - y1) / (x2 - x1));
	return slope;
}

void lineEquation(int *result,int *line, int (*dot)[2], float slope, int row, int col) {
	int x = line[0];
	int b = line[1] - (slope * x);
	if(b >= 0)
		cout << "랜덤 직선 : Y=" << slope << "X+" << b << "생성" << endl;
	else
		cout << "랜덤 직선 : Y=" << slope << "X" << b << "생성" << endl;
	
	for (int i = 0; i < 50; i++) {
		if (dot[i][1] > (slope * dot[i][0]) + b) result[0]++;
		else if (dot[i][1] < (slope * dot[i][0]) + b) result[2]++;
		else result[1]++;
	}
}

void printResult(int* result) {
	
	cout << "직선 위에 점" << result[0] << "개" << endl;
	cout << "직선 상에 점" << result[1] << "개" << endl;
	cout << "직선 아래에 점" << result[2] << "개" << endl;
}

int main()
{
	int line[4];
	int dot[50][2];
	int result[3] = {0,0,0}; // 결과 0:위 1:직선상 2:아래
	float slope = 0;
	int row = sizeof(dot) / sizeof(dot[0]);
	int col = sizeof(dot[0]) / sizeof(int);
		
	setLine(line);
	setDot(dot, row, col);
	slope = setSlope(line, slope);
	lineEquation(result, line ,dot, slope, row, col);
	printResult(result);
}