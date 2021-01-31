#include <string>
#include "container.hpp"

#ifndef F_H
#define F_H

using namespace std;

class Floor : public Container
{
  int id;

public:
  Floor(int i);
  bool UpPressed();
  bool DownPressed();
  void PressUp();
  void PressDown();
  void ClearUp();
  void ClearDown();
  string summary();
  string toString();
};
#endif
