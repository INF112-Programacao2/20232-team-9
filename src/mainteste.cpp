#include <bits/stdc++.h>
#include "pessoa.h"
#include "pessoajuridica.h"
#include "contabilidade_fisica.h"
#include "contabilidade_juridica.h"
#include "juridica_comercial.h"
#include "juridica_industrial.h"
#include "juridica_prestservico.h"
#include "recebe_arquivo.h"
#include "estatisticosfisico.h"
#include "estatisticosjuridico.h"

void contabil_fisica(std::string cpf_informado)
{
  std::fstream in("data/Pessoa_Fisica.csv", std::ios::in);
  std::string cpf, nome;
  if (!in.is_open())
  {
    std::cerr << "erro ao abrir arquivo!" << std::endl;
  }
  while (in.peek() != EOF && cpf_informado != cpf)
  {

    getline(in, cpf, ',');

    if (cpf == cpf_informado)
    {
      std::string nome, local, tipo;
      ContabilFisica conta;

      getline(in, nome, ',');
      getline(in, local, ',');
      Pessoa pessoa(nome, local);

      getline(in, tipo, '\n');
      pessoa.set_cpf(cpf);
      pessoa.set_tipo_pessoa(tipo);
      
      conta.set_ano_contabil();
      conta._calcula_inss(pessoa);
      conta._calcula_deducao_dependente();
      conta._base_calculos();
      conta._calcula_imposto_renda();
      RecebeArquivo r;
      r.recebe_dados_fisico(conta, pessoa);
      in.close();
      std::cout<<conta.get_Imposto_Renda_Final()<<std::endl;
      return;

    }

    else
    {
      getline(in, cpf, '\n');
    }
  }
  std::cout<<"O CPF informado não está cadastrado no sistema!! \n";
  in.close();
  return;
}

