#ifndef FacultyManager_hpp
#define FacultyManager_hpp

class UserManager;

#include "ArrayList.hpp"
#include "Faculty.hpp"
#include "UserManager.hpp"
#include <string>

class FacultyManager{
private:
    ArrayList <Faculty*> profesores;
    UserManager *userManager;
    const char *pathFaculty;
    void loadFaculty(int);
    void updateFaculty();
    int profesoresTotal;

public:
    //FacultyManager();
    FacultyManager(const char* pathFaculty, int profesoresTotal);
    void createNewFaculty(UserManager*);
    Faculty *getFacultyByID(std::string);
    ArrayList <Faculty*> getAllFaculty();
    void editFaculty(Faculty*);
    void showFaculty();
    void deleteFaculty(Faculty*);
};
#endif
