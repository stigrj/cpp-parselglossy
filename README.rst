================
cpp-parselglossy
================

.. image:: https://img.shields.io/travis/dev-cafe/cpp-parselglossy/master.svg?logo=linux&logoColor=white
        :target: https://travis-ci.org/dev-cafe/cpp-parselglossy
        :alt: Linux build status

This repo contains a simple example of how to use ``parselglossy`` in a C++
project using two different CMake setups: externalproject and fetchcontent.
The code example is identical in the two setups.

To install ``parselglossy`` through pipenv using the provided Pipfile:

.. code:: bash

    $ cd cpp-parselglossy
    $ pipenv install
    $ pipenv shell

To configure and build the ``fetchcontent`` example (identical for ``externalproject``):

.. code:: bash

    $ cd fetchcontent
    $ mkdir build
    $ cmake -H. -Bbuild
    $ cd build
    $ make

To run the test suite:

.. code:: bash

    $ cd build
    $ ctest

To run example:

.. code:: bash

    $ cd examples
    $ parselglossy parse --outfile=throw_darts.json --template=../build/share/template.yml --grammar=getkw throw_darts.inp
    $ ../build/bin/pi throw_darts.json
