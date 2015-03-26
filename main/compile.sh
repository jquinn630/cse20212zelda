#!/bin/sh
setenv QTDIR /usr/lib64/qt-3.3
qmake-qt4 -project
qmake-qt4
make
