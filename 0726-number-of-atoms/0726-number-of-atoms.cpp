class Solution {
public:
    string countOfAtoms(string formula) {
        vector<map<string, int>> scopes(1);
        int i = 0, n = formula.size();
        auto number = [&]() {
            int value = 0;
            while (i < n && isdigit(formula[i])) value = value * 10 + formula[i++] - '0';
            return value == 0 ? 1 : value;
        };
        while (i < n) {
            if (formula[i] == '(') { scopes.emplace_back(); ++i; }
            else if (formula[i] == ')') {
                ++i; int multiplier = number();
                auto group = scopes.back(); scopes.pop_back();
                for (auto& [atom, count] : group) scopes.back()[atom] += count * multiplier;
            } else {
                string atom(1, formula[i++]);
                while (i < n && islower(formula[i])) atom += formula[i++];
                scopes.back()[atom] += number();
            }
        }
        string answer;
        for (auto& [atom, count] : scopes.front()) {
            answer += atom;
            if (count > 1) answer += to_string(count);
        }
        return answer;
    }
};