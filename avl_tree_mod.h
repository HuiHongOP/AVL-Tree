//Huihong Zheng
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "dsexceptions.h"
#include "sequence_map.h"
#include <algorithm>
#include <iostream> 
using namespace std;

// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class AvlTree
{
  public:
    AvlTree( ) : root{ nullptr }
      { }
    
    AvlTree( const AvlTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    AvlTree( AvlTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    ~AvlTree( )
    {
        makeEmpty( );
    }

    /**
     * Deep copy.
     */
    AvlTree & operator=( const AvlTree & rhs )
    {
        AvlTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    AvlTree & operator=( AvlTree && rhs )
    {
        std::swap( root, rhs.root );
        
        return *this;
    }
    
    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMax( root )->element;
    }
    
    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
     
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }
     
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }
    
    int UseToInitailize = 0; // declare variable integer to initailzie 0s to parameters;

    //2.1
    //declare void GetAndPrintMatch to print the enzyme acronyms that matched the sequences
    void GetAndPrintMatch( const Comparable & item)
    {	
    	 GetAndPrinter( item, root); 
    }

    //part 2b
    //declare integer ReadforAllnode function that will count the number of nodes in the current AVL Tree
    int ReadForAllNode()
    {
    	return ReadForAllNode(root);
    }
    
    //main driver for MaximumDepth
    //declare double MaximumDepth function 
    //return the maximum depth of the AVL tree
    double MaximumDepth()
    {
    	return MaximumDepth(root,UseToInitailize );  
    } 
    
    //main driver for find
    //similar to contain function in the above
    //declare integer function  to return how many times it took recursively to find the sequence in the AVL tree
    //@return number of times it took to find the sequences
    int  find (const Comparable & item)
    {
    	return find(item,root,UseToInitailize ); 
    }

    //main driver for findandRemove
    //integer findandremove function similar to find and remove on the above functions 
    //if it's on the avl tree
    //However this one will search that if the AVL tree contains the object, then removes it
    int findandRemove( const Comparable & item) 
    {
    	return findandRemove(item,root,UseToInitailize ); 
    }
    
    
   
  private:
    struct AvlNode
    {
        Comparable element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;

        AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        
        AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
          : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
    };

    AvlNode *root;

    // for 2.1 
    //printer function that will find the sequence that matches with the one in AVL tree to get the enzyme acronyms
    //It will print out the enzyme acronyms
    void GetAndPrinter( const Comparable &  item, AvlNode * ThePassedRoot)
    {
	    if(ThePassedRoot != nullptr) 
	    {
    		if(item < ThePassedRoot->element )  
    		{
    			return GetAndPrinter( item, ThePassedRoot->left); 
    		}
    		else if((ThePassedRoot->element) < item) 
    		{
    			
    			return GetAndPrinter( item, ThePassedRoot->right);
    		}
    		else
    		{ 
    			cout<<ThePassedRoot->element;
    		}
    	}
    	else
    	{
    		return;
    	}
    }
     

    //part 2b
    //function that return the number of node within the AVL tree
    int ReadForAllNode( AvlNode* thenode) const 
    {
    	if( thenode != nullptr ) 
    	{
    		return ( ReadForAllNode( thenode->left) + ReadForAllNode(thenode->right) +1);
    	}
    	else
    	{      
    		return 0;
    	} 
    }
    
    // function that will return the max depth of the current AVL tree
    double MaximumDepth( AvlNode * thenode, int TotalOfNumbers) const 
    {
    	if( thenode != nullptr) 
    	{	
    		return (TotalOfNumbers + (MaximumDepth ((thenode->left),TotalOfNumbers+1)) + MaximumDepth((thenode->right),TotalOfNumbers+1));
    	}
    	else  
    	{
    		return 0;
    	}
    }

    //similar to contain function on the above on contain to check if it's on the avl tree
    //integer function that would be use to find each string in the sequence.txt file
    //it will return the number of time the recursion being called
    int find(const Comparable & item, AvlNode *thenode, int NumberOfTimeBeingCalled) 
    {
    	NumberOfTimeBeingCalled = NumberOfTimeBeingCalled +1; 
    	if (thenode ==nullptr) 
    	{
    		return 1; 
    	}
    	else if (item < thenode->element) 
    	{
    		return find(item,thenode->left,NumberOfTimeBeingCalled); 
    	}
    	else if(thenode->element <item)
    	{
    		return find(item, thenode->right,NumberOfTimeBeingCalled); 
    	}
    	return NumberOfTimeBeingCalled; 
    }
    
    //Combination of find and remove function
    //integer findandremove function similar to remove on the above functions 
    //if it's on the avl tree
    //However this one will search that if the AVL tree contains the object, then removes it
    //@NumberOfTimeBeingCalled: return how many times it called to findandremove
    int findandRemove( const Comparable & item, AvlNode * & thenode ,int NumberOfTimeBeingCalled)
    {
    	NumberOfTimeBeingCalled = NumberOfTimeBeingCalled+ 1;
        if( thenode == nullptr ) 
            return 1;
        if( item < thenode->element ) 
        {
             //it will go through the left side 
            return findandRemove( item, thenode->left, NumberOfTimeBeingCalled); 
        }
        else if( thenode->element < item ) 
        {
            //it will go through the right side 
            return findandRemove( item, thenode->right ,NumberOfTimeBeingCalled); 
         }
        else if( thenode->left != nullptr && thenode->right != nullptr ) // Two children, when both of them are not empty
        {
            thenode->element = findMin( thenode->right )->element; 
            return findandRemove( thenode->element, thenode->right,NumberOfTimeBeingCalled );
        }
        else
        {
            // declare new node that initalize from the node being passed
            AvlNode *deleteNode=thenode; 
            thenode = ( thenode->left != nullptr ) ? thenode->left : thenode->right; 
            delete deleteNode;  
        }
        balance(thenode);
        return NumberOfTimeBeingCalled; 
    }	
    
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
            t = new AvlNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
        {
        	t->element.Merge(x);
        }
        balance( t );
    }

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, AvlNode * & t )
    {
        if( t == nullptr )
            t = new AvlNode{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        else
        {
        	t->element.Merge(x);
        }
        
        balance( t );
    }
     
    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            AvlNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
        
        balance( t );
    }
    
    static const int ALLOWED_IMBALANCE = 1;

    // Assume t is balanced or within one of being balanced
    void balance( AvlNode * & t )
    {
        if( t == nullptr )
            return;
        
        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE ) {
            if( height( t->left->left ) >= height( t->left->right ) )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t->left );
        } else if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE ) {
            if( height( t->right->right ) >= height( t->right->left ) )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t->right );
	}
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }
    
    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    AvlNode * findMin( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    AvlNode * findMax( AvlNode *t ) const
    {
        if( t != nullptr )
            while( t->right != nullptr )
                t = t->right;
        return t;
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
/****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( AvlNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( AvlNode *t ) const
    {
        if( t != nullptr )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }

    /**
     * Internal method to clone subtree.
     */
    AvlNode * clone( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new AvlNode{ t->element, clone( t->left ), clone( t->right ), t->height };
    }
        // Avl manipulations
    /**
     * Return the height of node t or -1 if nullptr.
     */
    int height( AvlNode *t ) const
    {
        return t == nullptr ? -1 : t->height;
    }

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild( AvlNode * & k2 ) // 
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild( AvlNode * & k1 ) //
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    //This is a double rotation without calling two single rotations
    void doubleWithLeftChild( AvlNode * & k1 ) 
    {
    	AvlNode *k2 = k1->right; 
        k1->right = k2->left; 
        k2->left = k1; 
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;   
        AvlNode *k8 = k1->left; 
        k1->left = k8->right;
        k8->right = k1; 
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k8->height = max( height( k8->left ), k1->height ) + 1; 
        k1 = k8;  	      
    }

    /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
    //This is a double rotation without calling two single rotations
    void doubleWithRightChild( AvlNode * & k1 ) 
    {

        AvlNode *k5 = k1->left; 
        k1->left = k5->right; 
        k5->right = k1;
        k1->height = max (height(k1->left),height(k1->right))+1; 
        k5->height = max(height(k5->left),k1->height)+1; 
        k1=k5;   
        AvlNode *k2 = k1->right; 
        k1->right = k2->left;  
        k2->left = k1; 
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1; 
        k2->height = max( height( k2->right ), k1->height ) + 1; 
        k1 = k2; 
    }
};

#endif
