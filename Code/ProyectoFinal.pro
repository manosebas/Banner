TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Course.cpp \
        CourseManager.cpp \
        Faculty.cpp \
        FacultyManager.cpp \
        Grade.cpp \
        GraduateStudent.cpp \
        Proxy.cpp \
        Student.cpp \
        StudentManager.cpp \
        UnderGraduateStudent.cpp \
        User.cpp \
        UserManager.cpp \
        main.cpp

HEADERS += \
    ArrayList.hpp \
    Course.hpp \
    CourseManager.hpp \
    Faculty.hpp \
    FacultyManager.hpp \
    Grade.hpp \
    GraduateStudent.hpp \
    Proxy.hpp \
    RunTimeExceptions.h \
    Student.hpp \
    StudentManager.hpp \
    UnderGraduateStudent.hpp \
    User.hpp \
    UserManager.hpp
