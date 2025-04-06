#ifndef TEAM_H
#define TEAM_H

#include "Role.h"
#include <memory>

class Team {
    std::unique_ptr<Role> A;
    std::unique_ptr<Role> B;
    std::unique_ptr<Role> C;
    double teamShield;

public:
    // Constructor with ownership transfer
    Team(std::unique_ptr<Role> a, std::unique_ptr<Role> b, std::unique_ptr<Role> c, double teamShield);

    // Rule of Five
    ~Team() = default;
    Team(const Team& other);                    // Deep copy
    Team(Team&& other) noexcept = default;      // Move
    Team& operator=(const Team& other);         // Copy assignment
    Team& operator=(Team&& other) noexcept = default; // Move assignment

    // Getters (return raw pointers for access)
    [[nodiscard]] Role* getA() const;
    [[nodiscard]] Role* getB() const;
    [[nodiscard]] Role* getC() const;
    [[nodiscard]] double getTeamShield() const;

    // Setters (take ownership)
    void setA(std::unique_ptr<Role> newA) noexcept;
    void setB(std::unique_ptr<Role> newB) noexcept;
    void setC(std::unique_ptr<Role> newC) noexcept;
    void setTeamShield(double shield) noexcept;

    std::string getMemberType(Role* member) const;
};

#endif // TEAM_H