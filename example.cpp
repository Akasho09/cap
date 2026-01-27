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
#include<iostream>
using namespace std;

class Attraction{
    string name;
    string category ;
    int fess ;
    int timeInHours;
    int rating;
public: 
    int getRating(){
        return rating;
    }
};

class itinerary {
    vector<Attraction>cities;
    int budget;
    int timeLimit;
public:
    itinerary(int b , int t){
        budget=b; timeLimit=t;
    }
    void addAttraction(Attraction&a){
        cities.push_back(a);
    }
    vector<Attraction> generateItinerary(){
        vector<Attraction>ans;

        sort(cities.begin(), cities.end() , []( Attraction&a , Attraction&b){
            return a.getRating()>b.getRating();
        });
        

    }
};

int main()
{
  
}
