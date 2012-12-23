#include <iostream>
#include <stdexcept>
#include <rosalind.h>
#include <dna.h>

void process_data(std::vector<std::string> data);

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: gc <input file path>" << std::endl;
    return -1;
  }

  auto data = Rosalind::read_data_file(argv[1]);

  process_data(data);

  return 0;
}


void process_data(std::vector<std::string> data)
{
  auto dnas = Rosalind::process_fasta_data(data);

  std::string highest_id;
  double highest_perc = 0.0;

  for (Dna& dna : dnas)
  {
    double gc_count = 0.0;
    for (auto c : dna.dna)
    {
      if (c == 'G' || c == 'C')
        ++gc_count;
    }

    double perc = gc_count / dna.dna.size() * 100;

    if (perc > highest_perc)
    {
      highest_perc = perc;
      highest_id = dna.id;
    }
  }

  std::cout << highest_id << std::endl;
  std::cout << highest_perc << "%" << std::endl;
}
