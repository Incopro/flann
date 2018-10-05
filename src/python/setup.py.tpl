#!/usr/bin/env python2

from setuptools import setup

setup(
    name='incoproflann',
    version='1.0',
    description='Fast Library for Approximate Nearest Neighbors',
    author='Marius Muja',
    author_email='mariusm@cs.ubc.ca',
    license='BSD',
    url='http://www.cs.ubc.ca/~mariusm/flann/',
    packages=['pyflann'],
    package_data={'pyflann': ['libflann.so']},
)
