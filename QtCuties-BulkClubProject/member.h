#ifndef MEMBER_H
#define MEMBER_H
#include <QString>
using namespace std;

class Member
{
private:
   QString name;
   int membershipNumber;
   bool executiveMember; // True for executive, false for standard.
   QString expDate;
   double totalSpent;
   double rebateAmount;

public:
    Member();
    ~Member();
    Member(QString name, int membershipNumber, bool executiveMember);
};

#endif // MEMBER_H

