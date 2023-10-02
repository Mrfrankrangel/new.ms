#include <iostream>
#include <string>

// Function to calculate the Julian day number using the Fliegel & Van Flandern equation.
int JulianDay(int month, int day, int year) {
  if (month <= 2) {
    year--;
    month += 12;
  }
  int a = year / 100;
  int b = 2 - a + (year / 4);
  return (int)(365.25 * (year + 4716)) + (int)(30.6001 * (month + 1)) + day + b - 1524;
}

// Function to return the number of days between a start date and end date.
int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  int startJulian = JulianDay(start_month, start_day, start_year);
  int endJulian = JulianDay(end_month, end_day, end_year);
  return endJulian - startJulian;
}

// Function to print the given date to standard output in the format MM/DD/YYYY
void PrintDate(int month, int day, int year) {
  std::cout << month << "/" << day << "/" << year;
}

// Function to prompt the user for an integer and return it.
int PromptForInt(std::string query) {
  int value;
  std::cout << query;
  std::cin >> value;
  return value;
}

int main(int argc, char* argv[]) {
  // Prompt the user for start date components
  int start_month = PromptForInt("Enter a start month: ");
  int start_day = PromptForInt("Enter a start day: ");
  int start_year = PromptForInt("Enter a start year: ");

  // Prompt the user for end date components
  int end_month = PromptForInt("Enter an end month: ");
  int end_day = PromptForInt("Enter an end day: ");
  int end_year = PromptForInt("Enter an end year: ");

  // Calculate the difference between the two dates
  int difference = DateDifference(start_month, start_day, start_year,
                                   end_month, end_day, end_year);

  // Output the result
  std::cout << "The number of days between ";
  PrintDate(start_month, start_day, start_year);
  std::cout << " and ";
  PrintDate(end_month, end_day, end_year);
  std::cout << " is " << difference << " days." << std::endl;

  return 0;
}
