#include <iostream>
#include <string>
using namespace std;

int main() {
    
    //Declaring Variables for components, power levels, efficiency, and total energy.
    std::string component1;
    std::string component2;
    std::string component3;

    double power_level_1;
    double power_level_2;
    double power_level_3;
    
    const double EFFICIENCY = 0.85;

    double total_energy;

    //User Input and Output.
    cout << "Stewie's Super Smart Energy Calculator!\n\nEnter the name of the first component: ";
    getline(cin >> ws, component1);
   
    cout << "Enter its power level(watts): ";
    cin >> power_level_1;
   
    cout << "Enter the name of the second component: ";
    getline(cin >> ws, component2);
    
    cout << "Enter its power level(watts): ";
    cin >> power_level_2;
    
    cout << "Enter the name of the third component: ";
    getline(cin >> ws, component3);
    
    cout << "Enter its power level(watts): ";
    cin >> power_level_3;
    
    //Calculating total energy consumption after efficiency.
    cout << "calculating..." << endl;
    total_energy = (power_level_1 + power_level_2 + power_level_3) * EFFICIENCY;
    
    //Displaying results.
    cout << "Component List:\n1. " << component1 << " - " << power_level_1 << " watts\n2. " 
         << component2 << " - " << power_level_2 << " watts\n3. " 
         << component3 << " - " << power_level_3 << " watts\n"
         << "Total energy consumption after efficiency: " << total_energy << " Watts\n\nStewie: Behold! A flawless calculation. Honestly, why aren't you all bowing already?" << endl;

    return 0;
}
