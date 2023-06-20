#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<stdio.h>

using namespace std;

void red()
{

	printf("\033[0;31m");

}
void boldRed()
{

	printf("\033[1;31m");

}
void yellow()
{

	printf("\033[0;33m");

}
void boldYellow()
{

	printf("\033[1;33m");

}
void green()
{

	printf("\033[0;32m");

}
void boldGreen()
{

	printf("\033[1;32m");

}
void blue()
{

	printf("\033[0;34m");

}
void boldBlue()
{

	printf("\033[1;34m");

}
void magenta()
{

	printf("\033[0;35m");

}
void boldMagenta()
{

	printf("\033[1;35m");

}
void cyan()
{

	printf("\033[0;36m");

}
void boldCyan()
{

	printf("\033[1;36m");

}
void reset()
{

	printf("\033[0m");

}

int getSizeOfcharArray(char name[])
{
	int count = 0;
	for (int i = 0; name[i] != '\n' && name[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
class Name
{
	char* firstName;
	int sizeFirstName;
	char* lastName;
	int sizeLastName;
public:
	Name(char* fName, char* lName);
	//add following functions getter,setters Destructors, DEfault constructor, COpy constructors
	friend ostream& operator<<(ostream&, const Name&);
	Name()
	{
		firstName = new char[100];
		lastName = new char[100];
	}
	~Name()
	{
		delete[]firstName;
		delete[]lastName;
	}
	void setName(char fName[], char lName[])
	{
		int sizeOf_fName = 0;
		int sizeOf_lName = 0;

		sizeOf_fName = getSizeOfcharArray(fName);
		sizeOf_lName = getSizeOfcharArray(lName);

		sizeFirstName = sizeOf_fName;
		sizeLastName = sizeOf_lName;

		for (int i = 0; i < sizeOf_fName; i++)
		{
			firstName[i] = fName[i];
		}
		firstName[sizeOf_fName] = '\0';
		for (int i = 0; i < sizeOf_lName; i++)
		{
			lastName[i] = lName[i];
		}
		lastName[sizeOf_lName] = '\0';
	}
	void printName()
	{
		cout << "First Name of the Customer: ";
		for (int i = 0; i < sizeFirstName; i++)
		{
			cout << firstName[i];
		}
		cout << endl;
		cout << "Last Name of the Customer: ";
		for (int i = 0; i < sizeLastName; i++)
		{
			cout << lastName[i];
		}
		cout << endl;
	}
};
ostream& operator<<(ostream& cout, const Name& n)
{
	cout << n.firstName << " " << n.lastName << endl;
	return cout;
}

class Date
{
	int day;
	int month;
	int year;
	//add constructors getters and setters and stream output operator that
	//gives format day/month/year
public:
	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	~Date()
	{

	}
	void setDateOfBirth(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	void printDateOfBirth()
	{
		cout << "Date: " << day << "/" << month << "/" << year << endl;
	}
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
};

class Time
{
	int hour;
	int min;
	int sec;
	//add constructors getters and setters and stream output operator that
	//gives format hr/min/sec
public:
	Time()
	{
		hour = 0;
		min = 0;
		sec = 0;
	}
	~Time()
	{

	}
	void setTime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void printTime()
	{
		cout << hour << ":" << min << ":" << sec << endl;
	}
};

class Service/*: public Customer,public Vehicle, public Driver*/
{
	char* source;
	char* destination;
	float distance; //in km
	Date bookingDate;
	Time bookingTime;
	bool status; //false for pending true for complete 
	float fuelRate;

	int customerID; //customer who booked the ride
	int driverID; //driver id
	int vehicleID; //vehicla id
	int serviceID;
	//can add more members if required
	//add member functions
public:
	Service()
	{
		source = new char[100];
		destination = new char[100];
		distance = 0; //in km
		status = false; //false for pending true for complete
		fuelRate = 0;

		customerID = 0; //customer who booked the ride
		driverID = 0; //driver id
		vehicleID = 0; //vehicla id
	}
	~Service()
	{
		delete[]source;
		delete[]destination;
	}
	void setServices(int sID, int cID, int dID, int vID, char sour[], char dest[], float fuel, float dis, bool stat,
		int day, int month, int year, int hr, int min, int sec)
	{
		serviceID = sID;
		customerID = cID;
		driverID = dID;
		vehicleID = vID;
		int sizeOfSource = getSizeOfcharArray(sour);
		int sizeOfDestination = getSizeOfcharArray(dest);
		for (int i = 0; i < sizeOfSource; i++)
		{
			source[i] = sour[i];
		}
		source[sizeOfSource] = '\0';
		for (int i = 0; i < sizeOfDestination; i++)
		{
			destination[i] = dest[i];
		}
		destination[sizeOfDestination] = '\0';
		fuelRate = fuel;
		distance = dis;
		status = stat;

		bookingDate.setDateOfBirth(day, month, year);
		bookingTime.setTime(hr, min, sec);
	}
	void printServices()
	{
		cout << "\t\t\tSERVICE HISTORY\n";
		cout << "Service ID: " << serviceID << endl;
		cout << "Customer ID: " << customerID << endl;
		cout << "Driver's ID: " << driverID << endl;
		cout << "Vehicle's ID: " << vehicleID << endl;
		int sizeOfSource = getSizeOfcharArray(source);
		int sizeOfDestination = getSizeOfcharArray(destination);
		cout << "Source Location: ";
		for (int i = 0; i < sizeOfSource; i++)
		{
			cout << source[i];
		}
		cout << endl;
		cout << "Destination Location: ";
		for (int i = 0; i < sizeOfDestination; i++)
		{
			cout << destination[i];
		}
		cout << endl;
		cout << "Fuel Rate was: " << fuelRate << endl;
		cout << "Distance Travelled: " << distance << endl;
		cout << "Status If booked or Not: " << status << endl;
		bookingDate.printDateOfBirth();
		bookingTime.printTime();
	}
	float getDistance()
	{
		return distance;
	}
	float getFuelRate()
	{
		return fuelRate;
	}
	int getVehicleIdInService()
	{
		return vehicleID;
	}
	int getCustomerIdinService()
	{
		return customerID;
	}
	int getDriverIdInService()
	{
		return driverID;
	}
	int getDayInService()
	{
		return bookingDate.getDay();
	}
	int getMonthInService()
	{
		return bookingDate.getMonth();
	}
	int getYearInService()
	{
		return bookingDate.getYear();
	}
	int getStatusInService()
	{
		return status;
	}
};

class Ride :public Service
{
	int noOfPassengers;
	char* rideType; //intercity, intracity
	float driverRanking;// (0 to 5) worst to best
	float vehicleRanking;// (0 to 5) worst to best
	bool bookRide;
	int fileCountForRide;
	//can add more members
public:
	Ride()
	{
		noOfPassengers = 0;
		rideType = new char[50];
		driverRanking = 0;
		vehicleRanking = 0;
		bookRide = false;
	}
	~Ride()
	{
		delete[]rideType;
	}
	void setRideInfo(int noOfPas, char r_type[], float d_Rank, float v_Rank, int sID, int cID, int dID, int vID,
		char sour[], char dest[], float fuel, float dis, bool stat, int day, int month, int year, int hr,
		int min, int sec, bool bookRide)
	{
		noOfPassengers = noOfPas;
		strcpy(rideType, r_type);
		driverRanking = d_Rank;
		vehicleRanking = v_Rank;
		this->bookRide = bookRide;
		Service::setServices(sID, cID, dID, vID, sour, dest, fuel, dis,
			stat, day, month, year, hr, min, sec);

	}
	void setRideFileCount(int fileCount)
	{
		fileCountForRide = fileCount;
	}
	int getRideFileCount()
	{
		return fileCountForRide;
	}
	void printRideInfo()
	{
		boldMagenta();
		cout << "\t\t\tRIDE SERVICE\n";
		cout << "Number of Passengers: " << noOfPassengers << endl;
		int sizeOfrideType = getSizeOfcharArray(rideType);
		cout << "Ride Type (Inter-or-IntraCity): ";
		for (int i = 0; i < sizeOfrideType; i++)
		{
			cout << rideType[i];
		}
		cout << endl;
		cout << "Driver Rank: " << driverRanking << endl;
		cout << "Vehicle Rank: " << vehicleRanking << endl;
		Service::printServices();
	}
	char* getRideType()
	{
		return rideType;
	}
	bool getBookRide()
	{
		return bookRide;
	}

};

class Delivery :public Service
{
	float goodsWeight; //in kgs
	char* goodsType; //types of goods food furniture petroleum chemicals etc
	bool bookDeli;
	int fileCountForDeli;
public:
	Delivery()
	{
		goodsWeight = 0;
		goodsType = new char[200];
		bookDeli = false;
	}
	~Delivery()
	{
		delete[]goodsType;
	}
	void setDeliveryInfo(float goodsW, char goodsT[], int sID, int cID, int dID, int vID,
		char sour[], char dest[], float fuel, float dis, bool stat, int day, int month, int year, int hr,
		int min, int sec, bool bookDeli)
	{
		goodsWeight = goodsW;
		strcpy(goodsType, goodsT);
		this->bookDeli = bookDeli;
		Service::setServices(sID, cID, dID, vID, sour, dest, fuel, dis,
			stat, day, month, year, hr, min, sec);
	}
	void setDeliveryFileCount(int fileCount)
	{
		fileCountForDeli = fileCount;
	}
	int getDeliveryFileCount()
	{
		return fileCountForDeli;
	}
	bool getBookDelivery()
	{
		return bookDeli;
	}
	void printDeliveryInfo()
	{
		boldYellow();
		cout << "\t\t\tDELIVERY SERVICE\n";
		cout << "The Total weight of the Goods is: " << goodsWeight << endl;
		cout << "Information about the Good: ";
		int sizeOfgoods = getSizeOfcharArray(goodsType);
		for (int i = 0; i < sizeOfgoods; i++)
		{
			cout << goodsType[i];
		}
		cout << endl;
		Service::printServices();
	}
};

class Person
{
	Name personName;
	Date dateOfBirth;
	int age;
	int nationalId;
	//add following functions getter,setters Destructors, DEfault constructor, COpy constructors
	//(print information of the person)
public:
	Person()
	{

	}
	~Person()
	{

	}
	void setCustomerAge_Nid(int a, int nId, char fName[], char lName[], int day, int month, int year)
	{
		age = a;
		nationalId = nId;

		personName.setName(fName, lName);
		dateOfBirth.setDateOfBirth(day, month, year);
	}
	void printPersonsInfo()
	{
		personName.printName();
		cout << "Age: " << age << endl;
		cout << "National ID: " << nationalId << endl;
		dateOfBirth.printDateOfBirth();
	}
};

class Customer :public Person
{
	int custId;
	Service** bookingHistory;
	int fileCount;
	// add following functions getter, setters Destructors, DEfault constructor, COpy constructors
	//(print information of the person)
public:
	Customer()
	{
		custId = 0;
		bookingHistory = new Service * [10];
		for (int i = 0; i < 10; i++)
		{
			bookingHistory[i] = new Service;
		}
	}
	~Customer()
	{
		for (int i = 0; i < 10; i++)
		{
			delete[] bookingHistory[i];
		}
		delete[] bookingHistory;
	}
	void setNewCustomer(int custCount, char fName[], char lName[], int age, int nId, int day, int month, int year)
	{
		custId = custCount;
		Person::setCustomerAge_Nid(age, nId, fName, lName, day, month, year);
	}
	void setCustomerServices(int sID, int cID, int dID, int vID, char sour[],
		char dest[], float fuel, float dis, bool stat, int day, int month, int year, int hr, int min, int sec)
	{
		for (int i = 0; i < 1; i++)
		{
			bookingHistory[i][0].setServices(sID, cID, dID, vID, sour, dest, fuel, dis, stat, day, month, year, hr, min, sec);

		}
	}
	void printCustomerInfo()
	{
		cyan();
		cout << "The Customer ID is: " << custId << endl;
		//Name::printName();
		Person::printPersonsInfo();
	}
	/*void printCustomerServices()
	{
		for (int i = 0; i < 1; i++)
		{
			bookingHistory[i][0].printServices();
		}
	}*/
	int getCustomerId()
	{
		return custId;
	}
	void setCustomerFileCount(int cId)
	{
		custId = cId;
	}
	int getCustomerFileCount()
	{
		return custId;
	}
};

class Driver :public Person
{
	int driverId;
	char** licenceList;
	int noOfLicences;
	float overallRanking;
	float salary;
	int experience;
	int status; //1 free 2 booked 3 canceled
	int fileCountDriv;
	Service** serviceHistory;
	// add following functions getter, setters Destructors, DEfault constructor, COpy constructors
	//(print information of the driver)
public:
	Driver()
	{
		licenceList = new char* [8];
		for (int i = 0; i < 8; i++)
		{
			licenceList[i] = new char;
		}
		driverId = 0;
		noOfLicences = 0;
		overallRanking = 0;
		salary = 0;
		experience = 0;
		status = 0;
		serviceHistory = new Service * [10];
		for (int i = 0; i < 10; i++)
		{
			serviceHistory[i] = new Service;
		}
	}
	~Driver()
	{
		for (int i = 0; i < 8; i++)
		{
			delete[]licenceList[i];
		}
		delete[]licenceList;
	}
	Driver(Driver& D)
	{
		driverId = D.driverId;
		noOfLicences = D.driverId;
		overallRanking = D.overallRanking;
		salary = D.salary;
		experience = D.experience;
		status = D.status;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				licenceList[i] = D.licenceList[i];
			}
		}
	}
	void setDriverInfo(int dId, char** lic_list, int noOflic, float rank, float sal, int exp, int stat)
	{
		driverId = dId;
		noOfLicences = noOflic;
		overallRanking = rank;
		salary = sal;
		experience = exp;
		status = stat;
		for (int i = 0; i < 1; i++)
		{
			//	for (int j = 0; j < 1; j++)
				//{
			licenceList[i] = lic_list[i];
			//	}
		}
	}
	void setFileCountDriver(int fileCount)
	{
		fileCountDriv = fileCount;
	}

	void operator=(Driver& D)
	{
		driverId = D.driverId;
		noOfLicences = D.driverId;
		overallRanking = D.overallRanking;
		salary = D.salary;
		experience = D.experience;
		status = D.status;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				licenceList[i][j] = D.licenceList[i][j];
			}
		}
	}
	void printDriversInfo()
	{
		boldCyan();
		cout << "The Drivers ID is: " << driverId << endl;
		Person::printPersonsInfo();
		cout << "No of Licences: " << noOfLicences << endl;
		cout << "Licences Names: ";
		int size = 0;
		/*for(int i=0;i<1;i++)
			size = strlen(licenceList[i]);*/
		for (int i = 0; i < 1; i++)
			cout << licenceList[i];
		cout << endl;
		cout << "Salary: " << salary << endl;
		cout << "Overall Ranking: " << overallRanking << endl;
		cout << "Experienced Years: " << experience << endl;
		cout << "Status of the Driver(1 for free, 2 for booked, 3 for canceled): " << status << endl;

	}
	int getDriverId()
	{
		return driverId;
	}
	float getoverallRanking()
	{
		return overallRanking;
	}
	int getDriverDetailsFileCount()
	{
		return fileCountDriv;
	}
	int getStatusOfDriver()
	{
		return status;
	}
};

