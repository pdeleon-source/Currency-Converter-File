//
// Created by pauld on 2/14/2023.
//

#ifndef M2OEP_PDELEON2_CONVERT_H
#define M2OEP_PDELEON2_CONVERT_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::left;
using std::ostream;
using std::right;
using std::setw;
using std::string;
using std::vector;


class Convert {
private:
    double exchangeAmount;


public:
    Convert();
    Convert(double exchangeAmount);

    double getExchangeAmount() const;

    void setExchangeAmount(double exchangeAmount);

    double getDollarsToEuros(double input);
    double getDollarsToPounds(double input);
    double getDollarsToYen(double input);
    double getDollarsToYuan(double input);
    double getDollarsToRubles(double input);
    double getDollarsToWon(double input);
    double getDollarsToRupees(double input);

    double getPoundsToDollars(double input);
    double getPoundsToEuros(double input);
    double getPoundsToYen(double input);
    double getPoundsToYuan(double input);
    double getPoundsToRubles(double input);
    double getPoundsToWon(double input);
    double getPoundsToRupees(double input);

    double getEurosToDollars(double input);
    double getEurosToPounds(double input);
    double getEurosToYen(double input);
    double getEurosToYuan(double input);
    double getEurosToRubles(double input);
    double getEurosToWon(double input);
    double getEurosToRupees(double input);

    double getYenToDollars(double input);
    double getYenToEuros(double input);
    double getYenToPounds(double input);
    double getYenToYuan(double input);
    double getYenToRubles(double input);
    double getYenToRupees(double input);
    double getYenToWon(double input);

    double getRublesToDollars(double input);
    double getRublesToEuros(double input);
    double getRublesToPounds(double input);
    double getRublesToYen(double input);
    double getRublesToYuan(double input);
    double getRublesToWon(double input);
    double getRublesToRupees(double input);

    double getWonToDollars(double input);
    double getWonToPounds(double input);
    double getWonToEuros(double input);
    double getWonToYen(double input);
    double getWonToYuan(double input);
    double getWonToRupees(double input);
    double getWonToRubles(double input);

    double getYuanToDollars(double input);
    double getYuanToEuros(double input);
    double getYuanToYen(double input);
    double getYuanToWon(double input);
    double getYuanToPounds(double input);
    double getYuanToRubles(double input);
    double getYuanToRupees(double input);

    double getRupeesToDollars(double input);
    double getRupeesToEuros(double input);
    double getRupeesToPounds(double input);
    double getRupeesToYen(double input);
    double getRupeesToYuan(double input);
    double getRupeesToRubles(double input);
    double getRupeesToWon(double input);

    // How to actually implement overloaded operators?
    friend ostream& operator << (ostream& outs, const Convert &lec);
    friend bool operator == (const Convert &lhs, const Convert &rhs);
    friend ostream  operator * (const Convert &lhs, const Convert &rhs);
};



#endif //M2OEP_PDELEON2_CONVERT_H
