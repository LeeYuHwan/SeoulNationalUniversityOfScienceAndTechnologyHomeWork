#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int genTriangles(int (*triangles)[6], int numTriangles, int row, int col) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			triangles[i][j] = rand() % 20; // 너무 크면 오버플로우가 발생하여 제한을 두었음
		}
	}
	return numTriangles;
}

int computeArea(int (*triangles)[6], int numTriangles, float *areaTriangles, int row, int col) {
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int y1 = 0;
	int y2 = 0;
	int y3 = 0;
	
	for (int i = 0; i < row; i++) {
		x1 = triangles[i][0];
		y1 = triangles[i][1];
		x2 = triangles[i][2];
		y1 = triangles[i][3];
		x3 = triangles[i][4];
		y1 = triangles[i][5];
		areaTriangles[i] = ((((x1 * y2) + (x2 * y3) + (x3 * y1)) - ((x2 * y1) + (x3 * y2) + (x1 * y3))) / 2);
		if (areaTriangles[i] < 0) areaTriangles[i] *= -1;
	}

	return numTriangles;
}

int dispTriangles(int numTriangles, float* areaTriangles, int row) {
	for (int i = 0; i < row; i++) {
		cout << areaTriangles[i] << endl;
	}
	return numTriangles;
}


int main()
{

	int triangles[50][6];
	float areaTriangles[50];
	int row = sizeof(triangles) / sizeof(triangles[0]);
	int col = sizeof(triangles[0]) / sizeof(int);
	int numTriangles = 0;
	numTriangles = genTriangles(triangles, numTriangles, row, col);
	numTriangles = computeArea(triangles, numTriangles, areaTriangles, row, col);
	numTriangles = dispTriangles(numTriangles, areaTriangles, row);
}


