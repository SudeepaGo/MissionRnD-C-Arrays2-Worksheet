/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

int isEqual(char *, char *);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0, index=0, count=0;

	while (i < len)
	{
		if (isEqual(Arr[i].date, date)) //Finding the index in Arr whose date matches the given date
		{
			index = i;
			break;
		}
		else
		{
			i++;
			if (i == (len - 1)) return 0; //Return 0 if given date is not present in Arr
		}
	}

	for (i = 1; i < len; i++)  //Checking if all the dates in Arr are same
	{
		if (isEqual(Arr[0].date, Arr[i].date))
			count++;
	}
	if (count == len - 1) 
		return 0; //Return 0 if all dates in Arr are same
	else
	   count = len - index - 1; //Finding the count of transactions after the given date
	return count;
}

//Function to check if two given dates are the same

int isEqual(char *date1, char *date2) {

	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0, t, u, i;
	
		for (i = 0; i < 2; i++) //Finding the day values in dob1 and dob2
		{
			t = date1[i] - '0';
			d1 = t + d1 * 10;
			u = date2[i] - '0';
			d2 = u + d2 * 10;
		}
		for (i = 3; i < 5; i++) // Finding the month values in dob1 and dob2
		{
			t = date1[i] - '0';
			m1 = t + m1 * 10;
			u = date2[i] - '0';
			m2 = u + m2 * 10;
		}
		for (i = 6; i < 10; i++) // Finding the year values in dob1 and dob2
		{
			t = date1[i] - '0';
			y1 = t + y1 * 10;
			u = date2[i] - '0';
			y2 = u + y2 * 10;
		}
		if (y1 == y2 && m1 == m2 && d1 == d1)
			return 1;
		else return 0;
}