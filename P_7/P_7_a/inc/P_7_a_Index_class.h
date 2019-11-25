#include "Library_includes.h"
#include "P_7_a_Hour_class.h"

#if !defined(_INDEX_CLASS_)
#define _INDEX_CLASS_

class Index_class {
    private:
      std::string index_name;
      int index_age;
      Hour_class index_birth_time;

    public:
      Index_class(const std::string& = "", int = 0, int = 12, int = 0, int = 0, const std::string& = "AM");
      inline void set_name(const std::string& name) {this->index_name = name;}
      inline std::string get_name(void) const {return this->index_name;}
      inline void set_age(int& age) {this->index_age = age;}
      inline int get_age(void) const {return this->index_age;}
      inline bool set_birth_time(int h, int m, int s, std::string& f) {return this->index_birth_time.set_time(h, m, s, f);}
      inline Hour_class get_birth_time(void) const {return this->index_birth_time;}
      void view_index(void);
      /* Assigning 0 to very virtual methos turns this class into an abstract one! */
      virtual void show(void) = 0;
      virtual Index_class* clone(void) = 0;

      virtual ~Index_class() {};
  };
#endif
