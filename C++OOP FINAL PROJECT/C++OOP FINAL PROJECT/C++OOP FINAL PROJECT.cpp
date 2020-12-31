// COMPUTER ACADAMY STEP
// FT_SD_M8
// FINAL PROJECT 
// STUDENT MANAGEMENT
// C++ OOP
// NASAK NY

#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

class Student
{
private:
    int id;
    string name;
    string password;
    string sex;
    string adress;
    string phone;

    /* bool is_valid_email(const string& email)
    {

        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(email, pattern);

    }*/

    bool is_valid_number(const string& number)
    {
        for (const char c : number)
        {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    bool is_valid_name(const string& name)
    {
        for (const char c : name)
        {
            if (!isalpha(c) && !isspace(c))
                return false;
        }

        return true;
    }

    bool is_valid_password(string& password)
    {
        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;

        for (const char c : password) {
            if (islower(c)) {
                hasLower = true;
            }
            if (isupper(c)) {
                hasUpper = true;
            }
            if (isdigit(c)) {
                hasDigit = true;
            }
        }

        if (hasUpper && hasDigit && hasLower && (password.length() >= 6)) {
            cout << "Your password is Strong and succeeded" << endl;
        }
        else if ((hasLower || hasUpper) && hasDigit && (password.length() >= 6)) {
            cout << "Your password is Good and succeeded" << endl;
        }
        else {
            cout << "Your password is too Weak" << endl;
            return false;
        }
        return true;
    }

public:
    Student()
    {
        id = 0;
        name = "";
        password = "";
        sex = "";
        adress = "";
        phone = "";
    }
    Student(int id, string name, string password, string sex, string adress, string phone)
    {
        this->id = id;
        this->name = name;
        this->password = password;
        this->sex = sex;
        this->adress = adress;
        this->phone = phone;
    }
    // IT
    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id = id;
    }
    // PASSWORD
    string getPassword()
    {
        return password;
    }
    void setPassword(string password)
    {
        while (!is_valid_password(password)) {
            cout << "Please enter your password again : ";
            getline(cin, password);
            //cin.ignore();
        }
        this->password = password;
    }
    // SEX
    string getSex()
    {
        return sex;
    }
    void setSex(string sex)
    {
        while (!is_valid_name(sex))
        {
            cout << "Please enter your sex again : ";
            getline(cin, sex);
            //cin.ignore();
        }
        this->sex = sex;
    }
    // NAME
    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        while (!is_valid_name(name))
        {
            cout << "Please enter your name again : ";
            getline(cin, name);
            cin.ignore();
        }
        this->name = name;
    }
    // ADRESS
    string getAdress()
    {
        return adress;
    }
    void setAdress(string adress)
    {
        while (!is_valid_name(adress))
        {
            cout << "Please enter your adress again : ";
            getline(cin, adress);
            //cin.ignore();
        }
        this->adress = adress;
    }
    // Phone
    string getPhone()
    {
        return phone;
    }
    void setPhone(string role)
    {
        while (!is_valid_number(phone))
        {
            cout << "Please enter your Phonenumber number again : ";
            getline(cin, phone);
            //cin.ignore();
        }
        this->phone = phone;
    }

    void CreateStudent()
    {

        //cout << "\nENTER IT : ";
        //cin >> id;

        while (true)
        {
            cout << "ENTER ID : ";
            cin >> id;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (id <= 0) {
                continue;
            }

            break;
        }

        cout << "ENTER NAME : ";
        cin.ignore();
        getline(cin, name);
        setName(name);

        cout << "ENTER PASSWORD : ";
        //cin.ignore();
        getline(cin, password);
        setPassword(password);

        cout << "ENTER SEX (MALE / FEMALE) : ";
        //cin.ignore();
        getline(cin, sex);
        setSex(sex);

        cout << "ENTER ADRESS (CITY / PROVINCE) : ";
        //cin.ignore();
        getline(cin, adress);
        setAdress(adress);

        cout << "ENTER PHONE NUMBER : ";
        //cin.ignore();
        getline(cin, phone);
        setPhone(phone);

        cout << endl;
    }

    void DisplayStudent() {
        cout << "ID = " << id << endl;
        cout << "Username = " << name << endl;
        cout << "Password = " << password << endl;
        cout << "Sex = " << sex << endl;
        cout << "Adress = " << adress << endl;
        cout << "Phone = " << phone << endl;
        cout << endl;
    }
};

