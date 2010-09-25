#include <Python.h>
#include <stdio.h>
#include "AquesTalk2.h"

extern int synthe(const char*, int);
void init_aquestalk2(void);

PyObject* aquestalk2_synthe(PyObject* self, PyObject* args)
{
  char* koe;
  int speed=100;
  int size;
  unsigned char* wav;
  char buffer[50];
  PyObject* ret;
  if (!PyArg_ParseTuple(args, "s", &koe))
      return NULL;
  wav = AquesTalk2_Synthe_Utf8(koe, speed, &size, NULL);
  if (wav == NULL) {
    sprintf(buffer, "Aquestalk2Error %d", size);
    PyErr_SetString(PyExc_ValueError, buffer);
    return NULL;
  }
  ret = Py_BuildValue("s#", wav, size);
  AquesTalk2_FreeWave(wav);
  return ret;
}

static PyMethodDef aquestalk2_methods[] = {
  {"synthe", aquestalk2_synthe, METH_VARARGS},
  {NULL},
};

void init_aquestalk2()
{
  Py_InitModule("_aquestalk2", aquestalk2_methods);
}
