#include <Python.h>


char * getNewName();


// 1. The actual C function
static PyObject* my_function(PyObject* self, PyObject* args) {
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name)) return NULL;
	
	
    printf("Hello %s from %s C!\n", name,getNewName());
    Py_RETURN_NONE;
}

// 2. Method definition table
static PyMethodDef MyMethods[] = {
    {"hello", my_function, METH_VARARGS, "Greet someone from C"},
    {NULL, NULL, 0, NULL}
};

// 3. Module definition
static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT, "mymodule", NULL, -1, MyMethods
};

// 4. Initialization function (must be named PyInit_<modulename>)
PyMODINIT_FUNC PyInit_mymodule(void) {
    return PyModule_Create(&mymodule);
}
