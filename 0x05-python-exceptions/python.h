#include <stdio.h>
#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

int main() {
    // Initialize Python
    Py_Initialize();

    // Create and manipulate Python objects
    PyObject *byte_str = PyBytes_FromString("Hello");
    PyObject *byte_str2 = PyBytes_FromStringAndSize("\xFF\xF8\x00\x00\x00\x00\x00\x00", 8);
    PyObject *byte_str3 = PyBytes_FromString("What does the 'b' character do in front of a string literal?");
    PyObject *int_obj = PyLong_FromLong(42);
    PyObject *float_obj = PyFloat_FromDouble(3.14);

    // Call the functions to print information about Python objects
    print_python_bytes(byte_str);
    print_python_bytes(byte_str2);
    print_python_bytes(byte_str3);
    print_python_list(PyList_Pack(2, byte_str, byte_str2));
    print_python_float(float_obj);

    // Cleanup Python
    Py_XDECREF(byte_str);
    Py_XDECREF(byte_str2);
    Py_XDECREF(byte_str3);
    Py_XDECREF(int_obj);
    Py_XDECREF(float_obj);

    Py_Finalize();

    return 0;
}