void contabil_juridica(std::string cnpj_informado){
  int _tipo_contabilidade;
  std::fstream in("data/Pessoa_Juridica.csv", std::ios::in);
  std::string cnpj, cpf, nome, local, tipo;

  if (!in.is_open())
  {
    std::cerr << "erro ao abrir arquivo!" << std::endl;
  }
  while (in.peek() != EOF && cnpj_informado != cnpj)
  {

    getline(in, cpf, ',');
    getline(in, nome, ',');
    getline(in, local, ',');
    getline(in, tipo, ',');
    getline(in, cnpj, ',');

    if (cnpj == cnpj_informado)
    {
      
      while (true)
      {
        std::cout << "Qual Tipo de Contabilidade deseja fazer:" << std::endl;
        std::cout << "(1) - Balanço Mensal" << std::endl;
        std::cout << "(2) - Contabilidade Simples Nacional" << std::endl;
        try
        { // tratamento de exceções para entrada de dados
          std::cin >> _tipo_contabilidade;
          if (std::cin.fail())
          {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Devem ser digitados apenas números!");
          }
          else if (_tipo_contabilidade < 1 || _tipo_contabilidade > 2)
          {
            throw std::invalid_argument("Opção inválida! Digite novamente:");
          }

          break;
        }
        catch (std::invalid_argument &e)
        {
          std::cerr << e.what() << std::endl;
        }
      }

      std::string nome_empresa, apelido_empresa, modelo_negocio;

      getline(in, nome_empresa, ',');
      getline(in, apelido_empresa, ',');
      getline(in, modelo_negocio, '\n');
      //Para evitar que modelo de negócio "pegue" caracteres indesejados no csv que atrapalhem a comparação no momento da conferência do modelo de negócio no switch case:
      modelo_negocio.erase(std::remove_if(modelo_negocio.begin(), modelo_negocio.end(), ::isspace), modelo_negocio.end()); 

      PessoaJuridica pessoa(nome, nome_empresa, apelido_empresa, local);

      pessoa.set_cpf(cpf);
      pessoa.set_tipo_pessoa(tipo);
      pessoa.set_cnpj(cnpj);
      pessoa.set_modelo_negocio(modelo_negocio);

      RecebeArquivo r;  

      switch (_tipo_contabilidade)
      {
      case (1):
        if (pessoa.get_modelo_negocio() == "Industrial")
        {
          JuridicaIndustrial industria;
          industria.set_mes_contabil();
          industria.set_ano_contabil();
          industria.set_caixa();
          std::cout << industria.get_caixa() << std::endl;
          industria.set_contasPagar();
          std::cout << industria.get_contasPagar() << std::endl;
          industria.set_contasReceber();
          std::cout << industria.get_contasReceber() << std::endl;
          industria.set_emprestimos();
          std::cout << industria.get_emprestimos() << std::endl;
          industria.set_estoque();
          std:: cout << industria.get_estoque() << std::endl;
          industria.set_realizavelCurtoPrazo();
          std::cout << industria.get_realizavelCurtoPrazo() << std::endl;
          industria.set_realizavelLongoPrazo();
          std::cout << industria.get_realizavelLongoPrazo() << std::endl;
          industria._calculo_DRE();
          industria._calculo_fluxo_caixa();
          r.recebe_dados_industrial(industria, pessoa);
          industria._limpa_vectors ();
          in.close();
          return;
        }
        else if (pessoa.get_modelo_negocio() == "Comercial")
        {
          JuridicaComercial comercio;
          comercio.set_mes_contabil();
          comercio.set_ano_contabil();
          comercio.set_caixa();
          std::cout << comercio.get_caixa() << std::endl;
          comercio.set_contasPagar();
          std::cout << comercio.get_contasPagar() << std::endl;
          comercio.set_contasReceber();
          std::cout << comercio.get_contasReceber() << std::endl;
          comercio.set_emprestimos();
          std::cout << comercio.get_emprestimos() << std::endl;
          comercio.set_realizavelCurtoPrazo();
          std::cout << comercio.get_realizavelCurtoPrazo() << std::endl;
          comercio.set_realizavelLongoPrazo();
          std::cout << comercio.get_realizavelLongoPrazo() << std::endl;
          comercio._calculo_DRE();
          comercio._calculo_fluxo_caixa();
          r.recebe_dados_comercial(comercio, pessoa);
          comercio._limpa_vectors ();
          in.close();
          return;
        }
        else if (pessoa.get_modelo_negocio() == "PrestaçãodeServiço")
        {
          JuridicaPrestServi prestservi;
          prestservi.set_mes_contabil();
          prestservi.set_ano_contabil();
          prestservi.set_caixa();
          std::cout << prestservi.get_caixa() << std::endl;
          prestservi.set_contasPagar();
          std::cout << prestservi.get_contasPagar() << std::endl;
          prestservi.set_contasReceber();
          std::cout << prestservi.get_contasReceber() << std::endl;
          prestservi.set_emprestimos();
          std::cout << prestservi.get_emprestimos() << std::endl;
          prestservi.set_realizavelCurtoPrazo();
          std::cout << prestservi.get_realizavelCurtoPrazo() << std::endl;
          prestservi.set_realizavelLongoPrazo();
          std::cout << prestservi.get_realizavelLongoPrazo() << std::endl;
          prestservi._calculo_DRE();
          prestservi._calculo_fluxo_caixa();
          r.recebe_dados_prestservico(prestservi, pessoa);
          prestservi._limpa_vectors ();
          in.close();
          return;
        }

        break;
      case (2):
        if (pessoa.get_modelo_negocio() == "Industrial")
        {
          JuridicaIndustrial industria;
          industria._calculo_aliquotas_anexos(cpf);
          std:: cout << industria.get_result_simples_nacional() << std::endl;
          in.close();
          return;
        }
        else if (pessoa.get_modelo_negocio() == "Comercial")
        {
          JuridicaComercial comercio;
          comercio._calculo_aliquotas_anexos(cpf);
          std::cout << comercio.get_result_simples_nacional() << std::endl;
          in.close();
          return;
        }
        else if (pessoa.get_modelo_negocio() == "PrestaçãodeServiço")
        {
          JuridicaPrestServi prestservi;
          prestservi._calculo_aliquotas_anexos(cpf);
          std::cout << prestservi.get_result_simples_nacional() << std::endl;
          in.close();
          return;
        }
      default:
        break;
      }

    }

    else
    {
      getline(in, cpf, '\n');
    }
  }
  std::cout<<"O CNPJ informado não está cadastrado no sistema!! \n";
  in.close();
  return;
}

void confere_nomes(std::string &nome)
{

  while (true)
  {
    try
    {
      for (int i = 0; nome[i] != '\0'; i++)
      {
        if ((nome.at(i) == ' ') && i != 0)
        {
          continue;
        }
        else if (!isalpha(nome[i]))
        {
          throw std::invalid_argument("Nome inválido!! O nome deve conter apenas letras! Digite novamente:");
          break;
        }
      }

      break;
    }
    catch (std::invalid_argument &e)
    {
      std::cout << e.what() << std::endl;
      getline(std::cin, nome);
    }
  }
}

