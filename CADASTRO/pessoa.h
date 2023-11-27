#ifndef PESSOA_H_
#define PESSOA_H_
#include <string>


class Pessoa{
 
 protected:
  
  std::string _nomepessoa;
  std::string _local;
  std::string _cpf;

 
 public:

    Pessoa (std::string nomepessoa, std::string local);

    std::string get_nomepessoa ();

    std::string get_local ();

    std::string get_cpf ();

    void set_nomepessoa (std::string nomepessoa);

    void set_local (std::string local);

    void insere_cpf ( );

    void edicao_cadastro_fis (Pessoa &fisico);

    bool confirma_cadastro_fis (Pessoa &fisico);


};

#endif