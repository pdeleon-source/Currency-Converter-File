//
// Created by pauld on 2/14/2023.
//
//
// Currency converter
#include <iostream>
#include <fstream>
#include "Convert.h"
using namespace std;

int main() {
    bool keepGoing = true;
    while (keepGoing == true) {
        string choiceOne;
        int trueChoiceOne = 0;
        // Provide the list of currencies to choose from. The user will have to choose from numbers one to eight
        cout << "Please select the number on the list of currencies to choose from." << endl;
        cout << "This is the currency you would like to convert from." << endl;
        cout << "1.Dollars" << endl;
        cout << "2.Pounds" << endl;
        cout << "3.Euros" << endl;
        cout << "4.Yen" << endl;
        cout << "5.Yuan" << endl;
        cout << "6.Rubles" << endl;
        cout << "7.Won" << endl;
        cout << "8.Indian Rupees" << endl;

        bool isValidInt = false;
        getline(cin, choiceOne);
        // Input validation. Whitespace, strings, and doubles are not allowed
        while (!(isValidInt)) {
            isValidInt = true;
            for (int y = 0; y < choiceOne.length(); y++) {
                int tempVal;
                stringstream ff;
                ff << choiceOne[y];
                ff >> tempVal;
                if (isalpha(choiceOne[y]) || choiceOne[y] == ' ' || choiceOne[y] == '.') {
                    isValidInt = false;
                }

            }
            // Turn the input into an integer and test to see if it falls into the proper range of options
            if (isValidInt == true) {
                int newValue;
                stringstream ee;
                ee << choiceOne;
                ee >> newValue;
                if (newValue > 8 || newValue < 1) {
                    isValidInt = false;
                }
            }
            // The error message
            if (isValidInt == false) {
                cout << "Please enter a valid number: ";
                getline(cin, choiceOne);
            }
        }

        stringstream ss;
        ss << choiceOne;
        ss >> trueChoiceOne;

        // This list is given again, but this time to choose which currency to convert to
        cout << "Please select the number on the list of currencies to choose from." << endl;
        cout << "This is the currency you would like to convert to." << endl;
        cout << "1.Dollars" << endl;
        cout << "2.Pounds" << endl;
        cout << "3.Euros" << endl;
        cout << "4.Yen" << endl;
        cout << "5.Yuan" << endl;
        cout << "6.Rubles" << endl;
        cout << "7.Won" << endl;
        cout << "8.Indian Rupees" << endl;

        // The same input validation used on the first choice will be used again
        string secondChoice;
        int trueSecondChoice = 0;
        bool isSecondValidInt = false;
        getline(cin, secondChoice);
        while (!(isSecondValidInt)) {
            isSecondValidInt = true;
            for (int y = 0; y < secondChoice.length(); y++) {
                int secondTempVal;
                stringstream ee;
                ee << secondChoice[y];
                ee >> secondTempVal;
                if (isalpha(secondChoice[y]) || secondChoice[y] == ' ' || secondChoice[y] == '.') {
                    isSecondValidInt = false;
                }
            }
            if (isSecondValidInt == true) {
                int secondNewValue;
                stringstream ll;
                ll << secondChoice;
                ll >> secondNewValue;
                if (secondNewValue > 8 || secondNewValue < 1) {
                    isSecondValidInt = false;
                }
            }
            if (isSecondValidInt == false) {
                cout << "Please enter a valid number: ";
                getline(cin, secondChoice);
            }
        }

        stringstream gg;
        gg << secondChoice;
        gg >> trueSecondChoice;


        Convert theConversion = Convert();
        string fileDecision;
        // It now asks whether the user would like to enter a lsit of values to convert, or just one
        cout << "Would you like to convert a list, or a single value?(enter 'list' or 'single')" << endl;
        cout << "If you would like to enter a list, please enter the numbers into the text file." << endl;
        // Any input that does not include the word list or single will be rejected. It is not case sensitive
        while (!(cin >> fileDecision) || (fileDecision != "List" && fileDecision != "list" && fileDecision
        != "Single" && fileDecision != "single")) {
            cin.clear();
            //string junk;
            cout << "Please enter a valid option: ";

        }


        // It then asks the amount you want the conversion to be done with. No letters or negative numbers allowed
        double exchangeAmount;
        // Declare a vector of exchnage amounts
        vector<double> exchangeAmounts;
        if (fileDecision == "List" || fileDecision == "list") {
            //open file and use for to read through it
            double what = 0;

            // Open the file and read through it. At the same time adding the files to the vector
            fstream wfile;
            wfile.open("../NumberList.txt", ios::out | ios::in);
            while(wfile.peek() != EOF){
                wfile >> what;
                exchangeAmounts.push_back(what);
            }
            exchangeAmounts.erase(exchangeAmounts.end() - 1);
            wfile.close();

        } else {
            // In case the user rejects a list of values, it will only ask for a single value
            cout << "Enter the amount you would like to exchange." << endl;
            while (!(cin >> exchangeAmount) || exchangeAmount < 0) {
                cin.clear();
                string junk;
                cout << "Please enter a valid number ";
                getline(cin, junk);
            }
        }


        // Judging on the currencies chosen, it will call the appropriate function, and provide the output.
        // If the user asks for a list of values, then we iterate through the vector and run each value through
        // the conversion method
        if (trueChoiceOne == 1 && trueSecondChoice == 2) {
            // getDollarsToPounds(exchangeAmount);
            if (fileDecision == "single" || fileDecision == "Single") {
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getDollarsToPounds(exchangeAmount);
                cout << exchangeAmount << " dollars will be " << output << " British Pound Sterling" << endl;
            } else {
                for (int i = 0; i < exchangeAmounts.size(); i++) {
                    theConversion.setExchangeAmount(exchangeAmounts[i]);
                    double output = theConversion.getDollarsToPounds(exchangeAmounts[i]);
                    cout << exchangeAmounts[i] << " dollars will be " << output << " British Pound Sterling" << endl;
                }
            }
        }
            if (trueChoiceOne == 1 && trueSecondChoice == 3) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getDollarsToEuros(exchangeAmount);
                    cout << exchangeAmount << " dollars will be " << output << " Euros" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getDollarsToEuros(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " dollars will be " << output << " Euros" << endl;
                    }
                }
                /*
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getDollarsToEuros(exchangeAmount);
                cout << exchangeAmount << " dollars will be " << output << " Euros" << endl;
                 */
            }
            if (trueChoiceOne == 1 && trueSecondChoice == 4) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getDollarsToYen(exchangeAmount);
                    cout << exchangeAmount << " dollars will be " << output << " Japanese Yen" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getDollarsToYen(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " dollars will be " << output << " Japanese Yen" << endl;
                    }
                }
                /*
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getDollarsToYen(exchangeAmount);
                cout << exchangeAmount << " dollars will be " << output << " Japanese Yen" << endl;
                 */
            }
            if (trueChoiceOne == 1 && trueSecondChoice == 5) {
                    if (fileDecision == "single" || fileDecision == "Single") {
                        theConversion.setExchangeAmount(exchangeAmount);
                        double output = theConversion.getDollarsToYuan(exchangeAmount);
                        cout << exchangeAmount << " dollars will be " << output << " Chinese Yuan" << endl;
                    }else {
                        for (int i = 0; i < exchangeAmounts.size(); i++) {
                            theConversion.setExchangeAmount(exchangeAmounts[i]);
                            double output = theConversion.getDollarsToYuan(exchangeAmounts[i]);
                            cout << exchangeAmounts[i] << " dollars will be " << output << " Chinese Yuan" << endl;
                        }
                    }

                /*
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getDollarsToYuan(exchangeAmount);
                cout << exchangeAmount << " dollars will be " << output << " Chinese Yuan" << endl;
            */
            }
            if (trueChoiceOne == 1 && trueSecondChoice == 6) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getDollarsToRubles(exchangeAmount);
                    cout << exchangeAmount << " dollars will be " << output << " Russian Rubles" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getDollarsToRubles(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " dollars will be " << output << " Russian Rubles" << endl;
                    }
                }

                /*
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getDollarsToRubles(exchangeAmount);
                cout << exchangeAmount << " dollars will be " << output << " Russian Rubles" << endl;
                */
            }
            if (trueChoiceOne == 1 && trueSecondChoice == 7) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getDollarsToWon(exchangeAmount);
                    cout << exchangeAmount << " dollars will be " << output << " Korean Won" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getDollarsToWon(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " dollars will be " << output << " Korean Won" << endl;
                    }
                }

                /*
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getDollarsToWon(exchangeAmount);
                cout << exchangeAmount << " dollars will be " << output << " Korean Won" << endl;
            */
            }
            if (trueChoiceOne == 1 && trueSecondChoice == 8) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getDollarsToRupees(exchangeAmount);
                    cout << exchangeAmount << " dollars will be " << output << " Indian Rupees" << endl;
                }else {
                    for (int i = 0; i <= exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getDollarsToRupees(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " dollars will be " << output << " Indian Rupees" << endl;
                    }
                }
            }


            if (trueChoiceOne == 2 && trueSecondChoice == 1) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getPoundsToDollars(exchangeAmount);
                    cout << exchangeAmount << " British pounds will be " << output << " US dollars" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getPoundsToDollars(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " British Pounds will be " << output << " US dollars" << endl;
                    }
                }

                /*
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getPoundsToDollars(exchangeAmount);
                cout << exchangeAmount << " Pounds will be " << output << " US dollars" << endl;
                */
            }
            if (trueChoiceOne == 2 && trueSecondChoice == 3) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getPoundsToEuros(exchangeAmount);
                    cout << exchangeAmount << " British pounds will be " << output << " Euros" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getPoundsToEuros(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " British Pounds will be " << output << " Euros" << endl;
                    }
                }
            }
            if (trueChoiceOne == 2 && trueSecondChoice == 4) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getPoundsToYen(exchangeAmount);
                    cout << exchangeAmount << " British pounds will be " << output << " Japanese Yen" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getPoundsToYen(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " British Pounds will be " << output << " Japanese Yen" << endl;
                    }
                }
            }
            if (trueChoiceOne == 2 && trueSecondChoice == 5) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getPoundsToYuan(exchangeAmount);
                    cout << exchangeAmount << " British pounds will be " << output << " Japanese Yuan" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getPoundsToYuan(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " British Pounds will be " << output << " Japanese Yuan" << endl;
                    }
                }
            }
            if (trueChoiceOne == 2 && trueSecondChoice == 6) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getPoundsToRubles(exchangeAmount);
                    cout << exchangeAmount << " British pounds will be " << output << " Russian Rubles" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getPoundsToRubles(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " British Pounds will be " << output << " Russian Rubles" << endl;
                    }
                }
            }
            if (trueChoiceOne == 2 && trueSecondChoice == 7) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getPoundsToWon(exchangeAmount);
                    cout << exchangeAmount << " British pounds will be " << output << " Korean Won" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getPoundsToWon(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " British Pounds will be " << output << " Korean Won" << endl;
                    }
                }
            }
            if (trueChoiceOne == 2 && trueSecondChoice == 8) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getPoundsToRupees(exchangeAmount);
                    cout << exchangeAmount << " British pounds will be " << output << " Indian Rupees" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getPoundsToRupees(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " British Pounds will be " << output << " Indian Rupees" << endl;
                    }
                }
            }


            if (trueChoiceOne == 3 && trueSecondChoice == 1) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getEurosToDollars(exchangeAmount);
                    cout << exchangeAmount << " Euros will be " << output << " US dollars" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getEurosToDollars(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Euros will be " << output << " US dollars" << endl;
                    }
                }

                /*
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getEurosToDollars(exchangeAmount);
                cout << exchangeAmount << " Euros will be " << output << " US dollars" << endl;
                */
            }
            if (trueChoiceOne == 3 && trueSecondChoice == 2) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getEurosToPounds(exchangeAmount);
                    cout << exchangeAmount << " Euros will be " << output << " British Pounds" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getEurosToPounds(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Euros will be " << output << " British Pounds" << endl;
                    }
                }
            }
            if (trueChoiceOne == 3 && trueSecondChoice == 4) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getEurosToYen(exchangeAmount);
                    cout << exchangeAmount << " Euros will be " << output << " Japanese Yen" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getEurosToYen(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Euros will be " << output << " Japanese Yen" << endl;
                    }
                }
            }
            if (trueChoiceOne == 3 && trueSecondChoice == 5) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getEurosToYuan(exchangeAmount);
                    cout << exchangeAmount << " Euros will be " << output << " Chinese Yuan" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getEurosToYuan(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Euros will be " << output << " Chinese Yuan" << endl;
                    }
                }
            }
            if (trueChoiceOne == 3 && trueSecondChoice == 6) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getEurosToRubles(exchangeAmount);
                    cout << exchangeAmount << " Euros will be " << output << " Russian Rubles" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getEurosToRubles(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Euros will be " << output << " Russian Rubles" << endl;
                    }
                }
            }
            if (trueChoiceOne == 3 && trueSecondChoice == 7) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getEurosToWon(exchangeAmount);
                    cout << exchangeAmount << " Euros will be " << output << " Korean Won" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getEurosToWon(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Euros will be " << output << " Korean Won" << endl;
                    }
                }
            }
            if (trueChoiceOne == 3 && trueSecondChoice == 8) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getEurosToRupees(exchangeAmount);
                    cout << exchangeAmount << " Euros will be " << output << " Indian Rupees" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getEurosToRupees(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Euros will be " << output << " Indian Rupees" << endl;
                    }
                }
            }

            if (trueChoiceOne == 4 && trueSecondChoice == 1) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYenToDollars(exchangeAmount);
                    cout << exchangeAmount << " Chinese Yen will be " << output << " US dollars" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYenToDollars(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Chinese Yen will be " << output << " US dollars" << endl;
                    }
                }
                /*
                theConversion.setExchangeAmount(exchangeAmount);
                double output = theConversion.getYenToDollars(exchangeAmount);
                cout << exchangeAmount << " Yen will be " << output << " US Dollars" << endl;
                 */
            }
            if (trueChoiceOne == 4 && trueSecondChoice == 2) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYenToPounds(exchangeAmount);
                    cout << exchangeAmount << " Japanese Yen will be " << output << " British Pounds" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYenToPounds(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Japanese Yen will be " << output << " British Pounds" << endl;
                    }
                }
            }
            if (trueChoiceOne == 4 && trueSecondChoice == 3) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYenToEuros(exchangeAmount);
                    cout << exchangeAmount << " Japanese Yen will be " << output << " Euros" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYenToEuros(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Japanese Yen will be " << output << " Euros" << endl;
                    }
                }
            }
            if (trueChoiceOne == 4 && trueSecondChoice == 5) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYenToYuan(exchangeAmount);
                    cout << exchangeAmount << " Japanese Yen will be " << output << " Chinese Yuan" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYenToYuan(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Japanese Yen will be " << output << " Chinese Yuan" << endl;
                    }
                }
            }
            if (trueChoiceOne == 4 && trueSecondChoice == 6) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYenToRubles(exchangeAmount);
                    cout << exchangeAmount << " Japanese Yen will be " << output << " Russian Rubles" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYenToRubles(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Japanese Yen will be " << output << " Russian Rubles" << endl;
                    }
                }
            }
            if (trueChoiceOne == 4 && trueSecondChoice == 7) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYenToWon(exchangeAmount);
                    cout << exchangeAmount << " Japanese Yen will be " << output << " Korean Won" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYenToWon(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Japanese Yen will be " << output << " Korean Won" << endl;
                    }
                }
            }
            if (trueChoiceOne == 4 && trueSecondChoice == 8) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYenToRupees(exchangeAmount);
                    cout << exchangeAmount << " Japanese Yen will be " << output << " Indian Rupees" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYenToRupees(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Japanese Yen will be " << output << " Indian Rupees" << endl;
                    }
                }
            }


            if (trueChoiceOne == 5 && trueSecondChoice == 1) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYuanToDollars(exchangeAmount);
                    cout << exchangeAmount << " Chinese Yuan will be " << output << " US dollars" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYuanToDollars(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Chinese Yuan will be " << output << " US dollars" << endl;
                    }
                }
            }
            if (trueChoiceOne == 5 && trueSecondChoice == 2) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYuanToPounds(exchangeAmount);
                    cout << exchangeAmount << " Chinese Yuan will be " << output << " British Pounds" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYuanToPounds(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Chinese Yuan will be " << output << " British Pounds" << endl;
                    }
                }
            }
            if (trueChoiceOne == 5 && trueSecondChoice == 3) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYuanToEuros(exchangeAmount);
                    cout << exchangeAmount << " Chinese Yuan will be " << output << " Euros" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYuanToEuros(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Chinese Yuan will be " << output << " Euros" << endl;
                    }
                }
            }
            if (trueChoiceOne == 5 && trueSecondChoice == 4) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYuanToYen(exchangeAmount);
                    cout << exchangeAmount << " Chinese Yuan will be " << output << " Japanese Yen" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYuanToYen(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Chinese Yuan will be " << output << " Japanese Yen" << endl;
                    }
                }
            }
            if (trueChoiceOne == 5 && trueSecondChoice == 6) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYuanToRubles(exchangeAmount);
                    cout << exchangeAmount << " Chinese Yuan will be " << output << " Russian Rubles" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYuanToRubles(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Chinese Yuan will be " << output << " Russian Rubles" << endl;
                    }
                }
            }
            if (trueChoiceOne == 5 && trueSecondChoice == 7) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYuanToWon(exchangeAmount);
                    cout << exchangeAmount << " Chinese Yuan will be " << output << " Korean Won" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYuanToWon(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Chinese Yuan will be " << output << " Korean Won" << endl;
                    }
                }
            }
            if (trueChoiceOne == 5 && trueSecondChoice == 8) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getYuanToRupees(exchangeAmount);
                    cout << exchangeAmount << " Chinese Yuan will be " << output << " Indian Rupees" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getYuanToRupees(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Chinese Yuan will be " << output << " Indian Rupees" << endl;
                    }
                }
            }


            if (trueChoiceOne == 6 && trueSecondChoice == 1) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRublesToDollars(exchangeAmount);
                    cout << exchangeAmount << " Russian Rubles will be " << output << " US dollars" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRublesToDollars(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Russian Rubles will be " << output << " US dollars" << endl;
                    }
                }
            }
            if (trueChoiceOne == 6 && trueSecondChoice == 2) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRublesToPounds(exchangeAmount);
                    cout << exchangeAmount << " Russian Rubles will be " << output << " British Pounds" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRublesToPounds(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Russian Rubles will be " << output << " British Pounds" << endl;
                    }
                }
            }
            if (trueChoiceOne == 6 && trueSecondChoice == 3) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRublesToEuros(exchangeAmount);
                    cout << exchangeAmount << " Russian Rubles will be " << output << " Euros" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRublesToEuros(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Russian Rubles will be " << output << " Euros" << endl;
                    }
                }
            }
            if (trueChoiceOne == 6 && trueSecondChoice == 4) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRublesToYen(exchangeAmount);
                    cout << exchangeAmount << " Russian Rubles will be " << output << " Japanese Yen" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRublesToYen(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Russian Rubles will be " << output << " Japanese Yen" << endl;
                    }
                }
            }
            if (trueChoiceOne == 6 && trueSecondChoice == 5) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRublesToYuan(exchangeAmount);
                    cout << exchangeAmount << " Russian Rubles will be " << output << " Chinese Yuan" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRublesToYuan(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Russian Rubles will be " << output << " Chinese Yuan" << endl;
                    }
                }
            }
            if (trueChoiceOne == 6 && trueSecondChoice == 7) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRublesToWon(exchangeAmount);
                    cout << exchangeAmount << " Russian Rubles will be " << output << " Korean Won" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRublesToWon(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Russian Rubles will be " << output << " Korean Won" << endl;
                    }
                }
            }
            if (trueChoiceOne == 6 && trueSecondChoice == 8) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRublesToRupees(exchangeAmount);
                    cout << exchangeAmount << " Russian Rubles will be " << output << " Indian Rupees" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRublesToRupees(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Russian Rubles will be " << output << " Indian Rupees" << endl;
                    }
                }
            }


            if (trueChoiceOne == 7 && trueSecondChoice == 1) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getWonToDollars(exchangeAmount);
                    cout << exchangeAmount << " Korean Won will be " << output << " US dollars" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getWonToDollars(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Korean Won will be " << output << " US dollars" << endl;
                    }
                }
            }
            if (trueChoiceOne == 7 && trueSecondChoice == 2) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getWonToPounds(exchangeAmount);
                    cout << exchangeAmount << " Korean Won will be " << output << " British Pounds" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getWonToPounds(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Korean Won will be " << output << " British Pounds" << endl;
                    }
                }
            }
            if (trueChoiceOne == 7 && trueSecondChoice == 3) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getWonToEuros(exchangeAmount);
                    cout << exchangeAmount << " Korean Won will be " << output << " Euros" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getWonToEuros(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Korean Won will be " << output << " Euros" << endl;
                    }
                }
            }
            if (trueChoiceOne == 7 && trueSecondChoice == 4) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getWonToYen(exchangeAmount);
                    cout << exchangeAmount << " Korean Won will be " << output << " Japanese Yen" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getWonToYen(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Korean Won will be " << output << " Japanese Yen" << endl;
                    }
                }
            }
            if (trueChoiceOne == 7 && trueSecondChoice == 5) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getWonToYuan(exchangeAmount);
                    cout << exchangeAmount << " Korean Won will be " << output << " Chinese Yuan" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getWonToYuan(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Korean Won will be " << output << " Chinese Yuan" << endl;
                    }
                }
            }
            if (trueChoiceOne == 7 && trueSecondChoice == 6) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getWonToRubles(exchangeAmount);
                    cout << exchangeAmount << " Korean Won will be " << output << " Russian Rubles" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getWonToRubles(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Korean Won will be " << output << " Russian Rubles" << endl;
                    }
                }
            }
            if (trueChoiceOne == 7 && trueSecondChoice == 8) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getWonToRupees(exchangeAmount);
                    cout << exchangeAmount << " Korean Won will be " << output << " Indian Rupees" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getWonToRupees(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Korean Won will be " << output << " Indian Rupees" << endl;
                    }
                }
            }


            if (trueChoiceOne == 8 && trueSecondChoice == 1) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRupeesToDollars(exchangeAmount);
                    cout << exchangeAmount << " Indian Rupees will be " << output << " US dollars" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRupeesToDollars(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Indian Rupees will be " << output << " US dollars" << endl;
                    }
                }
            }
            if (trueChoiceOne == 8 && trueSecondChoice == 2) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRupeesToPounds(exchangeAmount);
                    cout << exchangeAmount << " Indian Rupees will be " << output << " British Pounds" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRupeesToPounds(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Indian Rupees will be " << output << " British Pounds" << endl;
                    }
                }
            }
            if (trueChoiceOne == 8 && trueSecondChoice == 3) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRupeesToEuros(exchangeAmount);
                    cout << exchangeAmount << " Indian Rupees will be " << output << " Euros" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRupeesToEuros(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Indian Rupees will be " << output << " Euros" << endl;
                    }
                }
            }
            if (trueChoiceOne == 8 && trueSecondChoice == 4) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRupeesToYen(exchangeAmount);
                    cout << exchangeAmount << " Indian Rupees will be " << output << " Japanese Yen" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRupeesToYen(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Indian Rupees will be " << output << " Japanese Yen" << endl;
                    }
                }
            }
            if (trueChoiceOne == 8 && trueSecondChoice == 5) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRupeesToYuan(exchangeAmount);
                    cout << exchangeAmount << " Indian Rupees will be " << output << " Chinese Yuan" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRupeesToYuan(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Indian Rupees will be " << output << " Chinese Yuan" << endl;
                    }
                }
            }
            if (trueChoiceOne == 8 && trueSecondChoice == 6) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRupeesToRubles(exchangeAmount);
                    cout << exchangeAmount << " Indian Rupees will be " << output << " Russian Rubles" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRupeesToRubles(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Indian Rupees will be " << output << " Russian Rubles" << endl;
                    }
                }
            }
            if (trueChoiceOne == 8 && trueSecondChoice == 7) {
                if (fileDecision == "single" || fileDecision == "Single") {
                    theConversion.setExchangeAmount(exchangeAmount);
                    double output = theConversion.getRupeesToWon(exchangeAmount);
                    cout << exchangeAmount << " Indian Rupees will be " << output << " Korean Won" << endl;
                }else {
                    for (int i = 0; i < exchangeAmounts.size(); i++) {
                        theConversion.setExchangeAmount(exchangeAmounts[i]);
                        double output = theConversion.getRupeesToWon(exchangeAmounts[i]);
                        cout << exchangeAmounts[i] << " Indian Rupees will be " << output << " Korean Won" << endl;
                    }
                }
            }


            string choiceThree;
            cout << "Would you like to insert another value?(Yes/No)" << endl;
            while (!(cin >> choiceThree) ||
                   (choiceThree != "Yes" && choiceThree != "yes" && choiceThree != "No" && choiceThree != "no")) {
                cin.clear();
                //string junk;
                cout << "Please enter a valid option: ";

            }

            string junk;
            getline(cin, junk);
            if (choiceThree == "No" || choiceThree == "no") {
                keepGoing = false;
            }


    }
}