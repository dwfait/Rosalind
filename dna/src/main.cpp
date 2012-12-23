#include <iostream>
#include <stdexcept>
#include <map>

#include <rosalind.h>

void process_data(std::vector<std::string> data);

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: dna <input file path>" << std::endl;
    return -1;
  }

  auto data = Rosalind::read_data_file(argv[1]);

  unsigned int expected_data_lines = 1;
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
  std::string dna = data[0];

  std::map<char, int> nuc_counter;

  for(auto nucleotide : dna)
  {
    ++nuc_counter[nucleotide];
  }

  std::cout <<
    nuc_counter['A'] << " " <<
    nuc_counter['C'] << " " <<
    nuc_counter['G'] << " " <<
    nuc_counter['T'] << std::endl;

}
