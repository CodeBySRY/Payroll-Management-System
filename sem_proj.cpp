#include <iostream>
#include <cmath>
#include <fstream>
#include <limits>
using namespace std;

// String is to be used for all the text inputs so that when, the user inputs, the spaces can be dealt with accordingly, using getline.
long long int EmployeeID;
string Name[100000];
string Position[100000];
string DOB[100000];
string address[100000];
int MonthSalary[100000];
string NewName[100000];
string NewPosition[100000];
string NewDOB[100000];
string Newaddress[100000];
float NewMonthSalary[100000];
int DaysWorked;
int leaves;
float HourlyRate;
int Overtime;
float OvertimePay;
float DailyRate;
float GrossSalary;
char UserChoiceML; // This is simplified to as the following: the user choice for the medical leaves code block.
int ML; // ML = medical leaves;
float deduct;
float netsalary;
int Logout;
int ViewChoice;


void MainFunc();


void AdminMenu();


void EmployeeMenu();


bool validCheck;


void EditEmployee();


void intCheck();


void View();


int main () {

	cout << endl;
	cout << "\t\t\t --------------------------------------------------------- " << endl;
	cout << " \t\t\t\t Welcome To Our Payroll Management System! " << endl;
		cout << "\t\t\t --------------------------------------------------------- " << endl;
		cout << endl;
		
		
		MainFunc();
		
		
		return 0;
	
}



void MainFunc() {
		int MainChoice;
			while (true) {
			cout << "Please Select Your Role: " << endl;
	cout << "1. Admin " << endl;
	cout << "2. Employee " << endl;
	wcout << "ENTER YOUR CHOICE (1 OR 2) =  ";
	cin >> MainChoice;
	intCheck();
	switch (MainChoice) {
		case 1:
			AdminMenu();
			break;
		case 2:
			EmployeeMenu();
			break;
		default:
			cout << " --------- " << endl;
			continue;
	}
	
	
	break;
	
	
		}
			
	
}


