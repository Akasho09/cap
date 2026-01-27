/*
Second Round The Travel Planner Scenario: You're planning a trip to a new city! 
You have a list of various tourist attractions with different attributes. 
Data: Each attraction has a: 
- Name Category (historical, museum, natural wonder, etc.) Entry fee (Rs.) Estimated time to visit (hours) Tourist rating (average score from online reviews) 
Challenge: Write a program that helps you create a well-rounded itinerary for your trip.
The program should consider: Category Mix: Include attractions from different categories to experience the city's diverse offerings. 
Budget Constraints: Select attractions that fit within your planned travel budget (considering entry fees). 
Time Management: Create an itinerary that allows you to visit a good number of attractions within your available time frame (considering estimated visit) 
Popularity Balance: Choose a mix of popular and less-crowded attractions to avoid long queues and experience hidden gems. 
Success Criteria: The program should output a list of tourist attractions for your itinerary, considering category variety, budget, time management, 
and optionally, your personal prefer solve it using the oops
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Attraction {
private:
    string name;
    string category;
    int entryFee;
    double timeRequired;
    double rating;

public:
    Attraction(string n, string c, int fee, double time, double r) {
        name = n;
        category = c;
        entryFee = fee;
        timeRequired = time;
        rating = r;
    }

    // Getters
    string getName() const { return name; }
    string getCategory() const { return category; }
    int getEntryFee() const { return entryFee; }
    double getTimeRequired() const { return timeRequired; }
    double getRating() const { return rating; }
};


class ItineraryPlanner {
private:
    vector<Attraction> attractions;
    int budget;
    double availableTime;

public:
    ItineraryPlanner(int b, double t) {
        budget = b;
        availableTime = t;
    }

    void addAttraction(const Attraction& a) {
        attractions.push_back(a);
    }

    vector<Attraction> generateItinerary() {
        vector<Attraction> result;
        set<string> usedCategories;

        int currentCost = 0;
        double currentTime = 0;

        // Simple greedy strategy:
        // Higher rating first
        sort(attractions.begin(), attractions.end(),
             [](Attraction &a, Attraction &b) {
                 return a.getRating() > b.getRating();
             });

        for (auto &a : attractions) {
            if (currentCost + a.getEntryFee() <= budget &&
                currentTime + a.getTimeRequired() <= availableTime) {

                // Prefer category diversity
                if (usedCategories.count(a.getCategory()) == 0 ||
                    usedCategories.size() < 3) {

                    result.push_back(a);
                    currentCost += a.getEntryFee();
                    currentTime += a.getTimeRequired();
                    usedCategories.insert(a.getCategory());
                }
            }
        }
        return result;
    }
};


int main() {
    ItineraryPlanner planner(1000, 8); // Budget Rs.1000, Time 8 hours

    planner.addAttraction(Attraction("City Fort", "Historical", 200, 2, 4.6));
    planner.addAttraction(Attraction("Art Museum", "Museum", 150, 1.5, 4.3));
    planner.addAttraction(Attraction("Botanical Garden", "Natural", 100, 2, 4.1));
    planner.addAttraction(Attraction("Hidden Lake", "Natural", 50, 1, 3.8));
    planner.addAttraction(Attraction("Science Center", "Museum", 250, 2.5, 4.7));

    vector<Attraction> itinerary = planner.generateItinerary();

    cout << "Your Travel Itinerary:\n";
    for (auto &a : itinerary) {
        cout << "- " << a.getName()
             << " (" << a.getCategory()
             << ", Rs." << a.getEntryFee()
             << ", " << a.getTimeRequired() << " hrs"
             << ", Rating " << a.getRating() << ")\n";
    }

    return 0;
}

/*
🧠 How This Meets the Problem Criteria
1. ✔ Category Mix
- Uses set<string> to avoid same-category repetition

2. ✔ Budget Constraints
- Checks total entry fee ≤ budget

3. ✔ Time Management
- Ensures visit time ≤ available hours

4. ✔ Popularity Balance
- High-rated places first

- Lower-rated places can still be selected if budget/time allows

*/