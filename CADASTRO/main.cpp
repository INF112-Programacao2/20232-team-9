#include <iostream>
#include <cstring>
#include "cadastro.h"

std::string confere_nomes (std::string &nome){
 
 int contnotalpha;
 int cont=1;
  
  while(cont>0){

   contnotalpha=0;

    for (int i=0; nome[i] != '\0'; i++){
       
        if((nome.at(i) == ' ') && i != 0){
            continue;
        }

        else if(!isalpha (nome[i])){

            contnotalpha++;

        }
    }


    if(contnotalpha>0){

         std::cout<<"Nome inválido!! O nome deve conter apenas letras! \n";
         std::cout<<"Digite um nome válido: \n";
         getline (std::cin, nome);

    }

    else {
      break;
    }

  }   

 return nome; 
   
}


int main(){

    std::string nomepessoa, nomeempresa, apelidoempresa, local, cnpj, cpf;
    int opcao, confirmacao, selecionador;

    std::cout<<"Olá cliente! \n";
    std::cout<<"Deseja realizar qual tipo de contabilidade? \n";
    std::cout<<"1- Contabilidade Jurídica. \n";
    std::cout<<"2- Contabilidade Física. \n";
    std::cout<<"Digite 1 para Contabilidade Jurídica ou 2 para Contabilidade Física: \n";
    std::cin>>opcao;


    while (opcao != 1 && opcao != 2){

        std::cerr<<"Opção inválida!! Digite 1 para Contabilidade Jurídica ou 2 para Contabilidade Física: \n";
        std::cin>>opcao;

    }



    if(opcao==1){

        std::cout<<"Bem-vindo, cliente! \n";
        std::cout<<"Iremos iniciar o cadastro. \n";
        std::cout<<"Digite o nome completo do proprietário da empresa: \n";
        std::cin.ignore();
        getline (std::cin, nomepessoa);
        confere_nomes(nomepessoa);
        std::cout<<"Digite o nome da empresa: \n";
        getline (std::cin, nomeempresa);
        confere_nomes(nomeempresa);
        std::cout<<"Digite o apelido da empresa: \n";
        getline (std::cin, apelidoempresa);
        std::cout<<"Digite o estado em que a empresa encontra-se localizada: \n";
        getline (std::cin, local);
        confere_nomes(local);

        Cadastro juridico (nomepessoa, nomeempresa, apelidoempresa, local);
        std::cout<<"Digite o CNPJ do proprietario: \n";
        std::cin>>cnpj;
        juridico.confere_cnpj(cnpj);
        std::cout<<juridico.get_nomepessoa()<<" "<<juridico.get_cnpj()<<" "<<juridico.get_nomeempresa()<<" "<<juridico.get_apelidoempresa()<<" "<<juridico.get_local();
        std::cout<<std::endl;

        std::cout<<"Você confirma os dados inseridos no cadastro? \n";
        std::cout<<"1- Sim. \n";
        std::cout<<"2- Não. \n";
        std::cout<<"Digite 1 para SIM ou 2 para NÃO: \n";
        std::cin>>confirmacao;
       

        while (confirmacao != 1 && confirmacao != 2){

          std::cout<<"Opção inválida!! Digite 1 para SIM ou 2 para NÃO: \n";
          std::cin>>confirmacao;

        }



        if(confirmacao==1){

            std::cout<<"Cadastro realizado com sucesso! Obrigado!! \n";

        }



        else if (confirmacao==2){

          while (confirmacao=2){

            std::cout<<"Qual dado deseja alterar? \n";
            std::cout<<"1- Nome do proprietário (DIGITE 1) \n";
            std::cout<<"2- Nome da empresa (DIGITE 2) \n";
            std::cout<<"3- Apelido da empresa (DIGITE 3) \n";
            std::cout<<"4- Localidade (DIGITE 4) \n";
            std::cout<<"5- CPF (DIGITE 5) \n";

            std::cin>>selecionador;


            while (selecionador != 1 && selecionador != 2 && selecionador != 3 && selecionador != 4 && selecionador != 5){

              std::cout<<"Opção inválida!! Digite uma opção válida: \n";
              std::cin>>selecionador;

            }

            
            std::cin.ignore();


            switch (selecionador){

                case (1):

                  std::cout<<"Digite o novo nome do proprietário: \n";

                  getline (std::cin, nomepessoa); 
                  confere_nomes(nomepessoa);
                  juridico.set_nomepessoa(nomepessoa);
                  break;

                case (2):

                  std::cout<<"Digite o novo nome da empresa: \n";
                  getline (std::cin, nomeempresa); 
                  confere_nomes(nomeempresa);
                  juridico.set_nomeempresa(nomeempresa);
                  break;


                case (3):

                  std::cout<<"Digite o novo apelido da empresa: \n";
                  getline (std::cin, apelidoempresa); 
                  juridico.set_apelidoempresa(apelidoempresa);
                  break;


                case(4):

                  std::cout<<"Digite a nova localidade da empresa: \n";
                  getline (std::cin, local); 
                  confere_nomes(local);
                  juridico.set_local(local);
                  break;


                case(5): 

                  std::cout<<"Digite o novo CNPJ: \n";
                  std::cin>>cnpj; 
                  juridico.confere_cnpj (cnpj);
                  break;

            }


             std::cout<<juridico.get_nomepessoa()<<" "<<juridico.get_cnpj()<<" "<<juridico.get_nomeempresa()<<" "<<juridico.get_apelidoempresa()<<" "<<juridico.get_local();
             std::cout<<std::endl;
             std::cout<<"Você confirma os novos dados inseridos no cadastro? \n";
             std::cout<<"1- Sim. \n";
             std::cout<<"2- Não. \n";
             std::cout<<"Digite 1 para SIM ou 2 para NÃO: \n";
             std::cin>>confirmacao;

        
            while (confirmacao != 1 && confirmacao != 2){

              std::cout<<"Opção inválida!! Digite 1 para SIM ou 2 para NÃO: \n";
              std::cin>>confirmacao;

           }


              if(confirmacao==1){
                 std::cout<<"Cadastro realizado com sucesso! Obrigado!! \n";
                 break;
             }

        }

    }

 }

 return 0;

}