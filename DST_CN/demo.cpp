// #include <assert.h>
// #include <algorithm>
// #include <iostream>
// #include <iterator>
// #include <vector>

// int main()
// {
//     int values[] = {1, 2, 3, 4, 5, 6, 7};
//     int elements[] = {1, 1, 1, 0, 0, 0, 0};
//     const size_t N = sizeof(elements) / sizeof(elements[0]);
//     assert(N == sizeof(values) / sizeof(values[0]));
//     std::vector<int> selectors(elements, elements + N);

//     do
//     {
//         for (size_t i = 0; i < selectors.size(); ++i)
//             if (selectors[i])
//                 std::cout << values[i] << ", ";
//         std::cout << std::endl;
//     } while (prev_permutation(selectors.begin(), selectors.end()));
// }





// #include <algorithm>
// #include <iostream>
// #include <iterator>

// bool isOdd(int x)
// {
//     return x % 2 != 0; // x % 2 == 1 is WRONG
// }

// void moveOddsBeforeEvens()
// {
//     int oddeven[] = {1, 2, 3, 4, 5, 6};
//     std::partition(oddeven, oddeven + 6, &isOdd);
//     std::copy(oddeven, oddeven + 6, std::ostream_iterator<int>(std::cout, ", "));
//     std::cout << std::endl;
// }

// int main()
// {
//     moveOddsBeforeEvens();

//     int oddeven[] = {1, 2, 3, 4, 5, 6};
//     std::stable_partition(oddeven, oddeven + 6, &isOdd);
//     std::copy(oddeven, oddeven + 6, std::ostream_iterator<int>(std::cout, ", "));
//     std::cout << std::endl;
// }





// #include <algorithm>
// #include <iostream>
// #include <iterator>
// #include <vector>

// int main()
// {
//     int elements[] = {1, 2, 3, 4};
//     const size_t N = sizeof(elements) / sizeof(elements[0]);
//     std::vector<int> vec(elements, elements + N);

//     int count = 0;
//     do
//     {
//         std::cout << ++count << ": ";
//         std::copy(vec.begin(), vec.end(),
//                   std::ostream_iterator<int>(std::cout, ", "));
//         std::cout << std::endl;
//     } while (next_permutation(vec.begin(), vec.end()));
// }





// #include <assert.h>
// #include <algorithm>
// #include <string>

// struct AreBothSpaces
// {
//     bool operator()(char x, char y) const
//     {
//         return x == ' ' && y == ' ';
//     }
// };

// void removeContinuousSpaces(std::string &str)
// {
//     std::string::iterator last = std::unique(str.begin(), str.end(), AreBothSpaces());
//     str.erase(last, str.end());
// }

// int main()
// {
//     std::string inout;

//     inout = "";
//     removeContinuousSpaces(inout);
//     assert(inout == "");

//     inout = "a";
//     removeContinuousSpaces(inout);
//     assert(inout == "a");

//     inout = " a";
//     removeContinuousSpaces(inout);
//     assert(inout == " a");

//     inout = "  a";
//     removeContinuousSpaces(inout);
//     assert(inout == " a");

//     inout = "a ";
//     removeContinuousSpaces(inout);
//     assert(inout == "a ");

//     inout = "a  ";
//     removeContinuousSpaces(inout);
//     assert(inout == "a ");

//     inout = "aaa    bbb";
//     removeContinuousSpaces(inout);
//     assert(inout == "aaa bbb");

//     inout = "aaa    bbb       ccc";
//     removeContinuousSpaces(inout);
//     assert(inout == "aaa bbb ccc");

//     inout = " a b   c d ";
//     removeContinuousSpaces(inout);
//     assert(inout == " a b c d ");

//     inout = "        ";
//     removeContinuousSpaces(inout);
//     assert(inout == " ");
// }
