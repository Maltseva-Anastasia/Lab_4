#include "Arkanoid.h"
#include <fstream>


int main(int argc, char** argv)
{
  std::ifstream inputFile;
  if (argc < 2) {
    std::cerr << "Not enough command line arguments!\n";
    return 1;
  }
  
  inputFile.open(argv[1]);
  if (!inputFile.is_open())
  {
    std::cerr << "Unable to open file!\n";
    return 1;
  }
  Arkanoid game("Arkanoid", 1000, 600);
  game.readLevels(inputFile);
  game.go();
  return 0;
}