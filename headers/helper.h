#pragma once
#include <iostream>
#include <string>

using namespace std;

class Snack
{
public:
    Snack(const string& name);
    Snack(const string& name, int price);
  string getName() const;
  void setSnackName(string& name);
  void setSnackPrice(int& price);
  int getSnackPrice() const;
private:
  string name;
  int price;
};

class SnackSlot
{
public:
    SnackSlot(short slotsAvailable);
  short getQuantity() const;
  short getFreeSlots() const;
  void addSnack(Snack *snack);
  void giveSnack();
  ~SnackSlot();
private:
  short slotsAvailable;
  short snacksQty;
  Snack** snacks;
};

class VendingMachine
{
public:
    VendingMachine(short totalSlots);
  void addSlot(SnackSlot* name);
  short getEmptySlotsCount() const;
  void giveSnack();
  ~VendingMachine();
private:
  short slotCount;
  short totalSlots;
  short snackCount;
  SnackSlot** slots;
};