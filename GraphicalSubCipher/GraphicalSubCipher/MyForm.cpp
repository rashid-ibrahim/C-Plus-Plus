#include "MyForm.h"
#include "Resources.h"


//Global Variables.
std::string type;
std::string userInput;
std::vector<std::string> keyVect;
std::string runAgain;
int globalCount = 0;
int max_count;
int keyShift = 0;

//Generates the key to be used for both decryption and encryption.
void keyGen(int key_space)
{
	//Based on the user input for the desired keyspace, the key is generated.
	if (key_space == 1)
	{
		keyVect.resize(26);
		keyVect[0] = "abcdefghijklmnopqrstuvwxyz";
	}
	else if (key_space == 2)
	{
		keyVect.resize(52);
		keyVect[0] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	}
	else if (key_space == 3)
	{
		keyVect.resize(62);
		keyVect[0] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	}
	else if (key_space == 4)
	{
		keyVect.resize(93);
		keyVect[0] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*(){}[]\\|-_=+:;<>,.?`~/";
	}
	//This section of the statement is for creating a user defined key.
	else if (key_space == 5)
	{
		//Prompts user for input.
		std::cout << "Input the characters to be used in the key space in one line and then press enter";
		std::cout << " done." << std::endl;
		std::cin >> userInput;
		//Resizes vector for current user key input.
		keyVect.resize(userInput.length());
		//Sets starting key to userInput.
		keyVect[0] = userInput;
		//Clears userInput.
		userInput = "";
	}

	//Variables used to generate all combinations or the key.
	std::string currKey = "", newKey = "";
	max_count = keyVect[0].length() - 1;

	//Loop to generates the combinations of the key.
	for (int i = 0; i < max_count; i++)
	{
		//variables for currentkey and newkey.
		currKey = keyVect[i];
		newKey = "";
		//Loops through each character in the current key string, moves it by one, and then adds it to the new key.
		for (size_t j = 0; j < currKey.length(); j++)
		{
			//If statement that adds the next key item to the new key each loop until the last item it reached.
			//It then adds the first item to the end.
			if (j < currKey.length() - 1)
			{
				newKey = newKey + currKey[j + 1];
			}
			else
			{
				newKey = newKey + currKey[0];
			}
		}
		//Adds the new key to the next vector index to be used in the next iteration.
		keyVect[i + 1] = newKey;
	}
	return;
}

//Function to get user input for various parts of the program. The type string is used to determine what
//type of input to get.
static void UserIn(std::string type)
{
	//Used for key generation.
	if (type == "key")
	{
		//Prompt to ask user what keyspace they would like to use.
		int keySpace = 0;
		std::cout << "Please select a key to use. 1 = abcdefghijklmnopqrstuvwxyz " << std::endl;
		std::cout << "2 = abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ " << std::endl;
		std::cout << "3 = abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 " << std::endl;
		std::cout << "4 = abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
		std::cout << "{}[]\\|-_=+:;<>,.?`~/" << std::endl;
		std::cout << "5 = Define your own keyspace." << std::endl;
		std::getline(std::cin, userInput);
		//Checks user input.
		try
		{
			keySpace = atoi(userInput.c_str());
			keyGen(keySpace);
		}
		catch (...)
		{
			std::cout << "The only acceptable inputs at this time are 1, 2, 3, 4 or 5." << std::endl;
			std::cout << std::endl;
			userInput = "";
			UserIn("key");
		}
		return;
	}
	//Prompt for decryption input.
	else if (type == "decrypt")
	{
		std::getline(std::cin, userInput);
		//Checks that user has actually entered text.
		if (userInput.length() > 0)
		{
			return;
		}
		else
		{
			//Prompts user when no text has been entered.
			std::cout << "The text to be input must contain at least one letter. " << std::endl;
			std::cout << std::endl;
			userInput = "";
			//Calls the input function again.
			UserIn("decrypt");
		}
	}
	//Checks user input for when the user is asked if they would like to run the program again.
	else if (type == "again")
	{
		std::getline(std::cin, userInput);

		//Returns if the user has input some text.
		if (userInput.length() > 0)
		{
			return;
		}
		else
		{
			//Prints to screen if the user inputs no text.
			std::cout << "You must enter a valid choice of 'yes' or 'no' here." << std::endl;
			//Calls the reRun() function again when no input was recieved.
			reRun();
			return;
		}
	}
	//Checks user input for shift space during encryption.
	else if (type == "shift")
	{
		//Prompts user for how much they would like to shift the phrase by.
		std::cout << std::endl;
		std::cout << "How much would you like to shift the text by?";
		std::cout << "(Hint: minimum shift is by 1 and maximum is by " << keyVect[0].size() << " or enter 'other' for skipping letters.)" << std::endl;
		//Gets user input.
		std::cin >> userInput;

		//Statement to check that user has input an integer.
		try
		{
			keyShift = stoi(userInput);
		}
		catch (...)
		{
			//Variable to pull first letter of user respone.
			std::string shiftFirst;
			//If statment to pull first letter only from user respone to clean up checking result.
			if (userInput.length() > 1)
			{
				int firstLetterInt = userInput.length() - 1;
				userInput = userInput[userInput.length() - firstLetterInt];
			}
			else if (userInput.length() == 1)
			{
				shiftFirst = userInput;
			}
			else if (userInput.length() <= 0)
			{
				//Prompts user for when a non integer input has been entered.
				std::cout << "You must enter a numeric value between 1 and " << keyVect[0].length() << " or type 'other'." << std::endl;
				//Recursively calls function to get user input again.
				UserIn("shift");
			}

			//Checks user respone for a valid input.
			if (shiftFirst == "o" || shiftFirst == "O")
			{
				std::cout << "Please enter a number for the positions in the key you would like to skip for each encryption step." << std::endl;
				std::cin >> userInput;
				try
				{
					keyShift = stoi(userInput);
				}
				catch (...)
				{
					//Prompts user for when a non integer input has been entered.
					std::cout << "You must enter a numeric value between 1 and " << keyVect[0].length() << " or type 'other'." << std::endl;
					//Recursively calls function to get user input again.
					UserIn("shift");
				}
			}
			else
			{
				//Prompts user for when a non integer input has been entered.
				std::cout << "You must enter a numeric value between 1 and " << keyVect[0].length() << " or type 'other'." << std::endl;
				//Recursively calls function to get user input again.
				UserIn("shift");
			}
		}

		//Checks that user input is greater than 0 and less or equal to the maximum keyspace.
		if (keyShift > 0 && keyShift <= keyVect[0].length())
		{
			return;
		}
		else
		{
			//Reprompts the user if the iteger is out of bounds of the keyspace.
			std::cout << "You must enter a numeric value between 1 and " << keyVect[0].length() << std::endl;
			//Recursively calls the function to get user input again for shift when invalid input has been entered.
			UserIn("shift");
		}
	}
	//Statement for encryption input checking.
	else if (type == "encryption")
	{
		//Variable for raw user input.
		std::string rawInput = "";
		std::cin >> rawInput;
		//Variable for current item in the loops to follow.
		std::string current = "";
		//Vector to hold boolean values. Used when checking if the user input is within the keyspace.
		std::vector<bool> RightChars;
		//Clears global user input.
		userInput = "";
		//Clears any spaces from the user input.
		for (size_t i = 0; i < rawInput.length(); i++)
		{
			if (isspace(rawInput[i]))
			{
				//Intentionally left blank to remove spaces.
			}
			else
			{
				//Adds current string item to cleaned text if there are no spaces.
				userInput += rawInput[i];
			}
		}

		//Sets the vector size to the current input length.
		RightChars.resize(userInput.length());

		//Loop to initialize each item in vector to false for the loop following.
		for (size_t i = 0; i < RightChars.size(); i++)
		{
			RightChars[i] = false;
		}

		//Loop to check that only characters in the keyspace are in the user input.
		for (size_t i = 0; i < userInput.length(); i++)
		{
			//Current string item being checked.
			current = userInput[i];
			//Loop to compare each item in the keyspace to the current item.
			for (size_t j = 0; j < keyVect[0].length(); j++)
			{
				//Statement that runs if a match has been found.
				if (current == keyVect[j])
				{
					RightChars[i] = true;
				}
			}
		}

		//Variable used when checking if all characters are contained in the key space.
		bool allTrue = true;

		//Loops through each item in the RightChars vector to check if every item is true.
		for (size_t i = 0; i < RightChars.size(); i++)
		{
			//Statement runs when a false if found in the RightChars vector.
			if (RightChars[i] == false)
			{
				allTrue = false;
			}
		}

		//Statement runs if any non-matching characters are found.
		if (allTrue = false)
		{
			//Prompts user to only user characters from the keyspace.
			std::cout << "The phrase entered contains characters outside of the keyspace.";
			std::cout << "Please only include characters from the keyspace: " << keyVect[0] << std::endl;
			//Restarts input for encryption.
			UserIn("decryption");
		}
		else
		{
			return;
		}

	}
}

