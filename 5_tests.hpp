#include <sstream>
TEST_CASE("Положителен тест") {
    std::ostringstream os;
    CHECK(permuteOrSingle("Merry Christmas and Happy New Year",
                          "Happy New Year and Merry Christmas",
               os));
    CHECK_EQ(os.str(), "");
}

TEST_CASE("Отрицателен тест") {
    std::ostringstream os;
    CHECK(!permuteOrSingle("Jingle bells jingle bells",
                           "jingle bells hooray",
               os));
    std::istringstream iss(os.str() + " ")
    std::string word1, word2;
    CHECK((iss >> word1 >> word2).good());
    bool test = (word1 == "Jingle" && word2 == "hooray") || (word1 == "hooray" && word2 == "Jingle");
    CHECK(test);
    CHECK((iss >> word1).fail());
}
