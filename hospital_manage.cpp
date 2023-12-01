// C++ program to implement the Hospital 
// Management System 
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

// Store the data of Hospital 
class Hospital {
public:
    string H_name;
    string location;
    int available_beds;
    float rating;
    string contact;
    string doctor_name;
    int price;
};
class Doctor {
public:
    int doctor_id;
    string doctor_name;
    float rating;
    int rating_number = 0;
    Hospital* hospital;
};
// Stores the data of Patient 
class Patient : public Hospital {
public:
    string P_name;
    int P_id;
    Doctor* doctor;
};
class User
{
public:
    int type;
    int id;
    string username;
    string password;
    Doctor* doctor;
    Patient* patient;
};
vector<Hospital> hospitals;
vector<Doctor> doctors;
vector<Patient> patients;
vector<User> users;
// Hospital Data 
void PrintHospitalData(vector<Hospital>& hospitals)
{

    cout << "PRINT hospitals DATA:"
        << endl;

    cout << "HospitalName     "
        << "Location     "
        << "Beds_Available     "
        << "Rating     "
        << "Hospital_Contact     "
        << "Doctor_Name     "
        << "Price_Per_Bed     \n";

    for (int i = 0; i < hospitals.size(); i++) {
        cout << hospitals[i].H_name
            << "               "
            << hospitals[i].location
            << "           "
            << hospitals[i].available_beds
            << "            "
            << hospitals[i].rating
            << "            "
            << hospitals[i].contact
            << "             "
            << hospitals[i].doctor_name
            << "             "
            << hospitals[i].price
            << "            "
            << endl;
    }

    cout << endl
        << endl;
}
void PrintDoctorData(vector<Doctor>& doctors)
{

    cout << "PRINT doctors DATA:"
        << endl;

    cout << "Doctor_id     "
        << "Doctor_Name     "
        << "Rating  "
        << "Hospital_Name   \n";

    for (int i = 0; i < doctors.size(); i++) {
        cout << doctors[i].doctor_id
            << "               "
            << doctors[i].doctor_name
            << "           "
            << doctors[i].rating
            << "            "
            << doctors[i].hospital->H_name
            << "            "
            << endl;
    }

    cout << endl
        << endl;
}
// Function to print the patient 
// data in the hospital 
void PrintPatientData(
    vector<Patient>& patients,
    vector<Hospital>& hospitals)
{
    cout << "PRINT patients DATA:"
        << endl;
    cout << "Patient_Name     "
        << "Patient_Id     "
        << "Patient_Contact     "
        << "Alloted_Hospital     "
        << "Patient_Expenditure     \n";

    for (int i = 0; i < patients.size(); i++) {
        cout << patients[i].P_name
            << "                "
            << patients[i].P_id
            << "              "
            << patients[i].contact
            << "              "
            << hospitals[i].H_name
            << "              "
            << patients[i].price
            << "            "
            << endl;
    }

    cout << endl
        << endl;
}

// Comparator function to sort the 
// hospital data by name 
bool name(Hospital& A, Hospital& B)
{
    return A.H_name > B.H_name;
}

// Function to sort the hospital 
// data by name 
void SortHospitalByName(
    vector<Hospital> hospitals)
{
    // Sort the date 
    sort(hospitals.begin(),
        hospitals.end(),
        name);

    cout << "SORT BY NAME:"
        << endl
        << endl;
    PrintHospitalData(hospitals);
}

bool location(Hospital& A, Hospital& B)
{
    return A.location < B.location;
}

void SortHospitalByLocation(vector<Hospital> hospitals)
{
    sort(hospitals.begin(),
        hospitals.end(),
        location);

    cout << "SORT BY LOCATION:"
        << endl
        << endl;
    PrintHospitalData(hospitals);
}
// Comparator function to sort the 
// hospital data by rating 
bool rating(Hospital& A, Hospital& B)
{
    return A.rating > B.rating;
}

