TEST_CASE("Примерът от условието работи") {
    std::string s[] = {"mistletoe","snow","bells","is","it","Christmas",
                       "yet","holly","pine","cheer","gift","Santa"};
    int l[] = {1,3,5,7, 9,10,-1,-1,-1,-1,-1,-1};
    int r[] = {2,4,6,8,-1,11,-1,-1,-1,-1,-1,-1};
    CHECK( horizontalSentence(buildTree(s, l, r), "is it Christmas yet"));
    CHECK(!horizontalSentence(buildTree(s, l, r), "holy pine gift Santa"));
    CHECK(!horizontalSentence(buildTree(s, l, r), "holy pine cheer"));
}
