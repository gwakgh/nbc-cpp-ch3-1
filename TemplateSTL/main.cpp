#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
private:
	T* arr;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector() : currentSize(0), currentCapacity(10) {
		arr = new T[currentCapacity];
	}
	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
		arr = new T[currentCapacity];
	}
	SimpleVector(const SimpleVector& other) {
		currentSize = other.currentSize;
		currentCapacity = other.currentCapacity;
		arr = new T[currentCapacity];

		for (int i = 0; i < currentSize; i++) {
			arr[i] = other.arr[i];
		}
	}
	T& operator[](int index) {
		return arr[index];
	}
	void push_back(const T& value) {
		if (currentSize < currentCapacity) {
			arr[currentSize++] = value;
		}
		else {
			resize(currentCapacity + 5);
			arr[currentSize++] = value;
		}
	}
	void pop_back() {
		if (currentSize) currentSize--;
	}
	int size() {
		return currentSize;
	}
	int capacity() {
		return currentCapacity;
	}

	void resize(int newCapacity) {
		if (newCapacity > currentCapacity)
		{
			T* temp = new T[newCapacity];

			for (int i = 0; i < currentSize; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
			currentCapacity = newCapacity;
		}
	}
	void sortData(int sortType) {
		switch (sortType)
		{
		case 0:
			sort(arr, arr + currentSize, greater<T>());
			break;
		case 1:
			sort(arr, arr + currentSize, less<T>());
			break;
		}
	}

	~SimpleVector() {
		delete[] arr;
	}
};

int main() {
	SimpleVector<int> i;
	SimpleVector<double> d(15);

	//size(), capacity()
	cout << "i Size: " << i.size() << " i Capacity: " << i.capacity() << endl;
	cout << "d Size: " << d.size() << " d Capacity: " << d.capacity() << endl;

	//push_back()
	for (int a = 0; a < i.capacity(); a++) {
		i.push_back(a + 10);
		cout << "i[" << a << "]: " << i[a] << ", ";
		cout << "Size: " << i.size() << endl;
	}

	//Out of Range. 동작하지 않음(조건 만족 X)
	i.push_back(11);	
	cout << endl;

	//다른 타입 push_back
	for (int a = 0; a < d.capacity(); a++) {
		d.push_back(a + 10.123);
		cout << "d[" << a << "]: " << d[a] << ", ";
		cout << "Size: " << d.size() << endl;
	}
	cout << endl;

	//capacity를 초과하여 push_back
	d.push_back(3333.333);
	for (int a = 0; a < d.size(); a++) {
		cout << "d[" << a << "]: " << d[a] << ", ";
		cout << "Size: " << d.size() << endl;
	}
	cout << "d.capacity() = " << d.capacity() << endl;

	cout << endl;

	//size가 10인 i 에서 pop_back() 3번 호출
	i.pop_back();
	i.pop_back();
	i.pop_back();
	for (int a = 0; a < i.size(); a++) {
		cout << "i[" << a << "]: " << i[a] << ", ";
		cout << "Size: " << i.size() << endl;
	}

	//복사 생성자
	SimpleVector<int> temp(i);

	cout << endl;
	for (int a = 0; a < temp.size(); a++) {
		cout << "temp[" << a << "]: " << temp[a] << ", ";
		cout << "Size: " << temp.size() << endl;
	}

	cout << endl;
	//오름차순 정렬
	i.sortData(1);
	for (int a = 0; a < i.size(); a++) {
		cout << "Sort(Less) i[" << a << "]: " << i[a] << ", ";
		cout << "Size: " << i.size() << endl;
	}

	cout << endl;

	//내림차순 정렬
	i.sortData(0);
	for (int a = 0; a < i.size(); a++) {
		cout << "Sort(Greater) i[" << a << "]: " << i[a] << ", ";
		cout << "Size: " << i.size() << endl;
	}
	cout << endl;

	//resize()
	d.resize(23);
	cout << d.capacity() << endl;
}