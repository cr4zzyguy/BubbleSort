//Viacheslav Sadkov

//I create a vector of 1,000 random integers (all < 10,000) and saved them in an output file.  
//Use vectors and iteractors thoughout your code.
//The resulting file of random integers should contain no duplicates.  


#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <vector>
#include <fstream>
using namespace std; 


void ShortBubble(vector<int>& values, int numValues);
void BubbleUp2(vector<int>& values, int startIndex, int endINdex,
			   bool& sorted);
inline void Swap(int& item1, int& item2);
bool check(vector<int>&,int); //checks the vector for duplicates
void outputIntegers(vector<int>&,ofstream&);

int main() 
{     
     srand((unsigned)time(0));
	 vector<int> randomIntegers(1000);
	 ofstream outData;
	 outData.open("output.txt");
	 //Fills the vector with random integers
	 for(vector<int>::iterator i = randomIntegers.begin();i!=randomIntegers.end();
		 ++i)
	 {
		 //Checks for duplicates upon inserting
		 bool inserted = false;
		 while(inserted != true)
		 {
			int num = (rand()%10000)+1;
			if (check(randomIntegers,num) != true){
				*i = num;
				inserted = true;
			}
		 }
	 }
	 ShortBubble(randomIntegers,randomIntegers.size());
	 outputIntegers(randomIntegers,outData);
	 cout << "Bubble Sort complete." << endl;
	 system("pause");
     return 0;
}

// Post: The elements in the array values are sorted by key.
//		 The process stops as soon as values is sorted.
void ShortBubble(vector<int>& values, int numValues)

{
	int current = 0;
	bool sorted = false;
	while (current < numValues - 1 && !sorted)
	{
		BubbleUp2(values, current, numValues-1, sorted);
		current++;
	}
}


// Post: Adjacent pairs that are out of order have been switched
//		 between values[startIndex]...values[endIndex] beginning at 
//		 values[endIndex].
//		 sorted is false if a swap was made and true otherwise.
void BubbleUp2(vector<int>& values, int startIndex, int endIndex,
			   bool& sorted)
{
	sorted = true;
	for (int index = endIndex; index > startIndex; index--)
		if (values[index] < values[index-1])
		{
			Swap(values[index], values[index-1]);
			sorted = false;
		}
}


//Post Contents of item1 and item2 have been swapped.
inline void Swap(int& item1, int& item2)
{
	int tempItem;
	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}


 //Outputs the vector contents to a file
void outputIntegers (vector<int>& randomIntegers, ofstream& outData)
{
	 for(vector<int>::iterator j = randomIntegers.begin();j!=randomIntegers.end();
		 ++j)
	 {
		 outData << *j << endl;
	 }

}

//Checks vector for duplicates
bool check(vector<int>& randomIntegers, int num)
{
	for(vector<int>::iterator i = randomIntegers.begin();i!=randomIntegers.end();++i)
	{
		if (*i == num)
			return true;
	}
	return false;
}

/*
Bubble Sort complete.
Press any key to continue . . .
*/