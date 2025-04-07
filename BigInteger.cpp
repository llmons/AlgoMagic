#include <iostream>
#include <vector>

class BigInt {
  std::vector<int> num;
  void fixLen() {
    while (!num.empty() && num.back() == 0)
      num.pop_back();
    if (num.empty())
      num.emplace_back(0);
  }

public:
  BigInt() { num.emplace_back(0); }
  BigInt(int x) {
    for (; x > 0; x /= 10)
      num.emplace_back(x % 10);
    if (num.empty())
      num.emplace_back(0);
  }
  BigInt(std::string s) {
    int len = s.size();
    num.resize(len);
    for (int i = 0; i < len; ++i)
      num[i] = s[len - 1 - i] - '0';
    fixLen();
  }
  void fix() {
    int len = num.size();
    num.resize(len + 1);
    for (int i = 0; i < len; ++i) {
      num[i + 1] += num[i] / 10;
      num[i] %= 10;
    }
    fixLen();
  }
  BigInt operator+(const BigInt &o) const {
    BigInt ret;
    int len = std::max(num.size(), o.num.size());
    ret.num.resize(len + 1);
    for (int i = 0; i < len; ++i) {
      if (i < num.size())
        ret.num[i] += num[i];
      if (i < o.num.size())
        ret.num[i] += o.num[i];
    }
    ret.fix();
    return ret;
  }
  BigInt operator*(const BigInt &o) const {
    BigInt ret;
    int len = num.size() + o.num.size();
    ret.num.resize(len);
    for (int i = 0; i < num.size(); ++i) {
      for (int j = 0; j < o.num.size(); ++j) {
        ret.num[i + j] += num[i] * o.num[j];
      }
    }
    ret.fix();
    return ret;
  }
  friend std::ostream &operator<<(std::ostream &os, const BigInt &x) {
    for (int i = x.num.size() - 1; i >= 0; --i) {
      os << x.num[i];
    }
    return os;
  }
};