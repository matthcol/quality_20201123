include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        include/Form.h \
        include/Point.h \
        include/Polygon.h \
        include/WeightedPoint.h \
        test_include/tst_distance.h \

SOURCES += \
        src/Form.cpp \
        src/Point.cpp \
        src/Polygon.cpp \
        src/WeightedPoint.cpp \
        test_src/main.cpp
