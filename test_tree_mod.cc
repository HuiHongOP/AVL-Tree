// Huihong Zheng
// Main file for Part 2.3 of Homework 3.

#include "avl_tree_mod.h"
#include "sequence_map.h"
// You will have to add #include "sequence_map.h"
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

namespace {

// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.

double TheAverageDepth; //declare double variable AverageDepth for global uses for void functions
double TheAverageDepthRatio; //declare TheAverageDepthRatio variable AverageDepth for global uses for void functions
// create template to operate with generic types
// void function named printforfour will be used for printing all the result of questions 4
template<typename TreeType>
void PrintForFour(const string seq_filename,TreeType &a_tree)
{
	int match = 0; //declare integer variable match and initialize to 0
	double NumberRecursionCalls = 0; // declare number of recursioncall as double and initailize to 0 
	ifstream sequenceFile(seq_filename); // read the passed seqfilename
	string ReqSequence; //declare empty string variable ReqSequence	
	string nothinginside; //declare empty string to pass parameter
	while(getline(sequenceFile,ReqSequence)) //while there's something to read and store into ReqSequence
	{
		SequenceMap SearchObject (ReqSequence, nothinginside); //creating new object sequencemap name SearchObject store the reqsequence
		NumberRecursionCalls =  NumberRecursionCalls+ a_tree.find(SearchObject);
		 // it will find the tree for each string in the sequence txt and counter total number of recursuons calls for executing all of find()
		 
		if(a_tree.contains(SearchObject)) // search if the object is into the tree and return true( for inside the avl tree) and false( for not )
		{
			match = match +1; // if it's inside the tree it will increase match by one
		}//end of if
	}//end of while
	cout<<"4a: "<< match <<endl; //print the number of total found and skip to new line
	NumberRecursionCalls = NumberRecursionCalls/match; //will divide the number of recursion by total number of successful strings found
	cout<<"4b: "<< NumberRecursionCalls<<endl; // print the average number of recursion calls and skip to a new line
}

//create template to operate with generic types
//this void function will be used for 5 and with 2 parameters to pass the seqfile and a_tree
template<typename TreeType>
void PrintForFive ( const string seq_filename,TreeType &a_tree)
{
	ifstream sequenceFile(seq_filename); 
	string ReqSequence; 
	double NumberRecursionCalls =0; 
	int Remainder =0 ; 
	int TotalNumberSuccessRemoved=0; 
	int UnableToRemove=0;
	while(getline(sequenceFile,ReqSequence)) 
	{
		if (Remainder %2 ==0) // loop through every other sequence if remainder divides by 2 equal 0
		{
			string NothingInside;  
			SequenceMap RecognitionSequence(ReqSequence, NothingInside ); 
			if(a_tree.contains(RecognitionSequence)) //search if object is in the AVL tree if it's return true and run through the if statement
			{
				// ses to count the number of recursions calls and the function to search and remove
				NumberRecursionCalls += a_tree.findandRemove(RecognitionSequence); //it will return number of times found then removed and add into the numberrecursioncalls
				TotalNumberSuccessRemoved = TotalNumberSuccessRemoved+1; // increment by one for each sequence that is inside the avl tree and able to remove
			}
			else//the object sequence isn't in the avl tree 
			{
				UnableToRemove= UnableToRemove+ 1; // increment by 1 each time the object is not in the avl tree and not able to remove it.
			}
		}
		Remainder = Remainder +1; 
	}
	cout<<"5a: "<<TotalNumberSuccessRemoved<<endl; //this will print out the total number of successful removes from the avl tree sequence 
	// count in the unableRemove + recursion calls into new recuriosncall varaible and divides it by number of removed calls 
	NumberRecursionCalls = (NumberRecursionCalls+UnableToRemove)/TotalNumberSuccessRemoved;
	cout<<"5b: "<<NumberRecursionCalls<<endl; // this will print the average number of recursion balls  for 5b 
}


//create template to operatre with generic types
//this void function will print all the questions in 6
template<typename TreeType>
void PrinterToSix(TreeType &a_tree)
{
    //call in the function to print the number of nodes in the tree 
    cout<<"6a: "<<a_tree.ReadForAllNode()<<endl; // print the number of nodes and skip to a new line
    
    //set the new averagedepth value to the maxdepth divides by number of nodes left in the new tree
    TheAverageDepth = a_tree.MaximumDepth()/a_tree.ReadForAllNode();
    cout<<"6b: "<< TheAverageDepth<<endl; // print the average depth and skip to new line
    
    //set the new ratio of the avergedepth to averagedepth divides by a new log base 2 of the number of node in that new tree.
    TheAverageDepthRatio =( TheAverageDepth/log2f(a_tree.ReadForAllNode()));
    cout<<"6c: "<< TheAverageDepthRatio<<endl; // print the averagedepth ratio and skip to a new line
}
	
//Main Function that will output part 2.2
//2: prints out the number of nodes in current AVL Tree
//3a: Computes the avg depth of AVL tree
//3b: Computes ratio of the avg dpeth to log2
//PrintForFour function: searches the AVL to find the string in the sequences.txt file and counts # of recursion function calls
//PrintForFive: Remove all sequences in the sequences.txt from the avl tree then count the # of recursion calls
//PrinterToSix: redo and print (2, 3a, and 3b)
template<typename TreeType>
void PrinterToAll(const string seq_filename,TreeType &a_tree)
{
	// Code for running Part 2.2
    cout<<"2: "<<a_tree.ReadForAllNode()<<endl; 
    TheAverageDepth = a_tree.MaximumDepth()/a_tree.ReadForAllNode(); 
    cout <<"3a: "<<TheAverageDepth<<endl; 
    TheAverageDepthRatio = (TheAverageDepth/(log2f(a_tree.ReadForAllNode())));
    cout <<"3b: "<<TheAverageDepthRatio<<endl; 
    PrintForFour(seq_filename,a_tree); 
    PrintForFive (seq_filename,a_tree); 
    PrinterToSix(a_tree);   
}


// @dbx_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
//@LinesNotBeingRead : not reading the header information
//@Tenlines: There is 10 lines not reading in input filename
template <typename TreeType>
void TestTree(const string &dbx_filename, TreeType &a_tree) 
{
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
}

}  // namespace

int
main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  const string seq_filename(argv[2]);
  cout << "Input file is " << dbx_filename << ", and sequences file is " << seq_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  //AvlTree<int> a_tree;
  AvlTree<SequenceMap> a_tree;
  TestTree(dbx_filename, a_tree); // call on the testtree function with 3 parameter passes rebase210.txt seqfile and atree
  PrinterToAll(seq_filename, a_tree);// call on the printer function and pass 2 parameter for seqfile and a tree to print all part 2b
  return 0;
}
