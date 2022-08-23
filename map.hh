#ifndef __TESTS_MAP_HH__
#define __TESTS_MAP_HH__
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <algorithm>
#include <sstream> 
typedef struct test_struct{
    bool test_bool; 
    double test_double; 
    std::vector<double> test_vector; 
} test_struct_t; 
class map
{
private:
    std::string m_path, m_str; 
    double m_double; 
    test_struct m_struct; 
public:
    map(const std::string& a_id);
    void set_str(std::string a_str); 
    void set_double(double a_double); 
    void set_struct(test_struct a_struct);
    void load_file(); 
    void save_file() const;
    void show_file() const;   
    ~map();
};
#endif //__TESTS_MAP_HH__
