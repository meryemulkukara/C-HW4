

#ifndef DECODE_LIST_H_
#define DECODE_LIST_H_
#include <iostream>
using namespace std;

struct tree_decode{
	string data;
	string decode;
	tree_decode *next;
};

class decode_list
{
private:tree_decode *head;tree_decode *tail;
public:
	decode_list():head(NULL),tail(NULL){};
	void add_decode_node(string data1,string decode1)
	{
		//cout<<"string data1,"<<data1<<" string decode1  "<<decode1 <<endl;
		tree_decode *tmp = new tree_decode;
		tmp->data = data1;
		tmp->decode=decode1;
		tmp->next = NULL;

		if(head == NULL)
		{
		     head = tmp;
		     tail = tmp;
		}
		else
		{
		     tail->next = tmp;
		     tail = tail->next;
		}
	}

	bool search( string search_element)
	{
		tree_decode* current = head; // Initialize current
	    while (current != NULL)
	    {
	        if (current->decode ==search_element)
	        { string space=" ";
	        	if(current->data==space)
	        	{
	        		cout <<"\"" <<current->data <<"\"";
	        	}
	        	else{cout<<current->data; }

	        	return true;
	        }
	        current = current->next;
	    }
	    return false;
	}

};

#endif /* DECODE_LIST_H_ */
