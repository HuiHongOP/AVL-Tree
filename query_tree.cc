//Huihong Zheng
// Main file for Part 2.1 of Homework 3.

#include "avl_tree.h"
#include "sequence_map.h"
// You will have to add #include "sequence_map.h"

#include <iostream>
#include <string>
#include <sstream> //include those 2 library to uses read files 
#include <fstream>
using namespace std;


namespace {


//Input recognition sequences 
//This function will take in the user's input recognition sequences and display whether it is in the avl tree
//@UserInputLine: Store the input recognition sequences
//@OneLineInput: Break into different sequences
//@InsertInputRecognition : store the user input by recognition sequence at a time
//@map: object of sequencemap contain user's input recognition 
//GetAndPrintMatch function: matches with user's input recognition sequence then output the enzyme acronyms
//@a_tree : AVl tree 
template<typename TreeType>
void UserInput(TreeType &a_tree)
{
	string UserInputLine; 
	while(getline(cin, UserInputLine)) 
	{
		stringstream OneLineInput(UserInputLine); 
		string InsertInputRecognition; 
		for (; OneLineInput>>InsertInputRecognition;) 
		{
			string EmptyString; 
			SequenceMap map(InsertInputRecognition,EmptyString); 
			
			//check with the avl tree
    		if(!a_tree.contains(map)) 
    		{
    			cout<<"Not Found" <<endl; 
    			break; 		
    		}
    		else 
    		{	
    			a_tree.GetAndPrintMatch(map);
    			cout<<endl;
    		}
    	}
    }
} 

// @dbx_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
//@LinesNotBeingRead : not reading the header information
//@Tenlines: There is 10 lines not reading in input filename
template <typename TreeType> // for part 2.1
void QueryTree(const string &dbx_filename, TreeType &a_tree) 
{
  // Code for running Part 2.1
  string db_line; 
  ifstream Rebasefile(dbx_filename); 
  string GetRidOfHeaderLines; 
  int  LinesNotBeingRead = 0; 
  int TenLines = 10; 
  while (LinesNotBeingRead  <TenLines ) 
  {
  	getline(Rebasefile,GetRidOfHeaderLines); 
  	LinesNotBeingRead ++; 
  }
  //reads the rebase210.txt file and insert them as an object into avl tree
  while(getline(Rebasefile,db_line))
  {	
  	stringstream openfile(db_line); // to read the strings db-Line
  	string TheEnzymeAcro ; 
  	string TheRecogSeq ;
  	getline(openfile,TheEnzymeAcro , '/'); 
  	while(getline(openfile,TheRecogSeq, '/')) 
  	{	
  	    if(TheRecogSeq.size() !=0 && TheEnzymeAcro.size() !=0 ) 
  	    {
  	        //create new object sequencemap that store the enzyme and recognition 
			//place that object into avl tree
  			SequenceMap new_sequence_map(TheRecogSeq, TheEnzymeAcro); 
  			a_tree.insert(new_sequence_map); // insert this new object into the avl tree
  		}
  	} 
   }
	
  // You can use public functions of TreeType. For example:
  //a_tree.insert(10);
  //a_tree.printTree();
}

}
 // namespace

int
main(int argc, char **argv) 
{
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  cout << "Input filename is " << dbx_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  //AvlTree<int> a_tree;
  AvlTree<SequenceMap> a_tree;
  QueryTree(dbx_filename, a_tree); // call void function Querytree with file and tree parameter
  UserInput(a_tree); // call void function Userinput to cin the sequence.txt or input the recognition sequence
  return 0;
}
