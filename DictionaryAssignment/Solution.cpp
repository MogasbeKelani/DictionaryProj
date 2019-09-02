/* Mohammed Mogasbe
 Xcode on a Mac
**If the files have been removed feel free to make your own
**for testing reasons
 
 
 */
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const string dictionaryFile = "unsorted dictionary.txt"; //16000 word File
const string vocabFile = "keywords.txt"; // 84 word File
const string outFileName = "output.txt"; // output file
void selectionSort(string array[], int size); // selection sort function
void printArray(string array[],int sizeofArray); // printing array function
int binarySearch(string [], int, string);// binary search function
int main()
{
    ifstream inFileBig;
    ifstream inFileSmall;
    ofstream outFile;
    inFileBig.open(dictionaryFile); //opening 16000 word file
    inFileSmall.open(vocabFile); // opening 84 word file
    outFile.open(outFileName); //opening output file
    string dictionaryWords; // variable that takes the words in the dictionary file
    string dictionaryArray[16000]; // array 0-15999
    string vocabWords;// variable that takes the words in the smaller word file
    string vocabArray[84]; // array 0-83
    int i = 0; // used to move through the big array
    int n= 0; // used to move through the small array
    int count = 0; // used to count the words not found in the bigger file using the binary search
   
    if(inFileBig.fail()) // Check for big file opening
    {
        cout<<" The File Named: "<<dictionaryFile<<" could not be opened...."<<endl;
    }
    if(inFileSmall.fail())
    {
        cout<<" The File Named: "<<vocabFile<<" could not be opened...."<<endl; // Check for small file opening
    }
    if(outFile.fail())
    {
        cout<<"The File Named: "<<outFileName<<" could not be opened...."<<endl; // Check for output file opening
    }
   
    while(inFileBig>>dictionaryWords) // loop creating dictionary array
    {
        dictionaryArray[i++]=dictionaryWords;
    }
    while(inFileSmall>>vocabWords) // loop creating vocab array
    {
        vocabArray[n++]=vocabWords;
    }
    selectionSort(dictionaryArray,16000); // sorting dictionary array for binary search
    selectionSort(vocabArray,84); // sorting vocab array for binary search
    
    for (int i = 0; i < 16000; i++)
    {
    int result = binarySearch(dictionaryArray,16000,vocabArray[i]);// searching the dictionary array while moving through the vocab array
        if (result == -1) // if keyword not found
        {
            outFile<< "keyword not found: " << vocabArray[i] << endl;
            count++; // counts how many times this if statement is repeated
        }
    }
    cout << "Number of keywords not found = " << count << endl; // the amount is displayed here
    
    
    
    return 0;
}

void selectionSort(string array[], int size) // sorting the array
{
    int i; // moves through the array
    int miniIndex; // minimum index of the selection sort
    string miniValue; // minimum string value
    
    for(i = 0; i < (size -1); i++)
    {
        miniIndex = i;
        miniValue = array[i]; // scanning begins
        for(int index = i +1; index < size; index++) // sorting by alphabetical order
        {
            if (array[index] < miniValue)
            {
                miniValue = array[index];
                miniIndex = index;
            }
        }
        array[miniIndex] = array[i];
        array[i] = miniValue;
    }
}

void printArray(string array[],int size) //Wasn't neccessary just for my own testing purposes
{
    for(int x=0; x<size; x++)
    cout <<array[x]<<endl;
}
int binarySearch(string array[], int size, string words) //Binary Search
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == words)
        {
            return mid;
        }
        else if (words > array[mid])
        {
            high = high;
            low = mid + 1;
        }
        else
        {
            low = low;
            high = mid - 1;
        }
    }
    return -1;
}
