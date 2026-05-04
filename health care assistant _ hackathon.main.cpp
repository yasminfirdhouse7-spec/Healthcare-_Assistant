version 1

#include<iostream>
using namespace std;
int main(){
char fever, cough, headache, stomach_pain;
cout<<"===Basic Healthcare Assistant===\n";
cout<<"Answer with (y/n)\n";
cout<<"Do you have fever?";
cin>>fever;
cout<<"Do you have cough? ";
cin>>cough;
cout<<"Do you have headache? ";
cin>>headache;
cout<<"Do you have stomach_pain? ";
cin>>stomach_pain; 
cout<<"\n===== Result=====\n";
if(fever == 'y' && cough == 'y' && headache == 'y' && stomach_pain == 'y')
{
cout<<"Possible COVID 19\n";
}
else if ( fever == 'y' && cough == 'y' && headache == 'y')
{ 
cout<<"Possible Viral Fever\n";
}
else if ( fever == 'y' && cough == 'y')
{
cout<<"Possible Flu\n";
}
else if  ( fever == 'y' )
{
cout<<"Possible Mild Fever\n ";
}
else
{
cout<<"No Major Issues\n ";
}

return 0;
}


Version 2


#include <iostream>
#include <fstream>
using namespace std;

// Diagnose function
string diagnose(bool fever, bool cough, bool fatigue, bool headache, bool breath, bool chest) {
    int viral = 0, covid = 0, heart = 0;

    if (fever) {
        viral++;
        covid++;
    }
    if (cough) {
        viral++;
        covid++;
    }
    if (fatigue) {
        viral++;
        covid++;
    }
    if (headache) viral++;
    if (breath) covid++;
    if (chest) heart++;

    if (covid >= 4)
        return "Possible COVID-19";
    else if (viral >= 3)
        return "Viral Infection";
    else if (heart >= 2)
        return "Heart Risk";
    else
        return "No major issue";
}

// Risk function
string getRisk(bool fever, bool cough, bool fatigue, bool breath, bool chest) {
    int score = 0;

    if (fever) score++;
    if (cough) score++;
    if (fatigue) score++;
    if (breath) score += 2;
    if (chest) score += 2;

    if (score >= 5)
        return "HIGH";
    else if (score >= 3)
        return "MEDIUM";
    else
        return "LOW";
}

// Advice function
string getAdvice(string risk) {
    if (risk == "HIGH")
        return "Seek medical attention immediately!";
    else if (risk == "MEDIUM")
        return "Take rest and monitor symptoms.";
    else
        return "Stay healthy and hydrated.";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Healthcare Assistant =====\n";
        cout << "1. New Patient Check\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int age;
            char fever, cough, fatigue, headache, breath, chest;

            cout << "\nEnter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;

            cout << "\nAnswer with (y/n)\n";
            cout << "Fever: ";
            cin >> fever;
            cout << "Cough: ";
            cin >> cough;
            cout << "Fatigue: ";
            cin >> fatigue;
            cout << "Headache: ";
            cin >> headache;
            cout << "Shortness of breath: ";
            cin >> breath;
            cout << "Chest pain: ";
            cin >> chest;

            // Convert to bool
            bool f = (fever == 'y');
            bool c = (cough == 'y');
            bool fa = (fatigue == 'y');
            bool h = (headache == 'y');
            bool b = (breath == 'y');
            bool ch = (chest == 'y');

            // Count symptoms
            int symptomCount = f + c + fa + h + b + ch;

            string result = diagnose(f, c, fa, h, b, ch);
            string risk = getRisk(f, c, fa, b, ch);
            string advice = getAdvice(risk);

            cout << "\n===== HEALTH REPORT =====\n";
            cout << "Patient: " << name << " | Age: " << age << endl;
            cout << "Symptoms Selected: " << symptomCount << endl;
            cout << "Condition: " << result << endl;
            cout << "Risk Level: " << risk << endl;
            cout << "Advice: " << advice << endl;
            cout << "=========================\n";

            // Save to file
            ofstream file("patients.txt", ios::app);
            file << "Name: " << name
                 << ", Age: " << age
                 << ", Symptoms: " << symptomCount
                 << ", Result: " << result
                 << ", Risk: " << risk << endl;
            file.close();

            cout << "✔ Data saved successfully!\n";
        }

        else if (choice == 2) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}



    
    