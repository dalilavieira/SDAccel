#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_1__ ;

/* Type definitions */
typedef  int npy_hash_t ;
struct TYPE_41__ {TYPE_1__* base; TYPE_1__* shape; } ;
struct TYPE_40__ {char byteorder; TYPE_3__* subarray; struct TYPE_40__* fields; struct TYPE_40__* names; int /*<<< orphan*/  alignment; int /*<<< orphan*/  elsize; int /*<<< orphan*/  flags; int /*<<< orphan*/  kind; } ;
typedef  scalar_t__ Py_ssize_t ;
typedef  TYPE_1__ PyObject ;
typedef  TYPE_1__ PyArray_Descr ;
typedef  TYPE_3__ PyArray_ArrayDescr ;

/* Variables and functions */
 int /*<<< orphan*/  NPY_CPU_BIG ; 
 int /*<<< orphan*/  PyArray_DescrCheck (TYPE_1__*) ; 
 int /*<<< orphan*/  PyArray_GetEndianness () ; 
 scalar_t__ PyDataType_HASSUBARRAY (TYPE_1__*) ; 
 int /*<<< orphan*/  PyDict_Check (TYPE_1__*) ; 
 TYPE_1__* PyDict_GetItem (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  PyErr_SetString (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  PyExc_SystemError ; 
 scalar_t__ PyInt_Check (TYPE_1__*) ; 
 int /*<<< orphan*/  PyList_Append (TYPE_1__*,TYPE_1__*) ; 
 TYPE_1__* PyList_AsTuple (TYPE_1__*) ; 
 TYPE_1__* PyList_New (int /*<<< orphan*/ ) ; 
 int PyObject_Hash (TYPE_1__*) ; 
 scalar_t__ PyTuple_Check (TYPE_1__*) ; 
 TYPE_1__* PyTuple_GET_ITEM (TYPE_1__*,int) ; 
 int PyTuple_GET_SIZE (TYPE_1__*) ; 
 TYPE_1__* PyTuple_GetItem (TYPE_1__*,scalar_t__) ; 
 scalar_t__ PyTuple_Size (TYPE_1__*) ; 
 int /*<<< orphan*/  PyUString_Check (TYPE_1__*) ; 
 TYPE_1__* Py_BuildValue (char*,int /*<<< orphan*/ ,char,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Py_DECREF (TYPE_1__*) ; 
 int /*<<< orphan*/  Py_INCREF (TYPE_1__*) ; 
 TYPE_1__* Py_None ; 
static  int _array_descr_walk (TYPE_1__*,TYPE_1__*) ; 

__attribute__((used)) static char _normalize_byteorder(char byteorder)
{
    switch(byteorder) {
        case '=':
            if (PyArray_GetEndianness() == NPY_CPU_BIG) {
                return '>';
            }
            else {
                return '<';
            }
        default:
            return byteorder;
    }
}

__attribute__((used)) static int _is_array_descr_builtin(PyArray_Descr* descr)
{
    if (descr->fields != NULL && descr->fields != Py_None) {
        return 0;
    }
    if (PyDataType_HASSUBARRAY(descr)) {
        return 0;
    }
    return 1;
}

__attribute__((used)) static int _array_descr_builtin(PyArray_Descr* descr, PyObject *l)
{
    Py_ssize_t i;
    PyObject *t, *item;
    char nbyteorder = _normalize_byteorder(descr->byteorder);

    /*
     * For builtin type, hash relies on : kind + byteorder + flags +
     * type_num + elsize + alignment
     */
    t = Py_BuildValue("(cccii)", descr->kind, nbyteorder,
            descr->flags, descr->elsize, descr->alignment);

    for(i = 0; i < PyTuple_Size(t); ++i) {
        item = PyTuple_GetItem(t, i);
        if (item == NULL) {
            PyErr_SetString(PyExc_SystemError,
                    "(Hash) Error while computing builting hash");
            goto clean_t;
        }
        PyList_Append(l, item);
    }

    Py_DECREF(t);
    return 0;

clean_t:
    Py_DECREF(t);
    return -1;
}

__attribute__((used)) static int _array_descr_walk_fields(PyObject *names, PyObject* fields, PyObject* l)
{
    PyObject *key, *value, *foffset, *fdescr, *ftitle;
    Py_ssize_t pos = 0;
    int st;

    if (!PyTuple_Check(names)) {
        PyErr_SetString(PyExc_SystemError,
                "(Hash) names is not a tuple ???");
        return -1;
    }
    if (!PyDict_Check(fields)) {
        PyErr_SetString(PyExc_SystemError,
                "(Hash) fields is not a dict ???");
        return -1;
    }

    for (pos = 0; pos < PyTuple_GET_SIZE(names); pos++) {
        /*
         * For each field, add the key + descr + offset to l
         */
        key = PyTuple_GET_ITEM(names, pos);
        value = PyDict_GetItem(fields, key);
        /* XXX: are those checks necessary ? */
        if (value == NULL) {
            PyErr_SetString(PyExc_SystemError,
                    "(Hash) names and fields inconsistent ???");
            return -1;
        }
        if (!PyUString_Check(key)) {
            PyErr_SetString(PyExc_SystemError,
                    "(Hash) key of dtype dict not a string ???");
            return -1;
        }
        if (!PyTuple_Check(value)) {
            PyErr_SetString(PyExc_SystemError,
                    "(Hash) value of dtype dict not a dtype ???");
            return -1;
        }
        if (PyTuple_GET_SIZE(value) < 2) {
            PyErr_SetString(PyExc_SystemError,
                    "(Hash) Less than 2 items in dtype dict ???");
            return -1;
        }
        PyList_Append(l, key);

        fdescr = PyTuple_GET_ITEM(value, 0);
        if (!PyArray_DescrCheck(fdescr)) {
            PyErr_SetString(PyExc_SystemError,
                    "(Hash) First item in compound dtype tuple not a descr ???");
            return -1;
        }
        else {
            Py_INCREF(fdescr);
            st = _array_descr_walk((PyArray_Descr*)fdescr, l);
            Py_DECREF(fdescr);
            if (st) {
                return -1;
            }
        }

        foffset = PyTuple_GET_ITEM(value, 1);
        if (!PyInt_Check(foffset)) {
            PyErr_SetString(PyExc_SystemError,
                    "(Hash) Second item in compound dtype tuple not an int ???");
            return -1;
        }
        else {
            PyList_Append(l, foffset);
        }

        if (PyTuple_GET_SIZE(value) > 2) {
            ftitle = PyTuple_GET_ITEM(value, 2);
            PyList_Append(l, ftitle);
        }
    }

    return 0;
}

__attribute__((used)) static int _array_descr_walk_subarray(PyArray_ArrayDescr* adescr, PyObject *l)
{
    PyObject *item;
    Py_ssize_t i;
    int st;

    /*
     * Add shape and descr itself to the list of object to hash
     */
    if (PyTuple_Check(adescr->shape)) {
        for(i = 0; i < PyTuple_Size(adescr->shape); ++i) {
            item = PyTuple_GetItem(adescr->shape, i);
            if (item == NULL) {
                PyErr_SetString(PyExc_SystemError,
                        "(Hash) Error while getting shape item of subarray dtype ???");
                return -1;
            }
            PyList_Append(l, item);
        }
    }
    else if (PyInt_Check(adescr->shape)) {
        PyList_Append(l, adescr->shape);
    }
    else {
        PyErr_SetString(PyExc_SystemError,
                "(Hash) Shape of subarray dtype neither a tuple or int ???");
        return -1;
    }

    Py_INCREF(adescr->base);
    st = _array_descr_walk(adescr->base, l);
    Py_DECREF(adescr->base);

    return st;
}

__attribute__((used)) static int _array_descr_walk(PyArray_Descr* descr, PyObject *l)
{
    int st;

    if (_is_array_descr_builtin(descr)) {
        return _array_descr_builtin(descr, l);
    }
    else {
        if(descr->fields != NULL && descr->fields != Py_None) {
            st = _array_descr_walk_fields(descr->names, descr->fields, l);
            if (st) {
                return -1;
            }
        }
        if(PyDataType_HASSUBARRAY(descr)) {
            st = _array_descr_walk_subarray(descr->subarray, l);
            if (st) {
                return -1;
            }
        }
    }

    return 0;
}

__attribute__((used)) static int _PyArray_DescrHashImp(PyArray_Descr *descr, npy_hash_t *hash)
{
    PyObject *l, *tl;
    int st;

    l = PyList_New(0);
    if (l == NULL) {
        return -1;
    }

    st = _array_descr_walk(descr, l);
    if (st) {
        Py_DECREF(l);
        return -1;
    }

    /*
     * Convert the list to tuple and compute the tuple hash using python
     * builtin function
     */
    tl = PyList_AsTuple(l);
    Py_DECREF(l);
    if (tl == NULL)
        return -1;

    *hash = PyObject_Hash(tl);
    Py_DECREF(tl);
    if (*hash == -1) {
        /* XXX: does PyObject_Hash set an exception on failure ? */
#if 0
        PyErr_SetString(PyExc_SystemError,
                "(Hash) Error while hashing final tuple");
#endif
        return -1;
    }

    return 0;
}

