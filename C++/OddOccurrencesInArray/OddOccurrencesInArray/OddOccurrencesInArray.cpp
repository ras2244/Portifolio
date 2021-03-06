// OddOccurrencesInArray.cpp : Defines the entry point for the console application.
//Codility test
//Author Ricardo Leal

#include <vector>
#include<iostream>
#include <cstdlib>

using namespace std;

int solution(vector<int> &);


void fill_MyVector(vector<int> &, int);

void printVector(const vector<int>&);



int main()
{
	vector<int> A;
	int size = 5;

	fill_MyVector(A, size);
	
	return 0;
}

void fill_MyVector(vector<int>& myvector, int size) {

	int *oddnumbers;
	int odd = 1;
	oddnumbers = new int[size];
	
	for (int i = 0; i < size; i++) {
		if (odd == 1){
			oddnumbers[i] = odd;
		}
		else {
			oddnumbers[i] = odd;
		}
		odd += 2;
	}

	for (int i = 0; i < size; i++) {
		cout << oddnumbers[i];
		myvector.push_back(oddnumbers[i]);		
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << myvector[i];
		myvector.push_back(oddnumbers[i]);
	}
	cout << endl;

	delete oddnumbers;
	
}

//int solution(vector<int> &A) {
//
//}

void printVector(const vector<int>& A) {
	cout << "A[";
	for (int i = 0; i < A.size(); i++) {
		if (i < A.size() - 1) {
			cout << A[i] << ",";
		}
		else {
			cout << A[i] << "]";;
		}

	}
	cout << endl;
}

