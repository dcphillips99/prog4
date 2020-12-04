

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"
#include "diskQueue.h"

const int BUFFER = 256;
const int INIT_VALUE = 0;
/*
 * structure created to keep track of the last iteration
 * and first iteration from a trace file 
 */
struct line {
	char * beginning;
	char * end;
	long int pid;
	int len; // position of beginning ref
	int byte; //number of bytes traversed parse 2
	int init = INIT_VALUE;
	struct line * nextLine;
};

struct parse1 {

	struct line * firstPID;
};

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
	int pidByte = 0; //number of pid bytes passed for 

	struct parse1 count;

	count.firstPID = malloc(sizeof(struct line));
	struct line * curr = &count.firstPID;
	
	while ((parse = fgetc(pidGet)) != EOF) {
		
		if (parse == ' ') {
			
			char * vpn;
			strcat(vpn, parse);

			while ((parse = fgetc(pidGet)) != EOF || parse != '\n') {
				
				strcat(vpn, parse); // pass through the vpn				
			}

			if (atoi(pid) != curr->pid) {

				curr = &count.firstPID;
				
				int out = 0;
				while (curr->init == 1 && out == 0) {

					if (curr->pid == atoi(pid)) {
						out = 1;
					}
					else {
						curr = curr->next;
					}
				}
				
				if (out == 0) {
					struct line * temp;
					temp->init = 1;
					temp->pid = atoi(pid);
					strcpy(temp->beginning, pid);
					strcat(temp->beginning, vpn);
					temp->len = ftell(fp);
				}
				else {
					strcpy(temp->end,pid);
					strcat(temp->end, vpn);
				}

				memset(parse, '\0', pidByte);
				pidByte = 0;
			}
		}
		
		else {
			strcat(pid, parse);
			++pidByte;
		}
	}
	
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
	struct line * tempLine = &pidStruct;
	while ((parse = fgetc(fp)) != EOF) {

		if (parse == ' ') {

			char * vpn;
			strcat(vpn, parse);

			while ((parse = fgetc(fp)) != EOF || parse == '\n') {

				strcat(vpn, parse);
				++byte;
			}
			
			if (pidStruct->pid != pid) {

			}

			else {
				struct Process temp;
				temp->vpn = atoi(vpn);
				temp->pid = atoi(pid);

				struct Page tempPage = lookUpPageFrame(temp, hash);
			       	
				if (tempPage.bit != 1) {
					createNode(temp, diskQueue);
					//need to block because page
					//fault
					tempLine.byte = byte; //save number of bytes
					//weve already parsed
					
					//Either we need to go to the next pid to start
					//parsing, or dequeue from diskQueue and start parsing 
					//from there
					if (tempLine->next->init != 1) {
						
						struct queueNode dequeue = dequeue(diskQueue);

						tempLine = &pidStruct;

						while (tempLine->pid != dequeue.pid) {
							
							tempLine = tempLine->next;
						}
						fseek(fp, tempLine->byte, SEEK_SET); //set pointer
						//to the last byte processed (should be start of a new line)
					}

					else {
						
						tempLine = tempLine->next;
					
						//get each subsequent line until we've found the 
						//beginning line for next process
						while (strcmp(fgets(lastLine, BUFFER, fp), tempLine->beginning) != 0) {
						
							memset(lastLine, '\0', BUFFER);
							continue;
						}
					}
										
				} else {
					//if the tempPage bit is 1, then it is in mem and 
					//continue as normal
				}
				
			}
		}

	}

}
					
