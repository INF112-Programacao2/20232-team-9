#ifndef PESSOA_H_
#define PESSOA_H_
#include <string>


class Pessoa{
 
 protected:
  
  std::string _nomepessoa;
  std::string _local;
  std::string _cpf;
  std::string _tipo_pessoa;

 
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

    void tipo_pessoa ();

    std::string get_tipo_pessoa ();

    void set_cpf (std::string cpf);

    void set_tipo_pessoa (std::string tipo_pessoa);

};

#endif

//contribuinte ou empregado 