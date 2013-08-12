#include <assert.h>
#include <iostream>

#include "string_util.h"

int main() {
    std::string s1 = "  hello world ";
    assert(StringUtil::ltrim(s1) == "hello world ");
    assert(StringUtil::ltrim(s1) == "hello world ");

    assert(StringUtil::rtrim(s1) == "hello world");
    assert(StringUtil::rtrim(s1) == "hello world");

    std::string s2 = "  ,hello world ";
    assert(StringUtil::trim(s2) == ",hello world");
    

    std::string s3 = "a,b, c, d,";
    std::vector<std::string> strs;
    StringUtil::split(s3, strs, ',');
    assert(strs.size() == 4);
    for (size_t i = 0, c = 'a'; i < strs.size(); ++i, c += 1) {
        assert(strs[i] == std::string(1, c));
    }
    const std::string s3a = StringUtil::join<std::string>(strs, ',');
    std::cout << "StringUtil::join result:" << s3a << std::endl;
    assert(s3a == "a,b,c,d");

    return 0;
}
