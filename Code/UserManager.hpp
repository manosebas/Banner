#ifndef UserManager_hpp
#define UserManager_hpp
#include "User.hpp"
#include "FacultyManager.hpp"
#include "StudentManager.hpp"
#include "ArrayList.hpp"
#include <string>
class StudentManager;
class FacultyManager;

class UserManager{
private:
    ArrayList<User*> usuarios;
    StudentManager *ObstudentManager;
    FacultyManager *ObfacultyManager;
public:
    UserManager();
    UserManager(FacultyManager*, StudentManager*);
    User *ObvalidateCredentials(std::string, std::string);
    void editUser(User*);
    void showUser();
    std::string getNewBannerID();
    void addNewUser(User*);
    ArrayList <User*> getAllUsers();
    void deletUser(User*);
};

#endif
