#include <iostream>
#include "./headers/helper.h"
#include "./helper.cpp"

using namespace std;

int main(){
  Snack *bounty = new Snack("Bounty");
  Snack *snickers = new Snack("Snickers");
  cout << bounty->getName() << ", " <<  snickers->getName() << " created" << endl;
  
  SnackSlot *slot = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);
  slot->addSnack(bounty); //Добавляем батончик в слот
  slot->addSnack(snickers); 

  cout << "всего слотов: " << slot->getQuantity() << endl;
  cout << "доступно мест для снеков: " << slot->getFreeSlots() << endl;
  
  VendingMachine* machine = new VendingMachine(4 /*Количество слотов для снеков*/);
  machine->addSlot(slot); // Помещаем слот обратно в аппарат
 
  cout << machine->getEmptySlotsCount() << endl;
  delete machine;
  delete slot;
  delete snickers;
  delete bounty;
}