/* Author:            Youssef Almkari                                                */
/* Creation Date:     August 28th, 2014                                              */
/* Due Date:          September 4th, 2014                                            */
/* Course:            CSC237                                                         */
/* Professor Name:    Dr. Schaper                                                    */
/* Assignment:        #1                                                             */
/* File Name:         LinkedList.cpp                                                 */
/* Purpose:           The implementation of the LinkedList                           */

#include <iostream>
#include <assert.h>
#include <fstream>
#include "LinkedList.h"

/*** LinkedList Implementation ***/

/* Function name:  constructor                 */
/* Description:    Construct LinkedList object */
/* Parameters:     None                        */
/* Return Value:   None                        */

LinkedList::LinkedList() : head(NULL) {}

/* Function name:  copy constructor                               */
/* Description:    Make copy of LinkedList                        */
/* Parameters:     LinkedList & : LinkedList to be copied - input */
/* Return Value:   None                                           */

LinkedList::LinkedList(LinkedList &List) { head = copy(List.head); }

/* Function name:  destructor         */
/* Description:    Destroy LinkedList */
/* Parameters:     None               */
/* Return Value:   None               */

LinkedList::~LinkedList() { destroy(head); }

/* Function name:  append                              */
/* Description:    Add integer to LinkedList           */
/* Parameters:     int & : integer to be added - input */
/* Return Value:   void                                */

void LinkedList::append(int number) {
	if(head == NULL)
		head = new node(number, NULL);
	else {
		node *p = head->next;
		node *tp = head;
		
		while(p != NULL) {
			tp = p;
			p = p->next;
		}
		tp->next = new node(number, p);
	}
} 

/* Function name:  empty                  */
/* Description:    Check if list is empty */
/* Parameters:     None                   */
/* Return Value:   bool - true if empty   */

bool LinkedList::empty() {
	return (head == NULL);
}

/* Function name:  destroy                                         */
/* Description:    Destroy LinkedList                              */
/* Parameters:     node * : head of list to destroy - input/output */
/* Return Value:   void                                            */

void LinkedList::destroy(node *list) {
	while(list != NULL) {
		node *doomed = list;
		list = list->next;
		delete doomed;
	}
}

/* Function name:  copy                                       */
/* Description:    Make copy of LinkedList                    */
/* Parameters:     node * : head of list to be copied - input */
/* Return Value:   nod* - head of copied list                 */

node* LinkedList::copy(node *list) {
	node *first = NULL;
	node *last = NULL;
	
	if(list != NULL) {
		first=last = new node(list->data,NULL);
		for(node *src = list->next; src != NULL; src=src->next, last=last->next)
			last->next = new node(src->data, NULL);
	}
	
	return first;
}

/* Function name:  operator<<                                      */
/* Description:    write LinkedList to output stream               */
/* Parameters:     ofstream &ofs : output stream           - input */
/*                 LinkedList  & : LinkedList to be copied - input */
/* Return Value:   ofstream - refrence to output stream            */

std::ofstream& operator<<(std::ofstream &ofs, const LinkedList &list) {
	ListItr itr(list);
	itr.start();
	int lastNum = 0;
	int currNum = 0;
	
	while(itr.more()) {
		currNum = itr.value();
		if(currNum > lastNum) {
			ofs << itr.value() << " ";
			lastNum = currNum;
			itr.next();
		}
		else
			itr.next();
	}
	
	return ofs;
}


/*** ListItr Implementation ***/

/* Function name:  constructor                                     */
/* Description:    constructor ListItr object                      */
/* Parameters:     LinkedList &list : list to be link with - input */
/* Return Value:   None                                            */

ListItr::ListItr(const LinkedList &list) : itr(list), current(list.head) {}

/* Function name:  start                    */
/* Description:    set current to list head */
/* Parameters:     None                     */
/* Return Value:   void                     */
		
void ListItr::start() {
	current = itr.head;
}
		
/* Function name:  more                               */
/* Description:    Check if current is NULL           */
/* Parameters:     None                               */
/* Return Value:   bool - true if current is not NULL */

bool ListItr::more() {
	return (current != NULL);
}
		
/* Function name:  lastNode                         */
/* Description:    Destroy LinkedList               */
/* Parameters:     None                             */
/* Return Value:   bool - true if next node is NULL */

void ListItr::next() {
	current = current->next;
}
		
/* Function name:  value             */
/* Description:    returns node data */
/* Parameters:     None              */
/* Return Value:   int - node data   */

bool ListItr::lastNode() {
	return (current->next == NULL);
}
		
/* Function name:  lastNode                         */
/* Description:    Destroy LinkedList               */
/* Parameters:     None                             */
/* Return Value:   bool - true if next node is NULL */

int& ListItr::value() const {
	return (current->data);
}
		
/* Function name:  lastNode                         */
/* Description:    Destroy LinkedList               */
/* Parameters:     None                             */
/* Return Value:   bool - true if next node is NULL */

int& ListItr::value() {
	return (current->data);
}

