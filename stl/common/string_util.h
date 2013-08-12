#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <algorithm> 
#include <functional> 
#include <iterator> 
#include <vector>
#include <sstream>
#include <string>


namespace StringUtil {

// trim from start
inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
inline std::string &rtrim(std::string &s) {
    // here is to find forward iterator of a reverse iterator via base() method
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

inline void split(const std::string &str, std::vector<std::string> &items, char delimeter) {
    std::istringstream ss(str);
    std::string item;
    while(std::getline(ss, item, delimeter)) {
        trim(item);
        if (!item.empty()) {
            items.push_back(item);
        }
    }
}

/*
 * this function will append one extra delimeter to destination
template <class T>
inline std::string join(const std::vector<T> &items, const char delimeter) {
    std::ostringstream oss;
    const char c[] = {delimeter};
    std::ostream_iterator<T> osit(oss, c);
    std::copy(items.begin(), items.end(), osit);
    return oss.str();
}
*/

template <class T>
inline std::string join(const std::vector<T> &items, char delimeter) {
    std::ostringstream oss;
    for (typename std::vector<T>::const_iterator it = items.begin(); it != items.end(); ++it) {
        if (it != items.begin()) {
            oss << delimeter;
        }
        oss << *it;
    }
    return oss.str();
}


} //end of namespace

#endif
