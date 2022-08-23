#include "map.hh"
int main(int argc, char const *argv[])
{
    std::string id = "id"; 
    const int action = std::stoi(argv[1]);
    if(argc > 2) id = std::string(argv[2]);
    switch (action)
    {
    case 1:
        {
            std::vector<double> l_vect = {0.1, 0.0, 0.6};
            test_struct save_struct = {true, 5.0, l_vect}; 
            map test_save(id); 
            test_save.show_file(); 
            test_save.set_double(8.0); 
            test_save.set_str("save this string"); 
            test_save.set_struct(save_struct); 
            test_save.show_file(); 
            test_save.save_file(); 
            map test_load(id);
            test_load.load_file();
            test_load.show_file(); 
        }
        break;
    case 2:
        {
            map test_load(id);
            test_load.load_file();
            test_load.show_file(); 
        }
        break;
    
    default:
        break;
    }
    return 0;
}
