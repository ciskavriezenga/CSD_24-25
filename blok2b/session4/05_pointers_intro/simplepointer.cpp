#include <iostream>


// maakt een kopie van year
void addTenByValue(int number)
{
  number = number + 10;
}


// wijst met een pointer naar year
void addTenByPointer(int* number)
{
  *number = *number + 10;
}


/* we kunnen number gewoon gebruiken als variabele
 * maar realiseer je dat achter de schermen
 * met een pointer naar year gewerkt wordt
 */
void addTenByReference(int& number)
{
  number = number + 10;
}


int main()
{

  int year=2022;

  std::cout << year << std::endl;
  addTenByValue(year);
  std::cout << year << std::endl;
  addTenByPointer(&year);
  std::cout << year << std::endl;
  addTenByReference(year);
  std::cout << year << std::endl;

  return 0;

}

