#include <iostream>
#include <stdexcept>
#include <rosalind.h>

void process_data(std::vector<std::string> data);

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: rna <input file path>" << std::endl;
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

  for(auto& nucleotide : dna)
  {
    if (nucleotide == 'T')
    {
      nucleotide = 'U';
    }
  }

  std::cout << dna << std::endl;
}
