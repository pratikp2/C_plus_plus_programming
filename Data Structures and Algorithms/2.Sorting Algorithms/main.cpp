# include<iostream>
#define MAX_SIZE 7

void Bubble_Sort(int arr[]) // Time Complexity : O(n²)
{
	for (int i = 0; i < MAX_SIZE - 1; i++)
		for (int j = 0; j < MAX_SIZE - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void Selection_Sort(int arr[]) // Time Complexity : O(n²)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		int minindex = i;
		for (int j = i + 1; j < MAX_SIZE; j++)
			if (arr[j] < arr[minindex])
				minindex = j;

		int temp = arr[i];
		arr[i] = arr[minindex];
		arr[minindex] = temp;
	}
}

void Insertion_Sort(int arr[]) // Time Complexity : O(n²)
{
	for (int i = 1; i < MAX_SIZE; i++)
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

void Merge_Sort(int arr[], int leftStart, int rightEnd) // Time Complexity : O(n*log(n))
{
	if (leftStart >= rightEnd)
		return;

	// Sort Logic
	int middle = leftStart + (rightEnd - leftStart) / 2;
	Merge_Sort(arr, leftStart, middle);
	Merge_Sort(arr, middle + 1, rightEnd);

	// Merge Logic
	{
		int leftSize = middle - leftStart + 1;
		int rightSize = rightEnd - middle;

		int* leftArray = new int[leftSize];
		int* righArray = new int[rightSize];

		int leftItr = 0, rightItr = 0;
		int mainItr = leftStart;

		for (leftItr = 0; leftItr < leftSize; leftItr++)
			leftArray[leftItr] = arr[leftStart + leftItr];
		for (rightItr = 0; rightItr < rightSize; rightItr++)
			righArray[rightItr] = arr[middle + 1 + rightItr];

		leftItr = rightItr = 0;

		while (leftItr < leftSize && rightItr < rightSize)
		{
			if (leftArray[leftItr] <= righArray[rightItr])
			{
				arr[mainItr] = leftArray[leftItr];
				leftItr++;
			}
			else
			{
				arr[mainItr] = righArray[rightItr];
				rightItr++;
			}
			mainItr++;
		}

		while (leftItr < leftSize)
		{
			arr[mainItr] = leftArray[leftItr];
			leftItr++;
			mainItr++;
		}

		while (rightItr < rightSize)
		{
			arr[mainItr] = righArray[rightItr];
			rightItr++;
			mainItr++;
		}

		if (leftArray != nullptr)
			delete[] leftArray;
		if (righArray != nullptr)
			delete[] righArray;

		leftArray = righArray = nullptr;
	}
}

void Quick_Sort(int arr[], int leftStart, int rightEnd) // Time Complexity : O(n*log(n))
{
	if (leftStart < rightEnd)
	{
		// Partition Logic		
		int partitionIndex = leftStart;
		int pivot = arr[rightEnd];

		for (int i = leftStart; i < rightEnd; i++)
		{
			if (arr[i] <= pivot)
			{
				std::swap(arr[i], arr[partitionIndex]);
				partitionIndex++;
			}
		}
		std::swap(arr[partitionIndex], arr[rightEnd]);

		// Sort Logic
		Quick_Sort(arr, leftStart, partitionIndex - 1);
		Quick_Sort(arr, partitionIndex + 1, rightEnd);
	}
}

void Print_Array(int arr[])
{
	std::cout << "Sorted sequence : ";
	for (int i = 0; i < MAX_SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int arr[MAX_SIZE] = { 1, 23, 41, 5, 14, 20, 33 };

	//Bubble_Sort(arr);
	//Selection_Sort(arr);
	//Insertion_Sort(arr);
	//Merge_Sort(arr, 0, MAX_SIZE - 1);
	Quick_Sort(arr, 0, MAX_SIZE - 1);

	Print_Array(arr);

	return 0;
}
