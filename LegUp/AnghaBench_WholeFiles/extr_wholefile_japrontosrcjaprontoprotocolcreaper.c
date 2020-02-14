#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_12__ {int /*<<< orphan*/  (* tp_free ) (int /*<<< orphan*/ *) ;} ;
struct TYPE_11__ {scalar_t__ (* tp_alloc ) (TYPE_2__*,int /*<<< orphan*/ ) ;} ;
struct TYPE_10__ {int /*<<< orphan*/ * connections; int /*<<< orphan*/ * call_later; int /*<<< orphan*/  idle_timeout; int /*<<< orphan*/ * check_interval; int /*<<< orphan*/ * check_idle; int /*<<< orphan*/ * check_idle_handle; } ;
typedef  TYPE_1__ Reaper ;
typedef  TYPE_2__ PyTypeObject ;
typedef  int /*<<< orphan*/  PyObject ;
typedef  int /*<<< orphan*/ * PyMODINIT_FUNC ;

/* Variables and functions */
 int /*<<< orphan*/  DEFAULT_CHECK_INTERVAL ; 
 int /*<<< orphan*/  DEFAULT_IDLE_TIMEOUT ; 
 int /*<<< orphan*/  PyArg_ParseTupleAndKeywords (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,char**,int /*<<< orphan*/ **,int /*<<< orphan*/ **,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  PyLong_AsLong (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * PyLong_FromLong (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PyModule_AddObject (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * PyModule_Create (int /*<<< orphan*/ *) ; 
 void* PyObject_GetAttrString (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ PyType_Ready (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Py_INCREF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Py_RETURN_NONE ; 
 TYPE_8__* Py_TYPE (TYPE_1__*) ; 
 int /*<<< orphan*/  Py_XDECREF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ReaperType ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  creaper ; 
 int /*<<< orphan*/  debug_print (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * default_check_interval ; 
 int /*<<< orphan*/  import_capi (char*) ; 
 int /*<<< orphan*/  protocol_capi ; 
 scalar_t__ stub1 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static PyObject*
Reaper_new(PyTypeObject* type, PyObject* args, PyObject* kwds)
{
  Reaper* self = NULL;

  self = (Reaper*)type->tp_alloc(type, 0);
  if(!self)
    goto finally;

  self->connections = NULL;
  self->call_later = NULL;
  self->check_idle = NULL;
  self->check_idle_handle = NULL;
  self->check_interval = NULL;

  finally:
  return (PyObject*)self;
}

__attribute__((used)) static void
Reaper_dealloc(Reaper* self)
{
  Py_XDECREF(self->check_interval);
  Py_XDECREF(self->check_idle_handle);
  Py_XDECREF(self->check_idle);
  Py_XDECREF(self->call_later);
  Py_XDECREF(self->connections);

  Py_TYPE(self)->tp_free((PyObject*)self);
}

__attribute__((used)) static PyObject*
Reaper_stop(Reaper* self)
{
#ifdef REAPER_ENABLED
  void* result = Py_None;
  PyObject* cancel = NULL;

  if(!(cancel = PyObject_GetAttrString(self->check_idle_handle, "cancel")))
    goto error;

  PyObject* tmp;
  if(!(tmp = PyObject_CallFunctionObjArgs(cancel, NULL)))
    goto error;
  Py_DECREF(tmp);

  goto finally;

  error:
  result = NULL;

  finally:
  Py_XINCREF(result);
  Py_XDECREF(cancel);
  return result;
#else
  Py_RETURN_NONE;
#endif
}

__attribute__((used)) static int
Reaper_init(Reaper* self, PyObject* args, PyObject* kwds)
{
  PyObject* loop = NULL;
  int result = 0;

  PyObject* app = NULL;
  PyObject* idle_timeout = NULL;

  static char* kwlist[] = {"app", "check_interval", "idle_timeout", NULL};

  if (!PyArg_ParseTupleAndKeywords(
      args, kwds, "|OOO", kwlist, &app, &self->check_interval, &idle_timeout))
      goto error;

  assert(app);

  if(!self->check_interval)
    self->check_interval = default_check_interval;
  Py_INCREF(self->check_interval);

  assert(PyLong_AsLong(self->check_interval) >= 0);

  if(!idle_timeout)
    self->idle_timeout = DEFAULT_IDLE_TIMEOUT;
  else
    self->idle_timeout = PyLong_AsLong(idle_timeout);

  assert(self->idle_timeout >= 0);

  debug_print("check_interval %ld", PyLong_AsLong(self->check_interval));
  debug_print("idle_timeout %ld", self->idle_timeout);

  if(!(loop = PyObject_GetAttrString(app, "_loop")))
    goto error;

  if(!(self->call_later = PyObject_GetAttrString(loop, "call_later")))
    goto error;

  if(!(self->connections = PyObject_GetAttrString(app, "_connections")))
    goto error;

#ifdef REAPER_ENABLED
  if(!(self->check_idle = PyObject_GetAttrString((PyObject*)self, "_check_idle")))
    goto error;

  if(!Reaper_schedule_check_idle(self))
    goto error;
#endif

  goto finally;

  error:
  result = -1;

  finally:
  Py_XDECREF(loop);
  return result;
}

PyMODINIT_FUNC
PyInit_creaper(void)
{
  PyObject* m = NULL;
  default_check_interval = NULL;

  if (PyType_Ready(&ReaperType) < 0)
    goto error;

  m = PyModule_Create(&creaper);
  if(!m)
    goto error;

  Py_INCREF(&ReaperType);
  PyModule_AddObject(m, "Reaper", (PyObject*)&ReaperType);

  if(!(default_check_interval = PyLong_FromLong(DEFAULT_CHECK_INTERVAL)))
    goto error;

  protocol_capi = import_capi("japronto.protocol.cprotocol");
  if(!protocol_capi)
    goto error;

  goto finally;

  error:
  Py_XDECREF(default_check_interval);
  m = NULL;

  finally:
  return m;
}

