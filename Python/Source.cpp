#include <Python.h>
#include <chrono>
#include <cmath>

static PyObject* standDev_calculate(PyObject* self, PyObject* args)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    PyObject* listObj;

    if (!PyArg_ParseTuple(args, "O", &listObj))
        return NULL;

    long length = PyList_Size(listObj);

    int i, sum = 0;
    for (i = 0; i < length; i++) {
        // Получаем элемент из списка - он также Python-объект
        PyObject* temp = PyList_GetItem(listObj, i);
        // Мы знаем, что элемент это целое число - приводим его к типу C long
        long elem = PyLong_AsLong(temp);  // Используем PyLong_AsLong вместо PyInt_AsLong
        sum += elem;
    }

    double aver = sum / length;

    sum = 0;
    for (i = 0; i < length; i++) {
        // Получаем элемент из списка - он также Python-объект
        PyObject* temp = PyList_GetItem(listObj, i);
        // Мы знаем, что элемент это целое число - приводим его к типу C long
        long elem = PyLong_AsLong(temp);  // Используем PyLong_AsLong вместо PyInt_AsLong
        sum += (aver - elem)*(aver - elem);
    }

    double stand_dev = std::sqrt(sum / length);

    auto end_time = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration<double>(end_time - start_time).count();

    PyObject* tuple = PyTuple_New(2);
    PyTuple_SetItem(tuple, 0, PyFloat_FromDouble(stand_dev));
    PyTuple_SetItem(tuple, 1, PyFloat_FromDouble(time_taken));

    return tuple;
}

static char standDev_docs[] =
"calculate(): calculates standart diviation of the list\n";

static PyMethodDef standDev_funcs[] = {
    {"calculate", standDev_calculate, METH_VARARGS, standDev_docs},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef standDev_module = {
    PyModuleDef_HEAD_INIT,
    "standDev",      // ��� ������
    "Standart diviation of the list",  // ������������
    -1,
    standDev_funcs
};

PyMODINIT_FUNC PyInit_standDev(void) {   // <-- ��� ������ PyInit_<module>
    return PyModule_Create(&standDev_module);
}

int main()
{
    return 0;
}