#ifndef __ROSALIND_H
#define __ROSALIND_H
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <dna.h>

class Rosalind
{
  public:
    static std::vector<std::string> read_data_file(std::string path)
    {
      std::ifstream data_file(path);
      if (!data_file.good())
        throw std::runtime_error("Can't read "+path);

      std::vector<std::string> data;
      std::copy(std::istream_iterator<std::string>(data_file),
          std::istream_iterator<std::string>(),
          std::back_inserter(data));

      return data;
    }

    static std::vector<Dna> process_fasta_data(std::vector<std::string> lines)
    {
      if (lines.at(0).at(0) != '>')
        throw std::runtime_error("incorrect FASTA format");

      std::vector<Dna> dnas;

      int cur_id_index = 0;
      for (unsigned int x = 1; x < lines.size(); ++x)
      {
        std::string line = lines.at(x);
        if (line.at(0) == '>')
        {
          auto begin = lines.begin() + (cur_id_index);
          auto end = lines.begin() + x;
          Dna dna = create_dna_from_data(begin, end);
          dnas.push_back(dna);
          cur_id_index = x;
        }
      }
      auto begin = lines.begin() + (cur_id_index);
      Dna dna = create_dna_from_data(begin, lines.end());
      dnas.push_back(dna);

      return dnas;
    }

  private:

    static Dna create_dna_from_data(
        std::vector<std::string>::iterator begin,
        std::vector<std::string>::iterator end)
    {
      Dna dna;
      dna.id = (*begin).substr(1);
      for (auto it = begin+1; it != end; ++it)
      {
        dna.dna.append(*it);
      }

      return dna;
    }

};

#endif
