#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
struct TYPE_10__ {int n; int* data; int element_size; int* ids; int capacity; } ;
typedef  TYPE_1__ BS_LIST ;

/* Variables and functions */
 int INDEX (int) ; 
 int /*<<< orphan*/  free (int*) ; 
 int memcmp (int /*<<< orphan*/  const*,int*,int) ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  memmove (int*,int*,int) ; 
 void* realloc (int*,int) ; 

__attribute__((used)) static int find(const BS_LIST *list, const uint8_t *data)
{
    //should work well, but could be improved
    if (list->n == 0) {
        return INDEX(0);
    }

    uint32_t i = list->n / 2; //current position in the array
    uint32_t delta = i / 2;   //how much we move in the array

    if (!delta) {
        delta = 1;
    }

    int d = -1; //used to determine if closest match is found
    //closest match is found if we move back to where we have already been

    while (1) {
        int r = memcmp(data, list->data + list->element_size * i, list->element_size);

        if (r == 0) {
            return i;
        }

        if (r > 0) {
            //data is greater
            //move down
            i += delta;

            if (d == 0 || i == list->n) {
                //reached bottom of list, or closest match
                return INDEX(i);
            }

            delta = (delta) / 2;

            if (delta == 0) {
                delta = 1;
                d = 1;
            }
        } else {
            //data is smaller
            if (d == 1 || i == 0) {
                //reached top or list or closest match
                return INDEX(i);
            }

            //move up
            i -= delta;

            delta = (delta) / 2;

            if (delta == 0) {
                delta = 1;
                d = 0;
            }
        }
    }
}

__attribute__((used)) static int resize(BS_LIST *list, uint32_t new_size)
{
    void *p;

    p = realloc(list->data, list->element_size * new_size);

    if (!p) {
        return 0;
    } else {
        list->data = p;
    }

    p = realloc(list->ids, sizeof(int) * new_size);

    if (!p) {
        return 0;
    } else {
        list->ids = p;
    }

    return 1;
}

int bs_list_init(BS_LIST *list, uint32_t element_size, uint32_t initial_capacity)
{
    //set initial values
    list->n = 0;
    list->element_size = element_size;
    list->capacity = 0;
    list->data = NULL;
    list->ids = NULL;

    if (initial_capacity != 0) {
        if (!resize(list, initial_capacity)) {
            return 0;
        }
    }

    list->capacity = initial_capacity;

    return 1;
}

void bs_list_free(BS_LIST *list)
{
    //free both arrays
    free(list->data);
    free(list->ids);
}

int bs_list_find(const BS_LIST *list, const uint8_t *data)
{
    int r = find(list, data);

    //return only -1 and positive values
    if (r < 0) {
        return -1;
    }

    return list->ids[r];
}

int bs_list_add(BS_LIST *list, const uint8_t *data, int id)
{
    //find where the new element should be inserted
    //see: return value of find()
    int i = find(list, data);

    if (i >= 0) {
        //already in list
        return 0;
    }

    i = ~i;

    //increase the size of the arrays if needed
    if (list->n == list->capacity) {
        // 1.5 * n + 1
        const uint32_t new_capacity = list->n + list->n / 2 + 1;

        if (!resize(list, new_capacity)) {
            return 0;
        }

        list->capacity = new_capacity;
    }

    //insert data to element array
    memmove(list->data + (i + 1) * list->element_size, list->data + i * list->element_size,
            (list->n - i) * list->element_size);
    memcpy(list->data + i * list->element_size, data, list->element_size);

    //insert id to id array
    memmove(&list->ids[i + 1], &list->ids[i], (list->n - i) * sizeof(int));
    list->ids[i] = id;

    //increase n
    list->n++;

    return 1;
}

int bs_list_remove(BS_LIST *list, const uint8_t *data, int id)
{
    int i = find(list, data);

    if (i < 0) {
        return 0;
    }

    if (list->ids[i] != id) {
        //this should never happen
        return 0;
    }

    //decrease the size of the arrays if needed
    if (list->n < list->capacity / 2) {
        const uint32_t new_capacity = list->capacity / 2;

        if (resize(list, new_capacity)) {
            list->capacity = new_capacity;
        }
    }

    list->n--;

    memmove(list->data + i * list->element_size, list->data + (i + 1) * list->element_size,
            (list->n - i) * list->element_size);
    memmove(&list->ids[i], &list->ids[i + 1], (list->n - i) * sizeof(int));

    return 1;
}

int bs_list_trim(BS_LIST *list)
{
    if (!resize(list, list->n)) {
        return 0;
    }

    list->capacity = list->n;
    return 1;
}

