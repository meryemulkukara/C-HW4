
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include "LinkedList_Frequency.h"
#include "decode_list.h"
#include "Huffman_Tree.h"
using namespace std;
void read_encode(string);
void read_decode(string,string);
void read_character(string,string);
void read_tree(string);
int main(int argc, char *argv[])
{	string argv1input="-i";
	string argv1character="-s";
	string argv1tree="-l";
	string argv_encode="-encode";
	string argv_decode="-decode";
	if(argv[1]==argv1input)
	{	if(argv[3]==argv_encode)
		{read_encode(argv[2]);}

		else if(argv[3]==argv_decode)
		{
			string file="tree.txt";
			read_decode(argv[2],file);

		}
		else{cout<<"invalid input";}
	}

	else if(argv[1]==argv1character)
	{
		string file="tree.txt";
		string s=argv[2];
		for_each(s.begin(), s.end(), [](char & c) {
		        c = ::tolower(c);
		    });
		read_character(s,file);
	}

	else if(argv[1]==argv1tree)
	{	string file="tree.txt";
		read_tree(file);
	}

	else {cout<<"invalid input";}

	return 0;
}

LinkedList_Frequency obj;
//Tree obj1;
Huffman_Tree huffman_tree_obj;
void read_encode(string fileName)
{	std::ifstream commands;
	commands.open(fileName,std::ifstream::in);
	vector < string > lines;
	vector < char > bytes;
	int lineNumber=0;
	char s='\\';
	string line;
	char charN='n';
	int j=1;

	if(!commands.is_open()) //if it is not open the
	{
		cout<<"I can't read " <<fileName<<" file";
		exit(1); //system stop
	}
	else{
		while(getline(commands,line))
		{
			string c=line;
			lines.push_back(c);

			lineNumber++;
		}
		for(const auto &it :lines)
		{
			for(std::string::size_type i = 0; i <it.size(); ++i)
			{
				bytes.push_back(tolower(it[i]));//add a vector char by char
			}//end of for loop
			if(j<lineNumber)//line #
			{
				bytes.push_back(s);//add \ end of the line
				bytes.push_back(charN);//add n end of the line
				j++;
			}//end of if loop
		}//end of for loop

		for(const auto &i :bytes)
		{
			obj.add_node(i);
		}//end of for loop

			obj.sorted_linkedlist();
			obj.display();
			char c;
			int c1;
			while(obj.name_char->next!=NULL)
			{
				c=obj.name_char->character;
				c1=obj.name_char->character_frequency;
				huffman_tree_obj.push_values_vector(c, c1);
				obj.jump_after_node();
			}
			c=obj.name_char->character;
			c1=obj.name_char->character_frequency;
			huffman_tree_obj.push_values_vector(c, c1);
			huffman_tree_obj.HuffmanCodes();
			huffman_tree_obj.printHuffmanTree();
	}
}
void tokenize(string &str, char delim, vector<string> &out)//split line space by space
{
	size_t start;
	size_t end = 0;
	int j=0;
	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
		j++;
	}
}
void read_character(string character,string fileName)
{
	ifstream commands;
	commands.open(fileName,std::ifstream::in);
	string line;
	if(!commands.is_open()) //if it is not open the
	{
		cout<<"I can't read " <<fileName<<" file";
		exit(1); //system stop
	}
	else
	{	while(getline(commands,line)) //read file
		{
		vector < string > v;
		char hyphen='-';
		tokenize(line,hyphen,v);
		int vector_size=v.size();
		int i;
		if(vector_size==3)//control tree child lines
		{
			for(i=0;i<vector_size;i++)
			{
				if(i==1)
				{
					if(v[1]==character)
					{cout<<v[2];break;}
				}
				else continue;
			}
		}
		}
		}//end of else
}

decode_list decode_list_obj;
void read_decode(string decode_file,string fileName)
{
	//first read Tree.txt and add char and decode linked list
	ifstream commands;
	commands.open(fileName,std::ifstream::in);
	string line;
	if(!commands.is_open()) //if it is not open the
	{
		cout<<"I can't read " <<fileName<<" file";
		exit(1); //system stop
	}
	else
	{	int length_encode;//use find longer encode number
		while(getline(commands,line)) //read file
		{
		vector < string > v;
		char hyphen='-';//delimiter element is -
		tokenize(line,hyphen,v);
		int vector_size=v.size();
		int i;
		if(vector_size==3)//control tree child lines
		{	string v1,v2;
			for(i=1;i<3;i++)
			{	if(i==1)
				{	//cout<<"v[1]	"<<v[1]<<endl;
					v1=v[1];}
				else
				{	//cout<<"v[2]	"<<v[2]<<endl;
					v2=v[2];
					int v2_length=v2.size();
					if(length_encode<v2_length){length_encode=v2_length;}//find longer length
					decode_list_obj.add_decode_node(v1, v2);
					//cout<<"v1 is	"<<v[1]<<" v2 is	"<<v[2]<<endl;}
				}//end of else
			}//end of for loop
		}}//end of while loop
		//decode_list_obj.display();

		//read input_decode.txt
		ifstream commands1;
		commands1.open(decode_file,std::ifstream::in);
		string line1;
		if(!commands1.is_open()) //if it is not open the
		{
			cout<<"I can't read " <<decode_file<<" file";
			exit(1); //system stop
		}
		else
		{
			vector<string> characters;
			while (getline(commands1,line1))
			{characters.push_back(line1);}//end of while loop
			int vector_size=characters.size();
			bool a=false;
			int i=0;//new line if it is not one line
			int j=0;//skip if you are find
			int k=1;
			while(!a)
			{
				int length_line=characters[i].size();
				string value = characters[i];
				int startIndex =j;//starting position 0
				int length = k;//length of the string
				string substring = value.substr(startIndex, length);
				a=decode_list_obj.search(substring);

				if(a)//skip if you are find
				{
					if(j<length_line)
					{
						j=j+k;k=1;
						if(j<length_line){a=false;}
						else
						{	if(i<vector_size){
								a=false;
								i++;
								j=0;
								k=1;}
						}
					}

				}
				else//if you dont find k =kplus
				{	if(k<length_encode)
					{k++;}
					else
					{		cout<<substring<<" is invalid decode";
							{break;}
					}}
			}//end of while loop that is find decode to encode
	}//end of reading decode.txt
}//end of reading tree.txt
}//end of read_decode


void read_tree(string fileName)
{
	//first read Tree.txt and add char and decode linked list
	ifstream commands;
	commands.open(fileName,std::ifstream::in);
	string line;
	if(!commands.is_open()) //if it is not open the
	{
		cout<<"I can't read " <<fileName<<" file";
		exit(1); //system stop
	}
	else
	{	vector < string > v;
		while(getline(commands,line)) //read file
		{

			v.push_back(line);}
			int vector_size=v.size();
			int i;
			for(i=0;i<vector_size;i++)
			{
				cout<<v[i]<<endl;
			}
	}
};



