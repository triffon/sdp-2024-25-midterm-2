#include <sstream>
TEST_CASE("Положителен тест") {
    std::ostringstream os;
    CHECK(permuteOrCommon("Merry Christmas and Happy New Year",
                          "Happy New Year and Merry Christmas",
               os));
    CHECK_EQ(os.str(), "");
}

TEST_CASE("Отрицателен тест") {
    std::ostringstream os;
    CHECK(!permuteOrCommon("Jingle bells jingle bells",
                           "jingle bells jingle all the way",
               os));
    std::istringstream iss(os.str());
    std::string word1, word2;
    CHECK((iss >> word1 >> word2).good());
    bool test = (word1 == "jingle" && word2 == "bells") || (word1 == "bells" && word2 == "jingle");
    CHECK(test);
    CHECK((iss >> word1).fail());
}
