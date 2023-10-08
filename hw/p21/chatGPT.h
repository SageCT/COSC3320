#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool isValid(const std::unordered_map<char, int> &assignments,
             const std::vector<char> &first, const std::vector<char> &second,
             const std::vector<char> &solution) {
  int n1 = 0, n2 = 0, res = 0;
  for (char c : first) {
    n1 = n1 * 10 + assignments.at(c);
  }
  for (char c : second) {
    n2 = n2 * 10 + assignments.at(c);
  }
  for (char c : solution) {
    res = res * 10 + assignments.at(c);
  }
  return n1 + n2 == res;
}

std::string backtrack(int index, std::unordered_map<char, int> &assignments,
                      const std::vector<char> &symbols,
                      const std::vector<char> &first,
                      const std::vector<char> &second,
                      const std::vector<char> &solution) {
  if (index == symbols.size()) {
    if (isValid(assignments, first, second, solution)) {
      std::string result;
      for (char c : symbols) {
        result += std::to_string(assignments.at(c));
      }
      return result;
    }
    return "";
  }

  for (int digit = 0; digit < 10; digit++) {
    if (assignments.find(symbols[index]) == assignments.end()) {
      assignments[symbols[index]] = digit;
      std::string res =
          backtrack(index + 1, assignments, symbols, first, second, solution);
      if (!res.empty()) {
        return res;
      }
      assignments.erase(symbols[index]);
    }
  }
  return "";
}

std::string solveForDigits(const std::vector<char> &symbols,
                           const std::vector<char> &first,
                           const std::vector<char> &second,
                           const std::vector<char> &solution) {
  std::unordered_map<char, int> assignments;
  for (char c : symbols) {
    assignments[c] = -1;
  }
  return backtrack(0, assignments, symbols, first, second, solution);
}

int main() {
  std::string symbols_str, first_str, second_str, solution_str;
  std::cin >> symbols_str >> first_str >> second_str >> solution_str;
  std::vector<char> symbols(symbols_str.begin(), symbols_str.end());
  std::vector<char> first(first_str.begin(), first_str.end());
  std::vector<char> second(second_str.begin(), second_str.end());
  std::vector<char> solution(solution_str.begin(), solution_str.end());
  std::cout << solveForDigits(symbols, first, second, solution) << std::endl;
  return 0;
}