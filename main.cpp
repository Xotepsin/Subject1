#include <iostream>
#include <array>

using namespace std;

int sum(const int a[]) {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += a[i];
	}
	return total;
}
double average(int sum, int size) {
	double result = sum / (double)size;
	return result;
}
// 버블 정렬
void sort_asc(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// 두 요소를 교환
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void sort_desc(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i- 1; j++) {
			if (arr[j] < arr[j + 1]) {
				// 두 요소를 교환
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {

	int arr[5];
	int size = sizeof(arr) / sizeof(int);
	int select;

	cout << "숫자 5개를 입력해주세요 : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	while (true) {
		cout << "(오름차순 정렬은 1, 내림차순 정렬은 2) : ";
		cin >> select;
		if (select == 1) {
			sort_asc(arr, size);
			break;
		}
		else if (select == 2) {
			sort_desc(arr, size);
			break;
		}
		else
			cout << "1과 2중 입력해주세요" << endl;
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		if (i == size - 1) {
			cout << endl;
		}
	}
	

	int total = sum(arr);
	double avr = average(total, size);

	cout << "총합" << total << endl;
	cout << "평균" << avr << endl;

	return 0;
}