class Feature
{
	int featureId;
	char* description;
	float cost;
public:
	Feature()
	{
		featureId = 0;
		description = new char[100];
		cost = 0;
	}
	~Feature()
	{
		delete[]description;
	}
	void setFeaturesForVehicle(int fId, char descrip[], float cost)
	{
		featureId = fId;
		/*int sizeOfDesc = getSizeOfcharArray(descrip);
		for (int i = 0; i < sizeOfDesc; i++)
		{
			description[i] = descrip[i];
		}*/
		strcpy(description, descrip);
		this->cost = cost;
	}
	void printFeaturesForVehicle()
	{
		cout << "Feature ID: " << featureId << endl;
		cout << "Description: ";
		int sizeOfDes = getSizeOfcharArray(description);
		for (int i = 0; i < sizeOfDes; i++)
		{
			cout << description[i];
		}
		cout << endl;
		cout << "Cost: " << cost << endl;
	}
};

class Vehicle
{
	int vehicleId;
	int registrationNo;
	float avgMileage;
	char* licenceType;
	bool status; //for booking
	char* fuelType;
	float overallRanking;
	Date manufacturingDate;
	Feature* list;
	Service** serviceHistory;
	//add services address in the array for tracking complete information of services
public:
	Vehicle()
	{
		vehicleId = 0;
		registrationNo = 0;
		avgMileage = 0;
		licenceType = new char[50];
		status = false; //for booking
		fuelType = new char[50];
		overallRanking;
		list = new Feature;
		serviceHistory = new Service * [20];
		for (int i = 0; i < 20; i++)
		{
			serviceHistory[i] = new Service;
		}
	}
	~Vehicle()
	{
		delete[]licenceType;
		delete[]fuelType;
		for (int i = 0; i < 20; i++)
		{
			delete[]serviceHistory[i];
		}
		delete[]serviceHistory;
	}
	void setVehicleDetials(int vId, int regNo, float mileage, char lic_type[], bool stat, char fuel_type[], float rank, int day, int month, int year, int fId, char descrip[], float cost)
	{
		vehicleId = vId;
		registrationNo = regNo;
		avgMileage = mileage;
		strcpy(licenceType, lic_type);
		status = stat;
		strcpy(fuelType, fuel_type);
		overallRanking = rank;
		manufacturingDate.setDateOfBirth(day, month, year);
		list->setFeaturesForVehicle(fId, descrip, cost);

	}
	void setVehicleServices(int sID, int cID, int dID, int vID, char sour[], char dest[], float fuel, float dis, bool stat, int day, int month, int year, int hr, int min, int sec)
	{
		for (int i = 0; i < 1; i++)
		{
			serviceHistory[i][0].setServices(sID, cID, dID, vID, sour, dest, fuel, dis, stat, day, month, year, hr, min, sec);
		}
	}
	void printVehicleDetails()
	{
		boldRed();
		cout << "The Vehicle ID is: " << vehicleId << endl;
		cout << "Registration No: " << registrationNo << endl;
		cout << "Average Mileage: " << avgMileage << endl;
		cout << "Licence Type (required for the Vehicle): ";
		int sizeOfLic = getSizeOfcharArray(licenceType);
		for (int i = 0; i < sizeOfLic; i++)
		{
			cout << licenceType[i];
		}
		cout << endl;
		cout << "Fuel Type (required for the Vehicle): ";
		int sizeOfFuel = getSizeOfcharArray(fuelType);
		for (int i = 0; i < sizeOfFuel; i++)
		{
			cout << fuelType[i];
		}
		cout << endl;
		cout << "Status of the Vehicle: " << status << endl;
		cout << "OverAll Ranking: " << overallRanking << endl;
		manufacturingDate.printDateOfBirth();
		list->printFeaturesForVehicle();
	}
	void printServicesOfVehicle()
	{
		for (int i = 0; i < 1; i++)
		{
			serviceHistory[i][0].printServices();
		}
	}
	bool getStatusForVehi()
	{
		return status;
	}
	float getRankForVehi()
	{
		return overallRanking;
	}
};

void writeInRideFileComplete(ofstream& write, int& noOfPas, char r_type[], float& d_Rank, float& v_Rank
	, int& sID, int& cID, int& dID, int& vID, char sour[], char dest[], float& fuel, float& dis, bool& stat,
	int& day, int& month, int& year, int& hr, int& min, int& sec, bool& bookRide)
{
	write << endl;
	write << sID;
	write << "/";
	write << cID;
	write << "/";
	write << dID;
	write << "/";
	write << vID;
	write << "/";
	write << sour;
	write << "/";
	write << dest;
	write << "/";
	write << day;
	write << "/";
	write << month;
	write << "/";
	write << year;
	write << "/";
	write << hr;
	write << "/";
	write << min;
	write << "/";
	write << sec;
	write << "/";
	write << fuel;
	write << "/";
	write << dis;
	write << "/";
	write << stat;
	write << "/";
	write << noOfPas;
	write << "/";
	write << r_type;
	write << "/";
	write << d_Rank;
	write << "/";
	write << v_Rank;
	write << "/";
	write << bookRide;

}
void readRideCompleteFile(ifstream& read, int& noOfPas, char r_type[], float& d_Rank, float& v_Rank
	, int& sID, int& cID, int& dID, int& vID, char sour[], char dest[], float& fuel, float& dis, bool& stat,
	int& day, int& month, int& year, int& hr, int& min, int& sec, bool& bookRide)
{
	char trash;
	read >> sID;
	read >> trash;
	read >> cID;
	read >> trash;
	read >> dID;
	read >> trash;
	read >> vID;
	read >> trash;
	read.getline(sour, 100, '/');
	read.getline(dest, 100, '/');
	read >> day;
	read >> trash;
	read >> month;
	read >> trash;
	read >> year;
	read >> trash;
	read >> hr;
	read >> trash;
	read >> min;
	read >> trash;
	read >> sec;
	read >> trash;
	read >> fuel;
	read >> trash;
	read >> dis;
	read >> trash;
	read >> stat;
	read >> trash;
	read >> noOfPas;
	read >> trash;
	read.getline(r_type, 50, '/');
	read >> d_Rank;
	read >> trash;
	read >> v_Rank;
	read >> trash;
	read >> bookRide;

}
void setRideCompleteFile(Ride* R, int& noOfPas, char r_type[], float& d_Rank, float& v_Rank, int& sID
	, int& cID, int& dID, int& vID, char sour[], char dest[], float& fuel, float& dis, bool& stat,
	int& day, int& month, int& year, int& hr, int& min, int& sec, bool& bookRide)
{
	static int i = 0;
	R[i].setRideInfo(noOfPas, r_type, d_Rank, v_Rank, sID, cID, dID, vID, sour, dest, fuel, dis,
		stat, day, month, year, hr, min, sec, bookRide);
	i++;
}

void readDeliveryCompleteFile(ifstream& read, float& goodW, char goodT[], int& sID, int& cID, int& dID, int& vID, char sour[], char dest[], float& fuel, float& dis, bool& stat,
	int& day, int& month, int& year, int& hr, int& min, int& sec, bool& bookDeli)
{
	char trash;
	read >> sID;
	read >> trash;
	read >> cID;
	read >> trash;
	read >> dID;
	read >> trash;
	read >> vID;
	read >> trash;
	read.getline(sour, 100, '/');
	read.getline(dest, 100, '/');
	read >> day;
	read >> trash;
	read >> month;
	read >> trash;
	read >> year;
	read >> trash;
	read >> hr;
	read >> trash;
	read >> min;
	read >> trash;
	read >> sec;
	read >> trash;
	read >> fuel;
	read >> trash;
	read >> dis;
	read >> trash;
	read >> stat;
	read >> trash;
	read.getline(goodT, 200, '/');
	read >> goodW;
	read >> trash;
	read >> bookDeli;
}
void setDeliveryCompleteFile(Delivery* Deli, float& goodW, char goodT[], int& sID, int& cID, int& dID, int& vID, char sour[],
	char dest[], float& fuel, float& dis, bool& stat, int& day, int& month, int& year,
	int& hr, int& min, int& sec, bool& bookDeli)
{
	static int i = 0;
	Deli[i].setDeliveryInfo(goodW, goodT, sID, cID, dID, vID, sour, dest, fuel, dis,
		stat, day, month, year, hr, min, sec, bookDeli);
	i++;
}
void writeDeliveryCompleteFile(ofstream& write, float& goodW, char goodT[], int& sID, int& cID, int& dID, int& vID, char sour[], char dest[], float& fuel, float& dis, bool& stat,
	int& day, int& month, int& year, int& hr, int& min, int& sec, bool& bookDeli)
{
	write << endl;
	write << sID;
	write << "/";
	write << cID;
	write << "/";
	write << dID;
	write << "/";
	write << vID;
	write << "/";
	write << sour;
	write << "/";
	write << dest;
	write << "/";
	write << day;
	write << "/";
	write << month;
	write << "/";
	write << year;
	write << "/";
	write << hr;
	write << "/";
	write << min;
	write << "/";
	write << sec;
	write << "/";
	write << fuel;
	write << "/";
	write << dis;
	write << "/";
	write << stat;
	write << "/";
	write << goodT;
	write << "/";
	write << goodW;
}

float fairCalculationForRide(Ride* R, float fuel, float dis)
{
	float tax = 0;
	/*for (int i = 0; i < fileCountRide; i++)
	{*/
	static int i = 0;
	if (dis >= 300 && fuel >= 150)
	{
		tax = 300 * 150;
	}
	else if ((dis <= 300 && dis >= 150) && fuel <= 150)
	{
		tax = 200 * 150;
	}
	else if ((dis <= 150 && dis >= 100) && fuel <= 150)
	{
		tax = 100 * 150;
	}
	else if ((dis <= 100 && dis >= 50) && fuel <= 150)
	{
		tax = 50 * 150;
	}
	else if ((dis <= 50 && dis >= 30) && fuel <= 150)
	{
		tax = 30 * 150;
	}
	else if ((dis <= 30 && dis >= 10) && fuel <= 150)
	{
		tax = 10 * 150;
	}
	else if ((dis <= 10 && dis >= 0) && fuel <= 150)
	{
		tax = 5 * 150;
	}


	cout << "--------------------------------------------------------------------------------------------\n";
	cout << "\t\t\tFOR YOUR DESIRED SERVICE THE CHARGES ARE\n\t\t\tOnly R.s:";
	cout << tax;
	return tax;
}
void writingInRideFile(Ride* R, ofstream& write, int inp_dId, int inp_vId)
{
	int noOfPass;
	char r_Type[50];
	float d_Rank;
	float v_Rank;
	char source[100];
	char destination[100];
	float distance;
	bool status;
	float fuelRate;
	srand(time(0));
	int sID = rand();
	int cID;
	int dID = inp_dId;
	int vID = inp_vId;
	int day;
	int month;
	int year;
	int hr;
	int min;
	int sec;
	bool bookRide;

	write << endl;
	write << sID;
	write << "/";
	cout << "Enter Customer ID: ";
	cin >> cID;
	write << cID;
	write << "/";

	write << dID;
	write << "/";

	write << vID;
	write << "/";

	cout << "Enter Your Departure Location: ";
	cin.ignore();
	cin.getline(source, 100);
	write << source;
	write << "/";

	cout << "Enter Your Destination Location: ";
	cin.getline(destination, 100);
	write << destination;
	write << "/";

	cout << "Enter Date(Format: day/month/year): ";
	cin >> day >> month >> year;
	write << day;
	write << "/";
	write << month;
	write << "/";
	write << year;
	write << "/";

	cout << "Enter Time (Format: hr/min/sec): ";
	cin >> hr >> min >> sec;
	write << hr;
	write << "/";
	write << min;
	write << "/";
	write << sec;
	write << "/";

	cout << "Enter Fuel Rate: ";
	cin >> fuelRate;
	write << fuelRate;
	write << "/";

	cout << "Enter the Total Distance Travelled: ";
	cin >> distance;
	write << distance;
	write << "/";

	cout << "Enter the Status (Format: 0 if pending || 1 if complete): ";
	cin >> status;
	write << status;
	write << "/";

	cout << "Enter Number of Passengers: ";
	cin >> noOfPass;
	write << noOfPass;
	write << "/";

	cout << "Enter Ride Type (Format->Enter InterCity or IntraCity): ";
	cin.ignore();
	cin.getline(r_Type, 50);
	write << r_Type;
	write << "/";

	cout << "Enter Rank you want to give to the Driver: (AS A FEEDBACK)";
	cin >> d_Rank;
	write << d_Rank;
	write << "/";
	cout << "Enter Rank you want to give to the Vehicle: (AS A FEEDBACK)";
	cin >> v_Rank;
	write << v_Rank;
	write << "/";

	cout << "Enter Status of Book Ride: ";
	cin >> bookRide;
	write << bookRide;

	fairCalculationForRide(R, fuelRate, distance);
	write.close();
}

