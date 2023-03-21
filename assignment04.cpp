/******************************************************************************/
/* Skeleton provided by S. Bassil (Spring 2023)                               */
/*                                                                            */
/* Programmer: Bisshoy Anwar                                                  */
/*                                                                            */
/* Program: assignment04                                                      */
/*                                                                            */
/* Approximate Completion Time: 60 minutes                                    */
/******************************************************************************/

/*
   This program populates an array with 5 integers, search for a specific
   integer using linear search algorithm or binary search algorithm.
   This program also sorts the array in ascending or descending order
   using bubble sorting algorithm or selection sorting algorithm.
   At any time, the user can print out the integers in the array.
*/

#include <iostream>

using namespace std;

/* functions prototypes */
int linearSearch(int array[], int size, int value);
int binarySearch(int array[], int size, int value);
void bubbleAscendingSort(int array[], int size);
void bubbleDescendingSort(int array[], int size);
void selectionAscendingSort(int array[], int size);
void selectionDescendingSort(int array[], int size);
void swap(int*, int*);
void menu();
void printArray(int[], int);

const int ARRAY_LENGTH = 5;

int main()
{
	int userArray[ARRAY_LENGTH];
	int choice;
	int value; 
	bool sortedAscending = false;

	cout << "Input five integers: ";
	cin >> userArray[0] >> userArray[1] >> userArray[2] 
	    >> userArray[3] >> userArray[4];

	cout << "\nWhat would you like to do?" << endl << endl;
	menu();
	cin >> choice;

	while (!(choice >= 1 && choice <= 8)) {
		cout << "\nInvalid choice. Please 1, 2, 3, 4, 5, 6, 7 or 8: ";
		cin >> choice;
	}

	do
	{
		cout << endl;
		switch(choice) {
			case 1: // Linear Search
				cout << "Input the integer you're looking for: ";
				cin >> value;

				if (linearSearch(userArray, ARRAY_LENGTH, value) == -1) {
					cout << "\nThe integer you're looking for" 
					     << " is not in the array" << endl 
						 << endl;
				}

				else {
					cout << "\nThe integer you're looking for" 
					     << " is in the array at position ";
					cout << linearSearch(userArray, ARRAY_LENGTH, value) 
					     << endl << endl;
				}

				menu();
				cin >> choice;
				break;

			case 2: // Binary Search
				// Test for sortedAscending to be true
				if (sortedAscending == false) {
					cout << "The array is not in ascending order" 
					     << ", you can't use binary search." << endl;
					cout << "Sort the array in ascending order first," 
					     << " then repeat the binary search." << endl 
						 << endl;

					menu();
					cin >> choice;
					break;
				}

				cout << "Input the integer you're looking for: ";
				cin >> value;

				if (binarySearch(userArray, ARRAY_LENGTH, value) == -1) {
					cout << "\nThe integer you're looking for is not" 
					     << " in the array" << endl << endl;
				}

				else {
					cout << "\nThe integer you're looking for" 
					     << " is in the array at position ";
					cout << binarySearch(userArray, ARRAY_LENGTH, value) 
					     << endl << endl;
				}

				menu();
				cin >> choice;
				break;

			case 3: // Bubble Sort (Ascending)
				bubbleAscendingSort(userArray, ARRAY_LENGTH);
				sortedAscending = true;

				cout << "\nArray was sorted in ascending order" 
				     << " using the Bubble Sort" << endl << endl;

				menu();
				cin >> choice;
				break;

			case 4: // Bubble Sort (Descending)
				bubbleDescendingSort(userArray, ARRAY_LENGTH);
				sortedAscending = false;

				cout << "\nArray was sorted in descending order" 
				     << " using the Bubble Sort" << endl << endl;
				
				menu();
				cin >> choice;
				break;

			case 5: // Selection Sort (Ascending)
				selectionAscendingSort(userArray, ARRAY_LENGTH);
				sortedAscending = true;

				cout << "\nArray was sorted in ascending order using" 
				     << " the Selection Sort" << endl << endl;

				menu();
				cin >> choice;
				break;

			case 6: // Selection Sort (Descending)
				selectionDescendingSort(userArray, ARRAY_LENGTH);
				sortedAscending = false;
				
				cout << "\nArray was sorted in descending order using" 
				     << " the Selection Sort" << endl << endl;
				
				menu();
				cin >> choice;
				break;

			case 7: // Print out array
				printArray(userArray, ARRAY_LENGTH);
				cout << endl;

				menu();
				cin >> choice;
				break;

			case 8: // Quit
				break;

			default: // Invalid input catching
				cout << "Invalid choice. Please 1, 2, 3, 4, 5, 6, 7 or 8: ";
				cin >> choice;
				break;
		}

	} while (choice != 8);

	cout << "\nThank you for using my Program!" << endl;

	return 0;
}

