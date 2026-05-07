#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

// Diagnose function
string diagnose(int score) {
    if (score >= 8)
        return "Possible COVID-19";
    else if (score >= 5)
        return "Viral Infection";
    else if (score >= 3)
        return "Mild Illness";
    else
        return "No major issue";
}

// Risk function
string getRisk(int score) {
    if (score >= 8)
        return "HIGH";
    else if (score >= 5)
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

// Safe yes/no
bool isYes(char ch) {
    return (ch == 'y' || ch == 'Y');
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Healthcare Assistant =====\n";
        cout << "1. New Patient Check\n";
        cout << "2. View Saved Records\n";
        cout << "3. Reset Database\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (choice == 1) {
            string name;
            int age;
            char fever, cough, fatigue, headache, breath, chest;

            // Date & Time
            time_t now = time(0);
            char* dt = ctime(&now);
            dt[strlen(dt)-1] = '\0';

            cout << "\nDate & Time: " << dt << endl;

            cin.ignore(1000, '\n');
            cout << "Enter Full Name: ";
            getline(cin, name);

            if (name.empty()) {
                cout << "Invalid name! Try again.\n";
                continue;
            }

            cout << "Enter Age: ";
            cin >> age;

            if (cin.fail() || age <= 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid age! Try again.\n";
                continue;
            }

            cout << "\nAnswer with (y/n)\n";

            cout << "Fever: "; cin >> fever;
            cout << "Cough: "; cin >> cough;
            cout << "Fatigue: "; cin >> fatigue;
            cout << "Headache: "; cin >> headache;
            cout << "Shortness of breath: "; cin >> breath;
            cout << "Chest pain: "; cin >> chest;

            // Convert
            bool f = isYes(fever);
            bool c = isYes(cough);
            bool fa = isYes(fatigue);
            bool h = isYes(headache);
            bool b = isYes(breath);
            bool ch = isYes(chest);

            // Weighted scoring
            int score = 0;
            if (f) score += 2;
            if (c) score += 2;
            if (fa) score += 1;
            if (h) score += 1;
            if (b) score += 3;
            if (ch) score += 3;

            int symptomCount = f + c + fa + h + b + ch;

            string result = diagnose(score);
            string risk = getRisk(score);
            string advice = getAdvice(risk);

            float confidence = (score / 12.0) * 100;
            if (confidence > 100) confidence = 100;

            // 🔥 PUSH OUTPUT ABOVE KEYBOARD
            cout << string(25, '\n');

            cout << "===== HEALTH REPORT =====\n";
            cout << "Patient: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Symptoms Selected: " << symptomCount << endl;
            cout << "Condition: " << result << endl;
            cout << "Risk Level: " << risk << endl;
            cout << "Confidence: " << confidence << "%\n";
            cout << "Advice: " << advice << endl;
            cout << "=========================\n";

            // Save data
            ofstream file("patients.txt", ios::app);
            file << "----------------------------------\n";
            file << "Date: " << dt << "\n";
            file << "Name: " << name << "\n";
            file << "Age: " << age << "\n";
            file << "Symptoms: " << symptomCount << "\n";
            file << "Score: " << score << "\n";
            file << "Result: " << result << "\n";
            file << "Risk: " << risk << "\n";
            file << "Confidence: " << confidence << "%\n";
            file << "----------------------------------\n\n";
            file.close();

            cout << "✔ Data saved successfully!\n";
        }

        else if (choice == 2) {
            ifstream readFile("patients.txt");
            string line;

            cout << "\n===== SAVED RECORDS =====\n";

            if (!readFile || readFile.peek() == EOF) {
                cout << "No records found.\n";
            } else {
                while (getline(readFile, line)) {
                    cout << line << endl;
                }
            }

            readFile.close();
        }

        else if (choice == 3) {
            ofstream file("patients.txt");
            file.close();
            cout << "✔ Database cleared successfully!\n";
        }

        else if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
	
