#!/usr/bin/env python2
import os
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext as build_ext_orig
from distutils.file_util import copy_file


class CMakeExtension(Extension):

    def __init__(self, name):
        Extension.__init__(
            self,
            name,
            sources=[],
        )


class build_ext(build_ext_orig):

    def run(self):
        for ext in self.extensions:
            self.build_cmake(ext)

    def build_cmake(self, ext):
        self.spawn(['cmake', '.'])
        self.spawn(['make', 'flann'])

        dest = os.path.join(self.build_lib, "pyflann", "libflann.so")
        copy_file("lib/libflann.so.1.9.1", dest)


setup(
    name='incoproflann',
    version='1.1',
    description='Fast Library for Approximate Nearest Neighbors',
    author='Marius Muja',
    author_email='mariusm@cs.ubc.ca',
    license='BSD',
    url='http://www.cs.ubc.ca/~mariusm/flann/',
    packages=['pyflann'],
    ext_modules=[CMakeExtension('pyflann/libflann')],
    package_dir={'pyflann': 'src/python/pyflann'},
    cmdclass={
        'build_ext': build_ext,
    }
)
