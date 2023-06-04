#include <iostream>
#include <queue>
#include <string>

// Structure to represent a patient
struct Patient {
    std::string name;
    int priority;

    // Constructor
    Patient(const std::string& n, int p) : name(n), priority(p) {}

    // Overloading the greater-than operator for comparison
    bool operator>(const Patient& other) const {
        return priority > other.priority;
    }
};

int main() {
    std::priority_queue<Patient, std::vector<Patient>, std::greater<Patient> > hospitalQueue;

    int numPatients;
    std::cout << "Enter the number of patients: ";
    std::cin >> numPatients;

    for (int i = 0; i < numPatients; ++i) {
        std::string name;
        int priority;

        std::cout << "Enter the name of patient " << (i + 1) << ": ";
        std::cin >> name;

        std::cout << "Enter the priority of patient " << (i + 1) << " (1 for Serious, 2 for Non-serious, 3 for General Checkup): ";
        std::cin >> priority;

        hospitalQueue.push(Patient(name, priority));
    }

    std::cout << "\nServing patients:\n";
    while (!hospitalQueue.empty()) {
        Patient nextPatient = hospitalQueue.top();
        hospitalQueue.pop();

        std::cout << "Next patient: " << nextPatient.name << " (Priority: " << nextPatient.priority << ")\n";
    }

    return 0;
}

