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
    //abertura de arquivo
    std::fstream out("data/Usuarios_Fisico.csv", std::ios::out | std::ios::app);

    //formatacao do arquivo csv, cada linha representa um bloco, cada endl representa uma criacao de nova linha
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
    //abertura do arquivo e de variaveis auxiliares
    std::vector<std::pair<std::string, double>> aux;
    aux = dados.get_contasPagar_dados(); //recebe vetor
    std::fstream out("data/Usuarios_Juridico_Industrial.csv", std::ios::out | std::ios::app);

    //formatacao do arquivo csv, cada linha representa um bloco, cada endl representa uma criacao de nova linha
    out << juridico.get_cnpj() << "," << juridico.get_nomepessoa() << "," << dados.get_mes_contabil() << "," << dados.get_ano_contabil() <<std::endl;

    out <<"Caixa" << "," <<dados.get_caixa() << std::endl;

    out << "Receita" << "," << dados.get_receita_bruta() << std::endl;

    out << "Lucro" << "," << dados.get_lucro() << std::endl;

    out << "Despesa" << "," << dados.get_despesa() << std::endl;

    out << "Contas a pagar:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados(); //recebe novo vetor


    out << "Contas a receber:" << ",";

    //laco de repeticao para printar o vetor  
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelCurtoPrazo_dados(); //recebe novo vetor

    out << "Realizavel a curto prazo:" << ",";
    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados(); //recebe novo vetor

    out << "Realizavel a longo prazo:" << ",";
    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados(); //recebe novo vetor
    out << "Emprestimos:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }

    out << std::endl;

    aux = dados.get_estoque_dados(); //recebe novo vetor
    out << "Estoque:" << ",";

    //laco de repeticao para printar o vetor
    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << ":," << aux[i].second << ";,";
    }

    
    out<<std::endl;
    out.close();
}

void RecebeArquivo::recebe_dados_comercial(JuridicaComercial &dados, PessoaJuridica &juridico)
{
    //abertura do arquivo e de variaveis auxiliares
    std::vector<std::pair<std::string, double>> aux;
    aux = dados.get_contasPagar_dados(); //recebe vetor
    std::fstream out("data/Usuarios_Juridico_Comercial.csv", std::ios::out | std::ios::app);

    //formatacao do arquivo csv, cada linha representa um bloco, cada endl representa uma criacao de nova linha
    out << juridico.get_cnpj() << "," << juridico.get_nomepessoa() << "," <<dados.get_mes_contabil()<< "," << dados.get_ano_contabil() <<std::endl;
    
    out <<"Caixa" << "," <<dados.get_caixa() << std::endl;

    out << "Receita" << "," << dados.get_receita_bruta() << std::endl;

    out << "Lucro" << "," << dados.get_lucro() << std::endl;

    out << "Despesa" << "," << dados.get_despesa() << std::endl;

    out << "Contas a pagar:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        std::cout << "Fonte: " << aux[i].first << " Valor: " << aux[i].second << std::endl;
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados(); //recebe novo vetor

    out << "Contas a receber:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelCurtoPrazo_dados(); //recebe novo vetor

    out << "Realizavel a curto prazo:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados(); //recebe novo vetor

    out << "Realizavel a longo prazo:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados(); //recebe novo vetor

    out << "Emprestimos:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out<<std::endl;

    out.close();
}

void RecebeArquivo::recebe_dados_prestservico(JuridicaPrestServi &dados, PessoaJuridica &juridico)
{
    //abertura do arquivo e de variaveis auxiliares
    std::vector<std::pair<std::string, double>> aux;
    aux = dados.get_contasPagar_dados();
    std::fstream out("data/Usuarios_Juridico_Prestacao_de_Servico.csv", std::ios::out | std::ios::app);

    //formatacao do arquivo csv, cada linha representa um bloco, cada endl representa uma criacao de nova linha
    out << juridico.get_cnpj() << "," << juridico.get_nomepessoa() << "," << dados.get_mes_contabil()<< "," << dados.get_ano_contabil() <<std::endl;
    out <<"Caixa" << "," <<dados.get_caixa() << std::endl;

    out << "Receita" << "," << dados.get_receita_bruta() << std::endl;

    out << "Lucro" << "," << dados.get_lucro() << std::endl;

    out << "Despesa" << "," << dados.get_despesa() << std::endl;

    out << "Contas a pagar:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados(); //recebe novo vetor

    out << "Contas a receber:" << ",";
    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelCurtoPrazo_dados(); //recebe novo vetor

    out << "Realizavel a curto prazo:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados(); //recebe novo vetor

    out << "Realizavel a longo prazo:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados(); //recebe novo vetor

    out << "Emprestimos:" << ",";

    //laco de repeticao para printar o vetor
    for (int i = 0; i < aux.size(); i++)
    {
        out << aux[i].first << ":," << aux[i].second << ";,";
    }
    out<<std::endl;

    out.close();
}