class StudentManager
{
private:
public:
    void SaveStudent();
    void DisplayAllStudents();
    void Display1Student(int id);
    void UpdateStudent(int id);
    void DeleteStudent(int id);
};

void StudentManager::SaveStudent()
{
    fstream fp;
    fp.open("student.txt", ios::out | ios::app);
    Student* student = new Student();
    student->CreateStudent();
    fp.write((char*)student, sizeof(*student));
    fp.close();
    cout << "STUDENT SAVED" << endl;
    cout << "\n__________________\n\n";
}

void StudentManager::DisplayAllStudents()
{
    cout << "---DISPLAY ALL STUDENT--- \n\n";
    Student* student = new Student();
    fstream fp;
    fp.open("student.txt", ios::in);
    while (fp.read((char*)student, sizeof(Student)))
    {
        student->DisplayStudent();
    }
    fp.close();
    cout << "\nAll student displayed" << endl;
    cout << "\n__________________\n";
}


void StudentManager::Display1Student(int id)
{
    fstream fp;
    Student* student = new Student();
    bool found = false;
    fp.open("student.txt", ios::in);
    while (fp.read((char*)student, sizeof(Student)))
    {
        if (student->getId() == id)
        {
            student->DisplayStudent();
            found = true;
            break;
        }
    }
    fp.close();

    if (found == false)
        cout << "ID not found\n";
    else
    {
        cout << "ID found\n";
        cout << "-------------------------------\n";
    }
}

void StudentManager::UpdateStudent(int id)
{
    fstream fp;
    Student* student = new Student();
    bool found = false;
    fp.open("student.txt", ios::in | ios::out);
    while (fp.read((char*)student, sizeof(*student)))
    {
        if (student->getId() == id)
        {
            student->DisplayStudent();
            cout << "---UPDATE STUDENT---: \n";
            student->CreateStudent();
            int pos = -1 * static_cast<int>(sizeof(*student));
            fp.seekp(pos, ios::cur);
            fp.write((char*)student, sizeof(*student));
            found = true;
            break;
        }
    }
    fp.close();
    if (found == false)
        cout << "ID not found\n";
    else
    {
        cout << "STUDENT UPDATED\n";
        cout << "\n__________________\n\n";
    }
}
void StudentManager::DeleteStudent(int id)
{
    fstream fp;
    Student* student = new Student();
    fp.open("student.txt", ios::in);
    fstream fp2;
    fp2.open("temp.txt", ios::out | ios::app);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)student, sizeof(*student)))
    {
        if (student->getId() != id)
        {
            fp2.write((char*)student, sizeof(*student));
            break;
        }
    }
    cout << "STUDENT DELETED\n";
    cout << "\n__________________\n\n";
    fp2.close();
    fp.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
}

void menu()
{
    StudentManager studentmanager;

    int selectedTransaction = 0;
    int exitProgramOption = 6;

    while (selectedTransaction != exitProgramOption)
    {
        cout << "\n---MENU---\n";
        cout << "1. ADD STUDENT\n";
        cout << "2. DISPLAY A STUDENT BY ID\n";
        cout << "3. DELETE STUDENT\n";
        cout << "4. DISPLAY ALL STUDENTS\n";
        cout << "5. UPDATE STUDENT\n";
        cout << "6. EXIT\n";

        cout << "ENTER 1-6 : "; cin >> selectedTransaction;
        cout << endl;

        switch (selectedTransaction)
        {
        case 1:
            studentmanager.SaveStudent();
            break;
        case 2:
            int a;
            cout << "ENTER ID TO DISPLAY : ";
            cin >> a;
            studentmanager.Display1Student(a);
            break;
        case 3:
            int d;
            cout << "ENTER ID TO DELETE : "; cin >> d;
            studentmanager.DeleteStudent(d);
            break;
        case 4:
            studentmanager.DisplayAllStudents();
            break;
        case 5:
            int u;
            cout << "ENTER ID TO UPDATE : "; cin >> u;
            studentmanager.UpdateStudent(u);
            break;
        case 6:
            cout << "THANK YOU";
        }
        cout << endl;
    }
}

int main()
{
    cout << "\n------WELCOME TO STUDENT MANAGEMENT SYSTEM------\n";
    StudentManager studentmanager;
    menu();

    return 0;
}