void AdminMenu() {
	
	ofstream file("december.txt", ios::app);
	
	cout << endl;
	cout << endl;
	int AdminChoice;

	
	while (true) {
			cout << " ----------- " << endl;
	cout << " ADMIN MENU " << endl;
	cout << " ----------- " << endl;
			cout << "1. Add New Employee " << endl;
	cout << "2. Edit Employee Info " << endl;
	cout << "3. Generate Payslip " << endl;
	cout << "4. View Employee Details " << endl;
	cout << "5. PROGRAM TERMINATION " << endl;
	cout << "Enter Your Choice = ";
	cin >> AdminChoice;
	switch (AdminChoice) {
		case 1:
			cout << endl;
			cout << "Enter Employee ID    : ";
			cin >> EmployeeID;
			intCheck();
			cin.ignore();
			cout << "Enter Name           : ";
			getline(cin, Name[EmployeeID]);
			cout << "Enter D.O.B          : ";
			getline(cin, DOB[EmployeeID]);
			cout << "Enter Position       : ";
			getline(cin, Position[EmployeeID]);
			cout << "Enter Monthly Salary : ";
			cin >> MonthSalary[EmployeeID];
			intCheck();
			cin.ignore();
			cout << "Enter Address        : ";
			getline(cin, address[EmployeeID]);
			cout << endl << endl;
			
			file << EmployeeID << ", " << Name[EmployeeID] << ", " << DOB[EmployeeID] << ", " << Position[EmployeeID] << ", " << MonthSalary[EmployeeID] << ", " << address[EmployeeID] << endl;
			file.close() ;
			cout << "EMPLOYEE DETAILS ADDED SUCCESSFULLY! " << endl << endl;
			
			break;
		
		case 2:
			cout << endl;
			cout << "Enter Employee ID To Edit : ";
			cin >> EmployeeID;
			cout << " ------------------- " << endl;
			cout << " Current Information " << endl;
			cout << " ------------------- " << endl;
			cout << "NAME          : " << Name[EmployeeID] << endl;
			cout << "D.O.B          : " << DOB[EmployeeID] << endl;
			cout << "POSITION       : " << Position[EmployeeID] << endl;
			cout << "MONTHLY SALARY : " << MonthSalary[EmployeeID] << endl;
			cout << "ADDRESS : " << address[EmployeeID] << endl << endl;
			cout << "What would you like to edit? " << endl;
			EditEmployee();
			
			break;
			
		case 3:
			cout << endl;
			cout << " -------------------- " << endl;
			cout << " Generating Payslips " << endl;
			cout << " -------------------- " << endl;
			cout << "Enter Employee ID : ";
			cin >> EmployeeID;
			cout << "NAME             : " << Name[EmployeeID] << endl;
			cout << "DESIGNATION      : " << Position[EmployeeID] << endl;
			cout << "MONTHLY SALARY   : " << MonthSalary[EmployeeID] << endl << endl;
			cout << "The Total Working Days = 22 " << endl << endl;
			DailyRate = MonthSalary[EmployeeID]/22.00;
			cout << "Daily Rate = " << DailyRate << endl;
			cout << "Enter Days Worked = ";
			cin >> DaysWorked;
			if (DaysWorked <= 22&& DaysWorked >= 0) {
				leaves = 22 - DaysWorked;
				cout << "Enter the # of OVERTIME hours = ";
				cin >> Overtime;
				HourlyRate = DailyRate/9;
				OvertimePay = Overtime*HourlyRate;
				cout << endl << endl;
				GrossSalary = (DailyRate*DaysWorked)+OvertimePay;
				cout << " GROSS SALARY : " << GrossSalary << endl;
				cout << " LEAVES : " << leaves << endl << endl;
				cout << "Were there medical leaves (Y/N) ? ";
				cin >> UserChoiceML;
				if ((UserChoiceML == 'Y')||(UserChoiceML == 'y')) { 
					cout << "How many of them? ";
					cin >> ML;
					if (ML > 0 && ML <= 15) {
						leaves = leaves - ML;
						cout << "CASUAL LEAVES : " << leaves << endl;
					}
					else {
						cout << "INVALID Input! " << endl;
					}
				}
				else if (UserChoiceML == 'N'|| UserChoiceML == 'n') {
					cout << "CASUAL LEAVES : " << leaves << endl;
				}
			}
			else {
				cout << "INVALID Input! There are 22 WORKING days. " << endl;
			}
			deduct = (0.05*GrossSalary)+(leaves*DailyRate)+1000;
			cout << "DEDUCTIONS  : " << deduct << endl << endl << endl;
			netsalary = GrossSalary - deduct;
			cout << "NET SALARY === " << netsalary << endl << endl;
			
			break;
			
			
		case 4:
			
			View();
			
		case 5:
			cout << endl;
			cout << " ------------------------------------------------------ " << endl;
				cout << "Would you like to: " << endl;
			cout << "1. Return To Main Menu " << endl;
			cout << "2. Logout " << endl;
			cout << "ENTER YOUR CHOICE = ";
			cin >> Logout;
			cout << endl << endl;
			switch (Logout) {
				case 1:
					
					MainFunc();
					
					break;
					
				case 2:
				cout << "\t\t\t\t ----------------------------------- " << endl;
				cout << "\t\t\t\t Thank You For Using Our Program! " << endl;
				cout << "\t\t\t\t ----------------------------------- " << endl;

			exit(0);
			
			break;
			}
		
				
	}
	
	
	} // This curly bracket corresponds to the while (true) loop.

	
	
}



void intCheck() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input! Try Again. " << endl;
		validCheck = false;
	}
	else {
		validCheck = true;
	}
}


