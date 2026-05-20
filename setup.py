from setuptools import setup, Extension

module = Extension(
    "mymodule", 
    sources=["example.c", "support.c"],
    
)

setup(
    name="mymodule",
    version="1.0",
    description="A simple C extension module",
    ext_modules=[module],
)

