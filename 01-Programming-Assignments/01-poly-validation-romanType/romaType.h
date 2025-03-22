//
// Created by alm20 on 3/22/2025.
//

#pragma once

#include <string>
#include <iomanip>
#include <vector>


class romaType {

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

	double conversionToNumericalValue(const std::string &numerals) {

		std::vector<RomanNumerals> romans = tokenize(numerals);
		for (auto& c : romans) {
			total += c;
		}
		/*std::cout << std::fixed << std::setprecision(2) << total << std::endl;*/
		return total;
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

			const int first = charToEnum(numerals[i]);
			const int second = charToEnum(numerals[k + 1]);

			if (first < second) {
				std::string two_letters = std::string(1, numerals[k]) + numerals[k + 1]; // string(1, numerals[i]) ex: 'I' and 'V' becomes 'IV'
				/*std::cout << numerals[k] << numerals[k + 1] << std::endl;*/
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

};

