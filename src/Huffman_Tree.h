#ifndef HUFFMAN_TREE_H_
#define HUFFMAN_TREE_H_
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Huffman_Tree{
public:
	// A Huffman tree node
	int length;//find most longer frequency

	struct tree_node//create node for huffman tree
	{
	  char data_name;//node data (character)
	  int freq;//frequency for data_name
	  struct tree_node *left;//create new node in the node for right child
	  struct tree_node *right;//create new node in the node for left child
	  
	  tree_node(char name,int frequency)
	  {
	      data_name = name;
	      freq=frequency;
	      //first left and right child is Null. We will change after
	      left = NULL;
	      right = NULL;
	      }
	};

	//for  all huffman elements this tree_encode linked list for create a tree.txt
	struct tree_encode
	{
		char char_name;
		string char_encode;
		tree_encode *next;
	};
	tree_encode *head=NULL;
	tree_encode *tail=NULL;
	
//added all huffman elements tree_encode linked list with add_decode_tree
void add_decode_tree(char name,string encode)
{
	tree_encode *tmp = new tree_encode;
	tmp->char_name = name;
	tmp->char_encode = encode;
	tmp->next = NULL;

	if(head == NULL)//if it is first element of linked list
	 {
	     head = tmp;
	     tail = tmp;
	 }
	else//or not
	{
	     tail->next = tmp;
	     tail = tail->next;
	}}//end of add_decode_tree

//print tree.txt this method 
void printHuffmanTree()
{
	ofstream commands;
	commands.open("Tree.txt",std::ifstream::out);


		tree_encode *print_tree = new tree_encode;
			char arr[length];//printing huffman tree control frequency with this arr
			int i=0;
			commands<<"Root"<<endl;//first line
			print_tree=head;
			string s;
			if(print_tree==head)
			{
				s=print_tree->char_encode;
				if(s.length()==1)
				{	for(char& c : s) {
					char ss=c;
					arr[i]=ss;
					i++; }
					commands<<"  |+Left Subtree0"<<"-"<<print_tree->char_name<<"-"<<print_tree->char_encode;
				}//end of if
				else if(s.length()>=1)
				{
					for(char& c : s) {
						char ss=c;
						arr[i]=ss;
						i++; }
					commands<<"  |+Left Subtree0"<<endl;
					int sLength=s.length();
					int k=2;
					while(sLength!=0)
					{	int j=k;
						while(j!=0)
						{	commands<<"  |";
							j--;}
						k++;
						sLength--;
						if(sLength!=0){commands<<"+Parent"<< arr[k-2]<<endl;}
					}
					commands<<"Child "<<"-"<<print_tree->char_name<<"-"<<print_tree->char_encode<<endl;}//end of the else if
				print_tree=print_tree->next;
			}//end of the if it is head
			while(print_tree!=NULL)
			{	int i=0,j=0;
				s=print_tree->char_encode;
				int sLength=s.length();
				int sLength1=s.length();
				char arr1[length];
				s=print_tree->char_encode;
				for(char& c : s) {
					char ss=c;
					arr1[i]=ss;
					i++;}
				while(arr[j]==arr1[j])
				{j++;}
				if(j==0)
				{
					commands<<"  |+Right Subtree1"<<endl;
					int k=2;
					while(sLength!=0)
					{	int cont=k;
						while(cont!=0)
						{	commands<<"  |";
							cont--;}
							k++;
							sLength--;
						if(sLength!=0){commands<<"+Parent"<< arr1[k-2]<<endl;}
					}
					commands<<"Child "<<"-"<<print_tree->char_name<<"-"<<print_tree->char_encode<<endl;
					int l=0;
					while(l<sLength1)
					{
						arr[l]=arr1[l];
						l++;
					}
					print_tree=print_tree->next;
				}//end of the if
				else{
					int k=j+1;
					while((sLength-j+1)!=0)
					{	int count=k;
						while(count!=0)
						{	commands<<"  |";
							count--;}
							k++;
						if((sLength-j)!=0){commands<<"+Parent"<< arr1[k-2]<<endl;}sLength--;
					}
					commands<<"Child "<<"-"<<print_tree->char_name<<"-"<<print_tree->char_encode<<endl;
					int l=0;
					while(l<sLength1)
					{
						arr[l]=arr1[l];
						l++;
						}
					print_tree=print_tree->next; }//end of the if

	  }
			commands.close();
}




// For comparison of two tree node which is the bigger which is the left right 
	struct compare {
		bool operator()(tree_node* l, tree_node* r)
		{return (l->freq > r->freq);}
	};


	void HuffmanTree(struct tree_node* root, string str)
	{

		if (!root)
			return;

		if (root->data_name != 'R')
			{
			add_decode_tree(root->data_name,str);//call add_decode_tree for create tree
			int str_length=str.length();
			if(length<str_length)//find bigger frequency
			{length=str_length;}
			}

		HuffmanTree(root->left, str + "0");//huffman tree encode 
		HuffmanTree(root->right, str + "1");//huffman tree encode 
	}
	
	// Create a vector for all elements
	priority_queue<tree_node*, vector<tree_node*>, compare> create_tree;
	
	void push_values_vector(char data, int freq)
	{
			create_tree.push(new tree_node(data, freq));
	}

	// The main function that builds a Huffman Tree and
	// print codes by traversing the built Huffman Tree
	void HuffmanCodes()
	{
		struct tree_node *left, *right, *top;

		// Iterate while size of heap doesn't become 1
		while (create_tree.size() != 1) {


			//first find top and value added left leaf later delete top value
			left = create_tree.top();
			create_tree.pop();
			//second find top and value added right leaf later delete top value
			right = create_tree.top();
			create_tree.pop();

			// Create a new internal node with old left leaf and right leaf.
			//node data_name is R it is special value (I choose it is changable)
			//frequency equals to sum of left_leaf and right_leaf frequency.
			top = new tree_node('R', left->freq + right->freq);

			//top left nodes is left
			top->left = left;
			//top right nodes is right
			top->right = right;

			//new top value added the create_tree
			create_tree.push(top);
		}

		// Print Huffman codes using
		// the Huffman tree built above
		HuffmanTree(create_tree.top(), "");
	}

	//HuffmanCodes(arr, freq, size);

	// This code is contributed by Aditya Goel



};

#endif /* HUFFMAN_TREE_H_ */
