/*
Question:

Given an input integer and we can at most flip one bit from 0->1, get the length of the longest subsequence of 1s that 
can be formed.

 given example:

i/p : 1775 (11011101111)
o/p : 8

*/

/*
My Approach (niave one):

Get the count of 0s and 1s in the i/p no as well as length of the input number in terms of number of bytes.

Convert the given binary number into an array with character count
Made a hashmap of my own using struct array to store the count of 0s and 1s 
ex:
1775 (11011101111)
array => 2 1s 1 0s 3 1s 1 0s 4 1s

My own Hash data structure:
count Bit
  2    1
  1    0
  3    1
  1    0
  4    1

struct hash hash_array[length] use karna isme

TC => O(number of bits in n)
SC => O(height*width)=O(n*2)=O(n)

see code for further logic

*/

#include<iostream>
using namespace std;

//creating my own hash data structure
struct Hash_Map
{
	int count=0;
	int bit;     //its either 1 or 0
};

//isko sorting se bhi bana sakte hai but I tried to keep constant time complexity
int max(int a,int b)
{
	//when every input is of different size
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
	
}

//Counts numbers of 1s and 0s from right to left and fills the hash table
void fill_table(int n)
{
	int i=0; //to keep track of index
	
	//traverse from right to left 
	while(n!=0)
	{
		//if current bits is 1 set i
		if((n&1)==1)
		{
			Hash_Map[i].bit==1;
			Hash_Map[i].count++;
			i++;
		}
		//if current bits is 0 set i
		else if((n&1)==0)
		{
			Hash_Map[i].bit==0;
			Hash_Map[i].count++;
			i++;
		}
		
	n>>=1;
	//jis i pe loop break hua usko preserve karo
	int i_break=i;
	
	}
	
	//jab n 0 ho jaaye to us index ke aage end mark kar do (I denoted end by ascii value of ***)
	int END=(int)'***';
	Hash_Map[i_break+1].bit=END;
	Hash_Map[i_break+1].count=END;
	
}

int lengthof1s(int n)
{
	int max_length=0,i=0,L=0,R=0;
	
	//traverse the hash map i have created above till we encounter the END
	while(Hash_Map[i].bit==END && Hash_Map[i].count==END)
	{
		//if 0 ek hi baar encounter hua to..
		if(Hash_Map[i].bit==0 && Hash_Map[i].count==1)
		{
			L=Hash_Map[i-1].count;
			R=Hash_Map[i+1].count;
			max_length=max((L+R+1),max_length);
		}
		//if 0 ek multiple baar encounter hua to..
		else if(Hash_Map[i].bit==0 && Hash_Map[i].count>1)
		{
			L=Hash_Map[i-1].count;
			R=Hash_Map[i+1].count;
			max_length=max(max((L+1),(R+1)),max_length);  ////used max(a,max(b,c)) to get max of a,b and c
		}
	}
	
return max_length;
}

int main() 
{ 	
	int n;
	cout<<"\nEnter your number => ";
	cin>>n;
	
	int allones = ~0;
	int allzeros= ~1;
	
	//corner cases
	if(n==allones)
	{
		//return number of bits in the input number
		int count=0,n_preserved=n;
		while(n_preserved!=0)	
		{
			n_preserved=n_preserved>>1;
			count++;
		}
		
		cout<<"\nLargest sequence of 1s is of length => "<<count;
	}
	else if(n==allzeros)
	{
		//return 1
		cout<<"\nLargest sequence of 1s is of length => 1";
	}
	else if(n<0)
	{
		//not allowed
		cout<<"\nNegative numbers not allowed!";
	}
	else
	{
		//call our function
		cout<<"\nLargest sequence of 1s is of length => "<<lengthof1s(n);
	}
	
return 0;	
}