//void writingInServicesFile(ofstream& write)
//{
//	char source[100];
//	char destination[100];
//	float distance;
//	bool status;
//	float fuelRate;
//	int cID;
//	int dID;
//	int vID;
//	int day;
//	int month;
//	int year;
//	int hr;
//	int min;
//	int sec;
//
//	write << endl;
//	cout << "Enter Customer ID: ";
//	cin >> cID;
//	write << cID;
//	write << "/";
//
//	cout << "Enter Drivers ID: ";
//	cin >> dID;
//	write << dID;
//	write << "/";
//
//	cout << "Enter Vehicles ID: ";
//	cin >> vID;
//	write << vID;
//	write << "/";
//
//	cout << "Enter Your Departure Location: ";
//	cin.ignore();
//	cin.getline(source, 100);
//	write << source;
//	write << "/";
//
//	cout << "Enter Your Destination Location: ";
//	cin.getline(destination, 100);
//	write << destination;
//	write << "/";
//
//	cout << "Enter Date(Format: day/month/year): ";
//	cin >> day >> month >> year;
//	write << day;
//	write << "/";
//	write << month;
//	write << "/";
//	write << year;
//	write << "/";
//
//	cout << "Enter Time (Format: hr/min/sec): ";
//	cin >> hr >> min >> sec;
//	write << hr;
//	write << "/";
//	write << min;
//	write << "/";
//	write << sec;
//	write << "/";
//
//	cout << "Enter Fuel Rate: ";
//	cin >> fuelRate;
//	write << fuelRate;
//	write << "/";
//
//	cout << "Enter the Total Distance Travelled: ";
//	cin >> distance;
//	write << distance;
//	write << "/";
//
//	cout << "Enter the Status (Format: 0 if pending || 1 if complete): ";
//	cin >> status;
//	write << status;
//
//	write.close();
//}
//void readServicesFile(ifstream& readServ, int& cID, int& dID, int& vID,
//	char sour[], char dest[], float& fuel, float& dis, bool& stat, char& trash, int& day,
//	int& month, int& year, int& hr, int& min, int& sec)
//{
//	readServ >> cID;
//	readServ >> trash;
//	readServ >> dID;
//	readServ >> trash;
//	readServ >> vID;
//	readServ >> trash;
//	readServ.getline(sour, 100, '/');
//	readServ.getline(dest, 100, '/');
//	readServ >> day;
//	readServ >> trash;
//	readServ >> month;
//	readServ >> trash;
//	readServ >> year;
//	readServ >> trash;
//	readServ >> hr;
//	readServ >> trash;
//	readServ >> min;
//	readServ >> trash;
//	readServ >> sec;
//	readServ >> trash;
//	readServ >> fuel;
//	readServ >> trash;
//	readServ >> dis;
//	readServ >> trash;
//	readServ >> stat;
//}
void readCustomerDetailsFileComplete(ifstream& read, int& cId, char fName[], char lName[], int& age,
	int& nId, int& day, int& month, int& year, char& trash)
{
	read >> cId;
	read >> trash;
	read.getline(fName, 100, ',');
	read.getline(lName, 100, ',');
	read >> age;
	read >> trash;
	read >> nId;
	read >> trash;
	read >> day;
	read >> trash;
	read >> month;
	read >> trash;
	read >> year;
}
void setCustomerDetailsFileComplete(Customer* C, int& cId, char fName[], char lName[], int& age,
	int& nId, int& day, int& month, int& year)
{
	static int i = 0;
	C[i].setNewCustomer(cId, fName, lName, age, nId, day, month, year);
	i++;

}
void newCustomerFunctionality(Customer& C)
{
	ofstream custDetails;
	cout << "\n\n\t\t\tHELLO SIR !! WE NEED SOME DETAILS FOR YOUR REGISTRATION\n";
	custDetails.open("CustomerDetails.txt", ios::app);
	if (custDetails.is_open())
	{
		char fName[100];
		char lName[100];
		int day, month, year;
		int nId;
		int age;
		int custCount = 0;
		srand(time(0));
		custCount = rand();
		custDetails << endl;
		custDetails << custCount;
		custDetails << "/";

		cout << "Enter First Name: ";
		cin.getline(fName, 100);
		custDetails << fName;
		custDetails << ",";

		cout << "Enter Second Name: ";
		cin.getline(lName, 100);
		custDetails << lName;
		custDetails << ",";

		cout << "Enter your Age: ";
		cin >> age;
		custDetails << age;
		custDetails << "/";

		cout << "Enter National ID: ";
		cin >> nId;
		custDetails << nId;
		custDetails << "/";

		cout << "Enter your Date of Birth: (Format: day/month/year)\n";
		cin >> day >> month >> year;
		custDetails << day;
		custDetails << "/";
		custDetails << month;
		custDetails << "/";
		custDetails << year;

	}
	else
	{
		cout << "FILE IS UNABLE TO OPEN\n";
	}


}
//void newCustomerServiceRequest()
//{
//	ofstream custServDetails;
//	custServDetails.open("Services.txt", ios::app);
//	if (custServDetails.is_open())
//	{
//		writingInServicesFile(custServDetails);
//	}
//	else
//	{
//		cout << "SERVICES FILE WAS UNABLE TO OPEN\n";
//	}
//}

void setDriverDetailsCompleteFile(Driver* D, int& driversId, char** lic_list, int& noOfLic, float& overallRank,
	float& sal, int& exp, int& status, int& age, int& nId, char fName[], char lName[], int& day, int& month, int& year)
{
	static int i = 0;
	D[i].setDriverInfo(driversId, lic_list, noOfLic, overallRank, sal, exp, status);
	D[i].setCustomerAge_Nid(age, nId, fName, lName, day, month, year);
	i++;
}
void writeDriverDetailsCompleteFile(ofstream& write, int& driversId, char** lic_list, int& noOfLic, float& overallRank, float& sal, int& exp, int& status,
	int& age, int& nId, char fName[], char lName[], int& day, int& month, int& year)
{
	write << endl;
	write << driversId;
	write << "/";
	write << fName;
	write << ",";
	write << lName;
	write << "/";
	write << age;
	write << "/";
	write << nId;
	write << "/";
	write << day;
	write << "/";
	write << month;
	write << "/";
	write << year;
	write << "/";
	for (int i = 0; i < 1; i++)
	{
		write << lic_list[i];
		write << "/";
	}
	write << ",";
	write << noOfLic;
	write << "/";
	write << overallRank;
	write << "/";
	write << sal;
	write << "/";
	write << exp;
	write << "/";
	write << status;
}
void readDriverDetailsFile(ifstream& read, int& driversId, char** lic_list, int& noOfLic, float& overallRank, float& sal, int& exp, int& status,
	int& age, int& nId, char fName[], char lName[], int& day, int& month, int& year, char& trash)
{
	read >> driversId;
	read >> trash;
	read.getline(fName, 100, ',');
	read.getline(lName, 100, '/');
	read >> age;
	read >> trash;
	read >> nId;
	read >> trash;
	read >> day;
	read >> trash;
	read >> month;
	read >> trash;
	read >> year;
	read >> trash;
	for (int i = 0; i < 1; i++)
		read.getline(lic_list[i], 50, ',');
	read >> noOfLic;
	read >> trash;
	read >> overallRank;
	read >> trash;
	read >> sal;
	read >> trash;
	read >> exp;
	read >> trash;
	read >> status;
}
void addDriverFunctionality(Driver& D)
{
	ofstream drivDetails;
	cout << "\t\t\tHello !! We need Some of your Details to register as a Driver in the Company\n ";
	drivDetails.open("DriverDetails.txt", ios::app);
	if (drivDetails.is_open())
	{
		int dId = 1;
		char** lic_list;
		int noOfLic;
		float overallRank;
		float sal;
		int exp;
		int status;
		char fName[100];
		char lName[100];
		int day, month, year;
		int nId;
		int age;

		lic_list = new char* [8];
		for (int i = 0; i < 8; i++)
		{
			lic_list[i] = new char;
		}
		drivDetails << endl;
		srand(time(0));
		dId = rand() / 2;
		drivDetails << dId;
		drivDetails << "/";

		cout << "Enter First Name: ";
		cin.ignore();
		cin.getline(fName, 100);
		drivDetails << fName;
		drivDetails << ",";

		cout << "Enter Second Name: ";
		cin.getline(lName, 100);
		drivDetails << lName;
		drivDetails << "/";

		cout << "Enter your Age: ";
		cin >> age;
		drivDetails << age;
		drivDetails << "/";

		cout << "Enter National ID: ";
		cin >> nId;
		drivDetails << nId;
		drivDetails << "/";

		cout << "Enter your Date of Birth: (Format: day/month/year)\n";
		cin >> day >> month >> year;
		drivDetails << day;
		drivDetails << "/";
		drivDetails << month;
		drivDetails << "/";
		drivDetails << year;

		//lic list
		cout << "\t\t\tFORMAT: Car Driving Licence <-> MotorBike <-> LTV <-> HTV <-> Tractor <-> PSV <-> International\n\t\t\t";
		cout << "You Can Enter 0 (zero) to terminate the input when you are done filling your licence list\n";
		bool terminate = false;
		cout << "Enter the Categories of Licenses that you own\nLicence List: \n";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				cin.getline(lic_list[i], 100);
				if (*lic_list[i] == 48)
				{
					terminate = true;
					break;
				}
				else
				{
					drivDetails << lic_list[i];
					drivDetails << "/";
				}
			}
			if (terminate)
			{
				break;
			}
		}
		drivDetails << ',';
		cout << "Enter Number of Licences that you have: ";
		cin >> noOfLic;
		drivDetails << noOfLic;
		drivDetails << "/";

		cout << "Enter Over All ranking in your driving career: ";
		cin >> overallRank;
		drivDetails << overallRank;
		drivDetails << "/";

		cout << "Enter Salary that you are getting: ";
		cin >> sal;
		drivDetails << sal;
		drivDetails << "/";

		cout << "Enter Number of Experience Years: ";
		cin >> exp;
		drivDetails << exp;
		drivDetails << "/";

		cout << "Enter Status true or False: ";
		cin >> status;
		drivDetails << status;
		drivDetails.close();
	}
	else
	{
		cout << "DRIVER DETAILS FILE WAS UNABLE TO OPEN\n";
	}
	/*ofstream servDetails;
	servDetails.open("Services.txt");
	if (servDetails.is_open())
	{
		writingInServicesFile(servDetails);
	}
	else
	{
		cout << "SERVICES FILE WAS UNABLE TO OPEN\n";
	}*/

}
void removeDriverFunctionality(Driver* D)
{
	int driversId;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int status;
	char fName[100];
	char lName[100];
	int day, month, year;
	int nId;
	int age;
	char trash;
	int driId;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}
	ofstream write;
	write.open("DriverDetailsUpdated.txt", ios::app);
	ifstream read;
	read.open("DriverDetails.txt");
	cout << "Enter Drivers ID: ";
	cin >> driId;
	if (read.is_open())
	{
		while (!read.eof())
		{
			read >> driversId;
			read >> trash;
			read.getline(fName, 100, ',');
			read.getline(lName, 100, '/');
			read >> age;
			read >> trash;
			read >> nId;
			read >> trash;
			read >> day;
			read >> trash;
			read >> month;
			read >> trash;
			read >> year;
			read >> trash;
			for (int i = 0; i < 1; i++)
				read.getline(lic_list[i], 50, ',');
			read >> noOfLic;
			read >> trash;
			read >> overallRank;
			read >> trash;
			read >> sal;
			read >> trash;
			read >> exp;
			read >> trash;
			read >> status;
			/*static int i = 0;
			D[i].setDriverInfo(driversId, lic_list, noOfLic, overallRank, sal, exp, status);*/

			//deleteContentFromTheFile(read);


			if (driId != driversId)
			{
				write << endl;
				write << driversId;
				write << "/";
				write << fName;
				write << ",";
				write << lName;
				write << "/";
				write << age;
				write << "/";
				write << nId;
				write << "/";
				write << day;
				write << "/";
				write << month;
				write << "/";
				write << year;
				write << "/";
				for (int i = 0; i < 1; i++)
				{
					write << lic_list[i];
				}
				write << ",";
				write << noOfLic;
				write << "/";
				write << overallRank;
				write << "/";
				write << sal;
				write << "/";
				write << exp;
				write << "/";
				write << status;

			}
		}
		read.close();
		write.close();
		remove("DriverDetails.txt");
		rename("DriverDetailsUpdated.txt", "DriverDetails.txt");
	}
	else
	{
		cout << "DRIVER DETAILS FILE WAS UNABLE TO OPEN\n";
	}
}

