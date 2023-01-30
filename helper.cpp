#include <iostream>
#include <string>
#include "./headers/helper.h"

using namespace std;

Snack::Snack(const string& name)
{
  this->name = name;
}

Snack::Snack(const string& name, int price)
{
  this->name = name;
  this->price = price;
}

string Snack::getName() const
{
  return name;
}

void Snack::setSnackName(string& name)
{
  this->name = name;
}

void Snack::setSnackPrice(int& price)
{
  this->price = price;
}

int Snack::getSnackPrice() const
{
  return price;
}

SnackSlot::SnackSlot(short slots)
{
  slotsAvailable = slots;
  snacks = new Snack * [slots];
}

SnackSlot::~SnackSlot()
{
  delete[] snacks;
}

short SnackSlot::getQuantity() const
{
  return slotsAvailable;
}

short SnackSlot::getFreeSlots() const
{
  return slotsAvailable - snacksQty;
}

void SnackSlot::addSnack(Snack *snack)
{
  if (slotsAvailable > snacksQty) {
    snacks[snacksQty] = snack;
    ++snacksQty;
  }
}

void SnackSlot::giveSnack()
{
  if (snacksQty > 0) {
    --snacksQty;
  }
}

VendingMachine::VendingMachine(short totalSlots)
{
  slots = new SnackSlot * [totalSlots];
  slotCount = 0;
  this->totalSlots = totalSlots;
}

void VendingMachine::addSlot(SnackSlot* slot)
{
  slots[slotCount] = slot;
  ++slotCount;
  snackCount += slot->getQuantity();
}

short VendingMachine::getEmptySlotsCount() const
{
  return totalSlots - slotCount;
}

void VendingMachine::giveSnack()
{
  --slotCount;
  slots[slotCount]->giveSnack();
}

VendingMachine::~VendingMachine()
{
	delete[] slots;
}