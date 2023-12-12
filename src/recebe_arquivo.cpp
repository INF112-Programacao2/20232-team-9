#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include "recebe_arquivo.h"
#include "pessoa.h"
#include "pessoajuridica.h"
#include "contabilidade_fisica.h"
#include "contabilidade_juridica.h"
#include "juridica_comercial.h"
#include "juridica_industrial.h"
#include "juridica_prestservico.h"

void RecebeArquivo::recebe_dados_fisico(ContabilFisica &dados, Pessoa &fisico)
{
    std::fstream out("data/Usuarios_Fisico.csv", std::ios::out | std::ios::app);
    out << fisico.get_cpf() << "," << fisico.get_nomepessoa() << ","<< dados.get_ano_contabil() <<std::endl;
    out << "Salario"
        << "," << dados.get_salario_bruto() << std::endl;
    out << "INSS"
        << "," << dados.get_inss() << std::endl;
    out << "Dependente"
        << "," << dados.get_deducao_dependente() << std::endl;
    out << "Base"
        << "," << dados.get_base_calculo() << std::endl;
    out << "Aliquota"
        << "," << dados.get_aliquota() << std::endl;
    out << "Imposto de Renda"
        << "," << dados.get_imposto_dados() << std::endl;
    out.close();
}

void RecebeArquivo::recebe_dados_industrial(JuridicaIndustrial &dados, PessoaJuridica &juridico)
{
    std::vector<std::pair<std::string, double>> aux;
    aux = dados.get_contasPagar_dados();
    std::fstream out("data/Usuarios_Juridico_Industrial.csv", std::ios::out | std::ios::app);
    out << juridico.get_cnpj() << "," << juridico.get_nomepessoa() << "," << dados.get_mes_contabil() << "," << dados.get_ano_contabil() <<std::endl;

    out <<"Caixa" << "," <<dados.get_caixa() << std::endl;

    out << "Receita" << "," << dados.get_receita_bruta() << std::endl;

    out << "Lucro" << "," << dados.get_lucro() << std::endl;

    out << "Despesa" << "," << dados.get_despesa() << std::endl;

    out << "Contas a pagar:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados();

    out << "Contas a receber:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelCurtoPrazo_dados();

    out << "Realizavel a curto prazo:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados();

    out << "Realizavel a longo prazo:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados();
    out << "Emprestimos:" << ",";

    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }

    out << std::endl;

    aux = dados.get_estoque_dados();
    out << "Estoque:" << ",";

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << ":," << aux[i].second << ";,";
    }

    
    out<<std::endl;
    out.close();
}

void RecebeArquivo::recebe_dados_comercial(JuridicaComercial &dados, PessoaJuridica &juridico)
{
    std::vector<std::pair<std::string, double>> aux;
    aux = dados.get_contasPagar_dados();
    std::fstream out("data/Usuarios_Juridico_Comercial.csv", std::ios::out | std::ios::app);
    out << juridico.get_cnpj() << "," << juridico.get_nomepessoa() << "," <<dados.get_mes_contabil()<< "," << dados.get_ano_contabil() <<std::endl;
    
    out <<"Caixa" << "," <<dados.get_caixa() << std::endl;

    out << "Receita" << "," << dados.get_receita_bruta() << std::endl;

    out << "Lucro" << "," << dados.get_lucro() << std::endl;

    out << "Despesa" << "," << dados.get_despesa() << std::endl;

    out << "Contas a pagar:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        std::cout << "Fonte: " << aux[i].first << " Valor: " << aux[i].second << std::endl;
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados();

    out << "Contas a receber:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelCurtoPrazo_dados();

    out << "Realizavel a curto prazo:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados();

    out << "Realizavel a longo prazo:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados();

    out << "Emprestimos:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out<<std::endl;

    out.close();
}

