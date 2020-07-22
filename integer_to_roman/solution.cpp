class Solution {
private:
    static string repeat (const string& pattern, const unsigned& repetitions) {
        string answer;

        for (size_t i = 0; i < repetitions; i ++)
            answer += pattern;

        return answer;
    }

    static string getRomanDigit (
            const unsigned& digit,
            const string& small,
            const string& middle,
            const string& great
    ) {
        if (digit < 4)
            return repeat(small, digit);

        else if (digit == 4)
            return small + middle;

        else if (digit < 9)
            return middle + repeat(small, digit - 5);

        else if (digit == 9)
            return small + great;

        return "";
    }

public:
    string intToRoman(int num) {
        unsigned a = num / 1000;
        unsigned b = (num % 1000) / 100;
        unsigned c = (num % 100) / 10;
        unsigned d = num % 10;

        return
            getRomanDigit(a, "M", "", "") +
            getRomanDigit(b, "C", "D", "M") +
            getRomanDigit(c, "X", "L", "C") +
            getRomanDigit(d, "I", "V", "X");
    }
};

