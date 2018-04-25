// By Brett Gilman and Jordan Ruckle
// 4/22/2018
// TestBed.cpp

/////////////// PURPOSE ///////////////
// The purpose of this program is to //
// test the five functions that will //
// be implemented in Functions.h     //
///////////////////////////////////////

//importing functions
#include<iostream>
#include"Functions.h"
#include<algorithm>

//from iostream
using std::cout;
using std::cin;
using std::endl;

//from algorithm
using std::sort;

//function for printing vectors
void PrintVector(vector<int> Vec, string VecName);
//function for testing if the custom sort function was successful
void CheckSort(vector<int> VecSTL, vector<int> VecCustom);

int main()
{
	///////////////// TESTING QUICKSORT /////////////////
	vector<int> QuickSortVec = {8,9,6,5,7,8,3,2,1,0,10,4}; //vector for testing quicksort function
	/* Manual Checking:
	//print the unsorted vector
	PrintVector(QuickSortVec, "Quick Sort Vector (unsorted)");
	//sort the vector
	QuickSort(QuickSortVec, 0 ,QuickSortVec.size() - 1);
	//print the sorted vector
	PrintVector(QuickSortVec, "Quick Sort Vector (sorted)");
	*/

	/*Auto Checking:*/
	cout << "Testing QuickSort Function: ";
	vector<int> QuickSTLVec = { 8,9,6,5,7,8,3,2,1,0,10,4 }; //vector for testing quicksort function
	QuickSort(QuickSortVec, 0, QuickSortVec.size() - 1); //sort the vector
	CheckSort(QuickSTLVec, QuickSortVec); //check if the STL sorted vector and the custom sort vector are the same

	/////////////////////////////////////////////////////

	///////////////// TESTING BINARY SEARCH /////////////////
	//print the unsorted vector
	//using the sorted quick sort vector from previous test:
	PrintVector(QuickSortVec, "Quick Sort Vector (sorted)");
	//sort the vector
	int result = BinarySearch(QuickSortVec, 8, 0, QuickSortVec.size() - 1);
	cout << "Looking for 8 (-1 if not found): " << result << endl;
	result = BinarySearch(QuickSortVec, 4, 0, QuickSortVec.size() - 1);
	cout << "Looking for 4 (-1 if not found): " << result << endl;
	result = BinarySearch(QuickSortVec, 15, 0, QuickSortVec.size() - 1);
	cout << "Looking for 15 (-1 if not found): " << result << endl;
	result = BinarySearch(QuickSortVec, -2, 0, QuickSortVec.size() - 1);
	cout << "Looking for -2 (-1 if not found): " << result << endl;
	result = BinarySearch(QuickSortVec, 10, 0, QuickSortVec.size() - 1);
	cout << "Looking for 10 (-1 if not found): " << result << endl;
	result = BinarySearch(QuickSortVec, 9, 0, QuickSortVec.size() - 1);
	cout << "Looking for 9 (-1 if not found): " << result << endl;
	/////////////////////////////////////////////////////////

	///////////////// TESTING MERGERSORT /////////////////
	vector<int> MergeSortVec = { 38,27,43,3,9,82,10 }; //vector for testing mergesort function
	//print the unsorted vector
	PrintVector(MergeSortVec, "Merge Sort Vector (unsorted)");
	//sort the vector
	MergeSort(MergeSortVec, 0, 6);
	//print the sorted vector
	PrintVector(MergeSortVec, "Merge Sort Vector (sorted)");
	/////////////////////////////////////////////////////


	//allow the user to see the data
	int temp = 0;
	cin >> temp;

	return 0; //terminate the function
}

void PrintVector(vector<int> Vec, string VecName)
{
	//print header with the passed in name
	cout << "------------------------------" << endl;
	cout << "Printing Out Vector: " << VecName << endl;
	//print all the elements
	for (int i = 0; i < Vec.size(); i++)
		cout << Vec[i] << endl;
	cout << "------------------------------" << endl;
}

//The purpose of this function is to test if two vectors are the same. The VecSTL is sorted before the comparison
//happens and VecCustom is assumed to already be sorted
void CheckSort(vector<int> VecSTL, vector<int> VecCustom)
{
	//assuming VecCustom is already sorted
	//sort VecSTL using the STL sort
	sort(VecSTL.begin(), VecSTL.end());
	//if the vectors are the same size
	if (VecSTL.size() == VecCustom.size())
	{
		//iterate throught the vectors and check if they are equal to each other
		for (int i = 0; i < VecSTL.size() - 1; i++)
		{
			//if one element is not the same
			if (VecSTL[i] != VecCustom[i])
			{
				cout << "Failed" << endl;
				return; //return that they are not the same
			}
		}
		cout << "Passed" << endl;
		return; //if program gets here, the two vectors were the same
	}
	else
	{
		cout << "Failed" << endl;
		return; //vectors are not the same size so they are not equal
	}
}