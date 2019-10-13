
#if !defined(_HOUR_CLASS_)
#define _HOUR_CLASS_

class Hour_class {
  private:
    int hours, minutes, seconds;
    char* time_format;

    bool set_time_format(const char* format_string);
    bool time_format_24_H(void) const;

  public:
    Hour_class(int h = 0, int m = 0, int s = 0, const char* tf = "24 HOURS");
    Hour_class(const Hour_class&);
    Hour_class& operator = (const Hour_class&);
    bool is_time_correct(void) const;
    bool set_time (int h, int min, int sec, char* format);
    void get_time(int& h, int& min, int& sec, char* format) const;
    void deallocate_format(void);
    ~Hour_class();
};

#endif
