TEST_CASE("Примерът от условието работи") {
    std::string s[] = {"is","it","bells","Christmas","pine",
                        "star","holly","yet","cheer","gift"};
    int l[] = {1, 3,4,6,-1,8,-1,-1,-1,-1};
    int r[] = {2,-1,5,7,-1,9,-1,-1,-1,-1};
    CHECK( verticalSentence(buildTree(s, l, r), "is it Christmas yet"));
    CHECK(!verticalSentence(buildTree(s, l, r), "is star gift"));
    CHECK(!verticalSentence(buildTree(s, l, r), "is bells star"));
}
