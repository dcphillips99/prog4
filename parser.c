

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"
#include "diskQueue.h"

const int INIT_VALUE = 0;
/*
 * structure created to keep track of the last iteration
 * and first iteration from a trace file 
 */
struct line {
	char * beginning;
	char * end;
	long int pid;
	int byte;
	int numVPNs;
	int init = INIT_VALUE;
	struct line * nextLine;
};

struct parse1 {
	int uniquePIDs;
	struct line * firstPID;
};

struct parse1 count;

/*
 * returns the number of pages found
 *
 * param: PID - the line struct to be added
 * to the last line
 *
 * traverse through all the linked line structs
 * and adds the line to the end
 *
 */
int findLine(struct line * PID) {
	if (count.firstPID->init == 0) {
		count.firstPID = PID;
		return 1;
	}

	else {
		struct line * unused = count.firstPID;
		
		int counter = 0;
		while (unused->init != 0) {
			
			unused->nextLine = unused->nextLine->nextLine;
			counter++;
		}
		
		unused->nextLine = PID;
		return counter;
	}
	
	return 0;
}

void count_parse(char * filename) {

	FILE * fp;

	fp = fopen(filename, "r");

	if (fp == NULL) {
		perror("Error opening file.");
		exit(0);
	}

	int pidCounter = 0;
	int vpnCounter = 0;
	char * pid;
	char * previousPID;
	char parse;
	int pidbytes = 0;
	
	//while loop iterating through the file
	while ((parse = fgetc(fp)) != EOF) {
		
		//finds the space between pid and vpn
		if (parse == ' ') {
			
			//checks that there is (or isn't) a previous pid to compare
			//to, as well as if the previous pid is the same as current
			//pid
			if (previousPID == NULL || strcmp(pid, previousPID) != 0) {
				
				//if it is, copy the current into previous
				//and clear the current string
				strcpy(previousPID, pid);
				memset(pid, '\0', pidBytes);
			}
			else {
				//if there is a previous pid and it is not
				//the same as the current, update # of pids,
				//then do the same as above (cpy and clear)
				pidCounter++;
				strcpy(previousPID, pid);
				memset(pid, '\0', pidBytes);
			}
			
			//iterate through the vpn since we've passed the space
			//iterates until a newline char
			while ((parse = fgetc(fp)) != EOF || parse != '\n') {
				
				continue;
			}
		}
		
		//if the current char (parse) is not a space,
		//then we concat to pid string as we are before a space
		//and therefore recording a pid 
		else {
			strcat(pid, parse);
			pidBytes++;
		}
	}

	//init the parse1 struct to have the correct num of unique
	//pids, as well as enough entries in the array of structs
	//such that 1 entry per pid (containing first and last
	//access, number of vpns, etc.)
	count.uniquePIDs = pidCount;
	count.firstPID = malloc(sizeof(struct line) * pidCount);
}

/*
 * parser function that opens a file 
 * with the file name, and looks through each byte
 * either adding it to the pid string or vpn string
 * once a space is found.
 * 
 * Creates hash table entries based off of the trace file.
 *
 * param: filename - the name of the trace file 
 *
 */
struct line parser(char * filename) {
	
	
	FILE * pidGet;

	pidGet = fopen(filename, "r");

	if (pidGet == NULL) {
		perror("Error opening file.");
		exit(0);
	}
	
	char * pid;
	char * previousLine;
	char parse;
	int byte = 0; //total number of bytes passed
	int pidByte = 0; //number of pid bytes passed for 
	int line = 0; //counts num of lines for each pid
	//clearing the string at the end 
	int vpnCount = 0;
	struct line * curr = count.firstPID;
	
	while ((parse = fgetc(pidGet)) != EOF) {
		
		if (parse == ' ') {
			
			char * vpn = parse;

			while ((parse = fgetc(pidGet)) != EOF || parse != '\n') {

				strcat(vpn, parse);
				++byte;
			}
			++vpnCount;
			if (curr->init == 0) { //for the first time through
				//since curr isn't initilized, it will init
				//it 
				curr->init = 1;
				curr->pid = atoi(pid);
				strcpy(curr->beginning, pid);
				strcat(curr->beginning, vpn);
			}
			else {
				//if the curr structs pid does not
				//match the current pid read
				if (curr->pid != atoi(pid)) {
					//copy the last line in end,
					//set the number of bytes and vpns
					//and create a new line struct
					//such that it is init, and has current
					//pid and is added to last line
					strcpy(curr->end, previousLine);
					curr->byte = byte;
					curr->numVPNs = vpnCount - 1;
					vpnCount = 0;
					byte = 0;

					struct line * tempLine;
					tempLine->pid = atoi(pid);
					strcpy(curr->beginning, pid);
					strcat(curr->beginning, vpn);

					curr->nextLine = tempLine;
					curr = curr->nextLine;

					memset(lastLine, '\0', 1); //clear last line so 
					//we dont mix pids 
				}
				else {

					if (curr->beginning == NULL) {
						strcpy(curr->beginning, pid);
						strcat(curr->beginning, vpn);
					}

					memset(lastLine, '\0', 1);
				}

				line++;
				strcpy(lastLine, pid);
				strcat(lastLine, vpn);

				memset(pid, '\0', pidByte);
				pidByte = 0;
			}
		}
		else {
			strcat(pid, parse);
			++pidByte;


	}

	strcpy(curr->end, lastLine);
	curr->byte = byte;
	curr->numVPN = vpnCount;
	
	fclose(pidGet);
	return count.firstPID;
	

}

void parser3(char * filename, struct diskQueue * diskQueue, struct Hash * hash, struct line * pidStruct) {
	
	FILE * fp;
	fp = fopen(filename);

	if (fp == NULL) {

		perror("Error opening file");
		exit(0);
	}
	
	char * lastLine;
	char * pid;
	char parse;
	int byte = 0;
	struct line tempLine = &pidStruct;
	while ((parse = fgetc(fp)) != EOF) {

		if (parse == ' ') {

			char * vpn;
			strcat(vpn, parse);

			while ((parse = fgetc(fp)) != EOF) {

				strcat(vpn, parse);
				++byte;
			}
			
			if (pidStruct->pid != pid) {

			}

			else {
				struct entry temp;
				temp->vpn = atoi(vpn);
				temp->pid = atoi(pid);

				struct page tempPage = lookUpPageFrame(temp, hash);
			       	
				if (tempPage.bit != 1) {
					createNode(temp, diskQueue);
					//need to block because page
					//fault
					tempLine = tempLine->next;
					
				}
			}
		}

	}

}
					
