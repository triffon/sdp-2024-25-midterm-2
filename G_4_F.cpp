/***********************************************************************
 * Моля, преименувате файла, като:
 *   - замените G с групата, с която ходите на упражнения
 *   - замените F с вашия факултетен номер
 **********************************************************************/

/***********************************************************************
Задача 4. Двоично дърво с думи по върховете се задава чрез три масива с 
еднаква дължина n: масив s от низовете по върховете на дървото и два 
масива l и r, където на всеки индекс 0 ≤ i < n съответства възел със 
стойност s[i] и индекси на ляво и дясно дете съответно l[i] и r[i]. 
Липса на дете се задава с индекс -1, а коренът е на индекс 0. 
а) Да се реализира функция
<подходящ тип> buildTree(std:string s[], int l[], int r[]),
която построява двоично дърво в свързано представяне 
по дадени три масива.
б) Да се реализира функция
bool verticalSentence(<тип> tree, std::string const& sentence),
която проверява дали има път от корен до листо в дървото tree, чиито думи,
разделени с интервал, съставят изречението sentence.
Представянето на дървото е по ваш избор.
Пример: std::string s[] = {"is","it","bells","Christmas","pine",
                        	"star","holly","yet","cheer","gift"};
int l[] = {1, 3,4,6,-1,8,-1,-1,-1,-1}, r[] = {2,-1,5,7,-1,9,-1,-1,-1,-1};
verticalSentence(buildTree(s, l, r), "is it Christmas yet")	→ true
verticalSentence(buildTree(s, l, r), "is star gift")		    → false
verticalSentence(buildTree(s, l, r), "is bells star")		    → false
************************************************************************/
#include <string>

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

// <подходящ тип> buildTree(std::string s[], int l[], int r[]); {

// bool verticalSentence(<подходящ тип> tree, std::string const& sentence);

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
//#include "4_tests.hpp"

int main () {
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
