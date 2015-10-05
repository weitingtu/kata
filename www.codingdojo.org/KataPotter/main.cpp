#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>

std::vector<int> book_count;
std::vector<int> book_set;
std::vector<double> discount = {0.75, 0.8, 0.9, 0.95, 1};

double price(const std::vector<int>& books)
{
    book_count.clear();
    book_count.resize(5, 0);

    for(int i = 0; i < (int)books.size(); ++i)
    {
        book_count[books[i]]++;
    }
//    std::sort(book_count.begin(), book_count.end(), [](int a, int b){return a <b;});
    std::sort(book_count.begin(), book_count.end());

    book_set.clear();
    book_set.resize(5, 0);
    int nb_set = 0;
    for(int i = 0; i < (int)book_count.size(); ++i)
    {
        book_set[i] += (book_count[i] - nb_set);
        nb_set += book_set[i];
    }

    // adjust 5,3 to 4,4
    int n = std::min(book_set[0], book_set[2]);
    book_set[0] -= n;
    book_set[1] += 2*n;
    book_set[2] -= n;

    double cost = 0.0;
    int nb_book = 5;
    for(int i = 0, nb_book = 5; i < (int)book_set.size(); ++i, --nb_book)
    {
        cost += discount[i] * nb_book * book_set[i] * 8;
    }

    return cost;
}

int main()
{
    double cost = price({0, 0, 1, 1, 2, 2, 3, 4});
    printf("cost = %f\n", cost);

    assert(0 == price({}));
    assert(8 == price({0}));
    assert(8 == price({1}));
    assert(8 == price({2}));
    assert(8 == price({3}));
    assert(8 == price({4}));
    assert(8 * 2 == price({0, 0}));
    assert(8 * 3 == price({1, 1, 1}));

    assert(8 * 2 * 0.95 == price({0, 1}));
    assert(8 * 3 * 0.9  == price({0, 2, 4}));
    assert(8 * 4 * 0.8  == price({0, 1, 2, 4}));
    assert(8 * 5 * 0.75 == price({0, 1, 2, 3, 4}));

    assert(8 + (8 * 2 * 0.95) == price({0, 0, 1}));
    assert(2 * (8 * 2 * 0.95) == price({0, 0, 1, 1}));
    assert((8 * 4 * 0.8) + (8 * 2 * 0.95) == price({0, 0, 1, 2, 2, 3}));
    assert(8 + (8 * 5 * 0.75) == price({0, 1, 1, 2, 3, 4}));
    return 0;
}
