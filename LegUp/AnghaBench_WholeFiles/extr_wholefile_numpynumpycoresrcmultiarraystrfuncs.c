#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int npy_intp ;
struct TYPE_2__ {int /*<<< orphan*/  type; int /*<<< orphan*/  elsize; } ;
typedef  int Py_ssize_t ;
typedef  int /*<<< orphan*/  PyObject ;
typedef  int /*<<< orphan*/  PyArrayObject ;

/* Variables and functions */
 char* PyArray_DATA (int /*<<< orphan*/ *) ; 
 TYPE_1__* PyArray_DESCR (int /*<<< orphan*/ *) ; 
 int* PyArray_DIMS (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * PyArray_GETITEM (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ PyArray_ISEXTENDED (int /*<<< orphan*/ *) ; 
 int PyArray_NBYTES (int /*<<< orphan*/ *) ; 
 int PyArray_NDIM (int /*<<< orphan*/ *) ; 
 int* PyArray_STRIDES (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PyArray_free (char*) ; 
 char* PyArray_malloc (int) ; 
 char* PyArray_realloc (char*,int) ; 
 int /*<<< orphan*/ * PyErr_NoMemory () ; 
 int /*<<< orphan*/ * PyObject_Repr (int /*<<< orphan*/ *) ; 
 char* PyString_AsString (int /*<<< orphan*/ *) ; 
 int PyString_Size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * PyUString_FromFormat (char*,char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/ * PyUString_FromStringAndSize (char*,int) ; 
 int /*<<< orphan*/  Py_XDECREF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memmove (char*,char*,int) ; 

__attribute__((used)) static char *
extend_str(char **strp, Py_ssize_t n, Py_ssize_t *maxp)
{
    char *str = *strp;
    Py_ssize_t new_cap;

    if (n >= *maxp - 16) {
        new_cap = *maxp * 2;

        if (new_cap <= *maxp) {     /* overflow */
            return NULL;
        }
        str = PyArray_realloc(*strp, new_cap);
        if (str != NULL) {
            *strp = str;
            *maxp = new_cap;
        }
    }
    return str;
}

__attribute__((used)) static int
dump_data(char **string, Py_ssize_t *n, Py_ssize_t *max_n, char *data, int nd,
          npy_intp *dimensions, npy_intp *strides, PyArrayObject* self)
{
    PyObject *op = NULL, *sp = NULL;
    char *ostring;
    npy_intp i, N, ret = 0;

#define CHECK_MEMORY do {                           \
        if (extend_str(string, *n, max_n) == NULL) {    \
            ret = -1;                               \
            goto end;                               \
        }                                           \
    } while (0)

    if (nd == 0) {
        if ((op = PyArray_GETITEM(self, data)) == NULL) {
            return -1;
        }
        sp = PyObject_Repr(op);
        if (sp == NULL) {
            ret = -1;
            goto end;
        }
        ostring = PyString_AsString(sp);
        N = PyString_Size(sp)*sizeof(char);
        *n += N;
        CHECK_MEMORY;
        memmove(*string + (*n - N), ostring, N);
    }
    else {
        CHECK_MEMORY;
        (*string)[*n] = '[';
        *n += 1;
        for (i = 0; i < dimensions[0]; i++) {
            if (dump_data(string, n, max_n,
                          data + (*strides)*i,
                          nd - 1, dimensions + 1,
                          strides + 1, self) < 0) {
                return -1;
            }
            CHECK_MEMORY;
            if (i < dimensions[0] - 1) {
                (*string)[*n] = ',';
                (*string)[*n+1] = ' ';
                *n += 2;
            }
        }
        CHECK_MEMORY;
        (*string)[*n] = ']';
        *n += 1;
    }

#undef CHECK_MEMORY

end:
    Py_XDECREF(op);
    Py_XDECREF(sp);
    return ret;
}

__attribute__((used)) static PyObject *
array_repr_builtin(PyArrayObject *self, int repr)
{
    PyObject *ret;
    char *string;
    /* max_n initial value is arbitrary, dump_data will extend it */
    Py_ssize_t n = 0, max_n = PyArray_NBYTES(self) * 4 + 7;

    if ((string = PyArray_malloc(max_n)) == NULL) {
        return PyErr_NoMemory();
    }

    if (dump_data(&string, &n, &max_n, PyArray_DATA(self),
                  PyArray_NDIM(self), PyArray_DIMS(self),
                  PyArray_STRIDES(self), self) < 0) {
        PyArray_free(string);
        return NULL;
    }

    if (repr) {
        if (PyArray_ISEXTENDED(self)) {
            ret = PyUString_FromFormat("array(%s, '%c%d')",
                                       string,
                                       PyArray_DESCR(self)->type,
                                       PyArray_DESCR(self)->elsize);
        }
        else {
            ret = PyUString_FromFormat("array(%s, '%c')",
                                       string,
                                       PyArray_DESCR(self)->type);
        }
    }
    else {
        ret = PyUString_FromStringAndSize(string, n);
    }

    PyArray_free(string);
    return ret;
}

