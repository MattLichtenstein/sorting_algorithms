#include<iostream>
#include<fstream>
#include<time.h>
#include <chrono>

using namespace std;

void merge(int arr[], int left, int middle, int right);
void merge_sort(int arr[], int left, int right);

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
			merge_sort(arr, 0, INPUTS[curr_size]);
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


void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {

        int middle = left + (right - left)/2;
 
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
 
        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int a;
    int b;
    int c;
    int temp = middle - left + 1;
    int temp2 =  right - middle;
 
    int Larr[temp];
    int Rarr[temp2];
 
    for (a = 0; a < temp; a++)
        Larr[a] = arr[left + a];
    for (b = 0; b < temp2; b++)
        Rarr[b] = arr[middle + 1+ b];
 
    a = 0;
    b = 0; 
    c = left;
    while (a < temp && b < temp2)
    {
        if (Larr[a] <= Rarr[b])
        {
            arr[c] = Larr[a];
            a++;
        }
        else
        {
            arr[c] = Rarr[b];
            b++;
        }
        c++;
    }
 
    while (a < temp)
    {
        arr[c] = Larr[a];
        a++;
        c++;
    }
 
    while (b < temp2)
    {
        arr[c] = Rarr[b];
        b++;
        c++;
    }
}
 
