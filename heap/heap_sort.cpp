#include<iostream>
#include<fstream>
#include<time.h>
#include<chrono>

using namespace std;

void heapify(int arr[], int len, int i);
void heap_sort(int arr[], int len);


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
			heap_sort(arr, INPUTS[curr_size]);
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



void heapify(int arr[], int len, int i)
{
    int biggest = i;  
    int left = 2*i + 1; 
    int right = 2*i + 2;
 
    if (left < len && arr[left] > arr[biggest])
        biggest = left;
 
    if (right < len && arr[right] > arr[biggest])
        biggest = right;
 
    if (biggest != i)
    {
        swap(arr[i], arr[biggest]);
        heapify(arr, len, biggest);
    }
}
 
void heap_sort(int arr[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);
 
    for (int i = len - 1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}