/* Author:            Youssef Almkari                                                */
/* Creation Date:     August 28th, 2014                                              */
/* Due Date:          September 4th, 2014                                            */
/* Course:            CSC237                                                         */
/* Professor Name:    Dr. Schaper                                                    */
/* Assignment:        #1                                                             */
/* File Name:         LinkedList.h                                                   */
/* Purpose:           To represent a LinkedList data structure that holds integers   */

#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include <iostream>
#include <assert.h>
#include <fstream>

/** Node **/
class node {
	private:
		node(int num, node *link = NULL) : data(num), next(link) {};
		
		int data;
		node *next;
		
		// needed to access members: data, next
		friend class LinkedList;
		friend class ListItr;

};

/** LinkedList **/
class LinkedList {
	private:
		node *head;
		
	/* Function name:  destroy                          */
    /* Description:    Destroy LinkedList               */
    /* Parameters:     node * : head of list to destroy */
    /* Return Value:   void                             */
		
		void destroy(node *);  // used by destructor 
		
    /* Function name:  copy                               */
    /* Description:    Make copy of LinkedList            */
    /* Parameters:     node * : head of list to be copied */
    /* Return Value:   nod* - head of copied list         */
		
		node* copy(node *);    // used by copy constructor 
		
		friend class ListItr;  // needed to access 'head'
		
	public:
    /* Function name:  constructor                 */
    /* Description:    Construct LinkedList object */
    /* Parameters:     None                        */
    /* Return Value:   None                        */
		
		LinkedList();
		
    /* Function name:  copy constructor                       */
    /* Description:    Make copy of LinkedList                */
    /* Parameters:     LinkedList & : LinkedList to be copied */
    /* Return Value:   None                                   */
		
		LinkedList(LinkedList &);
		
    /* Function name:  destructor         */
    /* Description:    Destroy LinkedList */
    /* Parameters:     None               */
    /* Return Value:   None               */
		
		~LinkedList();
		
    /* Function name:  append                      */
    /* Description:    Add integer to LinkedList   */
    /* Parameters:     int & : integer to be added */
    /* Return Value:   void                        */		
		
		void append(int);
		
    /* Function name:  empty                  */
    /* Description:    Check if list is empty */
    /* Parameters:     None                   */
    /* Return Value:   bool - true if empty   */
		
		bool empty();
		
    /* Function name:  operator<<                              */
    /* Description:    write LinkedList to output stream       */
    /* Parameters:     ofstream &ofs : output stream           */
	/*                 LinkedList  & : LinkedList to be copied */
    /* Return Value:   ofstream - refrence to output stream    */
		
		friend std::ofstream& operator<<(std::ofstream &ofs, const LinkedList &);
		
};

/** ListItr **/
class ListItr {
	private:
		const LinkedList &itr;
		node *current;
		
	public:
	
    /* Function name:  constructor                             */
    /* Description:    constructor ListItr object              */
    /* Parameters:     LinkedList &list : list to be link with */
    /* Return Value:   None                                    */
		
		ListItr(const LinkedList &list);
		
    /* Function name:  start                    */
    /* Description:    set current to list head */
    /* Parameters:     None                     */
    /* Return Value:   void                     */
		
		void start();
		
    /* Function name:  more                               */
    /* Description:    Check if current is NULL           */
    /* Parameters:     None                               */
    /* Return Value:   bool - true if current is not NULL */
		
		bool more();
		
    /* Function name:  next              */
    /* Description:    Move to next node */
    /* Parameters:     None              */
    /* Return Value:   void              */
		
		void next();
		
    /* Function name:  lastNode                         */
    /* Description:    Destroy LinkedList               */
    /* Parameters:     None                             */
    /* Return Value:   bool - true if next node is NULL */
		
		bool lastNode();
		
    /* Function name:  value             */
    /* Description:    returns node data */
    /* Parameters:     None              */
    /* Return Value:   int - node data   */
		
		int& value() const;

    /* Function name:  value             */
    /* Description:    returns node data */
    /* Parameters:     None              */
    /* Return Value:   int - node data   */
		
		int& value();
};


#endif
