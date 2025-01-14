/***********************************************************************
 * Моля, преименувате файла, като:
 *   - замените G с групата, с която ходите на упражнения
 *   - замените F с вашия факултетен номер
 **********************************************************************/

/***********************************************************************
Задача1. Двоично дърво с думи по върховете се задава чрез три масива с 
еднаква дължина n: масив s от низовете по върховете на дървото и два 
масива l и r, където на всеки индекс 0 ≤ i < n съответства възел със 
стойност s[i] и индекси на ляво и дясно дете съответно l[i] и r[i]. 
Липса на дете се задава с индекс -1, а коренът е на индекс 0. 
а) Да се реализира функция
<подходящ тиm> buildTree(size_t n, std::string s[], int l[], int r[]), 
която построява свързано представяне на двоичното дърво, зададено чрез 
три масива.
б) Да се реализира функция
bool horizontalSentence(<тип> tree, std::string const& sentence),
която проверява дали има ниво в дървото tree, чиито думи, разделени с
интервал, съставят изречението sentence и се грижи за освобождаването
на паметта.
Пример: std::string s[] = {"mistletoe","snow","bells","is","it","Christmas",
                   	     "yet","holly","pine","cheer","gift","Santa"};
int l[] = {1,3,5,7,9,10,-1,-1,-1,-1,-1,-1}, r[] = {2,4,6,8,-1,11,-1,-1,-1,-1,-1,-1};
horizontalSentence(buildTree(s, l, r), "is it Christmas yet")	→ true
horizontalSentence(buildTree(s, l, r), "holy pine gift Santa")	→ false
horizontalSentence(buildTree(s, l, r), "holy pine cheer")		→ false
************************************************************************/

#include <string>

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/
#include "linked_queue.hpp"
#include "binary_tree.hpp"

using StringTree = BinaryTree<std::string>;
StringTree buildTree(std::string s[], int l[], int r[], int index = 0) {
    if (index == -1)
        return StringTree();
    return StringTree(s[index], buildTree(s, l, r, l[index]), buildTree(s, l, r, r[index]));
}

bool horizontalSentence(StringTree tree, std::string const& sentence) {
    if (tree.empty()) {
        // Ако дървото е празно, връщаме true само ако изречението също е празно
        return sentence.empty();
    }

    using Position = StringTree::Position;
    LinkedQueue<Position> q;
    q.enqueue(tree.rootPos());
    int levelSize = 1, newLevelSize;

    while (!q.empty()) {
        std::string levelStr;
        newLevelSize = 0;
        for (int i = 0; i < levelSize; ++i) {
            Position current = q.dequeue();
            if (i > 0)
                levelStr += ' ';
            levelStr += *current;

            if (-current) {
                q.enqueue(-current);
                newLevelSize++;
            }
            if (+current) {
                q.enqueue(+current);
                newLevelSize++;
            }
        }
        levelSize = newLevelSize;

        if (levelStr == sentence)
            return true;
    }

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
#include "1_tests.hpp"

int main () {
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
