
#include<iostream>
#include<regex>
using namespace std;
int locateMaximum(const string[], int);
bool matchingValuesTogether(const string array[], int n);
bool hasDuplicates(const string array[], int  n);
string majorityElement(const string array[], int  n);
bool hasReverse(const string array[], int n);
int findLastOccurrence(const string array[], int n, string target);
int countFloatingPointValues(const string array[], int n);
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);

int main()
{
	const string fol[10] = { "samwell", "jon", "margaery", "daenerys",
						  "tyrion", "jon", "llewmas", "noj" };
	const string dat[6] = { "mama", "mama", "mama", "12,", "sansa", "mtama" };
	string peo[5] = { "howard", "pixie", "barak", "joe", "donald" };
	string de[4] = { "4.4.3.3", "+44", "-33.098", "33.098a" };
	cout << matchingValuesTogether(dat, 6);

}

// beginning of Xander's part

int locateMaximum(const string array[], int len) {
	int highest = 0;
	int index = 0;

	if (len <= 0) {
		return -1;
	}
	else {
		for (int i = 0; i < len; i++) {
			if (array[i].length() > highest) {
				highest = array[i].size();
				index = i;
			}
		}
	}

	return index;
}

bool hasDuplicates(const string array[], int len) {

	if (len <= 0) {
		return false;
	}
	else {
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (array[i] == array[j]) {
					return true;
				}
			}
		}
	}

	return false;

}

bool matchingValuesTogether(const string array[], int len) {


	if (len <= 0)
		return false;
	for (int i = 0; i < len; i++)
	{
		while (array[i] == array[i + 1])
		{
			i++;
		}
		for (int j = i; j < len; j++)
		{
			if (array[i] == array[j] && j - i > 1)
			{
				return false;
			}
		}

	}
	return true;

}

//end of xander's part

//start of victor B's part

string majorityElement(const string array[], int  n)
{
	int occurance = 0;
	for (int i = 0; i<n; i++)
	{
		for (int ii = i; ii < n; ii++)
		{
			if (array[ii] == array[i])
			{
				occurance++;
			}
				
		}
		if (occurance > n / 2) {
			return array[i];
		}
			
		occurance = 0;
	}
	return "";
}

bool hasReverse(const string array[], int n)
{
	if (n <= 0)return false;
	string reverse = "";
	char temp = '0';

	for (int i = 0; i < n; i++)
	{
		//reverse the word
		reverse = array[i];
		for (int j = 0; j < reverse.length() / 2; j++)
		{
			temp = reverse[j];
			reverse[j] = reverse[reverse.length() - 1 - j];
			reverse[reverse.length() - 1 - j] = temp;
		}

		//compare all values in the array to reversed word
		for (int ii = i; ii < n; ii++)
		{
			if (array[ii] == reverse)
				return true;
		}

		//revert the word back to how it was
		for (int j = 0; j < reverse.length() / 2; j++)
		{
			temp = reverse[j];
			reverse[j] = reverse[reverse.length() - 1 - j];
			reverse[reverse.length() - 1 - j] = temp;
		}
	}

	return false;
}

int findLastOccurrence(const string array[], int n, string target)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (array[i] == target)
			return i;
	}
	return -1;
}
//end of Victor B's part

//Start of Victor A's part

int countFloatingPointValues(const string array[], int n) {
	if (n <= 0)
	{
		return -1;
	}
	int count = 0;
	regex float_regex("[0-9]+(.)?[0-9]*");
	for (int i = 0; i < n; ++i) {
		if (regex_match(array[i].begin(), array[i].end(), float_regex))
		{
			count++;
		}
	}
	return count;
}


int replaceAll(string array1[], int n, char charToReplace, char letterToFill) {
	int replace_count = 0;
	if (n < 0) {
		return -1;
	}
	else {
		for (int i = 0; i < n; ++i)
		{
			for (auto it = array1[i].begin(); it != array1[i].end(); ++it) {
				if (*it == charToReplace) {
					++replace_count;
					*it = letterToFill;
				}
			}
		}
	}
	return replace_count;
}

//end of Victor A's part 