// Function to sort the hospital 
// data by namerating 
void SortHospitalByRating(vector<Hospital> hospitals)
{
    sort(hospitals.begin(),
        hospitals.end(),
        rating);

    cout << "SORT BY Rating:"
        << endl
        << endl;

    PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by Bed Available 
bool beds(Hospital& A, Hospital& B)
{
    return A.available_beds > B.available_beds;
}

// Function to sort the hospital 
// data by Bed Available 
void SortByBedsAvailable(
    vector<Hospital> hospitals)
{
    sort(hospitals.begin(),
        hospitals.end(),
        beds);

    cout << "SORT BY Available Beds:"
        << endl
        << endl;

    PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by Bed Price 
bool beds_price(Hospital& A, Hospital& B)
{
    return A.price < B.price;
}

// Function to sort the hospital 
// data by Bed Price 
void SortByBedsPrice(
    vector<Hospital> hospitals)
{
    sort(hospitals.begin(),
        hospitals.end(),
        beds_price);

    cout << "SORT BY Available Beds Price:"
        << endl
        << endl;

    PrintHospitalData(hospitals);
}

// Comparator function to sort the 
// hospital data by City 
void PrintHospitalBycity(
    string city, vector<Hospital> hospitals)
{
    cout << "PRINT hospitals by City :"
        << city << endl;

    cout << "HospitalName     "
        << "Location     "
        << "Beds_Available     "
        << "Rating     "
        << "Hospital_Contact     "
        << "Doctor_Name     "
        << "Price_Per_Bed     \n";

    for (int i = 0; i < hospitals.size(); i++) {

        if (hospitals[i].location != city)
            continue;
        cout << hospitals[i].H_name
            << "                "
            << hospitals[i].location
            << "           "
            << hospitals[i].available_beds
            << "             "
            << hospitals[i].rating
            << "            "
            << hospitals[i].contact
            << "            "
            << hospitals[i].doctor_name
            << "            "
            << hospitals[i].price
            << "            "
            << endl;
    }
    cout << endl
        << endl;
}

void PrintHospitalByName(string name, vector<Hospital> hospitals)
{
    cout << "PRINT hospitals by Name :"
        << name << endl;

    cout << "HospitalName     "
        << "Location     "
        << "Beds_Available     "
        << "Rating     "
        << "Hospital_Contact     "
        << "Doctor_Name     "
        << "Price_Per_Bed     \n";
    for (int i = 0; i < hospitals.size(); i++) {

        if (hospitals[i].H_name != name)
            continue;
        cout << hospitals[i].H_name
            << "                "
            << hospitals[i].location
            << "           "
            << hospitals[i].available_beds
            << "             "
            << hospitals[i].rating
            << "            "
            << hospitals[i].contact
            << "            "
            << hospitals[i].doctor_name
            << "            "
            << hospitals[i].price
            << "            "
            << endl;
    }
    cout << endl
        << endl;
}

void PrintHospitalByDoctorName(string doctorname, vector<Hospital> hospitals)
{
    cout << "PRINT hospitals by DoctorName :"
        << doctorname << endl;

    cout << "HospitalName     "
        << "Location     "
        << "Beds_Available     "
        << "Rating     "
        << "Hospital_Contact     "
        << "Doctor_Name     "
        << "Price_Per_Bed     \n";
    for (int i = 0; i < hospitals.size(); i++) {

        if (hospitals[i].doctor_name != doctorname)
            continue;
        cout << hospitals[i].H_name
            << "                "
            << hospitals[i].location
            << "           "
            << hospitals[i].available_beds
            << "             "
            << hospitals[i].rating
            << "            "
            << hospitals[i].contact
            << "            "
            << hospitals[i].doctor_name
            << "            "
            << hospitals[i].price
            << "            "
            << endl;
    }
    cout << endl
        << endl;
}

void PrintHospitalByAvailablebeds(int available_beds, vector<Hospital> hospitals)
{
    cout << "PRINT hospitals which available_beds is not less than:"
        << available_beds << endl;

    cout << "HospitalName     "
        << "Location     "
        << "Beds_Available     "
        << "Rating     "
        << "Hospital_Contact     "
        << "Doctor_Name     "
        << "Price_Per_Bed     \n";
    for (int i = 0; i < hospitals.size(); i++) {

        if (hospitals[i].available_beds < available_beds)
            continue;
        cout << hospitals[i].H_name
            << "                "
            << hospitals[i].location
            << "           "
            << hospitals[i].available_beds
            << "             "
            << hospitals[i].rating
            << "            "
            << hospitals[i].contact
            << "            "
            << hospitals[i].doctor_name
            << "            "
            << hospitals[i].price
            << "            "
            << endl;
    }
    cout << endl
        << endl;
}

void PrintHospitalByPrice(int price, vector<Hospital> hospitals)
{
    cout << "PRINT hospitals which beds_price is not more than:"
        << price << endl;

    cout << "HospitalName     "
        << "Location     "
        << "Beds_Available     "
        << "Rating     "
        << "Hospital_Contact     "
        << "Doctor_Name     "
        << "Price_Per_Bed     \n";
    for (int i = 0; i < hospitals.size(); i++) {

        if (hospitals[i].price > price)
            continue;
        cout << hospitals[i].H_name
            << "                "
            << hospitals[i].location
            << "           "
            << hospitals[i].available_beds
            << "             "
            << hospitals[i].rating
            << "            "
            << hospitals[i].contact
            << "            "
            << hospitals[i].doctor_name
            << "            "
            << hospitals[i].price
            << "            "
            << endl;
    }
    cout << endl
        << endl;
}
// Function to implement Hospital 
// Management System 
void HospitalManagement(
    string patient_Name[], int patient_Id[],
    string patient_Contact[], int bookingCost[],
    string hospital_Name[], string locations[], int beds[],
    float ratings[], string hospital_Contact[],
    string doctor_Name[], int prices[],int doctor_id[])
{
    // Stores the Hospital data 
    // and user data 
    

    // Create Objects for hospital 
    // and the users 
    Hospital h;

    // Initialize the data 
    for (int i = 0; i < 4; i++) {
        h.H_name = hospital_Name[i];
        h.location = locations[i];
        h.available_beds = beds[i];
        h.rating = ratings[i];
        h.contact = hospital_Contact[i];
        h.doctor_name = doctor_Name[i];
        h.price = prices[i];
        hospitals.push_back(h);
    }

    Doctor d;

    for (int i = 0; i < 4; i++)
    {
        d.doctor_id = doctor_id[i];
        d.doctor_name= doctor_Name[i];
        d.rating = ratings[i];
        d.hospital = &hospitals[i];
        doctors.push_back(d);
    }
    // Stores the patient data 
    
    Patient p;

    // Initialize the data 
    for (int i = 0; i < 4; i++) {
        p.P_name = patient_Name[i];
        p.P_id = patient_Id[i];
        p.contact = patient_Contact[i];
        p.price = bookingCost[i];
        p.doctor = &doctors[i];
        patients.push_back(p);
    }

    //cout << endl;

    /*PrintHospitalData(hospitals);
    PrintPatientData(patients, hospitals);

    SortHospitalByName(hospitals);
    SortHospitalByRating(hospitals);
    PrintHospitalBycity("Bangalore", hospitals);
    SortByBedsAvailable(hospitals);
    SortByBedsPrice(hospitals);*/
}
//主界面
void UI(vector<Hospital> hospitals, vector<Patient> patients,vector<Doctor> doctors,User user)
{
    cout << endl;
    cout << "请选择：";
    cout << "1.展示医院信息 2.展示医生信息 3.展示病人信息 4.按医院名称排序医院 5.按医院评价排序医院 6.按地点排序医院" << endl; 
    cout << "7.按剩余可用床位排序医院 8.按床位价格排序医院 9.按地点筛选医院 10.按名称查找医院" << endl;
    cout << "11.按医生姓名查找医院 12.按剩余可用床位筛选医院 13.按床位价格筛选医院 14.评价医生" << endl;
    cout << "15.查看自己的评价 16.退出登录" << endl;
    cout << endl;
    string x; string y; int z;
    cin >> x;
    int x1 = atoi(x.c_str());
    switch (x1) {
    case 1:
        if (user.type == 0) 
        { 
            PrintHospitalData(hospitals); UI(hospitals, patients, doctors, user);
        }
        else
        {
            cout << "该功能仅限管理员！" << endl; cout << endl; UI(hospitals, patients, doctors, user);
        }
        break;
    case 2:
        if (user.type == 0)
        {
            PrintDoctorData(doctors); UI(hospitals, patients, doctors, user);
        }
        else
        {
            cout << "该功能仅限管理员！" << endl; cout << endl; UI(hospitals, patients, doctors, user);
        }
        break;
    case 3:
        if (user.type == 0)
        {
            PrintPatientData(patients, hospitals); UI(hospitals, patients, doctors, user);
        }
        else
        {
            cout << "该功能仅限管理员！" << endl; cout << endl; UI(hospitals, patients, doctors, user);
        }
         break;
    case 4:SortHospitalByName(hospitals); UI(hospitals, patients, doctors, user); break;
    case 5:SortHospitalByRating(hospitals); UI(hospitals, patients, doctors, user); break;
    case 6:SortHospitalByLocation(hospitals); UI(hospitals, patients, doctors, user); break;
    case 7:SortByBedsAvailable(hospitals); UI(hospitals, patients, doctors, user); break;
    case 8:SortByBedsPrice(hospitals); UI(hospitals, patients, doctors, user); break;
    case 9:cout << endl;
        cout << "请输入地点：";
        cin >> y;
        PrintHospitalBycity(y, hospitals);
        cout << endl;
        UI(hospitals, patients, doctors, user); break;
    case 10:cout << endl;
        cout << "请输入名称：";
        cin >> y;
        PrintHospitalByName(y, hospitals);
        cout << endl;
        UI(hospitals, patients, doctors, user); break;
    case 11:cout << endl;
        cout << "请输入医生姓名：";
        cin >> y;
        PrintHospitalByDoctorName(y, hospitals);
        cout << endl;
        UI(hospitals, patients, doctors, user); break;
    case 12:cout << endl;
        cout << "请输入剩余床位最小值：";
        cin >> z;
        PrintHospitalByAvailablebeds(z, hospitals);
        cout << endl;
        UI(hospitals, patients, doctors, user); break;
    case 13:cout << endl;
        cout << "请输入床位价格最大值：";
        cin >> z;
        PrintHospitalByPrice(z, hospitals);
        cout << endl;
        UI(hospitals, patients, doctors, user); break;
    case 14:cout << endl;
        if (user.type == 2)
        {
            
            cout << "主治医生" << user.patient->doctor->doctor_name<<endl;
            cout << "请输入评分：";
            
        L1:
            cout << endl;
            cin >> z;
            if (z < 0 || z>6)
            {
                cout << "评分在0-6之间，请重新输入：";
                goto L1;
            }
            else
            {
                user.patient->doctor->rating_number++;
                user.patient->doctor->rating = (user.patient->doctor->rating * (user.patient->doctor->rating_number - 1) + z) / user.patient->doctor->rating_number;
                user.patient->doctor->hospital->rating = user.patient->doctor->rating;
                cout << "评价成功！";
                cout << endl;
                UI(hospitals, patients, doctors, user); 
            }
        }
        else
        {
            cout << "该功能仅限病人！" << endl;
            cout << endl;
            UI(hospitals, patients, doctors, user);
        }
        break;
    case 15:cout << endl;
        if (user.type == 1)
        {
            cout << "共有" << user.doctor->rating_number << "人评价了你" << endl;
            cout << "你的评分为" << user.doctor->rating << endl;
            cout << "你的医院评分为" << user.doctor->hospital->rating << endl;
            cout << endl;
            UI(hospitals, patients, doctors, user);
        }
        else
        {
            cout << "该功能仅限医生！" << endl;
            cout << endl;
            UI(hospitals, patients, doctors, user);
        }
        break;
    case 16:break;
    default:
        cout << endl;
        cout << "不合法输入！";
        UI(hospitals, patients, doctors, user); break;
    }
}

void log_in()
{
    string x;
    string y;
    int z = 0;
    string w;
    User user;
L2:
    cout << endl;
    cout << "请选择：";
    cout << "1.注册 2.登录 3.退出" << endl;
    cin >> x;
    int x1 = atoi(x.c_str());
    switch(x1)
    {
    case 1:cout << "请输入用户名" << endl;
        cin >> x;
        cout << "请输入密码" << endl;
        cin >> y;
        cout << "请输入你的身份：1.医生 2.病人" << endl;
        cin >> z;
        cout << "请输入你的姓名：" << endl;
        cin >> w;
        user.id = users[users.size() - 1].id + 1;
        user.username = x;
        user.password = y;
        user.type = z;
        if (z == 1)
        {
            for (int i = 0; i < doctors.size(); i++)
            {
                if (doctors[i].doctor_name == w)
                {
                    user.doctor = &doctors[i];
                    user.patient = NULL;
                    break;
                }
            }
        }
        else if(z==2)
        {
            for (int i = 0; i < patients.size(); i++)
            {
                if (patients[i].P_name == w)
                {
                    user.doctor = NULL;
                    user.patient = &patients[i];
                    break;
                }
            }
        }
        else
        {
            cout << "不合法输入！" << endl;
            cout << endl;
            goto L2;
        }
        if (user.doctor == NULL && user.patient == NULL)
        {
            cout << "找不到本人信息！" << endl;
            cout << endl;
            goto L2;
        }
        users.push_back(user);
        cout << endl;
        cout << "欢迎回来，用户" << user.username << endl;
        cout << endl;
        UI(hospitals, patients, doctors, user);
        log_in();
        break;
    case 2:cout << endl;
        cout << "请输入用户名" << endl;
        cin >> x;
        cout << "请输入密码" << endl;
        cin >> y;
        
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].username == x && users[i].password == y)
            {
                cout << endl;
                cout << "欢迎回来，用户" << users[i].username << endl;
                cout << endl;
                UI(hospitals, patients, doctors, users[i]);
                z = 1;
                break;
            }
        }
        if (!z)
        {
            cout << endl;
            cout << "用户名或密码有误！请重新输入" << endl;
            cout << endl;
        }
        log_in();
        break;
    case 3:break;
    default:cout << "不合法输入！" << endl;
        log_in();
        break;
    }
}
// Driver Code 
int main()
{
    // Stores hospital data and 
    // the user data 
    string patient_Name[] = { "P1", "P2", "P3", "P4" };
    int patient_Id[] = { 2, 3, 4, 1 };
    string patient_Contact[]
        = { "234534XXX7", "234576XXX2", "857465XXX9",
            "567657XXX0" };
    int bookingCost[] = { 1000, 1200, 1100, 600 };

    string hospital_Name[] = { "H1", "H2", "H4", "H3" };
    string locations[] = { "Bangalore", "Bangalore",
                           "Mumbai   ", "Prayagraj" };
    int beds[] = { 4, 5, 6, 9 };
    float ratings[] = { 5.2, 4.1, 3.4, 5.9 };
    string hospital_Contact[]
        = { "657534XXX7", "298766XXX2", "324565XXX9",
            "343456XXX4" };
    string doctor_Name[] = { "D1", "D4", "D3", "D2" };
    int prices[] = { 100, 200, 100, 290 };
    int doctor_id[] = { 1,2,3,4 };
    // Function Call 
    
    HospitalManagement(
        patient_Name, patient_Id, patient_Contact,
        bookingCost, hospital_Name, locations, beds,
        ratings, hospital_Contact, doctor_Name, prices,doctor_id);
    User user;
    user.id = 1;
    user.type = 0;
    user.username = "admin";
    user.password = "123";
    user.doctor = NULL;
    user.patient = NULL;
    users.push_back(user);
    log_in();
    return 0;
}