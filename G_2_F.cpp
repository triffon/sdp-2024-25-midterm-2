/***********************************************************************
 * Моля, преименувате файла, като:
 *   - замените G с групата, с която ходите на упражнения
 *   - замените F с вашия факултетен номер
 **********************************************************************/

/***********************************************************************
 Задача 2. Дума наричаме последователност от малки и големи латински букви.
 Изречение наричаме низ, който представлява последователност от думи,
 разделени с точно един интервал. Да се реализира функция с минимална
 сложност по време bool permuteOrCommon(std::string const& s1,
 std::string const& s2, std::ostream& os), която проверява дали изречението
 s2 може да се получи с подходящо разместване на думите в изречението s1.
 Ако отговорът е „не", функцията да извежда на потока os думите, които
 се срещат и в двете изречения, разделени с интервал.
 Каква е сложността на решението ви?
 Пример: permuteOrCommon("Merry Christmas and Happy New Year",
                        "Happy New Year and Merry Christmas", std::cout) → true
 permuteOrCommon("Jingle bells jingle bells",
                 "bells jingle all the way", std::cout) → jingle bells
************************************************************************/

#include <iostream>

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/
#include <sstream>
#include "hash_table.hpp"
#include "linked_list.hpp"

size_t betterSumHashFunction(std::string const& s) {
    size_t result = 0;
    for(int i = 0; i < s.size(); i++) {
        (result *= 17) += s[i];
    }
    return result;
}

using WordFrequencies = HashTable<std::string, int, betterSumHashFunction>;

WordFrequencies getFrequencies(std::string const& s) {
  WordFrequencies freq;
  std::istringstream iss(s);
  std::string word;
  while (iss >> word)
    if (!freq.contains(word))
      freq.add(word, 1);
    else
      freq.lookup(word)++;
  return freq;
}

// O(n), където n е сумата от дължините на двете изречения
bool permuteOrCommon(std::string const& s1, std::string const& s2, std::ostream& os) {
    WordFrequencies freq1 = getFrequencies(s1);
    WordFrequencies freq2 = getFrequencies(s2);

    // Проверяваме дали двете изречения са пермутации едно на друго,
    // т.е. дали имат еднакви думи с еднакви честоти.

    bool same = true;
    LinkedList<std::string> commonWords;

    // всяка ли дума в първото изречение я има същия брой пъти във второто?
    for(KeyValuePair<std::string, int> const& kv : freq1)
        if (freq2.contains(kv.key)) {
          commonWords.insertLast(kv.key);
          if (freq2.lookup(kv.key) != kv.value)
            same = false;
        } else
          same = false;

    // има ли думи в второто изречение, които ги няма във първото?
    if (same)
      for(KeyValuePair<std::string, int> const& kv : freq2)
        if (!freq1.contains(kv.key))
          same = false;

    if (same)
        return true;
  
    // Ако не са пермутации, намираме общите думи и ги извеждаме
    for(std::string const& word : commonWords)
        os << word << ' ';

    return false;
}
/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "2_tests.hpp"

int main() {
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