//Function to ask the user if they would like to run the program again.
static void reRun()
{
	//Prompts user for input.
	std::cout << std::endl;
	std::cout << "Would you like to run another encryption/decryption?" << std::endl;
	//Grabs user input
	UserIn("again");
	//Variable to pull first letter of user respone.
	std::string runFirst;
	//If statment to pull first letter only from user respone to clean up checking result.
	if (userInput.length() > 1)
	{
		int firstLetterInt = userInput.length() - 1;
		userInput = userInput[userInput.length() - firstLetterInt];
	}
	else if (userInput.length() == 1)
	{
		runFirst = userInput;
	}
	else if (userInput.length() < 1)
	{
		reRun();
	}
	//Checks user respone for a valid input.
	if (runFirst == "y" || runFirst == "Y")
	{
		ClearVars();
		main();
	}
	else if (runFirst == "n" || runFirst == "Y")
	{
		return;
	}
	else
	{
		//Recalls this function if the user input an invalid response.
		std::cout << std::endl;
		std::cout << "Please enter a valid choice of either Yes(y) or No(n)." << std::endl;
		system("pause");
		reRun();
	}
}

//Function to clear global variables, so as to not use old values for succesive runs of the program.
static void ClearVars()
{
	type = "";
	userInput = "";
	runAgain = "";
	globalCount = 0;
	max_count = 0;

	//Loops through array to clear each value.
	for (size_t i = 0; i < keyVect.size(); i++)
	{
		keyVect[i] = "";
	}
	return;
}

