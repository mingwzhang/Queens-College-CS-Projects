#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_without_sort(vector<int> a, vector<int> b) {
	vector<int> result;
	int i = 0, j = 0, n = a.size(), m = b.size();
		
	while (i < n && j < m) { //while both indexes are within range
		if (a[i] <= b[j]) { //if element from vector a <= element from vector b
			result.push_back(a[i]); //push this element
			++i; //move onto next index in vector a
		} else { //otherwise consider element from vector b
			result.push_back(b[j]); //push this element
			++j; //move onto next index in vector b
		}
	}
	
	if (i < n) { //if there are still elements left in vector a
		while (i < n) {
			result.push_back(a[i]);
			++i;
		}
	} else { //otherwise consider elements in vector b
		while (j < m) {
			result.push_back(b[j]);
			++j;
		}
	}
	
	return result;
}

void sort(vector<int>& v) { //gnome sort, look it up
	int i = 0, temp, size = v.size();
	
	while (i < size) {
		if (i == 0) {
			++i;
		} else if (v[i-1] <= v[i]) {
			++i;
		} else {
			temp = v[i];
			v[i] = v[i-1];
			v[--i] = temp;
		}
	}
}

//vectors a and b are being passed by value, so pop_back() won't affect the original vector arguments
vector<int> merge_with_sort(vector<int> a, vector<int> b) {
	vector<int> result;
	
	while (a.size() > 0) {
		result.push_back( a.back() );
		a.pop_back();
	}
	
	while (b.size() > 0) {
		result.push_back( b.back() );
		b.pop_back();
	}
	
	sort(result); //implement your favorite sorting algorithm
	
	return result;
}

int main() {
	vector<int> a;
	a.push_back(2);
	a.push_back(4);
	a.push_back(6);
	a.push_back(8);
	
	vector<int> b;
	b.push_back(1);
	b.push_back(3);
	b.push_back(7);
	b.push_back(10);
	b.push_back(13);
	
	cout << "Merged without sorting..." << endl;
	
	vector<int> merged = merge_without_sort(a, b);
	int size = merged.size();
	
	for (int i = 0; i < size; ++i)
		cout << merged[i] << ' ';
	cout << endl;
	
	cout << "Merged with sorting..." << endl;
	
	merged = merge_with_sort(a, b);
	
	for (int i = 0; i < size; ++i)
		cout << merged[i] << ' ';
	cout << endl;
	
	return 0;
}