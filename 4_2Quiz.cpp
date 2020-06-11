#include <iostream>
#include <ctime>
#define NUMDATA 20
using namespace std;

void genData(unsigned char(*data)[NUMDATA], int numrow, int numcol) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < numrow; i++) {
		for (int j = 0; j < numcol; j++) {
			data[i][j] = rand() % 255;
		}
	}
}

void dispData(unsigned char(*data)[NUMDATA], int numrow, int numcol) {
	for (int i = 0; i < numrow; i++) {
		for (int j = 0; j < numcol; j++) {
			cout << (int)data[i][j] << "";
		}
		cout << endl;
	}
}

void getHisto(unsigned char(*data)[NUMDATA], int numrow, int numcol,
	int* histo, int numHisto) {
	for (int i = 0; i < numrow; i++) {
		for (int j = 0; j < numcol; j++) {	
			numHisto = (int)data[i][j];
			histo[numHisto]++;
		}
	}
}

void dispHisto(int* histo, int numHisto) {
	for (int i = 0; i < 256; i++) {
		numHisto = histo[i];
		cout << i << "값" << numHisto << "회" << endl;
	}
}

int main()
{
	unsigned char data[NUMDATA][NUMDATA];
	int histo[256] = {0};
	int numHisto = 0;

	genData(data, NUMDATA, NUMDATA);
	dispData(data, NUMDATA, NUMDATA);
	getHisto(data, NUMDATA, NUMDATA, histo, numHisto);
	dispHisto(histo, numHisto);
}

