<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Live Server</title>
</head>
<body>
    <h1>AVL_Tree/hw</h1>
    <p>In this Project/Hw will be using restriction enzyme database to construct an AVL Tree.</p>
    <p>In the query_tree.cc will be reading the rebase210.txt file and inserting the enzyme acronyms corresponding with it's recognition sequence into the AVL tree as an object. 
    </p>
    <p>To Run the query_tree.cc file</p>
    <p>g++ -std=c++14 -o query_tree query_tree.cc
    </p>
    <p>./query_tree rebase210.txt < input_part2.1.txt</p>
    <p>The expected output is in the "output_part2.1.txt" file</p>
    <p>./query_tree rebase210.txt </p>
    <p><string of recognition sequences></p>
    <p>Example:</p>
    <p>Enter the recognition sequences like : Y'GGCCR </p>
    <br>
    <hr> 
    <p>To run the test_tree_mod.cc/test_tree.cc </p>
    <p>g++ -std=c++14 -o test_tree/test_tree_mod test_tree_mod.cc/test_tree.cc </p>
    <p>./query_tree rebase210.txt </p>
    <p>./<test_tree or test_tree_mod> rebase210.txt sequences.txt </p>

</body>
</html>
