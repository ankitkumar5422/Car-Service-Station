#include <bits/stdc++.h>
#include <string>
#include <map>

using namespace std;

class CarType {
  public:
    virtual int getPrice(string serviceCode) = 0;
};


class Hatchback: public CarType {
  public:
    int getPrice(string serviceCode) {
     
      map<string, int> prices = {
        {"BS01", 2000},
        {"EF01", 5000},
        {"CF01", 2000},
        {"BF01", 1000},
        {"GF01", 3000}
      };
      return prices[serviceCode];
    }
};

// Derived class for sedan cars
class Sedan: public CarType {
  public:
    int getPrice(string serviceCode) {
      
      map<string, int> prices = {
        {"BS01", 4000},
        {"EF01", 8000},
        {"CF01", 4000},
        {"BF01", 1500},
        {"GF01", 6000}
      };
      return prices[serviceCode];
    }
};

// Derived class for SUV cars
class SUV: public CarType {
  public:
    int getPrice(string serviceCode) {

      map<string, int> prices = {
        {"BS01", 5000},
        {"EF01", 10000},
        {"CF01", 6000},
        {"BF01", 2500},
        {"GF01", 8000}
      };
      return prices[serviceCode];
    }
};

int main() {

  map<string, CarType*> carTypes = {
    {"Hatchback", new Hatchback()},
    {"Sedan", new Sedan()},
    {"SUV", new SUV()}
  };

  cout << "Enter type of car: ";
  string carType;
  cin >> carType;

  cout << "Enter service codes (separated by space): ";
  
  string serviceCode;
  int totalBill = 0;
  bool isFreeCleaning = false;


  while (cin >> serviceCode) {
    int servicePrice = carTypes[carType]->getPrice(serviceCode);
    if(serviceCode == "BS01"){
        cout << "Charges for Basic servicing = " << servicePrice <<endl;
    }
    
     if(serviceCode == "EF01"){
        cout << "Charges for Engine Fixing = " << servicePrice <<endl;
    }
    
     if(serviceCode == "CF01"){
        cout << "Charges for Clutch Fixing = " << servicePrice <<endl;
    }
    
     if(serviceCode == "BF01"){
        cout << "Charges for Break Fixing = " << servicePrice <<endl;
    }
    
     if(serviceCode == "GF01"){
        cout << "Charges for Gear Fixing = " << servicePrice <<endl;
    }
    totalBill = totalBill + servicePrice;
  }
  
  

   cout << "Total bill: " << totalBill << endl;
  if (totalBill > 10000) {
    isFreeCleaning = true;
  }

 
  if (isFreeCleaning) {
    cout << "Free cleaning service included." << endl;
  }
  

  return 0;
}