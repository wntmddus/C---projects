#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;
// initialize size of array as 100000000 
// use static dynamic array in order to avoid stack overflow
static int * array1 = new int [100000000];
static int * array2 = new int [100000000];
static int * array3 = new int [100000000];


// include comparison value as parameters in functions
// quicksort1 chooses last element in array as pivot
// quicksort2 chooses random element in array as pivot
// quicksort3 chooses median element in array as pivot
// in order to get comparison value for 100 mil number, put long long int instead of int
void quicksort1(int* input, int p, int r, int * comparison1);

int partition1(int* input, int p, int r, int & comparison1);

void quicksort2(int* input, int p, int r, int * comparison2);

int partition2(int* input, int p, int r, int & comparison2);

void quicksort3(int* input, int p, int r, int * comparison3);

int partition3(int* input, int p, int r, int & comparison3);


int main()

{
   srand(time(NULL));
	 int size;
	 double time;
	 int comparison1 = 0;
	 int comparison2 = 0;
	 int comparison3 = 0;
	 clock_t t1, t2, t3;

	 cout << "Type size of the array" << endl;

	 std::cin >> size;

	 for(int i = 0; i < size;i++)
	 {
		 array1[i] = rand();
	 }
	 array2 = array1;
	 array3 = array1;
	 // calculate time for 100000 or 1 mil or 10 mil or 100 mil numbers in array using quicksort of last element pivot	
	 t1 = clock();
	 quicksort1(array1, 0, size -1, &comparison1);
	 t1 = clock() - t1;
	 // calculate time for 100000 or 1 mil or 10 mil or 100 mil numbers in array using quicksort of random element pivot
	 t2 = clock();
	 quicksort2(array2, 0, size -1, &comparison2);
	 t2 = clock() - t2;
	 // calculate time for 100000 or 1 mil or 10mil or 100mil numbers in array using quicksort of median element pivot
	 t3 = clock();
	 quicksort3(array3, 0, size -1, &comparison3);
	 t3 = clock() - t3;

	 cout << "Array Size              : " << size << " " << endl;

	 cout << "Total Time(s) of QS1    : " << ((double)t1)/CLOCKS_PER_SEC << " Seconds"<<endl;

	 cout << "Total Time(s) of QS2    : " << ((double)t2)/CLOCKS_PER_SEC << " Seconds"<<endl;

	 cout << "Total Time(s) of QS3    : " << ((double)t3)/CLOCKS_PER_SEC << " Seconds"<<endl;

	 cout << "Comparisons in QS1      : " << comparison1 << " Number of comparisons"<<endl;

	 cout << "Comparisons in QS2      : " << comparison2 << " Number of comparisons"<<endl;

	 cout << "Comparisons in QS3      : " << comparison3 << " Number of comparisons"<<endl;
	
	 system("PAUSE");
//	 delete [] array1;

//	 delete [] array2;

//	 delete [] array3;

	 return 0;




}

// The quicksort recursive function 
// This sort chooses last element of array as pivot
void quicksort1(int* input, int p, int r, int * comparison1)
{
	if ( p < r )
    {
        int j = partition1(input, p, r, *comparison1);        
        quicksort1(input, p, j-1, comparison1);
        quicksort1(input, j+1, r, comparison1);
	}
}




// The quicksort recursive function
// This sort choose random number of elements in array as a pivot
void quicksort2(int* input, int p, int r, int * comparison2)
{
    if ( p < r )
    {
        int j = partition2(input, p, r, * comparison2);        
        quicksort2(input, p, j-1, comparison2);
        quicksort2(input, j+1, r, comparison2);
    }
}

// The quicksort recursive function
// This sort choose median number of elements in array as pivot
void quicksort3(int* input, int p, int r, int * comparison3)
{
    if ( p < r )
    {
        int j = partition3(input, p, r, * comparison3);        
        quicksort3(input, p, j-1, comparison3);
        quicksort3(input, j+1, r, comparison3);
	}
}
// The partition function
int partition1(int * input, int p, int r, int & comparison1)
{
    int pivot = input[r];
    while ( p < r )
    {
		comparison1++;
        while ( input[p] < pivot )
            p++;
        while ( input[r] > pivot )
            r--;
        if ( input[p] == input[r] )
            p++;
        else if ( p < r )
        {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
		}
    }
    return r;
}
// The partition function

int partition2(int* input, int p, int r, int & comparison2)
{
    int pivotIdx = p + rand() % (r-p);
    int pivot = input[pivotIdx];
    while ( p < r )
    {
		comparison2++;
        while ( input[p] < pivot )
            p++;
        while ( input[r] > pivot )
            r--;
        if ( input[p] == input[r] )
            p++;
        else if ( p < r )
        {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    return r;
}
// The partition function

int partition3(int* input, int p, int r, int & comparison3)
{
    int pivot = input[(p+r)/2];
    while ( p < r )
    {
		comparison3++;
        while ( input[p] < pivot )
            p++;
        while ( input[r] > pivot )
            r--;
        if ( input[p] == input[r] )
            p++;
        else if ( p < r )
        {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }
    return r;
}
