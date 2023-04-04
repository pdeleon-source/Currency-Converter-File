//
// Created by pauld on 2/14/2023.
//
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Convert.h"

// Constructors
Convert::Convert() {
    exchangeAmount = 33.5;
}

Convert::Convert(double exchangeAmount){
    setExchangeAmount(exchangeAmount);
}

// Getter for exchange amount
double Convert::getExchangeAmount() const {
    return exchangeAmount;
}

// Setter for exchange amount
void Convert::setExchangeAmount(double outcome){
    this->exchangeAmount = outcome;
}


// Equations for the currency conversions are done here. The user input will be multiplied
// by the exchange rate between the two currencies
double Convert::getDollarsToEuros(double input){
    input = exchangeAmount * 0.93;
    return input;
    // Exchange rate = 1.09
}
double Convert::getDollarsToPounds(double input){
    input = exchangeAmount * 0.83;
    return input;
    // exchange rate = 1.20
}
double Convert::getDollarsToRubles(double input){
    input = exchangeAmount * 73.75;
    return input;
    // exchange rate = 0.01356
}
double Convert::getDollarsToYuan(double input){
    input = exchangeAmount * 6.92;
    return input;
    // exchange rate = 0.14
}
double Convert::getDollarsToYen(double input){
    input = exchangeAmount * 131;
    return input;
    // exchange rate = 0.0076
}
double Convert::getDollarsToWon(double input){
    input = exchangeAmount * 1232.47;
    return input;
    // exchange rate = 0.01
}
double Convert::getDollarsToRupees(double input){
    input = exchangeAmount * 82.83;
    return input;
    // Exchange rate = 1.09
}

double Convert::getEurosToDollars(double input){
    input = exchangeAmount * 1.09;
    return input;
    // exchange rate = 0.01
}
double Convert::getEurosToPounds(double input){
    input = exchangeAmount * 0.88;
    return input;
}
double Convert::getEurosToRubles(double input){
    input = exchangeAmount * 76.65;
    return input;
}
double Convert::getEurosToYuan(double input){
    input = exchangeAmount * 7.34;
    return input;
}
double Convert::getEurosToYen(double input){
    input = exchangeAmount * 141.43;
    return input;
}
double Convert::getEurosToWon(double input){
    input = exchangeAmount * 1338.59;
    return input;
}
double Convert::getEurosToRupees(double input){
    input = exchangeAmount * 89.01;
    return input;
    // Exchange rate = 1.09
}

double Convert::getPoundsToDollars(double input){
    input = exchangeAmount * 1.23;
    return input;
}
double Convert::getPoundsToEuros(double input){
    input = exchangeAmount * 1.13;
    return input;
}
double Convert::getPoundsToRubles(double input){
    input = exchangeAmount * 86.94;
    return input;
}
double Convert::getPoundsToYen(double input){
    input = exchangeAmount * 160.38;
    return input;
}
double Convert::getPoundsToYuan(double input){
    input = exchangeAmount * 8.32;
    return input;
}
double Convert::getPoundsToWon(double input){
    input = exchangeAmount * 1518.28;
    return input;
}
double Convert::getPoundsToRupees(double input){
    input = exchangeAmount * 99.13;
    return input;
    // Exchange rate = 1.09
}

double Convert::getRublesToDollars(double input){
    input = exchangeAmount * 0.014;
    return input;
    // exchange rate = 0.01
}
double Convert::getRublesToPounds(double input){
    input = exchangeAmount * 0.011;
    return input;

}
double Convert::getRublesToEuros(double input){
    input = exchangeAmount * 0.013;
    return input;

}
double Convert::getRublesToYen(double input){
    input = exchangeAmount * 1.84;
    return input;
}
double Convert::getRublesToYuan(double input){
    input = exchangeAmount * 0.096;
    return input;
}
double Convert::getRublesToWon(double input){
    input = exchangeAmount * 17.46;
    return input;
}
double Convert::getRublesToRupees(double input){

    input = exchangeAmount * 1.16;
    return input;

}

double Convert::getYenToDollars(double input){
    input = exchangeAmount * 0.0077;
    return input;
    // exchange rate = input /
    // exchange rate = 0.01
}
double Convert::getYenToPounds(double input){
    input = exchangeAmount * 0.0062;
    return input;
}
double Convert::getYenToEuros(double input){
    input = exchangeAmount * 0.0071;
    return input;
}
double Convert::getYenToYuan(double input){
    input = exchangeAmount * 0.052;
    return input;
}
double Convert::getYenToRubles(double input){
    input = exchangeAmount * 0.54;
    return input;
}
double Convert::getYenToWon(double input){
    input = exchangeAmount * 9.47;
    return input;
}
double Convert::getYenToRupees(double input){
    input = exchangeAmount * 0.63;
    return input;
}

double Convert::getYuanToDollars(double input){
    input = exchangeAmount * 0.15;
    return input;
}
double Convert::getYuanToEuros(double input){
    input = exchangeAmount * 0.14;
    return input;
}
double Convert::getYuanToPounds(double input){
    input = exchangeAmount * 0.12;
    return input;
}
double Convert::getYuanToRubles(double input){
    input = exchangeAmount * 10.45;
    return input;
}
double Convert::getYuanToYen(double input){
    input = exchangeAmount * 19.26;
    return input;
}
double Convert::getYuanToWon(double input){
    input = exchangeAmount * 182.44;
    return input;
}
double Convert::getYuanToRupees(double input){
    input = exchangeAmount * 12.14;
    return input;
}


double Convert::getRupeesToDollars(double input) {
    input = exchangeAmount * 0.00081;
    return input;
}
double Convert::getRupeesToPounds(double input) {
    input = exchangeAmount * 0.010;
    return input;
}
double Convert::getRupeesToEuros(double input) {
    input = exchangeAmount * 0.011;
    return input;
}
double Convert::getRupeesToRubles(double input) {
    input = exchangeAmount * 0.86;
    return input;
}
double Convert::getRupeesToYuan(double input) {
    input = exchangeAmount * 0.082;
    return input;
}
double Convert::getRupeesToYen(double input) {
    input = exchangeAmount * 1.60;
    return input;
}
double Convert::getRupeesToWon(double input){
    input = exchangeAmount * 15.17;
    return input;
}

double Convert::getWonToDollars(double input) {
    input = exchangeAmount * 0.00081;
    return input;
}
double Convert::getWonToPounds(double input) {
    input = exchangeAmount * 0.00066;
    return input;
}
double Convert::getWonToEuros(double input) {
    input = exchangeAmount * 0.00075;
    return input;
}
double Convert::getWonToRubles(double input) {
    input = exchangeAmount * 0.057;
    return input;
}
double Convert::getWonToYuan(double input) {
    input = exchangeAmount * 0.0055;
    return input;
}
double Convert::getWonToYen(double input) {
    input = exchangeAmount * 0.11;
    return input;
}
double Convert::getWonToRupees(double input){
    input = exchangeAmount * 0.066;
    return input;
}

ostream& operator << (ostream& outs, const Convert &con) {
    outs << setw(25) << left << con.getExchangeAmount();
    return outs;
}

bool operator == (const Convert &lhs, const Convert &rhs) {
    return lhs.exchangeAmount == rhs.exchangeAmount;
}

