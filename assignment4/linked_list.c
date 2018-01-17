
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Created By
 Doron Nussbaum 2016
 
 Modifications:
 November 2017 - minor modifications
 
 
 Copyright 2017
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, char *firstName, char *familyName){
	//add code
	PersonalInfo *newNode = (PersonalInfo *)malloc(sizeof(PersonalInfo));
	if(newNode == NULL) {
		return NULL;
	}
	if(*head == NULL) {
		*head = newNode;
		newNode->next = NULL;
		newNode->id = id;
		strcpy(newNode->firstName,firstName);
		strcpy(newNode->familyName,familyName);
		return newNode;
	}
	else {
		newNode->next = *head;
		*head = newNode;
		newNode->id = id;
		strcpy(newNode->firstName,firstName);
		strcpy(newNode->familyName,familyName);
		return newNode;

	}
	//return pointer to node that was allocated 
}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName){
	// add code
	//check if the node exists
	if (node == NULL){
		return NULL;
	} 
	else{
		PersonalInfo *createdNode = NULL;
		createdNode = (PersonalInfo *)malloc(sizeof(PersonalInfo));
		
		//set information for createdNode
		createdNode->id = id;
		strcpy(createdNode->firstName, firstName);
		strcpy(createdNode->familyName, familyName);
		//node point to next node
		createdNode->next = node->next;
		//point to new struct
		node->next = createdNode;
		//return pointer to node tht was allocated
		return createdNode;
	}


}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName){
	//check if the head has atleast one elemeent
	
	PersonalInfo *newNode = (PersonalInfo*)malloc(sizeof(PersonalInfo));

	if (newNode == NULL){
		printf("Unable to allocate memory");
		return NULL;
	}
	newNode->id = id;
	strcpy(newNode->firstName, firstName);
	strcpy(newNode->familyName, familyName);

	if (*head == NULL){
		//add to the front of the list since the head has no elements
		return insertToList(head, id, firstName, familyName);
	} else {
		//iterate throught the list to find the end
		PersonalInfo *temp = *head;
		while(temp->next != NULL) {
			//set temp as them current node until it is the last node
			temp = temp->next;
		}
		//return new node at the end 
		return insertAfter(temp, id, firstName, familyName);
	}

}


/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName){
	//add code
	//if head is empty
	if (head == NULL){
		return NULL;
	} 
	else{
		//loop and find node with name searched for 
		PersonalInfo *tempNode = head;
		while(tempNode != NULL){
			//find node with name
			if (strcmp(tempNode->firstName, firstName)==0) {
				//pointer to node searched and found 
				return tempNode;
			} 
			else{
				//set node to next
				tempNode = tempNode->next;
			}
		}
	}

}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id){
	//add code
	//if head is empty
	if (head == NULL){
		return NULL;
	} 
	else{
		//loop to find node with ID tht was searched 
		PersonalInfo *tempNode = head;
		while(tempNode != NULL) {
			//find node with ID
			if (tempNode->id == id){
				return tempNode;
			} 
			else{
				//set set node to next
				tempNode = tempNode->next;
			}
		}
	}
    
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id, char *firstName, char *familyName){
    	//add code
	//if head is empty
	if (*head == NULL){
		//return 1 because it is empty or not removed
		return 1;
	}
	else{
		//set node and update it
		PersonalInfo *tempNode = *head;

		*head = tempNode->next;

		strcpy(firstName, tempNode->firstName);
		strcpy(familyName, tempNode->familyName);
		*id = tempNode->id;

		free(tempNode);
		//return 0 if node was deleted
		return 0;
	}

}




