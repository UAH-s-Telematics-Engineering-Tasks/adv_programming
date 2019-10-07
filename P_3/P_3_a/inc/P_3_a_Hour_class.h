
#if !defined(_HOUR_CLASS_)
#define _HOUR_CLASS_

class Hour_class {
  private:
    int hours, minutes, seconds;
    char* time_format;

    bool set_time_format(char* format_string);
    bool time_format_24_H(void) const;

  protected:
    bool is_time_correct(void) const;

  public:
    Hour_class();
    bool set_time (int h, int min, int sec, char* format);
    void get_time(int& h, int& min, int& sec, char* format) const;
    void deallocate_format(void);
    ~Hour_class();
};

#endif
