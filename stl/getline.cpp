// extract to string
#include <iostream>
#include <string>

#include "../common/string_util.h"

main ()
{

  std::cout << "Please, enter your full name: ";

  std::string name;
  while (std::getline (std::cin, name, ',')) {
      StringUtil::trim(name);
      if (name.empty())
        break;
      std::cout << "Hello, " << name << "!\n";
  }

  return 0;
}

