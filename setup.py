from setuptools import setup, Extension
from Cython.Build import cythonize

setup(
    ext_modules = cythonize([
        Extension("example_threads", ["example_threads.pyx", "example_threads.cpp"],
                    language="c++",
                    )
    ])
)