void EditEmployee() {
	int UserChoice;
	cout << "1. Name " << endl;
	cout << "2. D.O.B " << endl;
	cout << "3. Position " << endl;
	cout << "4. Monthly Salary " << endl;
	cout << "5. Address " << endl;
	cout << endl;
	cout << "ENTER YOUR CHOICE = ";
	cin >> UserChoice;
	switch (UserChoice) {
		case 1:
			cout << "Enter NEW Name : ";
			cin.ignore(); // This removes the input buffer from before, through the use of cin operator, and prevents the compiler by going into the next line by way of '\n'.
			getline(cin, NewName[EmployeeID]);
			Name[EmployeeID] = NewName[EmployeeID];
			
			cout << endl << endl;

			
			cout << "EDITING DONE SUCCESSFULLY!" << endl << endl;
			
			break;
		
		case 2:
			cout << "Enter NEW D.O.B : ";
			cin.ignore();
			getline(cin, NewDOB[EmployeeID]);
			DOB[EmployeeID] = NewDOB[EmployeeID];
			
			cout << endl << endl;

			
			cout << "EDITING DONE SUCCESSFULLY!" << endl << endl;

			
			break;
			
		case 3:
			cout << "Enter NEW Position : ";
			cin.ignore();
			getline(cin, NewPosition[EmployeeID]);
			Position[EmployeeID] = NewPosition[EmployeeID];
			
			cout << endl << endl;

			
			cout << "EDITING DONE SUCCESSFULLY!" << endl << endl;

			
			break;
			
		case 4:
			cout << "Enter NEW Monthly Salary : ";
			cin.ignore();
			cin >> NewMonthSalary[EmployeeID];
			MonthSalary[EmployeeID] = NewMonthSalary[EmployeeID];
			
			cout << endl << endl;

			
			cout << "EDITING DONE SUCCESSFULLY!" << endl << endl;

			
			break;
			
		case 5:
			cout << "Enter NEW Address : ";
			cin.ignore();
			getline(cin, Newaddress[EmployeeID]);
			address[EmployeeID] = Newaddress[EmployeeID];
			
			cout << endl << endl;
			
			cout << "EDITING DONE SUCCESSFULLY!" << endl << endl;

			
			break;
	}
}


void EmployeeMenu() {
	cout << endl;
	cout << endl;
	int EmployeeChoice;
	
	while (true) {
	cout << " --------------- " << endl;
	cout << " EMPLOYEE MENU " << endl;
	cout << " --------------- " << endl;
	cout << "1. View Personal Information " << endl;
	cout << "2. View Payslip " << endl;
	cout << "3. PROGRAM TERMINATION " << endl;
	cout << "Enter Your Choice = ";
	cin >> EmployeeChoice;
	switch (EmployeeChoice) {
		case 1:
			cout << endl;
			cout << "Kindly Enter Your Employee ID: ";
			cin >> EmployeeID;
			cout << " ----------------------------------------------- " << endl;
			cout << "EMPLOYEE ID    : " << EmployeeID << endl;
			cout << "NAME           : " << Name[EmployeeID] << endl;
			cout << "DESIGNATION    : " << Position[EmployeeID] << endl;
			cout << "D.O.B          : " << DOB[EmployeeID] << endl;
			cout << "MONTHLY SALARY : " << MonthSalary[EmployeeID] << endl;
			cout << "ADDRESS        : " << address[EmployeeID] << endl;
			cout << " ----------------------------------------------- " << endl;
			
			break;
			
		case 2:
			cout << "Enter Your Employee ID : ";
			cin >> EmployeeID;
			cout << " ----------------------------------------------- " << endl;
			cout << "EMPLOYEE ID       : " << EmployeeID << endl;
			cout << "NAME              : " << Name[EmployeeID] << endl;
			cout << "DESIGNATION       : " << Position[EmployeeID] << endl;
			cout << "MONTHLY SALARY    : " << "$" << MonthSalary[EmployeeID] << endl;
			cout << "DAILY RATE        : " << "$" << DailyRate << endl;
			cout << "DAYS WORKED       : " << DaysWorked << "/22" << endl;
			cout << endl;
			cout << endl;
			cout << "Gross Salary = " << "$" << GrossSalary << endl;
			cout << "Deductions   = " << "$" << deduct << endl;
			cout << "NET Salary   = " << "$" << netsalary << endl;
			cout << " ----------------------------------------------- " << endl;
			
			break;
			
		case 3:
			cout << "Would you like to: " << endl;
			cout << "1. Return To Main Menu " << endl;
			cout << "2. Logout " << endl;
			cout << "ENTER YOUR CHOICE = ";
			cin >> Logout;
			cout << endl << endl;
			switch (Logout) {
				case 1:
					
					MainFunc();
					
					break;
					
					
				case 2:
					cout << "\t\t\t\t ----------------------------------- " << endl;
					cout << "\t\t\t\t Thank You For Using Our Program! " << endl;
					cout << "\t\t\t\t ----------------------------------- " << endl;

					exit(0);
			
					break;
			}
		


	}
	}
}


