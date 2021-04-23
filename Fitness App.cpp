#include <iostream> 
#include <string>
#include <iomanip>
#include <cctype>
#include <stdlib.h> //system("CLS");
#include <fstream>
using namespace std;

//void main_menu();
int login_function();
void my_account();
void calorie_intake();
void calorie_calculator();
void water_intake();
void progress_tracker();
void workout_plan();
void workout_tracker();

double energy, weight, calories;
double total = 0;
int entry, minutes;
int yoga, badminton, cycling, swimming, running;
int pushups, pullups, situps, squats, jumpingjacks;
int light, moderate, heavy;
int totalminutes = 0;
char input, choice;
string activity;
char goback, gender;
int age, new_age;
int change;
double current_weight, goal_weight, height;
string name, notes;
double finalCal;
double bmr;
double totalwi = 0; // total water intake
string text;

int main() {

	int function;

	system("CLS");
	cout << "\t\t\tMyFitness" << endl;
	cout << "------------------------------------------------------------\n";
	cout << "\t\t\Hello! Welcome to MyFitness\n";

	do {
		cout << "\n------------------------------------------------------------\n";
		cout << "\t\t\tMain Menu";
		cout << "\n------------------------------------------------------------\n";
		cout << "\nPlease select a function\n";
		cout << "\n1. My Account\t\t5. Progress Tracker\n2. Calorie Intake\t6. Workout Plan\n3. Calorie Calculator\t7. Workout Tracker\n4. Water Intake\t\t8. Log-In/Register\n9. Exit" << endl;
		cout << "\nFunction: ";
		cin >> function;
		cout << "------------------------------------------------------------\n";

		if (function == 1) {
			my_account();
		}

		else if (function == 2) {
			calorie_intake();
		}

		else if (function == 3) {
			calorie_calculator();
		}

		else if (function == 4) {
			water_intake();
		}

		else if (function == 5) {
			progress_tracker();
		}

		else if (function == 6) {
			workout_plan();
		}

		else if (function == 7) {
			workout_tracker();
		}

		else if (function == 8) {
			login_function();
		}

		else if (function == 9) {
			cout << "Alright, have a nice day!" << endl;
		}

		else {
			cout << "Invalid Option. Pick a valid function\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}

	} while (function != 1 && function != 2 && function != 3 && function != 4 && function != 5 && function != 6 && function != 7 && function != 8 && function != 9);

	return 0;
}

//login_function 
int login_function()

{
	int command, counter = 0;
	char command2;
	string Username, password, comfirmpassword, inName, inPassword, Name, registerPassword;

	char input;
	system("CLS");
	cout << "\n------------------------------------------------------------\n";
	cout << "\t\tLog-In/ Register" << endl;
	cout << "------------------------------------------------------------\n";
	cout << "Welcome!\n" << endl;
	cout << "Please type in a command." << endl;
	cout << "1 = Register" << endl;
	cout << "2 = Log In" << endl;
	cout << "3 = To Main Menu" << endl;
	cout << "4 = Generate report" << endl;
	cout << "------------------------------------------------------------\n";
	cout << "\nCommand: ";

	while (1)
	{
		cin >> command;

		// Exit
		if (command == 3)
		{
			system("CLS");
			main();
		}

		// Register
		else if (command == 1 && counter == 0)
		{

			ofstream g("registration.txt");
			if (!g.is_open())
			{
				cout << "Could not open file\n";
				return 0;
			}
			system("CLS");

			cout << "\t\t\tRegistration" << endl;
			cout << "\t\t\t------------\n";
			cout << "\nNew Username: ";

			cin.ignore();
			getline(cin, Username);


			do {
				cout << "New Password: "; //check if password and confirm password is correct
				getline(cin, registerPassword);
				cout << "Please type your password again: ";
				getline(cin, comfirmpassword);
				"\n";
				system("CLS");
				if (registerPassword != comfirmpassword) {
					cout << "Password does not match" << endl;
				}
			} while (registerPassword != comfirmpassword);
			counter = 1;
			cout << "Successfully Registered!" << endl;
			cout << "\nYou may proceed to Main Menu by picking '3' in the commands\n";

			cout << "\n------------------------------------------------------------\n";
			cout << "\t\t\tLog-In" << endl;
			cout << "------------------------------------------------------------\n";
			cout << "\nPlease type in a command." << endl;
			cout << "3 = To Main Menu" << endl;
			cout << "4 = Generate report" << endl;
			cout << "------------------------------------------------------------\n";
			cout << "\nCommand: ";

			g << Username; //save name and password to file
			g << '\n';
			g << registerPassword << '\n';
			g.close();
		}

		// Login
		else if (command == 2 && counter == 1)
		{

			ifstream f("registration.txt");
			if (!f.is_open())
			{
				cout << "File error\n";
				return 0;
			}
			getline(f, Username, '\n'); //get data from file
			getline(f, password, '\n');

			system("CLS");

			cout << "\t\t\tLog-In" << endl;
			cout << "\t\t\t------\n";

			cout << "\nEnter Your Username: ";
			cin.ignore();
			getline(cin, inName);
			cout << "Enter Your Password: ";
			getline(cin, inPassword);

			if (inName == Username && inPassword == password)
			{
				cout << "Login Successful\n"
					<< "Welcome, "
					<< Username << endl;
				counter = 2;
				system("CLS");
				cout << "------------------------------------------------------------\n";
				cout << "Welcome " << Username << endl;
				cout << "------------------------------------------------------------\n";
				cout << "Please type in a command.\n";
				cout << "3 = Main Menu\n";
				cout << "4 = Generate report\n";
				cout << "------------------------------------------------------------\n";
				cout << "\nCommand: ";
			}
			else {
				cout << "Incorrect name or password\n";
				cout << "\nPlease log in again." << endl << endl;
				system("pause");
				system("CLS");
				login_function();
			};
		}
		// generate report
		else if (command == 4) {
			system("CLS");
			cout << "\n------------------------------------------------------------\n";
			cout << "User Info";
			cout << "\n------------------------------------------------------------\n";
			cout << "Username: " << inName << endl;
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Gender: " << gender << endl;
			cout << "Height: " << height << endl;
			cout << "Weight: " << current_weight << endl;
			cout << "Goal weight: " << goal_weight << endl;
			cout << "Note to self: " << notes << endl;
			cout << "\n------------------------------------------------------------\n";
			cout << "Calories Tracker";
			cout << "\n------------------------------------------------------------\n";
			cout << "The total amount of calories you ate today is: " << finalCal << endl;
			cout << "Your recommended calorie intake is " << bmr << " kcal" << endl;
			cout << "\n------------------------------------------------------------\n";
			cout << "Water Intake";
			cout << "\n------------------------------------------------------------\n";
			cout << "Your total water intake is: " << totalwi << " ml" << endl;
			cout << "\n------------------------------------------------------------\n";
			cout << "Workout Plan";
			cout << "\n------------------------------------------------------------\n";
			ifstream workout("workoutplan.txt");
			while (getline(workout, text)) {
				cout << text << endl;
			}
			workout.close();
			cout << "You have burned " << total << " calorie(s)" << ", and you have exercised for " << totalminutes << "minutes" << endl;
			cout << "\n------------------------------------------------------------\n";
			cout << "Do you want to print out ? (Y/N) " << endl;
			do {

				cin >> command2;
				command2 = toupper(command2);


				if (command2 == 'Y')
				{
					ofstream report("report.txt");
					if (!report.is_open())
					{
						cout << "Could not open file\n";
						return 0;
					}
					report << "\n------------------------------------------------------------\n";
					report << "User Info";
					report << "\n------------------------------------------------------------\n";
					report << "Username: " << inName << endl;
					report << "Name: " << name << endl;
					report << "Age: " << age << endl;
					report << "Gender: " << gender << endl;
					report << "Height: " << height << endl;
					report << "Weight: " << current_weight << endl;
					report << "Goal weight: " << goal_weight << endl;
					report << "Note to self: " << notes << endl;
					report << "\n------------------------------------------------------------\n";
					report << "Calories Tracker";
					report << "\n------------------------------------------------------------\n";
					report << "The total amount of calories you ate today is: " << finalCal << endl;
					report << "Your recommended calorie intake is " << bmr << " kcal" << endl;
					report << "\n------------------------------------------------------------\n";
					report << "Water Intake";
					report << "\n------------------------------------------------------------\n";
					report << "Your total water intake is: " << totalwi << " ml" << endl;
					report << "\n------------------------------------------------------------\n";
					report << "Workout Plan";
					report << "\n------------------------------------------------------------\n";

					ifstream workout("workoutplan.txt");
					while (getline(workout, text)) {
						report << text << endl;
					}
					workout.close();
					report << "You have burned " << total << " calorie(s)" << ", and you have exercised for " << totalminutes << "minutes" << endl;
					report << "\n------------------------------------------------------------\n";
					report.close();
					system("CLS");
					cout << "Your data has been saved to report.txt" << endl;
					system("pause");
					login_function();

				}
				else if (command2 == 'N')
				{
					system("CLS");
					login_function();

				}
				else
				{
					cout << "invalid command" << endl;
					cin.clear();
				}


			} while (command2 != 'Y' && command2 != 'N');
		}
		else {
			cout << "Invalid Command" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Command: ";
		}

	}
	system("CLS");
	main();

	cout << "------------------------------------------------------";
	cout << "\nWould you like to return back to the main menu? (Y/N): ";
	cin >> input;

	input = toupper(input);

	if (input == 'Y') {
		main();
	}

	else {
		cout << "Alright! Have a nice day\n";
	}
}

//my_account (1)
void my_account() {

	char input;

	system("CLS");

	cout << "\t\t\tMy Account" << endl;
	cout << "------------------------------------------------------------\n";

	cout << "Would you like to record your details? (Y/N): ";
	cin >> input;

	input = toupper(input);

	if (input == 'Y') {

		cout << "Hey there! What's your name?: ";
		cin.ignore();
		getline(cin, name);

		//age
		cout << "\nEnter your age: ";

		while (!(cin >> age)) {
			cout << "\nInvalid input. Please enter a valid age: ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		//gender
		cout << "\nEnter your gender (M/F): ";
		cin >> gender;
		gender = toupper(gender);

		while (gender != 'M' && gender != 'F') {
			cout << "\nInvalid input. Please input a valid gender\n";
			cout << "Enter your gender (M/F): ";
			cin >> gender;
			gender = toupper(gender);
		}

		//height
		cout << "\nEnter your height (cm): ";
		while (!(cin >> height)) {
			cout << "\nInvalid input. Please enter a valid height (cm): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		//current weight
		cout << "---------------------------------------";
		cout << "\nEnter your current weight (KG): ";
		while (!(cin >> current_weight)) {
			cout << "\nInvalid input. Please enter a valid weight (KG): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		//goal weight
		cout << "What's your goal weight? (KG): ";
		while (!(cin >> goal_weight)) {
			cout << "\nInvalid input. Please enter a valid weight: ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		//notes
		cout << "-------------------------------------------------------\n";
		cout << "Any words of encouragement towards the starting of your fitness journey?:\n";
		cin.ignore();
		getline(cin, notes);
		cout << "------------------------------------------------------\n";

		cout << "Name\t\t: " << name << endl;
		cout << "Age\t\t: " << age << endl;
		cout << "Current Weight\t: " << current_weight << " kg" << endl;
		cout << "Goal Weight\t: " << goal_weight << " kg" << endl;
		cout << "Note-to-Self\t: " << notes << endl;
		cout << "------------------------------------------------------";
		cout << "\nProfile is set.\n\nGood luck on your journey!" << endl;

		cout << "------------------------------------------------------";
		cout << "\nWould you like to return back to the main menu? (Y/N): ";
		cin >> input;

		input = toupper(input);

		if (input == 'Y') {
			main();
		}

		else {
			cout << "Alright! Have a nice day\n";
		}
	}
	cout << "------------------------------------------------------";
	cout << "\nWould you like to return back to the main menu? (Y/N): ";
	cin >> input;

	input = toupper(input);

	if (input == 'Y') {
		main();
	}

	else {
		cout << "Alright! Have a nice day\n";
	}
}


//calorie intake (2)
void calorie_intake() {
	string food;
	char input;
	double fat, carbs, protein;
	double fatCal, carbsCal, proteinCal, totalCal = 0;

	system("CLS");

	cout << "\t\t\tCalorie Intake" << endl;
	cout << "------------------------------------------------------------\n";

	do {
		cout << "What did you eat today?: ";
		while (!(cin >> food)) {
			cout << "\nInvalid input. Please enter a valid food: ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		cout << "---------------------------------\n";
		cout << "\nEnter the gram of: ";
		cout << "\nFat: ";
		while (!(cin >> fat)) {
			cout << "\nInvalid input. Please enter a valid value (g): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		cout << "Carbohydrates: ";
		while (!(cin >> carbs)) {
			cout << "\nInvalid input. Please enter a valid value (g): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		cout << "Protein: ";
		while (!(cin >> protein)) {
			cout << "\nInvalid input. Please enter a valid value (g): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		fatCal = fat * 9;
		carbsCal = carbs * 4;
		proteinCal = protein * 4;

		cout << "---------------------------------\n";
		cout << "Number of calories of:\n\n";
		cout << "Fat: " << fatCal << endl;
		cout << "Carbohydrates: " << carbsCal << endl;
		cout << "Protein: " << proteinCal << endl;

		totalCal = fatCal + carbsCal + proteinCal;
		finalCal = finalCal + totalCal;

		cout << "\nThe amount of calories in " << food << " is " << totalCal << endl;
		cout << "--------------------------------------------------------------";

		cout << "\nDid you eat more food? (Y/N): ";
		cin >> input;
		cout << "--------------------------------------------------------------\n";

		input = toupper(input);

	} while (input == 'Y');

	cout << "The total amount of calories you ate today is: " << finalCal << endl;

	cout << "\nWould you like to return back to the main menu? (Y/N): ";
	cin >> input;

	input = toupper(input);

	if (input == 'Y') {
		main();
	}

	else {
		cout << "Alright! Have a nice day\n";
	}
}

//calorie_calculator (3)
void calorie_calculator() {
	int age, activity_level;
	double weight_alm, weight, height; //bmr: basal metabolic rate
	char gender, weight_target;

	char input;

	system("CLS");
	do {
		system("CLS");
		cout << "\t\t\tCalorie Calculator" << endl;
		cout << "------------------------------------------------------------------\n";
		cout << "Kindly add your age, gender, height, current weight and activity level below." << endl;
		cout << "Age			: ";
		while (!(cin >> age)) {
			cout << "\nInvalid input. Please enter a valid age: ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		cout << "Gender (M/F)		: ";
		cin >> gender;
		gender = toupper(gender);

		while (gender != 'M' && gender != 'F') {
			cout << "\nInvalid input. Please input a valid gender\n";
			cout << "Gender (M/F)		:";
			cin >> gender;
			gender = toupper(gender);
		}

		cout << "Height (cm)		: ";
		while (!(cin >> height)) {
			cout << "\nInvalid input. Please enter a valid height (cm): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		cout << "Current Weight (KG)	: ";
		while (!(cin >> weight)) {
			cout << "\nInvalid input. Please enter a valid weight (KG): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		switch (gender) {
		case 'M':
		case 'm':
			bmr = 66 + (13.375 * weight) + (5 * height) - (6.8 * age);
			break;

		case 'F':
		case 'f':
			bmr = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);
			break;

		default:
			cout << "Invalid. Please key in a valid input";
		}

		do {
			cout << "\n-------------------------------------------" << endl;
			cout << " 1 |" << " Little or no exercise" << endl;
			cout << " 2 |" << " Light exercise (1-3 days a week)" << endl;
			cout << " 3 |" << " Moderate exercise (4-5 days a week)" << endl;
			cout << " 4 |" << " Hard exercise/sports (6-7 days a week)" << endl;
			cout << "-------------------------------------------" << endl;

			cout << "Activity Level (1,2,3,4) : ";
			cin >> activity_level;

			switch (activity_level) {
			case 1:
				bmr = bmr * 1.2;
				break;

			case 2:
				bmr = bmr * 1.375;
				break;

			case 3:
				bmr = bmr * 1.55;
				break;

			case 4:
				bmr = bmr * 1.725;
				break;

			default:
				cout << "\nInvalid. Please key in a valid input";
				cin.clear();
				cin.ignore(256, '\n');
				break;
			}
		} while (activity_level != 1 && activity_level != 2 && activity_level != 3 && activity_level != 4);

		cout << "------------------------------------------------" << endl;
		cout << "Your recommended calorie intake is " << bmr << " kcal" << endl;
		cout << "------------------------------------------------" << endl;

		do {
			cout << "Do you want to add, lose or maintain your weight? (A / L / M): ";
			cin >> weight_target;

			switch (weight_target) {
			case 'A':
			case 'a':
				cout << "\nHow much weight do you want to add? (KG): ";
				cin >> weight_alm;
				bmr = bmr + (weight_alm * 100);
				break;

			case 'L':
			case 'l':
				cout << "\nHow much weight do you want to lose? (KG): ";
				cin >> weight_alm;
				bmr = bmr - (weight_alm * 100);
				break;

			case 'M':
			case 'm':
				bmr = bmr;
				break;

			default:
				cout << "\nInvalid. Please key in a valid input\n";
				cin.clear();
				cin.ignore(256, '\n');
			}

			weight_target = toupper(weight_target);

		} while (weight_target != 'A' && weight_target != 'L' && weight_target != 'M');

		cout << "------------------------------------------------" << endl;
		cout << "Your current recommended calorie intake is " << bmr << " kcal" << endl;
		cout << "------------------------------------------------" << endl;

		cout << "\nWould you like to do a new calculation? (Y/N):";
		cin >> input;

		input = toupper(input);

	} while (input == 'Y');

	cout << "------------------------------------------------" << endl;
	cout << "Would you like to return back to the main menu? (Y/N): ";
	cin >> input;

	input = toupper(input);

	if (input == 'Y') {
		main();
	}

	else {
		cout << "Alright! Have a nice day\n";
	}
}

//water_intake (4)
void water_intake() {

	system("CLS");

	cout << "\t\t\tWater Intake" << endl;
	cout << "------------------------------------------------------------------\n";

	int activity_level;
	double weight, water_consumption, rwi, wi_left; //riw: recommended water intake, wi_left: water intake left 
	char input;

	cout << "Would you like to record your water intake today? (Y/N): ";
	cin >> input; 

	input = toupper(input);
	if (input == 'Y') {

		cout << "Kindly add in your activity level, weight and water intake." << endl;

		cout << "\nWeight(KG) : ";
		while (!(cin >> weight)) {
			cout << "\nInvalid input. Please enter a valid weight (KG): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		rwi = weight / 30;
		rwi = rwi * 1000;

		do {
			cout << "\n-------------------------------------------" << endl;
			cout << " 1 |" << " Little or no exercise" << endl;
			cout << " 2 |" << " Light exercise (1-3 days a week)" << endl;
			cout << " 3 |" << " Moderate exercise (4-5 days a week)" << endl;
			cout << " 4 |" << " Hard exercise/sports (6-7 days a week)" << endl;
			cout << "-------------------------------------------" << endl;

			cout << "Activity Level (1,2,3,4) : ";
			cin >> activity_level;
			cout << "-------------------------------------------" << endl;

			switch (activity_level) {

			case 1:
				rwi = rwi + (1.2 / 30 * 0.35);
				break;

			case 2:
				rwi = rwi + (1.375 / 30 * 0.35);
				break;

			case 3:
				rwi = rwi + (1.55 / 30 * 0.35);
				break;

			case 4:
				rwi = rwi + (1.725 / 30 * 0.35);
				break;

			default:
				cout << "\nInvalid Selection. Please enter a valid activity level";
				cin.clear();
				cin.ignore(256, '\n');
			}
		} while (activity_level != 1 && activity_level != 2 && activity_level != 3 && activity_level != 4);

		do {
			cout << "How much was your water intake?\n";
			cout << "Water Intake(ml) : ";
			while (!(cin >> water_consumption)) {
				cout << "\nInvalid input. Please enter a valid value (ml): ";
				cin.clear(); //clear previous input
				cin.ignore(256, '\n'); //discard previous input
			}
			wi_left = rwi - totalwi;

			cout << "-----------------------------------------------\n";
			if (water_consumption < rwi) {
				cout << "You are Dehydrated" << endl;
				cout << "Please drink " << wi_left << " ml more " << endl;
				cout << "--------------------------------------------------";
				cout << "\nYour recommended water intake is " << rwi << " ml" << endl;
				cout << "--------------------------------------------------\n";
			}
			else {
				cout << "You are Hydrated" << endl;
				cout << "--------------------------------------------------";
				cout << "\nYour recommended water intake is " << rwi << " ml" << endl;
				cout << "\nYou drank more than your recommended water intake! Good job!\n";
				cout << "--------------------------------------------------\n";
			}

			totalwi = totalwi + water_consumption;
			wi_left = rwi - totalwi;

			cout << "Your water intake is " << water_consumption << " ml" << endl;
			cout << "You drank " << totalwi << " ml of water in total" << endl;

			cout << "--------------------------------------------------\n";
			cout << "Do you want to add more water consumption? (Y/N) : ";
			cin >> input;
			cout << "--------------------------------------------------\n";

			input = toupper(input);

		} while (input == 'Y');

		cout << "Your total water intake is: " << totalwi << " ml" << endl;
		cout << "\nStay hydrated!\n" << endl;

		cout << "\nWould you like to return back to the main menu? (Y/N): ";
		cin >> input;

		input = toupper(input);

		if (input == 'Y') {
			main();
		}

		else {
			cout << "Alright! Have a nice day\n";
		}
	}
	
	else {
		cout << "\n--------------------------------------------------";
		cout << "\nWould you like to return back to the main menu? (Y/N): ";
		cin >> input;

		input = toupper(input);

		if (input == 'Y') {
			main();
		}

		else {
			cout << "Alright! Have a nice day\n";
		}
	}
}

//progress_tracker (5)
void progress_tracker() {

	double weight, height, BMI, goal_weight, progress_left;
	double new_BMI;

	char input;

	system("CLS");

	cout << "\t\t\tProgress Tracker" << endl;
	cout << "------------------------------------------------------------\n";

	cout << "Would you like to record your progress today? (Y/N): ";
	cin >> input;

	input = toupper(input);
	if (input == 'Y') {

		cout << "Please key in your height and weight to calculate your Body Mass Index(BMI)\n" << endl;
		cout << "Weight(KG): ";
		while (!(cin >> weight)) {
			cout << "\nInvalid input. Please enter a valid weigjt (KG): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		cout << "Height(Metres) (Eg: 1.75m): ";
		while (!(cin >> height)) {
			cout << "\nInvalid input. Please enter a valid height (m): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		BMI = weight / (height * height);

		cout << "------------------------------------------------\n";
		cout << "Your BMI is " << setprecision(2) << fixed << BMI << endl;

		if (BMI < 18.5) {
			cout << "You are underweight." << endl;
		}
		else if (BMI >= 18.5 && BMI <= 24.9) {
			cout << "You are at normal weight." << endl;
		}
		else if (BMI >= 25 && BMI <= 29.9) {
			cout << "You are overweight." << endl;
		}
		else if (BMI >= 30 && BMI <= 34.9) {
			cout << "You are mildly obese." << endl;
		}
		else if (BMI >= 35 && BMI <= 39.9) {
			cout << "You are moderately obesity." << endl;
		}
		else if (BMI > 40) {
			cout << "You are morbidly obese." << endl;
		}

		cout << "---------------------------------------------\n";
		cout << "What is your goal weight?" << endl;
		cout << "Goal Weight(KG)\t:";
		while (!(cin >> goal_weight)) {
			cout << "\nInvalid input. Please enter a valid weight (LG): ";
			cin.clear(); //clear previous input
			cin.ignore(256, '\n'); //discard previous input
		}

		cout << "--------------------------------------------------\n";

		if (goal_weight > weight) {
			progress_left = (weight - goal_weight) * -1;
			cout << "Weight left to gain(KG): " << setprecision(0) << fixed << progress_left << endl;
		}

		else if (goal_weight < weight) {
			progress_left = weight - goal_weight;
			cout << "Weight left to lose(KG): " << setprecision(0) << fixed << progress_left << endl;
		}

		else {
			cout << "Good Job! Maintain your goal!" << endl;
		}

		new_BMI = goal_weight / (height * height);

		cout << "\nNew BMI of goal weight:" << setprecision(2) << fixed << new_BMI << endl;
		cout << "\nGood luck! Fighting!";
		cout << "\n--------------------------------------------------";

		cout << "\nWould you like to return back to the main menu? (Y/N): ";
		cin >> input;

		input = toupper(input);

		if (input == 'Y') {
			main();
		}

		else {
			cout << "Alright! Have a nice day\n";
		}
	}
	cout << "\n--------------------------------------------------";

	cout << "\nWould you like to return back to the main menu? (Y/N): ";
	cin >> input;

	input = toupper(input);

	if (input == 'Y') {
		main();
	}

	else {
		cout << "Alright! Have a nice day\n";
	}
}

//workout_plan (6)
void workout_plan() {
	int index = choice;
	index = 0;

	system("CLS");

	cout << "\t\tWorkout Plan" << endl;
	cout << "------------------------------------------------------------\n";

	cout << "Do you want to work out today? (Y/N)" << endl;
	cout << "Option: ";
	cin >> input;

	input = toupper(input);

	if (input == 'Y') {
		cout << "\nEnter your Weight(KG): ";
		cin >> weight;

		ofstream workoutplan;  //start opening the file
		workoutplan.open("workoutplan.txt");
		do {
			do {
				cout << "------------------------------------------------\n";
				cout << "Please pick a category:" << endl;
				cout << "1. Cardio\n2. Strength\n3. Lifting" << endl;
				cout << "\nCategory: ";
				cin >> entry;

				if (entry == 1) {
					do {
						cout << "------------------------------------------------\n";
						cout << "Pick a workout:" << endl;
						cout << "A. Yoga\t\tD. Swimming\nB. Cycling\tE. Running\nC. Badminton" << endl;
						cout << "\nWorkout: ";
						cin >> choice;

						choice = toupper(choice);

						if (choice == 'A') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Yoga";
							yoga = 3;
							energy = 0.0175 * yoga * weight;
							activity = "Yoga";   // this string is for workout plan output 

						}

						else if (choice == 'B') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Cycling";
							cycling = 5;
							energy = 0.0175 * cycling * weight;
							activity = "Cycling";
						}

						else if (choice == 'C') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Badminton";
							badminton = 6;
							energy = 0.0175 * badminton * weight;
							activity = "Badminton";
						}

						else if (choice == 'D') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen : Swimming";
							swimming = 8;
							energy = 0.0175 * swimming * weight;
							activity = "Swimming";
						}

						else if (choice == 'E') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Running";
							running = 12;
							energy = 0.0175 * running * weight;
							activity = "Running";
						}

						else {
							cout << "\nInvalid Selection. Please insert a valid choice.\n";
						}
					} while (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E');
				}

				else if (entry == 2) {
					do {
						cout << "------------------------------------------------\n";
						cout << "\nPick a workout:" << endl;
						cout << "A. Push-Ups\t\tD. Squats\nB. Pull-Ups\t\tE. Jumping Jacks\nC. Sit-Ups" << endl;
						cout << "\nWorkout: ";
						cin >> choice;

						choice = toupper(choice);

						if (choice == 'A') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Push-Ups";
							pushups = 6;
							energy = 0.0175 * pushups * weight;
							activity = "Push-Ups";
						}

						else if (choice == 'B') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Pull-Ups";
							pullups = 6;
							energy = 0.0175 * pullups * weight;
							activity = "Pull-Ups";
						}

						else if (choice == 'C') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Sit-Ups";
							situps = 3;
							energy = 0.0175 * situps * weight;
							activity = "Sit-Ups";
						}

						else if (choice == 'D') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Squats";
							squats = 9;
							energy = 0.0175 * squats * weight;
							activity = "Squats";
						}

						else if (choice == 'E') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Jumping Jacks";
							jumpingjacks = 6;
							energy = 0.0175 * jumpingjacks * weight;
							activity = "Jumping Jacks";
						}

						else {
							cout << "\nInvalid Selection. Please insert a valid choice.\n";
						}
					} while (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E');
				}

				else if (entry == 3) {
					do {
						cout << "------------------------------------------------\n";
						cout << "Pick a workout:" << endl;
						cout << "A. Light Lifting\nB. Moderate Lifting\nC. Heavy Lifting" << endl;
						cout << "\nWorkout: ";
						cin >> choice;

						choice = toupper(choice);

						if (choice == 'A') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Light Lifting";
							light = 3;
							energy = 0.0175 * light * weight;
							activity = "Light Lifting";
						}

						else if (choice == 'B') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Moderate Lifting";
							moderate = 6;
							energy = 0.0175 * moderate * weight;
							activity = "Moderate Lifting";
						}

						else if (choice == 'C') {
							cout << "------------------------------------------------\n";
							cout << "You have chosen: Heavy Lifting";
							heavy = 9;
							energy = 0.0175 * heavy * weight;
							activity = "Heavy Lifting";
						}

						else {
							cout << "\nInvalid Selection. Please insert a valid choice.\n";
						}

					} while (choice != 'A' && choice != 'B' && choice != 'C');
				}

				else {
					cout << "\nInvalid Selection. Please insert a valid choice.\n";
				}

				index++;

			} while (entry != 1 && entry != 2 && entry != 3);

			cout << "\n\nHow long would you like to work out for? (minutes): ";
			cin >> minutes;
			totalminutes = totalminutes + minutes;

			cout << "\nEnergy expenditure (calories per minute): " << energy;

			calories = energy * minutes;
			cout << "\nCalories to be burned (according to your minutes): " << calories;

			total = total + calories;

			if (!workoutplan) {  //in case they is error opening file
				cout << "Error opening file";
			}

			workoutplan << "You did " << activity << " and burned " << calories << " calorie(s)" << " for " << minutes << " minute(s)" << endl << '\n';

			cout << "\n------------------------------------------------\n";
			cout << "Do you have any other workout plans? (Y/N): ";
			cin >> input;

			input = toupper(input);
		} while (input == 'Y');

		//final display

		cout << "------------------------------------------------\n";
		cout << "You have picked: " << index << " workout(s)";

		cout << "\nThe total amount of calories you can lose from your workout is: " << total;
		cout << "\n\nEnjoy your workout!" << endl;
		workoutplan.close();

		cout << "\nWould you like to return back to the main menu? (Y/N): ";
		cin >> input;

		input = toupper(input);

		if (input == 'Y') {
			main();
		}

		else {
			cout << "\nAlright! Have a nice day\n";
		}
	}

	else {
		cout << "\nAlright! Have a nice day\n";
		cout << "------------------------------------------------" << endl;
		cout << "Would you like to return back to the main menu? (Y/N): ";
		cin >> input;

		input = toupper(input);

		if (input == 'Y') {
			main();
		}

		else {
			cout << "Alright! Have a nice day\n";
		}
	}
}

//workout_tracker (7)

void workout_tracker() {
	void workout_tracker();
	void workoutplan();

	int command;


	cout << "\t\tWorkout Tracker" << endl;
	cout << "------------------------------------------------------------\n";
	cout << "Please enter a command." << endl;
	cout << "1. Check my workout plan" << endl;
	cout << "2. Exit to main menu" << endl;
	cout << "Command: ";
	cin >> command;

	switch (command) {
	case 1:
	{
		ifstream workout("workoutplan.txt");
		while (getline(workout, text)) {
			cout << text << endl;
		}
		workout.close();
		cout << "You have burned " << total << " calorie(s)" << ", and you have exercised for " << totalminutes << " minute(s)" << endl;
		break;
	}
	case 2:
	{
		main();
		break;
	}
	default: {
		cout << "Wrong command" << endl;
		break; }
	}

	cout << "\nWould you like to return back to the main menu? (Y/N): ";
	do {
		cin >> input;

		input = toupper(input);

		if (input == 'Y') {
			main();
		}

		else if (input == 'N') {
			cout << "Have a nice day";
		}
		else {
			cout << "wrong command" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (input != 'Y' && input != 'N');
}
