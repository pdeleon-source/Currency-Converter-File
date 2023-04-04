//
// Created by pauld on 2/26/2023.
//
#include "Convert.h"
#include <iostream>
int main(){
    Convert conversion;
    double input;
    conversion.getExchangeAmount();

    // Declare all of the conversion methods within the Convert object
    conversion.getDollarsToEuros(input);
    conversion.getDollarsToPounds(input);
    conversion.getDollarsToYen(input);
    conversion.getDollarsToYuan(input);
    conversion.getDollarsToRubles(input);
    conversion.getDollarsToWon(input);
    conversion.getDollarsToRupees(input);

    conversion.getPoundsToDollars(input);
    conversion.getPoundsToEuros(input);
    conversion.getPoundsToYen(input);
    conversion.getPoundsToYuan(input);
    conversion.getPoundsToRubles(input);
    conversion.getPoundsToWon(input);
    conversion.getPoundsToRupees(input);

    conversion.getEurosToDollars(input);
    conversion.getEurosToPounds(input);
    conversion.getEurosToYen(input);
    conversion.getEurosToYuan(input);
    conversion.getEurosToRubles(input);
    conversion.getEurosToWon(input);
    conversion.getEurosToRupees(input);

    conversion.getYenToDollars(input);
    conversion.getYenToEuros(input);
    conversion.getYenToPounds(input);
    conversion.getYenToYuan(input);
    conversion.getYenToRubles(input);
    conversion.getYenToRupees(input);
    conversion.getYenToWon(input);

    conversion.getRublesToDollars(input);
    conversion.getRublesToEuros(input);
    conversion.getRublesToPounds(input);
    conversion.getRublesToYen(input);
    conversion.getRublesToYuan(input);
    conversion.getRublesToWon(input);
    conversion.getRublesToRupees(input);

    conversion.getWonToDollars(input);
    conversion.getWonToPounds(input);
    conversion.getWonToEuros(input);
    conversion.getWonToYen(input);
    conversion.getWonToYuan(input);
    conversion.getWonToRupees(input);
    conversion.getWonToRubles(input);

    conversion.getYuanToDollars(input);
    conversion.getYuanToEuros(input);
    conversion.getYuanToYen(input);
    conversion.getYuanToWon(input);
    conversion.getYuanToPounds(input);
    conversion.getYuanToRubles(input);
    conversion.getYuanToRupees(input);

    conversion.getRupeesToDollars(input);
    conversion.getRupeesToEuros(input);
    conversion.getRupeesToPounds(input);
    conversion.getRupeesToYen(input);
    conversion.getRupeesToYuan(input);
    conversion.getRupeesToRubles(input);
    conversion.getRupeesToWon(input);


    return 0;
}