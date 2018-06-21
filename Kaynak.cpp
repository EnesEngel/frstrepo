#include <iostream>
using namespace std;
class Array {
	int *data, size = 0, capacity;
public:
	Array() {
		capacity = 5;
		data = new int[capacity];
	}
	Array(int x)
	{

		capacity = x;
		data = new int[capacity];
	}
	void printItems() {
		cout << "\n";
		for (int i = 0; i < size; i++) {
			cout << data[i] << "-";
		}
		cout << "\ncapacity = " << capacity << " size = " << size << "\n";

	}
	void addItem(int x) {

		if (capacity <= size) {
			int *tra = new int[capacity * 2];
			for (int i = 0; i < size; i++) {
				tra[i] = data[i];
			}
			capacity = capacity * 2;
			data = tra;

		}
		data[size] = x;
		size++;
	}
	void removeIndexItem(int index) {
		if (index > -1 && index < size) {
			for (int i = index; i < size; i++) {
				data[i] = data[i + 1];
			}
			size--;
		}
		else {
			cout << "ERROR No item at the index " << index << "\n";
		}
	}
	void trim() {
		capacity = size;
		int *tra = new int[capacity];
		for (int i = 0; i < size; i++) {
			tra[i] = data[i];
		}

		data = tra;
	}
	int findIndex(int x) {
		for (int i = 0; i <= size; i++) {
			if (data[i] == x) {
				return i;
			}
		}
		return -1;
	}
	int findIndex(int x, int index) {
		for (int i = index; i < size; i++) {
			if (data[i] == x) {
				return i;
			}

		}
		return -1;
	}
	void removeItem(int x) {

		while (findIndex(x) != -1) {
			removeIndexItem(findIndex(x));
		}

		/*	int a=0;
		for (int i = 0; i < size; i++) {
		if (data[i] == x) {
		data[i] = data[i + 1];
		a++;
		}
		}
		size-=a;*/
	}
	void subtractArray(Array A) {
		int a;
		for (int i = 0; i < size; i++) {
			for (a = 0; a < A.size; a++) {
				if (data[i] == A.data[a]) {
					removeIndexItem(i);
				}
			}
		}
	}
	void addArray(Array A) {
		if (capacity < size + A.size) {
			int *tra = new int[capacity * 2];
			for (int i = 0; i < size; i++) {
				tra[i] = data[i];
			}
			capacity = capacity * 2;
			data = tra;

		}
		for (int i = 0; i <A.size; i++) {
			data[size] = A.data[i];
			size++;
		}

	}

};
int main() {
	Array a;
	a.printItems(); // should print each item in the array. Aldo prints size and capacity
	a.addItem(1); a.addItem(2); a.addItem(9);
	a.addItem(3); a.addItem(4); a.printItems();
	a.addItem(5); a.addItem(3); a.addItem(6); a.printItems();
	a.removeIndexItem(2); //remove the item at that index
	a.removeIndexItem(-1); //if index value is wrong, it will give an error message
	a.removeIndexItem(18); //if index value is wrong, it will give an error message
	a.printItems();
	a.trim(); //it will trim the unused place in the array
	a.printItems();
	a.addItem(7); a.addItem(8); a.printItems();
	cout << "The item 17 is located at " << a.findIndex(17) << endl;
	cout << "The item 3 is located at " << a.findIndex(3) << endl;
	cout << "The item 3 located after index 4 is " << a.findIndex(3, 4) << endl;
	cout << "The item 3 located at after index 6 is " << a.findIndex(3, 7) << endl;
	a.removeItem(17); //remove the all items with the same value
	a.printItems();
	a.removeItem(3); a.printItems();
	a.trim(); a.printItems();
	Array b(2); //Second constructor with one parameter. Capacity should set as 2
	b.printItems();
	b.addItem(33); b.addItem(1); b.printItems();
	a.subtractArray(b); //delete the items which exist in arry b
	a.printItems();
	a.addArray(b); //add items at the end of the array
	a.printItems();

}