/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id, char *firstName, char *familyName){
	//add code
	//if head is empty
	if (*head == NULL){
		//return 1 because node is empty or was not removed
		return 1;
	} 
	PersonalInfo *tempNode = *head;
	PersonalInfo *current;
	if (tempNode->next == NULL){
		free(tempNode->next);
		deleteFromList(head, id, firstName, familyName);
	}
	else{
		//loop to find last node 
		while (tempNode->next != NULL) {
			current = tempNode;
			tempNode = tempNode->next;
		}

		strcpy(firstName, tempNode->firstName);
		strcpy(familyName, tempNode->familyName);
		*id = tempNode->id;

		free(current->next);
		current->next = NULL;
		//return 0 if node was deleted 
		return 0;
 	}

}



/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of deleted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonalInfo *node, unsigned int *id, char *firstName, char *familyName){
   	// add code
	// return 1 if node was not deleted
	if (node == NULL || node->next == NULL){
		return 1;
	} 
	else{
		//keep tracked of removed Node
		PersonalInfo *removedNode = node->next;
		//set the next node to next next node
		node->next = removedNode->next;

		strcpy(firstName, removedNode->firstName);
		strcpy(familyName, removedNode->familyName);
		*id = removedNode->id;

		free(removedNode);
		//return 0 if node was deleted 
		return 0;
	}

}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName, char *familyName, unsigned int *id){
	//add code 
	//if head is empty
	PersonalInfo *tempNode = *head;
	PersonalInfo *prev = NULL;

	if (*head == NULL){
		//return 1 if node was not found 
		return 1;
	}
	if(strcmp(tempNode->firstName,firstName)==0) {
		prev = tempNode->next;
		*head = prev;
	
		strcpy(firstName, tempNode->firstName);
		strcpy(familyName, tempNode->familyName);
		*id = tempNode->id;

		free(tempNode);
		return 0;
	}
	
	while (tempNode->next != NULL){	
		if (strcmp(tempNode->next->firstName, firstName)==0){
			prev = tempNode->next->next;

			strcpy(firstName, tempNode->next->firstName);
			strcpy(familyName, tempNode->next->familyName);
			*id = tempNode->next->id;

			free(tempNode->next);
			tempNode->next = prev;
			return 0;
		}
		else{
			tempNode = tempNode->next;
		}
	}
	return 1;
	

}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head){
	//add code
	//pointers for currentNode and nextNode
	PersonalInfo *tempNode = *head;
	PersonalInfo *next = NULL;
	//loop the list
	while(tempNode != NULL) {
		//set nextNode to currentNodes nextNode
		next = tempNode->next;
		free(tempNode);
		tempNode = next;
	}
	*head = NULL;
}



/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node){
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);

}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head){
	//add code
	PersonalInfo *tempNode = head;
	//loop through 
	while (tempNode != NULL){
		printNode(tempNode);
		//set node to next
		tempNode = tempNode->next;
	}
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head){
	//add code 
	int counter = 0;
	//create temp node
	PersonalInfo *tempNode = head;
	//loop throguh list
	while (tempNode != NULL) {
		//keep track of each item in list
		counter++;
		tempNode = tempNode->next;
	}
	//return number of nodes in the list
	return counter;
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countRecords(PersonalInfo *head, char *firstName){
	//add code
	int counter = 0;
	//create temp node
	PersonalInfo *tempNode = head;
	while (tempNode != NULL) {
		//compare name in tempNode to name searched
		if (strcmp(tempNode->firstName, firstName)==0) {
			//keep track of times that a name has appeared in node
			counter++;
		}
		//next node
		tempNode = tempNode->next;
	}
	//return the number of nodes in the list that match the first name
	return counter;
}




/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list



*/




void removeDuplicates(PersonalInfo *head){
	//add code
	//if head is not empty
	if (head != NULL){
		PersonalInfo *tempNode = head;
		PersonalInfo *next = NULL;
		//loop through the list
		while (tempNode->next != NULL){
			//compare first names
			if (strcmp(tempNode->firstName, tempNode->next->firstName)==0){
				next = tempNode->next->next;
				free(tempNode->next);
				tempNode->next = next;
			} 
			else{
				//move tempNode to next position
				tempNode = tempNode->next;
			}
		}
	}

}

