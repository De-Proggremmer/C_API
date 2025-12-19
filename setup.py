from setuptools import setup, Extension

setup(
    name='standDev',               # Имя пакета
    version='1.0',                 # Версия пакета
    ext_modules=[Extension('standDev', ['Source.cpp'])]  # Указание расширения на C/C++, которое будет собрано из файла Source.cpp
)