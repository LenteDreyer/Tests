#include "map.hh"
map::map(const std::string& a_id)
{
    m_path = "./map/" + a_id + ".bin";
    m_str = "none"; 
    m_double = 0.0; 
    m_struct = {false, 0.0};  
}
void map::set_str(std::string a_str){
    m_str = a_str; 
}
void map::set_double(double a_double){
    m_double = a_double; 
} 
void map::set_struct(test_struct a_struct){
    m_struct = a_struct; 
}
void map::load_file(){
    std::ifstream l_inF;
    l_inF.open(m_path.c_str(), std::ios::binary | std::ios::in);
    l_inF.read((char*)&m_double,sizeof(double));
    l_inF.read((char*)&m_struct,sizeof(test_struct_t));
    size_t str_size; 
    l_inF.read((char*)&str_size, sizeof(str_size));
    m_str.resize(str_size); 
    l_inF.read((char*)&m_str[0], str_size);
    l_inF.close(); 
}
void map::save_file() const{
    std::ofstream l_outF;
    l_outF.open(m_path.c_str(), std::ios::binary | std::ios::out);
    l_outF.write((char*)&m_double,sizeof(double));
    l_outF.write((char*)&m_struct,sizeof(test_struct_t));
    size_t str_size = m_str.size(); 
    l_outF.write((char*)&str_size, sizeof(str_size));
    l_outF.write((char*)&m_str[0], str_size);
    l_outF.close(); 
}
void map::show_file() const{
    std::cout << ">>-----------------------------------------------" << std::endl; 
    std::cout << ">> double        : " << m_double << std::endl; 
    std::cout << ">> double        : " << m_double << std::endl; 
    std::cout << ">> struct.bool   : " << m_struct.test_bool << std::endl;
    std::cout << ">> struct.double : " << m_struct.test_double << std::endl;
    std::cout << ">> struct.vector : " << "size = " << m_struct.test_vector.size() <<  std::endl; 
    std::cout << ">> string        : " << m_str <<  std::endl; 
    std::cout << ">>-----------------------------------------------" << std::endl; 

}   

map::~map(){}