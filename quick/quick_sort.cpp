#include<iostream>
#include<fstream>
#include<time.h>
#include<chrono> 

using namespace std;

void quick_sort(int arr[], int smallest, int largest);
int partition (int arr[], int smallest, int largest);
void swap(int* a, int* b);


int main(){
	
	const int ITERATIONS = 1; //number of runs for each input size
	const int NUMOFINPUTS = 11; //number of different input lengths (10, 50, 100, 500, etc)
	const int INPUTS[NUMOFINPUTS] = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};	//all different input lengths
	const int MIN_NUM = 0;	//smallest Random Number
	const int MAX_NUM = 65535; //largest random number
	int times[NUMOFINPUTS][10];	//array of sort times [2D if you want to change # of iterations]

	//seed random number generator
	srand((unsigned)time(NULL));

	//loop through however many input lengths denoted by NUMOFINPUTS
	for(int curr_size = 0; curr_size < NUMOFINPUTS; curr_size++){

		//loop through ITERATION number of iterations
		for(int curr_iter = 0; curr_iter < ITERATIONS; curr_iter++){

			int arr[INPUTS[curr_size]];	//array of random integers 0 - 65535
			
			//Defines array's indicies to numbers 0 - 65535
			for(int i = 0; i < INPUTS[curr_size]; i++){
				arr[i] = rand()%(MAX_NUM - MIN_NUM + 1) + MIN_NUM;
			}

			//printing array -- debugging
			/*
			cout << "{";
			for(int i = 0; i < INPUTS[curr_size]; i++){
				cout << arr[i] << " ";
			}
			cout << "}";
			*/


			//cout << "\n\t\t\t\t\tSorting...\n";
			
			//start timing sort
			auto started = std::chrono::high_resolution_clock::now();
			//sorting
			quick_sort(arr, 0, INPUTS[curr_size] - 1);
			//end timing sort
			auto done = std::chrono::high_resolution_clock::now();


			//printing sorted array -- debugging
			/*
			cout << "{";
			for(int i = 0; i < INPUTS[curr_size]; i++){
				cout << arr[i] << " ";
			}
			cout << "}";
			*/

			//calculating total runtime
			int runtime = std::chrono::duration_cast<std::chrono::microseconds>(done-started).count();
			times[curr_size][curr_iter] = runtime;
			
			//print sort time -- debugging
			/*
			cout << "\n\nElapsed Time: ";
			cout << runtime << " microseconds\n";
			*/
	
		}

	}
	
	//print array of 10 sort times for each size -- debugging
	/*
	cout << "\n"; 
	cout << "------------------------------------------------------------------------------------------";
	cout << "\n\n";
	for(int i = 0; i<NUMOFINPUTS; i++){
		cout << "[Run: " << i+1 << "] ";
		for(int j = 0; j < ITERATIONS; j++){
			cout << times[i][j] << " ";
		}
	cout << "\n";
	}
	cout << "\n";
	*/


	//printing results to txt file
	char filename[] = "output.txt";
    fstream file;

    file.open(filename, fstream::in | fstream::out | fstream::trunc);

	for(int i = 0; i<NUMOFINPUTS; i++){
		for(int j = 0; j < ITERATIONS; j++){
			if(j==ITERATIONS-1){
				file << times[i][j];
			}
			else
				file << times[i][j] << " ";
		}
		file << "\n";
	}

	file.close();





}

void quick_sort(int arr[], int smallest, int largest)
{
    if (smallest < largest)
    {
        int piv = partition(arr, smallest, largest);

        quick_sort(arr, smallest, piv  - 1);
        quick_sort(arr, piv + 1, largest);
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int smallest, int largest)
{
    int pivot = arr[largest];  
    int i = (smallest - 1);  
 
    for (int j = smallest; j <= largest- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[largest]);
    return (i + 1);
}
 