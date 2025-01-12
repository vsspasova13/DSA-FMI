#include <iostream>
#include <vector>
using namespace std;


void bubbleSort(int arr[], int n)
{
	bool swapped;
	for (size_t i = 0; i < n-1; i++)
	{
		swapped = false;
		for (size_t j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j+1], arr[j]); swapped = true;
			}
		}
		if (!swapped)break;
	}
}

void selectionSort(int arr[], int n)
{
	for (size_t i = 0; i < n-1; i++)
	{
		int minIndex = i;
		for (size_t j = i+1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])minIndex = j;
		}
		if (minIndex != i)
			std::swap(arr[i], arr[minIndex]);
	}
}

void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void merge(int arr[], int start, int middle, int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;

	vector<int> left(n1), right(n2);

	for (int i = 0; i <n1; i++)
	{
		left[i]=arr[start + i];
	}

	for (int j = 0; j < n2; j++)
	{
		right[j]=arr[middle+1+j];
	}

	int i = 0, j = 0, k = start;
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i++];
		}
		else arr[k] = right[j++];

		k++;
	}

	while (i < n1)
	{
		arr[k++] = left[i++];
	}

	while (j < n2)
	{
		arr[k++] = right[j++];
	}
}

void mergeSort(int arr[], int start, int end)
{
	if (start < end) {
		int mid = start + (end - start) / 2;
		mergeSort(arr, start,mid);
		mergeSort(arr, mid + 1, end);


		merge(arr, start, mid, end);
	}
}

int partititon(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low-1;

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			std::swap(arr[i], arr[j]);
			
		}
	}
	std::swap(arr[i+1], arr[high]);
	return i+1;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partititon(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);

	}
}

void printArray(char arr[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void countingSort(char arr[], int n)
{
	char* arrCpy = new char[n];
	for (size_t i = 0; i < n; i++)
	{
		arrCpy[i] = arr[i];
	}

	int count[256]{ 0 };

	for (size_t i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}
	
	for (size_t i = 1; i <= 255; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		arr[count[arrCpy[i]] - 1] = arrCpy[i];
		count[arrCpy[i]] = count[arrCpy[i]] - 1;
	}
}



int main() 
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Test Merge Sort


	//cout << "Original array: \n";
	//printArray(arr, n);

	//cout << "Testing Merge Sort:\n";
	//mergeSort(arr, 0, n - 1);
	//printArray(arr, n);
	char ch[] = { "bjwiowoisa3fx" };
	countingSort(ch, 14);
	// Test Quick Sort
	//cout << "Testing Quick Sort:\n";
	//quickSort(arr, 0, n - 1);
	printArray(ch, 14);

}

