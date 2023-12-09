#include <bits/stdc++.h>
#include "pessoa.h"
#include "pessoajuridica.h"
#include "contabilidade_fisica.h"
#include "contabilidade_juridica.h"
#include "juridica_comercial.h"
#include "juridica_industrial.h"
#include "juridica_prestservico.h"

double contabil_fisica(std::string cpf_informado)
{
  std::fstream in("Pessoa_Fisica.csv", std::ios::in);
  std::string cpf, nome;
  if (!in.is_open())
  {
    std::cerr << "erro ao abrir arquivo!" << std::endl;
  }
  while (in.peek() != EOF || cpf_informado != cpf)
  {

    getline(in, cpf, ',');

    if (cpf == cpf_informado)
    {
      std::string nome, local, tipo;
      ContabilFisica conta;

      getline(in, nome, ',');
      getline(in, local, ',');
      Pessoa p(nome, local);

      getline(in, tipo, '\n');
      p.set_cpf(cpf);
      p.set_tipo_pessoa(tipo);

      conta._calcula_inss(p);
      conta._calcula_deducao_dependente();
      conta._base_calculos();
      conta._calcula_imposto_renda();
      return conta.get_Imposto_Renda_Final();
    }

    else
    {
      getline(in, cpf, '\n');
    }
    in.close();
    return -1;
  }
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

  std::string nomepessoa, nomeempresa, apelidoempresa, local, cnpj, cpf, opcao, selecionador;
  int selecionador2;
  bool valide = true;

  while (valide)
  {

    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>> MENU <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
    std::cout << "Olá cliente! \n";
    std::cout << "O que você deseja fazer? \n";
    std::cout << "(1) - Cadastrar \n";
    std::cout << "(2) - Realizar contabilidade (cliente já deve ser cadastrado) \n";
    std::cout << "(3) - Checar análises estatísticas (cliente já deve ser cadastrado) \n";
    std::cout << "(4) - Sair do Menu \n";
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
        std::cout << "Digite o CNPJ do proprietario: \n";
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
        juridico.modelo_negocio();
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
        std::cout << std::endl;
        std::cout << "Cadastro finalizado com sucesso!" << std::endl;
        std::fstream arquivofisico("Pessoa_Fisica.csv", std::ios::out | std::ios::app);
        arquivofisico << fisico.get_cpf() << "," << fisico.get_nomepessoa() << "," << fisico.get_local() << "," << fisico.get_tipo_pessoa() << std::endl;
        arquivofisico.close();
      }

      break;

    case (2):

      // PARA LUIS:

      // PARA CONFIRMAR O TIPO DE PESSOA

      int op;
      std::cout << "Qual é o tipo de pessoa? \n";
      std::cout << "1- Pessoa Jurídica. \n";
      std::cout << "2- Pessoa Física. \n";
      while (true)
      {
        try
        {
          std::cin >> op;
          if (op != 1 && op != 2)
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

      std::cout << "Digite seu cpf: ";
      std::cin >> cpf;
      switch (op)
      {
      case (2):
        std::cout << contabil_fisica(cpf) << std::endl;
      }

      // PARA CONTABILIDADE DO TIPO JURIDICO INDUSTRIAL
      /*
          JuridicaIndustrial industria;
          industria.set_caixa();
          std::cout<<industria.get_caixa ()<<std::endl;
          industria.set_contasPagar ();
          std::cout<<industria.get_contasPagar ()<<std::endl;
          industria.set_contasReceber ();
          std::cout<<industria.get_contasReceber ()<<std::endl;
          industria._calculo_DRE ();
          industria._calculo_fluxo_caixa ();
       */

      break;

    case (3):

      // ESTATISTICOS

      break;

    default:
      valide = false;

      break;
    }
  }

  return 0;
}