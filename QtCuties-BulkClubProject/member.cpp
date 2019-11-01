#include "member.h"

Member::Member()
{

}

Member::~Member(){}

Member::Member(QString name, int membershipNumber, bool executiveMember)
{
    this->name = name;
    this->membershipNumber = membershipNumber;
    this->executiveMember = executiveMember;
    expDate = "12/31/20";
    totalSpent = 0.00;
    rebateAmount = 0.00;
}