int main()
{
  std::string nomepessoa, nomeempresa, apelidoempresa, local, cnpj, cpf, opcao, selecionador, op;
  int selecionador2, option;
  bool valide = true;

  while (valide)
  {

    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>> MENU <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
    std::cout << "Olá cliente! \n";
    std::cout << "O que você deseja fazer? \n";
    std::cout << "(1) - Cadastrar \n";
    std::cout << "(2) - Realizar contabilidade (cliente já deve ser cadastrado) \n";
    std::cout << "(3) - Checar análises estatísticas (cliente já deve ser cadastrado) \n";
    std::cout << "(4) - Fechar programa \n";
    while (true)
    {
      try
      {
        std::cin >> selecionador;
        if (selecionador != "1" && selecionador != "2" && selecionador != "3" && selecionador != "4")
        {
          throw std::invalid_argument("Opção inválida!! Digite uma opção válida:");
        }
        break;
      }
      catch (std::invalid_argument &e)
      {
        std::cerr << e.what() << std::endl;
      }
    }
    selecionador2 = stoi(selecionador);

    switch (selecionador2)
    {
    case (1):
      std::cout << std::endl;
      std::cout << "Qual é o tipo de pessoa? \n";
      std::cout << "1- Pessoa Jurídica. \n";
      std::cout << "2- Pessoa Física. \n";
      std::cout << "Digite 1 para Pessoa Jurídica ou 2 para Pessoa Física: \n";
      while (true)
      {
        try
        {
          std::cin >> opcao;
          if (opcao != "1" && opcao != "2")
          {
            throw std::invalid_argument("Opção inválida!! Digite 1 para Pessoa Jurídica ou 2 para Pessoa Física:");
          }
          break;
        }
        catch (std::invalid_argument &e)
        {
          std::cerr << e.what() << std::endl;
        }
      }

      // PESSOA JURIDICA
      if (opcao == "1")
      {

        std::cout << std::endl;
        std::cout << "Bem-vindo, cliente! \n";
        std::cout << "Iremos iniciar o cadastro. \n";
        std::cout << "Digite o nome completo do proprietário da empresa: \n";
        std::cin.ignore();
        getline(std::cin, nomepessoa);
        confere_nomes(nomepessoa);
        std::cout << "Digite o nome da empresa: \n";
        getline(std::cin, nomeempresa);
        std::cout << "Digite o apelido da empresa: \n";
        getline(std::cin, apelidoempresa);
        std::cout << "Digite o número correpondente ao estado em que a empresa encontra-se localizada: \n";
        std::cout << "(1)- MG \n"
                  << "(2)- SP \n"
                  << "(3)- RJ \n";
        while (true)
        {
          try
          {
            std::cin >> opcao;
            if (opcao != "1" && opcao != "2" && opcao != "3")
            {
              throw std::invalid_argument("Opção inválida!! Digite uma opção válida: ");
            }

            break;
          }
          catch (std::invalid_argument &e)
          {
            std::cerr << e.what() << std::endl;
          }
        }

        if (opcao == "1")
        {
          local = "MG";
        }
        else if (opcao == "2")
        {
          local = "SP";
        }
        else
        {
          local = "RJ";
        }

        PessoaJuridica juridico(nomepessoa, nomeempresa, apelidoempresa, local);
        std::cout << "Digite o CNPJ da empresa: \n";
        juridico.insere_cnpj();
        std::cout << "Digite o CPF do proprietario: \n";
        juridico.insere_cpf();
        std::cout << std::endl;
        if (juridico.confirma_cadastro(juridico) == true)
        {
          std::cout << "Cadastro realizado com sucesso! Obrigado!! \n";
        }
        else
        {
          juridico.edicao_cadastro(juridico);
        }

        std::cout<<std::endl;
        juridico.modelo_negocio();

        std::fstream out("data/Pessoa_Juridica.csv", std::ios::out | std::ios::app);

        out << juridico.get_cpf() << "," << juridico.get_nomepessoa() << "," << juridico.get_local() << "," << juridico.get_tipo_pessoa() 
        << "," << juridico.get_cnpj() << "," << juridico.get_nomeempresa() << "," << juridico.get_apelidoempresa() << 
        ","<< juridico.get_modelo_negocio() << std::endl;

        out.close();

        std::cout << std::endl;
      }

      // PESSOA FISICA
      else if (opcao == "2")
      {

        std::cout << std::endl;
        std::cout << "Bem-vindo, cliente! \n";
        std::cout << "Iremos iniciar o cadastro. \n";
        std::cout << "Digite seu nome completo: \n";
        std::cin.ignore();
        getline(std::cin, nomepessoa);
        confere_nomes(nomepessoa);
        std::cout << "Digite o número correpondente ao seu estado de residência: \n";
        std::cout << "(1)- MG \n"
                  << "(2)- SP \n"
                  << "(3)- RJ \n";
        while (true)
        {
          try
          {
            std::cin >> opcao;
            if (opcao != "1" && opcao != "2" && opcao != "3")
            {
              throw std::invalid_argument("Opção inválida!! Digite uma opção válida: ");
            }

            break;
          }
          catch (std::invalid_argument &e)
          {
            std::cerr << e.what() << std::endl;
          }
        }
        if (opcao == "1")
        {
          local = "MG";
        }
        else if (opcao == "2")
        {
          local = "SP";
        }
        else
        {
          local = "RJ";
        }

        Pessoa fisico(nomepessoa, local);
        std::cout << "Digite seu CPF: \n";
        fisico.insere_cpf();
        std::cout << std::endl;
        if (fisico.confirma_cadastro_fis(fisico) == true)
        {
          std::cout << "Cadastro realizado com sucesso! Obrigado!! \n";
        }
        else
        {
          fisico.edicao_cadastro_fis(fisico);
        }
        fisico.tipo_pessoa();
        std::cout<<std::endl;
        std::fstream arquivofisico("data/Pessoa_Fisica.csv", std::ios::out | std::ios::app);
        arquivofisico << fisico.get_cpf() << "," << fisico.get_nomepessoa() << "," << fisico.get_local() << "," << fisico.get_tipo_pessoa() << std::endl;
        arquivofisico.close();
      }

      break;

    case (2):

      std::cout<<std::endl;
      std::cout << "Qual é o tipo de pessoa? \n";
      std::cout << "1- Pessoa Jurídica. \n";
      std::cout << "2- Pessoa Física. \n";
      while (true)
      {
        try
        {
          std::cin >> op;
          if (op != "1" && op != "2")
          {
            throw std::invalid_argument("Opção inválida!! Digite 1 para Pessoa Jurídica ou 2 para Pessoa Física:");
          }
          break;
        }
        catch (std::invalid_argument &e)
        {
          std::cerr << e.what() << std::endl;
        }
      }

      option = stoi (op);
      
      switch (option)
      {
      case(1):
       std::cout<<"Digite o CNPJ da empresa: \n";
       while (true){
        try{ 
          std::cin>>cnpj;

          if(cnpj.size()<14 || cnpj.size()>14){
            throw std::out_of_range ("CNPJ Inválido!! Digite um novo CNPJ com tamanho válido (14):");
          }

          else{
           for(int i=0; cnpj[i] != '\0'; i++){
              if (!isdigit (cnpj[i])){
                throw std::invalid_argument ("CNPJ Inválido!! Digite um novo CNPJ apenas com números (14):");
                break;
              }
            }
          }

         break;

        }catch (std::invalid_argument &e){
        std::cerr<<e.what()<<std::endl;

        }catch (std::out_of_range &e2){
        std::cerr<<e2.what()<<std::endl;
        }    
       }
        contabil_juridica(cnpj);
        std::cout<<std::endl;
        break;
      
      case (2):
       std::cout<<"Digite seu CPF: \n";
       while (true){
        try{ 
          std::cin>>cpf;

          if(cpf.size()<11 || cpf.size()>11){
            throw std::out_of_range ("CPF Inválido!! Digite um novo CPF com tamanho válido (11):");
          }

          else{
            for(int i=0; cpf[i] != '\0'; i++){
                if (!isdigit (cpf[i])){
                  throw std::invalid_argument ("CPF Inválido!! Digite um novo CPF apenas com números (11):");
                  break;
               }
              }
          }

         break;

        }catch (std::invalid_argument &e){
         std::cerr<<e.what()<<std::endl;

        }catch (std::out_of_range &e2){
         std::cerr<<e2.what()<<std::endl;
        }    

       }
        contabil_fisica(cpf);
        std::cout<<std::endl;
        break;
      }

      break;

    case (3):

      // ESTATISTICOS

      std::cout << "Qual é o tipo de pessoa? \n";
      std::cout << "1- Pessoa Jurídica. \n";
      std::cout << "2- Pessoa Física. \n";
      while (true)
      {
        try
        {
          std::cin >> op;
          if (op != "1" && op != "2")
          {
            throw std::invalid_argument("Opção inválida!! Digite 1 para Pessoa Jurídica ou 2 para Pessoa Física:");
          }
          break;
        }
        catch (std::invalid_argument &e)
        {
          std::cerr << e.what() << std::endl;
        }
      }

      option = stoi (op);
      switch (option)
      {
      case(1):{
        EstatisticosJuridico e;
        e.dados_mensal();
        break;
      }

        break;
      case (2):{
        EstatisticosFisico e;
        e.imposto_renda_anual_fisico();
        break;
        }  
        
      }
      std::cout << std::endl;
      break;

    default:
      valide = false;

      break;
    }
  }

  return 0;
}