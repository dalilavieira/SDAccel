#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint16_t ;
struct TYPE_11__ {int* buffer; scalar_t__ head; scalar_t__ tail; int size; int free; scalar_t__ overrun; } ;
typedef  TYPE_1__ FIFO_Data_TypeDef ;

/* Variables and functions */
 int __LDREXH (int*) ; 
 scalar_t__ __STREXH (int,int*) ; 

bool FIFO_InitStruct(FIFO_Data_TypeDef *inStruct, uint8_t* inBuf, uint16_t inBufSize) {
	if(inStruct == NULL || inBuf == NULL)
		return false;
	inStruct->buffer = inBuf;
	inStruct->head = 0;
	inStruct->tail = 0;
	inStruct->size = inBufSize;
	inStruct->free = inBufSize;
	inStruct->overrun = 0;
	return true;
}

inline bool FIFO_write(FIFO_Data_TypeDef *inStruct, uint8_t inByte) {
    uint16_t workFree;
	if(inStruct->free <= 0) {
		inStruct->overrun++;
		return false;
	}

    inStruct->buffer[inStruct->head++] = inByte;
    if(inStruct->head >= inStruct->size)
        inStruct->head = 0;

    do {
        workFree = __LDREXH(&inStruct->free);
        workFree -= 1;
    } while( __STREXH(workFree, &inStruct->free));


	return true;
}

bool FIFO_write_bytes(FIFO_Data_TypeDef *inStruct, uint8_t *inBytes, uint16_t count) {
	int i;
	uint16_t workFree;

	if(inStruct->free < count) {
		inStruct->overrun++;
		return false;
	}

    for(i = 0; i < count; i++) {
        inStruct->buffer[inStruct->head++] = inBytes[i];
        if(inStruct->head >= inStruct->size)
            inStruct->head = 0;
    }
    do {
        workFree = __LDREXH(&inStruct->free);
        workFree -= count;
    } while( __STREXH(workFree, &inStruct->free));

	return true;
}

bool FIFO_read(FIFO_Data_TypeDef *inStruct, uint8_t *outByte, uint16_t count) {
	int i;
	uint16_t workFree;

	if( count > (inStruct->size - inStruct->free) )
		return false;

	for(i = 0; i < count; i++) {
		outByte[i] = inStruct->buffer[inStruct->tail++];
		if(inStruct->tail >= inStruct->size) {
			inStruct->tail = 0;
		}
	}
    do {
        workFree = __LDREXH(&inStruct->free);
        workFree += count;
    } while( __STREXH(workFree, &inStruct->free));

	return true;
}

uint16_t FIFO_read_until(FIFO_Data_TypeDef *inStruct, uint8_t *outByte, uint16_t max, const char *searchList, uint8_t listLength) {
	int i, j, ptr, available;

	available = inStruct->size - inStruct->free;
	if(available > max)
		available = max;
	ptr = inStruct->tail;
	for(i = 0; i < available; i++) {
		for(j = 0; j < listLength; j++) {
			if( inStruct->buffer[ptr] == searchList[j] ) {
				// found something we are looking for so build the return string
				FIFO_read( inStruct, outByte, i+1 );
				return i+1;
			}
		}
		ptr++;
		if(ptr >= inStruct->size)
			ptr = 0;
	}
	// cover the case where we didn't encounter a line ending but have hit the max length
	if(i == max) {
		FIFO_read(inStruct, outByte, i);
		return i;
	}
	return 0;
}

uint16_t FIFO_read_token(FIFO_Data_TypeDef *inStruct, uint8_t *outBytes, uint16_t max, const char *delimiters, uint8_t listLength) {
	int i, j, ptr, available, start;
	bool found;

	start = -1;

	available = inStruct->size - inStruct->free;
	if(available > max)
		available = max;
	ptr = inStruct->tail;
	for(i = 0; i < available; i++) {
        found = false;
		for(j = 0; j < listLength; j++) {
			if( inStruct->buffer[ptr] == delimiters[j] ) {
                // found something we are looking for so build the return string
                found = true;
			    if(start != -1) {
                    // discard the first bytes
                    if(start != 0)
                        FIFO_read( inStruct, outBytes, start );
                    // read the remaining non-delimiters (throw away ending delimiter by returning 1 less than bytes read)
			        FIFO_read( inStruct, outBytes, i+1-start );
                    return i-start;
			    }
			    break;
			}
		}
		if(!found && start == -1)
            start = i;

		ptr++;
		if(ptr >= inStruct->size)
			ptr = 0;
	}

	// cover the case where we didn't encounter a delimiter but have hit the max length
	if(i == max) {
		FIFO_read(inStruct, outBytes, i);
		return i;
	}
	return 0;
}

uint8_t FIFO_peek(FIFO_Data_TypeDef *inStruct) {
	return inStruct->buffer[inStruct->tail];
}

uint16_t FIFO_available(FIFO_Data_TypeDef *inStruct) {
	return inStruct->size - inStruct->free;
}

uint16_t FIFO_free(FIFO_Data_TypeDef *inStruct) {
	return inStruct->free;
}