/******************************************************************************/
/* Function: linearSearch                                                     */
/*                                                                            */
/* Description: Iterates straight through array until desired value is found  */
/*                                                                            */
/* Data in: array of integers, size of the array, the integer searching for   */
/*                                                                            */
/* Data out: position of the integer searching for if found, -1 otherwise     */
/******************************************************************************/

int linearSearch(int array[], int size, int value)
{
	for (int count = 0; count < size; count++) {
		if (array[count] == value) {
			// If found, returns array subscript
			return count;
		}
	}

	// If not found, returns -1;
	return -1;
}

/******************************************************************************/
/* Function: binarySearch                                                     */
/*                                                                            */
/* Description: Uses binary search to find value in array, returning -1 if    */
/*              value not found.										      */
/*                                                                            */
/* Data in: array of integers, size of the array, the integer searching for   */
/*                                                                            */
/* Data out: position of the integer searching for if found, -1 otherwise     */
/******************************************************************************/

int binarySearch(int array[], int size, int value)
{
	int first = 0;
	int last = size - 1;
	int middle;

	while (first <= last) {
		middle = first + (last - first) / 2;

		if (array[middle] == value) {
			return middle;
		}

		else if (array[middle] > value) {
			last = middle - 1;
		}

		else {
			first = middle + 1;
		}

	}

	// Return -1 if value not in array
	return -1;

}

/******************************************************************************/
/* Function: bubbleAscendingSort                                              */
/*                                                                            */
/* Description: Bubbles sorts in ascending order				              */
/*                                                                            */
/* Data in: array of integers, size of the array                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void bubbleAscendingSort(int array[], int size)
{
	bool switched;
	int bottom = size - 1;

	do
	{
		switched = false;

		for (int i = 0; i < bottom; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				switched = true; 
			}
		}

		bottom--;

	} while (switched != false);
}

/******************************************************************************/
/* Function: bubbleDescendingSort                                             */
/*                                                                            */
/* Description: Bubble sorts in descending order				              */
/*                                                                            */
/* Data in: array of integers, size of the array                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void bubbleDescendingSort(int array[], int size)
{
	bool switched;
	int bottom = size - 1;

	do
	{
		switched = false;

		for (int i = 0; i < bottom; i++) {
			if (array[i] < array[i + 1]) {
				swap(array[i], array[i + 1]);
				switched = true; 
			}
		}

		bottom--;

	} while (switched != false);
}

/******************************************************************************/
/* Function: selectionAscendingSort                                           */
/*                                                                            */
/* Description: Selection sorts in ascending order				              */
/*                                                                            */
/* Data in: array of integers, size of the array                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void selectionAscendingSort(int array[], int size)
{
	int seek;
	int minCount;
	int minValue;

	for (seek = 0; seek < (size - 1); seek++) {
		minCount = seek;
		minValue = array[seek];

		for (int index = seek + 1; index < size; index++) {
			if (array[index] < minValue) {
				minValue = array[index];
				minCount = index;
			}
		}

		array[minCount] = array[seek];
		array[seek] = minValue;
	}

}

/******************************************************************************/
/* Function: selectionDescendingSort                                          */
/*                                                                            */
/* Description: Selection sorts in descending order				              */
/*                                                                            */
/* Data in: array of integers, size of the array                              */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void selectionDescendingSort(int array[], int size)
{
	int seek;
	int minCount;
	int minValue;

	for (seek = 0; seek < (size - 1); seek++) {
		minCount = seek;
		minValue = array[seek];

		for (int index = seek + 1; index < size; index++) {
			if (array[index] > minValue) {
				minValue = array[index];
				minCount = index;
			}
		}

		array[minCount] = array[seek];
		array[seek] = minValue;
	}

}

/******************************************************************************/
/* Function: swap                                                             */
/*                                                                            */
/* Description: Switches variable values by pointer                           */
/*                                                                            */
/* Data in: Memory addresses whose values are to be swapped                   */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void swap(int* a, int* b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}

/******************************************************************************/
/* Function: menu                                                             */
/*                                                                            */
/* Description: Prints out a menu for the user	                              */
/*                                                                            */
/* Data in: None										                      */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void menu()
{
	cout << "   1- Find integer in array using Linear Search" << endl;
	cout << "   2- Find integer in array using Binary Search" << endl;
	cout << "   3- Sort integers in ascending order" 
	     << " using Bubble Sort" << endl;
	cout << "   4- Sort integers in descending order" 
	     << " using Bubble Sort" << endl;
	cout << "   5- Sort integers in ascending order" 
	     << " using Selection Sort" << endl;
	cout << "   6- Sort integers in descending order" 
	     << " using Selection Sort" << endl;
	cout << "   7- Print out integers in array" << endl;
	cout << "   8- Quit " << endl << endl;

	cout << "   Enter 1, 2, 3, 4, 5, 6, 7 or 8: ";
}

/******************************************************************************/
/* Function: printArray                                                       */
/*                                                                            */
/* Description: Prints out array (for ease of programming)                    */
/*                                                                            */
/* Data in: array of ints and size of array				                      */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}