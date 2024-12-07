#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> answer;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                if (i % 5 == 0) answer.emplace_back("FizzBuzz");
                else answer.emplace_back("Fizz");
            }
            else if (i % 5 == 0) answer.emplace_back("Buzz");
            else answer.emplace_back(std::to_string(i));

        }

        return answer;
    }
};