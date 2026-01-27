/*
OOPs based question:

Given the data of players which include:
Age
Rating
Name
Bowling-style(left or right)
Batting-style(spin or pace)
Write an implementation to return a team of 11 players having a good mix of left and right-handed players spinners pace ballers and all-rounders of mixed-age groups.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ENUMS */
enum class BowlingStyle { SPIN, PACE, NONE };
enum class BattingStyle { LEFT, RIGHT };
enum class Role { BATSMAN, BOWLER, ALL_ROUNDER };

/* PLAYER CLASS */
class Player {
public:
    int age;
    int rating;
    string name;
    BowlingStyle bowling;
    BattingStyle batting;
    Role role;

    Player(string n, int a, int r, BowlingStyle bw, BattingStyle bt, Role rl)
        : name(n), age(a), rating(r), bowling(bw), batting(bt), role(rl) {}
};

/* TEAM CLASS */
class Team {
    vector<Player> players;

public:
    Team(const vector<Player>& p) : players(p) {}

    vector<Player> getGoodMixTeam() {
        vector<Player> team;

        // Sort players by rating (descending)
        sort(players.begin(), players.end(),
             [](const Player& a, const Player& b) {
                 return a.rating > b.rating;
             });

        int leftBat = 0, rightBat = 0;
        int spinners = 0, pacers = 0;
        int allRounders = 0;
        bool young = false, prime = false, senior = false;

        for (const Player& p : players) {
            if (team.size() == 11) break;

            // Count checks (temporary)
            int l = leftBat + (p.batting == BattingStyle::LEFT);
            int r = rightBat + (p.batting == BattingStyle::RIGHT);

            int s = spinners + (p.bowling == BowlingStyle::SPIN);
            int pc = pacers + (p.bowling == BowlingStyle::PACE);

            int ar = allRounders + (p.role == Role::ALL_ROUNDER);

            bool y = young || p.age < 25;
            bool pr = prime || (p.age >= 25 && p.age <= 32);
            bool sr = senior || p.age > 32;

            // Constraint guards
            if (l > 6 || r > 6) continue;
            if (s + pc > 7 && p.role == Role::BOWLER) continue;

            // Accept player
            team.push_back(p);

            leftBat = l;
            rightBat = r;
            spinners = s;
            pacers = pc;
            allRounders = ar;
            young = y;
            prime = pr;
            senior = sr;
        }

        return team;
    }
};

/* MAIN */
int main() {
    vector<Player> pool = {
        {"Rohit", 36, 92, BowlingStyle::NONE, BattingStyle::RIGHT, Role::BATSMAN},
        {"Virat", 35, 95, BowlingStyle::NONE, BattingStyle::RIGHT, Role::BATSMAN},
        {"Jadeja", 34, 90, BowlingStyle::SPIN, BattingStyle::LEFT, Role::ALL_ROUNDER},
        {"Hardik", 30, 88, BowlingStyle::PACE, BattingStyle::RIGHT, Role::ALL_ROUNDER},
        {"Ashwin", 37, 89, BowlingStyle::SPIN, BattingStyle::RIGHT, Role::BOWLER},
        {"Bumrah", 31, 94, BowlingStyle::PACE, BattingStyle::RIGHT, Role::BOWLER},
        {"Shami", 33, 91, BowlingStyle::PACE, BattingStyle::RIGHT, Role::BOWLER},
        {"Kuldeep", 29, 87, BowlingStyle::SPIN, BattingStyle::LEFT, Role::BOWLER},
        {"Gill", 24, 90, BowlingStyle::NONE, BattingStyle::RIGHT, Role::BATSMAN},
        {"Pant", 26, 89, BowlingStyle::NONE, BattingStyle::LEFT, Role::BATSMAN},
        {"Surya", 32, 88, BowlingStyle::NONE, BattingStyle::RIGHT, Role::BATSMAN},
        {"Axar", 30, 86, BowlingStyle::SPIN, BattingStyle::LEFT, Role::ALL_ROUNDER}
    };

    Team t(pool);
    vector<Player> bestTeam = t.getGoodMixTeam();

    cout << "Selected Team:\n";
    for (const Player& p : bestTeam) {
        cout << p.name << " | Age: " << p.age << " | Rating: " << p.rating << endl;
    }

    return 0;
}
