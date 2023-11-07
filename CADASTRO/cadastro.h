#include <string>

class Cadastro{
 
 private:
  
  std::string _nomepessoa;
  std::string _nomeempresa;
  std::string _apelidoempresa;
  std::string _local;
  std::string _cpf;
  std::string _cnpj;

 
 
 public:

    Cadastro (std::string nomepessoa, std::string nomeempresa, std::string apelidoempresa, std::string local);

    Cadastro (std::string nomepessoa, std::string local);

    std::string get_nomepessoa ();

    std::string get_nomeempresa ();

    std::string get_apelidoempresa ();

    std::string get_local ();

    std::string get_cpf ();

    std::string get_cnpj ();

    void set_nomepessoa (std::string nomepessoa);

    void set_nomeempresa (std::string nomeempresa);

    void set_apelidoempresa (std::string apelidoempresa);

    void set_local (std::string local);

    void confere_cpf (std::string cpf);

    void confere_cnpj (std::string cnpj);


};