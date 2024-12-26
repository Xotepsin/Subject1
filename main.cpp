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
// ���� ����
void sort_asc(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// �� ��Ҹ� ��ȯ
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
				// �� ��Ҹ� ��ȯ
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

	cout << "���� 5���� �Է����ּ��� : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	while (true) {
		cout << "(�������� ������ 1, �������� ������ 2) : ";
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
			cout << "1�� 2�� �Է����ּ���" << endl;
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		if (i == size - 1) {
			cout << endl;
		}
	}
	

	int total = sum(arr);
	double avr = average(total, size);

	cout << "����" << total << endl;
	cout << "���" << avr << endl;

	return 0;
}