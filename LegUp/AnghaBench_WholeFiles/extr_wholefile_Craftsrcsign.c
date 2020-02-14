#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {int x; int y; int z; int face; char* text; } ;
struct TYPE_14__ {int capacity; int size; TYPE_2__* data; } ;
typedef  TYPE_1__ SignList ;
typedef  TYPE_2__ Sign ;

/* Variables and functions */
 int MAX_SIGN_LENGTH ; 
 scalar_t__ calloc (int,int) ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  memcpy (TYPE_2__*,TYPE_2__*,int) ; 
 int sign_list_remove (TYPE_1__*,int,int,int,int) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,int) ; 

void sign_list_alloc(SignList *list, int capacity) {
    list->capacity = capacity;
    list->size = 0;
    list->data = (Sign *)calloc(capacity, sizeof(Sign));
}

void sign_list_free(SignList *list) {
    free(list->data);
}

void sign_list_grow(SignList *list) {
    SignList new_list;
    sign_list_alloc(&new_list, list->capacity * 2);
    memcpy(new_list.data, list->data, list->size * sizeof(Sign));
    free(list->data);
    list->capacity = new_list.capacity;
    list->data = new_list.data;
}

void _sign_list_add(SignList *list, Sign *sign) {
    if (list->size == list->capacity) {
        sign_list_grow(list);
    }
    Sign *e = list->data + list->size++;
    memcpy(e, sign, sizeof(Sign));
}

void sign_list_add(
    SignList *list, int x, int y, int z, int face, const char *text)
{
    sign_list_remove(list, x, y, z, face);
    Sign sign;
    sign.x = x;
    sign.y = y;
    sign.z = z;
    sign.face = face;
    strncpy(sign.text, text, MAX_SIGN_LENGTH);
    sign.text[MAX_SIGN_LENGTH - 1] = '\0';
    _sign_list_add(list, &sign);
}

int sign_list_remove(SignList *list, int x, int y, int z, int face) {
    int result = 0;
    for (int i = 0; i < list->size; i++) {
        Sign *e = list->data + i;
        if (e->x == x && e->y == y && e->z == z && e->face == face) {
            Sign *other = list->data + (--list->size);
            memcpy(e, other, sizeof(Sign));
            i--;
            result++;
        }
    }
    return result;
}

int sign_list_remove_all(SignList *list, int x, int y, int z) {
    int result = 0;
    for (int i = 0; i < list->size; i++) {
        Sign *e = list->data + i;
        if (e->x == x && e->y == y && e->z == z) {
            Sign *other = list->data + (--list->size);
            memcpy(e, other, sizeof(Sign));
            i--;
            result++;
        }
    }
    return result;
}