void RecebeArquivo::recebe_dados_prestservico(JuridicaPrestServi &dados, PessoaJuridica &juridico)
{
    std::vector<std::pair<std::string, double>> aux;
    aux = dados.get_contasPagar_dados();
    std::fstream out("data/Usuarios_Juridico_Prestacao_de_Servico.csv", std::ios::out | std::ios::app);
    out << juridico.get_cnpj() << "," << juridico.get_nomepessoa() << "," << dados.get_mes_contabil()<< "," << dados.get_ano_contabil() <<std::endl;
    out <<"Caixa" << "," <<dados.get_caixa() << std::endl;

    out << "Receita" << "," << dados.get_receita_bruta() << std::endl;

    out << "Lucro" << "," << dados.get_lucro() << std::endl;

    out << "Despesa" << "," << dados.get_despesa() << std::endl;

    out << "Contas a pagar:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados();

    out << "Contas a receber:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelCurtoPrazo_dados();

    out << "Realizavel a curto prazo:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados();

    out << "Realizavel a longo prazo:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados();

    out << "Emprestimos:" << ",";
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out<<std::endl;

    out.close();
}

double RecebeArquivo::retorna_receita_bruta(std::string cpf_informado){
    std::fstream in("data/Pessoa_Juridica.csv", std::ios::in);
    std::string cpf, nome;
    double receita_bruta = 0.0;
    if (!in.is_open()){
        std::cerr << "erro ao abrir arquivo!" << std::endl;
    }
    while (in.peek() != EOF)
  {

      getline(in, cpf, ',');
      if (cpf == cpf_informado)
      {
          std::string nome, local, tipo, cnpj, nome_empresa, apelido_empresa, modelo_negocio;

          getline(in, nome, ',');
          getline(in, local, ',');
          getline(in, tipo, ',');
          getline(in, cnpj, ',');
          getline(in, nome_empresa, ',');
          getline(in, apelido_empresa, ',');
          getline(in, modelo_negocio, '\n');

          PessoaJuridica pessoa(nome, nome_empresa, apelido_empresa, local);

          pessoa.set_cpf(cpf);
          pessoa.set_tipo_pessoa(tipo);
          pessoa.set_cnpj(cnpj);
          pessoa.set_modelo_negocio(modelo_negocio);

          RecebeArquivo r;

          if (pessoa.get_modelo_negocio() == "Industrial")
          {
              JuridicaIndustrial industria;
              std::fstream ent("data/Usuarios_Juridico_Industrial.csv", std::ios::in | std::ios::app);
              std::string cpf2, aux;
              while (ent.peek() != EOF)
              {
                  getline(ent, cpf2, ',');
                  if (cpf_informado == cpf2)
                  {
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, ',');
                      getline(ent, aux, '\n');
                      receita_bruta += atof(aux.c_str());
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                  }
                  else
                  {
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                  }
              }
          }
          else if (pessoa.get_modelo_negocio() == "Comercial")
          {
              JuridicaComercial comercio;
              std::fstream ent("data/Usuarios_Juridico_Comercial.csv", std::ios::in | std::ios::app);
              std::string cpf2, aux;
              while (ent.peek() != EOF)
              {
                  getline(ent, cpf2, ',');
                  if (cpf_informado == cpf2)
                  {
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, ',');
                      getline(ent, aux, '\n');
                      receita_bruta += atof(aux.c_str());
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                  }
                  else
                  {
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                  }
              }
          }
          else if (pessoa.get_modelo_negocio() == "Prestação de Serviço")
          {

              JuridicaPrestServi prestservi;

              std::fstream ent("data/Usuarios_Juridico_Prestacao_de_Servico.csv", std::ios::in | std::ios::app);
              std::string cpf2, aux;
              while (ent.peek() != EOF)
              {
                  getline(ent, cpf2, ',');
                  if (cpf_informado == cpf2)
                  {
                      getline(ent, aux, '\n');
                      getline(ent, aux, '\n');
                      getline(ent, aux, ',');
                      getline(ent, aux, '\n');
                      receita_bruta += atof(aux.c_str());
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                  }
                  else
                  {
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                      getline(ent, cpf2, '\n');
                  }
              }
          }

    }
    else{
        getline(in, cpf, '\n');
    }
  }
  return receita_bruta;
}