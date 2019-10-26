 
#include <iostream>
#include <string.h>
using namespace std;

template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
        int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList()
		{
			element=NULL;
		}
		 

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize)
		{
			 element=new Item [MaxListSize]();
			for (int i = 0; i < MaxListSize ; ++i)
			{
				element[i]=1;
			}
			len=0;
			MaxSize=MaxListSize;
		}

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList()
		{
			 delete[] element;

		}

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i)
		{
			return element[i-1];
		} //return i'th element of list
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty()
		{
			if(element==NULL)
				return true;
			else
				return false;
		}

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int length()
		{ 
		    return len;
		}

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize()
		{
			return MaxSize;
		}

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k)
		{
			//cout<<element[k-1]<<" ";
			return element[k-1];

		}

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x)
        {
        		element[k-1]=x;
        		return true;
        	
        }
		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x)
		{
			for (int i = 0; i < len; ++i)
			{
				 if(element[i]==x)
				 	return i+1;
			}
			
			return 0;
		}

		/* Set x to the k-th element and delete that k-th element.
		 * */
		Item deleteElement(const int k)
		{   Item x;
			x=element[k-1];
			for (int i = k; i <len; ++i)
			{
				element[i-1]=element[i];
			}
			len=len-1;
			return x;
		}

		/* Insert x after k-th element.
		 * */
		void insert(const int k, Item& x)
		{   
             int i;
			for ( i =len; i>=k; i--)
			{ 
				element[i]=element[i-1];
			}
		    element[k-1]=x;
			
			len++;
		}
		void  insert1(const int  k, Item& x)
		{   
			element[k-1]=x;
			len++;
		}
}; 
