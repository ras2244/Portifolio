//Author Ricardo Leal


#include <string>
#include <array>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//@ Vector<int>& and int with number of rotations.
// returns a Vector rotated with n number times.
vector<int> solution(vector<int> &, int);


//Create a vector with positive numbers.
void fill_myVector(vector<int>&, int);

//print a vector
void printVector(const vector<int>&);

int main()
{
	vector<int> A;
	unsigned int size = 0;
	unsigned int k;

	vector<int> B;
	cout << "Enter a Array size: ";
	
	cin >> size;	

	if (size < 0 || size>100) {
		do {
			cout << "please enter a number greater than 0 and less than 100" << endl;
			cout << "please try again: ";
			cin >> size;
		} while (size < 0 || size>100);
	}

	cout << "Enter number of rotations: ";
	cin >> k;

	if (k < 0 || k>100) {
		do {
			cout << "please enter a number greater than 0 and less than 100" << endl;
			cout << "please try again";
			cin >> k;
		} while (k < 0 || k>100);
	}

	fill_myVector(A, size);
	cout << "Rotating vector " << k << " times" << endl;	
	B = solution(A, k);
	printVector(B);

	return 0;
}

void printVector(const vector<int>& A) {
	cout << "A[";
	for (auto i = 0; i < A.size(); i++) {
		if (i < A.size() -1) {
			cout << A[i] << ",";
		}
		else {
			cout << A[i] << "]";;
		}

	}
	cout << endl;
}

void fill_myVector(vector<int>& myvector, int size) {
	cout << "Enter a your "<<size<<" numbers: ";
	int input=0;	
	int i=0;
	while (i != size) {	
		cin >> input;
		if (input < -1000 || input>1000) {
			do {
				cout << "please enter a number greater than -1000 and less than 1000" << endl;
				cout << "please try again";
				cin >> input;
			} while (input < 0 || input>100);
		}
		myvector.push_back(input);
		i++;
	}

}

vector<int> solution(vector<int> &A, int k) {
	
	int B;
	
	for (auto i = 0; i < k-1; i++) {
		B = A.front();
		A.erase(A.begin());
		A.push_back(B);
	}	 
	return A;
}	