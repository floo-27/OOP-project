#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Definition of the structure for an event
struct Event {
    string title;          // Title of the event
    string description;    // Description of the event
    string startTime;      // Start time of the event
    string endTime;        // End time of the event
    string contactInfo;    // Contact information of the professor or TA

    // Constructor to initialize an event with the provided details
    Event(string t, string d, string start, string end, string contact)
    : title(t), description(d), startTime(start), endTime(end), contactInfo(contact) {}
};

// Class to handle the calendar
class Calendar {
private:
    vector<Event> events;  // Vector to store events

public:
    // Method to add an event to the calendar
    void addEvent(const Event& event) {
        events.push_back(event);  // Add the event to the vector of events
    }

    // Method to show the events
    void showEvents() {
        // Iterate through all events in the vector
        for (size_t i = 0; i < events.size(); ++i) {
            const Event& event = events[i];  // Get the current event
            // Display the details of the event
            cout << "Title: " << event.title << "\n"
                 << "Description: " << event.description << "\n"
                 << "Start: " << event.startTime << "\n"
                 << "End: " << event.endTime << "\n"
                 << "Contact: " << event.contactInfo << "\n\n";
        }
    }
};

// User interface to interact with the calendar
void runCalendarUI(Calendar& calendar) {
    while (true) {  // Infinite loop for the user interface
        cout << "1. Add event\n";   // Option to add an event
        cout << "2. Show events\n"; // Option to show events
        cout << "3. Exit\n";        // Option to exit
        int choice;
        cin >> choice;       // Read the user's choice
        cin.ignore();        // Ignore the remaining newline character in the input buffer

        if (choice == 1) {  // If the option is to add an event
            string title, desc, start, end, contact;
            cout << "Enter event title: ";  // Ask for the event title
            getline(cin, title);            // Read the title
            cout << "Enter description: ";  // Ask for the event description
            getline(cin, desc);             // Read the description
            cout << "Start time (HH:MM): "; // Ask for the event start time
            getline(cin, start);            // Read the start time
            cout << "End time (HH:MM): ";   // Ask for the event end time
            getline(cin, end);              // Read the end time
            cout << "Professors name: ";// Ask for the contact information
            getline(cin, contact);          // Read the contact information
            // Add the event to the calendar
            calendar.addEvent(Event(title, desc, start, end, contact));
        } else if (choice == 2) {  // If the option is to show events
            calendar.showEvents(); // Show the events
        } else if (choice == 3) {  // If the option is to exit
            break;  // Break the loop and exit the program
        }
    }
}

int main() {
    Calendar myCalendar;     // Create an instance of the calendar
    runCalendarUI(myCalendar);// Run the calendar user interface
    return 0;  // Return 0 indicating the program ended successfully
}




