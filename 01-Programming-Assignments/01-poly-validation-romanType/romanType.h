//
// Created by alm20 on 3/22/2025.
//

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>


class romanType {

public:

	enum RomanNumerals {
		M = 1000,
		D = 500,
		C = 100,
		L = 50,
		X = 10,
		V = 5,
		I = 1,
		IV = 4,
		IX = 9,
		XL = 40,
		XC = 90,
		CD = 400,
		CM = 900
	};

	static void printEnumKeys(RomanNumerals r) {
		switch (r) {
			case M:
				std::cout << "M"; break;
			case D:
				std::cout << "D"; break;
			case C:
				std::cout << "C"; break;
			case L:
				std::cout << "L"; break;
			case X:
				std::cout << "X"; break;
			case V:
				std::cout << "V"; break;
			case I:
				std::cout << "I"; break;
			case IV:
				std::cout << "IV"; break;
			case IX:
				std::cout << "IX"; break;
			case XL:
				std::cout << "XL"; break;
			case XC:
				std::cout << "XC"; break;
			case CD:
				std::cout << "CD"; break;
			case CM:
				std::cout << "CM"; break;
		}
	}

	double conversionToNumericalValue(const std::string &numerals) {

		std::vector<RomanNumerals> romans = tokenize(numerals);
		for (auto& c : romans) {
			total += c;
		}
		std::cout << std::fixed << std::setprecision(2) <<  total;
		return total;
	}

	int conversionFromRomanToNumericalValue(int numbers) {
		tokenize(numbers);
		return 1;
	}



private:

	std::string roman_numerals;
	int number = 0;
	double total = 0;

	static RomanNumerals charToEnum(const std::string &numerals) {

		const char first_numeral = numerals[0];
		const char second_numeral = numerals[1];

		if (first_numeral == 'I' && second_numeral == 'V') {
			return IV;
		}
		if (first_numeral == 'I' && second_numeral == 'X') {
			return IX;
		}
		if (first_numeral == 'X' && second_numeral == 'L') {
			return XL;
		}
		if (first_numeral == 'X' && second_numeral == 'C') {
			return XC;
		}
		if (first_numeral == 'C' && second_numeral == 'D') {
			return CD;
		}
		if (first_numeral == 'C' && second_numeral == 'M') {
			return CM;
		}
		return I;
	}

	static RomanNumerals charToEnum(char c) {

		switch (c) {
		case 'M': return M;
		case 'D': return D;
		case 'C': return C;
		case 'L': return L;
		case 'X': return X;
		case 'V': return V;
		case 'I': return I;
		default: return M;

		}
	}

	static std::vector<RomanNumerals> tokenize(const std::string &numerals) {

		int k = 0;
		std::vector<RomanNumerals> romans;

		for (int i = 0; k < numerals.size(); i++) {

			/* converts char type to enum type to get explicit enum value */

			const int first = charToEnum(numerals[k]);
			const int second = charToEnum(numerals[k + 1]);

			if (first < second) {
				std::string two_letters = std::string(1, numerals[k]) + numerals[k + 1]; // string(1, numerals[i]) ex: 'I' and 'V' becomes 'IV'
				/*std::cout << numerals[k] << numerals[k + 1] << " ";*/
				romans.push_back(charToEnum(two_letters));
				k += 2;
			}
			else {
				romans.push_back(charToEnum(numerals[k]));
				/*std::cout << numerals[k] << std::endl;*/
				k++;
			}
		}
		/*for (auto& c : romans) {
			std::cout << c << std::endl;
		}*/

		return romans;
	}

	static std::vector<RomanNumerals> tokenize(int number) {
		std::vector<RomanNumerals> tokens;
		bool flag = true;
		while (flag) {
			if (number >= 1000) {
				number -= 1000;
				tokens.push_back(M);
			} else if (number < 1000 && number >= 900) {
				number -= 900;
				tokens.push_back(CM);
			}
			else if (number >= 500 && number < 1000) {
				number -= 500;
				tokens.push_back(D);
			}
			else if (number < 500 && number >= 400) {
				number -= 400;
				tokens.push_back(CD);
			}
			else if (number >= 100 && number < 500) {
				number -= 100;
				tokens.push_back(C);
			}
			else if (number < 100 && number >=90) {
				number -= 90;
				tokens.push_back(XC);
			}
			else if (number >= 50 && number < 100) {
				number -= 50;
				tokens.push_back(L);
			}
			else if (number < 50 && number >=40) {
				number -= 40;
				tokens.push_back(XL);
			}
			else if (number >= 10 && number < 50) {
				number -= 10;
				tokens.push_back(X);
			}
			else if (number == 9) {
				number -= 9;
				tokens.push_back(IX);
			}
			else if (number >= 5 && number < 10) {
				number -= 5;
				tokens.push_back(V);
			}
			else if (number == 4) {
				number -= 4;
				tokens.push_back(IV);
			}
			else if (number >= 1 && number < 5) {
				number -= 1;
				tokens.push_back(I);
			}
			else {
				flag = false;
			}
		}
		for (auto t : tokens) {
			printEnumKeys(t);
		}
		return tokens;
	}
};

