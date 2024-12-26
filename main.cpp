#include <iostream>
#include <array>

using namespace std;

// 총합을 구하는 함수 sum
int sum(const int a[]) {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += a[i];		// 반복문으로 배열을 0번인덱스부터 마지막인덱스까지 total 변수에 더함
	}
	return total;
}

// 평균을 구하는 함수 average
double average(int sum, int size) {
	double result = sum / (double)size;		// 두 매개변수가 int이기때문에 하나를 double로 형변환
	return result;
}

// 버블 정렬 활용
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
// 버블 정렬 내림차순
void sort_desc(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i- 1; j++) {
			if (arr[j] < arr[j + 1]) { //요기만 바꿔주면 내림차순이됨
				// 두 요소를 교환
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
// 버블 정렬은 인접한 두 요소를 비교하고, 필요에 따라 위치를 교환하는 방식으로 정렬한다.
// 오름차순기준으로 설명하자면 첫 순회때 인덱스0부터 마지막인덱스까지 인접한 두 요소를 반복비교하며 가장 큰 값을 찾아 맨뒤로 보낸다.
// 두 번째때는 인덱스 0 부터 마지막인덱스 -1 까지 인접한 두 요소를 반복 비교한다.두 번째로 큰 값이 맨 뒤에서 두번째에 위치하게 된다. 이렇게 계속 반복하게 되며 오름차순으로 정렬 되는 것이다.

int main() {

	int arr[5];		// 배열 선언
	int size = sizeof(arr) / sizeof(int);	// 코드의 재사용성을 높이기 위한 size 변수선언
	int select;		// 오름차순인지 내림차순인지 선택 변수 선언

	cout << "숫자 " << size << "개를 입력해주세요 : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];		// size수만큼 배열에 숫자를 입력받음.
	}
	while (true) {
		cout << "(오름차순 정렬은 1, 내림차순 정렬은 2) : ";		
		cin >> select;
		if (select == 1) {		// 1이 입력되면 오름차순 정렬
			sort_asc(arr, size);
			break;
		}
		else if (select == 2) {		// 2가 입력되면 내림차순 정렬
			sort_desc(arr, size);
			break;
		}
		else
			cout << "1과 2중 입력해주세요" << endl;	// 숫자가 제대로 입력될때까지 while문 무한루프
	}

	//	제대로 정렬되었는지 확인하기위한 반복문과 출력문
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
		if (i == size - 1) {
			cout << endl;
		}
	}		
	
	int total = sum(arr);		// total 변수에 sum함수 리턴값 할당
	double avr = average(total, size);	// avr변수에 average함수 리턴값 할당

	cout << "총합" << total << endl;
	cout << "평균" << avr << endl;

	return 0;
}