//Function used for encryption.
static void encrypt()
{
	//Prompts user to choose keyspace. Will allow for custom key spaces in the future.
	std::cout << std::endl;
	std::cout << "What keyspace would you like to use for the encryption?" << std::endl;
	std::cout << "Enter a number between 1 and 4: " << std::endl;
	//Calls user input function to calculate keyspace.
	UserIn("key");

	//Calls user input to calculate shift space.
	UserIn("shift");

	//Prompts user for encryption phase.
	std::cout << std::endl;
	std::cout << "Please enter a phrase to encrypt using characters from this list only: " << keyVect[0] << std::endl;
	//Calls user input for encryption.
	UserIn("encryption");

	//Variable for output.
	std::string outPut = "";
	//Variable to hold the current key.
	std::string key = keyVect[keyShift];
	//Loop to actually transform the input plain text to the encrypted text based on the key.
	for (size_t i = 0; i < userInput.length(); i++)
	{
		//Adds the output of encrypted text during each iteration of the loop.
		outPut += key[i];
	}
	//Displays the encrypted phrase to the user.
	std::cout << "Encrypted your phrase is: " << outPut << std::endl;
	//Pauses the program to allow the user time to read.
	system("pause");
	return;
}

//Function used for decryption.
static void decrypt()
{
	if (userInput != "")
	{
		std::cout << std::endl;
		//Variable used to hold initial input before sanitation of spaces.
		std::string rawText = "";
		//Sets pre-sanitized text to the current user input.
		rawText = userInput;
		//Clears user input to ready it for the sanitized text.
		userInput = "";
		//Clears any spaces from the user input.
		for (size_t i = 0; i < rawText.length(); i++)
		{
			//Statement to remove spaces.
			if (isspace(rawText[i]))
			{
				//--->>Intentionally left blank to remove spaces.<<---
			}
			else
			{
				//Adds the input text to the fixed string if the text is not a blank space.
				userInput += rawText[i];
			}
		}
		//Loop to output all possible decrypted variations.
		while (globalCount <= max_count)
		{
			//Variable for output.
			std::string outPut = "";
			//Variable to hold the current key.
			std::string key = keyVect[globalCount];
			//Loop to compare each letter of the string to the key.
			for (size_t i = 0; i < userInput.length(); i++)
			{
				//Loop to step though each segment of the key.
				for (size_t j = 0; j <= key.length(); j++)
				{
					//Statment that runs if the current item in the userInput is equal to the current item in the key.
					if (userInput[i] == key[j]) {
						//Sets the corresponding key item to the output.
						outPut += key[i];
					}
				}
			}

			//Adds to the global count each itteration.
			globalCount += 1;
			std::cout << "key: " << key << std::endl;
			//Prints out the input decrypted with the current key each itteration.
			std::cout << outPut << std::endl;
		}
		//Pauses the program after all itterations.
		system("pause");
	}
	return;
}

//Main function used as a starting point for the program.
void main()
{
	//Asks the user if they would like to encypte or decrypt a string.
	std::string typeFirst;
	std::cout << "Would you like to Decrypt(d) or Encrypt(e) a phrase? " << std::endl;
	std::getline(std::cin, type);

	//Pulls the first letter of the input string.
	if (type.length() > 1)
	{
		int firstLetterInt = type.length() - 1;
		typeFirst = type[type.length() - firstLetterInt];
	}
	else if (type.length() == 1)
	{
		typeFirst = type;
	}
	else if (type.length() < 1)
	{
		main();
	}
	//Chooses to either start the encryption or decryption process.
	if (typeFirst == "d" || typeFirst == "D")
	{
		//Get the keyspace desired from the user.
		std::cout << std::endl;
		std::cout << "What size key would you like to use?" << std::endl;
		//Generates the key.
		UserIn("key");
		//Gets the user decryption text.
		std::cout << std::endl;
		std::cout << "What is the text you would like to decrypt? " << std::endl;
		//Sanitizes the user input.
		UserIn("decrypt");
		//Decrypts the user input.
		decrypt();
	}
	else if (typeFirst == "e" || typeFirst == "E")
	{
		std::cout << std::endl;
		//Runs encryption.
		encrypt();
	}
	else
	{
		//This runs when a non valid choice is input.
		std::cout << std::endl;
		std::cout << "Please enter a valid choice of either Decrypt(d) or Encrypt(e)." << std::endl;
		//Pauses the program for the user to read.
		system("pause");
		//Restarts the program.
		main();
	}
	//Checks if the user would like to rerun the program.
	reRun();
	//Ends the program.
	return;
}