double RecebeArquivo::retorna_receita_bruta(std::string cpf_informado){
    //abre arquivo e variaveis auxiliares
    std::fstream in("data/Pessoa_Juridica.csv", std::ios::in);
    std::string cpf, nome;
    double receita_bruta = 0.0;

    //verifica abertura de arquivo
    if (!in.is_open()){
        std::cerr << "erro ao abrir arquivo!" << std::endl;
    }

    //laco para varredura completa do arquivo
    while (in.peek() != EOF)
  {
      //le ate ',' no arquivo
      getline(in, cpf, ',');

      //confere se o cpf e igual ao informado
      if (cpf == cpf_informado)
      {
          //declara variaveis que sao usadas pelo objeto
          std::string nome, local, tipo, cnpj, nome_empresa, apelido_empresa, modelo_negocio;
          
          //atribui todas ao que esta na linha do arquivo
          getline(in, nome, ',');
          getline(in, local, ',');
          getline(in, tipo, ',');
          getline(in, cnpj, ',');
          getline(in, nome_empresa, ',');
          getline(in, apelido_empresa, ',');
          getline(in, modelo_negocio, '\n');
          
          //instancia um objeto auxiliar de pessoa e da set em atributos
          PessoaJuridica pessoa(nome, nome_empresa, apelido_empresa, local);

          pessoa.set_cpf(cpf);
          pessoa.set_tipo_pessoa(tipo);
          pessoa.set_cnpj(cnpj);
          pessoa.set_modelo_negocio(modelo_negocio);

          //cria um objeto do tipo recebearquivo
          RecebeArquivo r;

          //condicionais para os tipos de modelo de negocio
          if (pessoa.get_modelo_negocio() == "Industrial")
          {
              //cria objeto e abre arquivo
              JuridicaIndustrial industria;
              std::fstream ent("data/Usuarios_Juridico_Industrial.csv", std::ios::in | std::ios::app);
              std::string cpf2, aux;

              //le arquivo ate o fim
              while (ent.peek() != EOF)
              {
                  //le cpf
                  getline(ent, cpf2, ',');

                  //condicional de igualdade do cpf informado e do lido
                  if (cpf_informado == cpf2)
                  {
                      //pula linhas e faz leitura do valor procurado
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

                  //pula as linhas exatas para proxima verificacao
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
              //cria objeto e abre arquivo
              JuridicaComercial comercio;
              std::fstream ent("data/Usuarios_Juridico_Comercial.csv", std::ios::in | std::ios::app);
              std::string cpf2, aux;

              //le arquivo ate o fim
              while (ent.peek() != EOF)
              {
                  //le cpf
                  getline(ent, cpf2, ',');

                  //condicional de igualdade do cpf informado e do lido
                  if (cpf_informado == cpf2)
                  {
                      //pula linhas e faz leitura do valor procurado
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

                  //pula as linhas exatas para proxima verificacao
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
              //cria objeto e abre arquivo
              JuridicaPrestServi prestservi;

              //le arquivo ate o fim
              std::fstream ent("data/Usuarios_Juridico_Prestacao_de_Servico.csv", std::ios::in | std::ios::app);
              std::string cpf2, aux;

              //le arquivo ate o fim
              while (ent.peek() != EOF)
              {
                  //le cpf
                  getline(ent, cpf2, ',');
                  if (cpf_informado == cpf2)
                  {
                      //pula linhas e faz leitura do valor procurado
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

                  //pula as linhas exatas para proxima verificacao
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
    //pula para o proximo cpf
    else{
        getline(in, cpf, '\n');
    }
  }

  //da return do valor lido e somado
  return receita_bruta;
}