void View() {
	cout << "Please select the month for which you would like to view the employee data: ";
	cout << "1. June " << endl;
	cout << "2. July " << endl;
	cout << "3. August " << endl;
	cout << "4. September " << endl;
	cout << "5. October " << endl;
	cout << "6. November " << endl;
	cout << "7. December " << endl;
	cout << "ENTER YOUR CHOICE = ";
	cin >> ViewChoice;
	
	ifstream ViewFile;
    string text;
    // Variables declared once, to prevent re-declaration in each case.
    
    
	switch (ViewChoice) {
		  case 1:
            cout << "Displaying Data For June... " << endl;
            cout << endl;
            ViewFile.open("June.txt");
            if (ViewFile.is_open()) {
                while (getline(ViewFile, text)) { // getline allows for the whole lines to be output and displayed line by line using endl.
                    cout << text << endl;
                }
            } else {
                cout << "Error opening file for June." << endl;
            }
            ViewFile.close();  // It is necessary to close the file;
            break;

        case 2:
            cout << "Displaying Data For July... " << endl;
            cout << endl;
            ViewFile.open("July.txt");
            if (ViewFile.is_open()) {
                while (getline(ViewFile, text)) {
                    cout << text << endl;
                }
            } else {
                cout << "Error opening file for July." << endl;
            }
            ViewFile.close();
            break;

        case 3:
            cout << "Displaying Data For August... " << endl;
            cout << endl;
            ViewFile.open("August.txt");
            if (ViewFile.is_open()) {
                while (getline(ViewFile, text)) {
                    cout << text << endl;
                }
            } else {
                cout << "Error opening file for August." << endl;
            }
            ViewFile.close();
            break;

        case 4:
            cout << "Displaying Data For September... " << endl;
            cout << endl;
            ViewFile.open("September.txt");
            if (ViewFile.is_open()) {
                while (getline(ViewFile, text)) {
                    cout << text << endl;
                }
            } else {
                cout << "Error opening file for September." << endl;
            }
            ViewFile.close();
            break;

        case 5:
            cout << "Displaying Data For October... " << endl;
            cout << endl;
            ViewFile.open("October.txt");
            if (ViewFile.is_open()) {
                while (getline(ViewFile, text)) {
                    cout << text << endl;
                }
            } else {
                cout << "Error opening file for October." << endl;
            }
            ViewFile.close();
            break;

        case 6:
            cout << "Displaying Data For November... " << endl;
            cout << endl;
            ViewFile.open("November.txt");
            if (ViewFile.is_open()) {
                while (getline(ViewFile, text)) {
                    cout << text << endl;
                }
            } else {
                cout << "Error opening file for November." << endl;
            }
            ViewFile.close();
            break;

        case 7:
            cout << "Displaying Data For December... " << endl;
            cout << endl;
            ViewFile.open("December.txt");
            if (ViewFile.is_open()) {
                while (getline(ViewFile, text)) {
                    cout << text << endl;
                }
            } else {
                cout << "Error opening file for December." << endl;
            }
            ViewFile.close();
            break;

        default:
            cout << "Invalid choice! Please enter a number between 1 and 7." << endl;
            break;
    }
			
			
	}
