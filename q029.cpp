#include <string>
#include <cassert>
#include <regex>

bool validate_license_plate_format(std::string const & str) {

    // cpprefjp.github.io/lang/cpp11/raw_string_literals.html
    std::regex rx(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");

    // https://cpprefjp.github.io/reference/string/basic_string/c_str.html
    return std::regex_match(str.c_str(), rx);
}

std::vector<std::string> extract_license_plate_numbers(std::string const & str) {
    std::regex rx(R"(([A-Z]{3}-[A-Z]{2} \d{3,4})*)");
    std::smatch match;
    std::vector<std::string> results;

    // https://cpprefjp.github.io/reference/regex/regex_iterator.html
    for (auto i = std::sregex_iterator(std::cbegin(str), std::cend(str), rx);
         i != std::sregex_iterator(); ++i) {
            if((*i)[1].matched) {
                results.push_back(i->str());
            }
         }
         return results;
}

int main() {
    // test: validate_license_plate_format
    assert(validate_license_plate_format("ABC-DE 123"));
    assert(validate_license_plate_format("ABC-DE 1234"));
    // assert(validate_license_plate_format("ABC-DE 12345"));
    // assert(validate_license_plate_format("abc-de 1234"));

    // test: extract_license_plate_numbers
    std::vector<std::string> expected{"AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001"};
    std::string text{"AAA-AA 123qwe-ty 1234 ABC-DE 123456.. XYZ-WW 0001"};
    assert(expected == extract_license_plate_numbers(text));
}