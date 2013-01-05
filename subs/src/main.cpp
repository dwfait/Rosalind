#include <iostream>
#include <stdexcept>
#include <rosalind.h>

void process_data(std::vector<std::string> data);

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: subs <input file path>" << std::endl;
    return -1;
  }

  auto data = Rosalind::read_data_file(argv[1]);

  unsigned int expected_data_lines = 2;
  if (data.size() != expected_data_lines)
  {
    std::cout << "Expected " << expected_data_lines
      << "lines in data file." << std::endl;
    return -1;
  }

  process_data(data);

  return 0;
}


void process_data(std::vector<std::string> data)
{
  std::string str = data[0];
  std::string substr = data[1];

  std::size_t location;

  while(true){
    location = str.find(substr,location);
    if (location == std::string::npos){
      break;
    } else {
      ++location;
      std::cout << location << " ";
    }
  }
  std::cout << std::endl;
}
