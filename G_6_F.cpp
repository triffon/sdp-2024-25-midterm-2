/***********************************************************************
 * Моля, преименувате файла, като:
 *   - замените G с групата, с която ходите на упражнения
 *   - замените F с вашия факултетен номер
 **********************************************************************/

/***********************************************************************
 Задача 6. Асистентът ви по СДП проверява контролна работа, но това се
 оказва тежка задача, тъй като е писано на хартия и листовете са
 разбъркани! Листовете са представени като двусвързан списък от тройни 
 кутии от вида: struct node { int dir, page; node *prev, *next; }; където 
 page указва номера на листа, а dir указва посоката, в която трябва да се
 търси следващия по номер лист. Ако dir е отрицателно число, листът трябва
 да се търси назад в списъка, ако е положително число – напред в списъка,
 а ако е 0 – това е последната страница. Листовете с отрицателен номер са
 чернова и трябва да се изтрият от списъка, тъй като не се четат. Да се 
 реализира функция int pages(node* start), която връща броя листове, които
 асистентът трябва да отгърне, започвайки от листа с номер 1, указан от
 start, за да прочете всички листи подред докато стигне до последната 
 страница. Асистентът не подрежда и не чете листовете, които прелиства,
 докато търси следващия номер, и изхвърля черновите при първо преминаване
 през тях. При грешка функцията да връща -1.
 Пример: pages(5↓ ⇔ 3→ ⇔ -2→ ⇔ 1→ ⇔ -1← ⇔ 2← ⇔ -3→ ⇔ 4←) → 13
************************************************************************/

struct node {
  int code;
  node *prev, *next;
};

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

int pages(node* start);

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
//#include "6_tests.hpp"

int main () {
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
