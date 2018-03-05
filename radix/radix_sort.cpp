#include<iostream>
#include<fstream>
#include<time.h>
#include<chrono>

using namespace std;

int getMax(int arr[], int len);
void countSort(int arr[], int len, int term);
void radix_sort(int arr[], int len);


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
			radix_sort(arr, INPUTS[curr_size]);
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


int getMax(int arr[], int len)
{
    int cross = arr[0];
    for (int i = 1; i < len; i++)
        if (arr[i] > cross)
            cross = arr[i];
    return cross;
}

//uses counting sort
void countSort(int arr[], int len, int term)
{
    int out[len]; 
    int i, count[10] = {0};
 
    for (i = 0; i < len; i++)
        count[ (arr[i]/term)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 

    for (i = len - 1; i >= 0; i--)
    {
        out[count[ (arr[i]/term)%10 ] - 1] = arr[i];
        count[ (arr[i]/term)%10 ]--;
    }
    for (i = 0; i < len; i++)
        arr[i] = out[i];
}
 
void radix_sort(int arr[], int len)
{
    int max = getMax(arr, len);
 
    for (int term = 1; max/term > 0; term *= 10)
        countSort(arr, len, term);
}

