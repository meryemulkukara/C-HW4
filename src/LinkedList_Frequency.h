
#ifndef LINKEDLIST_FREQUENCY_H_
#define LINKEDLIST_FREQUENCY_H_
#include <iostream>
using namespace std;
struct character_list
{
    char character;
    int character_frequency;
    struct character_list *next;
};
character_list *headList;

class LinkedList_Frequency{
private:
	character_list *head,*tail;
	int counter;
public:

	LinkedList_Frequency():head(NULL),tail(NULL),counter(0){};

	int search_character(char ch)
	{
		int pos = 0,i;
		bool flag = false;
		character_list *s = new character_list;
		s = head;
		int count=counter+1;
		if(s==NULL)
		{
			return count;
		}
		for (i = 0;i < counter;i++)
		{
		    pos++;
		    if (s->character == ch)
		    {
		       //cout<<"ch "<<ch <<endl;
		       //cout<<"s character"<<s->character<<endl;
		        flag=true;
		        return pos;
		    }
		    s = s->next;
		}
		if (!flag)
		{
		    //cout<<"\n			User "<<data1<<" does not exit";
		 return count;}

	};
	void add_node(char n)
	    {
	        character_list *tmp = new character_list;
	        character_list *tmp1 = new character_list;
	        tmp->character = n;
	        tmp->next = NULL;
	        int sequence=search_character(n);
	        if(head == NULL)
	        {
	        	tmp->character = n;
	        	tmp->character_frequency=1;
	        	tmp->next = NULL;
	            head = tmp;
	            tail = tmp;
	            counter++;
	        }
	        else
	        {	if(sequence<=counter)
	        	{
	        	     tmp1 = head;
	        	     for (int i = 1;i <sequence;i++)
	        	     {
	        	        tmp1=tmp1->next;
	        	     }
	        	        int freq=tmp1->character_frequency;
	        	        tmp1->character_frequency=freq+1;
	        	      //  cout<<"name "<<tmp1->character<<endl;
	        	       // cout<<"frequency "<<tmp1->character_frequency<<endl;
	        	        tmp1=tmp1->next;

	        	     }

	        	else
	        	{	tmp->character = n;
	        		tmp->character_frequency=1;
	        		tmp->next = NULL;
	        		tail->next = tmp;
	        		tail = tail->next;
	        		counter++;
	        	}
	    }
	};
	character_list *name_char = new character_list;
	void display()
	{
		 character_list *display = new character_list;
		 display=head;
		 while(display->next!=NULL)
		 {
			 display=display->next;
		 }
		 name_char=head;

	}

	void my_swap (character_list *node_1,character_list *node_2)
	{
		char temp = node_1->character;
		int temp1=node_1->character_frequency;
		node_1->character = node_2 -> character;
		node_1->character_frequency=node_2->character_frequency;
		node_2 -> character = temp;
		node_2->character_frequency=temp1;
	}

	void sorted_linkedlist()
	{
		int swapped;

		character_list *lPtr; // left pointer will always point to the start of the list
		character_list *rPrt = NULL; // right pointer will always point to the end of the list
		//character_list *control_tail=new character_list;

			do
			{
				swapped = 0;
				lPtr = head;
				while(lPtr->next != rPrt)
				{
					if (lPtr->character_frequency > lPtr->next->character_frequency)
					{
						my_swap(lPtr, lPtr->next);
		                swapped = 1;
					}
					lPtr = lPtr->next;
				}
				//as the largest element is at the end of the list, assign that to rPtr as there is no need to
				//check already sorted list
				rPrt = lPtr;

			}while(swapped);

	}
	void jump_after_node()
	{
		name_char=name_char->next;
	}


};

#endif /* LINKEDLIST_FREQUENCY_H_ */
