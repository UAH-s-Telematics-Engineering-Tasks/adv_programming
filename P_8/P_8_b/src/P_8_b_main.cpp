#include "../inc/Library_includes.h"
#include "../inc/P_8_b_Contract_class.h"
#include "../inc/P_8_b_Urgent_disaster_class.h"
#include "../inc/P_8_b_Normal_disaster_class.h"
#include "../inc/P_8_b_Customer_class.h"
#include "../inc/P_8_b_Enterprise_class.h"
#include "../inc/Utils.h"

#define MAX_CUSTOMERS 10

const char* menu[] = {" 1. List_class' empty()",
                      " 2. List_class' operator []",
                      " 3. Contract_class' copy constructor",
                      " 4. Contract_class' add_disaster()",
                      " 5. Customer_class' << operator",
                      " 6. Static member next_code",
                      " 7. Disaster_class' and derived compute_budget()",
                      " 8. Customer_class' add_contract()",
                      " 9. total += insurances[i]",
                      "10. Disaster and Urgent_disaster's constructors",
                      "11. const_cast<List_class<T>*>(this)",
                      "12. get_cost()?",
                      "13. c.add_disaster()",
                      "14. Enterprise_class template",
                      "15. Save and enterprise",
                      "16. Quit"
                };

int main() {
    while(true) {
      switch(utils::General_utils::show_menu(menu, sizeof(menu) / sizeof(char*))) {
          case 1:
        {
          std::vector<std::string> test_vec;
          std::string names[] = {"Name_1", "Name_2", "Name_3", "Name_4", "Name_5",
            "Name_6", "Name_7", "Name_8", "Name_9", "Name_10"};

          for (int i = 0; i < 10; i++)
            test_vec.push_back(names[i]);

          for (long unsigned int i = 0; i < test_vec.size(); i++) {
            try {
              std::cout << test_vec.at(i) << '\n';
            }
            catch (const std::out_of_range& e) {
              std::cout << e.what() << '\n';
            }
          }

          test_vec.clear();

          if (test_vec.empty())
            std::cout << "I'm empty!\n";
          else
            std::cout << "Error freeing the list...\n";

          std::cout << "Answer 1: This question doesn't apply...";
          getchar();
          break;
        }
      case 2:
        {
          std::vector<int> i_vec;
          int acc = 0;

          for (int i = 0; i < 10; i++)
            i_vec.push_back(i);
          
          for (int i = 0; i < 10; i++)
            acc += i_vec[i];

          std::cout << "Total: " << acc << '\n';

          try {
            i_vec.at(20);
          }
          catch (const std::out_of_range& e) {
            std::cout << e.what() << '\n';
          }

          getchar();
          break;
        }
      case 3:
        {
          Contract_class original(12345, "Copy constructor test", "11-01-16", 123456789, 987654321);

          original.add_disaster(Urgent_disaster_class("Disaster 1", local));
          original.add_disaster(Normal_disaster_class("Disaster 2"));
          original.add_disaster(Normal_disaster_class("Disaster 3"));
          std::cout << "Original contract: " << "\n\n" << original;

          std::cout << "\nContract_class' copy constructor successfully executed!" << '\n';
          Contract_class cpy(original);
          original = cpy;
          std::cout << "Copied contract: " << cpy << '\n';

          getchar();
          break;
        }
      case 4:
        {
          Contract_class test(12345);
          test.add_disaster(Urgent_disaster_class("Disaster X", local));
          test.add_disaster(Normal_disaster_class("Disaster Y"));

          test.show_disasters();
          std::cout << "Clone needs to be a virtual method so that we can invoke the method for a reference to the base class and still clone the appropriate object. In other words, we need virtual methods to implement polymorphism!\n";
          getchar();
          break;
        }
      case 5:
        {
          Customer_class test_cust("Obi-Wan");

          Contract_class test_contract(12345);
          test_contract.add_disaster(Urgent_disaster_class("Disaster X", local));
          test_contract.add_disaster(Normal_disaster_class("Disaster Y"));

          test_cust.add_contract(test_contract);

          std::cout << "Customer data:" << '\n' << test_cust << '\n';
          getchar();

          operator<<(std::cout << "Explicit call: ", test_cust);

          getchar();
          break;
        }
      case 6:
        {
          std::cout << "Answer 6: We need to initialize the attribute in the global scope so that we can access it from each and every method. It also needs to be static so that each object we instantiate uses a coherent value\n";
          getchar();
          break;
        }
      case 7:
        {
          Urgent_disaster_class urg_dis("Urgent sinister example", international);
          urg_dis.compute_budget(7, 3);
          Normal_disaster_class nor_dis("Normal disaster example");
          nor_dis.compute_budget(9, 4);

          std::cout << "If we are to access a variable directly using 'dot notation' (i.e through 'this') then we need to be using a PROTECTED attribute, otherwise it won't be accessible to the derived classes... The thing is we could declare 'cost' as a private member in the base class because we happen to have a method that lets us retreive its value: get_cost(). Nevertheless this approach would let us GET the value of said attribute but we wouldn't be able to assign a new value to it... Unless we declare a method like set_cost() OR we use the default assignment operator explicitly through Disaster_class::operator=(). Summing up: If we want to declare 'cost' as a private attribute we MUST define a set_cost() method or we need to use the default assignment operator to achieve the desired functionality.\n";
          getchar();
          break;
        }
      case 8:
        {
          Customer_class test_cust("Yoda");

          Contract_class test_contract(55555);
          test_contract.add_disaster(Urgent_disaster_class("Disaster A", local));
          test_contract.add_disaster(Normal_disaster_class("Disaster B"));

          test_cust.add_contract(test_contract);

          std::cout << "Customer data:" << '\n' << test_cust << '\n';

          getchar();
          break;
        }
      case 9:
        {
          Customer_class* insurances = new Customer_class[MAX_CUSTOMERS];

          Contract_class test_contract(1);
          test_contract.add_disaster(Urgent_disaster_class("Disaster P", local));
          test_contract.add_disaster(Normal_disaster_class("Disaster O"));

          for (int i = 0; i < MAX_CUSTOMERS; i++)
            insurances[i].add_contract(test_contract);

          long total = 0;
          for (int i = 0; i < MAX_CUSTOMERS; i++)
            total += insurances[i];
          std::cout << "\nTotal number of contracts: " << total << '\n';

          getchar();
          delete[] insurances;
          break;
        }
      case 10:
        {
          Normal_disaster_class test_dis("Blowup!");
          test_dis.show();

          getchar();
          break;
        }
      case 11:
        {
          std::cout << "Answer 11: We need to remove the constantness with const_cast() or we won't be able to change any attributes...\n";

          getchar();
          break;
        }
      case 12:
        {
          std::cout << "Answer 12: We have declared Disaster_class so that it's an abstract class. This implies we cannot instantiate it... As we won't have objects belonging of the Disaster_class type we would neet to declare this method 'static' so that we could call it in the absence of any instantiated objects. Nevertheless we notice how this method will be called from objects belonging to Disaster_class' derived classes from where we do have access to the method as we have acquired it through public derivation. Notice how this method is public as well so there is nothing preventing us from calling it from objects belonging to the derived classes!\n";

          getchar();
          break;
        }
      case 13:
        {
          Contract_class test_contract(12345, "RPi 3 B+","LA 2019", 100, 1000);
          Urgent_disaster_class test_dis("Messed up...", national);
          test_contract.add_disaster(test_dis);

          std::cout << "Answer 13: When calling this method we will call the clone() method for a reference to an Urgent_disaster. This will in turn call the copy constructor of the Urgent_disaster class. When it returns the address of the newly reserverd object we will then call the add_element method for a List from our template. This last method will call several methods itself: am_i_empty() and the copy construcor for the Node_class. Depending on the sate of the list we will also call set_next_node() and get_next_node()!\n";

          getchar();
          break;
        }
      case 14:
        {
          Enterprise_class<Customer_class> corp_a;

          Customer_class test_cust("Mace Windu");

          Contract_class test_contract(2);
          test_contract.add_disaster(Urgent_disaster_class("Disaster Q", local));
          test_contract.add_disaster(Normal_disaster_class("Disaster W"));
          test_cust.add_contract(test_contract);

          corp_a.add_element(test_cust);

          Enterprise_class<Customer_class> corp_b(corp_a);

          std::cout << "Enterprise clients:\n" << corp_b[0] << '\n';

          getchar();
          break;
        }
      case 15:
        {
          Enterprise_class<Customer_class> corp;

          Customer_class test_cust("Mace Windu");

          Contract_class test_contract(2);
          test_contract.add_disaster(Urgent_disaster_class("Disaster Q", local));
          test_contract.add_disaster(Normal_disaster_class("Disaster W"));
          test_cust.add_contract(test_contract);

          for (int i = 0; i < MAX_CUSTOMERS; i++)
            corp.add_element(test_cust);
          
          std::fstream file_stream;
          file_stream.open("Corp_data.txt", std::ios::in | std::ios::out | std::ios::trunc);
          for (int i = 0; i < MAX_CUSTOMERS; i++)
            file_stream << corp[i].get_name() << '\n';

          std::cout << "Stored the corp's customers!\nShowing them now...\n";

          std::string in_buff;
          file_stream.seekg(std::ios::beg);
          for (int i = 0; i < MAX_CUSTOMERS; i++) {
            getline(file_stream, in_buff);
            std::cout << "Name: " << in_buff << '\n';
          }

          getchar();
          break;
      }
      case 16:
        std::string buf = "", target_strs[] = {"Y", "N", "X"};
        if (utils::Cpp_utils::read_string_cmp(buf, "Delete corp data file? (Y/n) -> ", target_strs) == "Y")
          std::system("rm Corp_data.txt");
        return 0;
    }
  }
}