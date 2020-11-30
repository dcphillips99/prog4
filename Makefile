
537pfsim-fifo:


537pfsim-lru:


537pfsim-clock:


main.o: main.c
	gcc -c main.c

schedulingAlgorithm.o: schedulingAlgorithm.c
	gcc -c schedulingAlgorithm.c

hashTable.o: hashTable.c hashTable.h
	gcc -c hashTable

diskQueue.o: diskQueue.c diskQueue.h
	gcc -c diskQueue.c

pageTable.o: pageTable.c pageTable.h
	gcc -c pageTable.c

pageFrameTable.o: pageFrameTable.c pageFrame.h
	gcc -c pageFrameTable.c

statistics.o: statistics.c statistics.h

clean:
	rm *.o 537pfsim-fifo
	rm *.o 537pfsim-lru
	rm *.o 537pfsim-clock

#
# Run the Clang Static Aynalyzer
#
scan-build: clean
	scan-build -o $(SCAN_BUILD_DIR) make

#
# View the one scan available using firefox
#
scan-view: scan-build
	firefox -new-window $(SCAN_BUILD_DIR)/*/index.html
