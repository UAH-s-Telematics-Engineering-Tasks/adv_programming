#include "../inc/Library_includes.h"
#include "../inc/P_5_Hour_class.h"
#include "../inc/P_5_Index_class.h"
#include "../inc/Utils.h"

const char* menu[] = {
  "1. Create an index card",
  "2. View the index card",
  "3. Quit"
};

std::string target_strs[] = {
  "AM",
  "PM",
  "24 HOURS",
  "X"
};

int main(int argc, char const* argv[]) {
  if (!strcmp(argv[argc - 1], "0")) {
    /* Important note: Due to how read_string() is implemented we cannot use it twice in the same function call! If we do so, the first call will write something in the string. The second call will overwrite it, as we would expect. The thing is that the function returns a reference to the string where the contents have been read! As we are reading into the same string that reference is the same... Thus, even though we have written to the string twice we are passing a reference to an string whose content is what we set it to in the last call... That's why we were getting the same string in the name and time format fields... The function will only be called oonce all the needed parameters have been set! */

    Index_info::Index_class* dynamic_info = NULL;
    std::string recipient_str_a, recipient_str_b;

    while(true) {
      switch(utils::General_utils::show_menu(menu, sizeof(menu) / sizeof(char*))) {
        case 1:
          if (!dynamic_info)
            dynamic_info = new (std::nothrow) Index_info::Index_class(utils::Cpp_utils::read_string(recipient_str_a, "Name: "), utils::General_utils::read_int("Age: "), utils::General_utils::read_int("Hours: "), utils::General_utils::read_int("Minutes: "), utils::General_utils::read_int("Seconds: "), utils::Cpp_utils::read_string_cmp(recipient_str_b, "Time format: ", target_strs));
          break;

        case 2:
          Index_info::view_index(*dynamic_info);
          break;

        case 3:
          if (dynamic_info)
            delete dynamic_info;
          return 0;
      }
    }
  }
  else if (!strcmp(argv[argc - 1], "1")) {
    /* When calling this "version" of the prgram we'll see a fair ammount of method's being called despite not having lots of lines... The first constructor to be called will be Hour_class() despite what we could think. If we take a look at said constructor's definition we can see why this is happening! Remember that we initialized the index_card object with a list and that we were calling the construtor for the index_birth_time attribute within said list... After that one returns we can get in the body of the constructor belonging to index_card and we will indeed see that this constructor has been called. Taking this into account we can see that the first constructor to be called is Index_class() and this one will call Hour_class(). The order of the messages is different due to what we said before so we have to be extra carful!

    After solving this issue we will see that Hour_class() is called once more when creating the time object.

    The next method in line will be get_birth_time(). It's return statement will create a copy of the index_birth_time member and to do that it'll call Hour_class' copy constructor. We should note that the copy construtor belongs to the nameless object to be rreturned, not the index_birth_time attribute! This copy will be returned to main() and we only have one more step to go!

    Finally, the nameless object returned by get_birth_time() will be assigned to time. To that end we will call the assignment operator we had overloaded. We should point out we are calling time's assignment operator! Once it finishes its task we will exit the program.

    We should end by noting that we have this many calls due to the fact that get_birth_time() returns an Hour_class object. We'll see how things change when returning a reference to an object of that class! */

    Index_info::Index_class index_card;
    Hour::Hour_class time;
    time = index_card.get_birth_time();
    return 0;
  }
  else if (!strcmp(argv[argc - 1], "2")) {
    /* We will see that the first three methods called are exactly the same: Index_class() once and Hour_class() twice in that order.

    The next method being called is get_birth_time() once more, but the ubtle difference is we are not returning an object but a reference this time! This translates into one less method call: we won't call Hour_class' copy constructor! We are just returning a reference now so after calling get_birth_time() we will be back at main() in no time.

    We'll finally call time's assignment operator and that concludes the calls.

    We then find that time and the index_birth_time attribute are totally different things despite what we may have thought! This is due to how the assignment operator is implemented. It takes a reference as an input and gets the reference's values. Remember that time is an object in itself, not a reference!

    We decided to play a little more and declared time as a reference (Hour::Hour_class&). In doing so we found that time was a synonym of the index_birth_time attribute so that if you changed one you were modifying the other too; they were connected! This is possible too when get_birth_time() returns a reference to the index_birth_time attribute. It wouldn't be allowed in the example above!

    We would finally like to show why we needed to discard the const qualifier in the function definition for this case. In order to maintain a fucntion returning a Hour_class object reference instead of a constant one we need to drop the const qualifer. We are otherwise returing a non-constant reference when the object the reference belongs to is constant... In other words, we are trying to return a constant reference as non-constant. That's an error in the compiler's eyes... */

    Index_info::Index_class index_card;
    Hour::Hour_class time;
    time = index_card.get_birth_time();
    return 0;
  }
  std::cout << "Error...\n";
}
