TEST_CASE("Примерът в условието работи") {
    node* start = new node{-1, nullptr,
                  new node{2, nullptr,
                  new node{1, nullptr,
                  new node{3, nullptr,
                  new node{-2, nullptr,
                  new node{0, nullptr,
                  new node{4, nullptr, nullptr}}}}}}};
    node *prev = start, *current = start->next;
    while (current) {
      current->prev = prev;
      prev = current;
      current = current->next;
    }

    CHECK_EQ(steps(start->next->next, 2), 8);

    while (start) {
      node* toDelete = start;
      start = start->next;
      delete toDelete;
    }
}