#include <bits/stdc++.h>
using namespace std;

// NOT REALLY A LENGTHY CODE :P JUST FULL OF EASY EXPLANATION

int main()
{
	string numbers[10]={"zero","one","two","three","four","five","six","seven","eight","nine"}; // to refer

    int test_cases; 
    cin>>test_cases;
    while(test_cases--) // test case loop
    {

    	int crates[100]; // array of weights (max crates given = 100)
    	int c=0; // counter for number of crates and to insert the number in above array

    	char ch; // to detect either comma or dot

		do // take crates
		{

			// notice that the weight is always a three digit number
			int d1,d2,d3; // let the number be d1d2d3
			string s1,s2,s3; // each number of 3 digit 
			cin>>s1>>s2>>s3;

			// we will store the entire number in d1	

			// start from d1
			for(int i=0;i<=9;i++)
			{
				if(numbers[i]==s1)     // if digit found
					d1=i;     // assign it
			}

			//current number -> d1
			d1=d1*10;
			//current number -> d10

			// move for d2
			for(int i=0;i<=9;i++)
			{
				if(numbers[i]==s2)     // if digit found
					d1=d1+i;     // append it to target number
				// above line makes the number to be d1d2
			}

			//current number -> d1d2
			d1=d1*10;
			//current number -> d1d20

			// before we move to s3, we know s3 consists of a comma or dot at the end
			// so first store the character in variable ch for while condition
			// and pop the last character of s3 to compare s3 with numbers array

			ch=s3[s3.length()-1]; // last character
			s3.resize(s3.length()-1); // deletes last character

			// move for d3
			for(int i=0;i<=9;i++)
			{
				if(numbers[i]==s3)     // if digit found
					d1=d1+i;     // append it to target number
				// above lines makes the number to be d1d2d3
			}

			//finally d1 has value d1d2d3

			crates[c]=d1; // add it to array of weights
			c++; // count

		}
		while(ch!='.'); // while we don't hit the dot   	

		// Now we have the weights in integer form
		
		int position[c]; // Initial positions of crates, c being the total number of crates
		for(int i=0;i<c;i++)
		{
			position[i]=i+1; // 1-based indexing
		}	

		// we will rearrange the positions array according to the way the crates array is sorted to obtain the answer
		int temp;
		for(int i=0;i<c-1;i++)
		{
			for(int j=i+1;j<c;j++)
			{
				if(crates[j]>crates[i])  // sort in descending order
				{
					temp=crates[j];
					crates[j]=crates[i];
					crates[i]=temp;

					//also arrange positions accordingly
					temp=position[j];
					position[j]=position[i];
					position[i]=temp;
				}
			}
		}

		// finally print the required order (positions)
		for(int i=0;i<c;i++)
		{
			cout<<position[i]<<" ";
		} 
		cout<<endl; 

    }
    return 0;
} 
