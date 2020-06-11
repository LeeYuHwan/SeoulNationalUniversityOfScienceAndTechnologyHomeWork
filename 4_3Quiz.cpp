#include <iostream>
#include <ctime>
using namespace std;

struct bookInform {
	char title[10];
	char autor[5];
	int year;
	int price;
};

void setBook(bookInform *book, int index) {
	for (int i = 0; i < 10; i++) {	
		book[index].title[i] = rand() % (90 - 65 + 1) + 65;
	}
	for (int i = 0; i < 5; i++) {
	    book[index].autor[i] = rand() % (90 - 65 + 1) + 65;
	}
	book[index].year = rand() % (2020 - 1990 + 1) + 1990;
	book[index].price = rand() % (50000 - 20000 + 1) + 20000;
}

void choiceYearPrint(bookInform* book, int index, int start, int end) {
	if (start <= book[index].year && end >= book[index].year) {
		cout << "책 제목 : ";
		for (int i = 0; i < 10; i++) {
			cout << book[index].title[i];
		}
		cout << endl;
		cout << "저자 : ";
		for (int i = 0; i < 5; i++) {
			cout << book[index].autor[i];
		}
		cout << endl;
		cout << "출판년도 : ";
		cout << book[index].year << endl;
		cout << "가격 : ";
		cout << book[index].price << endl;
	}
}

void choicePricePrint(bookInform* book, int index, int start, int end) {
	if (start <= book[index].price && end >= book[index].price) {
		cout << "책 제목 : ";
		for (int i = 0; i < 10; i++) {
			cout << book[index].title[i];
		}
		cout << endl;
		cout << "저자 : ";
		for (int i = 0; i < 5; i++) {
			cout << book[index].autor[i];
		}
		cout << endl;
		cout << "출판년도 : ";
		cout << book[index].year << endl;
		cout << "가격 : ";
		cout << book[index].price << endl;
	}
}

void showAll(bookInform* book, int index) {
	cout << "책 제목 : ";
	for (int i = 0; i < 10; i++) {
		cout << book[index].title[i];
	}
	cout << endl;
	cout << "저자 : ";
	for (int i = 0; i < 5; i++) {
		cout << book[index].autor[i];
	}
	cout << endl;
	cout << "출판년도 : ";
	cout << book[index].year << endl;
	cout << "가격 : ";
	cout << book[index].price << endl;
}

int main()
{
	bookInform book[10];
	int start, end = 0;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		setBook(book, i);
	}
	cout << "찾고 싶은 출판년도 범위를 입력하세요." << endl;
	cout << "시작년도 :";
	cin >> start;
	cout << "끝 년도 : ";
	cin >> end;
	for (int i = 0; i < 10; i++) {
		choiceYearPrint(book, i, start, end);
	}
	cout << endl;
	cout << "찾고 싶은 출판가격 범위를 입력하세요." << endl;
	cout << "시작가격 :";
	cin >> start;
	cout << "끝 가격 : ";
	cin >> end;
	for (int i = 0; i < 10; i++) {
		choicePricePrint(book, i, start, end);
	}
	cout << endl;
	cout << "모든 책의 정보를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		showAll(book, i);
	}
}
