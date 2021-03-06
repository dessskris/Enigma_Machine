/*--------------------------------------------------------------------------+
|  File Name:    main.cpp                                                   |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 2              |
|  Description:  Enigma machine to encrypt and decrypt messages             |
|  Date:         23 November 2015                                           |
+--------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "enigma.h"
#include "helper.h"
#include "errors.h"

using namespace std;

int main(int argc, char **argv) {
  Enigma enigma(argc, argv);

  switch(enigma.good) {
  case 1:
    cerr << "Insufficient number of parameters!" << endl;
    cerr << "In order to set up the Enigma machine, a configuration file each "
	 << "for the wiring map of the plugboard and of the reflector is "
	 << "needed at the minimum." << endl;
    cerr << "If you wish to configure at least one rotor, please include "
	 << "a configuration file for the wiring map of each rotor and "
	 << "a configuration file for their initial starting positions." << endl;
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  case 3:
    cout << "Failed!" << endl;
    cerr << "Configuration file contains a number not between 0 and 25!" << endl;
    return INVALID_INDEX;
  case 4:
    cout << "Failed!" << endl;
    cerr << "Configuration file contains a non-numeric character!" << endl;
    return NON_NUMERIC_CHARACTER;
  case 5:
    cout << "Failed!" << endl;
    cerr << "Impossible plugboard configuration!" << endl;
    cerr << "A contact may not be connected to itself, "
	 << "or to more than one other contacts!" << endl;
    return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
  case 6:
    cout << "Failed!" << endl;
    cerr << "Incorrect number of plugboard parameters!" << endl;
    cerr << "The configuration file must contain "
	 << "an even number of numbers!" << endl;
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  case 7:
    cout << "Failed!" << endl;
    cerr << "Invalid rotor mapping!" << endl;
    cerr << "No two inputs may be mapped to the same output! "
	 << "For all inputs, each input must be mapped to some output! "
	 << "When listing the turnover notches positions, "
	 << "please list each position only once!" << endl;
    return INVALID_ROTOR_MAPPING;
  case 8:
    cout << "Failed!" << endl;
    cerr << "No rotor starting position!" << endl;
    cerr << "Please specify the starting position for each rotor used!" << endl;
    return NO_ROTOR_STARTING_POSITION;
  case 9:
    cout << "Failed!" << endl;
    cerr << "Impossible reflector configuration!" << endl;
    cerr << "A contact may not be connected to itself, "
	 << "or to more than one other contacts!" << endl;
    return INVALID_REFLECTOR_MAPPING;
  case 10:
    cout << "Failed!" << endl;
    cerr << "Incorrect number of reflector parameters!" << endl;
    cerr << "The configuration file must contain exactly 13 pairs of numbers!" << endl;
    return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
  case 11:
    cout << "Failed!" << endl;
    cerr << "Error opening configuration file!" << endl;
    return ERROR_OPENING_CONFIGURATION_FILE;
  default:
    break;
  }

  cout << "Welcome to the Enigma machine!" << endl
       << "This machine will encrypt your message." << endl << endl;

  char letter;
  int letter_index;

  cout << "Please input the plaintext in uppercase to encrypt : ";

  cin >> ws;

  cout << endl << "The ciphertext is ";

  while (cin >> ws >> letter) {
    if (letter < 65 || letter > 90) {
      cerr << endl << "Invalid input character!" << endl;
      cerr << "The Enigma machine may only encrypt uppercase letters." << endl;
      return INVALID_INPUT_CHARACTER;
    }
    letter_index = letter - 65;
    letter_index = enigma.encrypt(letter_index);
    letter = char(letter_index) + 65;
    cout << letter;
  }
  cout << endl;

  return NO_ERROR;
}
