#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  shape ;
struct TYPE_30__ {size_t perm; } ;
typedef  TYPE_1__ npy_stride_sort_item ;
typedef  size_t npy_intp ;
typedef  scalar_t__ npy_bool ;
struct TYPE_31__ {size_t elsize; } ;
typedef  int /*<<< orphan*/  PyObject ;
typedef  TYPE_2__ PyArray_Descr ;
typedef  TYPE_2__ PyArrayObject_fields ;
typedef  TYPE_2__ PyArrayObject ;

/* Variables and functions */
 int /*<<< orphan*/  NPY_ANYORDER ; 
 int NPY_MAXDIMS ; 
 scalar_t__ PyArray_CopyInto (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  PyArray_CreateSortedStridePerm (int,size_t*,TYPE_1__*) ; 
 int /*<<< orphan*/ * PyArray_DATA (TYPE_2__*) ; 
 TYPE_2__* PyArray_DESCR (TYPE_2__*) ; 
 size_t* PyArray_DIMS (TYPE_2__*) ; 
 TYPE_2__* PyArray_DTYPE (TYPE_2__*) ; 
 int /*<<< orphan*/  PyArray_FLAGS (TYPE_2__*) ; 
 int PyArray_NDIM (TYPE_2__*) ; 
 scalar_t__ PyArray_NewFromDescr (int /*<<< orphan*/ *,TYPE_2__*,int,size_t*,size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ PyArray_NewLikeArray (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 size_t* PyArray_STRIDES (TYPE_2__*) ; 
 scalar_t__ PyArray_SetBaseObject (TYPE_2__*,int /*<<< orphan*/ *) ; 
 scalar_t__ PyArray_SetWritebackIfCopyBase (TYPE_2__*,TYPE_2__*) ; 
 int /*<<< orphan*/  PyArray_Type ; 
 int /*<<< orphan*/  PyErr_Format (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  PyExc_ValueError ; 
 int /*<<< orphan*/  Py_DECREF (TYPE_2__*) ; 
 int /*<<< orphan*/  Py_INCREF (TYPE_2__*) ; 
 int /*<<< orphan*/ * Py_TYPE (TYPE_2__*) ; 
 int /*<<< orphan*/  memcpy (size_t*,size_t*,int) ; 

__attribute__((used)) static PyArrayObject *
allocate_reduce_result(PyArrayObject *arr, npy_bool *axis_flags,
                        PyArray_Descr *dtype, int subok)
{
    npy_intp strides[NPY_MAXDIMS], stride;
    npy_intp shape[NPY_MAXDIMS], *arr_shape = PyArray_DIMS(arr);
    npy_stride_sort_item strideperm[NPY_MAXDIMS];
    int idim, ndim = PyArray_NDIM(arr);

    if (dtype == NULL) {
        dtype = PyArray_DTYPE(arr);
        Py_INCREF(dtype);
    }

    PyArray_CreateSortedStridePerm(PyArray_NDIM(arr),
                                    PyArray_STRIDES(arr), strideperm);

    /* Build the new strides and shape */
    stride = dtype->elsize;
    memcpy(shape, arr_shape, ndim * sizeof(shape[0]));
    for (idim = ndim-1; idim >= 0; --idim) {
        npy_intp i_perm = strideperm[idim].perm;
        if (axis_flags[i_perm]) {
            strides[i_perm] = 0;
            shape[i_perm] = 1;
        }
        else {
            strides[i_perm] = stride;
            stride *= shape[i_perm];
        }
    }

    /* Finally, allocate the array */
    return (PyArrayObject *)PyArray_NewFromDescr(
                                    subok ? Py_TYPE(arr) : &PyArray_Type,
                                    dtype, ndim, shape, strides,
                                    NULL, 0, subok ? (PyObject *)arr : NULL);
}

__attribute__((used)) static PyArrayObject *
conform_reduce_result(int ndim, npy_bool *axis_flags,
                      PyArrayObject *out, int keepdims, const char *funcname,
                      int need_copy)
{
    npy_intp strides[NPY_MAXDIMS], shape[NPY_MAXDIMS];
    npy_intp *strides_out = PyArray_STRIDES(out);
    npy_intp *shape_out = PyArray_DIMS(out);
    int idim, idim_out, ndim_out = PyArray_NDIM(out);
    PyArray_Descr *dtype;
    PyArrayObject_fields *ret;

    /*
     * If the 'keepdims' parameter is true, do a simpler validation and
     * return a new reference to 'out'.
     */
    if (keepdims) {
        if (PyArray_NDIM(out) != ndim) {
            PyErr_Format(PyExc_ValueError,
                    "output parameter for reduction operation %s "
                    "has the wrong number of dimensions (must match "
                    "the operand's when keepdims=True)", funcname);
            return NULL;
        }

        for (idim = 0; idim < ndim; ++idim) {
            if (axis_flags[idim]) {
                if (shape_out[idim] != 1) {
                    PyErr_Format(PyExc_ValueError,
                            "output parameter for reduction operation %s "
                            "has a reduction dimension not equal to one "
                            "(required when keepdims=True)", funcname);
                    return NULL;
                }
            }
        }

        Py_INCREF(out);
        return out;
    }

    /* Construct the strides and shape */
    idim_out = 0;
    for (idim = 0; idim < ndim; ++idim) {
        if (axis_flags[idim]) {
            strides[idim] = 0;
            shape[idim] = 1;
        }
        else {
            if (idim_out >= ndim_out) {
                PyErr_Format(PyExc_ValueError,
                        "output parameter for reduction operation %s "
                        "does not have enough dimensions", funcname);
                return NULL;
            }
            strides[idim] = strides_out[idim_out];
            shape[idim] = shape_out[idim_out];
            ++idim_out;
        }
    }

    if (idim_out != ndim_out) {
        PyErr_Format(PyExc_ValueError,
                "output parameter for reduction operation %s "
                "has too many dimensions", funcname);
        return NULL;
    }

    /* Allocate the view */
    dtype = PyArray_DESCR(out);
    Py_INCREF(dtype);

    /* TODO: use PyArray_NewFromDescrAndBase here once multiarray and umath
     *       are merged
     */
    ret = (PyArrayObject_fields *)PyArray_NewFromDescr(
            &PyArray_Type, dtype,
            ndim, shape, strides, PyArray_DATA(out),
            PyArray_FLAGS(out), NULL);
    if (ret == NULL) {
        return NULL;
    }

    Py_INCREF(out);
    if (PyArray_SetBaseObject((PyArrayObject *)ret, (PyObject *)out) < 0) {
        Py_DECREF(ret);
        return NULL;
    }

    if (need_copy) {
        PyArrayObject *ret_copy;

        ret_copy = (PyArrayObject *)PyArray_NewLikeArray(
            (PyArrayObject *)ret, NPY_ANYORDER, NULL, 0);
        if (ret_copy == NULL) {
            Py_DECREF(ret);
            return NULL;
        }

        if (PyArray_CopyInto(ret_copy, (PyArrayObject *)ret) != 0) {
            Py_DECREF(ret);
            Py_DECREF(ret_copy);
            return NULL;
        }

        if (PyArray_SetWritebackIfCopyBase(ret_copy, (PyArrayObject *)ret) < 0) {
            Py_DECREF(ret);
            Py_DECREF(ret_copy);
            return NULL;
        }

        return ret_copy;
    }
    else {
        return (PyArrayObject *)ret;
    }
}

__attribute__((used)) static int
count_axes(int ndim, npy_bool *axis_flags)
{
    int idim;
    int naxes = 0;

    for (idim = 0; idim < ndim; ++idim) {
        if (axis_flags[idim]) {
            naxes++;
        }
    }
    return naxes;
}

