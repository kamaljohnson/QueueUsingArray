/*A Queue is a method of storing data 
  where the data is released from the
  storage as first come first serve
		i.e. the data entered first will
  leave the queue after processing first 
  then the next one and so on
  
  this is a program that will impliment
  a simple queue where the main duty of
  the queue is to display the items and
  delete the items from the begining
  and adding to the last
  
  the data storage method used here is 
  a simple integer array */


#include<iostream>

//all the funtions used in this program are declared over here

int selection();

int* addItemToQueue(int item,int* array,int* end,int size);

int* deleteItemFromQueue(int* array,int* end);

void displayQueue(int* array,int* end);

void main()			//the main funtion
{
	int select;		//selection 
	int size;		//max size of the queue
	int *beg;		//pointer pointing to the begining of the queue
	int *end;		//pointer pointing to the end of the queue

	std::cout << "This programe impliments Queue" << std::endl;
	std::cout << "enter the max size of the queue needed :";
	std::cin >> size;

	int* array = new int[size];		//making a dynamic array  with size 'size' using a pointer
	
	memset(array, 0, size);		//initialising the array elements with the element 0

	end = array;	//initialising the end to point to the begning of the array
	beg = array;
	
	int exit = 0;	//a flag for the exit condition of the loop

	while (!exit)
	{
		int item;
		select = selection();		//the selection is made here 	

		switch (select)
		{
		case 1:
			std::cout << "Enter the number to be added to the queue:";
			std::cin >> item;
			
			end = addItemToQueue(item,array,end,size);
			
			break;
		case 2:
			
			end = deleteItemFromQueue(array,end);
			
			break;

		case 3:
			
			displayQueue(array,end);
			
			break;
			
		case 4:
			
			exit = 1;

			break;
		default:
			break;
		}
		displayQueue(array, end);

	}
}

int selection()			//returns the selection integer
{
	int select;

	std::cout << "\nEnter your choice :\n"<<std::endl;
	std::cout << "Add to the queue ---------> 1" << std::endl;
	std::cout << "Delete from the queue ----> 2" << std::endl;
	std::cout << "Display the queue --------> 3" << std::endl;
	std::cout << "Exit ---------------------> 4" << std::endl;
	std::cin >> select;
	
	return(select);
}

int* addItemToQueue(int item,int* array,int* end,int size)	//adding the item to the queue
{
	if (end == &array[size - 1])
	{
		std::cout << "the queue is full!!" << std::endl;
	}
	else 
	{
		if (end == array)
		{
			*end = item;
			end++;
		}
		else {

			*end = item;
			end++;
		}
		std::cout << "\nthe item " << item << " is added to the queue at " << end << std::endl;
	}
	return(end);
}
int* deleteItemFromQueue(int* array,int* end) //deletion of the item from the queue
{
	int* temp = array;
	if (end == array)
	{
		std::cout << "\nthe Queue is empty!!" << std::endl;
		return(end);
	}
	std::cout <<"\n\n"<< *temp << " poped out off the queue."<<std::endl;
	while (true)
	{
		if (temp == end)
		{
			end--;
			break;
		}
	
		*temp = *(temp + 1);
		temp++;

	}
	return(end);
}
void displayQueue(int* array,int* end) // displaying the items of the queue
{
	int* itr = array;
	std::cout << "\n\n[";
	while (true)
	{
		if (itr == end)
			break;
		
		std::cout <<" "<< *itr;
		itr++;

	}
	std::cout << "]\n\n";
	std::cout << std::endl;
}
