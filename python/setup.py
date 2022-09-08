#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
from setuptools import Extension, setup, find_packages

try:
    import pybind11
    pybind11_include_path = pybind11.get_include()
except ImportError:
    pybind11_include_path = ""


include_dirs = [
    "../",
]
if pybind11_include_path:
    include_dirs.append(pybind11_include_path)

libraries = [
    "png",
]

library_dirs = []

sources = []
for dirname, dirs, filenames in os.walk("./src/"):
    for filename in sorted(filenames):
        if not filename.endswith(".cpp"):
            continue
        sources.append(os.path.join(dirname, filename))

extras = [
    "-std=c++17",
]

ext = Extension(
    name="glslike.__glslike",
    include_dirs=include_dirs,
    libraries=libraries,
    library_dirs=library_dirs,
    sources=sources,
    extra_compile_args=extras,
)


install_requires = []
requirements_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "requirements.txt")
if os.path.exists(requirements_path):
    with open(requirements_path) as fp:
        install_requires = fp.read().splitlines()


setup(name="glslike",
    version="1.0.0",
    description="glsl shader like interface",
    url="https://github.com/mugwort-rc/glslike",
    license="Apache2.0",
    classifiers=[
        "Intended Audience :: Developers",
        "License :: OSI Approved :: Apache Software License",
        "Programming Language :: Python",
        "Programming Language :: C++",
        "Development Status :: 4 - Beta",
        "Topic :: Multimedia :: Graphics :: 3D Rendering",
    ],
    keywords=["glsl", "shader", "vector", "matrix"],
    author="mugwort_rc",
    author_email="mugwort [dot] rc [at] gmail [dot] com",
    zip_safe=False,
    packages=find_packages(),
    ext_modules=[ext],
    install_requires=install_requires,
)
