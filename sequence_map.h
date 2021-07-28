//Huihong Zheng
//header for sequencemap part 1 hw#3
#ifndef Sequence_Map
#define Sequence_Map
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//creating class called SequenceMap
class SequenceMap
{
public:
	// zero- parameter constructor
	SequenceMap() = default;
	

	//*******This is the "Big Five" implementation
	//They are set to default

	//Destructor
	~SequenceMap() = default;
	
	// Copy Constructor
	SequenceMap(const SequenceMap &other) = default;
	
	// Copy Assignment
	SequenceMap & operator=( const SequenceMap &other) = default;	
	
	// Move Constructor
	SequenceMap(SequenceMap &&other) = default; 
	
	// Move Assignment
	SequenceMap & operator = ( SequenceMap && other)= default;
	//End of "Big Five"


	
	// 2 parameter constructor for sequencemap function
	SequenceMap(const std::string &a_rec_seq,const std::string &an_enz_acro):recognition_sequence_(a_rec_seq) //set recognition to a-rec-seq that's being passed
	{	
		enzyme_acronyms_.push_back(an_enz_acro); //insert into the vector of enyzem acryonms
	}
	//return true or false operator 
	bool operator<(const SequenceMap &rhs) const
	{
		return (recognition_sequence_ < rhs.recognition_sequence_);
	}

	//this overloading << operator function will print out the output of enymzes 
	friend std::ostream &operator<<(std::ostream &out, const SequenceMap  &output)
	{
	
		vector<string> StorePrinter = output.enzyme_acronyms_;
		for ( const auto & LoopThroughStore: StorePrinter)
		{
			out<<LoopThroughStore<< " "; 
		}
		return out; // prints the output
	}
	//merges the other sequence enyzeme acronym with the object's enyzyme acryonmy. The other sequence object are not affected
	void Merge(const SequenceMap & other_sequence)
	{
		vector<string> Store = other_sequence.enzyme_acronyms_;		
		for ( const auto & LoopThroughAll : Store)
		{
			enzyme_acronyms_.push_back(LoopThroughAll); 
		}
	}
private:
 	//data members
	//@recognition_sequence_ : 
	string recognition_sequence_; 
	vector<string>enzyme_acronyms_;	
	
};
#endif
