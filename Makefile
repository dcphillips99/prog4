
537pfsim-fifo: main.o mainMem.o FIFO.o hashTable.o diskQueue.o pageTable.o pageFrameTable.o statistics.o
	gcc -c main.o mainMem.o FIFO.o hashTable.o diskQueue.o pageTable.o pageFrameTable.o statistics.o

537pfsim-lru: main.o mainMem.o LRU.o hashTable.o diskQueue.o pageTable.o pageFrameTable.o statistics.o
	gcc -c main.o mainMem.o LRU.o hashTable.o diskQueue.o pageTable.o pageFrameTable.o statistics.o

537pfsim-clock: main.o mainMem.o CLOCK.o hashTable.o diskQueue.o pageTable.o pageFrameTable.o statistics.o
	gcc -c main.o mainMem.o CLOCK.o hashTable.o diskQueue.o pageTable.o pageFrameTable.o statistics.o

main.o: main.c
	gcc -c main.c

mainMem.o: mainMem.c mainMem.h
	gcc -c mainMem.c
	
FIFO.o: FIFO.c FIFO.h
	gcc -c FIFO.c

LRU.o: LRU.c LRU.h
	gcc -c LRU.c

CLOCK.o: CLOCK.c CLOCK.h
	gcc - CLOCK.c

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
