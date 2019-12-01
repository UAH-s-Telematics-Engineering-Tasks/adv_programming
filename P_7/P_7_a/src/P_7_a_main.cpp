#include "../inc/Library_includes.h"
#include "../inc/P_7_a_Hour_class.h"
#include "../inc/P_7_a_Index_class.h"
#include "../inc/P_7_a_Record_class.h"
#include "../inc/Utils.h"

#define DATA_SIZE 6

const char* menu[] = {
  "1. Enter a new employee",
  "2. Enter a new customer",
  "3. Search by name",
  "4. Show record",
  "5. Show employees",
  "6. Backup the record",
  "7. Restore the record",
  "8. Quit"
};

std::string names[] = {
  "Obi-Wan Kenobi",
  "Mace Windu",
  "Qui-Gon Jinn",
  "Yoda",
  "Darth Vader",
  "Ki-Adi Mundi"
};

std::string positions[] = {
  "Padawan",
  "Jedi Knight",
  "Jedi Master",
  "Stormtrooper",
  "Bounty Hunter",
  "Sith Lord"
};

int ages[] = {20, 25, 30, 35, 40, 45};

int wrk_y[] = {1, 3, 5, 7, 9, 11};

std::string DNIs[] = {"DNI_a", "DNI_b", "DNI_c", "DNI_d", "DNI_e", "DNI_f"};

int main(void) {
  Record_class record(utils::General_utils::read_int("Number of people: "));
  Record_class* backup = NULL;
  int data_index = 0;
  std::string str_buff = "";
  bool flag;
  /* This call is needed for each employee or customer. As it is going to be incredibly cumbersome to fill in the data during tests we are just going to "harcode" some values and pass them */
  /* Employee_class new_emp(utils::Cpp_utils::read_string(str_buff, "Name: "), utils::General_utils::read_int("Age: "), utils::General_utils::read_int("Hours: "), utils::General_utils::read_int("Minutes: "),
  utils::General_utils::read_int("Seconds: "),
  utils::Cpp_utils::read_string(str_buff, "Time_format: "), utils::Cpp_utils::read_string(str_buff, "Position: "), utils::General_utils::read_int("Worked_years: "));*/

  while (true)
    switch (utils::General_utils::show_menu(menu, sizeof(menu) / sizeof(char*))) {
      case 1: {
        Employee_class new_emp(names[data_index % DATA_SIZE], ages[data_index % DATA_SIZE], 12, 0, 0, "AM", positions[data_index % DATA_SIZE], wrk_y[data_index % DATA_SIZE]);
        data_index++;
        if (record.add_person(&new_emp))
          std::cout << "\033[38;2;0;255;255m" << "Current records: " << record.get_next_free() << " " << "\033[0m";
        else
          std::cout << "I'm kind of full... ";
        std::getchar();
      }
        break;

      case 2: {
        Customer_class new_cust(names[data_index % DATA_SIZE], ages[data_index % DATA_SIZE], 12, 0, 0, "AM", DNIs[data_index % DATA_SIZE]);
        data_index++;
        if (record.add_person(&new_cust))
          std::cout << "\033[38;2;0;255;255m" << "Current records: " << record.get_next_free() << " " << "\033[0m";
        else
          std::cout << "I'm kind of full... ";
        std::getchar();
      }
        break;

      case 3:
        if (!record.get_next_free()) {
          std::cout << "\033[38;2;255;0;0m" << "We have an empty record... " << "\033[0m";
          std::getchar();
          break;
        }
        utils::Cpp_utils::read_string(str_buff, "Name to look for: ");
        flag = true;
        for (int i = record.get_next_free() - 1; i >= 0 && flag; i--)
          if (record[i]->get_name() == str_buff) {
            record[i]->show();
            if (Record_class::is_employee(record[i])) {
              std::cout << "\033[38;2;0;255;0m" << "\tI'm an employee!" << "\033[0m";
              flag = false;
            }
            else {
              std::cout << "\033[38;2;0;255;0m" << "\tI'm a customer!" << "\033[0m";
              flag = false;
            }   
          }
        std::getchar();
        break;

      case 4:
        record.show_record();
        std::cout << "\b\b ";
        std::getchar();
        break;

      case 5:
        record.show_employees();
        std::getchar();
        break;

      case 6:
        if (!backup) {
          if(!(backup = new (std::nothrow) Record_class(record)))
            std::cout << "Error while backing up...\n";
          std::cout << "\033[38;2;0;255;0m" << "Backing up... " << "\033[0m";
        }
        else
          std::cout << "\033[38;2;255;0;0m" << "We already have a backup! " << "\033[0m";
        std::getchar();
        break;

      case 7:
        if (backup) {
          record.free_record();
          record = *backup;
          delete backup;
          backup = NULL;
          std::cout << "\033[38;2;0;255;0m" << "Restored the backup! " << "\033[0m";
        }
        else
          std::cout << "\033[38;2;255;0;0m" << "We don't have a backup yet... " << "\033[0m";
        std::getchar();
        break;

      case 8:
        if (backup)
          delete backup;
        return 0;
    }
}
