class C_matx_float {
  private:
    float** mtx;
    int n_rows, n_cols;

  public:
    void initialize(void);
    void create_2d_mtx(int, int);
    void create_1d_mtx(int);
    void populate(void);
    void show_mtx(void);
    void deallocate(void);
    bool exists(void);
};
