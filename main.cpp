#include <iostream>
#include <array>

using namespace std;

// ������ ���ϴ� �Լ� sum
int sum(const int a[]) {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += a[i];		// �ݺ������� �迭�� 0���ε������� �������ε������� total ������ ����
	}
	return total;
}

// ����� ���ϴ� �Լ� average
double average(int sum, int size) {
	double result = sum / (double)size;		// �� �Ű������� int�̱⶧���� �ϳ��� double�� ����ȯ
	return result;
}

// ���� ���� Ȱ��
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
// ���� ���� ��������
void sort_desc(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i- 1; j++) {
			if (arr[j] < arr[j + 1]) { //��⸸ �ٲ��ָ� ���������̵�
				// �� ��Ҹ� ��ȯ
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
// ���� ������ ������ �� ��Ҹ� ���ϰ�, �ʿ信 ���� ��ġ�� ��ȯ�ϴ� ������� �����Ѵ�.
// ���������������� �������ڸ� ù ��ȸ�� �ε���0���� �������ε������� ������ �� ��Ҹ� �ݺ����ϸ� ���� ū ���� ã�� �ǵڷ� ������.
// �� ��°���� �ε��� 0 ���� �������ε��� -1 ���� ������ �� ��Ҹ� �ݺ� ���Ѵ�.�� ��°�� ū ���� �� �ڿ��� �ι�°�� ��ġ�ϰ� �ȴ�. �̷��� ��� �ݺ��ϰ� �Ǹ� ������������ ���� �Ǵ� ���̴�.

int main() {

	int arr[5];		// �迭 ����
	int size = sizeof(arr) / sizeof(int);	// �ڵ��� ���뼺�� ���̱� ���� size ��������
	int select;		// ������������ ������������ ���� ���� ����

	cout << "���� " << size << "���� �Է����ּ��� : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];		// size����ŭ �迭�� ���ڸ� �Է¹���.
	}
	while (true) {
		cout << "(�������� ������ 1, �������� ������ 2) : ";		
		cin >> select;
		if (select == 1) {		// 1�� �ԷµǸ� �������� ����
			sort_asc(arr, size);
			break;
		}
		else if (select == 2) {		// 2�� �ԷµǸ� �������� ����
			sort_desc(arr, size);
			break;
		}
		else
			cout << "1�� 2�� �Է����ּ���" << endl;	// ���ڰ� ����� �Էµɶ����� while�� ���ѷ���
	}

	//	����� ���ĵǾ����� Ȯ���ϱ����� �ݺ����� ��¹�
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		if (i == size - 1) {
			cout << endl;
		}
	}		
	
	int total = sum(arr);		// total ������ sum�Լ� ���ϰ� �Ҵ�
	double avr = average(total, size);	// avr������ average�Լ� ���ϰ� �Ҵ�

	cout << "����" << total << endl;
	cout << "���" << avr << endl;

	return 0;
}