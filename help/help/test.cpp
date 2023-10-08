#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solver {
public:
  Solver(const std::vector<char> &symbols, const std::vector<char> &first,
         const std::vector<char> &second, const std::vector<char> &solution)
      : symbols_(symbols), first_(first), second_(second), solution_(solution) {
    checked_ = vector<bool>(10, false);
    for (char c : symbols_) {
      assignments_[c] = -1;
    }
  }
  Solver() { checked_ = vector<bool>(10, false); }

  std::string solveForDigits() { return backtrack(0); }

private:
  std::vector<char> symbols_;
  std::vector<char> first_;
  std::vector<char> second_;
  std::vector<char> solution_;
  std::vector<bool> checked_;
  std::unordered_map<char, int> assignments_;

  bool isValid() {
    int n1 = 0, n2 = 0, res = 0;
    for (char c : first_) {
      n1 = n1 * 10 + assignments_.at(c);
    }
    for (char c : second_) {
      n2 = n2 * 10 + assignments_.at(c);
    }
    for (char c : solution_) {
      res = res * 10 + assignments_.at(c);
    }
    return n1 + n2 == res;
  }

  std::string backtrack(int index) {
    if (index == symbols_.size()) {
      if (isValid()) {
        std::string result;
        for (char c : symbols_) {
          result += std::to_string(assignments_.at(c));
        }
        return result;
      }
      return "";
    }

    for (int digit = 0; digit < 10; digit++) {
      if (!checked_[digit]) {
        assignments_[symbols_[index]] = digit;
        checked_[digit] = true;
        std::string res = backtrack(index + 1);
        if (!res.empty())
          return res;
        checked_[digit] = false;
      }
    }
    return "";
  }
};

int main() {
  std::string symbols_str, first_str, second_str, solution_str;
  std::cin >> symbols_str >> first_str >> second_str >> solution_str;

  std::vector<char> symbols(symbols_str.begin(), symbols_str.end());
  std::vector<char> first(first_str.begin(), first_str.end());
  std::vector<char> second(second_str.begin(), second_str.end());
  std::vector<char> solution(solution_str.begin(), solution_str.end());

  Solver solver(symbols, first, second, solution);
  std::cout << solver.solveForDigits() << std::endl;
}