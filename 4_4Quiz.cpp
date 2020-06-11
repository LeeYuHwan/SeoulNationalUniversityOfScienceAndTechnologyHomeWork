#include <iostream>
#include<fstream>
#include<string>
#include <ctime>
using namespace std;

struct Area {
	int temperature;
	int humidity;
	int wind_speed;
};

void setArea(Area (*area)[3][3], int i, int j, int z) {
	area[i][j][z].temperature = rand() % (30 + 10 + 1) - 10;
	area[i][j][z].humidity = rand() % 100 + 1;
	area[i][j][z].wind_speed = rand() % 10 + 1;
}

void printArea(Area(*area)[3][3], int i, int j, int z) {
	cout << "온도 : " << area[i][j][z].temperature << endl;
	cout << "습도 : " << area[i][j][z].humidity << endl;
	cout << "풍속 : " << area[i][j][z].wind_speed << endl;
	cout << endl;
}

void writeTextFile(Area(*area)[3][3]) {
	ofstream fout("Area.txt");
	if (!fout) {
		cerr << "파일 열기 오류" << endl;
		exit(1);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int z = 0; z < 3; z++) {
				fout << "온도 : " << area[i][j][z].temperature << endl;
				fout << "습도 : " << area[i][j][z].humidity << endl;
				fout << "풍속 : " << area[i][j][z].wind_speed << endl;
				fout << endl;
			}
		}
	}
	cout << "텍스트 파일 쓰기 성공" << endl;
	fout.close();
}

void writeBinaryFile(Area(*area)[3][3]) {
	ofstream fout;
	fout.open("areaBinary.dat", ios::out | ios::binary);
	if (!fout) {
		cerr << "파일 열기 오류" << endl;
		exit(1);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int z = 0; z < 3; z++) {
				int tmp[] = { area[i][j][z].temperature, area[i][j][z].humidity, area[i][j][z].wind_speed };
				fout.write((char*)tmp, sizeof(tmp));
			}
		}
	}
	fout.close();
	cout << "이진 파일 쓰기 성공" << endl;
	
}

int main()
{
	Area area[3][3][3];

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int z = 0; z < 3; z++) {
				setArea(area, i, j, z);
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int z = 0; z < 3; z++) {
				printArea(area, i, j, z);
			}
		}
	}

	writeTextFile(area);
	writeBinaryFile(area);
	
}
