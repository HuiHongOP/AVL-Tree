# AVL-Tree


In this Project/Hw will be using restriction enzyme database to construct an AVL Tree.

In the query_tree.cc will be reading the rebase210.txt file and inserting the enzyme acronyms corresponding with it's recognition sequence into the AVL tree as an object. 

To Run the query_tree.cc file

g++ -std=c++14 -o query_tree query_tree.cc
./query_tree rebase210.txt < input_part2.1.txt
The expected output is in the "output_part2.1.txt" file
or
./query_tree rebase210.txt 
<string of recognition sequences>
 Example: 
  ./query_tree rebase210.txt 
  Enter the recognition sequences like : Y'GGCCR 
 
  
 To run the test_tree_mod.cc/test_tree.cc
 g++ -std=c++14 -o test_tree/test_tree_mod test_tree_mod.cc/test_tree.cc
  ./<test_tree or test_tree_mod> rebase210.txt sequences.txt
  
  
