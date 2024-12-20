TEST_CASE("Примерът в условието работи") {
    node* start = new node{0, 5, nullptr,
                  new node{1, 3, nullptr,
                  new node{1,-2, nullptr,
                  new node{1, 1, nullptr,
                  new node{1,-1, nullptr,
                  new node{-1,2, nullptr,
                  new node{-1,-3, nullptr,
                  new node{-1,4, nullptr, nullptr}}}}}}}};
    node *prev = start, *current = start->next;
    while (current) {
      current->prev = prev;
      prev = current;
      current = current->next;
    }

    CHECK_EQ(pages(start->next->next->next), 13);

    while (start) {
      node* toDelete = start;
      start = start->next;
      delete toDelete;
    }
}