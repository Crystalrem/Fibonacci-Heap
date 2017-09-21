#ifndef DATA_STRUCTURE_FIB_HRAP_HPP
#define DATA_STRUCTURE_FIB_HRAP_HPP

#include <cstddef>
#include <functional>
#include <map>

namespace data_structrue {

const int error = -1; /* The heap is empty */

template<typename T, class Compare = std::less<T>>

class Fib_heap 
{
public:
    Compare cmp;
    
    size_t heap_size;
    class List;

    struct Node 
    {                                                                                          
        T value;
        int degree, mark; 
        List *children;
        Node *left, *right, *father;
        
        Node() 
        {
            degree = 0; 
            mark = false; 
            children = NULL;
            left = right = father = NULL;
        }
        
        Node(T val, int deg = 0) : value(val), degree(deg) 
        {
            if (deg != -1) children = new List; 
            /* degree of head and tail is -1*/
            else children = NULL;
            left = right = NULL;  mark = false;
        }
        
        ~Node() 
        {
            if(children) delete children;
        }
    }*minn = NULL;
    
    std::map<T, Node*> representation;
    
    class List
    {
    public:
        Node *head, *tail;
        
        List()
        {
            head = new Node(); head -> level = -1; 
            tail = new Node(); tail -> level = -1; 
            head -> right = tail, tail -> left = head;
        }
        
        /*Insert p into the list between L and R*/
        void add(Node *L, Node *p, Node *R)
        {
            L -> right = p, p -> left = L;
            p -> right = R, R -> left = p;
        }
        
        /*Insert p into the list before the tail*/
        void add(Node *p)
        {
            Node *q = tail -> left;
            q -> right = p, p -> left = q;
            p -> right = tail, tail -> left = p;
        }
        
        ~List() 
        {
            Node *q = NULL;
            for (Node *p = head; p; p = q)
            {
                q = p -> right;
                delete p;
            }
        }
        
    };
    
    
    List *rootlist;
    
    Fib_heap() 
    {
        rootlist = new List();
        minn = rootlist -> head;
    }
    
    ~Fib_heap() {}

    /* Merge List last into now */
	void link(List *last, List *now) 
	{
	    if(last -> head -> right == last -> tail) return;
	    Node *p = last -> tail -> left;
	    Node *q = last -> head -> right;
	    p -> right = now -> head -> right;
	    q -> left = now -> head;
	    q -> left -> right = q;
	    p -> right -> left = p;
    }
    
    /* Merge heap with Fib_heap update */
    void merge(Fib_heap *upodate) 
	{
	
	}

    /* Return the minimum of the heap */
	const int & top() const
	{

	}
	
	/* Add element e into heap*/
	void push(const T &e)  
    {
	}
	void consolidate
	{
    }
	/* Delete the minimum of the heap */
	void pop() 
	{
	    if(heap_size == 0) throw error;
	    Node *ret = minn;
	    ret -> left -> right = ret -> right;
	    ret -> right -> left = ret -> left;
	    link(ret -> children, rootlist);
	    delete ret; 
	    heap_size --;
	    minn = rootlist -> head -> right; //minn may point at the tail or head of rootlist
	    consolidate();
	}
	
	/* remove element e */
	void remove(const T &e)
	{
	    
    } 
    
	size_t size() const 
	{
        return heap_size;   
	}
	
	bool empty() const 
	{
        return ( size == 0);
	}
	
}; 

}

#endif  