void readVehicleDetailsCompleteFile(ifstream& readVeh, int& vId, int& regNo, float& mileage, char lic_type[], bool& stat, char fuel_type[], float& rank,
	int& day, int& month, int& year, int& fId, char descrip[], float& cost, char& trash)
{
	readVeh >> vId;
	readVeh >> trash;
	readVeh >> regNo;
	readVeh >> trash;
	readVeh >> mileage;
	readVeh >> trash;
	readVeh.getline(lic_type, 50, '/');
	readVeh.getline(fuel_type, 50, '/');
	readVeh >> rank;
	readVeh >> trash;
	readVeh >> stat;
	readVeh >> trash;
	readVeh >> day;
	readVeh >> trash;
	readVeh >> month;
	readVeh >> trash;
	readVeh >> year;
	readVeh >> trash;
	readVeh >> fId;
	readVeh >> trash;
	readVeh.getline(descrip, 100, '/');
	readVeh >> cost;
}
void setVehicleDetailsCompleteFile(Vehicle* V, int& vId, int& regNo, float& mileage, char lic_type[], bool& stat, char fuel_type[],
	float& rank, int& day, int& month, int& year, int& fId, char descrip[], float& cost)
{
	static int i = 0;
	V[i].setVehicleDetials(vId, regNo, mileage, lic_type, stat, fuel_type, rank, day, month, year, fId, descrip, cost);
	i++;
}
void writeVehicleDetailsCompleteFile(ofstream& vehiDetails, int& vId, int& regNo, float& mileage, char lic_type[], bool& stat, char fuel_type[], float& rank,
	int& day, int& month, int& year, int& fId, char descrip[], float& cost, char trash)
{
	vehiDetails << vId;
	vehiDetails << "/";
	vehiDetails << regNo;
	vehiDetails << "/";
	vehiDetails << mileage;
	vehiDetails << "/";
	vehiDetails << lic_type;
	vehiDetails << ",";
	vehiDetails << "/";
	vehiDetails << fuel_type;
	vehiDetails << ",";
	vehiDetails << "/";
	vehiDetails << rank;
	vehiDetails << "/";
	vehiDetails << stat;
	vehiDetails << "/";
	vehiDetails << day;
	vehiDetails << "/";
	vehiDetails << month;
	vehiDetails << "/";
	vehiDetails << year;
	vehiDetails << "/";
	vehiDetails << fId;
	vehiDetails << "/";
	vehiDetails << descrip;
	vehiDetails << "/";
	vehiDetails << cost;


}
void addVehicleFunctionality()
{
	ofstream vehiDetails;
	cout << "\t\t\tHello !! Register A Vehicle here\n";
	vehiDetails.open("VehicleDetails.txt", ios::app);
	if (vehiDetails.is_open())
	{
		int vId;
		int regNo;
		float mileage;
		char* lic_type = new char[20];
		bool status;
		char* fuel_type = new char[10];
		float rank;
		int day;
		int month;
		int year;
		int fId;
		char descrip[100];
		float cost;
		srand(time(0));
		vId = rand();
		vehiDetails << endl;
		vehiDetails << vId;
		vehiDetails << "/";

		cout << "Enter Registration of the Vehicle: ";
		cin >> regNo;
		vehiDetails << regNo;
		vehiDetails << "/";

		cout << "Enter Current Mileage of the Vehicle (Unit L/100 km): ";
		cin >> mileage;
		vehiDetails << mileage;
		vehiDetails << "/";

		cout << "LTV, HTV etc are Some catergories we like to have\nEnter 0 (zero) to terminate when you are done\n";
		cout << "Enter Licence Type (Such as LTV, HTV, International etc) required for the Vehicle: ";
		for (int i = 0; i < 20; i++)
		{
			cin.getline(lic_type, 50);
			if (*lic_type == 48)
			{
				break;
			}
			else
			{
				vehiDetails << lic_type;
				vehiDetails << ",";
			}

		}
		vehiDetails << "/";
		cout << "\t\t\tThree Types of Fuel Types are there Petrol <-> Diesel <-> CNG\n";
		cout << "\t\t\tEnter 0 (zero) to terminate when you are done\nYou can add multiple Types\n";
		cout << "Enter Fuel Type of the Vehicle: ";
		for (int i = 0; i < 10; i++)
		{
			cin.getline(fuel_type, 50);
			if (*fuel_type == 48)
			{
				break;
			}
			else
			{
				vehiDetails << fuel_type;
				vehiDetails << ",";
			}
		}
		vehiDetails << "/";
		cout << "Enter Overall Ranking of the Vehicle: ";
		cin >> rank;
		vehiDetails << rank;
		vehiDetails << "/";

		cout << "Enter Status of the Vehicle (True or False): ";
		cin >> status;
		vehiDetails << status;
		vehiDetails << "/";

		cout << "Enter Manufacturing Date: (Format: day/month/year): ";
		cin >> day >> month >> year;
		vehiDetails << day;
		vehiDetails << "/";
		vehiDetails << month;
		vehiDetails << "/";
		vehiDetails << year;
		vehiDetails << "/";

		fId = rand();
		vehiDetails << fId;
		vehiDetails << "/";

		cout << "Enter Description for the Vehicle: ";
		cin.ignore();
		cin.getline(descrip, 100);
		vehiDetails << descrip;
		vehiDetails << "/";

		cout << "Enter the Cost: ";
		cin >> cost;
		vehiDetails << cost;

		vehiDetails.close();
	}
	else
	{
		cout << "VEHICLE DETAILS FILE WAS UNABLE TO OPEN\n";
	}
}
void removeVehicleFunctionality()
{
	int vId;
	int regNo;
	float mileage;
	char* lic_type = new char[20];
	bool status;
	char* fuel_type = new char[10];
	float rank;
	int day;
	int month;
	int year;
	char trash;
	int ID_veh;
	int fId;
	char descrip[100];
	float cost;
	ofstream write;
	write.open("VehicleDetailsUpdated.txt", ios::app);
	ifstream read;
	read.open("VehicleDetails.txt");
	cout << "Enter Vehicle ID to remove: ";
	cin >> ID_veh;
	if (read.is_open())
	{
		while (!read.eof())
		{
			read >> vId;
			read >> trash;
			read >> regNo;
			read >> trash;
			read >> mileage;
			read >> trash;
			read.getline(lic_type, 50, '/');
			read.getline(fuel_type, 50, '/');
			read >> rank;
			read >> trash;
			read >> status;
			read >> trash;
			read >> day;
			read >> trash;
			read >> month;
			read >> trash;
			read >> year;
			read >> trash;
			read >> fId;
			read >> trash;
			read.getline(descrip, 100, '/');
			read >> cost;
			if (ID_veh != vId)
			{
				write << endl;
				write << vId;
				write << "/";
				write << regNo;
				write << "/";
				write << mileage;
				write << "/";
				int sizeOflic_type = getSizeOfcharArray(lic_type);
				for (int i = 0; i < sizeOflic_type; i++)
					write << lic_type[i];
				write << "/";
				int sizeOffuel_type = getSizeOfcharArray(fuel_type);
				for (int i = 0; i < sizeOffuel_type; i++)
					write << fuel_type[i];
				write << "/";
				write << rank;
				write << "/";
				write << day;
				write << "/";
				write << month;
				write << "/";
				write << year;
				write << "/";
				write << fId;
				write << "/";
				write << descrip;
				write << "/";
				write << cost;
			}
		}
		read.close();
		write.close();
		remove("VehicleDetails.txt");
		rename("VehicleDetailsUpdated.txt", "VehicleDetails.txt");
	}
}
void addVehicleServices()
{
	ofstream servVehicles;
	servVehicles.open("Services.txt", ios::app);
	if (servVehicles.is_open())
	{

		char* source = new char[100];
		char* destination = new char[100];
		float distance;
		bool status;
		float fuelRate;
		int cID;
		int dID;
		int vID;

		servVehicles << endl;
		cout << "Enter Customer ID: ";
		cin >> cID;
		servVehicles << cID;
		servVehicles << "/";

		cout << "Enter Drivers ID: ";
		cin >> dID;
		servVehicles << dID;
		servVehicles << "/";

		cout << "Enter Vehicles ID: ";
		cin >> vID;
		servVehicles << vID;
		servVehicles << "/";

		cout << "Enter Your Departure Location: ";
		cin.ignore();
		cin.getline(source, 100);
		servVehicles << source;
		servVehicles << "/";

		cout << "Enter Your Destination Location: ";
		cin.getline(destination, 100);
		servVehicles << destination;
		servVehicles << "/";

		cout << "Enter Fuel Rate: ";
		cin >> fuelRate;
		servVehicles << fuelRate;
		servVehicles << "/";

		cout << "Enter the Total Distance Travelled: ";
		cin >> distance;
		servVehicles << distance;
		servVehicles << "/";

		cout << "Enter the Status (Format: 0 if pending || 1 if complete): ";
		cin >> status;
		servVehicles << status;


	}
	else
	{
		cout << "SERVICES FILE WAS UNABLE TO OPEN\n";
	}
}
void readVehicleDetailsFile(Vehicle* V)
{
	ifstream readVeh;
	readVeh.open("VehicleDetails.txt");
	if (readVeh.is_open())
	{
		int fileCount = 0;
		int vId = 0;
		int regNo = 0;
		float mileage = 0;
		char lic_type[50];
		bool status = true;
		char fuel_type[50];
		float rank = 0;
		int day = 0;
		int month = 0;
		int year = 0;
		int fId;
		char descrip[100];
		float cost;
		char trash;
		while (!readVeh.eof())
		{
			readVeh >> vId;
			readVeh >> trash;
			readVeh >> regNo;
			readVeh >> trash;
			readVeh >> mileage;
			readVeh >> trash;
			readVeh.getline(lic_type, 50, '/');
			readVeh.getline(fuel_type, 50, '/');
			readVeh >> rank;
			readVeh >> trash;
			readVeh >> status;
			readVeh >> trash;
			readVeh >> day;
			readVeh >> trash;
			readVeh >> month;
			readVeh >> trash;
			readVeh >> year;
			readVeh >> trash;
			readVeh >> fId;
			readVeh >> trash;
			readVeh.getline(descrip, 100, '/');
			readVeh >> cost;

			fileCount++;
			static int i = 0;
			V[i].setVehicleDetials(vId, regNo, mileage, lic_type, status, fuel_type, rank, day, month, year, fId, descrip, cost);
			i++;
		}
		for (int i = 0; i < fileCount; i++)
		{
			cout << "--------------------------------------------------------------------------------------------\n";
			cout << "\t\t\tVehicle " << i + 1 << endl;
			V[i].printVehicleDetails();
		}
	}
}
void readVehicleServicesFile(Ride* R, Delivery* Deli)
{
	//variables for ride
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int sIDOfR;
	int cIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int noOfPass;
	char r_Type[50];
	float d_Rank;
	float v_Rank;
	//variables for delivery
	float goodW;
	char goodT[200];
	bool bookDeli;
	/*char source[100];
	char destination[100];
	float distance;
	bool status;
	float fuelRate;
	int cID;
	int dID;
	int vID;
	int day;
	int month;
	int year;
	int hr;
	int min;
	int sec;*/
	srand(time(0));
	sIDOfR = rand();
	int checkID;
	cout << "Enter Vehicle ID for which you want to get Details: ";
	cin >> checkID;
	ifstream readRide;
	readRide.open("Ride.txt");
	if (readRide.is_open())
	{
		while (!readRide.eof())
		{
			readRideCompleteFile(readRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			static int i = 0;
			if (checkID == vIDOfR)
			{

				R[i].setRideInfo(noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
					, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
				R[i].printRideInfo();
				i++;
			}
		}

	}
	else
	{
		cout << "RIDE FILE WAS UNABLE TO OPEN\n";
	}
	ifstream readDeli;
	readDeli.open("Delivery.txt");
	if (readDeli.is_open())
	{
		while (!readDeli.eof())
		{
			readDeliveryCompleteFile(readDeli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
			static int i = 0;
			if (checkID == vIDOfR)
			{
				Deli[i].setDeliveryInfo(goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
					, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
				Deli[i].printDeliveryInfo();
				i++;
			}
		}
	}
	else
	{
		cout << "DELIVERY FILE WAS NOT OPENED\n";
	}
}


void bookRide(Driver* D, Vehicle* V, Ride* R)
{
	//Variables for the Drivers
	int dId = 1;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int status;
	char fName[100];
	char lName[100];
	int day, month, year;
	int nId;
	int age;
	char trash;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}
	//Variables for Vehicles
	int vId;
	int regNo;
	float mileage;
	char* lic_type = new char[20];
	bool stat;
	char* fuel_type = new char[10];
	float rank;
	/*int day;
	int month;
	int year;*/
	int fId;
	char descrip[100];
	float cost;

	//Counter to control the information of Drivers
	static int i = 0;
	float max[100];
	float temp;
	int fileCount = 0;
	ifstream readDriv;
	readDriv.open("DriverDetails.txt");
	if (readDriv.is_open())
	{
		while (!readDriv.eof())
		{
			static int counter = 0;
			readDriverDetailsFile(readDriv, dId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year, trash);
			setDriverDetailsCompleteFile(D, dId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year);
			max[counter++] = overallRank;
			fileCount++;
		}
	}
	else
	{
		cout << "DRIVER DETAILS FILE WAS UNABLE TO OPEN\n";
	}
	int count1 = 0;
	//Sorting in decending order
	int countSize = 0;
	for (int i = 0; i < 100; i++)
	{
		if (max[i] > 0 && max[i] < 5)
		{
			countSize++;
		}
	}
	for (int i = 0; i < countSize; i++)
	{
		for (int j = 0; j < countSize - i - 1; j++)
		{
			if (max[j] < max[j + 1])
			{
				temp = max[j];
				max[j] = max[j + 1];
				max[j + 1] = temp;
			}
		}
	}
	bool flag = false;
	while (true)
	{
		if (D[i].getStatusOfDriver() == 1 && max[count1] == D[i].getoverallRanking())
		{
			cout << "-----------------------------------------------------------------------------------------\n";
			cout << "\t\t\tDriver: " << count1 + 1 << endl;

			D[i].printDriversInfo();
			flag = true;
			count1++;
		}
		i++;
		if (flag)
		{
			i = 0;
		}
		if (fileCount == count1)
		{
			break;
		}
		flag = false;

	}
	//Counters for Vehicles file
	int fileCountForVehi = 0;
	float maxForVehi[100];
	int countForMaxVehi = 0;
	ifstream readVehi;
	readVehi.open("VehicleDetails.txt");
	if (readVehi.is_open())
	{
		while (!readVehi.eof())
		{
			readVehicleDetailsCompleteFile(readVehi, vId, regNo, mileage, lic_type, stat, fuel_type, rank, day,
				month, year, fId, descrip, cost, trash);
			setVehicleDetailsCompleteFile(V, vId, regNo, mileage, lic_type, stat, fuel_type, rank, day, month,
				year, fId, descrip, cost);
			maxForVehi[countForMaxVehi++] = rank;
			fileCountForVehi++;
		}
	}
	else
	{
		cout << "VEHICLE DETAILS FILE WAS UNABLE TO OPEN\n";
	}
	countForMaxVehi = 0;
	//Sorting in decending order
	for (int i = 0; i < 100; i++)
	{
		if (maxForVehi[i] > 0 && maxForVehi[i] < 5)
		{
			countForMaxVehi++;
		}
	}
	for (int i = 0; i < countForMaxVehi; i++)
	{
		for (int j = 0; j < countForMaxVehi - i - 1; j++)
		{
			if (maxForVehi[j] < maxForVehi[j + 1])
			{
				temp = maxForVehi[j];
				maxForVehi[j] = maxForVehi[j + 1];
				maxForVehi[j + 1] = temp;
			}
		}
	}
	bool flagVehi = false;
	static int j = 0;
	int checkCount = 0;
	while (true)
	{
		if (V[i].getStatusForVehi() == 1 && maxForVehi[checkCount] == V[i].getRankForVehi())
		{
			cout << "-----------------------------------------------------------------------------------------\n";
			cout << "\t\t\tVehicle: " << checkCount + 1 << endl;
			V[i].printVehicleDetails();
			flagVehi = true;
			checkCount++;
		}
		j++;
		if (flagVehi)
		{
			j = 0;
		}
		if (fileCountForVehi == checkCount)
		{
			break;
		}
		flagVehi = false;
	}
	//Booking a ride
	int inpDid;
	int inpVid;
	cout << "Enter Driver ID (to book): ";
	cin >> inpDid;
	cout << "Enter Vehicle ID (to book): ";
	cin >> inpVid;

	//Take features of the Ride
	//Variables for service and Ride
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int sIDOfR = rand();
	int cIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int noOfPass;
	char r_Type[50];
	float d_Rank;
	float v_Rank;
	cout << "WE NEED SOME DATA AGAINST YOUR RIDE REQUEST\n";
	ofstream writeRide;
	writeRide.open("Ride.txt", ios::app);
	if (writeRide.is_open())
	{
		writingInRideFile(R, writeRide, inpDid, inpVid);
		writeRide.close();
	}
	int fileCountRide = 0;
	ifstream readRide;
	readRide.open("Ride.txt");
	if (readRide.is_open())
	{
		while (!readRide.eof())
		{
			readRideCompleteFile(readRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			setRideCompleteFile(R, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			fileCountRide++;
		}
	}

}

float fairCalculationForDelivery(Delivery* Deli, float fuel, float dis)
{
	float tax = 0;
	/*for (int i = 0; i < fileCountRide; i++)
	{*/
	static int i = 0;
	if (dis >= 300 && fuel >= 150)
	{
		tax = 500 * 150;
	}
	else if ((dis <= 300 && dis >= 150) && fuel <= 150)
	{
		tax = 400 * 150;
	}
	else if ((dis <= 150 && dis >= 100) && fuel <= 150)
	{
		tax = 300 * 150;
	}
	else if ((dis <= 100 && dis >= 50) && fuel <= 150)
	{
		tax = 100 * 150;
	}
	else if ((dis <= 50 && dis >= 30) && fuel <= 150)
	{
		tax = 50 * 150;
	}
	else if ((dis <= 30 && dis >= 10) && fuel <= 150)
	{
		tax = 30 * 150;
	}
	else if ((dis <= 10 && dis >= 0) && fuel <= 150)
	{
		tax = 10 * 150;
	}


	cout << "--------------------------------------------------------------------------------------------\n";
	cout << "\t\t\tFOR YOUR DESIRED SERVICE THE CHARGES ARE\n\t\t\tOnly R.s:";
	cout << tax;
	return tax;
}
void writingInDeliveryFile(Delivery* Deli, ofstream& write, int inp_dId, int inp_vId)
{
	float goodW;
	char goodT[200];
	char source[100];
	char destination[100];
	float distance;
	bool status;
	float fuelRate;
	srand(time(0));
	int sID = rand();
	int cID;
	int dID = inp_dId;
	int vID = inp_vId;
	int day;
	int month;
	int year;
	int hr;
	int min;
	int sec;

	write << endl;
	write << sID;
	write << "/";
	cout << "Enter Customer ID: ";
	cin >> cID;
	write << cID;
	write << "/";

	write << dID;
	write << "/";

	write << vID;
	write << "/";

	cout << "Enter Your Departure Location: ";
	cin.ignore();
	cin.getline(source, 100);
	write << source;
	write << "/";

	cout << "Enter Your Destination Location: ";
	cin.getline(destination, 100);
	write << destination;
	write << "/";

	cout << "Enter Date(Format: day/month/year): ";
	cin >> day >> month >> year;
	write << day;
	write << "/";
	write << month;
	write << "/";
	write << year;
	write << "/";

	cout << "Enter Time (Format: hr/min/sec): ";
	cin >> hr >> min >> sec;
	write << hr;
	write << "/";
	write << min;
	write << "/";
	write << sec;
	write << "/";

	cout << "Enter Fuel Rate: ";
	cin >> fuelRate;
	write << fuelRate;
	write << "/";

	cout << "Enter the Total Distance Travelled: ";
	cin >> distance;
	write << distance;
	write << "/";

	cout << "Enter the Status (Format: 0 if pending || 1 if complete): ";
	cin >> status;
	write << status;
	write << "/";

	cout << "Enter Goods Specifications: ";
	cin.ignore();
	cin.getline(goodT, 200);
	write << goodT;
	write << "/";

	cout << "Enter Goods Total Weight: ";
	cin >> goodW;
	write << goodW;



	fairCalculationForDelivery(Deli, fuelRate, distance);
}
void bookDelivery(Driver* D, Vehicle* V, Delivery* Deli)
{
	//Variables for the Drivers
	int dId = 1;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int status;
	char fName[100];
	char lName[100];
	int day, month, year;
	int nId;
	int age;
	char trash;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}
	//Variables for Vehicles
	int vId;
	int regNo;
	float mileage;
	char* lic_type = new char[20];
	bool stat;
	char* fuel_type = new char[10];
	float rank;
	/*int day;
	int month;
	int year;*/
	int fId;
	char descrip[100];
	float cost;
	//Counter to control the information of Drivers
	static int i = 0;
	float max[100];
	float temp;
	int fileCount = 0;
	ifstream readDriv;
	readDriv.open("DriverDetails.txt");
	if (readDriv.is_open())
	{
		while (!readDriv.eof())
		{
			static int counter = 0;
			readDriverDetailsFile(readDriv, dId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year, trash);
			setDriverDetailsCompleteFile(D, dId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year);
			max[counter++] = overallRank;
			fileCount++;
		}
	}
	else
	{
		cout << "DRIVER DETAILS FILE WAS UNABLE TO OPEN\n";
	}
	int count1 = 0;
	//Sorting in decending order
	int countSize = 0;
	for (int i = 0; i < 100; i++)
	{
		if (max[i] > 0 && max[i] < 5)
		{
			countSize++;
		}
	}
	for (int i = 0; i < countSize; i++)
	{
		for (int j = 0; j < countSize - i - 1; j++)
		{
			if (max[j] < max[j + 1])
			{
				temp = max[j];
				max[j] = max[j + 1];
				max[j + 1] = temp;
			}
		}
	}
	bool flag = false;
	while (true)
	{
		if (D[i].getStatusOfDriver() == 1 && max[count1] == D[i].getoverallRanking())
		{
			cout << "-----------------------------------------------------------------------------------------\n";
			cout << "\t\t\tDriver: " << count1 + 1 << endl;

			D[i].printDriversInfo();
			flag = true;
			count1++;
		}
		i++;
		if (flag)
		{
			i = 0;
		}
		if (fileCount == count1)
		{
			break;
		}
		flag = false;

	}
	//Counters for Vehicles file
	int fileCountForVehi = 0;
	float maxForVehi[100];
	int countForMaxVehi = 0;
	ifstream readVehi;
	readVehi.open("VehicleDetails.txt");
	if (readVehi.is_open())
	{
		while (!readVehi.eof())
		{
			readVehicleDetailsCompleteFile(readVehi, vId, regNo, mileage, lic_type, stat, fuel_type, rank, day,
				month, year, fId, descrip, cost, trash);
			setVehicleDetailsCompleteFile(V, vId, regNo, mileage, lic_type, stat, fuel_type, rank, day, month,
				year, fId, descrip, cost);
			maxForVehi[countForMaxVehi++] = rank;
			fileCountForVehi++;
		}
	}
	else
	{
		cout << "VEHICLE DETAILS FILE WAS UNABLE TO OPEN\n";
	}
	countForMaxVehi = 0;
	//Sorting in decending order
	for (int i = 0; i < 20; i++)
	{
		if (maxForVehi[i] > 0 && maxForVehi[i] < 5)
		{
			countForMaxVehi++;
		}
	}
	for (int i = 0; i < countForMaxVehi; i++)
	{
		for (int j = 0; j < countForMaxVehi - i - 1; j++)
		{
			if (maxForVehi[j] < maxForVehi[j + 1])
			{
				temp = maxForVehi[j];
				maxForVehi[j] = maxForVehi[j + 1];
				maxForVehi[j + 1] = temp;
			}
		}
	}
	bool flagVehi = false;
	static int j = 0;
	int checkCount = 0;
	while (true)
	{
		if (V[i].getStatusForVehi() == 1 || maxForVehi[checkCount] == V[i].getRankForVehi())
		{
			cout << "-----------------------------------------------------------------------------------------\n";
			cout << "\t\t\tVehicle: " << checkCount + 1 << endl;
			V[i].printVehicleDetails();
			flagVehi = true;
			checkCount++;
		}
		j++;
		if (flagVehi)
		{
			j = 0;
		}
		if (fileCountForVehi == checkCount)
		{
			break;
		}
		flagVehi = false;
	}
	//Booking a Delivery
	int inpDid;
	int inpVid;
	cout << "Enter Driver ID (to book): ";
	cin >> inpDid;
	cout << "Enter Vehicle ID (to book): ";
	cin >> inpVid;

	ofstream writeDelivery;
	writeDelivery.open("Delivery.txt", ios::app);
	if (writeDelivery.is_open())
	{
		writingInDeliveryFile(Deli, writeDelivery, inpDid, inpVid);
		writeDelivery.close();
	}
}

void cancelRideFunctionality(Ride* R)
{	//variables for ride
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int sIDOfR;
	int cIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int noOfPass;
	char r_Type[50];
	float d_Rank;
	float v_Rank;
	int checkServID;
	int checkCustID;
	float fair;
	cout << "Enter Service ID: ";
	cin >> checkServID;
	cout << "Enter Customer ID: ";
	cin >> checkCustID;
	ifstream readRide;
	readRide.open("Ride.txt");
	ofstream writeRide;
	writeRide.open("RideUpdated.txt");
	if (readRide.eof())
	{
		while (!readRide.eof())
		{
			readRideCompleteFile(readRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			if (sIDOfR == checkServID && cIDOfR == checkCustID && statusOfR == 0)
			{
				bookRide = 0;//it shows cancelation
				fair = fairCalculationForRide(R, fuelRate, distance);
				fair *= (5 / 100);
				cout << "You are Required To Pay 5% of the Amount as per the Company's Policy for Canceling a Ride: \n";
				cout << fair;
			}
			writeInRideFileComplete(writeRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			setRideCompleteFile(R, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
		}
	}
	else
	{
		cout << "RIDE FILE WAS UNABLE TO OPEN\n";
	}
	readRide.close();
	writeRide.close();
	remove("Ride.txt");
	rename("RideUpdated.txt", "Ride.txt");

}
void cancelDeliveryFunctionality(Delivery* Deli)
{
	//variables for Delivery file
	float goodW;
	char goodT[200];
	bool bookDeli;
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int sIDOfR;
	int cIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int checkServID;
	int checkCustID;
	float fair;
	cout << "Enter Service ID: ";
	cin >> checkServID;
	cout << "Enter Customer ID: ";
	cin >> checkCustID;
	ifstream readDeli;
	readDeli.open("Delivery.txt");
	ofstream writeDeli;
	writeDeli.open("DeliveryUpdated.txt");
	if (readDeli.is_open())
	{
		while (!readDeli.eof())
		{
			readDeliveryCompleteFile(readDeli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
			if (sIDOfR == checkServID && cIDOfR == checkCustID && statusOfR == 0)
			{
				bookDeli = 0;
				fair = fairCalculationForDelivery(Deli, fuelRate, distance);
				fair *= (5 / 100);
				cout << "You are Required To Pay 5% of the Amount as per the Company's Policy for Canceling a Ride: \n";
				cout << fair;
			}
			writeDeliveryCompleteFile(writeDeli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
			setDeliveryCompleteFile(Deli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
		}
	}
	else
	{
		cout << "DELIVERY FILE WAS UNABLE TO OPEN\n";
	}
	writeDeli.close();
	readDeli.close();
	remove("Delivery.txt");
	rename("DeliveryUpdated.txt", "Delivery.txt");
}

void setServiceTrueRide(Ride* R, Driver* D, Vehicle* V)
{

	//Variables for Driver
	int driverId = 0;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int statOfDriv;
	char fName[100];
	char lName[100];
	int nId;
	int age;
	int dayOfDriv, monthOfDriv, yearOfDriv;
	char trashDriv;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}
	//Variables for Vehicles
	int vId = 0;
	int regNo = 0;
	float mileage = 0;
	char lic_type[50];
	bool statusOfV = true;
	char fuel_type[50];
	float rankOfV = 0;
	int dayOfV = 0;
	int monthOfV = 0;
	int yearOfV = 0;
	int fId;
	char descrip[100];
	char trashOfV = '/';
	float cost;
	//Variables for Ride File
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int sIDOfR;
	int cIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int noOfPass;
	char r_Type[50];
	float d_Rank;
	float v_Rank;
	int inp_servID;
	int inp_drivID;
	int inp_vehiID;
	int addRankDriv;
	int addRankVehi;
	cout << "Enter Service ID (against which the Service is completed): ";
	cin >> inp_servID;
	cout << "Enter Driver ID (against which the Service is completed): ";
	cin >> inp_drivID;
	cout << "Enter Vehicle ID (against which the Service is completed): ";
	cin >> inp_vehiID;
	cout << "Enter Rank you want to give to the Driver: ";
	cin >> addRankDriv;
	cout << "Enter Rank you want to give to the Vehicle: ";
	cin >> addRankVehi;
	ofstream writeRide;
	ofstream writeDriv;
	ofstream writeVehi;
	writeVehi.open("VehicleDetailsUpdated.txt");
	writeDriv.open("DriverDetailsUpdated.txt");
	writeRide.open("RideUpdated.txt");
	ifstream readVehi;
	ifstream readRide;
	ifstream readDriv;
	readVehi.open("VehicleDetails.txt");
	readDriv.open("DriverDetails.txt");
	readRide.open("Ride.txt");
	if (readRide.is_open() || readDriv.is_open() || readVehi.is_open())
	{
		while (!readRide.eof() || !readDriv.eof() || !readVehi.eof())
		{
			readRideCompleteFile(readRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			readDriverDetailsFile(readDriv, driverId, lic_list, noOfLic, overallRank, sal, exp, statOfDriv, age,
				nId, fName, lName, dayOfDriv, monthOfDriv, yearOfDriv, trashDriv);
			readVehicleDetailsCompleteFile(readVehi, vId, regNo, mileage, lic_type, statusOfV, fuel_type, rankOfV,
				dayOfV, monthOfV, yearOfV, fId, descrip, cost, trashOfV);
			if (inp_servID == sIDOfR)
			{
				statusOfR = 1;
				bookRide = 0;
			}
			if (inp_drivID == driverId)
			{
				statOfDriv = 1;
				if (addRankDriv >= 4)
				{
					overallRank += 1;
				}
				else if (addRankDriv >= 3)
				{
					overallRank += 0.7;
				}
				else if (addRankDriv >= 2)
				{
					overallRank += 0.5;
				}
				else if (addRankDriv >= 1)
				{
					overallRank += 0.3;
				}
				else
				{
					overallRank += 0.2;
				}
			}
			if (inp_vehiID == vId)
			{
				statusOfV = 1;
				if (addRankVehi >= 4)
				{
					rankOfV += 1;
				}
				else if (addRankVehi >= 3)
				{
					rankOfV += 0.7;
				}
				else if (addRankVehi >= 2)
				{
					rankOfV += 0.5;
				}
				else if (addRankVehi >= 1)
				{
					rankOfV += 0.3;
				}
				else
				{
					rankOfV += 0.2;
				}
			}
			writeDriverDetailsCompleteFile(writeDriv, driverId, lic_list, noOfLic, overallRank, sal, exp, statOfDriv, age,
				nId, fName, lName, dayOfDriv, monthOfDriv, yearOfDriv);
			writeInRideFileComplete(writeRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			writeVehicleDetailsCompleteFile(writeVehi, vId, regNo, mileage, lic_type, statusOfV, fuel_type, rankOfV,
				dayOfV, monthOfV, yearOfV, fId, descrip, cost, trashOfV);

			setDriverDetailsCompleteFile(D, driverId, lic_list, noOfLic, overallRank, sal, exp, statOfDriv, age,
				nId, fName, lName, dayOfDriv, monthOfDriv, yearOfDriv);
			setRideCompleteFile(R, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			setVehicleDetailsCompleteFile(V, vId, regNo, mileage, lic_type, statusOfV, fuel_type, rankOfV,
				dayOfV, monthOfV, yearOfV, fId, descrip, cost);
		}
	}
	writeRide.close();
	writeDriv.close();
	writeVehi.close();
	remove("RideUpdated.txt");
	remove("DriverDetailsUpdated.txt");
	remove("VehicleDetailsUpdated.txt");

	rename("RideUpdated.txt", "Ride.txt");
	rename("DriverDetailsUpdated.txt", "DriverDetails.txt");
	rename("VehicleDetailsUpdated.txt", "VehicleDetails.txt");
}
void setServiceTrueDelivery(Delivery* Deli, Driver* D, Vehicle* V)
{
	//Variables for Driver
	int driverId = 0;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int statOfDriv;
	char fName[100];
	char lName[100];
	int nId;
	int age;
	int dayOfDriv, monthOfDriv, yearOfDriv;
	char trashDriv;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}
	//Variables for Vehicles
	int vId = 0;
	int regNo = 0;
	float mileage = 0;
	char lic_type[50];
	bool statusOfV = true;
	char fuel_type[50];
	float rankOfV = 0;
	int dayOfV = 0;
	int monthOfV = 0;
	int yearOfV = 0;
	int fId;
	char descrip[100];
	char trashOfV;
	float cost;
	float goodW;
	char goodT[200];
	bool bookDeli;
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int sIDOfR;
	int cIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int inp_servID;
	int inp_drivID;
	int inp_vehiID;
	int addRankDriv;
	int addRankVehi;
	cout << "Enter Service ID (against which the Service is completed): ";
	cin >> inp_servID;
	cout << "Enter Driver ID (against which the Service is completed): ";
	cin >> inp_drivID;
	cout << "Enter Vehicle ID (against which the Service is completed): ";
	cin >> inp_vehiID;
	cout << "Enter Rank you want to give to the Driver: ";
	cin >> addRankDriv;
	cout << "Enter Rank you want to give to the Vehicle: ";
	cin >> addRankVehi;
	ifstream readDeli;
	ifstream readVehi;
	ifstream readDriv;
	ofstream writeDriv;
	ofstream writeVehi;
	ofstream writeDeli;
	readVehi.open("VehicleDetails.txt");
	readDriv.open("DriverDetails.txt");
	readDeli.open("Delivery.txt");
	writeDeli.open("DeliveryUpdated.txt");
	writeVehi.open("VehicleDetailsUpdated.txt");
	writeDriv.open("DriverDetailsUpdated.txt");
	if (readDeli.is_open() || readDriv.is_open() || readVehi.is_open())
	{
		while (!readDeli.eof() || !readDriv.eof() || !readVehi.eof())
		{
			readDeliveryCompleteFile(readDeli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
			readDriverDetailsFile(readDriv, driverId, lic_list, noOfLic, overallRank, sal, exp, statOfDriv, age,
				nId, fName, lName, dayOfDriv, monthOfDriv, yearOfDriv, trashDriv);
			readVehicleDetailsCompleteFile(readVehi, vId, regNo, mileage, lic_type, statusOfV, fuel_type, rankOfV,
				dayOfV, monthOfV, yearOfV, fId, descrip, cost, trashOfV);
			if (inp_servID == sIDOfR)
			{
				statusOfR = 1;
				bookRide = 0;
			}
			if (inp_drivID == driverId)
			{
				statOfDriv = 1;
				if (addRankDriv >= 4)
				{
					overallRank += 1;
				}
				else if (addRankDriv >= 3)
				{
					overallRank += 0.7;
				}
				else if (addRankDriv >= 2)
				{
					overallRank += 0.5;
				}
				else if (addRankDriv >= 1)
				{
					overallRank += 0.3;
				}
				else
				{
					overallRank += 0.2;
				}
			}
			if (inp_vehiID == vId)
			{
				statusOfV = 1;
				if (addRankVehi >= 4)
				{
					rankOfV += 1;
				}
				else if (addRankVehi >= 3)
				{
					rankOfV += 0.7;
				}
				else if (addRankVehi >= 2)
				{
					rankOfV += 0.5;
				}
				else if (addRankVehi >= 1)
				{
					rankOfV += 0.3;
				}
				else
				{
					rankOfV += 0.2;
				}
			}
			writeDeliveryCompleteFile(writeDeli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);

			writeDriverDetailsCompleteFile(writeDriv, driverId, lic_list, noOfLic, overallRank, sal, exp, statOfDriv, age,
				nId, fName, lName, dayOfDriv, monthOfDriv, yearOfDriv);
			writeVehicleDetailsCompleteFile(writeVehi, vId, regNo, mileage, lic_type, statusOfV, fuel_type, rankOfV,
				dayOfV, monthOfV, yearOfV, fId, descrip, cost, trashOfV);
			setDeliveryCompleteFile(Deli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
			setDriverDetailsCompleteFile(D, driverId, lic_list, noOfLic, overallRank, sal, exp, statOfDriv, age,
				nId, fName, lName, dayOfDriv, monthOfDriv, yearOfDriv);
			setVehicleDetailsCompleteFile(V, vId, regNo, mileage, lic_type, statusOfV, fuel_type, rankOfV,
				dayOfV, monthOfV, yearOfV, fId, descrip, cost);


		}
	}
	writeDeli.close();
	writeDriv.close();
	writeVehi.close();
	remove("DeliveryUpdated.txt");
	remove("DriverDetailsUpdated.txt");
	remove("VehicleDetailsUpdated.txt");

	rename("DeliveryUpdated.txt", "Delivery.txt");
	rename("DriverDetailsUpdated.txt", "DriverDetails.txt");
	rename("VehicleDetailsUpdated.txt", "VehicleDetails.txt");
}

class TMS
{
	Customer* C;
	Driver* D;
	Vehicle* V;
	Ride* R;
	Delivery* Deli;
public:
	TMS()
	{
		C = new Customer[15];
		D = new Driver[10];
		V = new Vehicle[20];
		R = new Ride[15];
		Deli = new Delivery[15];
	}
	~TMS()
	{
		delete[] D;
		delete[] V;
		delete[]R;
		delete[]Deli;
	}
	void addNewCustomer();
	void addOrRemoveDriver();
	void addOrRemoveVehicle();
	void printCustomerDetials();
	void printDriverDetails();
	void printListOfTheVehicles();
	void printDetailsHistoryVehicle();
	void printHistoryOfCustomer();
	void printCompleteHistoryOfDriver();
	void printDrivers4Above();
	void printMultipleLicenses();
	void printUpdatedSalaryOfTheDriver();
	void addServiceRequestForCustomer();
	void cancelingBooking();
	void completeService();
	void printDetailsOfCustomerWhoUsedSameRideDiffDate();
	void printDetailsOfDriverWhoCompleteServiceOnSameDay();
	void printPendingRequestsParticularDate();
	void printPendingServiceParticularDriver();
	void printDetailsOfAllCancelledServicesByCustomer();
	//Helping Functions
	void loadCustomerDetailsFileFromMain();
	void loadDriverDetailsFileFromMain();
	void loadVehicleDetailsFileFromMain();
	void loadRideFileFromMain();
	void loadDeliveryFileFromMain();
};
void TMS::addNewCustomer()
{
	string checkInput;
	bool run = true;
	cout << "Enter Yes (Format: yes or Yes) if you are using this App for the First Time\n";
	cout << "Enter No (Format: no or No) if you dont want to Register\n";
	cin.ignore();
	while (run)
	{
		getline(cin, checkInput);
		if (checkInput == "yes" || checkInput == "Yes")
		{

			newCustomerFunctionality(*C);

			run = false;
		}
		else if (checkInput == "No" || checkInput == "no")
		{
			run = false;
		}
		else
		{
			cout << "INAVALID INPUT !!\n";
			cout << "\nRe-Enter: ";
		}
	}
}
void TMS::addOrRemoveDriver()
{
	int sel = 0;
	bool run = true;
	cout << "Select the Category of Your Driving\n";
	cout << "Enter 1: To add a new Driver from the Company\n";
	cout << "Enter 2: To Remove a Driver from the Company\n";
	cout << "Enter -1: To Exit\n";
	/*Driver* D;
	D = new Driver[10];*/
	while (run)
	{
		cin >> sel;
		if (sel == 1)
		{
			addDriverFunctionality(*D);
			run = false;
		}
		else if (sel == 2)
		{
			removeDriverFunctionality(D);
			run = false;
		}
		else if (sel == -1)
		{
			cout << "EXITED SUCCESSFULLY\n";
			break;
		}
		else
		{
			cout << "Invalid Input\n";
			cout << "Re-Enter Input: ";
			run = true;
		}
	}
}
void TMS::addOrRemoveVehicle()
{
	int sel = 0;
	int selService = 0;
	bool run = true;
	cout << "Select the Category of Your Vehicle\n";
	cout << "Enter 1: To add a new Vehicle\n";
	cout << "Enter 2: To Remove a Vehicle\n";
	cout << "Enter -1: To Exit\n";
	while (run)
	{
		cin >> sel;
		if (sel == 1)
		{
			addVehicleFunctionality();
			/*cout << "Enter 1: To add Service: ";
			cin >> selService;
			if (selService == 1)
			{
				addVehicleServices();
			}
			else
			{
				cout << "INVALID INPUT\n";
			}*/

			run = false;
		}
		else if (sel == 2)
		{
			removeVehicleFunctionality();
			run = false;
		}
		else if (sel == -1)
		{
			cout << "YOU HAVE SUCCESSFULLY EXITED\n";
			break;
		}
		else
		{
			cout << "INVALID INPUT!!\n";
			run = true;
			cout << "Re-Enter: ";
		}
	}
}
void TMS::printCustomerDetials()
{
	ifstream read;
	int fileCount = 0;
	read.open("CustomerDetails.txt");
	if (read.is_open())
	{
		while (!read.eof())
		{
			char fName[100];
			char lName[100];
			int day, month, year;
			int nId;
			int age;
			int custCount = 0;
			char trash;

			read >> custCount;
			read >> trash;
			read.getline(fName, 100, ',');
			read.getline(lName, 100, ',');
			read >> age;
			read >> trash;
			read >> nId;
			read >> trash;
			read >> day;
			read >> trash;
			read >> month;
			read >> trash;
			read >> year;
			fileCount++;
			static int i = 0;
			C[i].setNewCustomer(custCount, fName, lName, age, nId, day, month, year);
			i++;
		}

	}
	else
	{
		cout << "CUSTOMER DETAILS FILES WAS UNABLE TO OPEN\n";
	}
	int i = 0;
	while (i < fileCount)
	{
		cout << "--------------------------------------------------------------------------\n";
		cout << "\t\t\tCUSTOMER " << i + 1 << endl;
		C[i].printCustomerInfo();
		i++;
	}
	read.close();
}
void TMS::printDriverDetails()
{
	ifstream read;
	read.open("DriverDetails.txt");
	if (read.is_open())
	{
		int dId = 1;
		char** lic_list;
		int noOfLic;
		float overallRank;
		float sal;
		int exp;
		int status;
		char fName[100];
		char lName[100];
		int day, month, year;
		int nId;
		int age;
		char trash;
		lic_list = new char* [8];
		for (int i = 0; i < 8; i++)
		{
			lic_list[i] = new char;
		}
		while (!read.eof())
		{
			read >> dId;
			read >> trash;
			read.getline(fName, 100, ',');
			read.getline(lName, 100, '/');
			read >> age;
			read >> trash;
			read >> nId;
			read >> trash;
			read >> day;
			read >> trash;
			read >> month;
			read >> trash;
			read >> year;
			read >> trash;
			for (int i = 0; i < 1; i++)
			{
				//	for (int j = 0; j < 1; j++)
					//{
				read.getline(lic_list[i], 50, ',');
				//	}
			}
			read >> noOfLic;
			read >> trash;
			read >> overallRank;
			read >> trash;
			read >> sal;
			read >> trash;
			read >> exp;
			read >> trash;
			read >> status;
			static int i = 0;
			D[i].setDriverInfo(dId, lic_list, noOfLic, overallRank, sal, exp, status);
			D[i].setCustomerAge_Nid(age, nId, fName, lName, day, month, year);
			cout << "-----------------------------------------------------------------------------------\n";
			cout << "\t\t\tDRIVER " << i + 1 << endl;
			D[i].printDriversInfo();
			i++;
		}
	}
	else
	{
		cout << "DRIVER DETAILS FILE WAS UNABLE TO OPEN\n";
	}
}
void TMS::printListOfTheVehicles()
{
	readVehicleDetailsFile(V);

}
void TMS::printDetailsHistoryVehicle()
{
	readVehicleServicesFile(R, Deli);
}
void TMS::printHistoryOfCustomer()
{
	//variables for ride
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int cIDOfR;
	int sIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int noOfPass;
	char r_Type[50];
	float d_Rank;
	float v_Rank;
	//variables for delivery
	float goodW;
	char goodT[200];
	bool bookDeli;
	/*char source[100];
	char destination[100];
	float distance;
	bool status;
	float fuelRate;
	int cID;
	int dID;
	int vID;
	int day;
	int month;
	int year;
	int hr;
	int min;
	int sec;*/
	int checkID;
	cout << "Enter Customer ID for which you want to get Details: ";
	cin >> checkID;
	ifstream readRide;
	readRide.open("Ride.txt");
	if (readRide.is_open())
	{
		while (!readRide.eof())
		{
			readRideCompleteFile(readRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			static int i = 0;
			if (checkID == cIDOfR)
			{

				R[i].setRideInfo(noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
					, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
				R[i].printRideInfo();
				i++;
			}
		}

	}
	else
	{
		cout << "RIDE FILE WAS UNABLE TO OPEN\n";
	}
	ifstream readDeli;
	readDeli.open("Delivery.txt");
	if (readDeli.is_open())
	{
		while (!readDeli.eof())
		{
			readDeliveryCompleteFile(readDeli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
			static int i = 0;
			if (checkID == cIDOfR)
			{
				Deli[i].setDeliveryInfo(goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
					, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
				Deli[i].printDeliveryInfo();
				i++;
			}
		}
	}
	else
	{
		cout << "DELIVERY FILE WAS NOT OPENED\n";
	}
	readRide.close();
	readDeli.close();
}
void TMS::printCompleteHistoryOfDriver()
{
	int driverId = 0;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int stat;
	char fName[100];
	char lName[100];/*
	int day, month, year;*/
	int nId;
	int age;
	int day, month, year;
	char trashDriv;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}
	//variables for ride
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int sIDOfR;
	int cIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int noOfPass;
	char r_Type[50];
	float d_Rank;
	float v_Rank;
	//variables for delivery
	float goodW;
	char goodT[200];
	bool bookDeli;
	int checkDriversID = 0;
	int fileCountDriver = 0;
	int fileCountServ = 0;
	ifstream readDriv;
	readDriv.open("DriverDetails.txt");
	cout << "Enter Drivers ID for which you want get full Detail of: ";
	cin >> checkDriversID;
	if (readDriv.is_open())
	{
		while (!readDriv.eof())
		{
			readDriverDetailsFile(readDriv, driverId, lic_list, noOfLic, overallRank, sal, exp, stat, age,
				nId, fName, lName, day, month, year, trashDriv);
			static int i = 0;
			if (checkDriversID == driverId)
			{

				D[i].setDriverInfo(driverId, lic_list, noOfLic, overallRank, sal, exp, stat);
				D[i].setCustomerAge_Nid(age, nId, fName, lName, day, month, year);
				cout << "-----------------------------------------------------------------------------------\n";
				cout << "\t\t\tDRIVER " << i + 1 << endl;
				D[i].printDriversInfo();
				i++;
				fileCountDriver++;
			}


		}
	}
	else
	{
		cout << "DRIVERS DETAIL FILE IS NOT OPEN\n";
	}
	ifstream readRide;
	readRide.open("Ride.txt");
	if (readRide.is_open())
	{
		while (!readRide.eof())
		{
			readRideCompleteFile(readRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			static int i = 0;
			if (checkDriversID == dIDOfR)
			{

				R[i].setRideInfo(noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
					, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
				R[i].printRideInfo();
				i++;
			}
		}

	}
	else
	{
		cout << "RIDE FILE WAS UNABLE TO OPEN\n";
	}
	ifstream readDeli;
	readDeli.open("Delivery.txt");
	if (readDeli.is_open())
	{
		while (!readDeli.eof())
		{
			readDeliveryCompleteFile(readDeli, goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
			static int i = 0;
			if (checkDriversID == dIDOfR)
			{
				Deli[i].setDeliveryInfo(goodW, goodT, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
					, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookDeli);
				Deli[i].printDeliveryInfo();
				i++;
			}
		}
	}
	else
	{
		cout << "DELIVERY FILE WAS NOT OPENED\n";
	}
	readRide.close();
	readDeli.close();
}
void TMS::printDrivers4Above()
{
	int driversId;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int status;
	char fName[100];
	char lName[100];
	int day, month, year;
	int nId;
	int age;
	char trash;
	int driId;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}

	ifstream read;
	read.open("DriverDetails.txt");

	if (read.is_open())
	{
		while (!read.eof())
		{
			readDriverDetailsFile(read, driversId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year, trash);
			if (overallRank > 4.5)
			{
				static int i = 0;
				D[i].setDriverInfo(driversId, lic_list, noOfLic, overallRank, sal, exp, status);
				D[i].setCustomerAge_Nid(age, nId, fName, lName, day, month, year);
				cout << "-----------------------------------------------------------------------------------\n";
				cout << "\t\t\tDRIVER " << i + 1 << endl;
				D[i].printDriversInfo();
				i++;
			}
		}
	}
}
void TMS::printMultipleLicenses()
{
	int driversId;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int status;
	char fName[100];
	char lName[100];
	int day, month, year;
	int nId;
	int age;
	char trash;
	int driId;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}

	ifstream readDriv;
	readDriv.open("DriverDetails.txt");
	if (readDriv.is_open())
	{
		while (!readDriv.eof())
		{
			readDriverDetailsFile(readDriv, driversId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year, trash);
			if (noOfLic > 1)
			{
				static int i = 0;
				D[i].setDriverInfo(driversId, lic_list, noOfLic, overallRank, sal, exp, status);
				D[i].setCustomerAge_Nid(age, nId, fName, lName, day, month, year);
				cout << "-----------------------------------------------------------------------------------\n";
				cout << "\t\t\tDRIVER " << i + 1 << endl;
				D[i].printDriversInfo();
				i++;
			}
		}
	}
	else
	{
		cout << "DRIVER DETAILS FILE WAS UNABLE TO OPEN\n";
	}
}
void TMS::printUpdatedSalaryOfTheDriver()
{
	int driversId;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int status;
	char fName[100];
	char lName[100];
	int day, month, year;
	int nId;
	int age;
	char trash;
	int driId;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}
	ifstream readDriv;
	readDriv.open("DriverDetails.txt");
	ofstream writeDriv;
	writeDriv.open("DriverDetailsUpdated.txt");
	cout << "\t\t\tRECENTLY YOU HAVE GAINED RANK POINTS SO YOU WILL HAVE AN INCREMENT IN YOUR SALARY\n";
	cout << "\t\t\tCRITERIA +0.5 Rank -> 20,000 increment\n";
	if (readDriv.is_open())
	{
		while (!readDriv.eof())
		{
			readDriverDetailsFile(readDriv, driversId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year, trash);
			//if the rank is updated by 0.5 then there should be the increment of 40000

			static int i = 1;
			cout << "Driver " << i++ << " ID: " << driversId << " - Updated Salary: " << (sal += 20000) << endl;
			writeDriverDetailsCompleteFile(writeDriv, driversId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year);
		}
	}
	else
	{
		cout << "DRIVER DETAILS FILE WAS UNABLE TO OPEN\n";
	}
	readDriv.close();
	writeDriv.close();
	remove("DriverDetailsUpdated.txt");
	rename("DriverDetailsUpdated.txt", "DriverDetails.txt");
}
void TMS::addServiceRequestForCustomer()
{
	cout << "\t\t\tWELCOME SERVICE CENTER\n";
	cout << "\t\t\tYOU CAN BOOK A RIDE OR DELIVERY REQUEST\n";
	int sel = 0;
	cout << "Enter 1: To book a Ride \nEnter 2: To Request a Delivery\n";
	cin >> sel;
	if (sel == 1)
	{
		bookRide(D, V, R);
	}
	else if (sel == 2)
	{
		bookDelivery(D, V, Deli);
	}
	else
	{
		cout << "INVALID INPUT !!!\n";
	}
}
void TMS::cancelingBooking()
{
	cout << "\t\t\tSORRY!! IF YOU HAVE FACED INCONVENIENCE FROM OUR SIDE\n";
	cout << "For your cancelation process we some Information\n";
	cout << "Enter Ride if you want to Cancel a Ride (Format: ride or Ride): \n";
	cout << "Enter Delivery if you want to Cancel a Delivery (Format: delivery or Delivery): \n";
	string sel;
	getline(cin, sel);
	if (sel == "ride" || sel == "Ride")
	{
		cancelRideFunctionality(R);
	}
	else if (sel == "Delivery" || sel == "delivery")
	{
		cancelDeliveryFunctionality(Deli);
	}
	else
	{
		cout << "INVALID INPUT!!!\n";
	}
}
void TMS::completeService()
{

	cout << "Enter Ride if you want to Set Complete for a Ride (Format: ride or Ride): \n";
	cout << "Enter Delivery if you want to Set Complete for a Delivery (Format: delivery or Delivery): \n";
	string sel;
	getline(cin, sel);
	if (sel == "ride" || sel == "Ride")
	{
		setServiceTrueRide(R, D, V);
	}
	else if (sel == "Delivery" || sel == "delivery")
	{
		setServiceTrueDelivery(Deli, D, V);
	}
	else
	{
		cout << "INVALID INPUT!!!\n";
	}

}
void TMS::printDetailsOfCustomerWhoUsedSameRideDiffDate()
{
	int count = 0;
	static int i = 0;
	static int j = 1;
	while (true)
	{
		while ((R[i].getVehicleIdInService() == R[j].getVehicleIdInService()) &&
			(R[i].getDayInService() != R[j].getVehicleIdInService()
				|| R[i].getVehicleIdInService() != R[j].getVehicleIdInService()
				|| R[i].getVehicleIdInService() != R[j].getVehicleIdInService()))
		{
			count++;
			i++;
			j++;
		}
		if (count > 0)
		{
			i--;
			break;
		}
	}
	bool flag = false;
	static int k = 0;
	while (true)
	{
		if (C[k].getCustomerId() == R[i].getCustomerIdinService()) {
			cout << "\t\t\tDETAILS OF CUSTOMERS\n";
			C[k].printCustomerInfo();
			flag = true;
		}
		if (flag)
		{
			break;
		}
		k++;
	}
}
int binarySearchForDate(int s, Delivery* Deli)
{
	bool begin = false;
	int l = 0, m = 0;
	int terminateCount = 0;
	int r = s - 1;
	int i = 0;
	while (!begin)
	{
		terminateCount++;
		m = (l + r) / 2;
		if (Deli[m].getDayInService() == Deli[i].getDayInService() && Deli[m].getMonthInService() == Deli[i].getMonthInService()
			&& Deli[m].getYearInService() == Deli[i].getYearInService())
		{
			begin = true;
			return m;

		}
		else if (Deli[m].getDayInService() > Deli[i].getDayInService() && Deli[m].getMonthInService() > Deli[i].getMonthInService()
			&& Deli[m].getYearInService() > Deli[i].getYearInService())
		{
			l = m + 1;
		}
		else if (Deli[m].getDayInService() < Deli[i].getDayInService() && Deli[m].getMonthInService() < Deli[i].getMonthInService()
			&& Deli[m].getYearInService() < Deli[i].getYearInService())
		{
			l = m - 1;
		}
		if (terminateCount == s)
		{
			terminateCount = 0;
			l = 0;
			r = s - 1;
			m = 0;
			i++;
		}
	}

}
int binarySearchForDriver(int s, Driver* D, int indexOfDate)
{
	bool begin = false;
	int l = 0, m = 0;
	int terminateCount = 0;
	int r = s - 1;
	int i = 0;
	while (!begin)
	{
		terminateCount++;
		m = (l + r) / 2;
		if (D[m].getDriverId() == D[indexOfDate].getDriverId())
		{
			begin = true;
			return m;

		}
		else if (D[m].getDriverId() > D[indexOfDate].getDriverId())
		{
			l = m + 1;
		}
		else if (D[m].getDriverId() < D[indexOfDate].getDriverId())
		{
			l = m - 1;
		}
		if (terminateCount == s)
		{
			terminateCount = 0;
			l = 0;
			r = s - 1;
			m = 0;
			i++;
		}
	}

}
void TMS::printDetailsOfDriverWhoCompleteServiceOnSameDay()
{
	int fileCountDriv = 0;
	int indexOfDriv = 0;
	int fileCountDeli = Deli->getDeliveryFileCount();
	int indexOfDate;

	indexOfDate = binarySearchForDate(fileCountDeli, Deli);
	fileCountDriv = D->getDriverDetailsFileCount();
	indexOfDriv = binarySearchForDriver(fileCountDriv, D, indexOfDate);
	D[indexOfDriv].printDriversInfo();
}
void TMS::printPendingRequestsParticularDate()
{
	int d, m, y;
	cout << "Enter Day: ";
	cin >> d;
	cout << "Enter Month: ";
	cin >> m;
	cout << "Enter Year: ";
	cin >> y;
	for (int i = 0; i < R->getRideFileCount(); i++)
	{
		if (R[i].getDayInService() == d && R[i].getMonthInService() == m && R[i].getYearInService()) {
			if (R[i].getStatusInService() == 0)
			{
				R[i].printRideInfo();
			}
		}
	}
	for (int i = 0; i < Deli->getDeliveryFileCount(); i++)
	{
		if (R[i].getDayInService() == d && R[i].getMonthInService() == m && R[i].getYearInService())
		{
			if (Deli[i].getStatusInService() == 0)
			{
				Deli[i].printDeliveryInfo();
			}
		}
	}
}
void TMS::printPendingServiceParticularDriver()
{
	int inp_dID;
	cout << "Enter Drivers ID: ";
	cin >> inp_dID;
	for (int i = 0; i < R->getRideFileCount(); i++)
	{
		if (R[i].getDriverIdInService() == inp_dID)
		{
			if (R[i].getStatusInService() == 0)
			{
				R[i].printRideInfo();
			}
		}
	}
	for (int i = 0; i < Deli->getDeliveryFileCount(); i++)
	{
		if (Deli[i].getDriverIdInService() == inp_dID)
		{
			if (Deli[i].getStatusInService() == 0)
			{
				Deli[i].printDeliveryInfo();
			}
		}
	}
}
void TMS::printDetailsOfAllCancelledServicesByCustomer()
{
	for (int i = 0; i < R->getRideFileCount(); i++)
	{
		if (R[i].getBookRide() == 0)
		{
			if (R[i].getCustomerIdinService() == C[i].getCustomerId())
			{
				R[i].printRideInfo();
			}
		}
	}
	for (int i = 0; i < Deli->getDeliveryFileCount(); i++)
	{
		if (Deli[i].getBookDelivery() == 0)
		{
			if (Deli[i].getCustomerIdinService() == C[i].getCustomerId())
			{
				Deli[i].printDeliveryInfo();
			}
		}
	}
}
//Helping Functions Definition
void TMS::loadCustomerDetailsFileFromMain()
{
	char fName[100];
	char lName[100];
	int day, month, year;
	int nId;
	int age;
	int custCount = 0;
	int fileCount = 0;
	char trash;
	ifstream readCust;
	readCust.open("CustomerDetails.txt");
	if (readCust.is_open())
	{
		while (!readCust.eof()) {
			readCustomerDetailsFileComplete(readCust, custCount, fName, lName, age, nId, day, month, year, trash);
			setCustomerDetailsFileComplete(C, custCount, fName, lName, age, nId, day, month, year);
			fileCount++;
		}
	}
	C->setCustomerFileCount(fileCount);
	readCust.close();
}
void TMS::loadDriverDetailsFileFromMain()
{
	int dId = 1;
	char** lic_list;
	int noOfLic;
	float overallRank;
	float sal;
	int exp;
	int status;
	char fName[100];
	char lName[100];
	int day, month, year;
	int nId;
	int age;
	char trash;

	int fileCount = 0;
	lic_list = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		lic_list[i] = new char;
	}
	ifstream readDriv;
	readDriv.open("DriverDetails.txt");
	if (readDriv.is_open())
	{
		while (!readDriv.eof())
		{
			readDriverDetailsFile(readDriv, dId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year, trash);
			setDriverDetailsCompleteFile(D, dId, lic_list, noOfLic, overallRank, sal, exp,
				status, age, nId, fName, lName, day, month, year);
			fileCount++;
		}
	}
	D->setFileCountDriver(fileCount);
	readDriv.close();
}
void TMS::loadVehicleDetailsFileFromMain()
{
	int vId;
	int regNo;
	float mileage;
	char* lic_type = new char[20];
	bool stat;
	char* fuel_type = new char[10];
	float rank;
	int day;
	int month;
	int year;
	int fId;
	char descrip[100];
	float cost;
	char trash;
	ifstream readVehi;
	readVehi.open("VehicleDetails.txt");
	if (readVehi.is_open())
	{
		while (!readVehi.eof())
		{
			readVehicleDetailsCompleteFile(readVehi, vId, regNo, mileage, lic_type, stat, fuel_type, rank, day,
				month, year, fId, descrip, cost, trash);
			setVehicleDetailsCompleteFile(V, vId, regNo, mileage, lic_type, stat, fuel_type, rank, day, month,
				year, fId, descrip, cost);
		}
	}
	readVehi.close();
}
void TMS::loadRideFileFromMain()
{
	char* source = new char[100];
	char* destination = new char[100];
	float distance;
	bool statusOfR;
	float fuelRate;
	int sIDOfR;
	int cIDOfR;
	int dIDOfR;
	int vIDOfR;
	bool bookRide;
	int dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR;
	int noOfPass;
	char r_Type[50];
	float d_Rank;
	float v_Rank;
	int fileCount = 0;
	ifstream readRide;
	readRide.open("Ride.txt");
	if (readRide.is_open())
	{
		while (!readRide.eof())
		{
			readRideCompleteFile(readRide, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			setRideCompleteFile(R, noOfPass, r_Type, d_Rank, v_Rank, sIDOfR, cIDOfR, dIDOfR, vIDOfR, source, destination, fuelRate
				, distance, statusOfR, dayOfR, monthOfR, yearOfR, hrOfR, minOfR, secOfR, bookRide);
			fileCount++;
		}
	}
	R->setRideFileCount(fileCount);
	readRide.close();
}
void TMS::loadDeliveryFileFromMain()
{
	float goodW;
	char goodT[200];
	char source[100];
	char destination[100];
	float distance;
	bool statusOfDeli;
	float fuelRate;
	int sIDOfDeli;
	int cIDOfDeli;
	int dIDOfDeli;
	int vIDOfDeli;
	int dayOfDeli;
	int monthOfDeli;
	int yearOfDeli;
	int hrOfDeli;
	int minOfDeli;
	int secOfDeli;
	bool bookDeli;
	int fileCount = 0;
	ifstream readDeli;
	readDeli.open("Delivery.txt");
	if (readDeli.is_open())
	{
		while (!readDeli.eof())
		{
			readDeliveryCompleteFile(readDeli, goodW, goodT, sIDOfDeli, cIDOfDeli, dIDOfDeli, vIDOfDeli, source, destination, fuelRate
				, distance, statusOfDeli, dayOfDeli, monthOfDeli, yearOfDeli, hrOfDeli, minOfDeli, secOfDeli, bookDeli);
			setDeliveryCompleteFile(Deli, goodW, goodT, sIDOfDeli, cIDOfDeli, dIDOfDeli, vIDOfDeli, source, destination, fuelRate
				, distance, statusOfDeli, dayOfDeli, monthOfDeli, yearOfDeli, hrOfDeli, minOfDeli, secOfDeli, bookDeli);
			fileCount++;
		}
	}
	Deli->setDeliveryFileCount(fileCount);
	readDeli.close();
}



void printIntro()
{
	boldGreen();
	cout << "\t\t\tWELCOME TO THE CAR MANAGEMENT SYSTEM APP\n\n\n";
	cout << "DETAILS: \nThis application will help you to book Car Rides with various Varieties and Options\n";
	cout << "Like you can Book InterCity and IntraCity Transports with LTVs and HTVs\n\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	cout << "\t\t\tEnter any key to Begin\n\n\n";
}
void printMenu()
{
	reset();
	cout << "_________________________________________________________________________________________________\n";
	cout << "Enter 1: To Add a Customer\n";
	cout << "Enter 2: To Add or Remove a Driver\n";
	cout << "Enter 3: To Add or Remove a Vehicle\n";
	cout << "Enter 4: To print the Details of the Customer\n";
	cout << "Enter 5: To print the Detials of the Driver\n";
	cout << "Enter 6: To print Complete List of the Vehicle\n";
	cout << "Enter 7: To print complete Details of the Vehicles and Services\n";
	cout << "Enter 8: To print Complete History of a Perticular Customer\n";
	cout << "Enter 9: To print history of the Driver including the Services\n";
	cout << "Enter 10: To print list of the who have ranking above 4.5\n";
	cout << "Enter 11: To print list of all drivers who have multiple licenses\n";
	cout << "Enter 12: To print updated salary of the Driver based on its ranking\n";
	cout << "Enter 13: To Request a service (Ride or Delivery)\n";
	cout << "Enter 14: To Cancel a Service (Ride or Delivery)\n";
	cout << "Enter 15: To Complete a Service(Ride or Delivery)\n";
	cout << "Enter 16: To print detials of the Customer who used same vehicle on a different Date\n";
	cout << "Enter 17: To print list of all drivers who completed services on a single Date\n";
	cout << "Enter 18: To print all the pending requests on a perticulare Date\n";
	cout << "Enter 19: To print all the pending request of a perticular driver\n";
	cout << "Enter 20: To print all cancelled services by a Particular Driver\n";
}
void functionalitiesAccess(int selection)
{
	TMS* RUN = new TMS;
	//Loads and sets everything from the file
	RUN->loadCustomerDetailsFileFromMain();
	RUN->loadDeliveryFileFromMain();
	RUN->loadDriverDetailsFileFromMain();
	RUN->loadRideFileFromMain();
	RUN->loadVehicleDetailsFileFromMain();
	reset();
	switch (selection)
	{
	case 1:
	{
		RUN->addNewCustomer();
		break;
	}
	case 2:
	{
		RUN->addOrRemoveDriver();
		break;
	}
	case 3:
	{
		RUN->addOrRemoveVehicle();
		break;
	}
	case 4:
	{
		RUN->printCustomerDetials();
		break;
	}
	case 5:
	{
		RUN->printDriverDetails();
		break;
	}
	case 6:
	{
		RUN->printListOfTheVehicles();
		break;
	}
	case 7:
	{
		RUN->printDetailsHistoryVehicle();
		break;
	}
	case 8:
	{
		RUN->printHistoryOfCustomer();
		break;
	}
	case 9:
	{
		RUN->printCompleteHistoryOfDriver();
		break;
	}
	case 10:
	{
		RUN->printDrivers4Above();
		break;
	}
	case 11:
	{
		RUN->printMultipleLicenses();
		break;
	}
	case 12:
	{
		RUN->printUpdatedSalaryOfTheDriver();
		break;
	}
	case 13:
	{
		RUN->addServiceRequestForCustomer();
		break;
	}
	case 14:
	{
		RUN->cancelingBooking();
		break;
	}
	case 15:
	{
		RUN->completeService();
		break;
	}
	case 16:
	{
		RUN->printDetailsOfCustomerWhoUsedSameRideDiffDate();
		break;
	}
	case 17:
	{
		RUN->printDetailsOfDriverWhoCompleteServiceOnSameDay();
		break;
	}
	case 18:
	{
		RUN->printPendingRequestsParticularDate();
		break;
	}
	case 19:
	{
		RUN->printPendingServiceParticularDriver();
		break;
	}
	case 20:
	{
		RUN->printDetailsOfAllCancelledServicesByCustomer();
		break;
	}
	default:
		cout << "INVALID INPUT!!\n";
	}
}

int main()
{
	int selection = 0;
	printIntro();
	if (_getch())
	{
		boldYellow();

	}
	while (true)
	{
		printMenu();
		cout << "Enter your desired Input: ";
		cin >> selection;
		if (selection == -1)
		{
			break;
		}
		functionalitiesAccess(selection);
	}
	return 0;
}