#ifndef PESSOAJURIDICA_H_
#define PESSOAJURIDICA_H_
#include "pessoa.h"
#include <string>

class PessoaJuridica : public Pessoa{
 
 private:
  
  std::string _nomeempresa;
  std::string _apelidoempresa;
  std::string _cnpj; 
  std::string _modeloempresa;
 
 public:

    PessoaJuridica (std::string nomepessoa, std::string nomeempresa, std::string apelidoempresa, std::string local);

    std::string get_nomeempresa ();

    std::string get_apelidoempresa ();

    std::string get_cnpj ();

    void set_nomeempresa (std::string nomeempresa);

    void set_apelidoempresa (std::string apelidoempresa);

    void set_cnpj(std::string cnpj);

    void set_modelo_negocio(std::string modelo_negocio);

    void insere_cnpj ( );

    void edicao_cadastro (PessoaJuridica &juridico); 

    bool confirma_cadastro (PessoaJuridica &juridico);

    void modelo_negocio ();

    std::string get_modelo_negocio ();

};

#endif